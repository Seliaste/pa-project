//
// Created by seliaste on 11/9/22.
//

#ifndef PA_PROJECT_CAR_H
#define PA_PROJECT_CAR_H

#define V_MAX 50

typedef struct {
    double pos_x;
    double pos_y;
    double rot;
    double front_vel;
    double curr_speed_x; // for speed_function calculation
} car;

void init_car(car* input,int x, int y);

void compute_car_position(car* car);

double speed_function(double x);

#endif //PA_PROJECT_CAR_H
