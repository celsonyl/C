#include <stdio.h>
#include <string.h>
#define TAMANHO_MAXIMO 100


typedef struct {
  int topo;
  char letras[TAMANHO_MAXIMO];
} Pilha;

Pilha pilha;

void inicializa() {
  pilha.topo = 0;
}

void empilhar(char letra) {
  pilha.letras[pilha.topo] = letra;
  pilha.topo++;
}

char desempilhar() {
  pilha.topo--;
  return pilha.letras[pilha.topo];
}

void exibirPilha() {
  for (int i = pilha.topo - 1; i >= 0; i--)
    printf("%i - %c\n", i, pilha.letras[i]);
}

void palindromo() {
  char entradaDoUsuario[TAMANHO_MAXIMO];
  printf("Digite uma palavra: ");
  gets(entradaDoUsuario);

    printf("Palavra Digitada: %s\n", entradaDoUsuario);

    int count=0,i;
    for(i=0;entradaDoUsuario[i];i++){
        if(entradaDoUsuario[i]!=' '){
            entradaDoUsuario[count++]=entradaDoUsuario[i];
        }
    }
    entradaDoUsuario[count]=0;


  for (int i = 0; i < strlen(entradaDoUsuario); i++)
    empilhar(entradaDoUsuario[i]);


  printf("Palavra na Pilha: \n");
  exibirPilha();

  char *resultado = "Palindromo!";
  for (int i = 0; i < strlen(entradaDoUsuario); i++)
    if (entradaDoUsuario[i] != desempilhar())
      resultado = "Nao Palindromo";

  printf("%s\n", resultado);
}

int main() {
  palindromo();
}
