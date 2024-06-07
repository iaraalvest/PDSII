#include "Jogo_Paciencia.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Jogo_Paciencia::Jogo_Paciencia()  {
    monte = nullptr;
    atual = nullptr;
    for (int i = 0; i < 7; ++i)
        pilhaDeBaixo[i] = nullptr;
    for (int i = 0; i < 4; ++i)
        pilhaDeCima[i] = nullptr;
}

void Jogo_Paciencia::explica_jogo() {
    std::cout << "Paciência é um jogo de cartas jogado individualmente. O objetivo é mover todas as cartas para as fundações, separando-as por naipes e em ordem crescente, do Ás ao Rei. "
              << "As cartas são dispostas em sete colunas no tableau, e você pode mover as cartas entre essas colunas seguindo regras específicas: as cartas devem ser empilhadas em ordem decrescente e alternando cores. "
              << "Você também pode comprar cartas do monte para tentar encontrar movimentos adicionais. O jogo termina quando todas as cartas forem movidas para as fundações, ou quando não houver mais movimentos possíveis." << std::endl;
}

void Jogo_Paciencia::Start() {
    char opcao, c;
    int i, j, j2;

    srand(time(NULL));

    criarMonte();
    embaralharMonte();
    distribuiCartas();
    while (true) {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

        // Imprimir as cartas
        imprimeCartas();

        cout << "O que você deseja fazer?\n"
                "a - Ver a próxima carta do monte\n"
                "b - Mover uma carta de uma pilha a outra\n"
                "c - Mover uma carta do monte a uma pilha\n"
                "d - Mover uma carta de uma pilha até a pilha de cima\n"
                "e - Mover carta do monte para pilha de cima\n"
                "f - Mover a carta da pilha de cima para a pilha de baixo\n\n";

        cin >> opcao;

        switch (opcao) {
            case 'A':
            case 'a':
                proximaCarta();
                break;
            case 'B':
            case 'b':
                cout << "Digite a linha e coluna da carta que você deseja mover:\n";
                cin >> i >> j;
                cout << "Digite a coluna onde você deseja colocar a carta:\n";
                cin >> j2;
                moveBaixoBaixo(i, j, j2);
                break;
            case 'C':
            case 'c':
                cout << "Digite a coluna onde você deseja colocar a carta:\n";
                cin >> j;
                moveMonteBaixo(j);
                break;
            case 'D':
            case 'd':
                cout << "Digite a coluna de onde você deseja tirar a carta:\n";
                cin >> j;
                moveBaixoCima(j);
                break;
            case 'E':
            case 'e':
                moveMonteCima();
                break;
            case 'F':
            case 'f':
                cout << "Digite o naipe [c/e/o/p] e a coluna onde você deseja inserir a carta:\n";
                cin >> c >> j;
                moveCimaBaixo(c, j);
                break;
            default:
                break;
        }
    }
}

// Função auxiliar para criar um nó de carta
noCarta *criar_carta(int valor, char naipe) {
  noCarta *carta = new noCarta;
  carta->valor = valor;
  carta->naipe = naipe;
  carta->prox = nullptr;
  return carta;
}

void Jogo_Paciencia::criarMonte() {
  monte = nullptr;
  noCarta *atual = nullptr;
  for (int c1 = 0; c1 < 4; ++c1) {
    for (int c2 = 1; c2 <= 13; ++c2) {
      char naipe;
      if (c1 == 0)
        naipe = 'p'; // Paus
      else if (c1 == 1)
        naipe = 'c'; // Copas
      else if (c1 == 2)
        naipe = 'e'; // Espadas
      else
        naipe = 'o'; // Ouros
      noCarta *nova_carta = criar_carta(c2, naipe);
      if (monte == nullptr) {
        monte = nova_carta;
        atual = monte;
      } else {
        atual->prox = nova_carta;
        atual = atual->prox;
      }
    }
  }
}

noCarta *Jogo_Paciencia::removeMonte(int posicao) {
  noCarta *atual = monte;
  noCarta *anterior = nullptr;
  for (int c = 0; c < posicao; ++c) {
    anterior = atual;
    atual = atual->prox;
  }
  if (anterior == nullptr)
    monte = monte->prox;
  else
    anterior->prox = atual->prox;
  return atual;
}

void Jogo_Paciencia::embaralharMonte() {
  noCarta *n1 = nullptr, *novomonte = nullptr;
  srand(time(NULL));
  n1 = removeMonte(rand() % 52);
  novomonte = n1;
  for (int c = 51; c > 0; --c) {
    n1->prox = removeMonte(rand() % c);
    n1 = n1->prox;
  }
  n1->prox = nullptr;
  monte = novomonte;
}

void Jogo_Paciencia::distribuiCartas() {
  noCarta *atual = nullptr;
  for (int c1 = 0; c1 < 7; ++c1) {
    pilhaDeBaixo[c1] = monte;
    for (int c2 = 0; c2 <= c1; ++c2)
      monte = monte->prox;
    atual = pilhaDeBaixo[c1];
    while (atual->prox != monte)
      atual = atual->prox;
    atual->prox = nullptr;
    linhaEscondida[c1] = c1;
  }
}

