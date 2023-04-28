#include "../GameFunctions.hpp"

#include "../../../Features/Semirage.hpp"
#include "../../../Features/Visuals.hpp"
#include "../../../GameCache.hpp"
#include "../../../Interfaces.hpp"

void Hooks::Game::FrameStageNotify::HookFunc(void* thisptr, ClientFrameStage stage)
{
	switch (stage) {
	case ClientFrameStage::FRAME_START: {
		GameCache::ClearLocalPlayer();
		Features::Visuals::Esp::UpdateVisibility();
		break;
	}
	case ClientFrameStage::FRAME_RENDER_START: {
		Features::Semirage::Backtrack::FrameStageNotify();

		Features::Visuals::NoPunch::HidePunch();
		break;
	}
	case ClientFrameStage::FRAME_RENDER_END: {
		Features::Visuals::NoPunch::RestorePunch();

		worldToScreenMatrix = *Interfaces::engine->WorldToScreenMatrix();
		break;
	}
	default:
		// ignored
		break;
	}
	return InvokeFunction<void, void*, ClientFrameStage>(hook->proxy, thisptr, stage);
}