#include <iostream>
#include <string>

using namespace std;

class Engine {
public:
    Engine() {
        cout << "Engine created." << std::endl;
    }

    ~Engine() {
        cout << "Engine destroyed." << std::endl;
    }
};

class Car {
private:
    Engine engine; // Composición: Car tiene un Engine

public:
    Car() {
        cout << "Car created." << std::endl;
    }

    ~Car() {
        cout << "Car destroyed." << std::endl;
    }
};

int main() {
    Car myCar; // Cuando se crea myCar, también se crea el Engine
    return 0;   // Cuando se destruye myCar, también se destruye el Engine
}