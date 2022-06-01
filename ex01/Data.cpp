#include "Data.hpp"

/****************** Constructors ********************/

Data::Data()
 : myInteger(42), myDouble(42.42), myChar('f'), myString("This is an example")
{
	std::cout << "Data: Default constructor is called\n";
}

Data::Data(const Data& original)
 : myInteger(original.myInteger), myDouble(original.myDouble), myChar(original.myChar), myString(original.myString)
{
	std::cout << "Data: Copy constructor is called\n";
}

Data& Data::operator=(const Data& original)
{
	std::cout << "Data: Copy assignment overloading constructor is called\n";
	if (this != &original)
	{
		myInteger = original.myInteger;
		myDouble = original.myDouble;
		myChar = original.myChar;
		myString = original.myString;
	}
	return (*this);
}

/******************* Destructor *********************/

Data::~Data()
{
	std::cout << "Data: Destructor is called\n";
}

/***************** Member Functions *****************/

void	Data::printData(void)
{
	std::cout << "myInt is " << myInteger << std::endl
			  << "myDouble is " << myDouble << std::endl
			  << "myChar is " << myChar << std::endl
			  << "myString is " << myString << std::endl;
}

