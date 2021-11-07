#include <iostream>
#include <string>

using namespace std;

string palavra_secreta = "MELANCIA";

bool letra_existe(char chute) {
    // passa a usar looping do C++ 11 usando a flag "-std=c++11" (ver Makefile)
    for (char letra : palavra_secreta) {
        if (chute == letra) {
            return true;
        }
    }

    return false;
}

int main () {

    cout << "A palavra secreta é " << palavra_secreta << endl;

    bool nao_acertou = true;
    bool nao_enforcou = true;

    while (nao_acertou && nao_enforcou) {
        char chute;
        cin >> chute;

        if (letra_existe(chute)) {
            cout << "Você acertou! Seu chute está na palavra!" << endl;
        }
        else {
            cout << "Você errou! Seu chute não está na palavra!" << endl;
        }
    }
}