#include <iostream>

#include <glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_glfw.h"
#include "ImGui/imgui_impl_opengl3.h"

glm::vec3 clearColour = glm::vec3(0.4f, 0.5f, 0.65f);

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

    // Initialise ImGui
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO* _io = &ImGui::GetIO(); (void)_io;

        // Set style to rounded
        ImGui::StyleColorsClassic();
        ImGui::GetStyle().WindowRounding = 8.0f;

        ImGui_ImplGlfw_InitForOpenGL(windowHandle, true);
        ImGui_ImplOpenGL3_Init("#version 330");
    }

    while (!glfwWindowShouldClose(windowHandle))
    {
        glfwPollEvents();

        // Update Here
        {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            ImGui::ShowDemoWindow();
        }

        glClearColor(clearColour.r, clearColour.g, clearColour.b, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Render Here
        {
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glOrtho(-4.0f, 4.0f, -4.0f, 4.0f, 0.0f, 10.0f);
        }

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(windowHandle);
    }

    // Close ImGui
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    return 0;
}