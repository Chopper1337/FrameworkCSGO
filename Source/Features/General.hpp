#ifndef FEATURES_GENERAL
#define FEATURES_GENERAL

#include "../SDK/CUserCmd.hpp"
#include "../SDK/GameClass/CMoveData.hpp"

#include "../Serialization/Serializer.hpp"

namespace Features::General {
	namespace Menu {
		// Settings
		extern int menuKey;
		extern int style;

		void ImGuiLoop();

		// GUI
		void SetupGUI();

		// Serialization
		DECLARE_SERIALIZER(Serializer)
	}
	namespace Watermark {
		// Settings
		extern bool enabled;

		void ImGuiRender(ImDrawList* drawList);

		// GUI
		void SetupGUI();

		// Serialization
		DECLARE_SERIALIZER(Serializer)
	}
	namespace EnginePrediction {
		// Settings
		extern bool enabled;
		extern bool forceResetVelocityModifier;

		extern CMoveData moveData;
		extern int prePredictionFlags;

		void StartPrediction(CUserCmd* cmd);
		void EndPrediction();

		// GUI
		void SetupGUI();

		// Serialization
		DECLARE_SERIALIZER(Serializer)
	}
	namespace EventLog {
		// Settings
		extern bool enabled;
		extern int duration;

		void ImGuiRender(ImDrawList* drawList);

		// GUI
		void SetupGUI();

		// API
		void CreateReport(const char* fmt, ...);

		// Serialization
		DECLARE_SERIALIZER(Serializer)
	}

	// GUI
	void SetupGUI();

	// Serialization
	DECLARE_SERIALIZER(Serializer)
}

#endif
