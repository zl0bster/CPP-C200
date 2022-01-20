#pragma once
class Shape
{
	static size_t counter;
public:
	enum eColor{ BLACK = 0, RED =1, BLUE =4, YELLOW = 8, WHITE=255};
private:
	size_t m_id;
	eColor m_color;
public:
	Shape(eColor col = eColor::WHITE);
	Shape(const Shape& other);
	~Shape();
	inline void set_color(eColor col)
	{
		m_color = col;
	};
	inline eColor get_color() const
	{
		return m_color;
	};
	inline size_t get_id() const
	{
		return m_id;
	}
	virtual void WhereAmI() const;
	virtual void PrintShape() const;
};

