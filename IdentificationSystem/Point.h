
/* 
	Type identification system based on the example of the template class <Point>

	the system provides generation of random values of coordinates of objects of the <Point> class, 
	depending on the type of template that is passed to the <Point> class

*/

#pragma once 

#ifndef POINT_H
#define POINT_H

#include "includes.h"

SP_BEGIN

	using llInt_t = long long int;
	using lDouble_t = long double;
	using string_t = std::string;

	struct CharName {

	private:

		string_t charType;

		const string_t CHAR	= typeid(char).name();
		const string_t U_CHAR = typeid(char).name();

		enum CharID {

			EXCEPT = 0,
			CHAR_ID,
			U_CHAR_ID
		};

	public:

		CharName(string_t initChar = "") {
			this->charType = initChar;
		}

		void setChar(const string_t nameType) {
			this->charType = nameType;
		}

		string_t getChar() {
			return this->charType;
		}

		CharID enumOfChar() {
	
			if (this->charType == CHAR) {
				return CHAR_ID;
			}
			else if (this->charType == U_CHAR) {
				return U_CHAR_ID;
			}
			else {
				return EXCEPT;
			}

		}

		~CharName() {

		}

	};

	struct IntName {

	private:

		string_t intType;

		const string_t SHORT = typeid(short int).name();
		const string_t INT = typeid(int).name();
		const string_t LONG	= typeid(long int).name();
		const string_t U_SHORT = typeid(unsigned short).name();
		const string_t U_INT = typeid(unsigned int).name();
		const string_t U_LONG = typeid(unsigned long int).name();
		const string_t LL_INT = typeid(long long int).name();
		const string_t ULL_INT = typeid(unsigned long long int).name();

		enum IntID {

			EXCEPT = 0,
			SHORT_ID,
			INT_ID,
			LONG_ID,
			U_SHORT_ID,
			U_INT_ID,
			U_LONG_ID,
			LL_INT_ID,
			ULL_INT_ID

		};

	public:

		IntName(string_t initInt = "") {
			this->intType = initInt;
		}

		void setInt(const string_t initType) {
			this->intType = initType;
		}

		string_t getInt() {
			return this->intType;
		}
		
		IntID enumOfInt() {

			if (this->intType == SHORT) {
				return SHORT_ID;
			}
			else if (this->intType == INT) {
				return INT_ID;
			}
			else if (this->intType == LONG) {
				return LONG_ID;
			}
			else if (this->intType == U_SHORT) {
				return U_SHORT_ID;
			}
			else if (this->intType == U_INT) {
				return U_INT_ID;
			}
			else if (this->intType == U_LONG) {
				return U_INT_ID;
			}
			else if (this->intType == LL_INT) {
				return LL_INT_ID;
			}
			else if(this->intType == ULL_INT) {
				return ULL_INT_ID;
			}
			else {
				return EXCEPT;
			}

		}

		~IntName() {

		}

	};

	struct DoubleName {

	private:

		string_t doubleType;

		const string_t FLOAT = typeid(float).name();
		const string_t DOUBLE = typeid(double).name();
		const string_t L_DOUBLE = typeid(long double).name();

		enum DoubleID {

			EXCEPT = 0,
			FLOAT_ID,
			DOUBLE_ID,
			L_DOUBLE_ID

		};

	public:

		DoubleName(string_t initDouble = "") {
			this->doubleType = initDouble;
		}

		void setDouble(const string_t doubleInit) {
			this->doubleType = doubleInit;
		}

		string_t getDouble() {
			return this->doubleType;
		}

		DoubleID enumOfDouble() {

			if (this->doubleType == FLOAT) {
				return FLOAT_ID;
			}
			else if (this->doubleType == DOUBLE) {
				return DOUBLE_ID;
			}
			else if(this->doubleType == L_DOUBLE) {
				return L_DOUBLE_ID;
			}
			else {
				return EXCEPT;
			}

		}

		~DoubleName() {

		}

	};

	template <typename Tp, typename T = long double>
	class Point {
	private: 

		T xCoordinate;
		T yCoordinate;
		T zCoordinate;

		static int objectCount;
		int objectId;

		const string_t typenameTp = typeid(Tp).name();
		const string_t typenameT = typeid(T).name();

	public: 
		
		Point(Tp xDefault = 0, Tp yDefault = 0, Tp zDefault = 0) {

			srand(static_cast<unsigned int>(time(NULL)));

			std::cout << "constructor : Point();\n";

			this->xCoordinate = static_cast<T>(xDefault);
			this->yCoordinate = static_cast<T>(yDefault);
			this->zCoordinate = static_cast<T>(zDefault);

			
			objectId = objectCount++;

		}

		Point(const Point<Tp>& P) {

			this->xCoordinate = static_cast<T>(P.xCoordinate);
			this->yCoordinate = static_cast<T>(P.yCoordinate);
			this->zCoordinate = static_cast<T>(P.zCoordinate);

		}


		string_t getId() {

			string_t type = typeid(Tp).name();
			string_t id = std::to_string(objectId);

			return "Point<" + type + "> " + id;
		}

		static int getCount() {
			return objectCount;
		}

		void set(Tp x, Tp y, Tp z) {

			this->xCoordinate = static_cast<T>(x);
			this->yCoordinate = static_cast<T>(y);
			this->zCoordinate = static_cast<T>(z);

		}

		void get(T& isX, T& isY, T& isZ) {

			isX = this->xCoordinate;
			isY = this->yCoordinate;
			isZ = this->zCoordinate;

		}

		Point<Tp>& randomInput(Tp maxRandom = 20, Tp minRandom = 1) {

			std::cout << "randomInput();\n";
		
			std::cout << "Type of current object of class: " << this->typenameTp << '\n';

			CharName charName(this->typenameTp);
			IntName intName(this->typenameTp);
			DoubleName doubleName(this->typenameTp);

			if (!(this->xCoordinate || this->yCoordinate || this->zCoordinate)) {

				this->xCoordinate = NULL;
				this->yCoordinate = NULL;
				this->zCoordinate = NULL;

			}

			int charId = static_cast<int>(charName.enumOfChar());
			int intId = static_cast<int>(intName.enumOfInt());
			int doubleId = static_cast<int>(doubleName.enumOfDouble());


			//processing the input of a range of numbers
			if (maxRandom < minRandom) {

				Tp add = maxRandom;
				maxRandom = minRandom;
				minRandom = add;

			}


			if (intId) {

				const llInt_t max = static_cast<llInt_t>(maxRandom);
				const llInt_t min = static_cast<llInt_t>(minRandom);
				

				this->xCoordinate += rand() % (max - min + 1) + min;
				this->yCoordinate += rand() % (max - min + 1) + min;
				this->zCoordinate += rand() % (max - min + 1) + min;

				return* this;

			}
			else if (doubleId) {
				
				const lDouble_t max = static_cast<lDouble_t>(maxRandom);
				const lDouble_t min = static_cast<lDouble_t>(minRandom);
				
				this->xCoordinate += rand() / (max - min + 1) + min;
				this->yCoordinate += rand() / (max - min + 1) + min;
				this->zCoordinate += rand() / (max - min + 1) + min;

				return* this;

			}
			else if(charId) {

				const int SIZE = 7;

				char symbols[SIZE]{ '&', '#', '~', '8', 's', 'a', 'h' };


				const int BEGIN = 0;
				const int END = 6;
				
				char sym1 = symbols[rand() % END + BEGIN];
				char sym2 = symbols[rand() % END + BEGIN];
				char sym3 = symbols[rand() % END + BEGIN];

				this->xCoordinate += static_cast<llInt_t>(sym1);
				this->yCoordinate += static_cast<llInt_t>(sym2);
				this->zCoordinate += static_cast<llInt_t>(sym3);

				return* this;

			}
			else {
				return* this;
			}

		}
		

		T getX() {
			return this->xCoordinate;
		}

		T getY() {
			return this->yCoordinate;
		}

		T getZ() {
			return this->zCoordinate;
		}

		void output() {
			
			std::cout << this->xCoordinate << '\n';
			std::cout << this->yCoordinate << '\n';
			std::cout << this->zCoordinate << '\n';

		}

		void assignNull() {

			this->xCoordinate = NULL;
			this->yCoordinate = NULL;
			this->zCoordinate = NULL;

		}

		bool isNull() {

			return !(this->xCoordinate || this->yCoordinate || this->zCoordinate);

		}

		string_t globalType() {

			return this->typenameT;

		}

		string_t currentType() {

			return this->typenameTp;

		}

		Point<Tp>& operator = (const Point<Tp>& assignObj) {


			this->xCoordinate = assignObj.xCoordinate;
			this->yCoordinate = assignObj.yCoordinate;
			this->zCoordinate = assignObj.zCoordinate;

			return* this;

		}

		bool operator == (const Point<Tp>& equalObj) {
			
			return this->xCoordinate == equalObj.xCoordinate && 
				this->yCoordinate == equalObj.yCoordinate && 
				this->zCoordinate == equalObj.zCoordinate;

		}

		bool operator != (const Point<Tp>& notequalObj) {

			return this->xCoordinate != notequalObj.xCoordinate || 
				this->yCoordinate != notequalObj.yCoordinate || 
				this->zCoordinate != notequalObj.zCoordinate;

		}

		Point<Tp> operator + (const Point<Tp>& addit) {
			Point<Tp> newPoint;

			newPoint.xCoordinate = this->xCoordinate + addit.xCoordinate;
			newPoint.yCoordinate = this->yCoordinate + addit.yCoordinate;
			newPoint.zCoordinate = this->zCoordinate + addit.zCoordinate;

			return newPoint;
		}
		
		Point<Tp> operator - (const Point<Tp>& minus) {
			Point<Tp> point;

			point.xCoordinate = this->xCoordinate - minus.xCoordinate;
			point.yCoordinate = this->yCoordinate - minus.yCoordinate;
			point.zCoordinate = this->zCoordinate - minus.zCoordinate;

			return point;
		}

		Point<Tp>& operator += (const Point<Tp>& assignAdd) {
			this->xCoordinate += assignAdd.xCoordinate;
			this->yCoordinate += assignAdd.yCoordinate;
			this->zCoordinate += assignAdd.zCoordinate;

			return* this;
		}

		Point<Tp>& operator -= (const Point<Tp>& assignMinus) {
			this->xCootdinate -= assignMinus.xCoordinate;
			this->yCoordinate -= assignMinus.yCoordinate;
			this->zCoordinate -= assignMinus.zCoordinate;

			return* this;
		}

		Point<Tp>& operator ++ () {
			this->xCoordinate += 1;
			this->yCoordinate += 1;
			this->zCoordinate += 1;

			return* this;
		}

		Point<Tp> operator ++ (int value) {
			Point<Tp> point(*this);

			this->xCoordinate += 1;
			this->yCoordinate += 1;
			this->zCoordinate += 1;

			return point;
		}

		Point<Tp>& operator -- () {
			this->xCoordinate -= 1;
			this->yCoordinate -= 1;
			this->zCoordinate -= 1;

			return* this;
		}

		Point<Tp> operator -- (int some) {
			Point<Tp> point(*this);

			this->xCoordinate -= 1;
			this->yCoordinate -= 1;
			this->zCoordinate -= 1;

			return point;
		}

		Point<Tp>& operator * (Tp num) {
			
			this->xCoordinate *= num;
			this->yCoordinate *= num;
			this->zCoordinate *= num;

			return* this;
		}
		
		~Point() {

		}

	};

	
	template <typename Tp, typename T>
	int Point<Tp, T>::objectCount = 0;


SP_END

#endif