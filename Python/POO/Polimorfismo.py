class Universidad ():
    def __init__(self):
        self._universidad = 'ITESM'

    @property
    def universidad(self):
        print('La universidad es: ', self._universidad)

    @universidad.setter
    def universidad(self,universidad):
        self._universidad=universidad

class Estudiante(Universidad):
    def __init__(self, nombre, edad):
        self._nombre = nombre
        self._edad = edad
    
    @property
    def nombre(self):
        print ('El nombre del estudiante es: ', self._nombre)

    @nombre.setter
    def nombre(self,nombre):
        self._nombre=nombre

    @property
    def edad(self):
        print ('La edad del estudiante es: ', self._edad)

    @edad.setter
    def edad(self,edad):
        self._edad = edad

persona=Estudiante('Gonzalo',26)
persona.universidad
persona.nombre
persona.edad