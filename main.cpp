//---------------INCLUDES
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>  

#include "Jogo_21.hpp"
#include "Jogo_Truco.hpp"
#include "Jogo_Paciencia.hpp"

using namespace std;



//---------------FUNÇOES INLINE

inline void clear_screen() {
#ifdef _WIN32 // Verifica se estamos no Windows
    std::system("cls"); // Comando para limpar a tela no Windows
#else
    std::system("clear"); // Comando para limpar a tela no Linux/Unix
#endif
}

//---------------DECLARAÇAO DAS FUNÇOES DE MAIN
void entrar_jogo(int entrada_quantidade_de_jogadores)
{

char jogo_selecionado=casa.select_games(entrada_quantidade_de_jogadores);

//Dentro do Switch declara o objeto e já roda o jogo
switch(jogo_selecionado)
{
case 'v' : Jogo_21 vinte_um(entrada_quantidade_de_jogadores); vinte_um.Start(); break;
case 't' : Jogo_Truco Truco(entrada_quantidade_de_jogadores); Truco.Start(); break;
case 'p' : Jogo_Paciencia pacienciaa(entrada_quantidade_de_jogadores); pacienciaa.Start(); break;

}


//---------------MAIN
}

int main()
{
//Essa função inicializa a aleatoriedade que será muito usada ao longo do código, especificamente em Jogo.cpp, nas duas funções inline    
std::srand(static_cast<unsigned int>(std::time(nullptr)));

cout<<"Diga quantos jogadores tem inicialmente:"<<endl;
int quantidade_de_jogadores;
cin>>quantidade_de_jogadores;

//---------------INICIALIZAÇAO DO OBJETO CASA
Casa            casa(quantidade_de_jogadores);


//---------------LOBBY DO CODIGO
while(1)
{

cout<<"Selecione o que deseja fazer?(insira de 1 a 4)"<<endl;
cout<<"1 - Entrar em algum jogo"<<endl;
cout<<"2 - Mudar o numero de jogadores"<<endl;
cout<<"3 - Entender como os jogos funcionam"<<endl;
cout<<"4 - Encerrar "<<endl;

int selecao; bool encerrar;
cin>>selecao;

switch(selecao)
{
    case 1 : entrar_jogo(casa.Get_Quantidade_de_jogadores()) ;break;
    case 2 : casa.Set_Quantidade_de_jogadores()              ;break;
    case 3 :  casa.explica_games()                           ;break;
    case 4 :        encerrar++                               ;break;
    default:cout<<"Invalido! Insira Novamente"<<endl         ;break;
}


if(encerrar)break;
}

    return 0;
}