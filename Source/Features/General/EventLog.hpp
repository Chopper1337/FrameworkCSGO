#ifndef FEATURES_GENERAL_EVENTLOG
#define FEATURES_GENERAL_EVENTLOG

#include "../Features.hpp"

#include "imgui.h"

inline class EventLog : public Feature {
public:
	EventLog()
		: Feature("General", "Event log")
	{
	}

	bool enabled = true;
	int duration = 5000;

	void ImGuiRender(ImDrawList* drawList);

	void __attribute__((format(printf, 2, 3))) CreateReport(const char* fmt, ...);

	virtual void SetupGUI() override;
	virtual SERIALIZER() override;
} eventLog;

#endif