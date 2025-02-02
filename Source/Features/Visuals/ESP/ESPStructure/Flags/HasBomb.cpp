#include "../PlayerFlags.hpp"

#include "imgui.h"
#include <cstring>
#include <optional>
#include <string>

std::optional<std::string> HasBomb::GetText(const Player& player) const
{
	if (player.hasBomb)
		return "Has bomb";
	else
		return std::nullopt;
}