#include "stdafx.h"

#include "XmlStrategybase.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "XmlStrategybaseWriter.h"

namespace ww2015
{
XERCES_CPP_NAMESPACE::DOMNode * XmlStrategybaseWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlStrategybase & aStrategybase)
{
  XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("strategybase"));
  Fill(aDocument, aStrategybase, *element);
  return element;
}

void XmlStrategybaseWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlStrategybase & aStrategybase, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
  (void)aDocument;
  (void)aStrategybase;
  (void)anElement;
}


}