

#include"String.h"

//////////////////     ОПРЕДЕЛЕНИЕ КЛАССА (Class definition)  //////////////

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
	//конструктор по умолчанию создает пустую строку размером 80 Байт
	//this->size = size;
	//this->str = new char[size] {};
	cout << "DefaultConstructor:\t" << this << endl;

}
String::String(const char* str) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1; // strlen возвращает размер строки в символах, "+1
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
	//обнуляем принимаемый объект для того чтобы предотвратить удаление его ресурсов деструктором
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
	// проверяем, не является ли тот объект этим объектом
	if (this == &other)return *this;
	delete[] this->str; // удаляем старую динамическую память
	//this->str = other.str;
	this->size = other.size;
	this->str = new char[size] {}; // выделяем новую динамическую память
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{   // проверка, не является ли this и other одним и тем же объектом 
	if (this == &other)return *this;
	// удаление старой памяти
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

//////////////////    КОНЕЦ ОПРЕДЕЛЕНИЯ КЛАССА (Class definition end)  //////////////
