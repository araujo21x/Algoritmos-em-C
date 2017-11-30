#include <stdio.h>
#include <stdlib.h>
#define tamanho 4

typedef struct {
    int topo;
    float nota[tamanho];
}pilha;

int menu();
void iniciar(pilha *p);
void empilhar(pilha *p);//Menu 1
void desempilhar(pilha *p);//Menu 2
void exibir(pilha *p);//Menu 3
void localizarNota(pilha *p);//Menu 4
void localizarNo(pilha *p);//Menu 5
void extremos(pilha *p);//Menu 6
void exibirTopo(pilha *p);//Menu 7
void pares(pilha *p);//Menu 8
void ordenar(pilha *p);//Menu 9

int main(){
    menu();
return 0;
}
void iniciar(pilha *p){
    p->topo=-1;
}
void empilhar(pilha *p){//Menu 1

    if(p->topo >= tamanho-1){
        printf("Pilha cheia\n");
        system("pause");
    }else{
        p->topo++;
        printf("informe sua nota:");
        scanf("%f", &p->nota[p->topo]);
    }

    system("cls");

}
void desempilhar(pilha *p){//Menu 2

   if(p->topo == -1){
        printf("pilha vazia\n");
   }else{
        p->topo--;
        printf("Sucesso\n");
   }

    system("pause");
    system("cls");
}
void exibir(pilha *p){//Menu 3
    int i;
    for(i = p->topo; i >= 0; i--){
        printf("\nNota%d:%.2f\n", i, p->nota[i]);
    }

    system("pause");
    system("cls");
}
void localizarNota(pilha *p){//Menu 4
    float verificar;
    int aux=0;

    printf("Nota para conferir:");
    scanf("%f", &verificar);

    for(p->topo = 0; p->topo < tamanho; p->topo++){
        if(p->nota[p->topo] == verificar){
            printf("no %d e nota:%.2f\n", p->topo, p->nota[p->topo]);
            aux++;
        }
    }

    if(aux == 0){
        printf("\nErro: nao tem essa nota.\n");
    }

    system("pause");
    system("cls");
}
void localizarNo(pilha *p){//Menu 5
    int aux=0, verificar;

    printf("Informe o no:");
    scanf("%d", &verificar);

    for(p->topo = 0; p->topo < tamanho; p->topo++){
        if(p->topo == verificar){
            printf("no %d e nota:%.2f\n", p->topo, p->nota[p->topo]);
            aux++;
        }
    }

    if(aux == 0){
        printf("\nErro: nao tem essa No.\n");
    }

    system("pause");
    system("cls");
}
void extremos(pilha *p){//Menu 6
    float maior, menor;
    int i;

    for(i = 0; i < tamanho; i++){
        if(i == 0){
            maior = p->nota[i];
            menor = p->nota[i];
        }else{
            if(p->nota[i] > maior){
                maior = p->nota[i];
            }
            if(p->nota[i] < menor){
                menor = p->nota[i];
            }
        }
    }
    printf("Maior:%.2f\nMenor:%.2f\n", maior, menor);

    system("pause");
    system("cls");

}
void exibirTopo(pilha *p){//Menu 7
    printf("Nota do topo e:%.2f\n", p->nota[tamanho-1]);
    system("pause");
    system("cls");
}
void pares(pilha *p){//Menu 8
    for(p->topo = 0; p->topo < tamanho; p->topo++){
        if(p->topo % 2 == 0){
            printf("No e %d, sua nota e %.2f\n", p->topo, p->nota[p->topo]);
        }
    }
    system("pause");
    system("cls");
}
void ordenar(pilha *p){//Menu 9
    int j, i;
    float aux;

    for(i = 0; i <= p->topo; i++){
        for(j = i+1; j <= p->topo; j++){
            if(p->nota[i] > p->nota[j]){

                aux = p->nota[i];
                p->nota[i] = p->nota[j];
                p->nota[j] = aux;

            }
        }
    }
    printf("Sucesso\n");

    system("pause");
    system("cls");
}
int menu(){
    int menu=-1;

    pilha p;
    iniciar(&p);

    while(menu!=0){
        printf("==================Menu==================\n\n");
        printf("0 - Sair\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Exibir a pilha\n");
        printf("4 - Localizar por Nota\n");
        printf("5 - Localizar por No\n");
        printf("6 - Maior e menor nota\n");
        printf("7 - Mostra Nota do topo\n");
        printf("8 - Mostrar elementos pares\n");
        printf("9 - Ordenar pilha de forma crescente\n");
        printf("Digite sua opcao:");
        scanf("%d", &menu);

        system("cls");

        switch(menu){
            case 0:
                menu=0;
            break;

            case 1:
                empilhar(&p);
            break;

            case 2:
                desempilhar(&p);
            break;

            case 3:
                exibir(&p);
            break;

            case 4:
                localizarNota(&p);
            break;

            case 5:
                localizarNo(&p);
            break;

            case 6:
                extremos(&p);
            break;

            case 7:
                exibirTopo(&p);
            break;

            case 8:
                pares(&p);
            break;

            case 9:
                ordenar(&p);
            break;
        }
    }

return 0;
}