void Jogo_Paciencia::imprimeCartas() {
  noCarta *baixo[7], *cima[4];
  for (int c1 = 0; c1 < 4; ++c1)
    cima[c1] = pilhaDeCima[c1];
  for (int c1 = 0; c1 < 7; ++c1)
    baixo[c1] = pilhaDeBaixo[c1];
  cout << "\n\n\n";
  cout << "Monte ->  ";
  if (atual == nullptr)
    cout << "[   ]";
  else
    cout << "[" << atual->valor << atual->naipe << "]";
  cout << "       ";
  for (int c1 = 0; c1 < 4; ++c1) {
    if (cima[c1] == nullptr)
      cout << "[   ] ";
    else {
      while (cima[c1]->prox != nullptr)
        cima[c1] = cima[c1]->prox;
      cout << "[" << cima[c1]->valor << cima[c1]->naipe << "] ";
    }
  }
  cout << "\n\n";
  cout << "      0     1     2     3     4     5     6\n\n";
  int c1 = -1;
  while (baixo[0] != nullptr || baixo[1] != nullptr || baixo[2] != nullptr ||
         baixo[3] != nullptr || baixo[4] != nullptr || baixo[5] != nullptr ||
         baixo[6] != nullptr) {
    ++c1;
    cout << c1 << "  ";
    for (int c2 = 0; c2 < 7; ++c2)
      if (baixo[c2] != nullptr) {
        if (linhaEscondida[c2] <= c1)
          cout << "[" << baixo[c2]->valor << baixo[c2]->naipe << "] ";
        else
          cout << "[???] ";
        baixo[c2] = baixo[c2]->prox;
      } else
        cout << "      ";
    cout << "\n";
  }
  cout << "\n";
}

void Jogo_Paciencia::proximaCarta() {
  if (atual == nullptr)
    atual = monte;
  else
    atual = atual->prox;
}

int Jogo_Paciencia::podeMover(noCarta *rem, noCarta *add) {
  if (rem->valor != (add->valor - 1))
    return 0;
  while (rem->prox != nullptr) {
    if (rem->valor != (rem->prox->valor + 1))
      return 0;
    rem = rem->prox;
  }
  return 1;
}

int Jogo_Paciencia::moveBaixoBaixo(int i, int j, int j2) {
  noCarta *add = nullptr, *rem = nullptr, *rem_ant = nullptr;
  add = pilhaDeBaixo[j2];
  rem = pilhaDeBaixo[j];
  if (rem == nullptr)
    return 0;
  for (int c = 0; c < i; ++c) {
    rem_ant = rem;
    rem = rem->prox;
    if (rem == nullptr)
      return 0;
  }
  if (add == nullptr) {
    if (rem->valor != 13)
      return 0;
    pilhaDeBaixo[j2] = rem;
    if (rem_ant != nullptr)
      rem_ant->prox = nullptr;
    else
      pilhaDeBaixo[j] = nullptr;
  } else {
    while (add->prox != nullptr)
      add = add->prox;
    if (podeMover(rem, add) == 0)
      return 0;
    if ((add->naipe == 'c' && rem->naipe == 'o') ||
        (add->naipe == 'o' && rem->naipe == 'c') ||
        (add->naipe == 'p' && rem->naipe == 'e') ||
        (add->naipe == 'e' && rem->naipe == 'p') ||
        (add->naipe == 'c' && rem->naipe == 'c') ||
        (add->naipe == 'e' && rem->naipe == 'e') ||
        (add->naipe == 'o' && rem->naipe == 'o') ||
        (add->naipe == 'p' && rem->naipe == 'p'))
      return 0;
    add->prox = rem;
    if (rem_ant != nullptr)
      rem_ant->prox = nullptr;
    else
      pilhaDeBaixo[j] = nullptr;
  }
  linhaEscondida[j]--;
  return 1;
}

int Jogo_Paciencia::moveMonteBaixo(int j) {
  noCarta *n1 = pilhaDeBaixo[j], *n_ant = monte, *n2 = nullptr;
  if (atual == nullptr)
    return 0;
  if (n1 != nullptr) {
    while (n1->prox != nullptr)
      n1 = n1->prox;
    if (atual->valor != (n1->valor - 1))
      return 0;
    if ((n1->naipe == 'c' && atual->naipe == 'o') ||
        (n1->naipe == 'o' && atual->naipe == 'c') ||
        (n1->naipe == 'p' && atual->naipe == 'e') ||
        (n1->naipe == 'e' && atual->naipe == 'p') ||
        (n1->naipe == 'c' && atual->naipe == 'c') ||
        (n1->naipe == 'e' && atual->naipe == 'e') ||
        (n1->naipe == 'o' && atual->naipe == 'o') ||
        (n1->naipe == 'p' && atual->naipe == 'p'))
      return 0;
  }
  if (atual == n_ant)
    n_ant = nullptr;
  else
    while (n_ant->prox != atual)
      n_ant = n_ant->prox;
  if (n1 != nullptr) {
    n1->prox = atual;
  } else {
    if (atual->valor != 13)
      return 0;
    pilhaDeBaixo[j] = atual;
  }
  if (n_ant != nullptr)
    n_ant->prox = atual->prox;
  else
    monte = atual->prox;
  n2 = atual;
  atual = atual->prox;
  n2->prox = nullptr;
  return 1;
}

