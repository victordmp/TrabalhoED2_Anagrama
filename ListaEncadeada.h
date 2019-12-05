#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


typedef struct noh{
    char* Palavra;
    char* PalavraOrd;
    struct noh* prox;
}NOH;
typedef struct lista{
    NOH* Primeiro;
    NOH* Ultimo;
}Lista;

//Esaa função é responsavel por ordenar a palavras
char* Ordenacao_Word(unsigned char* v, int tam);

//Essa função responsavel por inserir o NOH na lista encadeada
//Ela é chamada pela função HASH_Inserir();
void inserirLista(Lista* v, char* palavra, int tam);

//Essa função é reponsavel por percorrer a Lista Encadeada
//Procurando os ananagramas 
//Ela é chamada pela função HASH_Busca() 
void BuscaLista(Lista* v, char* palavra);