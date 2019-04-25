void setBookStatus(book bookArray[],int arrayLenght,int value)
{
    int i;
    for(i = 0 ; i <  arrayLenght ;  i++)
    {
        bookArray[i].status = value;
    }
}
int findBookEmptyPlace(book bookArray[],int arrayLenght)
{
    int i;
    for(i = 0 ; i < arrayLenght ; i++)
    {
        if(bookArray[i].status == LIBRE)
            return i;
    }
    return OCUPADO;
}
int findBookByCode(book bookArray[],int arrayLenght,int code)
{
    int i;
    for(i = 0 ; i < arrayLenght ; i++)
    {
        if(bookArray[i].code == code)
        {
            return i;
        }
        return LIBRE;
    }
}
void orderBookArrayByTitle(book bookArray[],int arrayLenght)
{
    int i;
    int j;
    book auxBook;
    for(i = 0 ; i < arrayLenght -1 ; i++)
    {
        if(bookArray[i].status == LIBRE)
        {
            continue;
        }
        for(j = i + 1 ; j < arrayLenght ; j++)
        {
            if(bookArray[j].status == LIBRE)
            {
                continue;
            }
            if(strcmp(bookArray[i].title , bookArray[j].title) < 0)
            {
                auxBook = bookArray[i];
                bookArray[i] = bookArray[j];
                bookArray[j] = auxBook;
            }
            else if(strcmp(bookArray[i].title , bookArray[j].title) == 0)
            {
                if(bookArray[i].code < bookArray[j].code)
                {
                    auxBook = bookArray[i];
                    bookArray[i] = bookArray[j];
                    bookArray[j] = auxBook;
                }
            }
        }
    }
}

void setBook(book bookArray[],int freePlaceIndex, int codeAux,char titleAux[], int authorIdAux,int stockAux)
{
    bookArray[freePlaceIndex].code = codeAux;
    strcpy(bookArray[freePlaceIndex].title,titleAux);
    bookArray[freePlaceIndex].authorId = authorIdAux;
    bookArray[freePlaceIndex].stock = stockAux;
    bookArray[freePlaceIndex].status = OCUPADO;
}
void showBookArray(book bookArray[],int arrayLenght)
{
    int i;
    printf("|%5s|\t|%10s|\t|%20s|\t|%5s|\n","codigo","id del autor","titulo","stock");
    for(i = 0 ; i < arrayLenght ; i++)
    {
        if(bookArray[i].status == OCUPADO)
            printf("|%5d|\t|%10d|\t|%20s|\t|%5d|\n",bookArray[i].code,bookArray[i].authorId,bookArray[i].title,bookArray[i].stock);
    }
}
void setAuthorStatus(author authorArray[],int arrayLenght,int value)
{
    int i;
    for(i = 0 ; i <  arrayLenght ;  i++)
    {
        authorArray[i].status = value;
    }
}
int findAuthorEmptyPlace(author authorArray[],int arrayLenght)
{
    int i;
    for(i = 0 ; i < arrayLenght ; i++)
    {
        if(authorArray[i].status == LIBRE)
            return i;
    }
    return OCUPADO;
}
int findAuthorById(author authorArray[],int arrayLenght,int authorIdAux)
{
    int i;
    for(i = 0 ; i < arrayLenght ; i++)
    {
        if(authorArray[i].authorId == authorIdAux)
        {
            return i;
        }
        return -3;
    }
}
void setAuthor(author authorArray[],int freePlaceIndex, int authorIdAux,char nameAux[],char lastNameAux[])
{
    authorArray[freePlaceIndex].authorId = authorIdAux;
    strcpy(authorArray[freePlaceIndex].name , nameAux);
    strcpy(authorArray[freePlaceIndex].lastName , lastNameAux);
    authorArray[freePlaceIndex].status = OCUPADO;
}
void showAuthorArray(author authorArray[],int arrayLenght)
{
    int i;
    printf("|%15s|\t|%15s|\t|%10s|\n","apelido","nombre","id");
    for(i = 0 ; i < arrayLenght ; i++)
    {
        if(authorArray[i].status == OCUPADO)
            printf("|%15s|\t|%15s|\t|%10d|\n",authorArray[i].lastName,authorArray[i].name,authorArray[i].authorId);
    }
}
void showBookAuthorArray(book bookArray[],int arrayLenght,author authorArray[],int authorArrayLenght)
{
    int i;
    int authorIdAux;
    char auxAuthor[50];
    printf("|%12s|\t|%12s|\t|%12s|\t|%12s|\n","codigo","titulo del libro","autor","stock");
    for(i = 0 ; i < arrayLenght; i++)
    {
        if(bookArray[i].status == OCUPADO)
        {
            authorIdAux = findAuthorById(authorArray , authorArrayLenght , bookArray[i].authorId);
            if(authorIdAux != -3)
            {
                strcpy(auxAuthor , authorArray[authorIdAux].lastName);
            }
            else
            {
                sprintf(auxAuthor , "? (id:%d)",bookArray[i].authorId);
            }
            printf("|%12d|\t|%12s|\t|%12s|\t|%12d|\n",bookArray[i].code,bookArray[i].title,auxAuthor,bookArray[i].stock);
        }

    }

}

