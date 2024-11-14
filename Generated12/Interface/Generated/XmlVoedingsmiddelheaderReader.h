#pragma once
#include "../Interface\Generated\stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "../Interface\Generated\XmlClass.h"

// forward declarations
namespace ww_1_2 { class XmlVoedingsmiddelheader; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_2
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
