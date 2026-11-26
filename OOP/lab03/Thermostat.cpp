#include<iostream>
#include "Thermostat.h"

Thermostat::Thermostat() : room("Bilinmiyor"), temperature(20.0) {
}

Thermostat::Thermostat(std::string room, double temperature)
    : room(room), temperature(20.0) {
    setTemperature(temperature); // gecersizse 20 kalir
}

std::string Thermostat::getRoom() const {
    return room;
}

double Thermostat::getTemperature() const {
    return temperature;
}

void Thermostat::setRoom(std::string room) {
    this->room = room;
}

bool Thermostat::setTemperature(double temperature) {
    if (temperature >= 16.0 && temperature <= 30.0) {
        this->temperature = temperature;
        return true;
    }
    return false;
}

bool Thermostat::increase(double step) {
    if (step <= 0) {
        return false;
    }
    return setTemperature(temperature + step);
}

bool Thermostat::decrease(double step) {
    if (step <= 0) {
        return false;
    }
    return setTemperature(temperature - step);
}

void Thermostat::balanceWith(Thermostat& other) {
    double average = (temperature + other.temperature) / 2.0;
    setTemperature(average);
    other.setTemperature(average);
}