#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Funcao que gera um numero aleatorio entre 0 e 10.*/
int Numero_Aleatorio(){
    int n;
    srand((unsigned)time(NULL));
    n = rand()%11;
    return n;
}
/*Funcao que confere se dois numeros sao igual.
  Retorna 1 se forem iguais e 0 caso contrario.*/
int Igual(int a, int b){
    if(a == b) return 1;
    return 0;
}
/*Funcao que mostra as opcoes de jogo.
  Se o usuario deseja jogar ou sair.
  Retorna o numero da opcao escolhida.*/
int Opcao(){
    int i;
    printf("\n\033[1m1- Jogar\n2- Sair\033[m\n");
    scanf("%d", &i);
    return i;
}
/*Funcao que printa o nome do jogo.*/
void Comeco(){
    printf("\t\t\033[1;35m###### ADIVINHACAO #######\033[m\n");
}
/*Funcao que printa uma sequencia de asteriscos.*/
void Asterisco(int n){
    int i;
    char a;
    a = '*';
    for(i=0; i<n; i++) printf("\033[1;33m%c\033[m",a);
    printf("\n");
}
/*Funcao que printa o resultado final do jogo.*/
void Resultado(int acertos, int erros){
    printf("\n\033[1;32mVOCE ACERTOU:\033[m %d\n\033[1;31mVOCE ERROU: \033[m%d\n", acertos, erros);
}
/*Funcao principal que faz tudo funcionar.*/
int main(){
    int numero, sorteado, estado;
    int acertos = 0, erros = 0;
    Asterisco(100);
    Comeco();
    estado = Opcao();
    while(estado != 2){
        sorteado = Numero_Aleatorio();
        printf("\n\033[1mAdivinhe o numero de 0 a 10: \033[m");
        scanf("%d", &numero);
        if(Igual(sorteado, numero)){
            printf("\n\033[1;32m****** VOCE ACERTOU !!! ******\033[m\n");
            acertos++;
        }
        else{
            printf("\n\033[1;31m****** VOCE ERROU !!! ******\033[m\n");
            printf("\n\033[1mO numero era: %d\033[m\n", sorteado);
            erros++;
        }
        estado = Opcao();
    }
    Resultado(acertos, erros);
    Asterisco(100);
    return 0;
}

