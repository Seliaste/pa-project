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

void Car::computeCarPosition() {
    front_vel = speedFunction(curr_speed_x) / (slowed ? 2 : 1);
    pos += rot * front_vel;
    if (slowed) {
        slowed = false;
    }
}

double Car::speedFunction(double x) {
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
    double angle = (rate * turn_rate) * steer_speed_coeff;
    rot = glm::rotate(rot, angle);
}

double Car::getPosX() const {
    return this->pos.x;
}

double Car::getPosY() const {
    return this->pos.y;
}

double Car::getRotationDegrees() const {
    return -glm::degrees(glm::orientedAngle(rot, glm::dvec2(1, 0)));
}

char Car::getTileUnderCar(Track *track) const {
    int tilesize = track->getTileSize();
    return track->getTileType(floor(pos.x / tilesize), floor(pos.y / tilesize));
}

void Car::applySlowdown() {
    slowed = true;
}

