#include "VertexArray.h"
#include "Renderer.h"
#include <glad/glad.h>


VertexArray::VertexArray() : id(0)
{
	glGenVertexArrays(1, &id);
	glBindVertexArray(id);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &id);
}

void VertexArray::Bind() const
{
	glBindVertexArray(id);
}

void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}

void VertexArray::AddBuffer(const VertexBuffer& buffer, const BufferLayout& layout)
{
	//Bind array
	Bind();
	//Bind buffer so that we can access OpenGL functions
	buffer.Bind();

	//Add buffer to list
	buffers.push_back(buffer);

	//Iterate through list, add each layout to the VAO
	const auto& elements = layout.GetElements();
	unsigned int offset = 0;
	for (int i = 0; i < elements.size(); i++)
	{
		const auto& current = elements[i];

		GLCall(glVertexAttribPointer(i, current.count, current.type, current.normalized ? GL_TRUE : GL_FALSE, layout.GetStride(), (const void*)offset));
		GLCall(glEnableVertexAttribArray(i));

		offset += current.count * current.GetSizeOfType(current.type);
	}
}

