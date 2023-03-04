#include "Bhop.hpp"

#include "imgui.h"

#include "../../SDK/Definitions/InputFlags.hpp"
#include "../../SDK/Definitions/StateFlags.hpp"

#include "../../GameCache.hpp"

bool Features::Movement::Bhop::enabled		 = false;
int	 Features::Movement::Bhop::humanization = 0;

void Features::Movement::Bhop::CreateMove(CUserCmd* cmd) {
	if (!enabled)
		return;

	CBasePlayer* localPlayer = GameCache::GetLocalPlayer();
	if (!localPlayer)
		return;

	int flags = *localPlayer->Flags();

	if (humanization > 0) {
		if (!(flags & FL_ONGROUND)) {
			// We don't necessarily want to tell the server, that we are able to perform tick perfect button presses, so let's randomize them in air, they matter anyway
			if (rand() % humanization == 0)
				cmd->buttons &= ~IN_JUMP;
		} else {
			if (cmd->tick_count % (humanization + 1 /* mod 1 will always evaluate to 0 */) == 0)
				cmd->buttons &= ~IN_JUMP;
		}
	} else {
		if (cmd->buttons & IN_JUMP && !(flags & FL_ONGROUND))
			cmd->buttons &= ~IN_JUMP;
	}
}

void Features::Movement::Bhop::SetupGUI() {
	ImGui::Checkbox(xorstr_("Enabled##MovementBhop"), &enabled);
	ImGui::SliderInt(xorstr_("Humanize##MovementBhop"), &humanization, 0, 4);
}