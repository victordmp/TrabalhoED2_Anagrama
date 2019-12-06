#include "HASH.h"


HASH* HASH_Criar(int n){
    HASH* vetor = (HASH*) calloc(n,sizeof(HASH));
    for(int i=0; i<n; i++){
        Lista* v = (Lista*) calloc(1,sizeof(Lista));
        v->Primeiro = v->Ultimo = NULL;
        vetor[i].qtd = 0;
        vetor[i].lista = v;
    }

    return vetor;
}


int HASH_Position(unsigned int chave, int n){
    //if(chave < 0) chave*-1;
    return chave%n;   
}


int HASH_Chave(unsigned char* vet, int tam, int n){
    unsigned int chave = 1;
    for(int i = 0; i < tam; i++){
      chave+=vet[i]*(i+5);
    }
    return HASH_Position(chave,n);
}


void HASH_Inserir(HASH* v, char* vet, int n){

    int tam = strlen(vet);
    char* palavraOrd = (char*) malloc(tam+1*sizeof(char));
    palavraOrd = Ordenacao_Word(vet, tam);
    int chave = HASH_Chave(palavraOrd ,tam,n);
    inserirLista(v[chave].lista, vet, tam);
    v[chave].qtd++;
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
    char* palavra = Ordenacao_Word(vet,tam);
    int chave = HASH_Chave(palavra ,tam, n);
    BuscaLista(v[chave].lista, palavra);
}

void tamanho(HASH* v, int n){
    float media = 0;
    int cont = 0;
    for(int i=0; i<n; i++){
        if(v[i].qtd > 0) cont++;
        media += v[i].qtd;
        printf("[%d]\n", v[i].qtd);
    }
    printf("%.3f\n", media/cont);
}