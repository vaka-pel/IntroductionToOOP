#include<iostream>
using namespace std;
#define delimiter "\n-----------------------------------------------\n"

///////////////////////////////////////////////////////////////////////////
//////////////////    ���������� ������ (Class declaration)  //////////////

class String
{
	char* str;  // ����� ������ � ������������ ������
	int size;  //������ ������ � ������
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
//////////////////    ����� ���������� ������ (Class declaration end)  //////////////



//////////////////     ����������� ������ (Class definition)  //////////////

int String::get_size()const
{
	return size;

}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

// Constructors:

 String::String(int size) :size(size), str(new char[size] {})
{
	//����������� �� ��������� ������� ������ ������ �������� 80 ����
	//this->size = size;
	//this->str = new char[size] {};
	cout << "DefaultConstructor:\t" << this << endl;

}
String::String(const char* str) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1; // strlen ���������� ������ ������ � ��������, "+1
	//this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	//this->str = other.str;   // Shallow copy
	// Deep copy:
	//this->size = other.size;
	//this->str = new char[size] {};
	//for (int i = 0; i < size; i++)this->str[i] = other.str[i];

	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	//this->size = other.size;
	//this->str = other.str;
	//�������� ����������� ������ ��� ���� ����� ������������� �������� ��� �������� ������������
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor:\t" << this << endl;

}
String::~String()
{
	delete[] str;
	str = nullptr;
	size = 0;
	cout << "Destructor:\t\t" << this << endl;
}
//    Operators

String& String::operator=(const String& other)
{
	// ���������, �� �������� �� ��� ������ ���� ��������
	if (this == &other)return *this;
	delete[] this->str; // ������� ������ ������������ ������
	//this->str = other.str;
	this->size = other.size;
	this->str = new char[size] {}; // �������� ����� ������������ ������
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{   // ��������, �� �������� �� this � other ����� � ��� �� �������� 
	if (this == &other)return *this;
	// �������� ������ ������
	delete[] str;

	this->size = other.size;
	this->str = other.str;

	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t\t" << this << endl;
	return *this;
}
char String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

//          Metods:


void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		result[i] = left[i];
		//result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		result[i + left.get_size() - 1] = right[i];
		//result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return result;
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//////////////////    ����� ����������� ������ (Class definition end)  //////////////

//#define CONSTRUCTORS_CHECK
//#define COPY_SEMANTIC_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str1;
	str1.print();

	String str2(5); // Conversion from "int" to "string"
	str2.print();

	String str3 = "Hello";
	str3.print();
	cout << str3 << endl;

	String str4 = "World";
	cout << str4 << endl;

	cout << delimiter << endl;
	String str5;
	str5 = str3 + str4;
	cout << delimiter << endl;
	cout << str5 << endl;

#endif // CONSTRUCTORS_CHECK

#ifdef COPY_SEMANTIC_CHECK

	String str1 = "Hello";
	cout << str1 << endl;

	String str2 = str1;
	cout << str2 << endl;
#endif // COPY_SEMANTIC_CHECK

	String str1;   // DefaultConstructor
	str1.print();

	String str2(5);  // Single-Argument Constructor
	str2.print();

	String str3 = "Hello";   //   Single-Argument Constructor  (const char str[])
	str3.print();

	String str4();  // � ���� ������ �� ���������� DefaultConstructor, � �� ��������� ������
	                // ����� ����������� ������� str4, ������� ������ �� ���������
	                // � ���������� �������� ���� String
					// str4 �� �������� ��������
	// �� ����, ������� ������ �� ������ ����� ����� ������������ �� ���������
	// ���� ���� ������������� ���� ������� ����������� �� ���������, 
	// �� ��� ����� ������� ��� ������ �������� ������:

	String str5{};   // � ��� ������ ��� ���� �������� DefaultConstructor
	str5.print();

	String str6{ 6 };   //Single-Argument Constructor
	str6.print();

	String str7{ "World" };
	str7.print();

	String str8 = str7;
	str8.print();

	String str9(str8);
	str9.print();

	String str10{ str9 };
	str10.print();

	// !!! �������� ������ ��� ������ ������������� ������� ������������ � ������� �������������

	String str11 = str3 + str8;
	str11.print();
}                    