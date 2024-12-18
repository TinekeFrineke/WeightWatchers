//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================

#include "XmlReceptdefsWriter.h"

#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>

#include "XmlReceptdefs.h"

#include "XmlReceptdefWriter.h"
#include "XmlReceptdef.h"
namespace ww2024
{
XmlClass::Result XmlReceptdefsWriter::Write(const std::wstring & aFilename, const XmlReceptdefs & aReceptdefs)
{
    ParseErrorHandler eh;
    XERCES_CPP_NAMESPACE::XercesDOMParser parser;
    parser.setDoValidation(false);
    parser.setErrorHandler(&eh);

    XERCES_CPP_NAMESPACE::DOMImplementation* impl =
      XERCES_CPP_NAMESPACE::DOMImplementationRegistry::getDOMImplementation(L"Core");

    XERCES_CPP_NAMESPACE::DOMDocument* doc =
      impl->createDocument(0,               // root element namespace URI.
                           L"receptdefs",  // root element name
                           0);              // document type object (Xml).
    XERCES_CPP_NAMESPACE::DOMElement* rootelement = doc->getDocumentElement();
    Fill(*doc, aReceptdefs, *rootelement);

    XERCES_CPP_NAMESPACE::DOMWriter* writer = ((XERCES_CPP_NAMESPACE::DOMImplementationLS*)impl)->createDOMWriter();
    XERCES_CPP_NAMESPACE::LocalFileFormatTarget formatter(aFilename.c_str());
    writer->writeNode(&formatter, *doc);
    writer->release();

    doc->release();

    return Result::Ok;
}


void XmlReceptdefsWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlReceptdefs & aReceptdefs, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

    XmlReceptdefWriter Receptdefwriter;
    for (size_t i = 0; i < aReceptdefs.GetReceptdefList().size(); ++i)
    {
        XERCES_CPP_NAMESPACE::DOMNode * Receptdefnode = Receptdefwriter.Write(aDocument, *aReceptdefs.GetReceptdefList()[i]);
        anElement.appendChild(Receptdefnode);
    }
}


}
