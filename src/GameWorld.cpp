#include "GameWorld.h"

GameWorld::GameWorld() {
    player = new Car(0,0);
}

void GameWorld::update_world(EventManager* events){
    if(events->get_is_accelerating()){
        player->accelerate();
    }
    player->steer(events->get_steering_axis());
    player->compute_car_position();
}

void GameWorld::clear_game_data(){
    delete player;
}