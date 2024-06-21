#include "Jogo_Truco.hpp"
#include <cstdlib>
#include <ctime>
#include "casa.hpp"

Jogo_Truco::Jogo_Truco() {
    baralho = {"A♦", "2♦", "3♦", "4♦", "5♦", "6♦", "7♦", "Q♦", "J♦", "K♦",
               "A♠", "2♠", "3♠", "4♠", "5♠", "6♠", "7♠", "Q♠", "J♠", "K♠",
               "A♥", "2♥", "3♥", "4♥", "5♥", "6♥", "7♥", "Q♥", "J♥", "K♥",
               "A♣", "2♣", "3♣", "4♣", "5♣", "6♣", "7♣", "Q♣", "J♣", "K♣"};
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void Jogo_Truco::explica_jogo() {
    std::cout << "Truco: Uma versão brasileira do jogo de cartas, jogada em duplas. As regras principais são...\n"
              << "1. Cada jogador recebe três cartas.\n"
              << "2. O objetivo é ganhar mais rodadas do que o adversário.\n"
              << "3. As cartas têm valores específicos: 3 > 2 > A > K > J > Q > 7 > 6 > 5 > 4.\n"
              << "4. Você pode aumentar a aposta dizendo 'Truco!'.\n";
}

void Jogo_Truco::Start() {
    std::cout << "Iniciando o jogo de Truco...\n";
    distribuir_cartas();
    mostrar_cartas();
    jogar_rodada();

}

void Jogo_Truco::distribuir_cartas() {
    std::cout << "Distribuindo cartas...\n";
    cartas_jogador1.clear();
    cartas_jogador2.clear();

    for (int i = 0; i < 3; ++i) {
        int index = std::rand() % baralho.size();
        cartas_jogador1.push_back(baralho[index]);
        baralho.erase(baralho.begin() + index);

        index = std::rand() % baralho.size();
        cartas_jogador2.push_back(baralho[index]);
        baralho.erase(baralho.begin() + index);
    }
}

void Jogo_Truco::mostrar_cartas() {
    std::cout << "Cartas do Jogador 1: ";
    for (const auto& carta : cartas_jogador1) {
        std::cout << carta << " ";
    }
    std::cout << "\nCartas do Jogador 2: ";
    for (const auto& carta : cartas_jogador2) {
        std::cout << carta << " ";
    }
    std::cout << std::endl;
}

void Jogo_Truco::jogar_rodada() {
    std::cout << "Jogando uma rodada de Truco...\n";
    int pontos_jogador1 = 0;
    int pontos_jogador2 = 0;

    for (int i = 0; i < 3; ++i) {
        std::cout << "Rodada " << i + 1 << ": " << std::endl;
        std::cout << "Jogador 1 joga: " << cartas_jogador1[i] << std::endl;
        std::cout << "Jogador 2 joga: " << cartas_jogador2[i] << std::endl;

        if (cartas_jogador1[i][0] > cartas_jogador2[i][0]) {
            std::cout << "Jogador 1 ganha a rodada!" << std::endl;
            pontos_jogador1++;
        } else {
            std::cout << "Jogador 2 ganha a rodada!" << std::endl;
            pontos_jogador2++;
        }
    }

    if (pontos_jogador1 > pontos_jogador2) {
        std::cout << "Jogador 1 vence o jogo!" << std::endl;
    } else {
        std::cout << "Jogador 2 vence o jogo!" << std::endl;
    }
    IJogo::clear_screen_jogo();
    
}