#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlUnit.h"

#include <assert.h>
#include <tchar.h>


namespace ww_1_2
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