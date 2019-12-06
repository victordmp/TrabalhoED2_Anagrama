#include "ListaEncadeada.h"

typedef struct hash{
    Lista* lista;
    int qtd;
}HASH;

//Essa função é responsavel por criar e inicializar a HASHING 
HASH* HASH_Criar(int n);

//Essa função vai pegar a soma dos do vetor de palavras e vai fazer mod o tamanho da HASH
int HASH_Position(unsigned int chave, int n);

//Essa função é responsavel por fazer o somatorio do vetor de palavras
int HASH_Chave(unsigned char* vet, int tam, int n);

//Essa função é responsavel por achar a posição da HASH e chamar a função de inseriLista()
void HASH_Inserir(HASH* v, char* vet, int n);

//Essa função é responsavel em tranformar todas as letras Maíusculas em Mínusculas
void TransPalavraMin(char* palavra);

//Essa função pega as palavras do arquivo linha por linha e a função HASH_Inserir()
void PegaPalavrasArquivo(HASH* v, int n);

//Essa função é responsavel por chamar a função BuscaLista() que fará a busca dos anagramas
void HASH_Busca(HASH* v, char* vet, int n);

void tamanho(HASH* v, int n);




