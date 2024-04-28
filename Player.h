#pragma once
#include <GLFW/glfw3.h>
#include "Point.h"
class Player
{
public:
    Point* pos;
    float xAlfa = 70;
    float zAlfa = 0;
    float speed = 0;

    Player() {
        pos = new Point(0, 0);
    }




    void MoveCamera() {

        /* if (speed != 0) {
             pos->x +=  ;
             pos->y +=  ;
         }*/        

        glRotatef(-xAlfa, 1, 0, 0);
        glRotatef(-zAlfa, 0, 0, 1);

        glTranslatef(0, 0, -2);
        

    }

    void Player_keyCallback(int key, int scancode, int action) {
        if (key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT)) {           
            xAlfa += 2;
        }

        if (key == GLFW_KEY_W) {
            if ((action == GLFW_PRESS || action == GLFW_REPEAT)) {
                pos->y += 0.1;
            }
            else /*if (action == GLFW_RELEASE)*/ {
                speed = 0;
            }
        }

        if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT)) {           
            xAlfa -= 2;
            // Добавьте здесь код обработки нажатия на стрелку вниз
        }


        if (key == GLFW_KEY_LEFT) {
            if ((action == GLFW_PRESS || action == GLFW_REPEAT)) {
                
                // Добавьте здесь код обработки нажатия на стрелку влево
                zAlfa += 2;
            }   
        }
        if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT)) {            
            zAlfa -= 2;
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
    
};

