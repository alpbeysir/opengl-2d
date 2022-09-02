#include "TestVertexColor.h"

namespace test {
	TestVertexColor::TestVertexColor()
		: vb(data, 20 * sizeof(float)), ib(indices, 6), shader("Resources/Shaders/TestVertexColor.shader")
	{
		bl.Push<float>(2);
		bl.Push<float>(3);
		va.AddBuffer(vb, bl);

		proj = glm::ortho(0.0f, (float)WINDOW_WIDTH, 0.0f, (float)WINDOW_HEIGHT);
		view = glm::mat4(1.0f);
		model = glm::mat4(1.0f);
		mvp = proj * view * model;

		shader.Bind();
		shader.SetUniformMat4f("u_MVP", glm::translate(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 0)));
		shader.SetUniform1f("u_Scale", 1.0f);

	}

	TestVertexColor::~TestVertexColor()
	{
	}

	void TestVertexColor::OnUpdate(float deltaTime)
	{
	}

	void TestVertexColor::OnRender()
	{
		renderer.Clear();
		renderer.Draw(va, ib, shader);
	}

	void TestVertexColor::OnImGuiRender()
	{
	}
}
