#pragma once

#include "resource.h"
#include "stringedit.h"
#include "receptdefinitieslist.h"
#include "doubleedit.h"
#include "portiecombobox.h"
#include "afxwin.h"


class VMState;

namespace WW
{
class Day;
class Recept;
class ReceptDefinitie;
}

// CFindRecept dialog

class CFindRecept : public CDialog
{
	DECLARE_DYNAMIC(CFindRecept)

public:
                        CFindRecept(WW::Model &            aModel,
                                    WW::ReceptDefinitie * aDefinitie,
                                    CWnd *                pParent = NULL);   // standard constructor
	virtual               ~CFindRecept();

// Dialog Data
	enum { IDD = IDD_FIND_RECEPT };

  WW::Recept *          GetRecept() { return mRecept; }

protected:
	virtual void          DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

  BOOL                  OnInitDialog();

  afx_msg void          OnBnClickedOk();
  afx_msg void          OnBnClickedCancel();
  afx_msg void          OnEnChangeNaam();
//  afx_msg void          OnCbnSelchangeCombo1();
  afx_msg void          OnLvnItemchangedItemlist(NMHDR *pNMHDR, LRESULT *pResult);
  afx_msg void          OnEnChangePorties();
  afx_msg void          OnNMDblclkItemlist(NMHDR *pNMHDR, LRESULT *pResult);

private:
  void                  UpdateItemFilter();

  CStringEdit           mNaam;
  // Food items to pick from
  ReceptDefinitiesList  mItemList;
  // The number of porties
  CDoubleEdit           mPorties;
  CDoubleEdit           mPoints;

  WW::Model &           mModel;
  WW::Recept *          mRecept;
  WW::ReceptDefinitie * mDefinitie;

  bool                  mUpdating;
  bool                  mUpdatingFilter;
};


//class VMState
//{
//public:
//                            VMState(CFindRecept &         aDialog,
//                                    WW::ReceptDefinitie & aDefinitie,
//                                    WW::Model &                   aModel)
//                                    : mDialog   (aDialog),
//                                      mDefinitie(aDefinitie),
//                                      mModel    (aModel)
//                            {}
//
//  virtual void              Initialize() = 0;
//  virtual void              OnCheckFreePortion() = 0;
//
//  void                      UpdateFreeStateValues();
//  void                      UpdatePortionValues(const WW::Portie & aPortie);
//
//protected:
//  CFindRecept &     GetDialog()           { return mDialog; }
//  // The number of porties
//  CDoubleEdit &             GetPorties()          { return mDialog.mPorties; }
//  // The number of units
//  CDoubleEdit &             GetUnits()            { return mDialog.mUnits; }
//  CStringEdit &             GetUnitNaam()         { return mDialog.mUnitNaam; }
//
//  PortieComboBox &          GetPortieBox()        { return mDialog.mPortieNaam; }
//  CDoubleEdit &             GetPoints()           { return mDialog.mPoints; }
//  CButton &                 GetVrijePortieCheck() { return mDialog.mVrijePortieCheck; }
//
//  WW::ReceptDefinitie &
//                            GetDefinitie()        { return mDefinitie; }
//  const WW::Model &         GetModel() const      { return mModel; }
//
//private:
//  CFindRecept &     mDialog;
//  WW::ReceptDefinitie &
//                            mDefinitie;
//  WW::Model &               mModel;
//};


//class VMNoPortionsState : public VMState
//{
//public:
//                            VMNoPortionsState(CFindRecept &         aDialog,
//                                              WW::ReceptDefinitie & aDefinitie,
//                                              WW::Model &                   aModel)
//                            : VMState(aDialog, aDefinitie, aModel) {}
//
//  virtual void              Initialize();
//  virtual void              OnCheckFreePortion();
//};
//
//
//class VMFreePortionState : public VMState
//{
//public:
//                            VMFreePortionState(CFindRecept &         aDialog,
//                                               WW::ReceptDefinitie & aDefinitie,
//                                               WW::Model &                   aModel)
//                            : VMState(aDialog, aDefinitie, aModel) {}
//
//  virtual void              Initialize();
//  virtual void              OnCheckFreePortion();
//};
//
//
//class VMStandardPortionsState : public VMState
//{
//public:
//                            VMStandardPortionsState(CFindRecept &         aDialog,
//                                                    WW::ReceptDefinitie & aDefinitie,
//                                                    WW::Model &                   aModel)
//                            : VMState(aDialog, aDefinitie, aModel) {}
//
//  virtual void              Initialize();
//  virtual void              OnCheckFreePortion();
//};
//
//
//class VMBothState : public VMState
//{
//public:
//                            VMBothState(CFindRecept &         aDialog,
//                                        WW::ReceptDefinitie & aDefinitie,
//                                        WW::Model &                   aModel)
//                            : VMState(aDialog, aDefinitie, aModel) {}
//
//  virtual void              Initialize();
//  virtual void              OnCheckFreePortion();
//};
