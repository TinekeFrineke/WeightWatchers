// DiaryPage.cpp : implementation file
//

#include "stdafx.h"

#include ".\diarypage.h"

#include "WW/WWModel/Day.h"
#include "WW/WWModel/ManualItem.h"
#include "WW/WWModel/Personalia.h"
#include "WW/WWModel/Recept.h"
#include "WW/WWModel/Voedingsmiddel.h"
#include "WW/WWModel/Week.h"

#include "BewegingDialog.h"
#include "EditBonuses.h"
#include "FindRecept.h"
#include "FindVoedingsmiddel.h"
#include "HandmatigeItemDlg.h"
#include "ItemEditVisitor.h"
#include "WeightWatchers.h"


// CDiaryPage dialog

IMPLEMENT_DYNAMIC(CDiaryPage, CDialog)
CDiaryPage::CDiaryPage(WW::Model & aModel, CWnd* pParent /*=NULL*/)
: CDialog     (CDiaryPage::IDD, pParent),
  mModel      (aModel),
  mItemList   (aModel),
  mDay        (nullptr)
{
}

CDiaryPage::~CDiaryPage()
{
}

void CDiaryPage::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_ITEMLIST,  mItemList);
  DDX_Control(pDX, IDC_PUNTEN, mPunten);
  DDX_Control(pDX, IDC_WEEK_EINDE, mEndOfWeek);
  DDX_Control(pDX, IDC_WEEK_BEGIN, mStartOfWeek);
  DDX_Control(pDX, IDC_BONUSPUNTEN, mBonusPoints);
  DDX_Control(pDX, IDC_PUNTEN_OVER, mPointsLeft);
  DDX_Control(pDX, IDC_DATE, mDate);
  DDX_Control(pDX, IDC_WEIGHT, mWeight);
  DDX_Control(pDX, IDC_TOTAAL, mTotaal);
  DDX_Control(pDX, IDC_STRATEGIE, mStrategie);
  DDX_Control(pDX, IDC_WEEKPUNTEN, mWeekPunten);
  DDX_Control(pDX, IDC_WEEKPUNTENSTATIC, mWeekpuntenStatic);
  DDX_Control(pDX, IDC_CALCULATEDBONUS, mCalculatedBonusPoints);
}


BEGIN_MESSAGE_MAP(CDiaryPage, CDialog)
  ON_BN_CLICKED(IDC_ADD_FOOD, OnBnClickedAddFood)
  ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_WEEK_EINDE, OnDeltaposSpinWeekEinde)
  ON_EN_CHANGE(IDC_BONUSPUNTEN, OnEnChangeBonuspunten)
  ON_BN_CLICKED(IDC_DAY_MINUS, OnBnClickedDayMinus)
  ON_BN_CLICKED(IDC_DAY_PLUS, OnBnClickedDayPlus)
  ON_BN_CLICKED(IDC_ADD_RECEPT, OnBnClickedAddRecept)
  ON_BN_CLICKED(IDC_ADD_GERECHT, OnBnClickedAddGerecht)
  ON_BN_CLICKED(IDC_EDIT, OnBnClickedEdit)
  ON_BN_CLICKED(IDC_DELETE, OnBnClickedDelete)
  ON_EN_CHANGE(IDC_WEIGHT, OnEnChangeWeight)
  ON_BN_CLICKED(IDC_ADD_HANDMATIG, OnBnClickedAddHandmatig)
  ON_NOTIFY(NM_DBLCLK, IDC_ITEMLIST, OnNMDblclkItemlist)
  ON_WM_SHOWWINDOW()
  ON_EN_CHANGE(IDC_WEEK_EINDE, OnEnChangeWeekEinde)
  ON_BN_CLICKED(IDC_ADDBONUS, &CDiaryPage::OnBnClickedAddbonus)
END_MESSAGE_MAP()


// CDiaryPage message handlers

BOOL CDiaryPage::OnInitDialog()
{
  if (CDialog::OnInitDialog() == FALSE)
    return FALSE;

  mItemList.Initialize();
  mItemList.SetSelectionMark(0);
  mItemList.ShowWindow(SW_SHOW);

  ProcessDate(Utils::Date::Today());
  UpdatePointsLeft();

  return TRUE;
}


void CDiaryPage::OnCancel()
{
}


