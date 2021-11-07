#include <iostream>
#include <string>

using namespace std;

string palavra_secreta = "MELANCIA";

bool letra_existe(char chute) {
    for (int i = 0; i < palavra_secreta.size(); i++) {
        if (chute == palavra_secreta[i]) {
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