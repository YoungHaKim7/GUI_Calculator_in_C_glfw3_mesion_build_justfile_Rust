#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <libelf.h>
#include <stdbool.h>
#include "headers/leif.h" // Include the header for custom functions and types

#define WINW 400
#define WINH 600
#define PANELH (WINW / 3.0f)

int main()
{
    // Initialize GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    // Create a window
    GLFWwindow* window = glfwCreateWindow(WINW, WINH, "calc", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize custom library (e.g., leif)
    lf_init_glfw(WINW, WINH, window);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

        // Begin custom rendering
        lf_begin();

        // Draw a panel
        lf_div_bigin((vec2s){0, 0}, (vec2s){WINW, PANELH}, true);

        // End custom rendering
        lf_div_end();
        lf_end();

        // Poll events and swap buffers
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    // Clean up
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
