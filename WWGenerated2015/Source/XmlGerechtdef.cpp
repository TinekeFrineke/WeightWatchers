#include "stdafx.h"
#include "XmlGerechtdef.h"

#include <assert.h>
#include <tchar.h>


namespace ww2015
{
XmlGerechtdef::XmlGerechtdef()
{
}

XmlGerechtdef::~XmlGerechtdef()
{
}

std::wstring XmlGerechtdef::Getnaam() const
{
  return mnaam;
}

std::wstring XmlGerechtdef::Getpunten() const
{
  return mpunten;
}

void XmlGerechtdef::Setnaam(const std::wstring & anaam)
{
   mnaam = anaam;
}

void XmlGerechtdef::Setpunten(const std::wstring & apunten)
{
   mpunten = apunten;
}

}