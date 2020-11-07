#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct fila{
int fila[MAX];
int decolagem[MAX];
int topof, topod;
}FILA;



    int vazio (FILA f)
    {
        return (f.topof==0);
    }

    int cheio (FILA f)
    {
        return (f.topof==MAX);
    }

    void adicionarFila(int aviao, FILA *f)
    {
        if(cheio(*f))
        {
            printf("\nA fila esta cheia");

        }
        else
        {
            f->fila[f->topof] = aviao;
            f->topof++;
        }
    }

    void adicionarDecolagem(int aviao, FILA *f)
    {
        if(cheio(*f))
        {
            printf("\nA fila esta cheia");

        }
        else
        {
            f->decolagem[f->topod] = aviao;
            f->topod++;
        }
    }

    void mostrarDecolagem (FILA *f)
    {
        int total=0;
        printf("\n");
        printf("\nQuantidade de avioes aguardando na fila de decolagem: ");

        for (int i=0;i<f->topod;i++)
        {
          total = total + 1;
        }

        printf("%d",total);
         printf("\n");

    }

    void removePrimeiro (FILA *f)
    {
        if(vazio(*f))
        {
            printf("\nA fila esta vazia");
        }
        else
        {
            f->topof--;
            int primeiroaviao = f->fila[0];
            printf("O aviao %d decolou!",primeiroaviao);

            for (int i=0;i=f->topof;i++)
            {
                    f->fila[i] = f->fila[i+1];
            }

            primeiroaviao = f->decolagem[f->topod];
        }

    }

    void mostrarPrimeiro (FILA *f)
    {
        int total;
        printf("\n");
        printf("\nDigite o código do primeiro aviao: ");
        printf("%d",f->fila[0]);
        printf("\n");
    }

    void mostrarFila (FILA *f)
    {
        printf("\n");
        printf("\nAvioes  na fila de espera:\n");

        for (int i=0;i<f->topof;i++)
        {
          printf("%d",f->fila[i]);
          printf("\n");
        }

         printf("\n");
    }

int main()
{
    FILA f1;
    int opcao=0;
    int aviao;
    f1.topod = 0;
    f1.topof = 0;
    adicionarFila(101,&f1);
    adicionarFila(102,&f1);
    adicionarDecolagem(103,&f1);

    do{
       switch (opcao)
        {
        case 1:
            mostrarDecolagem(&f1);
            break;
        case 2:
            removePrimeiro(&f1);
            break;
        case 3:
            printf("\nDigite o codigo do aviao a ser adicionado na fila ");
            scanf("%d",&aviao);
            adicionarFila(aviao,&f1);
            break;
        case 4:
            mostrarFila(&f1);
            break;
         case 5:
            mostrarPrimeiro(&f1);
            break;
        }
        printf("\n");
        printf("\nEscolha:\n");
        printf("\n[1] - Mostrar quantidade de avioes na fila de decolagem");
        printf("\n[2] - Autorizar decolagem do primeiro aviao da fila");
        printf("\n[3] - Adicionar aviao na fila de espera");
        printf("\n[4] - Mostrar o codigo de todos os avioes da fila de espera");
        printf("\n[5] - Mostrar o codigo do primeiro aviao");
        printf("\nPressione qualquer numero acima de [5] para finalizar\n");
        printf("\nEscolha: ");
        scanf("%d",&opcao);
        system("cls");
    }while(opcao<=5);
    printf("Encerrou o programa!");

}
