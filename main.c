#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** readwords(FILE*, int*);
void findword(char**, char*, int);

int main(int argc, char * argv[])
{
    char** lista_palavras = NULL;
    char* palavra=NULL;
    FILE*  fp = NULL;
    int i=0;
    int numofwords=0;

    if (argc != 3)
    {
        printf("Error: Too few arguments from command line\n");
        exit(EXIT_FAILURE);
    }

    /*Copiar a palavra a procurar numa string */
    palavra=calloc(1, sizeof(char*));
    strcpy(palavra, argv[2]);

    fp = fopen(argv[1], "r"); /*Abrir o ficheiro introduzido*/

    if (fp == NULL)
    {
        printf("Error: Could not open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    lista_palavras=readwords(fp, &numofwords); /*ler as palavras do ficheiro e passar para o vetor*/
    findword(lista_palavras, palavra, numofwords);

    fclose(fp);

    for (i = 0; i < numofwords; i++)
    {
        free(lista_palavras[i]);
    }

    free(lista_palavras);
    lista_palavras = NULL;

    return EXIT_SUCCESS;
}

/**

readwords: função para ler as palavras do ficheiro e guardar no vetor de ponteiros. Retorna também o número de palavras

*/

char** readwords(FILE* _fp, int* _numofwords)
{
    char** arrayofwords=NULL;
    int i=0, dimline=0;
    char line[10000]; //buffer para guardar as linhas do ficheiro

    /* Determinaŕ o número de linhas (o número de palavras) do ficheiro*/

    while (fgets(line, sizeof(line), _fp) != NULL)
    {
       (*_numofwords)++;
    }

    rewind(_fp); //voltar ao início do ficheiro

    //Alocar memória
    arrayofwords=calloc((*_numofwords), (sizeof(char*)));

    if(arrayofwords==NULL)
        exit(EXIT_FAILURE);

    //Ciclo para guardas as palavras no vetor de ponteiros
    for(i=0; i<(*_numofwords); i++)
    {
        fgets(line, sizeof(line), _fp); //obter a linha do ficheiro
        dimline=strlen(line);//determinar a dimensão da palavra
        line[dimline-1]='\0';// remover o \n da string
        dimline--; //decrementar o comprimento (para não contar com o \0 agora acrescentado na última posição
        arrayofwords[i]=calloc(1, dimline+1); //alocar memória para a string (a dimensão mais o caracter terminador).
        strcpy(arrayofwords[i], line); // copiar para o vetor a palavra
    }


    return arrayofwords;
}

/**

findword: funcao que recebe a lista de palavras e a palavra e a procura

*/
void findword(char** _listapalavras, char* _palavra, int _numofwords)
{
    int i=0, flag=0;
    /* Ciclo para percorrer as palavras da lista */
    for (i=0; i < _numofwords; i++)
    {
        /* Comparar a palavra com a da lista*/
        if(strcmp(_palavra, _listapalavras[i])==0)
        {
            printf("Word found in line %d\n", i+1);
            flag=1;
            break;
        }
    }

    if(flag==0)
        printf("Word not found\n");


}

