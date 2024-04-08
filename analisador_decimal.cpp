//Joao P S L P
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Função para verificar se uma palavra é reconhecida pela gramática
bool verificarPalavra(const string& palavra) {
    char estado = 'p';
    for (char c : palavra) {
        switch (estado) {
            case 'p':
                if (c >= '0' && c <= '9')
                    estado = '1';
                else
                    return false; // Caractere inválido
                break;
            case '1':
                if (c >= '0' && c <= '9')
                    estado = '1';
                else
                    return false;
                break;
        }
    }
    return estado == '1';
}


int main() {
    string filename = "input.txt"; // Nome do arquivo de entrada
    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Erro ao abrir o arquivo " << filename << endl;
        return 1;
    }

    string palavra;
    while (inputFile >> palavra) {
        if (verificarPalavra(palavra)) {
            cout << palavra << " reconhecida" << endl;
        } else {
            cout << palavra << " rejeitada" << endl;
        }
    }

    inputFile.close();
    return 0;
}
