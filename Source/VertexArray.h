#pragma once

#include "VertexBuffer.h"
#include "BufferLayout.h"
#include <vector>

class VertexArray {
public:
	VertexArray();
	~VertexArray();
	
	void Bind() const;
	void Unbind() const;

	void AddBuffer(const VertexBuffer& buffer, const BufferLayout& layout);


private:
	unsigned int id;
	std::vector<VertexBuffer> buffers;
};
