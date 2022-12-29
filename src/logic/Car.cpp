//
// Created by seliaste on 11/9/22.
//

#include "Car.h"
#include <cmath>
#include "glm/common.hpp"
#include "glm/gtx/rotate_vector.hpp"
#include "glm/gtx/vector_angle.hpp"


Car::Car(double x, double y) {
    pos = glm::vec2(0, 0);
    pos.x = x;
    pos.y = y;
    curr_speed_x = 0;
    rot = glm::vec2(-1, 0);
    slowed = false;
}

void Car::compute_car_position() {
    front_vel = speed_function(curr_speed_x) / (slowed ? 2 : 1);
    pos += rot * front_vel;
    if (slowed) {
        slowed = false;
    }
}

double Car::speed_function(double x) {
    return -(1 - exp(v_max * x));
}

void Car::accelerate() {
    curr_speed_x += acceleration;
    if (curr_speed_x > 1) {
        curr_speed_x = 1;
    }
}

void Car::brake(double coeff) {
    curr_speed_x -= acceleration * coeff;
    if (curr_speed_x < 0) {
        curr_speed_x = 0;
    }
}

void Car::steer(int rate) {
    double steer_speed_coeff = (curr_speed_x * 1.5);
    if (steer_speed_coeff > 1) {
        steer_speed_coeff = 1;
    }
    double angle = (rate * turnrate) * steer_speed_coeff;
    rot = glm::rotate(rot, angle);
}

double Car::get_pos_x() const {
    return this->pos.x;
}

double Car::get_pos_y() const {
    return this->pos.y;
}

double Car::get_rotation_degrees() const {
    return -glm::degrees(glm::orientedAngle(rot, glm::dvec2(1, 0)));
}

char Car::get_tile_under_car(Track *track) const {
    int tilesize = track->get_tile_size();
    return track->get_tile_type(floor(pos.x / tilesize), floor(pos.y / tilesize));
}

void Car::apply_slowdown() {
    slowed = true;
}