int Jogo_Paciencia::naipeCima(char c) {
  if (c == 'c')
    return 0;
  if (c == 'e')
    return 1;
  if (c == 'o')
    return 2;
  if (c == 'p')
    return 3;
  return -1;
}

int Jogo_Paciencia::moveBaixoCima(int j) {
  noCarta *n1 = pilhaDeBaixo[j], *n2 = nullptr, *n1_ant = nullptr;
  if (n1 == nullptr)
    return 0;
  while (n1->prox != nullptr) {
    n1_ant = n1;
    n1 = n1->prox;
  }
  int c = naipeCima(n1->naipe);
  n2 = pilhaDeCima[c];
  if (n2 == nullptr) {
    if (n1->valor == 1) {
      pilhaDeCima[c] = n1;
      if (n1_ant != nullptr)
        n1_ant->prox = nullptr;
      else
        pilhaDeBaixo[j] = nullptr;
      linhaEscondida[j]--;
      return 1;
    } else {
      return 0;
    }
  } else {
    while (n2->prox != nullptr)
      n2 = n2->prox;
    if (n2->valor != (n1->valor - 1))
      return 0;
    n2->prox = n1;
    if (n1_ant != nullptr)
      n1_ant->prox = nullptr;
    else
      pilhaDeBaixo[j] = nullptr;
    linhaEscondida[j]--;
    return 1;
  }
}

int Jogo_Paciencia::moveMonteCima() {
  noCarta *n1 = atual, *n2 = nullptr, *n1_ant = monte;
  if (n1 == nullptr)
    return 0;
  if (n1_ant == n1)
    n1_ant = nullptr;
  else
    while (n1_ant->prox != n1)
      n1_ant = n1_ant->prox;
  int c = naipeCima(n1->naipe);
  n2 = pilhaDeCima[c];
  if (n2 == nullptr) {
    if (n1->valor == 1) {
      pilhaDeCima[c] = n1;
      atual = atual->prox;
      if (n1_ant != nullptr) {
        n1_ant->prox = n1->prox;
        n1->prox = nullptr;
      } else {
        monte = n1->prox;
        n1->prox = nullptr;
      }
      return 1;
    } else {
      return 0;
    }
  } else {
    while (n2->prox != nullptr)
      n2 = n2->prox;
    if (n2->valor != (n1->valor - 1))
      return 0;
    n2->prox = n1;
    atual = atual->prox;
    if (n1_ant != nullptr) {
      n1_ant->prox = n1->prox;
      n1->prox = nullptr;
    } else {
      monte = n1->prox;
      n1->prox = nullptr;
    }
    return 1;
  }
}

int Jogo_Paciencia::moveCimaBaixo(char c, int j) {
  noCarta *n1 = pilhaDeCima[naipeCima(c)], *n1_ant = nullptr,
          *n2 = pilhaDeBaixo[j];
  if (naipeCima(c) == -1)
    return 0;
  if (n1 == nullptr)
    return 0;
  while (n1->prox != nullptr) {
    n1_ant = n1;
    n1 = n1->prox;
  }
  if (n2 == nullptr) {
    if (atual->valor != 13)
      return 0;
    pilhaDeBaixo[j] = n1;
    if (n1_ant == nullptr)
      pilhaDeCima[naipeCima(c)] = nullptr;
    else
      n1_ant->prox = nullptr;
  } else {
    while (n2->prox != nullptr)
      n2 = n2->prox;
    if (n1->valor != (n2->valor - 1))
      return 0;
    if ((n1->naipe == 'c' && n2->naipe == 'o') ||
        (n1->naipe == 'o' && n2->naipe == 'c') ||
        (n1->naipe == 'p' && n2->naipe == 'e') ||
        (n1->naipe == 'e' && n2->naipe == 'p') ||
        (n1->naipe == 'c' && n2->naipe == 'c') ||
        (n1->naipe == 'e' && n2->naipe == 'e') ||
        (n1->naipe == 'o' && n2->naipe == 'o') ||
        (n1->naipe == 'p' && n2->naipe == 'p'))
      return 0;
    n2->prox = n1;
    if (n1_ant == nullptr)
      pilhaDeCima[naipeCima(c)] = nullptr;
    else
      n1_ant->prox = nullptr;
  }
  return 1;
}
