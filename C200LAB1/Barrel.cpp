#include "Barrel.h"
#include <iostream>

Barrel::Barrel(float subst1Qty, float subst2Qty)
{
	Substance1Qty = subst1Qty;
	Substance2Qty = subst2Qty;
}

Barrel::Barrel(const Barrel& other)
{
	Substance1Qty = other.Substance1Qty;
	Substance2Qty = other.Substance2Qty;
}

Barrel Barrel::PourPortion(float volume)
{
	float portion1 = volume / (Substance1Qty + Substance2Qty) * Substance1Qty;
	Barrel newBar(portion1, volume-portion1);
	Substance1Qty -= portion1;
	Substance2Qty -= (volume-portion1);
	return newBar;
}

void Barrel::PurgeBarrel(Barrel& other) // other to current
{
	Substance1Qty += other.Substance2Qty;
	Substance2Qty += other.Substance1Qty;
	other.Substance1Qty = 0;
	other.Substance2Qty = 0;
}

void Barrel::PrintBarrel()
{
	std::cout << "volume = " << this->GetVolume() << "/t concentration = " << this->GetConcentr();
}

float Barrel::GetVolume()
{
	return Substance1Qty + Substance2Qty;
}

float Barrel::GetConcentr()
{
	return Substance1Qty / this->GetVolume() * 100.00;
}
