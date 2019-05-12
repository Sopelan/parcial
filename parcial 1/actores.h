typedef struct{
int id;
char name[128];
char country[128];
}eActores;
void setActores(eActores actores[],int espacioLibre , int auxId, char auxName[] , char auxCountry[]);
void orderActor(eActores actorArray[],int arrayLenght );
void showActoresArray(eActores actores[] , int arrayLenght);

#include "actores.c"
