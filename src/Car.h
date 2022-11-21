//
// Created by seliaste on 11/9/22.
//

#ifndef PA_PROJECT_CAR_H
#define PA_PROJECT_CAR_H

#include <glm/vec2.hpp>

class Car{
private:
    static const int v_max = 1;
    const double acceleration = 0.1;
    const double turnrate = 0.1;
    glm::dvec2 pos;
    glm::dvec2 rot; // Vector of rotation
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

    void brake();

    /**
     * @brief Updates the car rotation
     * @param rate range: [-1,1], positive for clockwise and negative for counterclockwise
     */
    void steer(int rate);

    double get_pos_x() const;

    double get_pos_y() const;
};
#endif //PA_PROJECT_CAR_H
