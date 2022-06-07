#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <string>
// #include <stdint.h>

class	Data
{
private:
	int 		myInteger;
	double		myDouble;
	char		myChar;
	std::string	myString;
public:
/******************Constructors********************/
	Data();
	Data(const Data& original);
	Data& operator=(const Data& original);

/******************Destructor********************/
	~Data();

/******************Member Functions********************/
	void	printData(void);
};

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif
