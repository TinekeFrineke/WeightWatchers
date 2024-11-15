#include "stdafx.h"
#include "XmlRecept.h"

#include <assert.h>
#include <tchar.h>


namespace ww2015
{
XmlRecept::XmlRecept()
{
}

XmlRecept::~XmlRecept()
{
}

std::wstring XmlRecept::Getnaam() const
{
  return mnaam;
}

std::wstring XmlRecept::Getpunten() const
{
  return mpunten;
}

std::wstring XmlRecept::Gethoeveelheid() const
{
  return mhoeveelheid;
}

void XmlRecept::Setnaam(const std::wstring & anaam)
{
   mnaam = anaam;
}

void XmlRecept::Setpunten(const std::wstring & apunten)
{
   mpunten = apunten;
}

void XmlRecept::Sethoeveelheid(const std::wstring & ahoeveelheid)
{
   mhoeveelheid = ahoeveelheid;
}

}