#include "TestClearColor.h"
#include <imgui/imgui.h>

namespace test {
	TestClearColor::TestClearColor()
		: clearColor { 0.2f, 0.3f, 0.8f, 1.0f }
	{
	}

	TestClearColor::~TestClearColor()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}

	void TestClearColor::OnUpdate(float deltaTime)
	{
	}

	void TestClearColor::OnRender()
	{
		glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void TestClearColor::OnImGuiRender()
	{
		ImGui::ColorPicker4("Arkaplan Rengi", clearColor);
	}
}