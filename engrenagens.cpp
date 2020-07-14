

void iniciar_jogo(int op){
    jogador jog1,jog2;
    inicializa(op,&jog1,&jog2);
    bool teste = true;
    for(int rod=0; rod < 3; rod++){
        limpa_info(rod,&jog1,&jog2);
        gravacao(&jog1);
        gravacao(&jog2);
        if (teste){
            system("start leitura.exe");
            teste = false;
        }
        for (int i=0; i < 2; i++){
            associa(&jog1);
            gravacao(&jog1);
            associa(&jog2);
            gravacao(&jog2);
        }
        continuidade(rod,&jog1,&jog2);
        imprime_resultado(rod,&jog1,&jog2);
    }
    resultado_final(&jog1,&jog2);
    // excluir arquivos
}


void inicializa(int op,jogador * jog1, jogador * jog2){
    system("cls");
    if (op == 1){
        jog1->tipo_de_jogador = HU;
        jog2->tipo_de_jogador = HU;

    }
    else if (op == 2){
        jog1->tipo_de_jogador = HU;
        jog2->tipo_de_jogador = COMP;

    }
    else{
        jog1->tipo_de_jogador = COMP;
        jog2->tipo_de_jogador = COMP;

    }
    cout << "\t \t Jogador 1" << endl;
    if (jog1->tipo_de_jogador == HU){
        jog1->nome = nome();
    }
    else{
        jog1->nome = "COMP 1";
    }
    jog1->playn = JOG1;
    cout << "\t \t Jogador 2" << endl;
    if (jog2->tipo_de_jogador == HU){
        jog2->nome = nome();
    }
    else{
        jog2->nome = "COMP 2";
    }
    jog2->playn = JOG2;
    system("cls");
    jog1->vit = 0;
    jog1->emp = 0;
    jog1->der = 0;
    jog2->vit = 0;
    jog2->emp = 0;
    jog2->der = 0;
    srand((unsigned) time(0));
    jogo(INICIO);
}


void associa(jogador * jog1 ){
    int naipe1,face1;
    char nome[25];
    do{
        naipe1 = rand() % 4;
        face1 = rand() % 10;
    }while(baralho[naipe1][face1] == -1);
    baralho[naipe1][face1] = -1;
    strcpy(nome,face[face1]);
    strcat(nome," de ");
    strcat(nome,naipe[naipe1]);
    strcpy(jog1->cartas[jog1->jogada++],nome);
    jog1->valor += face1+1;
    imprime_carta(jog1->nome,jog1->jogada,jog1->cartas[jog1->jogada-1]);
}


void continuidade(int rod,jogador * jog1, jogador * jog2){
    int cont,op1,op2;
    cont =0;
    system("cls");
    do {
        cout << "\t\t\t  " << cont+3 << "o. jogada da " << rod+1 << "o. rodada" << endl;
        Sleep(1000);
        system("cls");
        if(jog1->valor < 21){

            system("cls");
            if (jog1->tipo_de_jogador == HU){
                cout << "\t\t\tVez do(a) " << jog1->nome << endl;
                Sleep(1000);
                impressao(jog1,jog2);
                op1 = decisao(jog1->nome);
            }
            else{
                computador(&op1,&jog1->valor,&jog2->valor);
                mensagem(jog1->nome,&op1);
            }
            system("cls");
        }
        else{
            op1 =0;
        }

        if(jog2->valor < 21){
            cout << "\t\t\tVez do(a) " << jog2->nome << endl;
            Sleep(2000);
            system("cls");
            if (jog2->tipo_de_jogador == HU){
                cout << "\t\t\tVez do(a) " << jog2->nome << endl;
                Sleep(1000);
                impressao(jog1,jog2);
                op2 = decisao(jog2->nome);
            }
            else{
                computador(&op2,&jog2->valor,&jog1->valor);
                mensagem(jog2->nome,&op2);
            }
            system("cls");
        }
        else{
            op2=0;
        }
        // limpatela
        if ( op1 == 1 || op2 == 1){
            cont++;
            if (op1 == 1){
                associa(jog1);
                gravacao(jog1);
            }
            if (op2 == 1){
                associa(jog2);
                gravacao(jog2);
            }
            system("cls");
        }
        else{
            break;
        }
    }while(cont < 3 && ((jog1->valor != 21 || jog2->valor != 21) && (jog1->valor <= 21  && jog2->valor <= 21)) );
}




void limpa_info(int rodada,jogador * jog1, jogador * jog2){

    embaralhando(rodada);
    for(int i=0; i < 4 ; i++){
        for (int j=0; j < 10; j++){
            baralho[i][j] = 0;
        }
    }
    for (int i=0; i < 5; i++){
        strcpy( jog1->cartas[i],"");
        strcpy( jog2->cartas[i],"");
    }
    jog1->valor = 0;
    jog1->jogada = 0;
    jog2->valor = 0;
    jog2->jogada = 0;
}
