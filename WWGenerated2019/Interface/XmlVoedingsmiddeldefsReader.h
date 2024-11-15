#pragma once
#include "../Interface/stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "../Interface/XmlClass.h"

// forward declarations
namespace ww2019{ class XmlVoedingsmiddeldefs; }
XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2019
{
class XmlVoedingsmiddeldefsReader : public XmlClass
{
public:
  XmlVoedingsmiddeldefsReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlVoedingsmiddeldefs *& aVoedingsmiddeldefs);
  XmlVoedingsmiddeldefs * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddeldefs & aVoedingsmiddeldefs);

private:
  // Prohibit copying and assignment
  XmlVoedingsmiddeldefsReader(const XmlVoedingsmiddeldefsReader & anOriginal);
  XmlVoedingsmiddeldefsReader & operator=(const XmlVoedingsmiddeldefsReader & anOriginal);
};


}