bool CDiaryPage::ProcessDate(const Utils::Date & aDate)
{
  mWeek = mModel.FindWeek(aDate);
  if (mWeek == NULL)
  {
    Utils::Date enddate(aDate);
    enddate.AddDays(6);
    mWeek = new WW::Week(aDate, enddate);
    mWeek->SetPoints(mModel.GetActivePersonalia()->GetPuntenTotaal(mModel.GetStrategy()));
    mWeek->SetSaveablePoints(mModel.GetVrijePunten());
    mWeek->SetStrategy(mModel.GetStrategy(), mModel);
    mWeek->SetStartWeight(mModel.GetActivePersonalia()->GetHuidigGewicht());
    mModel.Add(mWeek);
  }

  switch (mWeek->GetStrategy())
  {
  case WW::STRATEGY_TYPE::FlexiPoints:
    mStrategie.SetValue(_T("FlexiPoints"));
    break;
  case WW::STRATEGY_TYPE::ProPoints:
    mStrategie.SetValue(_T("ProPoints"));
    break;
  case WW::STRATEGY_TYPE::KCal:
    mStrategie.SetValue(_T("KCal"));
    break;
  case WW::STRATEGY_TYPE::CarboHydrates:
    mStrategie.SetValue(_T("CarboHydrates"));
    break;
  default:
    assert(false);
  }

  mPunten.SetValue(mWeek->GetPoints());
  mDate.SetValue(Utils::ToString(aDate));
  mStartOfWeek.SetValue(Utils::ToString(mWeek->GetStartDate()));
  mEndOfWeek.SetValue(Utils::ToString(mWeek->GetEndDate()));

  mDay = mWeek->GetDay(aDate);
  if (mDay == NULL)
  {
    mDay = new WW::Day(aDate);
    mDay->SetWeight(mModel.GetActivePersonalia()->GetHuidigGewicht());
    mWeek->Add(mDay);
  }

  mItemList.View(mDay);
  mBonusPoints.SetValue(mDay->GetFreeBonusPoints());
  mCalculatedBonusPoints.SetValue(mDay->GetCalculatedBonusPoints());
  mWeight.SetValue(mDay->GetWeight());

  return true; 
}


void CDiaryPage::OnDtnDatetimechangeDiarydate(NMHDR *pNMHDR, LRESULT *pResult)
{
  LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
  Utils::Date date(Utils::Date::FromSystemTime(pDTChange->st));

  ProcessDate(date);

  *pResult = 0;
}

void CDiaryPage::OnBnClickedAddFood()
{
  CFindVoedingsmiddel dialog(mModel, NULL, this);
  INT_PTR nResponse = dialog.DoModal();
	if (nResponse == IDOK)
	{
    if (dialog.GetVoedingsMiddel() != NULL)
    {
      mDay->Add(dialog.GetVoedingsMiddel());
      mItemList.View(mDay);
      UpdatePointsLeft();
    }
	}
  else
  {
    if (dialog.GetVoedingsMiddel() != NULL)
      delete dialog.GetVoedingsMiddel();
  }
}

void CDiaryPage::OnDeltaposSpinWeekEinde(NMHDR *pNMHDR, LRESULT *pResult)
{
  LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

  Utils::Date date(Utils::ToDate(mEndOfWeek.GetValue()));
  if (pNMUpDown->iDelta < 0)
  {
    if (date > mWeek->GetStartDate())
    {
      int diff;
      if (date.DaysDifference(mWeek->GetStartDate(), diff))
      {
        if (diff < 14)
          date.AddDays(1);
      }
    }

    mEndOfWeek.SetValue(Utils::ToString(date));
  }
  else
  {
    if (date > mWeek->GetStartDate() &&
        date > Utils::Date::Today())
    {
      int diff;
      if (date.DaysDifference(mWeek->GetStartDate(), diff))
      {
        if (diff > 3)
          date.SubtractDays(1);
      }
    }

    mEndOfWeek.SetValue(Utils::ToString(date));
  }

  *pResult = 0;
}


void CDiaryPage::UpdatePointsLeft()
{
  if (mWeek == NULL || mDay == NULL)
    return;

  mPointsLeft.SetValue(mWeek->GetPointsLeft(mDay->GetDate()));
  mWeekPunten.SetValue(mWeek->GetWeekPointsLeft(mDay->GetDate()));
  mTotaal.SetValue(mDay->GetPoints());
}

void CDiaryPage::OnEnChangeBonuspunten()
{
  mDay->SetFreeBonusPoints(mBonusPoints.GetValue());
  UpdatePointsLeft();
}

void CDiaryPage::OnBnClickedDayMinus()
{
  Utils::Date date(Utils::ToDate(mDate.GetValue()));
  date.SubtractDays(1);
  ProcessDate(date);
}

void CDiaryPage::OnBnClickedDayPlus()
{
  Utils::Date date(Utils::ToDate(mDate.GetValue()));
  date.AddDays(1);
  if (date <= Utils::Date::Today())
    ProcessDate(date);
}

