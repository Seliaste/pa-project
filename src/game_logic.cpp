#include "game_logic.h"

data_struct* init_game_data(){
    auto* res = new data_struct;
    car* player = new car;
    init_car(player,0,0);
    res->player = player;
    return res;
}

void compute_logic(data_struct* data){
    compute_car_position(data->player);
}


void clear_game_data(data_struct* data){
    delete data->player;
    delete data;
}