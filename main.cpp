#include <GLFW/glfw3.h>
#include <iostream>
#include "Point.h"
#include <math.h>
float vert[] = {1,1,0,  1,-1,0, -1,-1,0, -1,1,0};
float xAlfa = 70;
float zAlfa = 0;
float speed = 0;
Point* pos;
//float angle = -zAlfa / 180 * 3.1415;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    if (key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
        std::cout << "Up arrow key pressed" << std::endl;
        xAlfa +=2;
    }
    if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
        std::cout << "Down arrow key pressed" << std::endl;
        xAlfa-=2;
        // Добавьте здесь код обработки нажатия на стрелку вниз
    }
    if (key == GLFW_KEY_LEFT) {
        if ((action == GLFW_PRESS || action == GLFW_REPEAT)) {
            std::cout << "Left arrow key pressed" << std::endl;
            // Добавьте здесь код обработки нажатия на стрелку влево
            zAlfa +=2;
        }
        else {

        }
    }

    if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
        std::cout << "Right arrow key pressed" << std::endl;
        // Добавьте здесь код обработки нажатия на стрелку вправо
        zAlfa -=2;
    }
    
    if (key == GLFW_KEY_W) {
        if ((action == GLFW_PRESS || action == GLFW_REPEAT)) {
            pos->y += 0.1;
        }
        else /*if (action == GLFW_RELEASE)*/ {
            speed = 0;
        }  
    }
    if (key == GLFW_KEY_A) {
        if ((action == GLFW_PRESS || action == GLFW_REPEAT)) {
            pos->x -= 0.1;
            //angle -= 3.1415 * 0.5;
        }
        else /*if (action == GLFW_RELEASE)*/ {
            speed = 0;
            //angle += 3.1415 * 0.5 ;
        }
    }
    if (key == GLFW_KEY_D) {
        if ((action == GLFW_PRESS || action == GLFW_REPEAT)) {
            /*speed = 0.1;*/
            pos->x += 0.1;
            //angle += 3.1415 / 2;
        }
        else /*if (action == GLFW_RELEASE)*/ {
            speed = 0;
            //angle -= 3.1415 / 2;
        }
    }
    if (key == GLFW_KEY_S) {
        if ((action == GLFW_PRESS || action == GLFW_REPEAT)) {
            pos->y -= 0.1;
        }
        if (action == GLFW_RELEASE) {
            speed = 0;
        }

    }
}

void ShowWorld() {
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, &vert);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            glPushMatrix();
            if (((i + j) % 2) == 0) {
                glColor3f(0, 0.5, 0);
            }
            else {
                glColor3f(1, 1, 1);
            }
            glTranslatef(i * 2, j * 2, 0);
            glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
                glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
            glPopMatrix();
        }
    }


    glDisableClientState(GL_VERTEX_ARRAY);

}


void MoveCamera() {   
    
   /* if (speed != 0) {
        pos->x +=  ;
        pos->y +=  ;
    }*/



    glRotatef(-xAlfa, 1, 0, 0);
    glRotatef(-zAlfa, 0, 0, 1);

    glTranslatef(-pos->x, -pos->y, -2);
}
int main(void)
{
    pos = new Point(0, 0);
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1000, 1000, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwSetKeyCallback(window, keyCallback);
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glFrustum(-1,1,-1,1, 2,80);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();


            MoveCamera();
            ShowWorld();

        glPopMatrix();









        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}