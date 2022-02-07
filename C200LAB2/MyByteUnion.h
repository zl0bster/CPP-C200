#pragma once
class Bin
{
	unsigned char b0:1;
	unsigned char b1:1;
	
	void show() const;
	friend union MyUnion;
};

union MyUnion
{
private:
	unsigned char bt;
	Bin b;

public:
	void ShowBin() const { b.show(); };
};
