//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================

#include "XmlGerechtWriter.h"

#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>

#include "XmlGerecht.h"

namespace ww2019
{
XERCES_CPP_NAMESPACE::DOMNode * XmlGerechtWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlGerecht & aGerecht)
{
    XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("gerecht"));
    Fill(aDocument, aGerecht, *element);
    return element;
}

void XmlGerechtWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlGerecht & aGerecht, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
    (void)aDocument;
    (void)aGerecht;
    (void)anElement;
  anElement.setAttribute(_T("naam"), aGerecht.Getnaam().c_str());
  anElement.setAttribute(_T("punten"), aGerecht.Getpunten().c_str());
  anElement.setAttribute(_T("hoeveelheid"), aGerecht.Gethoeveelheid().c_str());
}


}
