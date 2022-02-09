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
	MyPoint(MyPoint&& oth);
	void GetCoords(int& x, int& y) const;
	void PrintPoint() const;
	MyPoint& operator =(const MyPoint&);
	MyPoint& operator+=(const MyPoint&);
	MyPoint& operator+=(int inc);
	MyPoint operator+(const MyPoint&) const;
	MyPoint operator+(int) const;
	const MyPoint& operator+() const;
	//TODO + by class 

	friend MyPoint operator-(const MyPoint&);
	friend MyPoint operator+(const int&, const MyPoint&);
	friend MyPoint operator-(const MyPoint&, const MyPoint&);
	friend MyPoint operator-(const MyPoint&, int);
	friend MyPoint& operator -=(MyPoint&, const MyPoint&);


};
