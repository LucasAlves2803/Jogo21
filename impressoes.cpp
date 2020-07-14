#include "impressoes.hpp"
#include "stdio.h"
void imprime_carta(string nome, int jogada ,char * carta){
    system("cls");
    //cout << "\t\t\t\t Vez do(a) " << nome << endl;
    //Sleep(1500);
    system("cls");
    cout << "\t \t \tDistribuindo as cartas..." << endl;
    cout << "\t \t \tJogador: " << nome << endl;
    cout << "\t \t \t" << jogada << "o. carta: " << carta << endl;
    Sleep(2300);}

void embaralhando(int rodada){
   system("cls");
   cout << "\t \t \t" << rodada+1 << "o. rodada" << endl;
   Sleep(1000);
   cout << "\t \t \tEmbaralhando as cartas..." << endl;
   Sleep(1500);
   system("cls");
}

void mensagem(string nome, int * op){
    system("cls");
    cout <<"\t \t \t" << nome << " escolheu";
    if (*op == 1){
        cout << " pegar uma carta" << endl;
    }
    else{
        cout << " NAO pegar uma carta" << endl;
    }
    Sleep(1000);
}

void gravacao(jogador * jog){
    string nome_arq;
    if (jog->playn == JOG1){
        nome_arq = JOG_1;
    }
    else{
        nome_arq = JOG_2;
    }
    ofstream arq;
    arq.open(nome_arq.c_str(),ios::out);
    arq << jog->nome << endl;
    arq << jog->jogada << endl;
    for (int i=0; i < jog->jogada ; i++){
        arq << jog->cartas[i] << endl;
    }
    arq << jog->valor << endl;
}


void imprime_resultado(int rod,jogador * jog1, jogador * jog2){
    //char a;
    system("cls");
    cout << "\t \t \t \t Resultado da " << rod+1 << "o rodada" << endl;
    impressao(jog1,jog2);
    resultado(jog1,jog2);
    cout << "\t \t Digite enter para continuar";
    cin.ignore(1,'\n');
    cin.ignore(1,'\n');
}

void resultado(jogador * jog1, jogador * jog2){
    if ( jog1->valor > 21 || jog2->valor > 21){
        if ((jog1->valor > 21 && jog2->valor > 21)){
             jog1->emp++;
             jog2->emp++;
            cout << "\t \t Os jogadores empataram!!!!" << endl;
        }
        else if ( jog1->valor > 21){
            cout << "\t \t Parabens, " << jog2->nome << " voce venceu!!!" << endl;
            jog2->vit++;
            jog1->der++;
        }
        else{
            cout << "\t \t Parabens, " << jog1->nome << " voce venceu!!!" << endl;
            jog1->vit++;
            jog2->der++;
        }
    }
    else{
        if (jog1->valor > jog2->valor){
            cout << "\t \t Parabens, " << jog1->nome << " voce venceu!!!" << endl;
            jog1->vit++;
            jog2->der++;
        }
        else if (jog2->valor > jog1->valor){
            cout << "\t \t Parabens, " << jog2->nome << " voce venceu!!!" << endl;
            jog2->vit++;
            jog1->der++;
        }
        else{
            cout << "\t \t Os jogadores empataram!!!!" << endl;
            jog2->emp++;
            jog1->emp++;
        }
    }
}


void impressao(jogador * jog1, jogador * jog2){
    int maior = (jog1->jogada >= jog2->jogada ? jog1->jogada : jog2->jogada);
    cout << "\t \t Jogadores: " << setw(17) << setiosflags(ios::left) << jog1->nome << " \t \t" << jog2->nome << endl;
    for (int i=0; i < maior ; i++){
        if (i < 2){
            if ( i ==0){
                cout << " \t \t Cartas:  " << setw(17) << setiosflags(ios::left) << jog1->cartas[i] << "\t | \t" << setw(17) << setiosflags(ios::left) <<jog2->cartas[i] << endl;
            }
            else{
                cout << "\t \t          " << setw(17) << setiosflags(ios::left) << jog1->cartas[i] << "\t | \t" << setw(17) << setiosflags(ios::left) <<  jog2->cartas[i] << endl;
            }
        }
        else{
                if (i <jog1->jogada && i < jog2->jogada){
                    cout << "\t \t          " << setw(17) << setiosflags(ios::left) << jog1->cartas[i] << "\t | \t" << setw(17) << setiosflags(ios::left) <<  jog2->cartas[i] << endl;
                }
                else{
                        if ( i < jog1->jogada ){
                            cout << "\t \t          " << setw(17) << setiosflags(ios::left) << jog1->cartas[i] << "\t |" << endl;
                        }
                        else{
                            cout << "\t \t \t \t \t \t | \t" << setw(17) << setiosflags(ios::left) << jog2->cartas[i] << endl;
                        }
                }

        }
    }
    cout << "\t \t Soma: " << setw(4) <<setiosflags(ios::left) << "\t" << jog1->valor << " \t \t \t \t" << jog2->valor << endl;
}



void resultado_final(jogador * jog1, jogador * jog2){
    jogador * joglista[2];
    joglista[1] = jog1;
    joglista[2] = jog2;
    system("cls");
    cout << "\t \t \t Resultado Final do jogo" << endl;
    cout << "\t \t \t \tTabela" << endl;
    cout << "\t \t Nome  \t\t  Vit \tEmp \tDer" << endl;
    if (jog1->vit != jog2->vit){
        if (jog1->vit < jog2->vit){
            joglista[1] = jog2;
            joglista[2] = jog1;
        }
        cout << "\t \t " << setw(10) <<joglista[1]->nome << setw(3) << "\t" << joglista[1]->vit << "\t" << joglista[1]->emp << "\t" << joglista[1]->der << endl;
        cout << "\t \t " << setw(10) <<joglista[2]->nome << setw(3) << "\t" << joglista[2]->vit << "\t" << joglista[2]->emp << "\t" << joglista[2]->der << endl;
        cout << "\t \t Parabens!! " << joglista[1]->nome << " voce venceu o jogo" << endl;
    }
    else{
    cout << "\t \t " << setw(10) <<joglista[1]->nome << setw(3) << "\t" << joglista[1]->vit << "\t" << joglista[1]->emp << "\t" << joglista[1]->der << endl;
    cout << "\t \t " << setw(10) <<joglista[2]->nome << setw(3) << "\t" << joglista[2]->vit << "\t" << joglista[2]->emp << "\t" << joglista[2]->der << endl;
    cout << "\t \t  O jogo terminou empatado!!!" << endl;
    }
    cout << "\t \t Digite enter para continuar" << endl;
    cin.ignore(4,'\n');
    jogo(FIM);
    system("cls");
}

void jogo(Estado jogo){
    ofstream arq;
    arq.open(JOGO,ios::out);
    arq << jogo << endl;
}


void remove_arq(){
    int arq1,arq2, arq3;
    arq1 = remove(JOG_1);
    arq2 = remove(JOG_2);
    arq3 = remove(JOGO);
    if (arq1 != 0 && arq2 != 0 && arq3 != 0){
        cout << "/t/t/t" <<"Dados removidos com sucesso" << endl;
    }
}



