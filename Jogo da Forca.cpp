# include <iostream>
# include <stdlib.h>
# include <string.h>
# include <fstream>

using namespace std;

const int quantPalavras = 20;
const int tamPalavra = 15;
char palavraSORT[tamPalavra];
int categoria, categoria2 = 0, qntLetras;
string nomeCategoria;

char banco_palavras[quantPalavras][tamPalavra];

void bancoPalavras(int categoria){

    ifstream arquivo;

    switch(categoria){
        case 1:
            arquivo.open("Cores.txt");
            nomeCategoria = "CORES";
            break;
        case 2:
            arquivo.open("Frutas.txt");
            nomeCategoria = "FRUTAS";
            break;
        case 3:
            arquivo.open("Nomes.txt");
            nomeCategoria = "NOMES DE PESSOAS";
            break;
    }

    string line;
    int cont = 0;
    char palavraTEMP[10];

    if (arquivo.is_open()){
        while (getline(arquivo,line)){
            strcpy(palavraTEMP, line.c_str());
            if((strlen(palavraTEMP)) == 0) continue;
            for(int i = 0; i < strlen(palavraTEMP); i++){
                banco_palavras[cont][i] = palavraTEMP[i];
            }
            cont++;
        }
        arquivo.close();
    } else{
        bancoPalavras(categoria);
    }

}

void imprimirFOR(int acertos, int erros, int qntLetras){
    cout << "\n\n\t\t\t   JOGO DA FORCA\n\n";
    cout << "\t\tACERTOS: " << acertos << "\t\t ERROS: " << erros << "\n\n";
    cout << "\t\tCATEGORIA: " << nomeCategoria << "\n\n";
    cout << "\t\t" << qntLetras << " LETRAS\n\n";

    switch(erros){
        case 0:
            cout<<"\t\t ________   \n";
            cout<<"\t\t|           \n";
            cout<<"\t\t|           \n";
            cout<<"\t\t|           \n";
            cout<<"\t\t|           \n";
            cout<<"            \n";
            break;
        case 1:
            cout<<"\t\t ________   \n";
            cout<<"\t\t|        0  \n";
            cout<<"\t\t|           \n";
            cout<<"\t\t|           \n";
            cout<<"\t\t|           \n";
            cout<<"            \n";
            break;
        case 2:
            cout<<"\t\t ________   \n";
            cout<<"\t\t|        O  \n";
            cout<<"\t\t|       /|\\\n";
            cout<<"\t\t|           \n";
            cout<<"\t\t|           \n";
            cout<<"            \n";
            break;
        case 3:
            cout<<"\t\t ________   \n";
            cout<<"\t\t|        O  \n";
            cout<<"\t\t|       /|\\\n";
            cout<<"\t\t|         \\\n";
            cout<<"\t\t|           \n";
            cout<<"            \n";
            break;
        case 4:
            cout<<"\t\t ________   \n";
            cout<<"\t\t|        O  \n";
            cout<<"\t\t|       /|\\\n";
            cout<<"\t\t|       / \\\n";
            cout<<"\t\t|           \n";
            cout<<"            \n";
            break;
        case 5:
            cout<<"\t\t ________   \n";
            cout<<"\t\t|           \n";
            cout<<"\t\t|           \n";
            cout<<"\t\t|    + RIP +\n";
            cout<<"\t\t|           \n";
            cout<<"            \n";
            break;
    }
}


void preencherPalavra(char palavraSORT[], int indice){
    for(int i = 0; i < tamPalavra; i++) palavraSORT[i] = banco_palavras[indice-1][i];
}

void imprimirPD(char palavraDIGIT[]){
    cout << "\n\n\t\t";
    for(int i = 0; i < strlen(palavraSORT); i++) cout << palavraDIGIT[i] << " ";
    cout << endl << endl;
}

void construtor(){
    cout << "\n\n\t\t\t   JOGO DA FORCA\n\n";
    cout << "\n\n\t\t.:: CATEGORIAS ::.\n\n\t\t1 - CORES\n\t\t2 - FRUTAS\n\t\t3 - NOMES DE PESSOAS\n\n";
    cout << "\n\n\t\tESCOLHER: ";
    cin >> categoria;
    if(categoria != categoria2) bancoPalavras(categoria);
}

int main(){
    construtor();

    preencherPalavra(palavraSORT, rand() % quantPalavras);

    if((strlen(palavraSORT) == 0)) system("cls"), main();

    char palavraDIGIT[tamPalavra];

    qntLetras = strlen(palavraSORT);

    for(int i = 0; i < strlen(palavraSORT); i++) palavraDIGIT[i] = '_';

    int cont_erros = 0, cont_acertos = 0;
    system("cls");

    char letra;

    while(cont_erros < 5){

        bool ativador = false;

        imprimirFOR(cont_acertos, cont_erros, qntLetras);
        imprimirPD(palavraDIGIT);

        cout << endl << "\t\tDIGITE UMA LETRA: ";
        cin >> letra;

        letra = toupper(letra);

        for(int i = 0; i < strlen(palavraSORT); i++){
            if (letra == palavraSORT[i]){
                if(letra != palavraDIGIT[i]) cont_acertos++;
                palavraDIGIT[i] = letra;

                ativador = true;
            }
        }

        if(!ativador){
            cout << "\n\t\tLETRA ERRADA\n\n";
            cont_erros++;
            system("pause");
        }

        if(cont_acertos == strlen(palavraSORT)) break;

        system("cls");
    }
    system("cls");

    imprimirFOR(cont_acertos, cont_erros, qntLetras);
    imprimirPD(palavraDIGIT);

    if(cont_erros == 5){
        cout << "\n\n\n\t\tPERDESTES!\n\n";
    } else{
        cout << "\n\n\n\t\tVENCESTES!\n\n";
    }

    system("pause");
    system("cls");

    char jogarNov;

    cout << "\n\n\t\tJOGAR NOVAMENTE (s/n)? ";
    cin >> jogarNov;

    if(jogarNov == 's'){
        system("cls");
        categoria2 = categoria;
        main();
    }

    return 0;
}
