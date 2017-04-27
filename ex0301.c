#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ReadKeyboard ();
void GenerateValues(int**,int);
void CalcNewArray(int**,int**,int);
void createMate(int ***, int);

int main(void)
{
    int **arraypp,**newarray;
    int ArraySize;

    ArraySize=ReadKeyboard();

    createMate(&arraypp, ArraySize);
    GenerateValues(arraypp, ArraySize);
    createMate(&newarray, ArraySize);
    CalcNewArray(arraypp,newarray,ArraySize);
    return EXIT_SUCCESS;
}

///repetir loop sem pedir numero quando exemplo quert
int ReadKeyboard()
{
    char sizetest[4]={0};
    int verify=0, size;
    for(int i=0; verify!=1 || size<3 || size>99;i++)
    {
        if(i>0)
        {
            printf("Error. Invalid value.\n\n");
        }
        printf("Enter the array size(min.3||max.99):\n>>>");
        fgets(sizetest,4,stdin);
        verify=(sscanf(sizetest,"%d",&size));
    }
    return size;
}

void GenerateValues(int** array, int size)
{
    int value;
    srand(time(NULL));
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            value=random()%8+1;
            array[i][j]=value;
            printf("  %2d  ", array[i][j]);
        }
        printf("\n\n");
    }
 return value;
}

void CalcNewArray(int** array,int** newarray,int size)
{
    for(int i=1; i<(size-1); i++)
        for(int j=1; j<(size-1); j++)
            newarray[i][j]=array[i][j]+array[i+1][j]+array[i-1][j]+array[i][j+1]+array[i][j-1];

    printf("================================================================================\n");
    for(int i=0; i<size; i++)
    {   printf("\n\n");
        for(int j=0; j<size; j++)
        {
            printf("  %02d  ", newarray[i][j]);
        }
    }
 return;
}

void createMate(int ***arraypp, int ArraySize)
{
    (*arraypp) = malloc(ArraySize*sizeof(int*));
    if(*arraypp==NULL)
    {
        fprintf(stderr,"out of memory\n");
        exit(-1);
    }

    for(int i=0; i<ArraySize; i++)
    {
        (*arraypp)[i]=malloc(ArraySize*sizeof(int));

        if((*arraypp)[i]==NULL)
        {
            fprintf(stderr,"out of memory\n");
            exit(-1);
        }
    }

}
