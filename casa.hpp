/*
Essa é a modularização do Objeto Casa
que será responsável por mexer nas moedas de todos os jogadores 
e o objeto responsável pelo Lobby

 */
#ifndef CASA_HPP
#define CASA_HPP

#include <iostream>
#include <vector>
#include <string>

#include "jogador.hpp"

class jogador;

class Casa
{
  private:
unsigned int Quantidade_de_jogadores;


  protected:
//Essa função fala o ranking de moedas dos jogadores  
void rank();

char select_games(int);

void explica_games();

int Get_Quantidade_de_jogadores();

void Set_Quantidade_de_jogadores_Jogador_Entrou();

void Set_Quantidade_de_jogadores_Jogador_Saiu();

void Set_Quantidade_de_jogadores();

//Vetor que contém o registro de todos os jogadores
std::vector <jogador> jogadores;

  public:
  Casa(int Input_Quantidade_de_jogadores)
  {
    this->Quantidade_de_jogadores=Input_Quantidade_de_jogadores;
  };
  
  ~Casa(){rank();};
};
 #endif
  