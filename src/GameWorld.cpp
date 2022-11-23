#include "GameWorld.h"

GameWorld::GameWorld() {
    player = new Car(0,0);
}

void GameWorld::update_world(EventManager* events){
    if(events->get_is_accelerating()){
        player->accelerate();
    }
    if(events->get_is_braking()){
        player->brake(1.);
    }
    if(!(events->get_is_braking() || events->get_is_accelerating())){
        player->brake(.1); // passive decay
    }
    player->steer(events->get_steering_axis());
    player->compute_car_position();
}

void GameWorld::clear_game_data(){
    delete player;
}

Car *GameWorld::getPlayerCar() {
    return player;
}
