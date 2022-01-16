#pragma once
class MyString
{
    char* m_pStr;	//строка-член класса
public:
    MyString();
    ~MyString();
    MyString(const char* other);
    void SetNewString(const char* other);
    void PrintMyString();
    const char* GetString();
};
