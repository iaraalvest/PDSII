 #ifndef JOGADOR_HPP
 #define JOGADOR_HPP

#include <iostream>
#include <string>

#include "jogo.hpp"

class jogo;

class jogador
{
//Dando para JOGO o titulo de amigo, jogo pode manipular jogador como bem entender
    friend jogo;

    private:
std::string nome;
unsigned int moedas;

    protected:
//respectivas funções para o atributo moedas
    int  Get_moedas();
    void Set_adicionar_moedas(int );
    void Set_remover_moedas(int );

//respectivas funções para o atributo nome
std::string Get_nome();

    public:
    jogador(std::string );
};

  #endif
