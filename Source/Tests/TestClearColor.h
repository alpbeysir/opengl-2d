#pragma once

#include "Test.h"
#include <glad/glad.h>

namespace test {

	class TestClearColor : public Test {
	public: 
		TestClearColor();
		~TestClearColor();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;
	private:
		float clearColor[4];
	};
}