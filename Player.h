#pragma once
#include <GLFW/glfw3.h>
#include "Point.h"
#include <iostream>
#include <math.h>
class Player
{
public:
    Point* pos;
    float xAlfa = 70;
    float zAlfa = 0;
    float speed = 0;
    float rotateSpeedX = 0;
    float rotateSpeedY = 0;
    int direction = 0;
    Player() {
        this->pos = new Point(0, 0);
    }




    void MoveCamera() {

         float angle = (-zAlfa / 180 * 3.1415) + (direction*1.57075);


         if (speed != 0) {
             pos->x += sin(angle) * speed;
             pos->y += cos(angle) * speed;
         }        



        zAlfa += rotateSpeedX;
        xAlfa += rotateSpeedY;

        glRotatef(-xAlfa, 1, 0, 0);
        glRotatef(-zAlfa, 0, 0, 1);

        glTranslatef(-pos->x, -pos->y, -2);
        

    }

    void Player_keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        /*if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
            speed = 0.1;
        }

        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            
        }
        
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
            speed = -0.1;
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
            speed = 0.1;
        }*/
        switch (key)
        {
            case GLFW_KEY_W:
                speed = (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) ? 0.1 : 0.0;
                break;
            case GLFW_KEY_A:
                if ((glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS))
                {
                    speed = 0.1;
                    direction = -1;
                }
                else {
                    speed = 0;
                    direction = 0;
                }
                break;
            case GLFW_KEY_S:
                speed = (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) ? -0.1 : 0.0;
                break;
            case GLFW_KEY_D:
                // Действия при нажатии клавиши D
                if ((glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS))
                {
                    speed = 0.1;
                    direction = 1;
                }
                else {
                    speed = 0;
                    direction = 0;
                }                
                break;
        default:
            speed = 0;
            direction = 0;
            break;
        }

        switch (key)
        {
            case GLFW_KEY_UP:
                rotateSpeedY = (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) ? 0.4 : 0.0;
                break;
            case GLFW_KEY_DOWN:
                rotateSpeedY = (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) ? -0.4 : 0.0;
                break;
            case GLFW_KEY_LEFT:
                rotateSpeedX = (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) ? 0.4 : 0.0;
                break;
            case GLFW_KEY_RIGHT:
                rotateSpeedX = (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) ? -0.4 : 0.0;
                break;
        default:
            rotateSpeedX = 0;
            break;
        }





        //if (key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT)) {   
        //    std::cout << 123;
        //    xAlfa += 2;
        //}

        //if ((key == GLFW_KEY_W)) {
        //    if ((action == GLFW_PRESS || action == GLFW_REPEAT)) {                
        //        pos->y += 0.1;
        //    }
        //    else /*if (action == GLFW_RELEASE)*/ {
        //        speed = 0;
        //    }
        //}

        //if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT)) {           
        //    xAlfa -= 2;
        //    // Добавьте здесь код обработки нажатия на стрелку вниз
        //}


        //if (key == GLFW_KEY_LEFT) {
        //    if ((action == GLFW_PRESS || action == GLFW_REPEAT)) {
        //        
        //        // Добавьте здесь код обработки нажатия на стрелку влево
        //        zAlfa += 2;
        //    }   
        //}
        //if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT)) {            
        //    zAlfa -= 2;
        //}






        //
        //if (key == GLFW_KEY_A) {
        //    if ((action == GLFW_PRESS || action == GLFW_REPEAT)) {
        //        this->pos->x -= 0.1;
        //        //angle -= 3.1415 * 0.5;
        //    }
        //    else /*if (action == GLFW_RELEASE)*/ {
        //        speed = 0;
        //        //angle += 3.1415 * 0.5 ;
        //    }
        //}
        //if (key == GLFW_KEY_D) {
        //    if ((action == GLFW_PRESS || action == GLFW_REPEAT)) {
        //        /*speed = 0.1;*/
        //        this->pos->x += 0.1;
        //        //angle += 3.1415 / 2;
        //    }
        //    else /*if (action == GLFW_RELEASE)*/ {
        //        speed = 0;
        //        //angle -= 3.1415 / 2;
        //    }
        //}
        //if (key == GLFW_KEY_S) {
        //    if ((action == GLFW_PRESS || action == GLFW_REPEAT)) {
        //        this->pos->y -= 0.1;
        //    }
        //    if (action == GLFW_RELEASE) {
        //        speed = 0;
        //    }

        //}
    }
    
};

