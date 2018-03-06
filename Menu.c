#include<stdio.h>

void menu();

int main(){
    int opcao

    while(opcao!=6){

        menu();

        scanf("%d", &opcao);

        switch (opcao){
            case 1:

            break;
        }
    }

return 0;
}
void menu(){

    printf("----------------------------------------------------------------\n");
    printf("                             Menu\n");
    printf("----------------------------------------------------------------\n");
    printf("1 - ");
    printf("6 - Sair\n");
    printf("Digite sua opcao:\n");
    printf("----------------------------------------------------------------");

}
