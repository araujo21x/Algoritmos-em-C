#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Elemento{/*os dados da fila*/
    int info;
    struct Elemento* proximo;
}elemento;

typedef struct{/*como se fosse a verdadeira struct*/
    elemento* inicio;
    elemento* fim;
}fila;

fila f;/*nomeando a struct, igual fazia antigamente mas uma global*/

void menu();
void inicializar(fila *f);
bool inserir(fila *f);/*Menu 1*/
void exibir(fila *f);/*Menu 2*/
void remover(fila *f);/*Menu 3*/
void esvaziar(fila *f);/*Menu 4*/
void media(fila *f);/*Menu 5*/
void pares(fila *f);/*Menu 6*/
void vezes(fila *f);/*Menu 7*/
void duplicar(fila *f);/*Menu 8*/

int main(){
    int opcao;

    inicializar(&f);

    while(opcao!= 0){

        menu();
        printf("Digite sua opcao:\n");
        scanf("%d", &opcao);
        system("cls");

        switch (opcao){
            case 1:
                inserir(&f);
            break;

            case 2:
                exibir(&f);
            break;

            case 3:
                remover(&f);
            break;

            case 4:
                esvaziar(&f);
            break;

            case 5:
                media(&f);
            break;

            case 6:
                pares(&f);
            break;

            case 7:
                vezes(&f);
            break;

            case 8:
                duplicar(&f);
            break;
        }
    }

return 0;
}
void menu(){

    printf("------------------------------------------------------------------------------------------------------\n");
    printf("                             Menu\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    printf("0 - SAIR;\n");
    printf("1 - INSERIR NO FINAL;\n");
    printf("2 - EXIBIR A FILA;\n");
    printf("3 - REMOVER DO INICIO;\n");
    printf("4 - ESVAZIAR A FILA;\n");
    printf("5 - MOSTAR O VALOR MEDIO DA FILA;\n");
    printf("6 - MOSTRAR OS VALORES PARES DA FILA;\n");
    printf("7 - CONTAR QUANTAS VEZES O VALOR K APARECE NA FILA;\n");
    printf("8 - CRIAR UMA FILA f2 E PREENCHER COM OS VALORES DA FILA f NA ORDEM INVERSA (DO FIM AO INICIO).\n");
    printf("------------------------------------------------------------------------------------------------------\n");

}
void inicializar(fila *f){/*inicializei estou falando que o valor e nulo e nao apontando para lixo*/
    f->inicio = NULL;
    f->fim = NULL;
}
bool inserir(fila *f){/*Menu 1*/
    int valor;/*o valor que vou adicionar no ponteiro no caso em "info"*/
    elemento *novo;/*como se fosse uma variavel que vai ser o novo "no" ou "elemento"*/

    novo = malloc(sizeof(elemento));/*configurando o espa�o do ponteiro para o mesmo que o de elemento*/
    printf("                             1 - INSERIR NO FINAL\n");
    printf("Valor que deseja adicionar:");
    scanf("%d", &valor);

    if(novo == NULL){
        return false;
    }
    novo->info = valor;
    novo->proximo = NULL;/*como � o ultimo valor adicionado ele esta ligando para null pois o ultimo sempre tem que apontar para null*/

    if (f->inicio == NULL){
    /*se meu inicio for nullo significa que nao tem nenhum valor entao meu inicio vai receber valor do "novo"*/
        f->inicio = novo;
    }else{
        /*vai colocar o novo como ultimo*/
        f->fim->proximo = novo;
    }
    f->fim = novo;

    system("cls");

    return true;
}
void exibir(fila *f){/*Menu 2*/
    elemento *valores;

    valores = f->inicio;

    if(f->inicio == NULL){
        printf("Erro - Fila Vazia\n\n");
    }else{
        printf("                             2 - EXIBIR A FILA\n\n");

        while (valores != NULL){
            printf("%d\n", valores->info);
            valores = valores->proximo;
        }
    }
    system("pause");
    system("cls");
}
void remover(fila *f){/*Menu 3*/
    elemento *remover;

    if(f->inicio == NULL){
        printf("Erro - Fila Vazia");
    }

    remover = f->inicio;
    f->inicio = remover->proximo;

    if(f->inicio == NULL){
        f->fim = NULL;
    }
    free(remover);
    printf("Removido com Sucesso.");
}
void esvaziar(fila *f){/*Menu 4*/
    elemento *elementoDel, *proximoEleme;

    if(!f->inicio == NULL){
        proximoEleme = f->inicio;
        while (proximoEleme != NULL){
            elementoDel = proximoEleme;
            proximoEleme = proximoEleme->proximo;
            free(elementoDel);
        }
    }
    printf("Esvaziada com Sucesso");
    inicializar(f);
    system("pause");
    system("cls");
}
void media(fila *f){/*Menu 5*/
    int cont = 0, media = 0, resultado;
    elemento *valores;

    valores = f->inicio;

    if(f->inicio == NULL){
        printf("Erro - Fila Vazia");
    }else{
        while(valores != NULL){
            media = media + valores->info;
            valores = valores->proximo;
            cont++;
        }
    }
    resultado = media/cont;
    printf("Media = %d\n", resultado);

    system("pause");
    system("cls");

}
void pares(fila *f){/*Menu 6*/
    elemento *valores;

    valores = f->inicio;
    if(f->inicio == NULL){
        printf("Erro - Fila Vazia\n");
    }else{
        while(valores != NULL){
            if(valores->info % 2 == 0){
                printf("%d\n", valores->info);
            }
            valores = valores->proximo;
        }
    }
    system("pause");
}
void vezes(fila *f){/*Menu 7*/
    int cont = 0, conferir;
    elemento *valores;

    printf("Informe o k(valor):");
    scanf("%d", &conferir);

    valores = f->inicio;
    while(valores != NULL){
        if(valores->info == conferir){
            cont++;
        }
        valores = valores->proximo;
    }

    printf("%d\n", cont);
    system("pause");
}
void duplicar(fila *f){/*Menu 8*/
}
