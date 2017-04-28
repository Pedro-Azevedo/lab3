#include <stdio.h>
#include <stdlib.h>

struct Model
{
    char CharModel;
    int IntModel;
};

typedef struct plane
{
    int airplaneID;
    struct Model model;
    float fuel;
} planeN;


int lowestFuel(struct plane*planes, int size)
{
    float lowFuel=(*planes).fuel;
    int planeThis=0;

    for(int j=1; j<size; j++)
    {
        if((*(planes+j)).fuel < lowFuel)
        {
            lowFuel=(*(planes+j)).fuel;
            planeThis=j;
        }
    }
    return planeThis;
}
void readPlanes (struct plane **planes,  int* size)
{
    int verify,j;
    char test[100];

    for(int i=0; verify!=1 ; i++)
    {
        printf("Enter fleetsize:\n >>> ");
        fgets(test,100,stdin);
        verify=sscanf(test,"%d",&*size);
    }

    (*planes) =(struct plane**) malloc((*size)*sizeof(struct plane));
    if(*planes==NULL)
    {
        fprintf(stderr,"out of memory\n");
        exit(-1);
    }

    for(j=0; j<*size || verify!=1 ; j++)
    {
        do{
        printf("Enter plane %d ID:\n >>> ",(j+1));
        fgets(test,100,stdin);
        verify=sscanf(test,"%d",&((*planes+j)->airplaneID));
        }while(verify!=1);

        do{
        printf("Enter plane %d model (UPPERCASE letter + number):\n >>> ",(j+1));
        fgets(test,100,stdin);
        verify=sscanf(test,"%c %d",&((*planes+j)->model.CharModel),&((*planes+j)->model.IntModel));
        }while(verify!=2 || ((*planes+j)->model.CharModel)<'A' || ((*planes+j)->model.CharModel)>'Z' );

        do{
        printf("Enter plane %d fuel:\n >>> ",(j+1));
        fgets(test,100,stdin);
        verify=sscanf(test,"%f",&((*planes+j)->fuel));
        }while(verify!=1);

    }
    return;
}

void printID(struct  plane *planes,  int  size)
{
    for(int j=0;j<size;j++)
    {
        printf("\n");
        printf("Plane %d:\n",(j+1));
        printf("PlaneID  %d\n", (*(planes+j)).airplaneID);
        printf("Model    %c%d\n", (*(planes+j)).model.CharModel, (*(planes+j)).model.IntModel);
    }
    return;
}

int main(void)
{
    struct plane *pptr;
    int fleetsize =0;
    int lowerFuelPlane;
    readPlanes(&pptr,&fleetsize);
    lowerFuelPlane=lowestFuel(pptr,fleetsize);
    printf("\n\nLowest Fuel Plane:\nID: %d\n",pptr[lowerFuelPlane].airplaneID);
    printf("Model: %c%d\n",pptr[lowerFuelPlane].model.CharModel,pptr[lowerFuelPlane].model.IntModel);
    printf("Fuel: %f\n",pptr[lowerFuelPlane].fuel);
    printID(pptr,fleetsize);
    return EXIT_SUCCESS;
}
