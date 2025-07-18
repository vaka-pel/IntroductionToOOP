#include<iostream>
using namespace std;

#define delimiter "\n---------------------------------------------\n"

class Point
{
		double x;
		double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this -> x = x;
	}
	void set_y(double y)
	{
		this -> y = y;
	}
	//			Constructors;
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "SingleArgumentConstructor:" << this << endl;
		//����������� � ����� ����������
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;;
	}
	//   Operators
	Point& operator = (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	Point& operator++() // Prefix increment
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int) //Postfix (suffix) increment
	{
		Point old = *this; // ��������� ������ �������� �������
		x++;
		y++;
		return old;
	}

	//  Methods
	double distance(const Point& other)
	{
		// - this - ��� ����� (������� ���������� �� ���� �����)
		// - other - �� ����� (�� ��������� �����)
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << this << ": X = " << x << ",\tY = " << y << endl;
	}
};

double distance(Point A, Point B)
{
	//A.set_x(A.get_x() * 100);
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
	

}
Point& operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

bool operator ==(const Point& left, const Point& right)
{
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
		return true;
	else
		return false;*/
	return (left.get_x() == right.get_x() && left.get_y() == right.get_y());
}
bool operator != (const Point& left, const Point& right)
{
	return !(left == right);
}

//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	int a; // ���������� ���������� ���� int
	Point A; // ���������� ���������� ���� Point
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;

#endif  STRUCT_POINT

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimiter << endl;
	cout << "���������� �� ����� 'A' �� ����� 'B':" << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "���������� �� ����� 'B' �� ����� 'A':" << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "���������� ����� ������� 'A' � 'B':  " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "���������� ����� ������� 'B' � 'A':  " << distance(B, A) << endl;
	cout << delimiter << endl;
	cout << sizeof(Point) << endl;

#endif  DISTANCE_CHECK

	#ifdef CONSTRUCTORS_CHECK
	Point A;		//����� �� ������ ������� ������, � ��� ����� ������ ���������� ����������� �� ���������
	A.print();
	//{
	//	//Point A;
	//	Point B;
	//	cout << "Point B ����������" << endl;
	//	B.distance(A);
	//}
	//cout << "����� Point B ��� �� ����������" << endl;

	Point B = 5;	//Single-argument constructor - ����������� � ����� ����������
	B.print();

	Point C(7, 8);	//
	C.print();

	Point D = C;	//Copy constructor
	D.print();

	Point E;		//Default constructor
	E = D;			//Assignment operator
	E.print();

#endif  CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK


	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << " \t" << c << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	//Point(2, 3);  ����� �� ���� �������� �����������, � ������� ��������� ���������� ������
	cout << delimiter << endl;
	A.Print();
	B.Print();
	C.Print();
#endif  ASSIGNMENT_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Point A(2, 3);
	Point B(7, 8);
	Point C = A + B;
	C.print();


	A = B++;
	A.print();
	B.print();
#endif  ARITHMETICAL_OPERATORS_CHECK

	
		cout << (Point (2, 3) != Point(7, 8)) << endl;
	


}