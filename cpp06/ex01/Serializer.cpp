#include "Serializer.hpp"
#include "Data.hpp"


Serializer::Serializer()
{

}
Serializer::~Serializer()
{

}

Serializer::Serializer(const Serializer& oth)
{
	*this = oth;
}

Serializer& Serializer::operator=(const Serializer& oth)
{
	if(this != &oth)
	{
		*this = oth;
	}
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data*>(raw));
}
