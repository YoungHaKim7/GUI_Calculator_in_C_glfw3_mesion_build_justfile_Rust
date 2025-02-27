#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <leif.h>

#include <OpenGL/gl3.h>

#define WINW 400
#define WINH 600

#define PANELH WINW / 3.0f

int main()
{
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(WINW, WINH, "calc", NULL, NULL);

    glfwMakeContextCurrent(window);

    lf_init_glfw(WINW, WINH, window);

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
