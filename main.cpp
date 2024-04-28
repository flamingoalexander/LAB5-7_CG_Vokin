#include <GLFW/glfw3.h>
#include <iostream>
#include "Point.h"
#include <math.h>
#include "Player.h"
#include <vector>
float vert[] = { 1,1,0,  1,-1,0, -1,-1,0, -1,1,0 };

Player* player;
//float angle = -zAlfa / 180 * 3.1415;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    player->Player_keyCallback(window, key, scancode, action, mods);   
}



void DrawPrisma(int count) {
    glPushMatrix();
    glTranslatef(8,8,1);
    glScalef(3,3,2);
    std::vector<float> figure;
    std::vector<float> figureUP;
    std::vector<float> figureDOWN;
    float step = 2 * 3.1415 / count;
   
    
        for (int i = 0; i < count; i++)
        {        
            for (int z = 0; z < 2; z++)
            {
                figure.push_back(cos(step * i));
                figure.push_back(sin(step * i));
                figure.push_back(z);
                if (z == 0) {
                    figureDOWN.push_back(cos(step * i));
                    figureDOWN.push_back(sin(step * i));
                    figureDOWN.push_back(z);
                }
                else {
                    figureUP.push_back(cos(step * i));
                    figureUP.push_back(sin(step * i));
                    figureUP.push_back(z);
                }
            }
            
        }   
    figure.push_back(figure[0]);
    figure.push_back(figure[1]);
    figure.push_back(figure[2]);
    figure.push_back(figure[3]);
    figure.push_back(figure[4]);
    figure.push_back(figure[5]);



    

    glVertexPointer(3, GL_FLOAT, 0, figure.data());
    glColor3f(1, 0, 0);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, count*2 + 2);
    glVertexPointer(3, GL_FLOAT, 0, figureUP.data());
    glDrawArrays(GL_POLYGON, 0, count);
    glVertexPointer(3, GL_FLOAT, 0, figureDOWN.data());
    glDrawArrays(GL_POLYGON, 0, count);
    
    glPopMatrix();
}


void ShowWorld() {
    glNormal3f(0, 0, 1);
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
    DrawPrisma(5);


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
    player = new Player();





    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-0.1, 0.1, -0.1, 0.1, 0.2, 200);
    //glFrustum(-0.1, 0.1, -0.1, 0.1, 0.2, 200);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glFrustum(-1, 1, -1, 1, 2, 200);
    //LIGHTING
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();
            glPushMatrix();
            glRotatef(30, 0,1,0);
            float position[] = { 0,0,1,0 };
            glLightfv(GL_LIGHT0, GL_POSITION, position);

            glPopMatrix();
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




