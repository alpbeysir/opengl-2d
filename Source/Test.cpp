#include "Test.h"
#include "Test2DRender.h"
#include "TestClearColor.h"

#include <imgui/imgui.h>

namespace test {
	TestMenu::TestMenu(Test*& _currentTest) : currentTest(_currentTest)
	{

	}
	void TestMenu::OnImGuiRender()
	{
		ImGui::Text("Tests");
		for (auto& test : tests) {
			if (ImGui::Button(test.first.c_str())) {
				currentTest = test.second();
			}
		}
	}
}