#ifndef FEATURES_VISUALS_FLASHREDUCTION
#define FEATURES_VISUALS_FLASHREDUCTION

#include "../Features.hpp"

#include "imgui.h"

#include "../../SDK/GameClass/IMaterial.hpp"

#include "../../GUI/ImGuiColors.hpp"

inline class FlashReduction : public Feature {
public:
	FlashReduction()
		: Feature("Visuals", "Flash reduction")
	{
	}

	bool enabled = false;
	bool clearFlashbang = false;
	ImColor flashColor = ImGuiColors::white;

	bool ViewDrawFade(std::byte* color, IMaterial*& pFadeMaterial);

	virtual void SetupGUI() override;
	virtual SERIALIZER() override;
} flashReduction;

#endif