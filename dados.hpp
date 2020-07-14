#ifndef DADOS_HPP_INCLUDED
#define DADOS_HPP_INCLUDED
    #include <iostream>
    #include <fstream>
    #include <cstdlib>
    #include <ctime>
    #include <iomanip>
    #include <cstring>
    #include <windows.h>
    using namespace std;
    using std::setw;
    using std::setiosflags;
    const char *naipe [4] = {"Copas","Paus", "Espadas","Ouros"};
    const char *face[10] = {"As", "Dois", "Tres", "Quatro","Cinco", "Seis", "Sete","Valete", "Dama","Rei"};
    int baralho [4][13]= {0};
    #define JOG_1 "jog1.txt"
    #define JOG_2 "jog2.txt"
    #define JOGO "jogo.txt"
    enum Status {
        HU =1, COMP
    };
    enum Player{
        JOG1 =1, JOG2
    };
    enum Estado{
        FIM, INICIO
    };
    typedef struct jogador{
        string nome;
        int vit,emp,der,valor,jogada;
        char  cartas[5][25];
        Status tipo_de_jogador;
        Player playn;
    }jogador ;



#endif // DADOS_HPP_INCLUDED
