#pragma once
class MyString
{
    char* m_pStr;	//������-���� ������
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
};
MyString ConcatLines(const char* , ...);// nullptr is end of line