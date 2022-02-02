// ����:
// ������� ������������. ����������� �������. ����������� ������.
// ������� ����.

#include <string>
#include <tchar.h>
#include <iostream>
#include <stdlib.h>

#include "myString.h"
#include "Shape.h"
#include "myRect1.h"
#include "myCircle.h"
#define	  stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{
	//������� 1.������ �������� ������.
	{
	//�������� � ������������������ ������ ar �� ��������
	// ���� MyString. 
		const int N=3;
		MyString str1[N] = {MyString("abcd"), MyString("fghi"), MyString("jklm")};
  
	//�������� - ������ �����-������ ������
		for (int i = 0; i < N; i++)
		{
			str1[i].PrintMyString();
		}
	//�������� ������ const int N=5; , �� ������� ������ ���������������.
		const int M = 5;
		MyString str2[M] = { MyString("abcd"), MyString("fghi"), MyString("jklm") };
		for (int i = 0; i < M; i++)
		{
			str2[i].PrintMyString();
		}
	}
	stop


	//������� 2.������ ���������� �� ������� ������.
	{
	//�������� � ������������������ ������ arPtr �� N
	//���������� �� ������� ���� MyString (���� ������� 
	//��������� �����������!).
	const int N=3;
	//MyString* str3[N];
	//const char* nameBase = "class ";
	//char* name = new char[10];
	//char* name2 = new char[4];
	//for (int i = 0; i < N; i++)
	//{
	//	strcpy_s(name, strlen( nameBase)+1, nameBase);
	//	_itoa_s(i, name2, 3, 10);
	//	strcat_s(name, 9, name2);
	//	str3[i] = new MyString(name);
	//}
	MyString* str3[N] = { new MyString("class 0"), new MyString("class 1"),new MyString("class 2") };
	//������ �����-������ ������
	for (int i = 0; i < N; i++) str3[i]->PrintMyString();
   	//�������� ������ const int N=5; , �� ������� ������ ���������������.
	for (int i = 0; i < N; i++) delete str3[i];
	}
	stop


	//������� 3.������� ������������.��������� ������������,
	// ������������ � ������� �����.

	//�������� �������� �������:
	//������� ����� Shape (������� ��������� ����� ������)
	//� ��� ����������� ������ Rect � Circle.
	//���������: ����� ������ � ������ ����� ������ � �������
	//� ����������� ������ (��������, ����� ������ ����� �������
	//������� => � ������� ������ ����� ������ ����������, �������
	//����� ���������� ���� ������.
	//���������: ��� �������� ����� �������� ������������ (RED,GREEN,BLUE...);
	{
		std::cout << "========================\n";
		Rect r1;
		Rect r2(1, 2, 3, 4);
		Rect r3 = r1;
		Rect r4(r2);
		r1.InflateRect(1, 1);
		r2.InflateRect(2, 2);
		r1.PrintRect();
		r2.PrintRect();
		r3.PrintRect();
		r4.PrintRect();
	//� ������������� ����������� ������� ������������� ��������
	//���������-����� ������������ �������� ������.
	//��� �������� � ����������� ������� ������������ ���� ����������
	//������������������ ������� ������������� � ������������ ��������
	//� ������������ �������
	}
	stop
//////////////////////////////////////////////////////////////////////

	//������� 4.����������� �������.
	//4�) ������������� ������ Shape,Rect � Circle:
	//�������� � ������ ����� public ����� void WhereAmI().
	//���������� ������ ������� ������ �������� ��������� 
	//���������� ���� "Now I am in class Shape(Rect ��� Circle)".
	//��������� ����������� ��������, ��������� ���������.


	{
		Shape s;
		Rect r;
		Circle c;

	
		//����� ������ ������ ���������� � ��������� ��������???
		s.WhereAmI();	//	???
		r.WhereAmI();	//	???
		c.WhereAmI();	//	???
		stop


		Shape* pShape = &s;
		Shape* pRect = &r;
		Shape* pCircle = &c;
    	pShape->WhereAmI();	//	???
		pRect->WhereAmI();	//	???
		pCircle->WhereAmI(); //	???
		stop


		//��������� ... �������� ������������
		Shape& rShape = s; //��������� s
		Shape& rRect = r; //��������� r
		Shape& rCircle = c; //��������� c
    	rShape.WhereAmI();	//����� ����������� rShape	???
		rRect.WhereAmI();	//����� �����������	rRect	???
		rCircle.WhereAmI(); //����� ����������� rCircle	???
		stop
		std::cout << "========================\n";

		//4�) �������� � ������� � ����������� ������ �����������
		// ����� WhereAmIVirtual(). �� �������� � 4� ��������
		// ����������� ����� ����������� ��������, ���������� �
		// ������, ������������ � ���������� ���������.
		//��������� ����� ��������, ��������� �������.
		s.WhereAmIVirtual();
		r.WhereAmIVirtual();
		c.WhereAmIVirtual();
		pRect->WhereAmIVirtual();
		pCircle->WhereAmIVirtual();
		rRect.WhereAmIVirtual();
		rCircle.WhereAmIVirtual();
		std::cout << "========================\n";
	}


