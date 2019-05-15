void setGenero(eGenero genero[],int freePlace , char auxName[])
{
    strcpy(genero[freePlace].name ,auxName);
}
void setGeneroStatus(eGenero generoArray[],int arrayLenght)
{
        int i;
        for(i = 0 ; i <  arrayLenght ;  i++)
        {
            generoArray[i].id = i + 1;
        }
}
void showGenerosArray(eGenero genero[] , int arrayLenght)
{
    int i;
    int j;
    char auxName[128];
    for(i = 0 ; i < arrayLenght - 1 ; i++)
    {
        for(j = i + 1 ; j < arrayLenght ; j++)
        {
            if(stricmp(genero[i].name , genero[j].name) > 0)
            {
                strcpy(auxName , genero[i].name);
                strcpy(genero[i].name , genero[j].name);
                strcpy(genero[j].name , auxName);
            }
        }
    }
    printf("|%5s|\t|%15s|\n","ID","nombre");
    for(i = 0 ; i < arrayLenght ; i++)
    {
        printf("|%5d|\t|%15s|\n",genero[i].id, genero[i].name);
    }
}
