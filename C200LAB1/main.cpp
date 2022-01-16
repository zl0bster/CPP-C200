#include "myRect.h"
#include "myString.h"
#include "Barrel.h"

#include <iostream>

#define stop __asm nop

int main()
{
using namespace std;

	//������� 1.���������� ������. �������� ���������� ������.
	//����� ������� ������. 
	//�������� �������� Class View - (����� �� ������� ����� ������� �
	//������ - ������� Rect � MyString)
	//�������� �������� �� ����������� ����� �� ���� ������ ������ - ���
	//���������� ������������ ������� � ������� ����� ������.

	//����� ����������� ���������� ��� �������� ���������� ������?
	{
		Rect rect;
		rect.PrintRect();
		stop
	}

	//1a. �������� � ���������� ����������� � ����������� ���
	//������������� ���������� ������. �������� ��������� ������ Rect
	//� ������� ������������ � �����������. ���� ���������� ������
	//������ � ���������� ���������, ��������� - ���� ��� ��
	//�������? ��������� ���������� ������.
	//�������� ������� � ������ ������ �� �����, ����������:
	//� ����� ������ ���������� ����� ������������(������?)?

	//���������: ������, ��� ������������ ������ ������ ����� ���������
	//� �������� ���������� ����� ��������! ��������:
	 Rect rrr(4,3,2,1);
	 rrr.PrintRect();

	stop
	//1�. ��� ��������������� ������� ����������� ������������ ��� ����������
	//������������� ������������� ���������� ������, ��������, �����

	
	
	stop
	//1�. ��������, ���������� � �������� ����� ������ InflateRect(), 
	//������� ����������� ������� �������������� �� �������� ����������
	//(��������� ������� �� ������ - ������ ������� �� ���� ��������).
	//���������: �������� � ���������� ������ ����� �� ������ "�������",
	//�� � � ������� Wizard-a Class View. ��� �����: �������� ��������
	//ClassView ���� �������, �������� �������� ����� Rect � �������
	//������ ������ ���� - � ����������� ����������� ���� ��������
	//Add/Add Member Function... � ������� ����������� ���������� ������
	//"����� ��������" Wizard-� ��� �������� � ���������� �����.

	rrr.InflateRect();
	rrr.PrintRect();
	stop


	//������� 2.���������� ������������� � ������� ������.
	//����������� �����������.

	//2�.�������� � ���������� ����������� ����������� � ������ Rect.
	//�������� ������� �� �����, ����������, �����
	//����������� ���������� ��� �������� r1,r2,r3 � r4?
	//���� ����� ���������� ��������� ��������?
		Rect r1;
		Rect r2(1,2,3,4);
		Rect r3 = r1;
		Rect r4(r2);
		stop


  //2�. �������� � ���������� � ������ Rect ����� InflateRect(),
	//������� ��������� ��� ���������, �� ��������� ������ 1, � 
	//���������� ������� �������������� �� �� �������� ����������.
	//��� ����� �������� ���������� ������� InflateRect()?
		r1.InflateRect(1,1);	
		r2.InflateRect(2,2);
		r1.PrintRect();
		r2.PrintRect();
	//����� �� ������� InflateRect() ���������� � ������ �� ���� �������?
		r3.InflateRect(2,2,2,2);
		r3.PrintRect();
		r3.InflateRect(3,3);
		r3.PrintRect();
		r3.InflateRect(5);
		r3.PrintRect();
		r3.InflateRect();
		r3.PrintRect();
	stop


	
	//������� 3.������������� �������. ������������. 
	{
	Rect r;
	//���������������� ��������� ������. ��������� ������
	//�����������

//	int tmp = r.m_left;

	std::cout << "========================\n";

	//������� � ����� Rect ����� void SetAll(...),
	//������� ����������� ���������� ������ ������������
	//��������. �������� ��������� �����, ��������� ������������. 
	r1.SetAll(10,10,30,30);
	r1.PrintRect();
	r1.InflateRect();
	r1.PrintRect();
	//������� � ����� Rect ������ ����� GetAll(...),
	//������� "�������" �������� private-���������� ������.
	//�������� ��������� �����, ��������� ������������. 
	//int x1, y1, x2, y2;
	stop
	}


	//������� 4.�������� ���������� ������ � �������� ���������
	//�������. ����������� ������� ������ �� ��������. ��������
	//�������� � ������������ ����������� ��� �������� ��������
	//�� �����, ����������: � ����� ������ ���������� ���������
	//� ������������ �����������. 
	//�������� ���������� ������� 
	// Rect BoundingRect(Rect, Rect);
	//������� ��������� ��� ������� ������ Rect �� �������� �
	//���������� ������ ������ Rect, ������� �������� ���������������,
	//� ������� ������� �������� ��������������. ��� ����������
	//�������� ���������� � ����������� ������� ������?

	//���������*: ������ ���� �� ������ ��� ����, ��� �������������
	//����� ��������� "�����������������", �� ���� m_left>m_right ���/�
	//m_top>m_bottom

	{

		Rect r1(1,2,3,4), r2(5,6,7,8),r3;
		r3= BoundingRect(r1, r2);
		stop

		//������� 4�. �������� �������� �� ������.
		//�������� ���������� ������� BoundingRect2, ������� ��������� �� ��
		//������, �������� ��������� �� ������
		//���������� �� ������������ ��� �������� ����������?
		Rect r4(r1, r2);

	//r3 = BoundingRect2(r1, r2);
	stop
	}

	//������� 4�.���������� �� �� ������ (BoundingRect) ������� ������
	Rect r5;
	r5.BindRect(r2, r1);


	//������� 5. ����� ���������� ������������ � �����������.
	//�������� � ����������
	//����� ���������� ������. ��������� �������� � 
	//������������ (�������������) � �����������. ����������: ����� ���
	//������� �� �������� ���������� �����������, � ����� - ����������?
	{
		std::cout << "==========================\n";
		Rect r1;
		Rect*	pR = new Rect(1,2,1,2);	
		{
			Rect r2(r1);
			Rect arRect[2];
			for(int i=0; i<3; i++)
			{
				std::cout << "---- iter " << i << '\n';
				static Rect r3 (i,i,i,i) ;
				Rect r4(*pR);
				Rect r5(i,i,i,i);
			}
		}
		delete pR;	
		stop

		std::cout << "==========================\n";
	}

 
	//������� 6.����������� + ���������� = ��������������
	// ���������. ����� MyString
	// ����������� ������������ (�������������) � ����������� ����������
	//���������� ������������� � ����������� �������
	//C ������� ��������� ���������� ����� ����������
	//������ � ������������ ������ ��� ������-����� ������
	{
		MyString	str("It's my string!");
		//�������� ����� GetString(), ������� ��������� ������ � ���������� ������.
		//� ������� cout � ������ GetString() ������������ ������ ������� str
		//���������: ���������, ��� ������� ��������� ����������� ����� GetString().
		cout << str.GetString() << '\n';
		cout << "======\n";
		//...
	}
	stop


	//6a. ���������������� ��������� ��������. ��������� - �����
	//������������ ��� �������. ���������� ��������� ��������� (���?)
	{
		MyString str1("The first string!");
		MyString str2 = str1;
		str1.PrintMyString();
		str2.PrintMyString();
	}
		stop

		//6�. ���������� ����� SetNewString, ������� ����� �������� ������
		// �� �����
	{
	MyString str1("The next first string!");
	str1.PrintMyString();
	str1.SetNewString("The second str.");
	str1.PrintMyString();
	}

	//������� 7.  ������ � ������� ������� ��������� ������:
	//���� ��� ����� ���������� ������. � ����� ����� � ��������� ������
	//������� ���������� ����� (96%), � ������ � ����.
	//������� �������� 1� ���������� ���������� ���������� �� ����� �����
	//� ������ ��������� ��������: �� ������ ��������
	//���������� �� ������ ����� -> ������ �� ������
	//���������� �� ������ ����� -> ������ � ������.
	//��������� ���������� ����� ��������, �� ������� ������������ ������ �
	//������ ����� ������ ������ 50%.

	//Bochka spirt(...);
	//Bochka water(...);
	//...
	//	while(������������ ������ � ����� spirt > 50%)
	//	{
	//		spirt.Pereliv(water); //��� spirt.Pereliv(water, �����_������);
	//		water.Pereliv(spirt); // ����������
	//		...

	//	}
	{
		cout << "=================================\n";
		Barrel water(100.0);
		Barrel alcohol(96.0, 4.0);
		int i = 0;
		while ((alcohol.GetConcentr() > 50) && (i<5000))
		{
			Barrel liter1 = water.PourPortion(1.0);
			alcohol.PurgeBarrel(liter1);
			liter1 = alcohol.PourPortion(1.0);
			water.PurgeBarrel(liter1);
			i++;
			cout << i << '\t' << alcohol.GetConcentr() << '\t' << alcohol.GetVolume() << '\t' << water.GetConcentr() << '\n';
		}
	}
return 0;

}//end_main

