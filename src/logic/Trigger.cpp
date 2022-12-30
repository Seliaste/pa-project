//
// Created by seliaste on 24/11/22.
//

#include "Trigger.h"

Trigger::Trigger(int x, int y, int w, int h) {
    origin = glm::vec2(x, y);
    dimension = glm::vec2(w, h);
}

bool Trigger::isOverlapping(Car *car) const {
    return
            car->getPosX() >= origin.x &&
            car->getPosX() <= origin.x + dimension.x &&
            car->getPosY() >= origin.y &&
            car->getPosY() <= origin.y + dimension.y;
}
