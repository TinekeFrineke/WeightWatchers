#pragma once
#include "../Interface/stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "../Interface/XmlClass.h"

// forward declarations
namespace ww2019 { class XmlRecept; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMElement;
class DOMNode;
class DOMDocument;
XERCES_CPP_NAMESPACE_END

namespace ww2019
{
class XmlReceptWriter : public XmlClass
{
public:
  XERCES_CPP_NAMESPACE::DOMNode * Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlRecept & aRecept);
  void Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlRecept & aRecept, XERCES_CPP_NAMESPACE::DOMElement & anElement);
};


}
