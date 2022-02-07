#pragma once
class MyString
{
    char* m_pStr;	//строка-член класса
public:
    MyString();
    ~MyString();
    explicit MyString(const char* other);
    void SetNewString(const char* other);
    void PrintMyString();
    const char* GetString();
    void Concat(const char* other);
    MyString& operator = (const MyString& oth);
    MyString& operator = (const char* oth);
};
MyString ConcatLines(const char* , ...);// nullptr is end of line