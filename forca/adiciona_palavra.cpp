#include <iostream>
#include <string>
#include <vector>
#include "adiciona_palavra.hpp"
#include "le_arquivo.hpp"
#include "salva_arquivo.hpp"

void adiciona_palavra() {
    std::cout << std::endl;
    std::cout << "Digite uma palavra, usando letras maiúsculas." << std::endl;
    std::string nova_palavra;
    std::cin >> nova_palavra;

    std::vector<std::string> lista_palavras = le_arquivo();
    lista_palavras.push_back(nova_palavra);

    salva_arquivo(lista_palavras);
}
