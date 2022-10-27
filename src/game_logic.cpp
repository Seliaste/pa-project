#include "game_logic.h"

data_struct* init_game_data(){
    auto* res = new data_struct;
    car* player = new car;
    res->player = player;
    return res;
}

void clear_game_data(data_struct* data){
    delete data->player;
    delete data;
}