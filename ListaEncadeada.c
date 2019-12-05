#include "ListaEncadeada.h"

char* Ordenacao_Word(unsigned char* v, int tam){
    char aux;
    int i, j;
    unsigned char* v2 = (char*) malloc(tam+1*sizeof(char));
    strcpy(v2,v);
    for(i = 0; i < tam; i++){    
        for(j = i+1 ; j < tam; j++){
            if(v2[i] > v2[j]){
                aux = v2[j];
                v2[j] = v2[i];
                v2[i] = aux;
            }
        }
    }
    return v2;
}

void inserirLista(Lista* v, char* palavra, int tam){
    NOH* vetor = (NOH*) calloc(1,sizeof(NOH));
    char* palavra2 = (char*) malloc(tam+1*sizeof(char));
    strcpy(palavra2, palavra);
    vetor->Palavra = palavra2;
    vetor->PalavraOrd = Ordenacao_Word(palavra,tam);
    vetor->prox = NULL;
    if(v->Primeiro == NULL){
        v->Primeiro = v->Ultimo = vetor;
    }else{
        v->Ultimo->prox = vetor;
        v->Ultimo = vetor;
    }
}

void BuscaLista(Lista* v, char* palavra){
    NOH* i = v->Primeiro;
    int cont = 0;
    while(i != NULL){
        if(strcmp(i->PalavraOrd, palavra) == 0 ){
            printf("%s\n", i->Palavra);
            cont++;
        }
        i = i->prox;
    }
    if(cont > 0) return;
    printf("Esta palavra não foi encontrada\n");
}
