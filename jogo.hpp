 #ifndef JOGO_HPP
 #define JOGO_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>  

#include "casa.hpp"

class casa;

//Declaração da superclasse jogo
class Jogo : public casa
{
    private:
    // TAD Baralho
 struct Baralho
 {
  const char naipe[5]={'C','O','E','P'};;
  const char simbolo[14]={'A',1,2,3,4,5,6,7,8,9,10,'K','Q','J'};
 };
  
   std::vector <char> cartas_usadas_naipes;
   std::vector <char> cartas_usadas_simbolos;

    protected:

 //essa função no TAD Baralho verifica se a carta em questão é repetida
  bool carta_repetida(char ,char );
  
  std::string carta_aleatoria();

    public:
   inline void clear_screen_jogo();
   virtual void explica_jogo(); 
   virtual void Start();
};

#endif