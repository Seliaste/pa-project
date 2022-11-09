//
// Created by seliaste on 11/9/22.
//

#include "car.h"
#include <cmath>

void init_car(car* input,int x, int y){
    input->pos_x = x;
    input->pos_y = y;
    input->curr_speed_x = 0;
    input->front_vel = 0;
    input->rot = 0;
}

void compute_car_position(car* car){
    car->front_vel = speed_function(car->curr_speed_x);
    car->pos_x += car->front_vel;
}

double speed_function(double x){
    return 1 - exp(5.*x);
}