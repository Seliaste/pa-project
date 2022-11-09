#include "game_logic.h"

data_struct* init_game_data(){
    auto* res = new data_struct;
    Car* player = new Car(0,0);
    res->player = player;
    return res;
}

void compute_logic(data_struct* data){
    data->player->compute_car_position();
}


void clear_game_data(data_struct* data){
    delete data->player;
    delete data;
}