#include "stdafx.h"
#include "XmlPuntenper100.h"

#include <assert.h>
#include <tchar.h>


namespace ww_1_1
{
XmlPuntenper100::XmlPuntenper100()
{
}

XmlPuntenper100::~XmlPuntenper100()
{
}

std::wstring XmlPuntenper100::Getpunten() const
{
  return mpunten;
}

void XmlPuntenper100::Setpunten(const std::wstring & apunten)
{
   mpunten = apunten;
}

}