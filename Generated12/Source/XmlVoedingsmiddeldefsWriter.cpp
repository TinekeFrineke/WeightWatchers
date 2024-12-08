#include "../Interface\Generated\stdafx.h"

#include "../Interface\Generated\XmlVoedingsmiddeldefs.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "../Interface\Generated\XmlVoedingsmiddeldefWriter.h"
#include "../Interface\Generated\XmlVoedingsmiddeldef.h"
#include "../Interface\Generated\XmlVoedingsmiddeldefsWriter.h"

namespace ww_1_2
{
XmlClass::eRESULT XmlVoedingsmiddeldefsWriter::Write(const std::wstring & aFilename, const XmlVoedingsmiddeldefs & aVoedingsmiddeldefs)
{
  ParseErrorHandler eh;
  XERCES_CPP_NAMESPACE::XercesDOMParser parser;
  parser.setDoValidation(false);
  parser.setErrorHandler(&eh);

  XERCES_CPP_NAMESPACE::DOMImplementation * impl =
    XERCES_CPP_NAMESPACE::DOMImplementationRegistry::getDOMImplementation(L"Core");

  XERCES_CPP_NAMESPACE::DOMDocument * doc =
    impl->createDocument(0,               // root element namespace URI.
                         L"voedingsmiddeldefs",  // root element name
                         0);              // document type object (Xml).
  XERCES_CPP_NAMESPACE::DOMElement * rootelement = doc->getDocumentElement();
  Fill(*doc, aVoedingsmiddeldefs, *rootelement);

  XERCES_CPP_NAMESPACE::DOMWriter * writer = ((XERCES_CPP_NAMESPACE::DOMImplementationLS*)impl)->createDOMWriter();
  XERCES_CPP_NAMESPACE::LocalFileFormatTarget formatter(aFilename.c_str());
  writer->writeNode(&formatter, *doc);
  writer->release();

  doc->release();

  return RESULT_Ok;
}


void XmlVoedingsmiddeldefsWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVoedingsmiddeldefs & aVoedingsmiddeldefs, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

  XmlVoedingsmiddeldefWriter Voedingsmiddeldefwriter;
  for (size_t i = 0; i < aVoedingsmiddeldefs.GetVoedingsmiddeldefList().size(); ++i)
  {
    XERCES_CPP_NAMESPACE::DOMNode * Voedingsmiddeldefnode = Voedingsmiddeldefwriter.Write(aDocument, *aVoedingsmiddeldefs.GetVoedingsmiddeldefList()[i]);
    anElement.appendChild(Voedingsmiddeldefnode);
  }
}


}
