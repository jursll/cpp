#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Serializer.hpp"
#include <stdint.h>
#include <iostream>
#include "Data.hpp"

class Serializer
{

	private:
		Serializer();
		Serializer(const Serializer& oth);
		Serializer& operator=(const Serializer& oth);
		~Serializer();
	public:
	static	uintptr_t	serialize(Data* ptr);
	static	Data*		deserialize(uintptr_t raw);


};
#endif
