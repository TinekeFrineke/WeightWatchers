#include "stdafx.h"
#include "XmlPropointsReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/sax/saxexception.hpp>
#include "XmlPropoints.h"
#include "XmlBonuslistReader.h"
#include "XmlBonuslist.h"
#include "XmlSterrelotsReader.h"
#include "XmlSterrelots.h"
#include "XmlStrategybaseReader.h"
#include "XmlStrategybase.h"
namespace ww2015
{


XmlPropointsReader::XmlPropointsReader()
{
}


XmlClass::eRESULT XmlPropointsReader::Read(const std::wstring & aFilename, XmlPropoints *& aPropoints)
{
  aPropoints = NULL;
  if (_taccess(aFilename.c_str(), 0) == -1)
  {
    switch (errno)
    {
      case ENOENT:
        return RESULT_FileNotFound;
      default:
        return RESULT_FileOpenError;
    }
  }

  ParseErrorHandler eh;
  XERCES_CPP_NAMESPACE::XercesDOMParser parser;
  parser.setDoValidation(false);
  parser.setErrorHandler(&eh);

  eRESULT result = ParseDocument(aFilename, parser);
  if (result != RESULT_Ok)
    if (result == RESULT_FileNotFound)
      return RESULT_Ok;
    else
      return result;

  if (parser.getDocument() == NULL)
    return RESULT_ErrorInFile;

  try
  {
    XERCES_CPP_NAMESPACE::DOMNodeList * list = parser.getDocument()->getChildNodes();

    if (list == NULL)
      return RESULT_ErrorInFile;

    for (XMLSize_t i = 0; i < list->getLength(); i++)
    {
      if (list->item(i) == NULL)
        continue;

      short type = list->item(i)->getNodeType();
      XERCES_CPP_NAMESPACE::DOMNode * node = list->item(i);

      if (type == XERCES_CPP_NAMESPACE::DOMNode::TEXT_NODE)
      {
        continue;
      }
      else if (type == XERCES_CPP_NAMESPACE::DOMNode::ELEMENT_NODE)
      {
        const TCHAR * name = node->getNodeName();
        (void)name;
        if (_tcscmp(node->getNodeName(), _T("propoints")) == 0)
          aPropoints = Generate(*node);
      }
    }

    if (aPropoints == NULL)
      return RESULT_ParserError;
  }
  catch (const std::exception & anException)
  {
    (void)anException;
    return RESULT_ParserError;
  }
  catch (const XERCES_CPP_NAMESPACE::SAXException & anException)
  {
    (void)anException;
    return RESULT_ParserError;
  }
  catch (...)
  {
    return RESULT_ParserError;
  }

  return RESULT_Ok;
}

XmlPropoints * XmlPropointsReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlPropoints * Propoints = new XmlPropoints;
  Fill(anElement, *Propoints);
  return Propoints;
}


XmlClass::eRESULT XmlPropointsReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPropoints & aPropoints)
{
  XERCES_CPP_NAMESPACE::DOMNodeList * list = anElement.getChildNodes();

  if (list == NULL)
    return XmlClass::RESULT_Ok;

  for (XMLSize_t i = 0; i < list->getLength(); i++)
  {
    if (list->item(i) == NULL)
      continue;

    short type = list->item(i)->getNodeType();
    XERCES_CPP_NAMESPACE::DOMNode * node = list->item(i);

    if (type == XERCES_CPP_NAMESPACE::DOMNode::ELEMENT_NODE)
    {
      if (_tcscmp(node->getNodeName(), _T("bonuslist")) == 0)
     {
       XmlBonuslistReader BonuslistReader;
       BonuslistReader.Fill(*node, aPropoints.GetBonuslist());
     }
      else if (_tcscmp(node->getNodeName(), _T("sterrelots")) == 0)
     {
       XmlSterrelotsReader SterrelotsReader;
       SterrelotsReader.Fill(*node, aPropoints.GetSterrelots());
     }
      else if (_tcscmp(node->getNodeName(), _T("strategybase")) == 0)
     {
       XmlStrategybaseReader StrategybaseReader;
       StrategybaseReader.Fill(*node, aPropoints.GetStrategybase());
     }
   }
  }
  return XmlClass::RESULT_Ok;
}


}


