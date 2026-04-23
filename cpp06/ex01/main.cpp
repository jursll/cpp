#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data d;
	d.age = 30;
	d.name = "Julia";
	d.last_name = "Russell";

	Data* original = &d;

	uintptr_t raw = Serializer::serialize(original);
	Data* restored = Serializer::deserialize(raw);

	std::cout << "Original pointer : " << original << "\n";
	std::cout << "Restored pointer : " << restored << "\n";

	if (original == restored)
		std::cout << "Same address!\n";
	else
		std::cout << "Different address!\n";

	// std::cout << "\nraw (dec): " << raw << "\n";
	// std::cout << "raw (hex): 0x" << std::hex << raw << std::dec << "\n";

	std::cout << "\n--- Data content ---\n";
	std::cout << "Age		: " << restored->age << "\n";
	std::cout << "Name		: " << restored->name << "\n";
	std::cout << "Last name : " << restored->last_name << "\n";

	return 0;
}
