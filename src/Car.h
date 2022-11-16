//
// Created by seliaste on 11/9/22.
//

#ifndef PA_PROJECT_CAR_H
#define PA_PROJECT_CAR_H

class Car{
private:
    static const int v_max = 50;
    const double acceleration = 0.1;
    const double turnrate = 0.1;
    double pos_x;
    double pos_y;
    double rot; // 360° of rotation. 0° = looking left from top down perspective
    double front_vel;
    double curr_speed_x; // for speed_function calculation
    static double speed_function(double x);

public:
    /**
     *
     * @param x base horizontal position of the car
     * @param y base vertical position of the car
     */
    Car(int x, int y);
    /**
     * @brief Updates the car position according to its current variables
     */
    void compute_car_position();
    /**
     * @brief Updates car values to increase speed.
     * Should be used when an acceleration event happens
     */
    void accelerate();

    /**
     * @brief Updates the car rotation
     * @param rate range: [-1,1], positive for clockwise and negative for counterclockwise
     */
    void steer(int rate);

};
#endif //PA_PROJECT_CAR_H
