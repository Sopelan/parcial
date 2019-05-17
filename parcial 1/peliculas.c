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
    int min = QTY;
    opcion = getValidInt("que queres ver?\n1.las peliculas sin actores\n2.las peliculas con actores\n3.Todas las películas con género y actor\n4.peliculas con autores de EEUU\n5.filtrar por nacionalidad\n6.genero\n7.cantidad de peliculas por genero\n8.Actores que más películas protagonizaron\n9.Género/s con menos películas\n10.Actor/es que no trabajaron en ninguna película\n","tiene que ser un numero\n",1,10);
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
            printf("|%10s|\t|%10s|\t|%10s|\t|%15s|\t|%15s|\n","id","nombre","codigo","actores","genero");
            for(i = 0 ; i < arrayLenghtActores ; i++)
            {
                for(j = 0 ; j < arrayLenght ; j++)
                {
                    for (k = 0 ; k < arrayLenghtGenero ; k++)
                    {
                        if(movieArray[j].status == OCUPADO && movieArray[j].actor == actores[i].id && movieArray[j].genero == generoArray[k].id)
                        {
                            printf("|%10d|\t|%10s|\t|%10d|\t|%15s|\t|%15s|\n",movieArray[j].id,movieArray[j].title,movieArray[j].code,actores[i].name,generoArray[k].name);
                        }
                    }

                }




            }
            break;
            case 4:
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
            break;
            case 5:
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

            case 6:
                for(k = 0 ; k < arrayLenghtGenero ; k++)
                {
                    printf("\n%s\n",generoArray[k].name);
                    for(j = 0 ; j < arrayLenght ; j++)
                    {
                        for (i = 0 ; i < arrayLenghtActores ; i++)
                        {
                            if(movieArray[j].status == OCUPADO && movieArray[j].genero == generoArray[k].id && movieArray[j].actor == actores[i].id )
                            {
                                printf("%s\n",movieArray[j].title);
                            }
                        }

                    }
                }
                break;
            case 7:
                for(k = 0 ; k < arrayLenghtGenero ; k++)
                {
                    printf("%s: ",generoArray[k].name);
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
            case 8:
                printf("Actores que más películas protagonizaron\n");
                for(i = 0 ; i < arrayLenghtActores ; i++)
                {
                    contador = 0;
                    for(j = 0 ; j < arrayLenght ; j++)
                    {
                        for (k = 0 ; k < arrayLenghtGenero ; k++)
                        {
                            if(movieArray[j].status == OCUPADO && movieArray[j].actor == actores[i].id && movieArray[j].genero == generoArray[k].id)
                            {
                                contador ++;
                            }
                        }


                    }
                    if(max < contador)
                    {
                        max = contador;
                    }
               }
               for(i = 0 ; i < arrayLenghtActores ; i++)
                {
                    contador = 0;
                    for(j = 0 ; j < arrayLenght ; j++)
                    {
                        for (k = 0 ; k < arrayLenghtGenero ; k++)
                        {
                            if(movieArray[j].status == OCUPADO && movieArray[j].actor == actores[i].id && movieArray[j].genero == generoArray[k].id)
                            {
                                contador ++;
                            }
                        }


                    }
                    if(max == contador)
                    {
                        printf("%s\n",actores[i].name);
                    }
               }
                break;
            case 9:
                printf("Género/s con menos películas\n");
                min = QTY;
                for(k = 0 ; k < arrayLenghtGenero ; k++)
                {
                    contador = 0;
                    for (i = 0 ; i < arrayLenghtActores ; i++)
                    {
                        for(j = 0 ; j < arrayLenght ; j++)
                        {
                            if(movieArray[j].status == OCUPADO && movieArray[j].genero == generoArray[k].id && movieArray[j].actor == actores[i].id )
                            {
                                    contador ++;
                            }
                        }

                    }
                    if(min > contador && contador > 0)
                    {
                        min = contador;

                    }
                }
                for(k = 0 ; k < arrayLenghtGenero ; k++)
                {
                    contador = 0;
                    for (i = 0 ; i < arrayLenghtActores ; i++)
                    {
                        for(j = 0 ; j < arrayLenght ; j++)
                        {
                            if(movieArray[j].status == OCUPADO && movieArray[j].genero == generoArray[k].id && movieArray[j].actor == actores[i].id )
                            {
                                    contador ++;
                            }

                        }

                    }
                    if(contador == min)
                    {
                        printf("%s\n", generoArray[k].name);
                    }
                }
                break;
            case 10:
                printf("actores que trabajaron en ninguna son\n");
                for(i = 0 ; i < arrayLenghtActores ; i++)
                {
                    contador = 0;
                    for (k = 0 ; k < arrayLenghtGenero ; k++)
                    {
                        for(j = 0 ; j < arrayLenght ; j++)
                        {
                            if(movieArray[j].status == OCUPADO && movieArray[j].actor == actores[i].id && movieArray[j].genero == generoArray[k].id)
                            {
                                if(movieArray[j].actor != 6)
                                    contador ++;
                            }
                        }
                    }
                    if( contador == 0)
                    {
                        printf("%s\n",actores[i].name);
                    }
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
            if(movieArray[i].status == OCUPADO && movieArray[j].status == OCUPADO)
            {
                if( movieArray[i].fechaDeEstreno < movieArray[j].fechaDeEstreno)
                {
                    auxMovie = movieArray[i];
                    movieArray[i] = movieArray[j];
                    movieArray[j] = auxMovie;
                }
                else if(movieArray[i].fechaDeEstreno == movieArray[j].fechaDeEstreno)
                {
                    if(strcmpi(movieArray[i].title , movieArray[j].title ) < 0)
                    {
                        auxMovie = movieArray[i];
                        movieArray[i] = movieArray[j];
                        movieArray[j] = auxMovie;
                    }
                }


            }

        }
    }

}

