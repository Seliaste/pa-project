#include "GameWorld.h"
#include <iostream>
GameWorld::GameWorld(TrackMenu* track_menu) {
    track = track_menu->getTrackQueue().front();
    start_pos = track->getStartPosition();
    int tile_size = track->getTileSize();
    startline = new Trigger(start_pos.x, start_pos.y, tile_size, tile_size);
    // initializes player car in the middle of the start line
    player = new Car(ceil(start_pos.x + tile_size / 2), ceil(start_pos.y + tile_size / 2));
    lap_timer = new Timer();
    initCheckpoints();
}

void GameWorld::updateWorld(EventManager *events) {
    if (events->get_is_accelerating()) {
        player->accelerate();
    }
    if (events->get_is_braking()) {
        player->brake(1.);
    }
    if (!(events->get_is_braking() || events->get_is_accelerating())) {
        player->brake(.1); // passive decay
    }
    player->steer(events->get_steering_axis());
    auto tile_under = player->getTileUnderCar(track);
    if (tile_under == 'o' || tile_under == 'g' || tile_under == 't') {
        player->applySlowdown();
    }
    player->computeCarPosition();
    computeCheckpointUpdates();
    if (startline->isOverlapping(player)) {
        tryValidatingLap();
    }
    if (events->get_wants_to_restart()) {
        resetGame();
    }
}

void GameWorld::clearGameData() {
    delete player;
    delete lap_timer;
    delete track;
    delete startline;
    for (Trigger *cp: checkpoints) {
        delete cp;
    }
}

void GameWorld::resetGame() {
    int tile_size = track->getTileSize();
    delete player;
    player = new Car(ceil(start_pos.x + tile_size / 2), ceil(start_pos.y + tile_size / 2));
    lap_timer->reset();
    validated[0] = false;
    validated[1] = false;
    validated[2] = false;
}

Car *GameWorld::getPlayerCar() {
    return player;
}

Timer *GameWorld::getLapTimer() {
    return lap_timer;
}

Track *GameWorld::getTrack() {
    return track;
}

void GameWorld::initCheckpoints() {
    int i = 0;
    glm::ivec2 size = track->getSize();
    int tilesize = track->getTileSize();
    for (int y = 0; y < size.y; y++) {
        for (int x = 0; x < size.x; x++) {
            if (track->getTileType(x, y) == 'c') {
                checkpoints[i] = new Trigger(x * tilesize, y * tilesize, tilesize, tilesize);
                i++;
            }
        }
    }
}

void GameWorld::computeCheckpointUpdates() {
    for (int i = 0; i < 3; i++) {
        if (checkpoints[i]->isOverlapping(player)) {
            validated[i] = true;
        }
    }
}

void GameWorld::tryValidatingLap() {
    bool allvalid = true;
    for (bool validation: validated) { allvalid = allvalid && validation; } // check all CPs
    if (allvalid) {
        track->writeLap(lap_timer->getCurrentTime());
        lap_timer->reset();
        validated[0] = false;
        validated[1] = false;
        validated[2] = false;
    }
}
