//
// Created by seliaste on 11/9/22.
//

#include "Car.h"
#include <cmath>
#include <glm/vec2.hpp>
#include <glm/gtx/rotate_vector.hpp>


Car::Car(int x, int y){
    pos = glm::vec2(0,0);
    pos.x = (double) x;
    pos.y = (double) y;
    curr_speed_x = 0;
    front_vel = 0;
    rot = glm::vec2(1,0);
}

void Car::compute_car_position(){
    front_vel = speed_function(curr_speed_x);
    pos += rot*front_vel;
}

double Car::speed_function(double x){
    return (1 - exp(v_max*x));
}

void Car::accelerate(){
    curr_speed_x += acceleration;
    if(curr_speed_x > 1){
        curr_speed_x = 1;
    }
}

void Car::brake() {
    curr_speed_x -= acceleration;
    if(curr_speed_x < 0){
        curr_speed_x = 0;
    }
}

void Car::steer(int rate) {
    rot = glm::rotate(rot,(double)rate*turnrate);
}

double Car::get_pos_x() const{
    return this->pos.x;
}

double Car::get_pos_y() const{
    return this->pos.y;
}

