#include "GameWorld.h"
#include <iostream>

GameWorld::GameWorld() {
    track = new Track("Tsukubad","../resources/track1.txt");
    glm::ivec2 startpos = track->get_start_position();
    int tile_size = track->get_tile_size();
    startline = new Trigger(startpos.x,startpos.y,tile_size,tile_size);
    player = new Car(startpos.x,startpos.y);
    lap_timer = new Timer();
    init_checkpoints();
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
    if(player->get_tile_under_car(track) == 'o'){
        player->apply_slowdown();
    }
    player->compute_car_position();
    compute_checkpoint_updates();
    if(startline->is_overlapping(player)){
        try_validating_lap();
    }
}

void GameWorld::clear_game_data(){
    delete player;
    delete lap_timer;
    delete track;
    for(Trigger* cp: checkpoints){
        delete cp;
    }
}

Car *GameWorld::getPlayerCar() {
    return player;
}

Timer* GameWorld::get_lap_timer() {
    return lap_timer;
}

Track* GameWorld::get_track(){
    return track;
}

void GameWorld::init_checkpoints() {
    int i = 0;
    glm::ivec2 size = track->get_size();
    int tilesize = track->get_tile_size();
    for(int y = 0; y < size.y; y++){
        for(int x = 0; x < size.x; x++){
            if(track->get_tile_type(x,y) == 'c'){
                checkpoints[i] = new Trigger(x * tilesize, y * tilesize, tilesize, tilesize);
                i++;
            }
        }
    }
}

void GameWorld::compute_checkpoint_updates() {
    for(int i = 0; i < 3; i++){
        if(checkpoints[i]->is_overlapping(player)){
            validated[i] = true;
        }
    }
}

void GameWorld::try_validating_lap() {
    bool allvalid = true;
    for(bool validation: validated){allvalid = allvalid && validation;} // check all CPs
    if(allvalid){
        lap_timer->reset();
        validated[0] = false;
        validated[1] = false;
        validated[2] = false;
    }
}
