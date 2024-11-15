#pragma once
#include "../Interface/stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "../Interface/XmlClass.h"

// forward declarations
namespace ww2019 { class XmlVoedingsmiddelheader; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2019
{
class XmlVoedingsmiddelheaderReader : public XmlClass
{
public:
  XmlVoedingsmiddelheaderReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlVoedingsmiddelheader *& aXmlVoedingsmiddelheader);
  XmlVoedingsmiddelheader * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddelheader & Voedingsmiddelheader);

private:
  // Prohibit copying and assignment
  XmlVoedingsmiddelheaderReader(const XmlVoedingsmiddelheaderReader & anOriginal);
  XmlVoedingsmiddelheaderReader & operator=(const XmlVoedingsmiddelheaderReader & anOriginal);
};


}