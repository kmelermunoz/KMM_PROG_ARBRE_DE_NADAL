#include <iostream>
#include <string>

using namespace std;

// Funció per imprimir espais
void dibuixaEspais(int n) {
    if (n > 0) {
        cout << ' ';
        dibuixaEspais(n - 1);
    }
}

// Funció per imprimir asteriscs
void dibuixaAsteriscs(int n) {
    if (n > 0) {
        cout << '*';
        dibuixaAsteriscs(n - 1);
    }
}

// Funció per dibuixar una fila de l'arbre
void dibuixaFilaArbre(int altura, int fila) {
    dibuixaEspais(altura - fila);
    dibuixaAsteriscs(2 * fila - 1);
    cout << endl;
}

// Funció per dibuixar el tronc de l'arbre
void dibuixaTroncArbre(int altura, char caracter) {
    int troncAltura = altura / 2;

    for (int i = 0; i < troncAltura; ++i) {
        cout << string(((2 * altura) + 1) / 2 - 2, ' ') << string(4, caracter) << endl;
    }
}

// Funció principal per dibuixar l'arbre de Nadal amb recursivitat
void dibuixaArbreNadalRecursiu(int altura, char caracter, int fila) {
    if (fila > altura) {
        return;
    }

    dibuixaFilaArbre(altura, fila);
    dibuixaArbreNadalRecursiu(altura, caracter, fila + 1);
}

// Funció per dibuixar l'arbre de Nadal amb bucles
void dibuixaArbreNadalBucles(int altura, char caracter) {
    for (int i = 1; i <= altura; ++i) {
        dibuixaFilaArbre(altura, i);
    }

    dibuixaTroncArbre(altura, caracter);
}

// Funció principal per dibuixar l'arbre de Nadal amb recursivitat i bucles
void dibuixaArbreNadal(int altura, char caracter) {

    // Utilitzant recursivitat
    cout << "\nUtilitzant Recursivitat:\n";
    dibuixaArbreNadalRecursiu(altura, caracter, 1);
    dibuixaTroncArbre(altura, caracter);

    // Utilitzant bucles
    cout << "\nUtilitzant Bucles:\n";
    dibuixaArbreNadalBucles(altura, caracter);
}

// Funció principal
int main() {
    int mida;
    char caracterArbre;

    cout << "Aplicacio de l'Arbre de Nadal\n";

    cout << "Introduiu la mida de l'arbre de Nadal: ";
    cin >> mida;

    cout << "Introduiu el caracter que voleu utilitzar per a l'arbre: ";
    cin >> caracterArbre;

    // Crida a la funció per dibuixar l'arbre de Nadal
    dibuixaArbreNadal(mida, caracterArbre);

    return 0;
}
