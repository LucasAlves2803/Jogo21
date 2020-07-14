#include "dados.hpp"
#include "impressoes.hpp"
#include "impressoes.cpp"

void teste (jogador *, jogador *);

int le_arquivo(jogador *jog, string nome){
    string tam;
    int num;
    ifstream arq;
	arq.open(nome.c_str(), ios::in); // usar define como constante
	if (!arq){
		cout << "O arquivo nao pode ser aberto" << endl;
        return 0;
	}
	else{
        getline(arq,jog->nome);
        getline(arq,tam);
        num = atoi(tam.c_str());
        jog->jogada = num;
        int i =0;
		while(i < num){
            string str;
            getline(arq,str);
            strcpy(jog->cartas[i],str.c_str());
            i++;
        }
        arq >> jog->valor;
        arq.close();
        return 1;
	} 
}

int estado_jogo(){
    ifstream arq;
    arq.open("jogo.txt", ios::in);
    int num;
    arq >> num;
    return num;
}

int main(){
        string arq1 = "jog1.txt";
        string arq2 = "jog2.txt";
        cout << "Ola mundo" << endl;
        jogador jog1, jog2;
        while(estado_jogo()){
            system("cls");
            if (le_arquivo(&jog1,arq1) && le_arquivo(&jog2,arq2)){
                impressao(&jog1,&jog2);
            }
            Sleep(1000);
        }
    return 0;
}
