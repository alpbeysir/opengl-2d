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

	class Test2DRender : public Test {
	public:
		Test2DRender();
		~Test2DRender();

		std::string name;

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;
	private:
		float positions[16] = {
	   -1.0f, -1.0f, 0.0f, 0.0f,
	   1.0f, -1.0f, 1.0f, 0.0f,
	   1.0f, 1.0f, 1.0f, 1.0f,
	   -1.0f, 1.0f, 0.0f, 1.0f
		};
		unsigned int indices[6] = {
	0, 1, 2,
	2, 3, 0
		};
		VertexArray va;
		VertexBuffer vb;
		BufferLayout bl;
		IndexBuffer ib;
		float transform1[2] = { 200, 200 };
		float transform2[2] = { 400, 600 };
		float scale1 = 10;
		float scale2 = 10;

		glm::mat4 proj;
		glm::mat4 view;
		glm::mat4 model;
		glm::mat4 mvp;

		Shader shader;
		Texture tex;

		Renderer renderer;
	};
}