#pragma once

#include <glad/glad.h>
#include <assert.h>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

static int WINDOW_WIDTH = 1280;
static int WINDOW_HEIGHT = 720;

#define ASSERT(x) if (!(x)) assert(false)

#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLCheckError())

void GLClearError();
bool GLCheckError();

class Renderer {
public:

    void Clear();
    void Draw(VertexArray& va, IndexBuffer& ib, Shader& shader);

private:


};