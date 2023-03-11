#include "../Serializer.hpp"

#include <algorithm>

#include "xorstr.hpp"

void Serialization::Serializer::Serialize(const char* name, int& type, Direction direction)
{
	switch (direction) {
	case SERIALIZE:
		GetValue(name) = std::to_string(type);
		break;
	case DESERIALIZE:
		std::string string = GetValue(name);
		if (!string.empty())
			type = std::stoi(string);
		break;
	}
}