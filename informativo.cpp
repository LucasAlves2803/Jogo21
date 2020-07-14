void menu(){
    int op;
    do{


        cout << "\t \t \t   " <<"   * * *       ** " << endl;
        cout << "\t \t \t   " <<"  *     *     * * " << endl;
        cout << "\t \t \t   " <<"       *     *  * " << endl;
        cout << "\t \t \t   " <<"     *          * " << endl;
        cout << "\t \t \t   " <<"   *            * " << endl;
        cout << "\t \t \t   " <<" * * * *      * * *" << endl;


        cout << "\t \t Para jogar contra outra pessoa       - Digite 1" << endl;
        cout << "\t \t Para jogar contra o computador       - Digite 2" << endl;
        cout << "\t \t Para jogar computador vs computador  - Digite 3" << endl;
        cout << "\t \t Para ver as regras do jogo           - Digite 4" << endl;
        cout << "\t \t Para sair do jogo                    - Digite 5" << endl;
        op = opcao();
        cin.ignore();
        switch (op){
            case 1:
                iniciar_jogo(op);
                break;
            case 2:
                iniciar_jogo(op);
                break;
            case 3:
                iniciar_jogo(op);
                break;
            case 4:
                Regras_do_jogo();
                break;
            case 5:
                cout << "\t \t \t Fim" << endl;
                break;
        }
    }while(op != 5);
}


void Regras_do_jogo(){
    char op;
    cout <<"\t \t O jogo é para dois jogadores" << endl;
    cout <<"\t \t Pode ser pessoa vs pessoa" << endl;
    cout <<"\t \t Ou pessoa vs computador" << endl;
    cout <<"\t \t O jogo inicia distribuindo "<< endl;
    cout <<"\t \t duas cartas para ambos os jogadores" << endl;
    cout <<"\t \t Apos receber as duas primeiras cartas" << endl;
    cout <<"\t \t cada jogador deve decidir se quer receber" << endl;
    cout <<"\t \t mais alguma carta (so pode receber mais tres)" << endl;
    cout <<"\t \t A rodada acaba quando ambos jogadores decidem" << endl;
    cout <<"\t \t parar ou algum jogador superou 21, ou quando" << endl;
    cout <<"\t \t todas as cartas foram distribuidas." << endl;
    cout <<"\t \t O vencedor DA RODADA sera aquele tem o maior valor menor" << endl;
    cout <<"\t \t ou iqual a 21 quando ambos nao estouraram (superaram 21)" <<endl;
    cout <<"\t \t ou quando apenas um dos jogadores supera 21" << endl;
    cout <<"\t \t automaticamente o outro se torna o vencedor" << endl;
    cout <<"\t \t A rodada termina empatada quando ambos somam o" << endl;
    cout <<"\t \t mesmo valor menor ou igual a 21, ou quando" << endl;
    cout <<"\t \t ambos estouram(superam 21)" << endl;
    cout <<"\t \t O jogo tem 5 rodadas, o vencedor DO JOGO" << endl;
    cout <<"\t \t sera aquele que vencer mais rodadas," << endl;
    cout <<"\t \t caso os jogadores tenham o mesmo numero de" << endl;
    cout <<"\t \t o jogo termina empatado" << endl;
    cout <<"\t \t Para ver os valores das cartas - Digite crtl+f e Enter" << endl;
    cin >> op;
    if (op == 6){
            cout <<"\t \t \t \t |  face  | valor |" << endl;
        for (int i=0; i < 10; i++){
            cout <<"\t \t \t \t | " << setw(6) << setiosflags(ios::left) << face[i] << " |   " << setw(2) << i+1 << "  |" << endl;
        }
    }
    cout <<"\t \t Para voltar ao menu principal - Digite crtl+f e Enter" << endl;
    cin >> op;
}


int opcao(){
    int op;
    do{
        cout << "\t \t ";
        cin >> op;
        if (op < 1 || op > 5){
            cout << "\t \t Valor invalido" << endl;
            cout << "\t \t Digite um valor entre 1 e 5" << endl;
        }
    } while(op < 1 || op > 5);
    return op;
}

void Pag_inicial(){
    menu();
    remove_arq();
}



string nome(){
    string name;
    cout << "\t \t Digite seu nome:" << endl;
    cout << "\t \t ";
    getline(cin, name);
    return name;
}

