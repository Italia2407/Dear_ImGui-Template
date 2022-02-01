#include <iostream>

#include <glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

glm::vec3 clearColour = glm::vec3(0.4f, 0.5f, 0.65f);

void DrawNGon(int numSides, float angle, glm::vec3 colour, glm::vec2 position, glm::vec2 scale)
{
    glColor3f(colour.r, colour.g, colour.b);
    glBegin(GL_POLYGON);

    for (int i = 0; i < numSides; i++)
    {
        float pointAngle = i * (360.0f / numSides) + angle;
        glVertex2f((glm::cos(glm::radians(pointAngle)) * scale.x) + position.x, (glm::sin(glm::radians(pointAngle)) * scale.y) + position.y);
    }

    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);
}
void DrawNGon(int numSides, float angle, glm::vec3 colour)
{
    DrawNGon(numSides, angle, colour, glm::vec2(0.0f, 0.0f), glm::vec2(1.0f, 1.0f));
}

int main()
{
    if (!glfwInit())
	{
		std::cerr << "Error: Failed to Initialise GLFW!" << std::endl;
		return -1;
	}

    GLFWwindow* windowHandle = glfwCreateWindow(640, 640, "Dear ImGui", nullptr, nullptr);
    if (!windowHandle)
    {
        std::cerr << "Error: Failed to Create Window!" << std::endl;
        glfwTerminate();
		return -1;
    }

    glfwMakeContextCurrent(windowHandle);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    while (!glfwWindowShouldClose(windowHandle))
    {
        glfwPollEvents();

        // Update Here
        {

        }

        glClearColor(clearColour.r, clearColour.g, clearColour.b, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Render Here
        {
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glOrtho(-4.0f, 4.0f, -4.0f, 4.0f, 0.0f, 10.0f);

            DrawNGon(3, 45.0f, glm::vec3(1.0f, 0.65f, 0.15f));
        }

        glfwSwapBuffers(windowHandle);
    }

    std::cout << "Hello World!" << std::endl;

    return 0;
}