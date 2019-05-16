typedef struct{
    char title[50];
    int id;
    int code;
    int actor;
    int status;
    int fechaDeEstreno;
    int genero;
}eMovie;
void setMovieStatus(eMovie movieArray[],int arrayLenght,int value);
int findMovieEmptyPlace(eMovie[],int );
int findMovieByCode(eMovie[],int ,int);
void setMovie( eMovie movieArray[],int freePlaceIndex, int codeAux,char titleAux[],int actorAux ,int fechaDeEstrenoAux , int generoAux);
void showMovieArray(eMovie  movieArray[],int arrayLenght , eActores actores[] , int arrayLenghtActores , eGenero generoArray[], int arrayLenghtGenero);
void orderMovie(eMovie  movieArray[],int arrayLenght );
int getValidIntChar(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
#include "peliculas.c"
