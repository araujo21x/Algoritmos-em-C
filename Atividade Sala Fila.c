#include <stdio.h>
#include <stdlib.h>
#define tamanho 4

typedef struct{
    int inicio, fim;
    int valor[tamanho];
}fila;

int menu();
void iniciar(fila *f);
void falsocheio(fila *f);
void inserir(fila *f);//Menu 1
void remover(fila *f);//Menu 2
void exibirInicio(fila *f);//Menu 3
void exibir(fila *f);//Menu 4

int main(){
    menu();

}
void iniciar(fila *f){
    f->inicio = 0;
    f->fim = -1;
}
void falsocheio(fila *f){
    int auxInicio=f->inicio, auxFim=f->fim, i;

    if(f->fim == tamanho-1 && f->inicio != 0){
        f->fim = -1;
        f->inicio = 0;
        for(i = auxInicio; i <= auxFim; i++){
            f->fim++;
            f->valor[f->fim] = f->valor[i];

        }
    }

}
void inserir(fila *f){//Menu 1

    if(f->fim == tamanho-1){
        printf("=============1 - Inserir=============\n\n");
        printf("Fila Cheia\n");
    }else{
        f->fim++;
        printf("=============1 - Inserir=============\n\n");
        printf("informe valor:");
        scanf("%d", &f->valor[f->fim]);
        printf("Inserido com Sucesso\n");
    }
    system("pause");
    system("cls");
}
void remover(fila *f){//Menu 2

    if(f->fim < f->inicio){
        printf("=============2 - Remover=============\n\n");
        printf("Erro: Fila Vazia\n");
    }else{
        f->inicio++;
        printf("=============2 - Remover=============\n\n");
        printf("Removido com Sucesso\n");
    }
    system("pause");
    system("cls");
}
void exibirInicio(fila *f){//Menu 3
    printf("=============3 - Exibir Inicio=============\n\n");
    printf("%d\n", f->valor[f->inicio]);
    system("pause");
    system("cls");
}
void exibir(fila *f){//Menu 4
    int i;

    printf("=============4 - Exibir=============\n\n");
    for(i = f->inicio; i <= f->fim; i++){
        printf("Valor: %d\n", f->valor[i]);
    }
    system("pause");
    system("cls");
}
int menu(){
    int menu;

    fila f;
    iniciar(&f);

    while(menu != 6){

        printf("=============Menu=============\n\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - exibir inicio\n");
        printf("4 - Exibir\n");
        printf("5 - Esvaziar fila\n");
        printf("6 - Sair\n");
        printf("Digite sua opcao:");
        falsocheio(&f);
        scanf("%d", &menu);

        system("cls");

        switch(menu){
            case 1:
                inserir(&f);
            break;

            case 2:
                remover(&f);
            break;

            case 3:
                exibirInicio(&f);
            break;

            case 4:
                exibir(&f);
            break;

            case 5:
                iniciar(&f);
            break;
        }
    }

return 0;
}
