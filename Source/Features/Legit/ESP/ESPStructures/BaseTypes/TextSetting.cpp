#include "../../ESPStructure.hpp"

#include "xorstr.hpp"

#include "../../../../../GUI/Elements/ClickableColorButton.hpp"

TextSetting::TextSetting(const char* id)
	: id(id)
	, enabled(false)
	, fontScale(1.0f)
	, fontColor(ImGuiColors::white)
	, shadow(false)
	, shadowColor(ImGuiColors::black)
{
}

void TextSetting::Draw(ImDrawList* drawList, ImVec4 rectangle, const char* text, float height)
{
	if (!enabled)
		return;

	// Hack
	float fontScale = ImGui::GetFont()->Scale;
	ImGui::GetFont()->Scale = fontScale;
	ImGui::PushFont(ImGui::GetFont());

	ImVec2 size = ImGui::CalcTextSize(text);

	float above = rectangle.y - size.y;
	float below = rectangle.w;
	ImVec2 position(rectangle.x + (rectangle.z - rectangle.x) * 0.5f - size.x / 2.0f, above + (below - above) * height);

	if (shadow)
		drawList->AddText(ImVec2(position.x + 1.0f, position.y + 1.0f), shadowColor, text);

	drawList->AddText(position, fontColor, text);

	ImGui::PopFont();
	ImGui::GetFont()->Scale = fontScale;
}

void TextSetting::Copy(TextSetting& src)
{
	enabled = src.enabled;
	fontScale = src.fontScale;
	fontColor = src.fontColor;
	shadow = src.shadow;
	shadowColor = src.shadowColor;
}

void TextSetting::SetupGUI()
{
	ImGui::PushID(id);
	ImGui::Checkbox(id, &enabled);

	ImGui::SameLine();
	if (ImGui::Button("..."))
		ImGui::OpenPopup(id);

	if (ImGui::BeginPopup(id)) {
		ImGui::SliderFloat(xorstr_("Font scale"), &fontScale, 0.1f, 2.0f, "%.2f");
		ImGui::ClickableColorButton(xorstr_("Font color"), fontColor);
		ImGui::Checkbox(xorstr_("Shadow"), &shadow);
		if (shadow)
			ImGui::ClickableColorButton(xorstr_("Shadow color"), shadowColor);

		ImGui::EndPopup();
	}

	ImGui::PopID();
}

BEGIN_SERIALIZED_STRUCT(TextSetting::Serializer, id)
SERIALIZED_TYPE(xorstr_("Enabled"), enabled)
SERIALIZED_TYPE(xorstr_("Font scale"), fontScale)
SERIALIZED_TYPE(xorstr_("Font color"), fontColor)
SERIALIZED_TYPE(xorstr_("Shadow"), shadow)
SERIALIZED_TYPE(xorstr_("Shadow color"), shadowColor)
END_SERIALIZED_STRUCT