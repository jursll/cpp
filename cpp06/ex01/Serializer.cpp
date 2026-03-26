#include "Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Constructor for Serializer called" << std::endl;
}

Serializer::Serializer(Serializer const &src) {
	std::cout << "Copy constructor for Serializer called" << std::endl;
	*this = src;
}

Serializer& Serializer::operator=(Serializer const &src) {
	std::cout << "Assignment operator for Serializer called" << std::endl;
	(void)src;
	return *this;
}

Serializer::~Serializer(){
	std::cout << "Destructor for Serializer called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
