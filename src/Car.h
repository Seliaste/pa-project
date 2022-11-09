//
// Created by seliaste on 11/9/22.
//

#ifndef PA_PROJECT_CAR_H
#define PA_PROJECT_CAR_H

class Car{
private:
    static const int v_max = 50;
    const double acceleration = 0.1;
    double pos_x;
    double pos_y;
    double rot;
    double front_vel;
    double curr_speed_x; // for speed_function calculation
    static double speed_function(double x);

public:
    Car(int x, int y);
    void compute_car_position();
    void accelerate();
};
#endif //PA_PROJECT_CAR_H