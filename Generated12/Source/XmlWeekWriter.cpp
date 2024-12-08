#include "../Interface\Generated\stdafx.h"

#include "../Interface\Generated\XmlWeek.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "../Interface\Generated\XmlDagWriter.h"
#include "../Interface\Generated\XmlDag.h"
#include "../Interface\Generated\XmlWeekWriter.h"

namespace ww_1_2
{
XmlClass::eRESULT XmlWeekWriter::Write(const std::wstring & aFilename, const XmlWeek & aWeek)
{
  ParseErrorHandler eh;
  XERCES_CPP_NAMESPACE::XercesDOMParser parser;
  parser.setDoValidation(false);
  parser.setErrorHandler(&eh);

  XERCES_CPP_NAMESPACE::DOMImplementation * impl =
    XERCES_CPP_NAMESPACE::DOMImplementationRegistry::getDOMImplementation(L"Core");

  XERCES_CPP_NAMESPACE::DOMDocument * doc =
    impl->createDocument(0,               // root element namespace URI.
                         L"week",  // root element name
                         0);              // document type object (Xml).
  XERCES_CPP_NAMESPACE::DOMElement * rootelement = doc->getDocumentElement();
  Fill(*doc, aWeek, *rootelement);

  XERCES_CPP_NAMESPACE::DOMWriter * writer = ((XERCES_CPP_NAMESPACE::DOMImplementationLS*)impl)->createDOMWriter();
  XERCES_CPP_NAMESPACE::LocalFileFormatTarget formatter(aFilename.c_str());
  writer->writeNode(&formatter, *doc);
  writer->release();

  doc->release();

  return RESULT_Ok;
}


void XmlWeekWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlWeek & aWeek, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

  XmlDagWriter Dagwriter;
  for (size_t i = 0; i < aWeek.GetDagList().size(); ++i)
  {
    XERCES_CPP_NAMESPACE::DOMNode * Dagnode = Dagwriter.Write(aDocument, *aWeek.GetDagList()[i]);
    anElement.appendChild(Dagnode);
  }
  anElement.setAttribute(_T("begindatum"), aWeek.Getbegindatum().c_str());
  anElement.setAttribute(_T("einddatum"), aWeek.Geteinddatum().c_str());
  anElement.setAttribute(_T("punten"), aWeek.Getpunten().c_str());
  anElement.setAttribute(_T("weekpunten"), aWeek.Getweekpunten().c_str());
  anElement.setAttribute(_T("startweight"), aWeek.Getstartweight().c_str());
  switch (aWeek.Getstrategie())
  {
    case XmlWeek::strategie_FlexiPoints:
      anElement.setAttribute(_T("strategie"), _T("FlexiPoints"));
    break;
    case XmlWeek::strategie_ProPoints:
      anElement.setAttribute(_T("strategie"), _T("ProPoints"));
    break;
    case XmlWeek::strategie_KCal:
      anElement.setAttribute(_T("strategie"), _T("KCal"));
    break;
    case XmlWeek::strategie_CarboHydrates:
      anElement.setAttribute(_T("strategie"), _T("CarboHydrates"));
    break;
    default:
      throw 1;
  }
}


}
