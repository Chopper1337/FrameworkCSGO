#include "../ESPStructure.hpp"

#include "xorstr.hpp"

#include "../../../../GUI/Elements/ClickableColorButton.hpp"

void PlayerTeamSettings::SetupGUI(const char* id)
{
	ImGui::PushID(id);
	if (ImGui::BeginTabBar(xorstr_("#Player team config selection"), ImGuiTabBarFlags_Reorderable)) {
		if (ImGui::BeginTabItem(xorstr_("Visible"))) {
			visible.SetupGUI(xorstr_("Visible"));
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem(xorstr_("Occluded"))) {
			occluded.SetupGUI(xorstr_("Occluded"));
			ImGui::EndTabItem();
		}
		ImGui::EndTabBar();
	}
	ImGui::PopID();
}

BEGIN_SERIALIZED_STRUCT(PlayerTeamSettings::Serializer)
SERIALIZED_STRUCTURE(xorstr_("Visible"), visible)
SERIALIZED_STRUCTURE(xorstr_("Occluded"), occluded)
END_SERIALIZED_STRUCT