void CDiaryPage::OnBnClickedAddRecept()
{
  CFindRecept dialog(mModel, NULL, this);
  INT_PTR nResponse = dialog.DoModal();
	if (nResponse == IDOK)
	{
    if (dialog.GetRecept() != NULL)
    {
      mDay->Add(dialog.GetRecept());
      mItemList.View(mDay);
      UpdatePointsLeft();
    }
	}
  else
  {
    if (dialog.GetRecept() != NULL)
      delete dialog.GetRecept();
  }
}

void CDiaryPage::OnBnClickedAddGerecht()
{
  // TODO: Add your control notification handler code here
}


void CDiaryPage::EditItem(WW::Item & item)
{
  ItemEditVisitor visitor(mModel, this);
  item.Accept(visitor);

  mItemList.View(mDay);
  UpdatePointsLeft();
}


void CDiaryPage::OnBnClickedEdit()
{
  ItemListItem * item = mItemList.GetSelectedItem();
  if (item == NULL || item->GetItem() == NULL)
    return;

  EditItem(*item->GetItem());
}

void CDiaryPage::OnBnClickedDelete()
{
  ItemListItem * item = mItemList.GetSelectedItem();
  if (item == NULL)
    return;

  mDay->Remove(item->GetItem());

  mItemList.View(mDay);
  UpdatePointsLeft();
}


void CDiaryPage::OnEnChangeWeight()
{
  mDay->SetWeight(mWeight.GetValue());
  mModel.GetActivePersonalia()->SetHuidigGewicht(mDay->GetWeight());
}


void CDiaryPage::OnBnClickedAddHandmatig()
{
  HandmatigeItemDlg dialog(NULL, this);
  INT_PTR nResponse = dialog.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
    if (dialog.GetItem() != NULL)
    {
      mDay->Add(dialog.GetItem());
      mItemList.View(mDay);
      UpdatePointsLeft();
    }
  }
  else
  {
    if (dialog.GetItem() != NULL)
      delete dialog.GetItem();
  }
}

void CDiaryPage::OnNMDblclkItemlist(NMHDR *pNMHDR, LRESULT *pResult)
{
  LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

  *pResult = 0;

  ItemListItem * item = mItemList.GetItemAt(pNMLV->iItem);
  if (item == NULL || item->GetItem() == 0)
    return;

  EditItem(*item->GetItem());
}

void CDiaryPage::OnShowWindow(BOOL bShow, UINT nStatus)
{
    CDialog::OnShowWindow(bShow, nStatus);

    if (mDay == nullptr) {
        MessageBox(L"Day == nulptr!!!", L"FATAL ERROR", MB_OK);
        return;
    }

    mPunten.SetValue(mWeek->GetPoints());

    mDay->SetWeight(mModel.GetActivePersonalia()->GetHuidigGewicht());
    mBonusPoints.SetValue(mDay->GetFreeBonusPoints());
    mCalculatedBonusPoints.SetValue(mDay->GetCalculatedBonusPoints());
    mWeight.SetValue(mDay->GetWeight());

    mWeekpuntenStatic .ShowWindow(mWeek->GetStrategy() != WW::STRATEGY_TYPE::FlexiPoints ? SW_SHOW : SW_HIDE);
    mWeekPunten       .ShowWindow(mWeek->GetStrategy() != WW::STRATEGY_TYPE::FlexiPoints ? SW_SHOW : SW_HIDE);
    mItemList.View(mDay);
}

void CDiaryPage::OnEnChangeWeekEinde()
{
  if (!mModel.SetEndDate(*mWeek, Utils::ToDate(mEndOfWeek.GetValue())))
  {
    ::MessageBox(m_hWnd, (_T("Could not set end date ") + mEndOfWeek.GetValue()).c_str(), _T("Error"), MB_OK);
    return;
  }

  UpdatePointsLeft();
}

void CDiaryPage::OnBnClickedAddbinus()
{
  CEditBonuses dialog(mModel, mDay->GetBonuses(), mDay->GetWeight(), this);
  INT_PTR nResponse = dialog.DoModal();
  if (nResponse == IDOK) {
    mDay->SetBonuses(dialog.GetBonuses());
    mCalculatedBonusPoints.SetValue(mDay->GetCalculatedBonusPoints());
  }
}



void CDiaryPage::OnBnClickedAddbonus()
{
    BewegingDialog dialog(mDay->GetCalculatedBonusPoints(), this);
    INT_PTR nResponse = dialog.DoModal();
    if (nResponse == IDOK) {
        WW::Bonus bonus{ WW::Bonus::INTENSITY::Medium, 1, static_cast<int>(dialog.GetBewegingsPunten()) };
        mDay->SetBonuses(std::list<WW::Bonus>({ bonus }));
        mCalculatedBonusPoints.SetValue(mDay->GetCalculatedBonusPoints());
    }
}
