#include <iostream>
#include <string>
#include <map>

using namespace std;

string palavra_secreta = "MELANCIA";
map<char, bool> chutou;

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
        for (char letra : palavra_secreta) {
            if (chutou[letra]) {
                cout << letra << " ";
            }
            else {
                cout << "_ "; 
            }
        }
        cout << endl;

        char chute;
        cin >> chute;

        chutou[chute] = true;

        if (letra_existe(chute)) {
            cout << "Você acertou! Seu chute está na palavra!" << endl;
        }
        else {
            cout << "Você errou! Seu chute não está na palavra!" << endl;
        }
    }
}