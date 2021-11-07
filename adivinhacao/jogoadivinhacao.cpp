#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo de adivinhação! *" << endl;
    cout << "**************************************" << endl;

    cout << "Escolha o seu nível de dificuldade:" << endl;
    cout << "Fácil (F), Médio (M) ou Difícil (D)? ";

    char dificuldade;

    cin >> dificuldade;

    int numero_de_tentativas;

    switch (dificuldade)
    {
    case 'F':
        numero_de_tentativas = 15;
        break;
    case 'M':
        numero_de_tentativas = 10;
        break;
    default:
        numero_de_tentativas = 5;
        break;
    }
    
    srand(time(0));
    int numero_secreto = rand() % 100;
    
    bool nao_acertou = true;

    double pontos = 1000.0;

    int tentativas = 0;

    for(tentativas = 1; tentativas <= numero_de_tentativas; tentativas++) {

        int chute;

        cout << "Tentativa " << tentativas << " de " << numero_de_tentativas << endl;

        cout << "Qual o seu chute? ";
        cin >> chute;

        double pontos_perdidos = abs(chute - numero_secreto) / 2.0;        
        pontos = pontos - pontos_perdidos;

        cout << "O valor do seu chute é " << chute << endl;
        bool acertou = chute == numero_secreto;
        bool maior = chute > numero_secreto;

        if (acertou) {
            cout << "Parabéns! Você acertou o número secreto!" << endl;
            nao_acertou = false;
            break;
        }
        else if (maior) {
            cout << "Seu chute foi maior que o número secreto!" << endl;
        }
        else {
            cout << "Seu chute foi menor que o número secreto!" << endl;
        }
    }

    cout << "Fim de jogo!" << endl;
    if (nao_acertou) {
        cout << "Você perdeu! O número secreto era " << numero_secreto << ". Tente novamente!" << endl;
    } else {
        cout << "Você acertou o número secreto em " << tentativas << " tentativas!" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi de " << pontos << " pontos!" << endl;
    }
}