#include <bits/stdc++.h>
using namespace std;

/*
Be prepared with a programing IDE to complete the following exercise in 15 min.
Print a square pattern of numbers from n to 1 as shown below. Each of the numbers is separated by a single space.
Input Format: The input will contain a single integer (n)
Output expected: Square pattern from n to 1
Example
Input: 4
Output:
                            4 4 4 4 4 4 4  
                            4 3 3 3 3 3 4   
                            4 3 2 2 2 3 4   
                            4 3 2 1 2 3 4   
                            4 3 2 2 2 3 4   
                            4 3 3 3 3 3 4   
                            4 4 4 4 4 4 4  
*/

void printSquarePattern(int n) {
    // Número total de filas y columnas en el patrón
    int totalRows = 2 * n - 1;
    int totalCols = 2 * n - 1;

    // Iterar a través de cada celda en la matriz
    for (int i = 1; i <= totalRows; i++) {
        for (int j = 1; j <= totalCols; j++) {
            // Determinar el valor a imprimir en la celda
            int currentValue = max(abs(n - i), abs(n - j)) + 1;
            cout << currentValue << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Output
    printSquarePattern(n);

  return 0;
}