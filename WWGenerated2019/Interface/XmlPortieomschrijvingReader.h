#pragma once
#include "../Interface/stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "../Interface/XmlClass.h"

// forward declarations
namespace ww2019 { class XmlPortieomschrijving; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2019
{
class XmlPortieomschrijvingReader : public XmlClass
{
public:
  XmlPortieomschrijvingReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlPortieomschrijving *& aXmlPortieomschrijving);
  XmlPortieomschrijving * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPortieomschrijving & Portieomschrijving);

private:
  // Prohibit copying and assignment
  XmlPortieomschrijvingReader(const XmlPortieomschrijvingReader & anOriginal);
  XmlPortieomschrijvingReader & operator=(const XmlPortieomschrijvingReader & anOriginal);
};


}