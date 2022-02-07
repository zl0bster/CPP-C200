#pragma once
class MyString
{
    char* m_pStr;	//строка-член класса
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
};
MyString ConcatLines(const char* , ...);// nullptr is end of line