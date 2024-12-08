#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlHandmatigitemReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "../Interface\Generated\XmlHandmatigitem.h"


namespace ww_1_2
{
XmlHandmatigitemReader::XmlHandmatigitemReader()
{
}


XmlHandmatigitem * XmlHandmatigitemReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlHandmatigitem * Handmatigitem = new XmlHandmatigitem;
  Fill(anElement, *Handmatigitem);
  return Handmatigitem;
}

XmlClass::eRESULT XmlHandmatigitemReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlHandmatigitem & aHandmatigitem)
{
  XERCES_CPP_NAMESPACE::DOMNodeList * list = anElement.getChildNodes();

  if (list == NULL)
    return XmlClass::RESULT_Ok;

  for (XMLSize_t i = 0; i < list->getLength(); i++)
  {
    if (list->item(i) == NULL)
      continue;

  }
  XERCES_CPP_NAMESPACE::DOMNamedNodeMap * attributes = anElement.getAttributes();
  if (attributes != NULL)
  {
    XERCES_CPP_NAMESPACE::DOMNode * naamnode = attributes->getNamedItem(_T("naam"));
    if (naamnode != NULL)
      aHandmatigitem.Setnaam(naamnode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * puntennode = attributes->getNamedItem(_T("punten"));
    if (puntennode != NULL)
      aHandmatigitem.Setpunten(puntennode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * hoeveelheidnode = attributes->getNamedItem(_T("hoeveelheid"));
    if (hoeveelheidnode != NULL)
      aHandmatigitem.Sethoeveelheid(hoeveelheidnode->getNodeValue());
  }

  return XmlClass::RESULT_Ok;
}


}
