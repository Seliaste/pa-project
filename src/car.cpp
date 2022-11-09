//
// Created by seliaste on 11/9/22.
//

#include "car.h"

void init_car(car* input,int x, int y){
    input->pos_x = x;
    input->pos_y = y;
    input->curr_speed_x = 0;
    input->front_vel = 0;
    input->rot = 0;
}

double speed_function(double x){
    return x**0.5;
}