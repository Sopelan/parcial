void setMovieStatus(eMovie movieArray[],int arrayLenght,int value)
{
        int i;
        for(i = 0 ; i <  arrayLenght ;  i++)
        {
            movieArray[i].status = value;
            movieArray[i].id = 1000 + i;
        }
}
int findMovieEmptyPlace(eMovie movieArray[],int arrayLenght)
{
    int i;
    for(i = 0 ; i < arrayLenght ; i++)
    {
        if(movieArray[i].status == LIBRE)
            return i;
    }
    return OCUPADO;
}
int findMovieByCode(eMovie movieArray[],int arrayLenght,int code)
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
void setMovie( eMovie movieArray[],int freePlaceIndex, int codeAux,char titleAux[], int actorAux ,int fechaDeEstrenoAux , int generoAux)
{
    movieArray[freePlaceIndex].code = codeAux;
    strcpy(movieArray[freePlaceIndex].title ,titleAux);
    movieArray[freePlaceIndex].actor = actorAux;
    movieArray[freePlaceIndex].fechaDeEstreno = fechaDeEstrenoAux;
    movieArray[freePlaceIndex].status = OCUPADO;
    movieArray[freePlaceIndex].genero = generoAux;
}

void showMovieArray(eMovie  movieArray[],int arrayLenght , eActores actores[] , int arrayLenghtActores, eGenero generoArray[], int arrayLenghtGenero)
{
    int i;
    int opcion;
    int j;
    int k;
    char aux[128];
    int contador = 0;
    int max = 0;
    opcion = getValidInt("que queres ver?\n1.las peliculas sin actores\n2.las peliculas con actores\n3.peliculas con autores de EEUU\n4.filtrar por nacionalidad\n5.genero\n6.cantidad de peliculas por genero\n","tiene que ser un numero\n",1,6);
    switch(opcion)

    {
        case 1:
            printf("|%10s|\t|%10s|\t|%10s|\n","ID","nombre","codigo");
            for(i = 0 ; i < arrayLenghtActores ; i++)
            {
                for(j = 0 ; j < arrayLenght ; j++)
                {
                    for (k = 0 ; k < arrayLenghtGenero ; k++)
                    {
                        if(movieArray[j].status == OCUPADO && movieArray[j].actor == actores[i].id && movieArray[j].genero == generoArray[k].id)
                        {
                            if(movieArray[j].actor == 6)
                            {
                                printf("|%10d|\t|%10s|\t|%10d|\n",movieArray[j].id , movieArray[j].title , movieArray[j].code);
                            }
                        }
                    }

                }
            }
        break;
        case 2:
            printf("|%10s|\t|%10s|\t|%10s|\t|%15s|\n","id","nombre","codigo","actores");
            for(i = 0 ; i < arrayLenghtActores ; i++)
            {
                for(j = 0 ; j < arrayLenght ; j++)
                {
                    for (k = 0 ; k < arrayLenghtGenero ; k++)
                    {
                        if(movieArray[j].status == OCUPADO && movieArray[j].actor == actores[i].id && movieArray[j].genero == generoArray[k].id)
                        {
                            if(movieArray[j].actor != 6)
                            {
                                printf("|%10d|\t|%10s|\t|%10d|\t|%15s|\n",movieArray[j].id,movieArray[j].title,movieArray[j].code,actores[i].name);
                            }
                        }
                    }

                }




            }
            break;
            case 3:
                printf("|%10s|\t|%10s|\t|%10s|\t|%15s|\n","id","nombre","codigo","actores");
                for(i = 0 ; i < arrayLenghtActores ; i++)
                {
                    for(j = 0 ; j < arrayLenght ; j++)
                    {
                        for (k = 0 ; k < arrayLenghtGenero ; k++)
                        {
                            if(movieArray[j].status == OCUPADO && movieArray[j].actor == actores[i].id && movieArray[j].genero == generoArray[k].id)
                            {
                                if(strcmp(actores[i].country , "EEUU") == 0)
                                {
                                    printf("|%10d|\t|%10s|\t|%10d|\t|%15s|\n",movieArray[j].id,movieArray[j].title,movieArray[j].code,actores[i].name);
                                }
                            }
                        }

                    }




                }
            case 4:
                getStringLetrasNumeros("eligi el pais\n",aux);
                for(i = 0 ; i < arrayLenghtActores ; i++)
                {
                    for(j = 0 ; j < arrayLenght ; j++)
                    {
                        for (k = 0 ; k < arrayLenghtGenero ; k++)
                        {
                            if(movieArray[j].status == OCUPADO && movieArray[j].actor == actores[i].id && movieArray[j].genero == generoArray[k].id)
                            {
                                if(strcmpi(actores[i].country , aux ) == 0)
                                {
                                    printf("|%10d|\t|%10s|\t|%10d|\t|%15s|\n",movieArray[j].id,movieArray[j].title,movieArray[j].code,actores[i].name);
                                    contador ++;
                                }
                            }
                        }

                    }




                }
                if(contador == 0)
                {
                    printf(" no hay peliculas en ese pais\n");
                }
                break;
            case 5:

                for(i = 0 ; i < arrayLenghtActores ; i++)
                {
                    contador = 0;
                    for(j = 0 ; j < arrayLenght ; j++)
                    {
                        for (k = 0 ; k < arrayLenghtGenero ; k++)
                        {
                            if(movieArray[j].status == OCUPADO && movieArray[j].actor == actores[i].id && movieArray[j].genero == generoArray[k].id)
                            {
                                if(movieArray[j].actor != 6)
                                {
                                    contador ++
                                }
                            }
                        }
                    max = contador
                    }
                }
            case 6:
                for(k = 0 ; k < arrayLenghtGenero ; k++)
                {
                    contador = 0;
                    for(j = 0 ; j < arrayLenght ; j++)
                    {
                        for (i = 0 ; i < arrayLenghtActores ; i++)
                        {
                            if(movieArray[j].status == OCUPADO && movieArray[j].genero == generoArray[k].id && movieArray[j].actor == actores[i].id )
                            {
                                    contador ++;
                            }
                        }

                    }
                    printf("%d\n",contador);
                }
                break;
            case 7:
                for(k = 0 ; k < arrayLenghtGenero ; k++)
                {
                    printf("%s ",generoArray[k].name);
                    contador = 0;
                    for(j = 0 ; j < arrayLenght ; j++)
                    {
                        for (i = 0 ; i < arrayLenghtActores ; i++)
                        {
                            if(movieArray[j].status == OCUPADO && movieArray[j].genero == generoArray[k].id && movieArray[j].actor == actores[i].id )
                            {
                                    contador ++;
                            }
                        }

                    }
                    printf("%d\n",contador);
                }
                break;


    }
}
void orderMovie(eMovie  movieArray[],int arrayLenght )
{
    int i;
    int j;
    eMovie auxMovie;
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

