#include <stdio.h>
#include <stdlib.h>


void imp (float *vetor, int nel)
{
    for(int i=0; i<nel; i++)
    {
        printf("%f, ", vetor[i]);
    }
}


int main()
{
    float *vMedias;
    int nMedias=0;
    printf("Digite o numero de alunos: ");
    scanf("%d",&nMedias);


    vMedias =  malloc(nMedias * sizeof(float));
        if(vMedias == NULL)
    {
        printf("Para gay");
        exit(0);
    }


    for (int i=0; i<nMedias; i++)
    {
        scanf("%f", &vMedias[i]);
    }

    imp(vMedias,nMedias);
    free(vMedias);
    return 0;
}