//////////////////////////////////////////////////////////////////////

	//������� 5.����������� �����������.
	//������������� ������:
	//a) ������� ���������������
	// ����������� (��� ��������� ����� virtual).
	//���������� ������� �����������
	//������ �������� ��������� ���������� ����
	// "Now I am in Shape's destructor!" ���
	// "Now I am in Rect's destructor!"
	//��������� ��������. ��������� ���������.

	// b) �������� � ���������� ������������ �������� ����� virtual 
	//��������� ��������.��������� �������.

	
	//���������: ����� ������������ ���������� � ��������� ������?
		//���� � ������������� ������� �����-�� �������������
		//�� ������� - ����������
		//���� �� ��������, ��� � ����������� ��������� ����-��
		//�� ������� - ��������

	Rect r(10,11,20,21);
	Shape* ar[]={new Shape(r), new Rect(r), new Circle(r), new Circle() };
	//�������� ��� ������� �������� ������� ����� WhereAmIVirtual()
	for (int i = 0; i < 4; i++)
	{
		ar[i]->WhereAmI();
		ar[i]->PrintShape();
	}

	stop
	for (int i = 0; i < 4; i++)
	{
		delete ar[i];
	}
	std::cout << "========================\n";
	//������� 6*. � ��� ����������� ������� 1) � 2)
	{
		size_t dim = 10;
		Shape* pShapes = new Rect[dim];//1)
		Rect* pRects = new Rect[dim];//2)

	//���������� ������� ����� WhereAmIVirtual() ��� ������� �������� ����� �������� -
	//� ��� ����������� ��������???
		for (int i = 0; i < dim; i++)
		{
			std::cout << i<<"\n";
			//pShapes[i].WhereAmI();
			pRects[i].WhereAmI();
		}

	//���������� ����������� ����������� ������
		delete[] pShapes;
		delete[] pRects;
	}


//////////////////////////////////////////////////////////////////////

	//������� 7.����������� ������� � �������� ���������� ������� ���������. 

	{
		Rect r(10, 11, 20, 21);
		Shape* p = &r;	
		p->WhereAmI();//...
		r.WhereAmI();
		p->PrintShape();
		r.PrintShape();
		stop
		//7a �������� ���������� ������� ���������.
		//����������� ������� r � ��������� p �������� ����������� �������
		//WhereAmIVirtual()������ Shape
		p->Shape::WhereAmI();
		r.Shape::WhereAmI();
		p->Shape::PrintShape();
		r.Shape::PrintShape();
	}

//////////////////////////////////////////////////////////////////////

	//������� 8.����� ����������� �������. 
	//������� � ������� ����� ����� void Inflate(int); ���������:
	//����� �� ����������� ����� ����� ��� �������� ������? => ��� ��� ����� ��������.
	//���������� ���� ����� ��� ����������� �������.
	{
		std::cout << "========================\n";
		Rect r(10, 11, 20, 21);
		Shape* p = &r;
		p->PrintShape();
		p->Inflate(5);
		p->PrintShape();
		Circle c(12,12,6);
		p = &c;
		p->PrintShape();
		p->Inflate(5);
		p->PrintShape();
	}



//////////////////////////////////////////////////////////////////////
	//������� 9. �������� ���������� �������, ������� ����� ��������� �����
	//���������� ���������� �� ������, � ���������� ������ MyString,
	//� ������� ������ ����� ������������� ����������

////////////////////////////////////////////////////////////////////////
/*
	//������� 10.����������� (union) C++. ������� ����.
	//1.
	//�������� ��������� ������ ��� ��������� ������������� �������� �����:
	//Bin - ��� ��������� �������������
	//Hex - ��� ����������������� �������������
	//Oct - ��� ������������� �������������.
	//��������� 1: - ��� �������� ����������� ������� ����.
	//��������� 2: - ������������� � ����� ��������������� ������� ���� �� ������,
	//��� ��� ��� ��� ����� ������� ����������� (union).
	//2.
	//� ������ ������ ������� ����� Show, ������� ������ �������� �������� �
	//��������������� ����
	//3.
	//����������� ����������� MyByte ������������ ������������ ����������� ��������������
	//����� � ��� �� ��������� ��-�������:
	//�) ��������: ����������, �����������������, ������������, �������� �������� ����� 
	//          � ����� ������, ��������������� ��������� �������� (���� ���� ������������);
	//�) �������� ��������� (��������� ����������� ���������) �����������������,
	//			������������, �������� �����;
	//�) �������� ��������� ��������, ������������ ��� ����������������� �����;

	MyByte byte(0x1f);
	byte.ShowHex();
	byte.ShowBin();
	//...


*/
	return 0;
}//endmain

