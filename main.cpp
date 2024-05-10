#include <GLFW/glfw3.h>
#include <iostream>
#include "Point.h"
#include <math.h>
#include "Player.h"
#include <vector>

#include <random>

// Функция для генерации случайного значения от 0 до 1
double randomValue() {
    // Создаем объект генератора случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0); // Определяем равномерное распределение в диапазоне [0, 1]

    return dis(gen); // Генерируем случайное значение и возвращаем его
}







//float vert[] = { 1,1,0,  1,-1,0, -1,-1,0, -1,1,0 };
float vert[] = { 0.01,0.01,0,  0.01,-0.01,0, -0.01,-0.01,0, -0.01,0.01,0 };
std::vector<float> normals = {1,1,3, 1,-1,3, -1,-1,3, -1,1,3};

void Draw_Cube(float x, float y, float z, float width, float height, float depth) {
    GLfloat vertices[] = {
     x - width, y - depth, z - height,
     x + width, y - depth, z - height,
     x + width, y + depth, z - height,
     x - width, y + depth, z - height,
     x - width, y - depth, z + height,
     x + width, y - depth, z + height,
     x + width, y + depth, z + height,
     x - width, y + depth, z + height
    };
    GLuint indices[] = {
     0, 1, 2,
     2, 3, 0,
     1, 5, 6,
     6, 2, 1,
     7, 6, 5,
     5, 4, 7,
     4, 0, 3,
     3, 7, 4,
     4, 5, 1,
     1, 0, 4,
     3, 2, 6,
     6, 7, 3
    };
    GLfloat normals[] = {
     0.0f, 0.0f, -1.0f,
     0.0f, 0.0f, -1.0f,
     0.0f, 0.0f, -1.0f,
     0.0f, 0.0f, -1.0f,
     0.0f, 0.0f, 1.0f,
     0.0f, 0.0f, 1.0f,
     0.0f, 0.0f, 1.0f,
     0.0f, 0.0f, 1.0f,
     -1.0f, 0.0f, 0.0f,
     -1.0f, 0.0f, 0.0f,
     -1.0f, 0.0f, 0.0f,
     -1.0f, 0.0f, 0.0f,
     1.0f, 0.0f, 0.0f,
     1.0f, 0.0f, 0.0f,
     1.0f, 0.0f, 0.0f,
     1.0f, 0.0f, 0.0f,
     0.0f, -1.0f, 0.0f,
     0.0f, -1.0f, 0.0f,
     0.0f, -1.0f, 0.0f,
     0.0f, -1.0f, 0.0f,
     0.0f, 1.0f, 0.0f,
     0.0f, 1.0f, 0.0f,
     0.0f, 1.0f, 0.0f,
     0.0f, 1.0f, 0.0f
    };
    glPushMatrix();
    //Init_Material();
    glColor3f(1, 1, 1);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glEnableClientState(GL_NORMAL_ARRAY);
    glNormalPointer(GL_FLOAT, 0, normals);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, indices);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glEnable(GL_NORMALIZE);
    glPopMatrix();
}





Player* player;
//float angle = -zAlfa / 180 * 3.1415;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    player->Player_keyCallback(window, key, scancode, action, mods);   
}



void DrawPrisma(int count, Point* pos, float transparency) {


    glPushMatrix();
    glTranslatef(pos->x,pos->y,pos->z);
    glScalef(1,1,1);
    std::vector<float> figure;
    std::vector<float> figureUP;
    std::vector<float> figureDOWN;
    float step = 2 * 3.1415 / count;   
        for (int i = 0; i < count; i++)
        {        
            for (int z = 0; z < 2; z++)
            {
                float koef = 0;
                if (z == 1)
                {
                    koef = 0.5;

                }
                if (z == 0)
                {
                    koef = 1.0;

                }
                 figure.push_back(cos(step * i)*(koef));
                 figure.push_back(sin(step * i)*(koef));
                 figure.push_back(z);
                if (z == 0) {
                    figureDOWN.push_back(cos(step * i));
                    figureDOWN.push_back(sin(step * i));
                    figureDOWN.push_back(z);
                }
                else {
                    figureUP.push_back(cos(step * i)/2);
                    figureUP.push_back(sin(step * i)/2);
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



    
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, figure.data());
    glNormalPointer(GL_FLOAT, 0, figure.data());
    glColor4f(1, 1, 0, transparency);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, count*2 + 2);

    glVertexPointer(3, GL_FLOAT, 0, figureUP.data());
    glNormalPointer(GL_FLOAT, 0, figureUP.data());


    //glColor4f(0, 0, 1, transparency);
    glDrawArrays(GL_POLYGON, 0, count);
    glVertexPointer(3, GL_FLOAT, 0, figureDOWN.data());
    glNormalPointer(GL_FLOAT, 0, figureDOWN.data());
    //glColor4f(1, 0, 0, transparency);
    glDrawArrays(GL_POLYGON, 0, count);
    


    
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    glPopMatrix();
}


void ShowWorld() {
    glShadeModel(GL_SMOOTH);
    //glNormal3f(0, 0, 1);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    for (int i = 0; i < 180; i++)
    {
        for (int j = 0; j < 180; j++)
        {
            glPushMatrix();
            
            if (((i + j) % 2) == 0) {
                glColor3f(1, 0.5, 0);
            }
            else {
                glColor3f(1, 0.5, 0);
            }
            glTranslatef(i * 2* 0.01, j * 2* 0.01, 0);
            glVertexPointer(3, GL_FLOAT, 0, &vert);
            glNormalPointer(GL_FLOAT, 0, normals.data());
            glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
            glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
            glPopMatrix();
            
        }
    }
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);

    //DRAW PRISMAS
    for (int i = 0; i < 9; i++)
    {
        float step = 2 * 3.1415 / 9;
        DrawPrisma(9, new Point((4*cos(step*i)) + 7, (4 * sin(step * i)) + 7, 1), 0.1*i + 0.1);
    }
    DrawPrisma(9, new Point(7,7,1), 1);

    //Draw_Cube(7, 7, 1, 1, 1, 1);    

}


void ApplyLight(float angle) {
    //glPushMatrix();

    //glRotatef(30, 0, 1, 0);
    std::vector<float> position;
    position.push_back(1);
    position.push_back((20*cos(angle)));
    position.push_back((20*sin(angle)));
    position.push_back(1);


    std::vector<float> direction;
    direction.push_back(0);
    direction.push_back(0);
    direction.push_back(-1);

    Draw_Cube(position[0], position[1], position[2]-2, 0.3, 0.3, 0.3);
    glLightfv(GL_LIGHT0, GL_POSITION, position.data());
    //glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 30);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction.data());
    //glPopMatrix();
}


void gameInit() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_ALPHA_TEST);
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
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 8.0);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 60);
    gameInit();
    /* Loop until the user closes the window */
    float angle = 0;
    float rotspeed = 0;
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glPushMatrix();
        
        
        player->MoveCamera();    

            ApplyLight(angle);
        
            ShowWorld();      

        glPopMatrix();

            
        

        
        angle += 0.01;
        angle = angle > 3.1415*2 ? 0 : angle;
            

        

            




        //var += 0.1;
        

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}




