typedef struct{
    char title[50];
    int id;
    int code;
    int actor;
    int status;
    char genero[128];
    int fechaDeEstreno;
}movie;
void setMovieStatus(movie movieArray[],int arrayLenght,int value);
int findMovieEmptyPlace(movie[],int );
int findMovieByCode(movie[],int ,int);
void setMovie( movie movieArray[],int freePlaceIndex, int codeAux,char titleAux[],int actorAux ,int fechaDeEstrenoAux);
void showMovieArray(movie  movieArray[],int arrayLenght , eActores actores[] , int arrayLenghtActores);
void orderMovie(movie  movieArray[],int arrayLenght );
#include "peliculas.c"
