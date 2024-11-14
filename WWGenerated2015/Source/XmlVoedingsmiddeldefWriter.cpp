#include "stdafx.h"

#include "XmlVoedingsmiddeldef.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "XmlVoedingswaardeWriter.h"
#include "XmlVoedingswaarde.h"
#include "XmlPuntenper100Writer.h"
#include "XmlPuntenper100.h"
#include "XmlVoedingsmiddelheaderWriter.h"
#include "XmlVoedingsmiddelheader.h"
#include "XmlPortieWriter.h"
#include "XmlPortie.h"
#include "XmlVoedingsmiddeldefWriter.h"

namespace ww2015
{
XERCES_CPP_NAMESPACE::DOMNode * XmlVoedingsmiddeldefWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVoedingsmiddeldef & aVoedingsmiddeldef)
{
  XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("voedingsmiddeldef"));
  Fill(aDocument, aVoedingsmiddeldef, *element);
  return element;
}

void XmlVoedingsmiddeldefWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVoedingsmiddeldef & aVoedingsmiddeldef, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

  XmlVoedingswaardeWriter Voedingswaardewriter;
  if (aVoedingsmiddeldef.GetVoedingswaarde() != NULL)
    anElement.appendChild(Voedingswaardewriter.Write(aDocument, *aVoedingsmiddeldef.GetVoedingswaarde()));

  XmlPuntenper100Writer Puntenper100writer;
  if (aVoedingsmiddeldef.GetPuntenper100() != NULL)
    anElement.appendChild(Puntenper100writer.Write(aDocument, *aVoedingsmiddeldef.GetPuntenper100()));

  XmlVoedingsmiddelheaderWriter Voedingsmiddelheaderwriter;
  anElement.appendChild(Voedingsmiddelheaderwriter.Write(aDocument, aVoedingsmiddeldef.GetVoedingsmiddelheader()));

  XmlPortieWriter Portiewriter;
  for (size_t i = 0; i < aVoedingsmiddeldef.GetPortieList().size(); ++i)
  {
    XERCES_CPP_NAMESPACE::DOMNode * Portienode = Portiewriter.Write(aDocument, *aVoedingsmiddeldef.GetPortieList()[i]);
    anElement.appendChild(Portienode);
  }
  switch (aVoedingsmiddeldef.Getfavoriet())
  {
    case XmlVoedingsmiddeldef::favoriet_true:
      anElement.setAttribute(_T("favoriet"), _T("true"));
    break;
    case XmlVoedingsmiddeldef::favoriet_false:
      anElement.setAttribute(_T("favoriet"), _T("false"));
    break;
    default:
      throw 1;
  }
}


}
