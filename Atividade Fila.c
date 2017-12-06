#include <stdio.h>
#include <stdlib.h>
#define tamanho 4

typedef struct{
    int inicio, fim;
    int matricula[tamanho];
    float nota_trab[tamanho];
    float nota_prova[tamanho];
    float media[tamanho];
}fila;

void iniciar(fila *f);
void falsocheio(fila *f);
void media(fila *f);
void inserir(fila *f);//Menu 1
void excluir(fila *f);//Menu 2
void exibir(fila *f);//Menu 3
void maior_nota(fila *f);//Menu 4
void primeiro_elemento(fila *f);//Menu 5
void menu();

int main(){

    menu();

return 0;
}
void iniciar(fila *f){
    f->inicio=0;
    f->fim=-1;
}
void falsocheio(fila *f){
    int auxInicio=f->inicio, auxFim=f->fim, i;

    if(f->fim == tamanho-1 && f->inicio != 0){
        f->fim = -1;
        f->inicio = 0;
        for(i = auxInicio; i <= auxFim; i++){
            f->fim++;
            f->matricula[f->fim] = f->matricula[i];
            f->nota_trab[f->fim] = f->nota_trab[i];
            f->nota_prova[f->fim] = f->nota_prova[i];
            f->media[f->fim] = f->media[i];
        }
    }

}
void media(fila *f){
    int i;

    for(i = f->inicio; i <= f->fim; i++){
        f->media[i] = (f->nota_prova[i] + f->nota_trab[i])/2;
    }
}
void inserir(fila *f){//Menu 1


    if(f->fim == tamanho-1){
        printf("=============1 - Inserir=============\n\n");
        printf("Erro - Fila Cheia\n");
    }else{
        f->fim++;

        printf("=============1 - Inserir=============\n\n");
        printf("Informe a matricula do aluno:");
        scanf("%d", &f->matricula[f->fim]);
        printf("Informe a nota do trabalho:");
        scanf("%f", &f->nota_trab[f->fim]);
        printf("Informe a nota da prova:");
        scanf("%f", &f->nota_prova[f->fim]);
        printf("\nInserido com Sucesso\n");
    }
    system("pause");
    system("cls");
}
void excluir(fila *f){// Menu 2
    if(f->fim < f->inicio){
        printf("=============2 - Excluir=============\n\n");
        printf("Erro - Fila vazia\n");
    }else{
        f->inicio++;
        printf("=============2 - Excluir=============\n\n");
        printf("Removido com Sucesso\n");
    }
    system("pause");
    system("cls");
}
void exibir(fila *f){// menu 3
    int i,j;

    printf("=====================================3 - exibir=====================================\n\n");
    printf("Matricula\tNota trabalho\tNota prova\tMedia\tResultado\n");
    for(i = f->inicio; i <= f->fim; i++){

        if(f->media[i] >= 7){
            printf("%d\t\t", f->matricula[i]);
            printf("%.2f\t\t", f->nota_trab[i]);
            printf("%.2f\t\t", f->nota_prova[i]);
            printf("%.2f \t", f->media[i]);
            printf("Aprovado\n");
        }else {
            printf("%d\t\t", f->matricula[i]);
            printf("%.2f\t\t", f->nota_trab[i]);
            printf("%.2f\t\t", f->nota_prova[i]);
            printf("%.2f \t", f->media[i]);
            printf("Reprovado\n");
        }
    }
    system("pause");
    system("cls");
}
void maior_nota(fila *f){//Menu 4
    int i, j;
    int maior = f->media[f->inicio];

    for(i = f->inicio; i <= f->fim; i++){
        if(f->media[i] > maior){
            maior = f->media[i];
        }
    }
    printf("Matricula\tNota trabalho\tNota prova\tMedia\n");
    for(i = f->inicio; i <= f->fim; i++){
        if( maior == f->media[i]){
            printf("%d\t\t", f->matricula[i]);
            printf("%.2f\t\t", f->nota_trab[i]);
            printf("%.2f\t\t", f->nota_prova[i]);
            printf("%.2f \t\t\n", f->media[i]);
        }
    }
    system("pause");
    system("cls");
}
void primeiro_elemento(fila *f){//Menu 5
    printf("====================5 - Primeiro elemento====================\n\n");
    printf("Matricula\tNota trabalho\tNota prova\tMedia\tResultado\n");

    if(f->media[f->inicio] >= 7){
        printf("%d\t\t", f->matricula[f->inicio]);
        printf("%.2f\t\t", f->nota_trab[f->inicio]);
        printf("%.2f\t\t", f->nota_prova[f->inicio]);
        printf("%.2f \t", f->media[f->inicio]);
        printf("Aprovado\n");
    }else {
        printf("%d\t\t", f->matricula[f->inicio]);
        printf("%.2f\t\t", f->nota_trab[f->inicio]);
        printf("%.2f\t\t", f->nota_prova[f->inicio]);
        printf("%.2f \t", f->media[f->inicio]);
        printf("Reprovado\n");
    }

    system("pause");
    system("cls");
}
void menu(){
    int menu;

    fila f;
    iniciar(&f);

    while(menu != 0){
        printf("============Menu============\n\n");
        printf("0 - Sair\n");
        printf("1 - Inserir na fila\n");
        printf("2 - Excluir da fila\n");
        printf("3 - Exibir\n");
        printf("4 - Aluno com maior nota\n");
        printf("5 - Primeiro elemento\n");
        printf("Digite sua opcao:");
        scanf("%d", &menu);

        media(&f);
        system("cls");

        switch(menu){
            case 1:
                falsocheio(&f);
                inserir(&f);
            break;

            case 2:
                excluir(&f);
            break;

            case 3:
                exibir(&f);
            break;

            case 4:
                maior_nota(&f);
            break;

            case 5:
                primeiro_elemento(&f);
            break;
        }
    }
}
