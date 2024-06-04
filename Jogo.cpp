#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>  

#include "jogo.hpp"
#include "jogador.hpp"

//a função abaixo gera um numero de 0 a 12 que diz respeito à uma das cartas da string constante simbolo
inline int numero_simbolo_aleatorio(){return (unsigned int)std::rand() % 12;}

//a função abaixo gera um numero de 0 a 3 que diz respeito à uma das cartas da string constante simbolo
inline int numero_naipe_aleatorio(){return (unsigned int)std::rand() % 3;}

inline void jogo:: clear_screen_jogo() {
#ifdef _WIN32 // Verifica se estamos no Windows
    std::system("cls"); // Comando para limpar a tela no Windows
#else
    std::system("clear"); // Comando para limpar a tela no Linux/Unix
#endif
cout<<"Para continuar insira qualquer coisa"<<endl;
char qualquer_coisa;cin>> qualquer_coisa;
}

   std::vector <char> cartas_usadas_naipes;
   std::vector <char> cartas_usadas_simbolos;



//essa função do TAD Baralho verifica se a carta em questão é repetida
   bool jogo:: carta_repetida(char naipe,char simbolo)
  {
      int tamanho_vector= cartas_usadas_naipes.size();
    for(int iteracao=0; iteracao<tamanho_vector; iteracao++)
    {
        if(cartas_usadas_naipes[iteracao]==naipe&&cartas_usadas_simbolos[iteracao]==simbolo)return 1;
    }

    return 0;
    }//end carta repetida


// A função carta aleatoria retornara uma string de dois caracteres sendo o primeiro o simbolo e o segundo o naipe
    std::string jogo:: carta_aleatoria()
    {
//Pegue naipes e simbolos aleatorios, e enquanto não der uma carta nova, mantenha pegando cartas aleatorias
        char naipee, simboloo;
  do{

        
        naipee   = numero_naipe_aleatorio();
        simboloo = numero_simbolo_aleatorio();
        
     }while(!carta_repetida( naipee,simboloo));
// E antes de terminar, registre a carta no vector de cartas usadas
    this->cartas_usadas_naipes.push_back(naipee);
    this->cartas_usadas_simbolos.push_back(simboloo);

//retorne a carta
    std::string retorno; 
    retorno.push_back(simboloo);
    retorno.push_back(naipee);
    return retorno;

    }


 void jogo::  explica_jogo()
       {
         std::cout<<"Temos 3 jogos disponiveis"<<std::endl;
         
         std::cout<<"Paciencia:"<<std::endl;
         std::cout<<"O Paciência é um jogo de cartas para apenas uma pessoa."<<std::endl;
         std::cout<<"O objetivo é criar quatro pilhas de cartas, uma para cada naipe, em ordem crescente (do ás ao rei)."<<std::endl;         
                  std::cout<<""<<std::endl;

         std::cout<<"Truco"<<std::endl;
         std::cout<<"Pode ser jogado por duas duplas"<<std::endl;         
         std::cout<<"O objetivo é fazer pontos através de blefes e estratégias para vencer as rodadas"<<std::endl;
                  std::cout<<""<<std::endl;


         std::cout<<"21"<<std::endl;

              DETERMINAR ISSO DIREITO
         std::cout<<"Pode ser jogado de até 5 pessoas"<<std::endl;    
         std::cout<<"O objetivo é chegar o mais próximo possível de 21 pontos sem ultrapassá-lo"<<std::endl;

         std::cout<<""<<std::endl;


       }; 

