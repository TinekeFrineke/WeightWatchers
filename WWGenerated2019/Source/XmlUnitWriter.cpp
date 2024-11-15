#include "../Interface/stdafx.h"

#include "../Interface/XmlUnit.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "../Interface/XmlUnitWriter.h"

namespace ww2019
{
XERCES_CPP_NAMESPACE::DOMNode * XmlUnitWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlUnit & aUnit)
{
  XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("unit"));
  Fill(aDocument, aUnit, *element);
  return element;
}

void XmlUnitWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlUnit & aUnit, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
  (void)aDocument;
  (void)aUnit;
  (void)anElement;
  anElement.setAttribute(_T("naam"), aUnit.Getnaam().c_str());
}


}