#include<iostream>
#include "Point.h"

using uchar_t = unsigned char;
using lint_t = long int;
using llint_t = long long int;
using sint_t = short int;
using uint_t = unsigned int;
using usint_t = unsigned short int;
using ulint_t = unsigned long int;
using ullint_t = unsigned long long int;
using ldouble_t = long double;


void unit1() {
	std::cout << "\t\t ---test #1---\n\n";

	sp::Point<char> p1(1, 2, 3);
	sp::Point<uchar_t> p2;
	sp::Point<sint_t> p3(4, 5, 6);
	sp::Point<int> p4;
	sp::Point<lint_t> p5(7, 8, 9);
	sp::Point<usint_t> p6;
	sp::Point<uint_t> p7(10, 11, 12);
	sp::Point<ulint_t> p8;
	sp::Point<llint_t> p9(13, 14, 15);
	sp::Point<ullint_t> p10;

	sp::Point<float> p11(static_cast<float>(34.5), static_cast<float>(22.4), static_cast<float>(45.6));
	sp::Point<double> p12(123.4, 17.34, 18.4);
	sp::Point<ldouble_t> p13(12121.5, 454.12, 12321.16);

	std::cout << "\n\t\t<------------------------------------------------------>\n\n";

	std::cout << "output object:\n\n";

	std::cout << "point1:\n";
	p1.output();
	std::cout << '\n';

	std::cout << "point2:\n";
	p2.output();
	std::cout << '\n';

	std::cout << "point3:\n";
	p3.output();
	std::cout << '\n';

	std::cout << "point4:\n";
	p4.output();
	std::cout << '\n';

	std::cout << "point5:\n";
	p5.output();
	std::cout << '\n';

	std::cout << "point6:\n";
	p6.output();
	std::cout << '\n';

	std::cout << "point7:\n";
	p7.output();
	std::cout << '\n';

	std::cout << "point8:\n";
	p8.output();
	std::cout << '\n';

	std::cout << "point9:\n";
	p9.output();
	std::cout << '\n';

	std::cout << "point10:\n";
	p10.output();
	std::cout << '\n';

	std::cout << "point11:\n";
	p11.output();
	std::cout << '\n';

	std::cout << "point12\n";
	p12.output();
	std::cout << '\n';

	std::cout << "point13:\n";
	p13.output();
	std::cout << '\n';
	
	//std::cout << '\n';
	
	std::cout << "\t\t ---end test #1---\n\n";

}

void unit2() {

	std::cout << "\t\t ---test #2---\n\n";

	sp::Point<char> charPoint;
	sp::Point<int> intPoint;
	sp::Point<double> doublePoint;

	std::cout << "\n\t\t<------------------------------------------------------>\n";

	std::cout << "\ndefault init\n\n";

	std::cout << "charPoint:\n";
	charPoint.output();
	std::cout << '\n';

	std::cout << "intPoint:\n";
	intPoint.output();
	std::cout << '\n';

	std::cout << "doublePoint:\n";
	doublePoint.output();
	std::cout << '\n';

	std::cout << "\ntesting <obj_name>.randomInput():\n\n";

	charPoint.randomInput();
	intPoint.randomInput();
	doublePoint.randomInput();
	
	std::cout << "charPoint:\n";
	charPoint.output();
	std::cout << '\n';

	std::cout << "intPoint:\n";
	intPoint.output();
	std::cout << '\n';

	std::cout << "doublePoint:\n";
	doublePoint.output();
	std::cout << '\n';

	std::cout << "\t\t ---end test #2---\n\n";

}

int main(int argc, char* argv[]) {

	/*
	for (int it = 0; it < argc; ++it) {
		std::cout << argv[it];
	}
	std::cout << '\n';
	*/

	unit1();

	unit2();

	return 0;
}