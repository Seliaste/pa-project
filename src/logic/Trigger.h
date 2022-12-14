//
// Created by seliaste on 24/11/22.
//

#ifndef PA_PROJECT_TRIGGER_H
#define PA_PROJECT_TRIGGER_H

#include "glm/vec2.hpp"
#include "Car.h"

/**
 * A trigger will be a class used by the start/finish line and checkpoints to be sure the player has made a valid lap
 */
class Trigger {
private:
    glm::vec2 origin{};
    glm::vec2 dimension{};
public:
    /**
     * @param x Horizontal position
     * @param y Vertical position
     * @param w Width
     * @param h Height
     */
    Trigger(int x, int y, int w, int h);

    /**
     * Checks for collision between a car and this trigger
     * @param car Car to check collision for
     * @return true if there is overlap
     */
    bool isOverlapping(Car *car) const;
};


#endif //PA_PROJECT_TRIGGER_H
