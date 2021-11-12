#include <vector>
#include "nao_enforcou.hpp"

extern std::vector<char> chutes_errados;

bool nao_enforcou() {
    // o limite da forca são de 5 tentativas erradas
    return chutes_errados.size() < 5;
}