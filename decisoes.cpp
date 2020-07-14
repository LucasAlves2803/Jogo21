#include "decisoes.hpp"

int decisao(string nome){
    int op;
    do {
    cout << nome <<", deseja pegar mais uma carta?" << endl;
    cout << "Se sim -> Digite 1" << endl;
    cout << "Se nao -> Digite 2" << endl;
    cin >> op;
    if (op != 1 && op != 2){
        cout << "Digite somente 1 ou 2" << endl;
    }
    } while( op != 1 && op != 2);
    return op;
}




void computador(int* op,int* x, int* y){
    if (*x < *y && *y == 21){
        *op = 1;
    }
    else{
        if (*x <= 11){
            arvore_decisao1(op,x,y);
        }
        else if( *x <= 15){
            arvore_decisao2(op,x,y);
        }
        else {
            arvore_decisao3(op,x,y);
        }
    }

}

void arvore_decisao1(int * op, int * x, int * y){
    int aleat;
    aleat = rand() % 10;
    if (*x > *y){
        if (aleat < 9){  // ->->-> probabilidade muito alta de pedir carta
            *op = 1;
        }
        else{
            *op = 0;
        }
    }
    else{
        if (*x < 5){
            if (aleat < 9){  // ->->-> probabilidade muito alta de pedir carta
                *op = 1;
            }
            else{
                *op = 0;
            }
        }
        else if ( *x < 7){
            if (aleat < 5){  // ->-> probabilidade media de pedir a carta
                *op = 1;
            }
            else{
                *op = 0;
            }
        }
        else{
           if (aleat < 9){  // ->->-> probabilidade muito alta de pedir carta
                *op = 1;
            }
            else{
                *op = 0;
            }
        }
    }
}

void arvore_decisao2(int* op,int * x, int * y){
    int aleat;
    aleat = rand() % 10;
    if (*x > *y){ // soma maior que a do adversário
        if ( *x <= 13){
            if (aleat < 7){ // ->-> probabilidade alta de pedir a carta
                *op = 1;
            }
            else{
                op = 0;
            }
        }
        else{
            if (aleat < 5){  // [] probabilidade media de pedir a carta
                *op = 1;
            }
            else{
                *op = 0;
            }
        }
    }
    else{ // soma menor ou igual que a do adversario
        if ( *x <= 13){
            if (aleat < 9){ // ->->-> probabilidade muito alta de pedir a carta
                *op = 1;
            }
            else{
                op = 0;
            }
        }
        else{  // 13 < x <= 15
            if (aleat < 7){  // ->-> probabilidade media de pedir a carta
                *op = 1;
            }
            else{
                *op = 0;
            }
        }
    }
}
void arvore_decisao3(int * op,int * x, int * y){
    int aleat;
    aleat = rand() % 10;
    if (*x > *y){
        if (*x < 18){
            if (aleat < 5){  // <-<- probabilidade media de pedir a carta
                *op = 1;
            }
            else{
                *op = 0;
            }
        }
        else if( *x < 19){
            if (aleat < 7){  // <-<- probabilidade alta de não pedir a carta
                *op = 0;
            }
            else{
                *op = 1;
            }
        }
        else{
            if (aleat < 9){ // <-<-<- probabilidade muito alta de nao pedir a carta
                *op = 0;
            }
            else{
                *op = 1;
            }
        }
    }
    else{
        if (*x < 18){
            if (aleat < 6){  // ->->-> probabilidade um pouco alta de pedir carta
                *op = 1;
            }
            else{
               *op = 0;
            }
        }
        else if(*x < 19){
            if (aleat < 5){  // [] probabilidade media de pedir a carta
                *op = 1;
            }
            else{
                *op = 0;
            }
        }
        else{
            if (aleat < 9){ // ->->-> probabilidade muito alta de pedir a carta
                *op = 1;
            }
            else{
                *op = 0;
            }
        }
    }
}
