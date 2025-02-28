#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define WIN_WIDTH 400
#define WIN_HEIGHT 600

// Calculator state
char input_buffer[100] = {0};
char output_buffer[100] = {0};
bool clear_buffer = false;
bool add = false, mul = false, divv = false, sub = false;
float result = 0.0;
static float num[10];
int count = 0;

// Button labels
const char *button_labels[] = {
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
    ".", "+", "-", "x", "/", "C", "="
};

// Button rectangles (x, y, width, height)
typedef struct {
    float x, y, w, h;
} Button;

Button buttons[17];

// Function to check if a point is inside a button
bool is_point_in_button(float x, float y, Button button) {
    return x >= button.x && x <= button.x + button.w &&
           y >= button.y && y <= button.y + button.h;
}

// Function to handle button clicks
void handle_button_click(const char *label) {
    if (strcmp(label, "+") == 0 || strcmp(label, "-") == 0 ||
        strcmp(label, "/") == 0 || strcmp(label, "x") == 0 ||
        strcmp(label, "=") == 0) {
        num[count] = atof(input_buffer);
        count++;
        clear_buffer = true;

        if (strcmp(label, "+") == 0) add = true;
        if (strcmp(label, "-") == 0) sub = true;
        if (strcmp(label, "/") == 0) divv = true;
        if (strcmp(label, "x") == 0) mul = true;
    }

    if (strcmp(label, "=") == 0) {
        if (add) {
            result = num[0] + num[1];
        } else if (sub) {
            result = num[0] - num[1];
        } else if (divv) {
            result = num[0] / num[1];
        } else if (mul) {
            result = num[0] * num[1];
        }

        add = sub = divv = mul = false;
        snprintf(output_buffer, sizeof(output_buffer), "%.3f", result);
        result = 0.0;
    } else if (strcmp(label, "C") == 0) {
        memset(input_buffer, 0, sizeof(input_buffer));
        memset(output_buffer, 0, sizeof(output_buffer));
        count = 0;
        for (int i = 0; i < 10; i++) num[i] = 0;
    } else {
        if (clear_buffer) {
            memset(input_buffer, 0, sizeof(input_buffer));
            clear_buffer = false;
        }
        strncat(input_buffer, label, 1);
        strncat(output_buffer, label, 1);
    }
}

// Function to render buttons
void render_buttons() {
    for (int i = 0; i < 17; i++) {
        glBegin(GL_QUADS);
        glVertex2f(buttons[i].x, buttons[i].y);
        glVertex2f(buttons[i].x + buttons[i].w, buttons[i].y);
        glVertex2f(buttons[i].x + buttons[i].w, buttons[i].y + buttons[i].h);
        glVertex2f(buttons[i].x, buttons[i].y + buttons[i].h);
        glEnd();
    }
}

// Function to initialize buttons
void init_buttons() {
    float x = 10, y = WIN_HEIGHT - 60;
    float button_width = 80, button_height = 50;
    float gap = 10;

    for (int i = 0; i < 17; i++) {
        buttons[i].x = x;
        buttons[i].y = y;
        buttons[i].w = button_width;
        buttons[i].h = button_height;

        x += button_width + gap;
        if ((i + 1) % 4 == 0) {
            x = 10;
            y -= button_height + gap;
        }
    }
}

// GLFW mouse click callback
void mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        ypos = WIN_HEIGHT - ypos; // Convert to OpenGL coordinates

        for (int i = 0; i < 17; i++) {
            if (is_point_in_button(xpos, ypos, buttons[i])) {
                handle_button_click(button_labels[i]);
                break;
            }
        }
    }
}

// Main rendering function
void render(GLFWwindow *window) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    render_buttons();

    glfwSwapBuffers(window);
}

int main() {
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "GLFW Calculator", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    init_buttons();

    while (!glfwWindowShouldClose(window)) {
        render(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
