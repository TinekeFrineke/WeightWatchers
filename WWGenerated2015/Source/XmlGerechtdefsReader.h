#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

// forward declarations
namespace ww2015{ class XmlGerechtdefs; }
XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2015
{
class XmlGerechtdefsReader : public XmlClass
{
public:
  XmlGerechtdefsReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlGerechtdefs *& aGerechtdefs);
  XmlGerechtdefs * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlGerechtdefs & aGerechtdefs);

private:
  // Prohibit copying and assignment
  XmlGerechtdefsReader(const XmlGerechtdefsReader & anOriginal);
  XmlGerechtdefsReader & operator=(const XmlGerechtdefsReader & anOriginal);
};


}
