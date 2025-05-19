#include <iostream>
#include <string>

using namespace std;

class Engine {
public:
    Engine() {
        cout << "Engine created." << endl;
    }

    ~Engine() {
        cout << "Engine destroyed." << endl;
    }
};

class Car {
private:
    Engine* engine; // Agregación: Car tiene una referencia a Engine

public:
    Car(Engine* eng) : engine(eng) {
        cout << "Car created." << endl;
    }

    ~Car() {
        cout << "Car destroyed." << endl;
        // No se destruye el Engine aquí
    }
};

int main() {
    Engine myEngine;   // Engine es creado
    Car myCar(&myEngine); // Car recibe una referencia al Engine

    return 0; // Engine no se destruye hasta el final
}