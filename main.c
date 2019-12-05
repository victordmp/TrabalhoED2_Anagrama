#include "HASH.h"

int main(int argc, char** argv){
    char* palavra;
    for(int i = 0; i < argc; i++){
        palavra = argv[i];
    }
    TransPalavraMin(palavra);
    
    int n = 15000; //Tamanho da HASH
    HASH* v = HASH_Criar(n);

    PegaPalavrasArquivo(v,n);
    HASH_Busca(v, palavra, n);
    return 0;
}