#pragma once
class Bin
{
	unsigned char b0:1;
	unsigned char b1:1;
	unsigned char b2:1;
	unsigned char b3:1;
	unsigned char b4:1;
	unsigned char b5:1;
	unsigned char b6:1;
	unsigned char b7:1;
	
	void show() const;
	void showPos(size_t pos) const;
	void edit(size_t pos, size_t val);
	friend union MyUnion;
};

class Oct
{
	unsigned char oct0:3;
	unsigned char oct1:3;
	unsigned char oct2:2;

	void show() const;
	void showPos(size_t pos)  const;
	void edit(size_t pos, size_t val);
	friend union MyUnion;
};

class Hex
{
	unsigned char hex0:4;
	unsigned char hex1:4;
	
	void show() const;
	void showPos(size_t pos) const;
	void edit(size_t pos, size_t val);
	friend union MyUnion;
};

union MyUnion
{
private:
	unsigned char bt;
	Bin b;
	Oct o;
	Hex h;
public:
	MyUnion(unsigned char byte);
	void ShowBin() const { b.show(); };
	void ShowOct() const { o.show(); };
	void ShowHex() const { h.show(); };
	void EditBin(size_t pos, size_t val) { b.edit(pos, val); };
	void EditOct(size_t pos, size_t val) { o.edit(pos, val); };
	void EditHex(size_t pos, size_t val) { h.edit(pos, val); };
};
