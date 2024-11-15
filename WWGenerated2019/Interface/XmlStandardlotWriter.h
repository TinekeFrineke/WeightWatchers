#pragma once
#include "../Interface/stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "../Interface/XmlClass.h"

// forward declarations
namespace ww2019 { class XmlStandardlot; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMElement;
class DOMNode;
class DOMDocument;
XERCES_CPP_NAMESPACE_END

namespace ww2019
{
class XmlStandardlotWriter : public XmlClass
{
public:
  XERCES_CPP_NAMESPACE::DOMNode * Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlStandardlot & aStandardlot);
  void Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlStandardlot & aStandardlot, XERCES_CPP_NAMESPACE::DOMElement & anElement);
};


}
