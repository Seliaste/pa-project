//
// Created by seliaste on 24/11/22.
//

#include "Trigger.h"

Trigger::Trigger(int x, int y, int w, int h) {
    origin = glm::vec2(x,y);
    dimension = glm::vec2(w,h);
}

bool Trigger::is_overlapping(Car *player) const {
    return
    player->get_pos_x() >= origin.x &&
    player->get_pos_x() <= origin.x + dimension.x &&
    player->get_pos_y() >= origin.y &&
    player->get_pos_y() <= origin.y + dimension.y;
}
