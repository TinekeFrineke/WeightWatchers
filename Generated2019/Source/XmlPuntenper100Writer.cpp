//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================

#include "XmlPuntenper100Writer.h"

#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>

#include "XmlPuntenper100.h"

namespace ww2019
{
XERCES_CPP_NAMESPACE::DOMNode * XmlPuntenper100Writer::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlPuntenper100 & aPuntenper100)
{
    XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("puntenper100"));
    Fill(aDocument, aPuntenper100, *element);
    return element;
}

void XmlPuntenper100Writer::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlPuntenper100 & aPuntenper100, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
    (void)aDocument;
    (void)aPuntenper100;
    (void)anElement;
  anElement.setAttribute(_T("punten"), aPuntenper100.Getpunten().c_str());
}


}
