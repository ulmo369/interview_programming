#include <iostream>
#include <string>

using namespace std;
// Clase abstracta
class Animal {
public:
    virtual void makeSound() const = 0; // Método puro virtual
    virtual string getType() const = 0; // Otro método puro virtual
};

// Clase derivada concreta
class Dog : public Animal {
public:

    void makeSound() const override {
        cout << "Woof! Woof!" << endl;
    }

    string getType() const override {
        return "Dog";
    }
};

int main() {
    Animal* myDog = new Dog();
    
    std::cout << "My " << myDog->getType() << " says: ";
    myDog->makeSound();

    delete myDog;

    return 0;
}