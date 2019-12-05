#include "HASH.h"


HASH* HASH_Criar(int n){
    HASH* vetor = (HASH*) calloc(n,sizeof(HASH));
    for(int i=0; i<n; i++){
        Lista* v = (Lista*) calloc(1,sizeof(Lista));
        v->Primeiro = v->Ultimo = NULL;
        vetor[i].lista = v;
    }

    return vetor;
}


int HASH_Position(int chave, int n){
    //if(chave < 0) chave*-1;
    return chave%n;   
}


int HASH_Chave(unsigned char* vet, int tam, int n){
    int chave = 0;
    for(int i = 0; i < tam; i++){
      chave+=vet[i];
    }
    return HASH_Position(chave,n);
}


void HASH_Inserir(HASH* v, char* vet, int n){
    int tam = strlen(vet);
    int chave = HASH_Chave(vet ,tam, n);
    inserirLista(v[chave].lista, vet, tam);
}

void TransPalavraMin(char* palavra){
  char *s = palavra;
    while (*s) {
        *s = tolower((unsigned char) *s);
        s++;
  }
}


void PegaPalavrasArquivo(HASH* v, int n){
  FILE *arq;
  char vet[100];
  char *resultado;
  int i;
  arq = fopen("palavras.txt", "rt");
  if (arq == NULL){
    return;
  }
  i = 1;
  while (!feof(arq)){
    resultado = fgets(vet, 100, arq);
    if(resultado == NULL) break;
    int i = 0;
    while(resultado[i] != '\n'){
      i++;
    }
    resultado[i] = '\0';
    TransPalavraMin(resultado);
    HASH_Inserir(v,resultado,n);
  }
  fclose(arq);
}


void HASH_Busca(HASH* v, char* vet, int n){
    int tam = strlen(vet);
    int chave = HASH_Chave(vet ,tam, n);
    char* palavra = Ordenacao_Word(vet,tam);
    BuscaLista(v[chave].lista, palavra);
}