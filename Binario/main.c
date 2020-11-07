#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    int num;
   int bin[8]; // <---------------
   int aux;
}PILHA;

void calc(int num,PILHA *p){

    if(num <= 63){
    for (p->aux = 7; p->aux >= 0; p->aux--)
   {
      if (num % 2 == 0)
         p->bin[p->aux] = 0;
      else
         p->bin[p->aux] = 1;
      num = num / 2;
   }

   for (p->aux = 0; p->aux < 8; p->aux++)
       printf("%d", p->bin[p->aux]);

   printf("\n");
    }else{
        printf("Esse numero usa mais que 6 bits!");
    }
}


int main()
{
    PILHA p;
   int num;

   printf("Digite o número (base decimal) para ser convertido: ");
   scanf("%d", &num);

   calc(num,&p);

   return 0;
}
