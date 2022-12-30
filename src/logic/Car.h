//
// Created by seliaste on 11/9/22.
//

#ifndef PA_PROJECT_CAR_H
#define PA_PROJECT_CAR_H

#include "glm/vec2.hpp"
#include "Track.h"

class Car {
private:
    constexpr static double v_max = 2;
    bool slowed;
    const double acceleration = 0.0125;
    const double turn_rate = 0.02;
    glm::dvec2 pos{}; // vector of center
    glm::dvec2 rot{}; // Vector of rotation
    double front_vel{};
    double curr_speed_x; // for speedFunction calculation
    static double speedFunction(double x);

public:
    /**
     *
     * @param x base horizontal position of the car
     * @param y base vertical position of the car
     */
    Car(double x, double y);

    /**
     * @brief Updates the car position according to its current variables
     */
    void computeCarPosition();

    /**
     * @brief Updates car values to increase speed.
     * Should be used when an acceleration event happens
     */
    void accelerate();

    /**
     * @brief Slows down the car
     * @param coeff range: [0,1], braking power
     */
    void brake(double coeff);

    /**
     * @brief Updates the car rotation
     * @param rate range: [-1,1], positive for clockwise and negative for counterclockwise
     */
    void steer(int rate);

    /**
     * @brief Gets the horizontal position on the car in the game world
     */
    [[nodiscard]] double getPosX() const;

    /**
     * @brief Gets the vertical position on the car in the game world
     */
    [[nodiscard]] double getPosY() const;

    /**
     * @brief Gets the angle the car is currently having
     */
    [[nodiscard]] double getRotationDegrees() const;

    /**
     * @brief Applies a slowdown, i.e. when the car is on a tile that slows down
     */
    void applySlowdown();

    /**
     *
     * @param track The track the car is on right now
     * @return character representing the tile type
     */
    char getTileUnderCar(Track *track) const;
};

#endif //PA_PROJECT_CAR_H
