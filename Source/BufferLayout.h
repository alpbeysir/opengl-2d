#pragma once
#include <vector>
#include <glad/glad.h>


struct BufferElement {
	BufferElement(unsigned int _type, unsigned int _count, bool _normalized) {
		type = _type;
		count = _count;
		normalized = _normalized;
	}
	unsigned int type;
	unsigned int count;
	bool normalized;

	static unsigned int GetSizeOfType(unsigned int type) {
		switch (type) {
		case GL_FLOAT:
			return sizeof(GLfloat);
		case GL_UNSIGNED_INT:
			return sizeof(GLuint);
		case GL_BYTE:
			return sizeof(GLbyte);
		}
		//ASSERT(false);
		return 0;

	}
};

class BufferLayout {
public:
	BufferLayout() : stride(0) {};
	~BufferLayout() {};

	inline const unsigned int GetStride() const { return stride; };
	inline const std::vector<BufferElement>& GetElements() const { return elements; };

	template <typename T>
	void Push(unsigned int count) {

	}

	template<>
	void Push<float>(unsigned int count) {
		elements.push_back( { GL_FLOAT, count, GL_FALSE } );
		stride += sizeof(GLfloat) * count;
	}

	template<>
	void Push<unsigned int>(unsigned int count) {
		elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
		stride += sizeof(GLuint) * count;
	}

	template<>
	void Push<unsigned char>(unsigned int count) {
		elements.push_back({ GL_BYTE, count, GL_TRUE });
		stride += sizeof(GLbyte) * count;
	}

private:
	std::vector<BufferElement> elements;
	unsigned int stride;
};
