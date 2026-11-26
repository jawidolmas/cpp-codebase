#pragma once

#include <string>

class Thermostat {
private:
    std::string room;
    double temperature;

public:
    Thermostat();
    Thermostat(std::string room, double temperature);

    std::string getRoom() const;
    double getTemperature() const;

    void setRoom(std::string room);
    bool setTemperature(double temperature);

    bool increase(double step);
    bool decrease(double step);

    void balanceWith(Thermostat& other);
};