#include <bits/stdc++.h>

using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////
// Definición de la clase Concursante
class Concursante {
public:
    int resueltos;  // Cantidad de problemas resueltos
    int penalizacion;  // Penalización total en tiempo
    map<int, int> intentos;  // Mapa para contar intentos incorrectos por problema (problema -> intentos)

    // Constructor de la clase
    Concursante() : resueltos(0), penalizacion(0) {}
};

int main() {
    ifstream input("input.txt");  // Abrir el archivo de entrada
    string line;  // Variable para almacenar cada línea del archivo
    int num_casos;  // Número de casos de prueba
    input >> num_casos;  // Leer el número de casos de prueba
    getline(input, line);  // Leer el salto de línea después del número de casos
    getline(input, line);  // Leer la línea en blanco que sigue

    // Procesar cada caso de prueba
    for (int i = 0; i < num_casos; ++i) {
        map<int, Concursante> concursantes;  // Mapa para almacenar los datos de cada concursante

        // Leer cada línea del caso hasta encontrar una línea en blanco
        while (getline(input, line) && !line.empty()) {
            istringstream iss(line);  // Crear un stringstream para procesar la línea
            int concursante, problema, tiempo;
            char resultado;

            // Extraer concursante, problema, tiempo y resultado usando >>
            iss >> concursante >> problema >> tiempo >> resultado;

            // Si el resultado es 'C' (correcto), actualizamos la información del concursante
            if (resultado == 'C') {
                // Verificar si es la primera vez que se resuelve este problema
                if (concursantes[concursante].intentos.find(problema) == concursantes[concursante].intentos.end()) {
                    concursantes[concursante].intentos[problema] = 0;
                }
                // Aumentar la cantidad de problemas resueltos
                concursantes[concursante].resueltos += 1;
                // Calcular y añadir la penalización total (tiempo + 20 minutos por cada intento incorrecto)
                concursantes[concursante].penalizacion += tiempo + concursantes[concursante].intentos[problema] * 20;
            } 
            // Si el resultado es 'I' (incorrecto), aumentamos el contador de intentos para ese problema
            else if (resultado == 'I') {
                concursantes[concursante].intentos[problema] += 1;
            }
        }

        // Vector de tuplas para almacenar la clasificación
        vector<tuple<int, int, int>> clasificacion;

        // Llenar el vector con los datos de los concursantes
        for (auto it = concursantes.begin(); it != concursantes.end(); ++it) {
            int id = it->first;  // ID del concursante
            Concursante c = it->second;  // Datos del concursante
            // Agregar una tupla con problemas resueltos negativos (para orden descendente), penalización e id
            clasificacion.push_back(make_tuple(-c.resueltos, c.penalizacion, id));
        }

        // Ordenar la clasificación por problemas resueltos (de mayor a menor),
        // luego por penalización (de menor a mayor), y finalmente por número de concursante (de menor a mayor)
        sort(clasificacion.begin(), clasificacion.end());

        // Imprimir la clasificación
        for (auto it = clasificacion.begin(); it != clasificacion.end(); ++it) {
            int neg_resueltos = get<0>(*it);  // Problemas resueltos negativos
            int penalizacion = get<1>(*it);  // Penalización total
            int id = get<2>(*it);  // ID del concursante
            cout << id << " " << -neg_resueltos << " " << penalizacion << endl;
        }

        // Si no es el último caso, imprimir una línea en blanco para separar las salidas
        if (i < num_casos - 1) {
            cout << endl;
        }
    }

    // Cerrar el archivo de entrada
    input.close();
    return 0;
}
