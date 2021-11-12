#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include "sorteia_palavra.hpp"
#include "le_arquivo.hpp"

extern std::string palavra_secreta;

void sorteia_palavra() {
    std::vector<std::string> lista_palavras = le_arquivo();
    
    srand(time(NULL));
    int indice_sorteado = rand() % lista_palavras.size();

    palavra_secreta = lista_palavras[indice_sorteado];
}