#pragma once
class MyString
{
    char* m_pStr;	//ñòðîêà-÷ëåí êëàññà
public:
    MyString();
    ~MyString();
    MyString(const char* other = "");
    void SetNewString(const char* other);
    void PrintMyString();
    const char* GetString();
};
