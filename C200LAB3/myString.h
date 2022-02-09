#pragma once
#include <iostream>
using namespace std;

class MyString
{
    static size_t counter;
private:
    char* m_pStr;
    size_t m_id;
public:
    MyString();
    ~MyString();
    explicit MyString(const char* other);
    MyString(const MyString& other);
    MyString(MyString&& other);
    void SetNewString(const char* other);
    void PrintMyString() const;
    const char* GetString() const;
    void Concat(const char* other);
    MyString& operator = (const MyString& oth);
    MyString& operator = (MyString&& oth);
    MyString& operator = (const char* oth);
    MyString& operator+= (const MyString& oth);

    friend MyString operator + (const MyString& left, const MyString& right);
    friend ostream& operator<<(ostream& os, const MyString& it);
};
MyString ConcatLines(const char* , ...);// nullptr is end of line