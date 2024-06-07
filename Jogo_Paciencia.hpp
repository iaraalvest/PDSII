 #ifndef JOGO_PACIENCIA_HPP
 #define JOGO_PACIENCIA_HPP

#include "jogo.hpp"

struct noCarta {
      int valor;
      char naipe;
      struct noCarta *prox;
};

class Jogo_Paciencia : public Jogo {
private:
    noCarta *monte;
    noCarta *pilhaDeBaixo[7];
    noCarta *pilhaDeCima[4];
    noCarta *atual;
    int linhaEscondida[7];

    void criarMonte();
    noCarta *removeMonte(int);
    void embaralharMonte();
    void distribuiCartas();
    void imprimeCartas();
    void proximaCarta();
    int podeMover(noCarta *, noCarta *);
    int moveBaixoBaixo(int, int, int);
    int moveMonteBaixo(int);
    int naipeCima(char);
    int moveBaixoCima(int);
    int moveMonteCima();
    int moveCimaBaixo(char, int);

public:
    Jogo_Paciencia();

    void explica_jogo() override;
    void Start() override;
};

#endif
