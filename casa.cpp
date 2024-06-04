#include <iostream>
#include <string>
#include <vector>

#include "casa.hpp"
#include "jogador.hpp"

using namespace std;


void casa:: rank()
{


};

void casa:: select_games(int Quantidade_de_jogadores)
{
 char jogoo;
 cout<<"Selecione os jogos disponiveis"<<endl<<"(Somente o primeiro simbolo do nome)"<<endl;
 if(Quantidade_de_jogadores==1)
 {
cout<< "Para 1 jogador temos:"<<endl;
cout<< "Paciencia(P)"<<endl;
cout<< "21(2)"<<endl;

 }
else if(Quantidade_de_jogadores==2)
{
cout<< "Para 2 jogadores temos:"<<endl;
cout<< "21(2)"<<endl;
}
else if(Quantidade_de_jogadores==4)
{
cout<< "Para 4 jogadores temos:"<<endl;
    cout<< "Truco(T)"<<endl;
}

else{
    cout<<"Quantidade incompatível com os jogos disponiveis"<<endl;
    cout<<"As quantidades compativeis são: 1,2 ou 4"<<endl;
    return;
 }

 while(1){
 cin>>jogoo;
switch(jogoo)
{
  case 't'
  case 'T':  return t ;

  case 'p'
  case 'P':  return p ;

  case 2  :    return v ;
  default: cout<<"Invalido! Selecione novamente"<<endl;break;
}
 }

};
void casa:: explica_games()
{
   Jogo_21          vinte_um(1);
   Jogo_Paciencia   paciencia(1);
   Jogo_Truco       paciencia(1);

vinte_um.explica_jogo();
paciencia.explica_jogo();
truco.explica_jogo();
};

int casa:: Get_Quantidade_de_jogadores()
{
    return this->Quantidade_de_jogadores;
};

void casa:: Set_Quantidade_de_jogadores_Jogador_Entrou( )
{
 this->Quantidade_de_jogadores++;
 cout<<"Qual o nome do novo jogador?"<<endl;
 std::string nomee;
 cin>>nomee;
 jogador novo_jogador(nomee);
 this->jogadores.push_back(novo_jogador);
};

void casa:: Set_Quantidade_de_jogadores_Jogador_Saiu()
{
cout<<"Qual o nome do jogador que saiu?"<<endl;
std::vector nomee; cin>>nomee;
int tamanho_vector = this->jogadores.size();

//O for abaixo procura o elemento de jogadores onde tem o nome requisitado e então o exclui
for(int interacao=0;interacao<tamanho_vector;interacao++)
{
    if(nomee==jogadores[interacao].nome){jogadores.erase(jogadores.begin()+interacao);}
}

};

void casa:: Set_Quantidade_de_jogadores()
{
    cout<<"Aumentar(A) ou Diminuir(D)"<<endl; 
             char Aumentar_ou_Diminuir;bool sair;
             while(1)
             {
              cin>>Aumentar_ou_Diminuir;
             if(Aumentar_ou_Diminuir=='A'){this->Set_Quantidade_de_jogadores_Jogador_Entrou();sair++;}
             else if(Aumentar_ou_Diminuir=='D'){this->Set_Quantidade_de_jogadores_Jogador_Saiu();sair++; 
             }else{cout<<"Invalido!"<<endl;}
             if(sair)break;
             }
};