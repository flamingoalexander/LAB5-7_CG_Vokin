#include <GLFW/glfw3.h>
#include <iostream>
#include "Point.h"
#include <math.h>
#include "Player.h"
float vert[] = { 1,1,0,  1,-1,0, -1,-1,0, -1,1,0 };

Player* player;
//float angle = -zAlfa / 180 * 3.1415;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    player->Player_keyCallback(window, key, scancode, action, mods);   
}



void DrawPrisma() {
    glPushMatrix();
    float prisma[] = { 0,0,2, 1,1,0,   1,-1,0, -1,-1,0, -1,1,0, 1,1,0 };
    glVertexPointer(3, GL_FLOAT, 0, &prisma);
    glColor3f(1, 0, 0);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 6);
    glPopMatrix();
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
                glColor3f(0, 0.2, 0);
            }
            else {
                glColor3f(1, 0, 1);
            }
            /*if ((i == 4) && (j == 4))
            {
                DrawPrisma();
            }*/
            glTranslatef(i * 2, j * 2, 0);
            glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
            glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
            glPopMatrix();
        }
    }


    glDisableClientState(GL_VERTEX_ARRAY);

}



int main(void)
{
    
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1360, 980, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwSetKeyCallback(window, keyCallback);
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glFrustum(-1, 1, -1, 1, 2, 80);
    player = new Player();


    glEnable(GL_DEPTH_TEST);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();


        player->MoveCamera();
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




