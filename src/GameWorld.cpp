#include "GameWorld.h"

GameWorld::GameWorld() {
    player = new Car(0,0);
}

void GameWorld::compute_logic(EventManager* events){
    if(events->get_is_accelerating()){
        player->accelerate();
    }
    player->compute_car_position();
}

void GameWorld::clear_game_data(){
    delete player;
}