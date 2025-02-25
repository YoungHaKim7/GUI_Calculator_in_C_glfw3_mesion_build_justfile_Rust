#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

#define WINW 400
#define WINH 600

int main()
{
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(WINW, WINH, "calc", NULL, NULL);

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
