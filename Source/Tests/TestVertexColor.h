#pragma once

#include "Test.h"
#include <glad/glad.h>

#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <imgui/imgui.h>

#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "BufferLayout.h"
#include "Texture.h"

namespace test {

	class TestVertexColor : public Test {
	public:
		TestVertexColor();
		~TestVertexColor();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;
	private:
		float data[20] = {
			/*Position data*/ -1.0f, -1.0f, /*Color data*/ 0.3f, 0.5f, 0.1f,
			/*Position data*/ 1.0f, -1.0f, /*Color data*/ 0.6f, 0.5f, 0.1f,
			/*Position data*/ 1.0f, 1.0f, /*Color data*/ 0.3f, 0.5f, 0.1f,
			/*Position data*/ -1.0f, 1.0f, /*Color data*/ 0.3f, 0.5f, 0.1f,
		};
		unsigned int indices[6] = {
	0, 1, 2,
	2, 3, 0
		};
		VertexArray va;
		VertexBuffer vb;
		BufferLayout bl;
		IndexBuffer ib;

		glm::mat4 proj;
		glm::mat4 view;
		glm::mat4 model;
		glm::mat4 mvp;

		Shader shader;
		Renderer renderer;
	};
}
