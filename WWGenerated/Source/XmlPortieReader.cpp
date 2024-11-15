#include "stdafx.h"
#include "XmlPortieReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlPortie.h"


namespace ww_1_1
{
XmlPortieReader::XmlPortieReader()
{
}


XmlPortie * XmlPortieReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlPortie * Portie = new XmlPortie;
  Fill(anElement, *Portie);
  return Portie;
}

Generator::XmlClass::eRESULT XmlPortieReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPortie & aPortie)
{
  XERCES_CPP_NAMESPACE::DOMNodeList * list = anElement.getChildNodes();

  if (list == NULL)
    return Generator::XmlClass::RESULT_Ok;

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
      aPortie.Setnaam(naamnode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * eenhedennode = attributes->getNamedItem(_T("eenheden"));
    if (eenhedennode != NULL)
      aPortie.Seteenheden(eenhedennode->getNodeValue());
  }

  return Generator::XmlClass::RESULT_Ok;
}


}