#pragma once
#include "../Interface\Generated\stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "../Interface\Generated\XmlClass.h"

// forward declarations
namespace ww_1_2 { class XmlPersonalia; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMElement;
class DOMNode;
class DOMDocument;
XERCES_CPP_NAMESPACE_END

namespace ww_1_2
{
class XmlPersonaliaWriter : public XmlClass
{
public:
  XmlClass::eRESULT Write(const std::wstring & aFilename, const XmlPersonalia & aPersonalia);
  void Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlPersonalia & aPersonalia, XERCES_CPP_NAMESPACE::DOMElement & anElement);
};


}
