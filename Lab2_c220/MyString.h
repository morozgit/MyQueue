#pragma once
#define _CRT_SECURE_NO_WARNINGS /*_CRT_NONSTDC_NO_WARNINGS*/
#include <iostream>
#include <string>
#include <algorithm>
//#include"Book.h"
using namespace std;


class MyString
{
	//friend class Book;
	char* m_pStr{};	//строка-член класса
	char* m_pDefaultStr{};
public:

	//MyString(char* i) : m_pStr(i)
	//{}

	MyString();

	/*explicit*/ MyString(const char* pStr);

	MyString(const MyString& other);

	MyString(MyString&& other);

	~MyString();

	const char* GetString();

	void SetNewString(const char*);

	MyString& operator = (const MyString& p);

	MyString& operator = (MyString&& p);

	MyString operator + (MyString& str1);

	MyString& operator+=(const MyString& rvalue);

	MyString& operator = (const char* a);
	//MyString& operator = (const Data& data){}

	friend bool operator== (const MyString& Mstr, const char* str);



	MyString operator[](int);

	friend ostream& operator << (ostream& os, const MyString& an);

	friend class Book;

};
