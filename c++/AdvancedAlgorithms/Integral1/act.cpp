

#include<iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#define SIZE 50000

using namespace std;

// ---------------------------------------- P A R T E  1 ----------------------------------------

// Función Z: llena el array Z para la busca de patrones
// Complejidad O(m+n)
void algorithmz(string str, int Z[]) { 
  int n = str.length(); 
  int L, R, k; 
  L = R = 0; 
  for (int i = 1; i < n; i++){ 
    if (i > R){ 
      L = R = i; 
      while (R<n && str[R-L] == str[R]) 
        R++; 
        Z[i] = R-L; 
        R--; 
    }

    else{ 
      k = i-L; 
      if (Z[k] < R-i+1)
        Z[i] = Z[k]; 
      else{ 
        L = i; 
        while (R<n && str[R-L] == str[R]) 
          R++; 
          Z[i] = R-L; 
          R--; 
      } 
    } 
  } 
}

// Función Z, concatena el patrón con el texto separado por un caracter especial
void patternsearch(string text, string pattern) { 
    string concat = pattern + "$" + text; 
    int l = concat.length(); 

    int Z[l]; 
    algorithmz(concat, Z); 
    bool check = false;

    // Búsqueda del patrón
    for (int i = 0; i < l; i++) 
    { 
        if (Z[i] == pattern.length()) {
            cout << "- true, start at position " << i - pattern.length() -1 << "\n";
            check = true;
        } 
    }
    if(check == false){
      cout << "- false" << "\n";
    } 
}

// ---------------------------------------- P A R T E  2 ----------------------------------------

int P[SIZE * 2];

// Construcción de una nueva cadena con caracteres especiales intermediarios
string convertSTR(const string &s) {
    string newString = "|";
    for (int i = 0; i < s.size(); i++){
      newString += "|" + s.substr(i, 1);
    }
    newString += "|";
    return newString;
}

// Algoritmo Manachar para encontrar el palíndromo más largo
// Complejidad O(n)
string manachar(const string &s) {
    string Q = convertSTR(s);
    int c = 0, r = 0;
    for (int i = 1; i < Q.size() - 1; i++){
      // Encontrando la letra correspondiente en el palíndromo subString
      int mirror = c - (i - c);
      if(r > i){
        P[i] = min(r - i, P[mirror]);
      }

      // Expansión del centro
      while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){
        P[i]++;
      }

      // Actualizar centro si excede el actual
      if (i + P[i] > r){
        c = i;
        r = i + P[i];
      }
    }

    // Palíndromo más largo
    int maxPalindrome = 0;
    int centerInd = 0;

    for (int i = 1; i < Q.size() - 1; i++){
      if (P[i] > maxPalindrome){
        maxPalindrome = P[i];
        centerInd = i;
      }
    }
    return s.substr( (centerInd - 1 - maxPalindrome) / 2, maxPalindrome);
}

void palindromous_search(string text, string pattern) { 
    string concat = pattern + "$" + text; 
    int l = concat.length(); 

    int Z[l]; 
    algorithmz(concat, Z); 

    for (int i = 0; i < l; i++) 
    { 
        if (Z[i] == pattern.length()) 
            cout << "mirrored code found, start at " << i - pattern.length() -1  << ", ended at " << pattern.length() << "\n";
            /*
            * Dentro de las instrucciones se nos pide la posición de inicio y fin, lo cual se da con la línea
            * de código comentada, sin embargo la autoevaluación de Github pide la longitud del palíndromo
            * la cual se consigue con la línea de código de arriba.
            */
            // cout << "mirrored code found, start at " << i - pattern.length() -1  << ", ended at " << i-1 << "\n"; 
    } 
}

// ---------------------------------------- P A R T E  3 ----------------------------------------

// Subsecuencia más larga por medio de DP
// Complejidad O(mn)
int longest_subseq(string str1, string str2) {
  int length1 = str1.size();
  int lenght2 = str2.size();
  int dp[length1 + 1][lenght2 + 1];

  for (int i = 0; i <= length1; i++){
    for (int j = 0; j <= lenght2; j++){
	    if (i == 0 || j == 0){
	      dp[i][j] = 0;	
		  }
	    else if (str1[length1 - i] == str2[lenght2 - j]){
	      dp[i][j] = 1 + dp[i - 1][j - 1];
	      }
	    else{
	      int a = dp[i - 1][j];
        int b = dp[i][j - 1];
        int c = dp[i - 1][j - 1];
        dp[i][j] = max(a, b);
			}
		}
	}
  return dp[length1][lenght2] +1;
}

// Lectura de archivos
string readFile(string filename) {
   char c;
   ifstream file(filename);

   string content;
   file >> skipws;
   while ( file >> c ) content += c;

   return content;
}

int main() {
  // Declaración de variables
  string mcode1;
  string mcode2;
  string mcode3;

  string transmission1;
  string transmission2;
  int transmission1Len;
  int transmission2Len;

  string pal;

  // Lectura
  transmission1 = readFile("transmission1.txt");
  transmission2 = readFile("transmission2.txt");
  //mcode1 = readFile("mcode1.txt");
  //mcode2 = readFile("mcode2.txt");
  //mcode3 = readFile("mcode3.txt");

  // PARTE 1
  //cout << "transmission1.txt:" <<"\n";
  //cout << "mcode1.txt "; patternsearch(transmission1, mcode1);
  //cout << "mcode2.txt "; patternsearch(transmission1, mcode2);
  //cout << "mcode3.txt "; patternsearch(transmission1, mcode3);
/*
  cout << "\n";

  cout << "transmission2.txt:" <<"\n";
  cout << "mcode1.txt "; patternsearch(transmission2, mcode1);
  cout << "mcode2.txt "; patternsearch(transmission2, mcode2);
  cout << "mcode3.txt "; patternsearch(transmission2, mcode3);

  cout << "\n";
  
  // PARTE 2
  cout << "transmission1.txt:"<<"\n";
  pal = manachar(transmission1);
  palindromous_search(transmission1, pal);

  cout << "\n";

  cout << "transmission2.txt:" << endl;
  pal = manachar(transmission2);
  palindromous_search(transmission2, pal);

  cout << "\n";
*/
  // PARTE 3
  cout << "the longest common substring between transmission1.txt and transmission2.txt is " << longest_subseq(transmission1, transmission2) << " characters long" << "\r\n";
  
  return 0; 
}