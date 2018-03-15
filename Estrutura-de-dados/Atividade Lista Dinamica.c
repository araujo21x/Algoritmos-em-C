#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    float salario;
    struct elemento* prox;
} Lista;

typedef Lista* lista;
int tamanho = 0;

void menu();
void inicializar(lista *l);
Lista* alocar();
void inserir(lista *l, float valor);/*Menu 1*/
void exibir(lista l);/*Menu 2*/
void MaiorQ(lista l);/*Menu 3*/
void remover(lista *l);/*Menu 4*/
void enderecoSalario(lista l);/*Menu 5*/
void QuantSalario(lista l);/*Menu 6*/
void ordenar(lista *l);/*Menu 7*/
void esvaziar (lista *l);/*Menu 8*/
void extremos(lista l);/*Menu 9*/

int main(){
    int opcao;
    float valor;

    lista l;

    inicializar(&l);

    while(opcao!=0){

        menu();

        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                system("cls");
                printf("\nInforme o valor que deseja adicionar:");
                scanf("%f", &valor);
                inserir(&l, valor);

            break;

            case 2:
                system("cls");
                exibir(l);
            break;

            case 3:
                system("cls");
                MaiorQ(l);
            break;

            case 4:
                system("cls");
                remover(&l);
            break;

            case 5:
                system("cls");
                enderecoSalario(l);
            break;

            case 6:
                system("cls");
                QuantSalario(l);
            break;

            case 7:
                system("cls");
                ordenar(&l);
            break;

            case 8:
                system("cls");
                esvaziar(&l);
            break;

            case 9:
                system("cls");
                extremos(l);
        }
    }

return 0;
}
void menu(){

    printf("----------------------------------------------------------------\n");
    printf("                             Menu\n");
    printf("----------------------------------------------------------------\n");
    printf("0 - Sair\n");
    printf("1 - INSERIR\n");
    printf("2 - EXIBIR A LISTA\n");
    printf("3 - CONTAR VALORES MAIORES QUE 'K'\n");
    printf("4 - REMOVER DO INiCIO\n");
    printf("5 - MOSTRAR O ENDEREÇO DE MEMORIA QUE CONTEM UM DETERMINADO SALARIO\n");
    printf("6 - CONTAR QUANTAS VEZES O SALARIO K APARECE NA LISTA\n");
    printf("7 - ORDENAR A LISTA DE FORMA DECRESCENTE\n");
    printf("8 - ESVAZIAR A FILA\n");
    printf("9 - MOSTRAR O MAIOR E O MENOR SALARIO DA LISTA\n");
    printf("----------------------------------------------------------------\n");
    printf("Digite sua opcao:\n");

}
void inicializar(lista *l){
    *l = NULL;
}
Lista* alocar(){
    lista novo;
    novo = (lista)malloc(sizeof(Lista));
    return(novo);

}
void inserir(lista *l, float valor){/*Menu 1*/
    lista auxiliar, novo;

    novo = alocar();
    if( novo == NULL){
        printf("Erro - Vazio");
    }
    novo->salario = valor;
    novo->prox = *l;
    *l = novo;

    tamanho++;
    system("cls");
}
void exibir(lista l){/*Menu 2*/
    lista auxiliar = l;

    printf("Valores\n");

    while(auxiliar != NULL){
        printf("%.2f\n", auxiliar->salario);
        auxiliar = auxiliar->prox;
    }
    system("pause");
    system("cls");
}
void MaiorQ(lista l){/*Menu 3*/
    float valor;
    int x=0;

    printf("Informe o valor de 'k':");
    scanf("%f", &valor);

    lista auxiliar = l;

    while(auxiliar != NULL){
        if(auxiliar->salario > valor){
            x++;
        }
        auxiliar = auxiliar->prox;
    }
    printf("existe %d valores maiores que 'k'\n", x);

    system("pause");
    system("cls");
}
void remover(lista *l){/*Menu 4*/
    lista deleta;

    if(*l == NULL){
        printf("Erro - vazia");
    }

    deleta = *l;
    *l = deleta->prox;

    free(deleta);

    printf("removido com sucesso!\n");

    system("pause");
    system("cls");
}
void enderecoSalario(lista l){/*Menu 5*/
    float valor;
    lista auxiliar = l;

    printf("Salario que deseja verificar:");
    scanf("%f", &valor);

    while(auxiliar != NULL){
        if(auxiliar->salario == valor){
            printf("%d\n", &auxiliar->salario);
        }
        auxiliar = auxiliar->prox;
    }
    system("pause");
    system("cls");
}
void QuantSalario(lista l){/*Menu 6*/
    float valor;
    int cont = 0;
    lista auxiliar = l;

    printf("Qual Salario:");
    scanf("%f", &valor);

    while(auxiliar != NULL){
        if(auxiliar->salario == valor){
            cont++;
        }
        auxiliar = auxiliar->prox;
    }
    printf("%.2f apareceu: %d\n", valor, cont);
    system("pause");
    system("cls");
}
void ordenar(lista *l){/*Menu 7*/
    float aux;
    lista ordernar, auxiliar = *l;

    while(auxiliar != NULL){
        ordernar = auxiliar->prox;
        while(ordernar != NULL){
            if(auxiliar->salario > ordernar->salario){
                aux = auxiliar->salario;
                auxiliar->salario = ordernar->salario;
                ordernar->salario = aux;
            }
            ordernar = ordernar->prox;
        }
        auxiliar = auxiliar->prox;
    }
}
void esvaziar (lista *l){/*Menu 8*/
    lista deleta;

    if(*l == NULL){
        printf("Erro - Vazia");
    }

    while(*l != NULL){
        deleta = *l;
        *l = deleta->prox;
        free(deleta);
    }

    printf("Esvaziada com sucesso!\n");

    system("pause");
    system("cls");
}
void extremos(lista l){
    float maior = 0, menor = 0;
    int cont = 0;
    lista auxiliar = l;

    while(auxiliar != NULL){

        if(cont == 0){
            menor = auxiliar->salario;
        }else if(auxiliar->salario < menor){
            menor = auxiliar->salario;
        }

        if(auxiliar->salario > maior){
            maior = auxiliar->salario;
            cont++;
        }
        auxiliar = auxiliar->prox;
    }

    printf("Maior:%.2f\nMenor:%.2f\n", maior, menor);

    system("pause");
    system("cls");

}

