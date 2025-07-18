#pragma once
#include<iostream>
using namespace std;
#define delimiter "\n-----------------------------------------------\n"

///////////////////////////////////////////////////////////////////////////
//////////////////    ОБЪЯВЛЕНИЕ КЛАССА (Class declaration)  //////////////

class String
{
	char* str;  // адрес строки в динамической памяти
	int size;  //размер строки в байтах
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	// Constructors:

	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();
	//    Operators

	String& operator=(const String& other);
	String& operator=(String&& other);
	char operator[](int i)const;
	char& operator[](int i);

	//          Metods:


	void print()const;
};
	String operator+(const String& left, const String& right);
	std::ostream& operator<<(std::ostream& os, const String& obj);
//////////////////    КОНЕЦ ОБЪЯВЛЕНИЯ КЛАССА (Class declaration end)  //////////////

