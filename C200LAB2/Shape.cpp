#include "Shape.h"
#include <stdio.h>

size_t Shape::counter = 0;

Shape::Shape(eColor col)
{
	m_id = counter++;
	m_color = col;
	printf("def created ID %d\n", m_id);
}

Shape::Shape(const Shape& other)
{
	m_color = other.m_color;
	m_id = counter++;
	printf("cpy created ID %d\n", m_id);
}

Shape::~Shape()
{
	printf("destroyed ID %d\n", m_id);
}

void Shape::PrintShape() const
{
	printf("---\n ID %d\n", get_id());
	printf(" color = %d \n", get_color());
}

void Shape::WhereAmIVirtual() const
{
	printf("It is virtual Shape \n");
}

void Shape::Inflate(int)
{
}

void Shape::WhereAmI() const
{
	printf("It is Shape Object\n");
}
