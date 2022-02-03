#pragma once
class MyString
{
    char* m_pStr;	//������-���� ������
public:
    MyString();
    ~MyString();
    explicit MyString(const char* other);
    void SetNewString(const char* other);
    void PrintMyString();
    const char* GetString();
    void Concat(const char* other);
};
MyString ConcatLines(const char* , ...);// nullptr is end of line