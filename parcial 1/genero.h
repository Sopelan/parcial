typedef struct{
    char name[128];
    int id;
}eGenero;
void setGenero(eGenero genero[],int freePlace , char auxName[]);
void setGeneroStatus(eGenero generoArray[],int arrayLenght);
void showGenerosArray(eGenero genero[] , int arrayLenght);
#include "genero.c"
