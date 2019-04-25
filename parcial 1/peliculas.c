void setMovieStatus(movie movieArray[],int arrayLenght,int value)
{
    int i;
    for(i = 0 ; i <  arrayLenght ;  i++)
    {
        movieArray[i].status = value;
        movieArray[i].id = 1000 + i;
    }
}
int findMovieEmptyPlace(movie movieArray[],int arrayLenght)
{
    int i;
    for(i = 0 ; i < arrayLenght ; i++)
    {
        if(movieArray[i].status == LIBRE)
            return i;
    }
    return OCUPADO;
}
int findMovieByCode(movie movieArray[],int arrayLenght,int code)
{
    int i;
    for(i = 0 ; i < arrayLenght ; i++)
    {
        if(movieArray[i].code == code)
        {
            return i;
        }
        return LIBRE;
    }
}
void setMovie( movie movieArray[],int freePlaceIndex, int codeAux,char titleAux[], char actorAux[])
{
    movieArray[freePlaceIndex].code = codeAux;
    strcpy(movieArray[freePlaceIndex].title ,titleAux);
    strcpy(movieArray[freePlaceIndex].actor , actorAux);
    movieArray[freePlaceIndex].status = OCUPADO;
}
void setActor(movie movieArray , int option)
{
    switch(option)
    {
        case 1:
            sprintf(movieArray.actor,"Julieta Roberto");
            break;
        case 2:
            sprintf(movieArray.actor ,"Roberto Deniro");
            break;
        case 3:
            sprintf(movieArray.actor ,"Richar Darin");
            break;
        case 4:
            sprintf(movieArray.actor ,"Tita Merelo");
            break;
        case 5:
            sprintf(movieArray.actor ,"Sandro");
            break;
        case 6:
            sprintf(movieArray.actor ,"");
            break;
    }
    return 0;

}
void showBookArray(movie  movieArray[],int arrayLenght)
{
    int i;
    printf("|%5s|\t|%10s|\t|%20s|\t|%5s|\n","","","","");
    option = getValidInt()
    switch(opcion)
    for(i = 0 ; i < arrayLenght ; i++)
    {
        if(movieArray[i].status == OCUPADO)

    }
}
