#include <bits/stdc++.h>
using namespace std;

class Persona {
    private:
        string name;
        int edad;
    
    public:
        Persona(string, int);
        virtual void mostrar();
};

Persona::Persona(string _name, int _edad){
    name = _name;
    edad = _edad;
}

void Persona::mostrar(){
    cout << name << " " << edad << endl;
}




class Alumno : public Persona{
    private:
        string matricula;
        float notaFinal;
    public:
        Alumno(string, int, string, float); //PRIMERO LOS DE LA CLASE PADRE
        void mostrar();
};


Alumno::Alumno(string _name, int _edad, string _matricula, float _notaFinal) : Persona(_name, _edad){
    matricula = _matricula;
    notaFinal = _notaFinal;
}



void Alumno::mostrar(){
    Persona::mostrar();
    cout << "Nota final" << notaFinal << endl;
}





class Profesor : public Persona{
    private:
        string materia;

    public:
        Profesor(string, int, string); //PRIMERO LOS DE LA CLASE PADRE
        void mostrar();
};


Profesor::Profesor(string _name, int _edad, string _materia) : Persona(_name, _edad){
    materia = _materia;
}



void Profesor::mostrar(){
    Persona::mostrar();
    cout << "Nota final" << materia << endl;
}


int main() {

    Persona *Emilio = new Alumno("Emilio", 20, "A01366802", 98.5);


    Emilio -> mostrar();


}