#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;

void le_arquivo(){
	string nome;
    int num,valor;
    string tam;
    string carta[5];
    ifstream arq;
	arq.open("jog1.txt", ios::in); // usar define como constante
	if (!arq){
		cout << "O arquivo nao pode ser aberto" << endl;
	}
	else{
        getline(arq,nome);
        getline(arq,tam);
        num = atoi(tam.c_str());
        cout << "Nome: " << nome << endl;
        int i =0;
		while(i < num){
            getline(arq,carta[i]);
            cout << "Carta: " << carta[i] << endl;
            i++;
        }
        arq >> valor;
        cout << "Soma : " << valor << endl;
	}
	arq.close();
}

int estado_jogo(){
    ifstream arq;
    arq.open("jogo.txt", ios::in);
    int num;
    arq >> num;
    return num;
}

int principal(){
        while(estado_jogo()){
        system("cls");
        le_arquivo();
        }
    return 0;
}
