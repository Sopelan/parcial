typedef struct{
    char title[50];
    int id;
    int code;
    char actor[50];
    int status;
}movie;
void setMovieStatus(movie movieArray[],int arrayLenght,int value);
int findMovieEmptyPlace(movie[],int );
int findMovieByCode(movie[],int ,int);
void setMovie( movie movieArray[],int freePlaceIndex, int codeAux,char titleAux[],char actorAux[]);
void setActor(movie movieArray , int option);
#include "peliculas.c"
