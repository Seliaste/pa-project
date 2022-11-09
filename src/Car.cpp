//
// Created by seliaste on 11/9/22.
//

#include "Car.h"
#include <cmath>


Car::Car(int x, int y){
    pos_x = x;
    pos_y = y;
    curr_speed_x = 0;
    front_vel = 0;
    rot = 0;
}

void Car::compute_car_position(){
    front_vel = speed_function(curr_speed_x);
    pos_x += front_vel;
}

double Car::speed_function(double x){
    return 1 - exp(5.*x);
}