#include "Test2DRender.h"

#include <iostream>

namespace test {
	Test2DRender::Test2DRender() 
		: vb(positions, 16 * sizeof(float)), ib(indices, 6), shader("Resources/Shaders/Test2DRender.shader"), tex("Resources/Textures/tex.png")
	{
		//Enable blending for transparency
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);

		bl.Push<float>(2);
		bl.Push<float>(2);
		va.AddBuffer(vb, bl);

		proj = glm::ortho(0.0f, (float)WINDOW_WIDTH, 0.0f, (float)WINDOW_HEIGHT);
		view = glm::mat4(1.0f);
		model = glm::mat4(1.0f);
		mvp = proj * view * model;

		shader.Bind();
		tex.Bind();

		shader.SetUniform1i("tex_slot", 0);
	}

	Test2DRender::~Test2DRender()
	{
	}

	void Test2DRender::OnUpdate(float deltaTime)
	{
	}

	void Test2DRender::OnRender()
	{      
		// Clear the screen
		renderer.Clear();

		//Garbage way to render multiple objects
		//TODO use batch rendering
		{
			model = glm::translate(glm::mat4(1.0f), glm::vec3(transform1[0], transform1[1], 0));
			mvp = proj * view * model;
			shader.SetUniformMat4f("u_MVP", mvp);
			shader.SetUniform1f("u_Scale", scale1);

			renderer.Draw(va, ib, shader);
		}

		{
			model = glm::translate(glm::mat4(1.0f), glm::vec3(transform2[0], transform2[1], 0));
			mvp = proj * view * model;
			shader.SetUniformMat4f("u_MVP", mvp);
			shader.SetUniform1f("u_Scale", scale2);

			renderer.Draw(va, ib, shader);
		}
	}

	void Test2DRender::OnImGuiRender()
	{
		ImGui::Text(u8"Türkçe karakter: ğüşiöçĞÜŞİÖÇ");
		ImGui::SliderFloat("X1", &transform1[0], 0 + scale1, WINDOW_WIDTH - scale1);
		ImGui::SliderFloat("Y1", &transform1[1], 0 + scale1, WINDOW_HEIGHT - scale1);
		ImGui::SliderFloat("Boyut1", &scale1, 1.0f, 200.0f);
		ImGui::SliderFloat("X2", &transform2[0], 0 + scale2, WINDOW_WIDTH - scale2);
		ImGui::SliderFloat("Y2", &transform2[1], 0 + scale2, WINDOW_HEIGHT - scale2);
		ImGui::SliderFloat("Boyut2", &scale2, 1.0f, 200.0f);
	}
}