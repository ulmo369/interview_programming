#include <bits/stdc++.h>
using namespace std;

class Persona {
    protected:
        string name;
        int edad;
    
    public:
        Persona(string, int);
        void mostrarPersona();
};

Persona::Persona(string _name, int _edad){
    name = _name;
    edad = _edad;
}

void Persona::mostrarPersona(){
    cout << name << " " << edad << endl;
}

///////////////////////////////////////////
class Alumno : public Persona{
    private:
        string matricula;
        float notaFinal;
    public:
        Alumno(string, int, string, float); //PRIMERO LOS DE LA CLASE PADRE
        void mostrarAlumno();
};

Alumno::Alumno(string _name, int _edad, string _matricula, float _notaFinal) : Persona(_name, _edad){
    matricula = _matricula;
    notaFinal = _notaFinal;
}

void Alumno::mostrarAlumno(){
    mostrarPersona();
    cout << matricula << endl;
    cout << notaFinal << endl;
}

int main() {

    Alumno alumno1 ("Emilio", 20, "A01366802", 98.5);

    alumno1.mostrarAlumno();

}