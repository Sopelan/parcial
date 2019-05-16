int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}
float getfloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}
char getchart(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}
char getNumeroAleatorio(int desde , int hasta , int iniciar )
{
    if(iniciar)
        srand(time(NULL));
    return desde+(rand()%(hasta + 1 - desde));
}
int soloNumeros(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9' )
            return 0;
        i++;
    }
    return 1;
}
int soloLetras(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] < 'a' || str[i] > 'z' ) && (str[i] < 'A' || str[i] > 'Z' ) && str[i] != ' ')
            return 0;
        i++;
    }
    return 1;
}
int alfanumericos(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] < 'a' || str[i] > 'z' ) && (str[i] < 'A' || str[i] > 'Z' ) && (str[i] < '0' || str[i] > '9' ) )
            return 0;
        i++;
    }
    return 1;
}
int telefono(char str[])
{
    int i = 0;
    int contadorDeGuiones = 0;
    while(str[i] != '\0')
    {
        if((str[i] < '0' || str[i] > '9')&&(str[i] != '-'))
            return 0;
        if(str[i] == '-')
            contadorDeGuiones++;
        i++;
    }
    if(contadorDeGuiones == 1 && i == 9)
    {
        return 1;
    }
    return 0;
}
void getString(char mensaje[] , char input[] )
{
    printf("%s" , mensaje );
    gets(input);
}
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(soloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
int getStringNumero(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(soloNumeros(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
void cleanStdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    int input;
    char inputAux[128];


    while(1)
    {
            if(!getStringNumero(requestMessage,inputAux))
        {
            printf("%s",errorMessage);
            continue;
        }
        input = atoi(inputAux);
        if(input >= lowLimit && input <= hiLimit)
        {
                return input;
        }
        else
        {
            printf("tiene que estar entre %d y %d\n",lowLimit,hiLimit);
            continue;
        }
    }



}
void getValidString(char requestMessage[],char errorMessage[], char input[])
{
    while(1)
    {
        if(!getStringLetras(requestMessage,input))
        {
            printf("%s",errorMessage);
            continue;
        }
        else
        {
            break;
        }
    }
}
int codigoNumeros(char stra[])
{
    int i = 0;
    int j = 0;
    int cantidadCeros = 0;
    int last;
    while(stra[i] != '\0')
    {
        if(stra[i] < '0' || stra[i] > '9' )

        {
            printf("tiene que contener numeros\n");
            return 0;
        }
        i++;
        last = i;
    }
    if(last < 3)
    {
       printf("tiene que contener por lo menos 3 cifras\n");
       return 0;
    }

    while(stra[j] != '\0' && j < 3)
    {
        if(stra[j] == '0')
        {
            cantidadCeros = cantidadCeros + 1;
        }


        if(cantidadCeros  == 3)
        {
            printf("no tiene que contener ceros a la izquierda\n");
            return 0;
        }
        j++;

    }
        return 1;
}
int getStringCodigo(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(codigoNumeros(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
int getValidCodigoInt(char requestMessage[])
{
    int input;
    char inputAux[128];

        if(!getStringCodigo(requestMessage,inputAux))
        {
            return 0;
        }
        input = atoi(inputAux);
        return input;

}
int alfanumericostitulo(char str[])
{
    int i = 0;
    int j = 0;
    while(str[i] != '\0')
    {
        if((str[i] >= 'a' || str[i] <= 'z' ) || (str[i] >= 'A' || str[i] <= 'Z' ) || (str[i] >= '0' || str[i] <= '9' ) || str[i] == ' ')
        {

        }
        else
        {
            printf("tiene que contener letra y numeros\n");
            return 0;
        }


        if(str[i] >= '0' && str[i] <= '9' )
        {
            j++;
        }
        i++;
    }
    if(i == j)
    {
        printf("debe terner por lo menos alguna letra\n");
        return 0;
    }
    return 1;
}
int getStringLetrasNumeros(char mensaje[],char input[])
{
    char aux[256];
    while(1)
    {
        getString(mensaje,aux);
        if(alfanumericostitulo(aux))
        {
            strcpy(input,aux);
            return 1;
        }
        else
        {
            continue;
        }
    }

    return 0;
}
int codigoMayor(char mensaje[], int valor )
{
    int num;
    char aux[128];
    if(!getStringNumero(mensaje, aux))
    {
        printf("tiene que ser un numero\n");
        return 0;
    }
    num = atoi(aux);
    if(num < valor)
    {
        printf("tiene que ser un numero mas grande que %d\n",valor);
        return 0;

    }

    return num;



}
int getValidIntChar(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    int input;
    char inputAux[128];
    if(!getStringNumero(requestMessage,inputAux))
    {
        printf("%s",errorMessage);
        return 0;
        }
        input = atoi(inputAux);
        if(input >= lowLimit && input <= hiLimit)
        {
                return input;
        }
        else
        {
            printf("tiene que estar entre %d y %d\n",lowLimit,hiLimit);
            return 0;
        }
}

