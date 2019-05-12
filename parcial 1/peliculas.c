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

    }
    return LIBRE;
}
void setMovie( movie movieArray[],int freePlaceIndex, int codeAux,char titleAux[], int actorAux ,int fechaDeEstrenoAux)
{
    movieArray[freePlaceIndex].code = codeAux;
    strcpy(movieArray[freePlaceIndex].title ,titleAux);
    movieArray[freePlaceIndex].actor = actorAux;
    movieArray[freePlaceIndex].fechaDeEstreno = fechaDeEstrenoAux;
    movieArray[freePlaceIndex].status = OCUPADO;
}

void showMovieArray(movie  movieArray[],int arrayLenght , eActores actores[] , int arrayLenghtActores)
{
    int i;
    int opcion;
    int j;

    opcion = getValidInt("que queres ver?\n1.las peliculas sin actores\n2.las peliculas con actores\n","tiene que ser un numero\n",1,2);
    switch(opcion)

    {
        case 1:
            printf("|%10s|\t|%10s|\t|%10s|\t|%15s|\n","ID","codigo","titulo","fecha de estreno");
            for(i = 0 ; i < arrayLenghtActores ; i++)
            {
                for(j = 0 ; j < arrayLenght ; j++)
                {
                    if(movieArray[j].status == OCUPADO && movieArray[j].actor == actores[i].id)
                    {
                        if(movieArray[j].actor == 6)
                        {
                            printf("|%10d|\t|%10d|\t|%10s|\t|%15d|\n",movieArray[j].id,movieArray[j].code,movieArray[j].title , movieArray[j].fechaDeEstreno);
                        }
                    }
                }
            }
        break;
        case 2:
            printf("|%10s|\t|%10s|\t|%10s|\t|%15s|\t|%10s|\n","ID","codigo","titulo","fecha de estreno","actores");
            for(i = 0 ; i < arrayLenghtActores ; i++)
            {
                for(j = 0 ; j < arrayLenght ; j++)
                {
                    if(movieArray[j].status == OCUPADO && movieArray[j].actor == actores[i].id)
                    {
                        if(movieArray[j].actor != 6)
                        {
                            printf("|%10d|\t|%10d|\t|%10s|\t|%15d|\t|%10s|\n",movieArray[j].id,movieArray[j].code,movieArray[j].title,movieArray[j].fechaDeEstreno,actores[i].name);
                        }
                    }
                }




            }
            break;

    }
}
void orderMovie(movie  movieArray[],int arrayLenght )
{
    int i;
    int j;
    movie auxMovie;
    for(i = 0 ; i < arrayLenght - 1 ; i++)
    {
        for(j = i + 1 ; j < arrayLenght ; j++)
        {
            if(movieArray[i].status == OCUPADO && movieArray[j].status == OCUPADO && movieArray[i].fechaDeEstreno < movieArray[j].fechaDeEstreno)
            {
                auxMovie = movieArray[i];
                movieArray[i] = movieArray[j];
                movieArray[j] = auxMovie;

            }

        }
    }

}

