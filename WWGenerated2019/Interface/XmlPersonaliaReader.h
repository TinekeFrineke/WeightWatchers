#pragma once
#include "../Interface/stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "../Interface/XmlClass.h"

// forward declarations
namespace ww2019{ class XmlPersonalia; }
XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2019
{
class XmlPersonaliaReader : public XmlClass
{
public:
  XmlPersonaliaReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlPersonalia *& aPersonalia);
  XmlPersonalia * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPersonalia & aPersonalia);

private:
  // Prohibit copying and assignment
  XmlPersonaliaReader(const XmlPersonaliaReader & anOriginal);
  XmlPersonaliaReader & operator=(const XmlPersonaliaReader & anOriginal);
};


}
