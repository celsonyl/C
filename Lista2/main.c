#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX 5

struct Pilha
{

    int capacidade;
    int codigo;
    float *dados;
    int primeiro;
    int ultimo;
    int nItens;

};


void criarPilha( struct Pilha *f)
{

    f->capacidade = MAX;
    f->dados = (float*) malloc (f->capacidade * sizeof(float));
    f->primeiro = 0;
    f->ultimo = -1;
    f->nItens = 0;

}


void inserir(struct Pilha *f, int v)
{


    if(f->nItens == f->capacidade)
    {
        printf("Pilha cheia!");
    }

    else
    {
        if(v > f->ultimo && f->ultimo != 0 && f->ultimo != -1)
        {
            printf("Caixa descartada por ser muito pesada");
        }

        else
        {
        f->dados[f->nItens] = v; // incrementa ultimo e insere
        f->nItens++; // mais um item inserido
        f->ultimo = v;
        }
    }


}


int remover( struct Pilha *f )   // pega o item do comeco da fila
{

    int temp = f->dados[f->primeiro++]; // pega o valor e incrementa o primeiro

    if(f->primeiro == f->capacidade)
        f->primeiro = 0;

    f->nItens--;  // um item retirado
    return temp;

}


void mostrarPilha(struct Pilha *f)
{


    int cont, i;
    printf("\n");
    for ( cont=0, i= f->primeiro; cont < f->nItens; cont++)
    {

        printf("[%d] %.2f\n",cont+1,f->dados[i++]);

        if (i == f->capacidade)
            i=0;

    }
    printf("\n\n");

}

float soma(struct Pilha *f)
{
    int cont,i;
    int soma;

    for(cont=0,i= f->primeiro; cont< f->nItens; cont++)
    {

        soma += f->dados[i++];
        if (i == f->capacidade)
            i=0;
    }
    return soma;
}




int estaVazia( struct Pilha *f )   // retorna verdadeiro se a fila está vazia
{

    return (f->nItens==0);

}

int estaCheia( struct Pilha *f )   // retorna verdadeiro se a fila está cheia
{

    return (f->nItens == f->capacidade);
}









void main ()
{

    int opcao;
    float peso;
    struct Pilha umaPilha;

    // cria a fila
    criarPilha(&umaPilha);

    // apresenta menu
    while( 1 )
    {



        printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Pilha\n4 Mostrar soma\nOpcao: ");
        scanf("%d", &opcao);


        switch(opcao)
        {

        case 1: // insere elemento
            if (estaCheia(&umaPilha))
            {
                printf("\nPilha cheia!!!\n\n");

            }
            else
            {

                printf("\nDigite o peso: ");
                scanf("%f", &peso);
                inserir(&umaPilha,peso);


            }

            break;

        case 2: // remove elemento
            if (estaVazia(&umaPilha))
            {

                printf("\nPilha vazia!!!\n\n");

            }
            else
            {

                peso = remover(&umaPilha);
                printf("\nRemovido com sucesso\n\n") ;

            }
            break;

        case 3: // mostrar fila
            if (estaVazia(&umaPilha))
            {

                printf("\nPilha vazia!!!\n\n");

            }
            else
            {

                printf("\nConteudo da pilha: => ");
                mostrarPilha(&umaPilha);


            }
            break;

        case 4://Mostrar soma
            if (estaVazia(&umaPilha))
            {

                printf("\nPilha vazia!!!\n\n");

            }

            else
            {

                printf("\nSoma do peso das caixas:  => ");
                printf("%f",soma(&umaPilha));
            }



        }
    }
}
