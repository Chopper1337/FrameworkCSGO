#include "../PlayerFlags.hpp"

#include "imgui.h"
#include <cstring>
#include <optional>
#include <string>

std::optional<std::string> Immune::GetText(const Player& player) const
{
	if (player.immune)
		return "Immune";
	else
		return std::nullopt;
}