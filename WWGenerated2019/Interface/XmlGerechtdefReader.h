#pragma once
#include "../Interface/stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "../Interface/XmlClass.h"

// forward declarations
namespace ww2019 { class XmlGerechtdef; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2019
{
class XmlGerechtdefReader : public XmlClass
{
public:
  XmlGerechtdefReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlGerechtdef *& aXmlGerechtdef);
  XmlGerechtdef * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlGerechtdef & Gerechtdef);

private:
  // Prohibit copying and assignment
  XmlGerechtdefReader(const XmlGerechtdefReader & anOriginal);
  XmlGerechtdefReader & operator=(const XmlGerechtdefReader & anOriginal);
};


}
