#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamL 4

typedef struct{
	int matAp[tamL];
	float notaAp[tamL];
}aprovados;
typedef struct{
	int n;//quantidade de alunos
	int limite;
	int mat[tamL];
	float nota[tamL];
	aprovados apr;
}aluno;

//funçoes
int menu();
void iniciar(aluno *a);
void inserirFinal(aluno *a);//1
void limite(aluno *a);//2
void localizarMatricula(aluno *a);//3
void localizarPosicao(aluno *a);//4
void excluir(aluno *a);//5
void maiorNota(aluno *a);//6
void substituir(aluno *a);//7
void ordenar(aluno *a);//8
void listaAprovados(aluno *a);//9
void mostrar(aluno *a);//10

int main(){

	menu();

}
void iniciar(aluno *a){
	a->n = 0;
	a->limite = tamL;
}
void inserirFinal(aluno *a){//1

	printf("\t\t\t-----------------Inserir-----------------\n");
	if(a->n > tamL-1 || a->n > a->limite-1){
		printf("\n\t\t\terro – elemento fora dos limites\n");
	}else if(a->n <= a->limite-1){
		printf("\n\t\t\tDados%d", a->n);
		printf("\n\t\t\tInforme numero de matricula:");
		scanf("%d", &a->mat[a->n]);
		printf("\t\t\tInforme sua nota:");
		scanf("%f", &a->nota[a->n]);
		a->n++;
	}
	system("pause");
	system("cls");
}
void limite(aluno *a){//2



	printf("\t\t\t-----------------Já preenchidos-----------------\n\n");
	printf("já foi preenchido:%d\n", a->n);

	system("pause");
	system("cls");

}
void localizarMatricula(aluno *a){//3
	int verificar, erro = 0;


	printf("\t\t\t-----------------Localizar por matricula-----------------\n");
	printf("\t\t\t\n matricula do aluno:");
	scanf("%d", &verificar);

	for(a->n = 0; a->n <= a->limite; a->n++){
		if(verificar == a->mat[a->n]){
			printf("\n\t\t\tMatricula:%d", a->mat[a->n]);
			printf("\n\t\t\tNota:%.2f\n", a->nota[a->n]);
			erro++;
		}
	}
	if(erro == 0){
		printf("\n\t\t\tErro - Matricula nao encontrada\n\n");
	}
	system("pause");
	system("cls");
}
void localizarPosicao(aluno *a){//4
	int posi, erro = 0;

	printf("\t\t\t-----------------Localizar por posicao-----------------\n");
	printf("\n\t\t\tPosicao do aluno:");
	scanf("%d", &posi);

	if(posi > a->limite-1){
		printf("\t\t\tErro - posicao maior que existente\n");
	}else{

		for(a->n = 0; a->n <= a->limite; a->n++){
			if(posi == a->n){
				printf("\n\t\t\tMatricula:%d", a->mat[a->n]);
				printf("\n\t\t\tNota:%.2f\n", a->nota[a->n]);
				erro++;
			}
		}
	}

	if(erro == 0){
		printf("\n\t\t\tErro - Posicao nao encontrada\n");
	}
	system("pause");
	system("cls");
}
void excluir(aluno *a){//5
	int removed;
	int mat_temp;
	float nota_temp;

	printf("Digite qual elemento deseja excluir");
	scanf("%d", &removed);

	if(removed > a->limite){
		printf("\t\t\tErro - Limite maior que quantidade suportada (500)\n");
	}else{
		mat_temp = a->mat[a->limite-1];
		nota_temp = a->nota[a->limite-1];

		a->mat[a->limite-1] = a->mat[removed];
		a->nota[a->limite-1] = a->nota[removed];

		a->mat[removed] = mat_temp;
		a->nota[removed] = nota_temp;

		a->limite--;
	}
	system("pause");
	system("cls");
}
void maiorNota(aluno *a){//6
	float maior = 0;
	int aux;

	for(a->n = 0; a->n < a->limite; a->n++){
		if(a->nota[a->n] >= maior){
			maior = a->nota[a->n];
			aux = a->n;
		}
	}

	printf("\t\t\t-----------------Maior nota-----------------\n");

	for(a->n = 0; a->n <= a->limite; a->n++){
		if(aux == a->n){
			printf("\t\t\t\tMatricula:%d", a->mat[a->n]);
			printf("\n\t\t\t\tNota:%.2f\n", a->nota[a->n]);
		}
	}
	system("pause");
	system("cls");
}
void substituir(aluno *a){//7
	int subs;

	printf("\t\t\t-----------------Substituir:-----------------\n");
	printf("\n\t\t\tInforme a posicao do aluno que deseja substituir:");
	printf("\t\t\tOBS: apartir do numero'0'");
	scanf("%d", &subs);

	if(subs > a->limite-1){
		printf("\n\t\t\tErro - Valor informado maior que limite\n");
	}else{
		for(a->n = 0; a->n < a->limite; a->n++){
			if(subs == a->n){
				printf("\n\n\t\t\tPosicao %d \n", a->n);
				printf("\t\t\tMudar atricula %d para :", a->mat[a->n]);
				scanf("%d", &a->mat[a->n]);
				printf("\t\t\tMudar nota %.2f para:", a->nota[a->n]);
				scanf("%f", &a->nota[a->n]);

				printf("\n\n\t\t\tNova Posicao %d\n", a->n);
				printf("\t\t\tMatricula:%d\n", a->mat[a->n]);
				printf("\t\t\tNota:%.2f\n", a->nota[a->n]);
			}
		}
	}
	system("pause");
    system("cls");
}
void ordenar(aluno *a){//8
	int j, aux;
	float auxf;

	for(a->n = 0; a->n < a->limite; a->n++){
		for(j=a->n+1; j < a->limite; j++){
			if(a->mat[a->n] > a->mat[j]){

				aux = a->mat[a->n];
				a->mat[a->n] = a->mat[j];
				a->mat[j] = aux;

				auxf = a->nota[a->n];
				a->nota[a->n] = a->nota[j];
				a->nota[j] = auxf;
			}
		}
	}
	printf("\t\t\t-----------------Ordenada com sucesso:-----------------\n");
	system("pause");
	system("cls");
}
void listaAprovados(aluno *a){//9
	printf("\t\t\t-----------------Aprovados-----------------\n\n");

	for(a->n = 0; a->n < a->limite; a->n++){
		if(a->nota[a->n] >= 7 ){
			a->apr.matAp[a->n] = a->mat[a->n];
			a->apr.notaAp[a->n] = a->nota[a->n];
			printf("\t\t\tMatricula:%d\n", a->apr.matAp[a->n]);
			printf("\t\t\tNota:%.2f\n\n", a->apr.notaAp[a->n]);
		}
	}
	system("pause");
    system("cls");
}
void mostrar(aluno *a){//10

	printf("\t\t\t-----------------Todos os alunos:-----------------\n");

	for(a->n = 0; a->n < a->limite; a->n++){

		printf("\n\t\t\t\tDados %d\n", a->n);
		printf("\t\t\t\tMatricula: %d\n", a->mat[a->n]);
		printf("\t\t\t\tNota:%f\n",a->nota[a->n]);
	}

	system("pause");
    system("cls");
}
int menu(){
	aluno a;
	iniciar(&a);

	int m = -1;

	while(m != 0){
		printf("\t\t\t-----------------Menu Lista-----------------\n\n");
		printf("OBS: informe o limite se nao preenchar todos os alunos 10\n ");
		printf("\t\t\t0 - Sair\n");
		printf("\t\t\t1 - Inserir\n");
		printf("\t\t\t2 - Determina No\n");
		printf("\t\t\t3 - Localizar por matricula:\n");
		printf("\t\t\t4 - Localizar por posicao:\n");
		printf("\t\t\t5 - Excluir um aluno(n\n");
		printf("\t\t\t6 - Maior nota\n");
		printf("\t\t\t7 - Substituir\n");
		printf("\t\t\t8 - Ordenar\n");
		printf("\t\t\t9 - Lista de Aprovados\n");
		printf("\t\t\t10 - Mostrar\n");
		printf("Informe opcao desejada:");
		scanf("%d", &m);

		system("cls");

		switch (m){
			case 0:
				m = 0;
			break;

			case 1:
				inserirFinal(&a);
			break;

			case 2:
				limite(&a);
			break;

			case 3:
				localizarMatricula(&a);
			break;

			case 4:
				localizarPosicao(&a);
			break;

			case 5:
				excluir(&a);
			break;

			case 6:
				maiorNota(&a);
			break;

			case 7:
				substituir(&a);
			break;

			case 8:
				ordenar(&a);
			break;

			case 9:
				listaAprovados(&a);
			break;

			case 10:
				mostrar(&a);
			break;
		}
	}

return 0;
}
