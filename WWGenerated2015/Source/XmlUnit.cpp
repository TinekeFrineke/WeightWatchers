#include "stdafx.h"
#include "XmlUnit.h"

#include <assert.h>
#include <tchar.h>


namespace ww2015
{
XmlUnit::XmlUnit()
{
}

XmlUnit::~XmlUnit()
{
}

std::wstring XmlUnit::Getnaam() const
{
  return mnaam;
}

void XmlUnit::Setnaam(const std::wstring & anaam)
{
   mnaam = anaam;
}

}