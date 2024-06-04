#include <iostream>

#include "jogador.hpp"
#include "jogo.hpp"


//respectivas funções para o atributo moedas
    int jogador:: Get_moedas(){return this->moedas;};
    
    void jogador:: Set_adicionar_moedas(int entrada){ this->moedas+=entrada;};
    void jogador:: Set_remover_moedas(int entrada){   this->moedas-=entrada;};

//respectivas funções para o atributo nome
std::string jogador:: Get_nome(){return this->nome;};

    
    jogador:: jogador(std::string entrada_nome)
    {
        this->nome=entrada_nome;
        this->moedas=100;
    };
