#pragma once
class Barrel
{
	float Substance1Qty; //in litres
	float Substance2Qty; //in litres
public:
	//Barrel();
	Barrel(float subst1Qty=0, float subst2Qty = 0);
	Barrel(const Barrel& other);
	Barrel PourPortion(float volume);
	void PurgeBarrel(Barrel& other);
	void PrintBarrel();
	float GetVolume();
	float GetConcentr();
};

