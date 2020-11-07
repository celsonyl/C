#include <stdio.h>
#include <string.h>
#define tamPilha 3 //quantidade de containers em cada local
#define tamPorto 4 //quantidade de locais do porto seco





typedef struct pilha{
      int topo;
      int item [tamPilha] ;
} PILHA;


//retorna se a pilha está vazia ou não
_Bool pilhaVazia(PILHA *p){
    if(p->topo == 0) {
        return 1;
    } else {
        return 0;
    }
}

//retorna se a pilha está cheia ou não
_Bool pilhaCheia(PILHA *p) {
	int tam = sizeof(p->item)/sizeof(int); //determina o tamanho do vetor

    if (p->topo < tam) {
        return 0;
    } else {
        return 1;
    }
}

//adiciona valor na pilha
void empilha(PILHA *p, int x){
    p->item[p->topo++]=x;
}

//remove valor da pilha
int desempilha(PILHA *p){
    return p->item[--p->topo];
}

//retorna o valor que está em cima na pilha
int valorTopo(PILHA *p) {
    return p->item[p->topo - 1];
}

//mostra os valores armazenados na pilha
void mostraPilha(PILHA *p) {
	printf("Valores da pilha: ");
	if (p->topo > 0) {
        for (int i = 0; i < p->topo; i++) {
            printf("%d ",p->item[i]);
        }
    } else {
       printf("pilha vazia");
    }
	printf("\n");
}

void mostraPorto(PILHA *vet[tamPorto]) {
    for (int i = 0; i < tamPorto; i++) {
        printf("Porto %d",i+1," -> ");
        mostraPilha(vet[i]);
    }
}

//determina qual pilha está mais vazia retornando a posição no vetor
int pilhaMaisVazia(PILHA *vet[tamPorto]) {
    //armazena o menor valor e que pilha (posicao) ele esta
    int menor = vet[0]->topo, posicao = 0;
    for (int i = 1; i < tamPorto; i++) {
        if (vet[i]->topo < menor) {
            menor = vet[i]->topo;
            posicao = i;
        }
    }

    return posicao;
}

void mostraOpcoes() {
   printf("Opcoes disponiveis: \n");
    printf("0: sair\n");
   printf("1: adicionar container\n");
    printf("2: remover   container\n");
    printf("Digite sua opcao: \n");
}

//verifica se o código está presente em alguma das pilhas do porto
//se existir retorna a posicao no vetor (local do porto)
int codigoExiste(PILHA *vet[tamPorto], int cod) {
    for (int i = 0; i < tamPorto; i++) {
        for (int j = 0; j < vet[i]->topo; j++) {
            if (vet[i]->item[j] == cod) {
                return i;
            }
        }
    }
    return -1; //se não encontrar o código vai retornar aqui
}

int main(){
    PILHA *local[tamPorto]; //cria um vetor de pilhas
    int opcao, codigo;

    do{
        mostraOpcoes();
        scanf("%d",&opcao);

        if(opcao == 0)
            break;


        printf("Informe o codigo do container: ");
        scanf("%d",&codigo);

        if (opcao == 1) { //adicionar container
            if (codigoExiste(local, codigo) != -1) {
               printf("Codigo invalido"); //codigo fornecido já existente
            } else {
                int posicaoPorto = pilhaMaisVazia(local);
                if (pilhaCheia(local[posicaoPorto])) {
                    printf("Impossivel empilhar!"); //nenhum lugar vago disponível
                } else {
                    empilha(local[posicaoPorto],codigo);
                }
            }
        } else { //remover container
            int posicaoPorto = codigoExiste(local, codigo);
            if (posicaoPorto == -1) {
               printf("Codigo invalido!"); //codigo fornecido não existente
            } else {
                if (valorTopo(local[posicaoPorto]) == codigo) {
                    desempilha(local[posicaoPorto]);
                } else {
                   printf("Impossivel desempilhar!"); //código fornecido não esta no topo da pilha
                }
            }
        }

        mostraPorto(local);
        printf("\n");
    }while(opcao != 0);

    return 0;
}
