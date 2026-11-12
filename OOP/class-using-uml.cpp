/*
Write the complete C++ class definitions and member implementations 
(you can write them inline or outside with ::, just make sure syntax is 100% valid) for the following UML specification:

Class Engine:
- horsepower : int
+ Engine(hp : int = 100)
+ getHP() const : int
Class Car:
- model : string
- eng : Engine (Composition)
- speed : int
- totalCars : int (underlined in UML)
+ Car(m : string, hp : int) (initializes speed to 0, increments totalCars)
+ ~Car() (decrements totalCars)
+ accelerate(inc : int) : Car& (adds inc to speed and returns *this for cascading)
+ printStatus() const : void (prints model, eng.getHP(), speed, and totalCars)
+ getTotalCars() : int (underlined in UML)
*/
#include<iostream>
#include<string>
using namespace std;
class Engine{
    private:   
        int horsepower;
    public:
        Engine(int hp = 100) : horsepower(hp){}
        int getHP() const{
            return horsepower;
        };
        
};

class Car{
    private:
        string model;
        Engine eng;
        int speed;
        static int totalCars;
        public:
        Car(string m, int hp) : model(m), eng(hp), speed(0){
            totalCars++;
        }
        ~Car(){
            totalCars--;
        }
        Car& accelerate(int inc){
            speed = inc + speed;
            return *this;
        }
        void printStatus() const{
            cout << model << eng.getHP() << speed << totalCars << endl;
        }
        static int getTotalCars(){
            return totalCars;
        }
};

int Car::totalCars = 0;

int main()
{
    Car c1("Mercedes Benz", 1200);
    c1.printStatus();


    return 0;
}