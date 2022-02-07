#pragma once
class MyPoint
{
	static size_t counter;
private:
	int mx = 0;
	int my = 0;
	size_t m_id;
public:
	MyPoint(int x=0, int y=0);
	~MyPoint();
	MyPoint(const MyPoint& oth);
	void GetCoords(int& x, int& y) const;
	void PrintPoint() const;
	//MyPoint& operator =(const MyPoint&);
	MyPoint& operator +=(const MyPoint&);
	MyPoint& operator +=(int inc);
	friend MyPoint& operator -=(MyPoint&, const MyPoint&);
	//MyPoint& operator +
};
