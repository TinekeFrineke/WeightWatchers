#include "../Interface\Generated\stdafx.h"

#include "../Interface\Generated\XmlGerechtdef.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "../Interface\Generated\XmlGerechtdefWriter.h"

namespace ww_1_2
{
XERCES_CPP_NAMESPACE::DOMNode * XmlGerechtdefWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlGerechtdef & aGerechtdef)
{
  XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("gerechtdef"));
  Fill(aDocument, aGerechtdef, *element);
  return element;
}

void XmlGerechtdefWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlGerechtdef & aGerechtdef, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
  (void)aDocument;
  (void)aGerechtdef;
  (void)anElement;
  anElement.setAttribute(_T("naam"), aGerechtdef.Getnaam().c_str());
  anElement.setAttribute(_T("punten"), aGerechtdef.Getpunten().c_str());
}


}
