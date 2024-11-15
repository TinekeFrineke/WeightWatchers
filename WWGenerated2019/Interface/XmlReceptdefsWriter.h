#pragma once
#include "../Interface/stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "../Interface/XmlClass.h"

// forward declarations
namespace ww2019 { class XmlReceptdefs; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMElement;
class DOMNode;
class DOMDocument;
XERCES_CPP_NAMESPACE_END

namespace ww2019
{
class XmlReceptdefsWriter : public XmlClass
{
public:
  XmlClass::eRESULT Write(const std::wstring & aFilename, const XmlReceptdefs & aReceptdefs);
  void Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlReceptdefs & aReceptdefs, XERCES_CPP_NAMESPACE::DOMElement & anElement);
};


}
