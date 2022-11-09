//
// Created by seliaste on 11/9/22.
//

#ifndef PA_PROJECT_CAR_H
#define PA_PROJECT_CAR_H

#define V_MAX 50

class Car{
private:
    double pos_x;
    double pos_y;
    double rot;
    double front_vel;
    double curr_speed_x; // for speed_function calculation
    static double speed_function(double x);

public:
    Car(int x, int y);
    void compute_car_position();
};
#endif //PA_PROJECT_CAR_H
