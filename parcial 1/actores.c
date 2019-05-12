void setActores(eActores actores[],int freePlace , int auxId, char auxName[] , char auxCountry[])
{
    actores[freePlace].id = auxId;
    strcpy(actores[freePlace].name ,auxName);
    strcpy(actores[freePlace].country , auxCountry);

}
void orderActor(eActores actorArray[],int arrayLenght )
{
    int i;
    int j;
    eActores auxactor;
    for(i = 0 ; i < arrayLenght - 1 ; i++)
    {
        for(j = i + 1 ; j < arrayLenght ; j++)
        {
            if(stricmp(actorArray[i].country , actorArray[j].country) > 0)
            {
                auxactor = actorArray[i];
                actorArray[i] = actorArray[j];
                actorArray[j] = auxactor;
            }
            else if(stricmp(actorArray[i].country , actorArray[j].country) == 0)
            {
                if(stricmp(actorArray[i].name , actorArray[j].name) > 0 )
                {
                    auxactor = actorArray[i];
                    actorArray[i] = actorArray[j];
                    actorArray[j] = auxactor;
                }
            }
        }
    }

}
void showActoresArray(eActores actores[] , int arrayLenght)
{
    int i;
    printf("|%5s|\t|%15s|\t|%20s|\n","ID","nombre","pais de origen");
    for(i = 0 ; i < arrayLenght ; i++)
    {
        printf("|%5d|\t|%15s|\t|%20s|\n",actores[i].id,actores[i].name,actores[i].country);
    }

}
