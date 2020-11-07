#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

struct Fila {

	int capacidade;
	float *dados;
	int primeiro;
	int ultimo;
	int nItens;

};

void criarFila( struct Fila *f, int c ) {

	f->capacidade = c;
	f->dados = (float*) malloc (f->capacidade * sizeof(float));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0;

}

void inserir(struct Fila *f, int v) {

	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;

	f->ultimo++;
	f->dados[f->ultimo] = v; // incrementa ultimo e insere
	f->nItens++; // mais um item inserido

}

int remover( struct Fila *f ) { // pega o item do comeÃ§o da fila

	int temp = f->dados[f->primeiro++]; // pega o valor e incrementa o primeiro

	if(f->primeiro == f->capacidade)
		f->primeiro = 0;

	f->nItens--;  // um item retirado
	return temp;

}

int estaVazia( struct Fila *f ) { // retorna verdadeiro se a fila estÃ¡ vazia

	return (f->nItens==0);

}

int estaCheia( struct Fila *f ) { // retorna verdadeiro se a fila estÃ¡ cheia

	return (f->nItens == f->capacidade);
}

void mostrarFila(struct Fila *f){

	int cont, i;

	for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){

		printf("%.2f\t",f->dados[i++]);

		if (i == f->capacidade)
			i=0;

	}
	printf("\n\n");

}

float media(struct Fila *f){
    int cont,i;
    int soma;

    for(cont=0,i= f->primeiro;cont< f->nItens;cont++){

    soma += f->dados[i++];
    if (i == f->capacidade)
			i=0;
    }
    return cont = soma/f->nItens;
}

void main () {

	int opcao, capa;
	int idade;
	struct Fila umaFila;
	struct Fila segundaFila;

	// cria a fila
    capa = 10;
	criarFila(&umaFila, capa);
	criarFila(&segundaFila,capa);

	// apresenta menu
	while( 1 ){

		printf("\n1 - Inserir elemento\n2 - ENCERRA PROGRAMA\n3 - Mostrar Fila\n0 Remover 1 de cada lista - \n4 Mostrar medias das filas\nOpcao?\n ");
		scanf("%d", &opcao);


        switch(opcao){

			case 1: // insere elemento
				if (estaCheia(&umaFila)){
					printf("\nFila maior que 18 Cheia!!!\n\n");

				}
                if(estaCheia(&segundaFila)){
                            printf("\nFila menor que 18 Cheia!!!\n\n");

                }
				else {

					printf("\nDigite a idade");
					scanf("%d", &idade);
					if(idade >= 18)
					inserir(&umaFila,idade);
					else
                        inserir(&segundaFila,idade);

				}

				break;

			case 0: // remove elemento
				if (estaVazia(&umaFila)){

					printf("\nFila de MAIOR vazia!!!\n\n");

				}

				if (estaVazia(&segundaFila)){

					printf("\nFila DE MENOR vazia!!!\n\n");

				}
				else {

					idade = remover(&umaFila);
					idade = remover(&segundaFila);
					printf("\nremovido com sucesso\n\n") ;

				}
				break;

				case 3: // mostrar fila
					if (estaVazia(&umaFila)){

						printf("\nFila DE MAIOR vazia!!!\n\n");

					}
					if (estaVazia(&segundaFila)){

						printf("\nFila DE MENOR vazia!!!\n\n");

					}
					else {

						printf("\nConteudo da fila DE MAIOR => ");
						mostrarFila(&umaFila);
						printf("\n");
						printf("\nConteudo da fila DE MENOR => ");
						mostrarFila(&segundaFila);

					}
					break;

                case 4://Mostrar média
                    if (estaVazia(&umaFila)){

						printf("\nFila DE MAIOR vazia!!!\n\n");

					}
					if (estaVazia(&segundaFila)){

						printf("\nFila DE MENOR vazia!!!\n\n");

					}
                    else{

                        printf("\nMédia das idades da fila DE MAIOR => ");
                        printf("%f",media(&umaFila));
                        printf("\n");
						printf("\nMédia da fila DE MENOR => ");
						printf("%f",media(&segundaFila));
                    }



		}
	}
}
