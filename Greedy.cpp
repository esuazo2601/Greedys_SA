#include "Greedy.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3 || string(argv[1]) != "-i") {
        std::cout << "Uso incorrecto. Debe especificar una instancia de problema con '-i <nombre-archivo>'." << std::endl;
        return 1; // Código de error
    }
    string nombreArchivo = argv[2];

    Greedy(nombreArchivo);
    return 0;
}

int Greedy(string nombre_archivo){
    vector<string>mat;
    ifstream archivo(nombre_archivo);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo: " << nombre_archivo << endl;
        return 1; // Código de error
    }

    // Leer el contenido del archivo y almacenarlo en el vector mat
    string linea;
    while (getline(archivo, linea)) {
        mat.push_back(linea);
    }
    archivo.close();

    cout << "Procesando instancia de problema desde el archivo: " << nombre_archivo << endl<<endl;
    unordered_map<char, int> frec;
    string resultado(mat.size(), ' '); // Inicializa resultado con espacios
    
    int lenY = mat.size();
    int lenX = mat.at(0).length();
    //Cuenta cuantas veces se repite cada caracter 
    for (int i = 0; i <lenY ; i++) {
        char letra = mat[i][0];
        if (frec.find(letra) != frec.end()) {
            frec[letra]++;
        } else {
            frec[letra] = 1;
        }
    }

    int max_rep = 0;
    char letra;
    //Revisa cual se repite mas para usar el primer lugar 
    for (auto caracter : frec) {
        if (caracter.second > max_rep) {
            letra = caracter.first;
            max_rep = caracter.second;
        }
    }

    resultado[0] = letra;
    vector<pair<int, char>> dist(mat.size(), make_pair(0, 'A'));
    //Se calculan las distancias para la primera columna 
    for (int i = 0; i < lenY; i++) {
        dist[i].first = dist[i].first + distancia(mat[i][0], resultado[0]);
        dist[i].second = mat[i][0];
    }

    //Se itera por columnas y se agrega al vector respuesta aquella letra que tenga menor distancia
    for (int i = 1; i < lenX; i++) {
        for (int j = 0; j < lenY; j++) {
            dist[j].first += distancia(mat[j][i], resultado[i - 1]); //distancia numerica
            dist[j].second = mat[j][i]; //letra en cuestión
        }
        resultado[i] = menor_distancia(dist, i);
    }

    //Se muestra por pantalla la cadena resultante
    for (int i = 0; i < lenX; i++) {
        cout << resultado[i] <<" ";
    }
    cout<<endl;
    int costo_total = 0;
    for(int i=0;i<lenY; i++){
        int dist_2 = dist[i].first*dist[i].first;
        costo_total += dist_2;
    }
    cout<< "Costo Total: "<<costo_total<<endl;
    return costo_total;
}

//Se retorna 0 si las letras son iguales, de lo contrario 1, se usa para sumar distancia.
int distancia(char a, char b) {
    if (a == b) {
        return 0;
    } else {
        return 1;
    }
}

//Función que determina cual es la letra con menor distancia
char menor_distancia(vector<pair<int, char>>& dist, int j) {
    int len = dist.size();
    int menor = dist[0].first;
    char letra = dist[0].second;
    for (int i = j; i < len; i++) {
        if (dist[i].first < menor) {
            menor = dist[i].first;
            letra = dist[i].second;
        }
    }
    return letra;
}
