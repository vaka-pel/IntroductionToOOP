#include"String.h"
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
	cout << str11 << endl;
}                    