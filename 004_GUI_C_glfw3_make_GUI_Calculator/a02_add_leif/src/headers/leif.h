#ifndef LEIF_H
#define LEIF_H

#include <GLFW/glfw3.h>
#include <stdbool.h>


typedef struct {
    float x;
    float y;
} vec2s;

void lf_init_glfw(int width, int height, GLFWwindow* window);
void lf_begin();
void lf_div_bigin(vec2s position, vec2s size, bool visible);
void lf_div_end();
void lf_end();

#endif // LEIF_H
