#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

string palavra_secreta = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_existe(char chute) {
    // passa a usar looping do C++ 11 usando a flag "-std=c++11" (ver Makefile)
    for (char letra : palavra_secreta) {
        if (chute == letra) {
            return true;
        }
    }

    return false;
}

bool nao_acertou() {
    for (char letra : palavra_secreta) {
        if (!chutou[letra]) {
            return true;
        }
    }
    return false;
}

bool nao_enforcou() {
    // o limite da forca são de 5 tentativas erradas
    return chutes_errados.size() < 5;
}

void imprime_cabecalho() {
    cout << "*********************" << endl;
    cout << "*** Jogo da Forca ***" << endl;
    cout << "*********************" << endl;
    cout << endl;
}

void imprime_erros() {
    cout << "Chutes errados: ";
    for (char letra: chutes_errados) {
        cout << letra << " ";
    }
    cout << endl;
}

void imprime_palavra() {
    for (char letra : palavra_secreta) {
        if (chutou[letra]) {
            cout << letra << " ";
        }
        else {
            cout << "_ "; 
        }
    }
    cout << endl;
}

void chuta() {
    cout << "Seu chute: ";
    char chute;
    cin >> chute;

    chutou[chute] = true;

    if (letra_existe(chute)) {
        cout << "Você acertou! Seu chute está na palavra!" << endl;
    }
    else {
        cout << "Você errou! Seu chute não está na palavra!" << endl;
        chutes_errados.push_back(chute);
    }
    cout << endl;
}

int main () {

    imprime_cabecalho();

    while (nao_acertou() && nao_enforcou()) {
        imprime_erros();

        imprime_palavra();

        chuta();
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era " << palavra_secreta << endl;
    if (nao_acertou()) {
        cout << "Você perdeu! Tente novamente!" << endl;
    }
    else {
        cout << "Parabéns! Você acertou a palavra secreta!" << endl;
    }
}