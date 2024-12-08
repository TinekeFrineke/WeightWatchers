#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlPersonalia.h"

#include <assert.h>
#include <tchar.h>


namespace ww_1_2
{
XmlPersonalia::XmlPersonalia()
: mgeslacht(geslacht_Mannelijk)
, mwerk(werk_Zittend)
, mstreven(streven_Afvallen)
, mstrategie(strategie_ProPoints)

{
}

XmlPersonalia::~XmlPersonalia()
{
}

std::wstring XmlPersonalia::Getnaam() const
{
  return mnaam;
}

std::wstring XmlPersonalia::Getgebruikersnaam() const
{
  return mgebruikersnaam;
}

std::wstring XmlPersonalia::Getpunten() const
{
  return mpunten;
}

std::wstring XmlPersonalia::Getpppunten() const
{
  return mpppunten;
}

std::wstring XmlPersonalia::Getppweekpunten() const
{
  return mppweekpunten;
}

std::wstring XmlPersonalia::Getkcpunten() const
{
  return mkcpunten;
}

std::wstring XmlPersonalia::Getkcweekpunten() const
{
  return mkcweekpunten;
}

std::wstring XmlPersonalia::Getchpunten() const
{
  return mchpunten;
}

std::wstring XmlPersonalia::Getchweekpunten() const
{
  return mchweekpunten;
}

std::wstring XmlPersonalia::Getgeboren() const
{
  return mgeboren;
}

XmlPersonalia::geslacht XmlPersonalia::Getgeslacht() const
{
  return mgeslacht;
}

XmlPersonalia::werk XmlPersonalia::Getwerk() const
{
  return mwerk;
}

std::wstring XmlPersonalia::Getlengte() const
{
  return mlengte;
}

std::wstring XmlPersonalia::Getgewicht() const
{
  return mgewicht;
}

std::wstring XmlPersonalia::Getstreefgewicht() const
{
  return mstreefgewicht;
}

std::wstring XmlPersonalia::Getstartgewicht() const
{
  return mstartgewicht;
}

std::wstring XmlPersonalia::Gethuidiggewicht() const
{
  return mhuidiggewicht;
}

XmlPersonalia::streven XmlPersonalia::Getstreven() const
{
  return mstreven;
}

XmlPersonalia::strategie XmlPersonalia::Getstrategie() const
{
  return mstrategie;
}

void XmlPersonalia::Setnaam(const std::wstring & anaam)
{
   mnaam = anaam;
}

void XmlPersonalia::Setgebruikersnaam(const std::wstring & agebruikersnaam)
{
   mgebruikersnaam = agebruikersnaam;
}

void XmlPersonalia::Setpunten(const std::wstring & apunten)
{
   mpunten = apunten;
}

void XmlPersonalia::Setpppunten(const std::wstring & apppunten)
{
   mpppunten = apppunten;
}

void XmlPersonalia::Setppweekpunten(const std::wstring & appweekpunten)
{
   mppweekpunten = appweekpunten;
}

void XmlPersonalia::Setkcpunten(const std::wstring & akcpunten)
{
   mkcpunten = akcpunten;
}

void XmlPersonalia::Setkcweekpunten(const std::wstring & akcweekpunten)
{
   mkcweekpunten = akcweekpunten;
}

void XmlPersonalia::Setchpunten(const std::wstring & achpunten)
{
   mchpunten = achpunten;
}

void XmlPersonalia::Setchweekpunten(const std::wstring & achweekpunten)
{
   mchweekpunten = achweekpunten;
}

void XmlPersonalia::Setgeboren(const std::wstring & ageboren)
{
   mgeboren = ageboren;
}

void XmlPersonalia::Setgeslacht(geslacht ageslacht)
{
   mgeslacht = ageslacht;
}

void XmlPersonalia::Setwerk(werk awerk)
{
   mwerk = awerk;
}

void XmlPersonalia::Setlengte(const std::wstring & alengte)
{
   mlengte = alengte;
}

void XmlPersonalia::Setgewicht(const std::wstring & agewicht)
{
   mgewicht = agewicht;
}

void XmlPersonalia::Setstreefgewicht(const std::wstring & astreefgewicht)
{
   mstreefgewicht = astreefgewicht;
}

void XmlPersonalia::Setstartgewicht(const std::wstring & astartgewicht)
{
   mstartgewicht = astartgewicht;
}

void XmlPersonalia::Sethuidiggewicht(const std::wstring & ahuidiggewicht)
{
   mhuidiggewicht = ahuidiggewicht;
}

void XmlPersonalia::Setstreven(streven astreven)
{
   mstreven = astreven;
}

void XmlPersonalia::Setstrategie(strategie astrategie)
{
   mstrategie = astrategie;
}

}