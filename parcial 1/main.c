/**************************************************
Desarrollar en ANSI C:
 Se desea construir una aplicación capaz de almacenar y administrar las fichas técnicas de
películas. De cada película, se necesita un identificador unívoco, su código de película ,su
título, fecha de estreno, genero (accion , comedia ,terror y otro) y un actor
principal(estructura). De los 5 actores se almacena: el id, el nombre y su país de origen.
estos son:
1- julieta roberto , EEUU
2- Roberto deniro, EEUU
3- Richar darin,Argentina
4-tita merelo,Argentina
5 -sandro, Argentina
, el programa solo tiene capacidad para almacenar 1 solo actor principal por película.
Crear un menú de opciones para que el usuario pueda interactuar con:
Primera parte
1. ALTAS PELÍCULAS: Se ingresan los datos de una sola película. El id deberá
generarse de manera automática a partir del número 1000. Realizar las validaciones:
a) el id es incremental.
b) código: debe ser de tres cifras sin ceros a la izquierda
c) título : no puede ser solo un número , debe tener letras.
d) el actor debe ser uno existente,
2. LISTAR:
a) listar los datos de Películas sin actores
b) listar los datos de Películas con actores
Nota 1: Se deberá desarrollar una biblioteca para cada una de las entidades involucradas en el
dominio. Junto a las bibliotecas de funciones propias (a criterio del alumno).
Nota 2: El código deberá tener comentarios con la documentación de cada una de las funciones y
respetar las reglas de estilo de la cátedra.
Nota 3: Realizar todas las validaciones necesarias tanto para los datos como para solicitar
conformidad al usuario.
Nota 4: El docente podrá solicitar, al momento de la corrección, agregar cualquier detalle que
considere necesario como por ejemplo cuestiones de estética del programa.
#include <stdio.h>
#include <stdlib.h>
**********************************************************************************/
/**
Necesidad:
Se desea construir una aplicación capaz de almacenar y administrar las fichas técnicas de
películas. De cada película, se necesita un identificador unívoco, su código de película ,su
título, año de estreno, genero (accion , comedia ,terror y otro) y un actor
principal(estructura). De los 5 actores se almacena: el id, el nombre y su país de origen.
estos son:
1- Julieta roberto , EEUU
2- Richar darin,Argentina
3- Nicole Kidman, Australiana
4- Tita merello,Argentina
5- Natalia Oreiro, Uruguay
las películas son :( se deben agregar los atributos faltantes)
1,999,terminator ,1,acción
2,666,thor ,5,acción
3,555,it ,4,terror
4,777,gladiador ,4,romántica
, el programa solo tiene capacidad para almacenar 1 solo actor principal por película.
Crear un menú de opciones para que el usuario pueda interactuar con:
Primera parte
1. Todas las películas con género y actor.
2. Películas cuya nacionalidad del actor sea EEUU

 */

#define QTYG 13
#define QTYAC 6
#define QTY 300
#define LIBRE -2
#define OCUPADO -3
#include <stdio.h>
#include <stdlib.h>
#include "bibloteca.h"
#include "actores.h"
#include "genero.h"
#include "peliculas.h"



int main()
{
    int option = 1;
    int opcion;
    int emptyPlace;
    int findPLace;
    eMovie movieArray[QTY];
    eMovie auxMovie;
    eActores actores[QTYAC];
    eGenero genero[QTYG];
    setActores(actores , 0 , 1 , "julieta roberto" , "EEUU");
    setActores(actores , 1 , 2 , "Roberto deniro" , "EEUU");
    setActores(actores , 2 , 3 , "Nicole Kidman" , "Argentina");
    setActores(actores , 3 , 4 , "tita merelo" , "Argentina");
    setActores(actores , 4 , 5 , "Natalia Oreiro" , "Uruguay");
    setActores(actores , 5 , 6 , "","");
    setGenero(genero , 0 , "drama" );
    setGenero(genero , 1 , "Ciencia Ficcion");
    setGenero(genero , 2 , "Accion");
    setGenero(genero , 3 , "Terror");
    setGenero(genero , 4 , "Comedia" );
    setGenero(genero , 5 , "Aventuras");
    setGenero(genero , 6 , "Animacion");
    setGenero(genero , 7 , "Romance");
    setGenero(genero , 8 , "Intriga");
    setGenero(genero , 9 , "Belico");
    setGenero(genero , 10 , "Musical");
    setGenero(genero , 11 , "Historico");
    setGenero(genero , 12 , "Western");
    setGeneroStatus(genero , QTYG);
    setMovieStatus(movieArray , QTY , LIBRE);
    setMovie(movieArray , 0 , 999 , "terminator" , 1 , 1986 , 2);
    setMovie(movieArray , 1 , 666 , "thor" ,5 , 2011 , 2 );
    setMovie(movieArray , 2 , 555 , "it" , 4 ,  2017, 3 );
    setMovie(movieArray , 3 , 777, "gladiador" ,4 , 2000  ,7);
    while (option != 5)
    {
        system("cls");
        option = getValidInt("\n1.alta\n2.baja\n3.modificar\n4.listar\n5.salir\n","tiene que contener numeros\n",1,5);
        switch(option)
        {
            case 1:
                system("cls");
                printf("alta\n");
                emptyPlace = findMovieEmptyPlace(movieArray , QTY);
                if(emptyPlace == OCUPADO)
                {
                    printf("no quedan lugares\n");
                    break;
                }
                auxMovie.code = codigoMayor("cual es el codigo\n",1000);
                if(auxMovie.code == 0)
                    break;
                if(!getStringLetrasNumeros("cual es el titulo de la pelicula\n",auxMovie.title))
                    break;
                auxMovie.actor = getValidInt("\nelija el actor\n\n1.Julieta Roberto , EEUU\n2.Roberto Deniro, EEUU\n3.Richar Darin,Argentina\n4.Tita Merelo,Argentina\n5.Sandro, Argentina\n6.sin autor\n","tiene que ser un numero\n",1,6);
                if(auxMovie.actor == 0)
                    break;
                auxMovie.fechaDeEstreno = getValidInt("cual es su anio de estreno\n","desbes ser un  numero\n",1894 , 2025);
                if(auxMovie.fechaDeEstreno == 0)
                    break;
                showGenerosArray(genero , QTYG);
                auxMovie.genero = getValidInt("elija su genero\n","deber ser un numero",1,QTYG + 1);
                if(auxMovie.genero == 0 )
                    break;

                setMovie(movieArray , emptyPlace  , auxMovie.code, auxMovie.title ,auxMovie.actor ,auxMovie.fechaDeEstreno , auxMovie.genero);
                break;
            case 2:
                system("cls");
                printf("baja\n");
                auxMovie.code = codigoMayor("cual es el codigo\n",1000);
                if(auxMovie.code == 0)
                    break;
                findPLace = findMovieByCode(movieArray ,QTY ,auxMovie.code);
                if(findPLace == LIBRE)
                {
                    printf("no existe\n");
                    break;
                }
                movieArray[findPLace].status = LIBRE;
                break;
            case 3:
                system("cls");
                printf("modificar\n");
                auxMovie.code = codigoMayor("cual es el codigo\n",1000);
                if(auxMovie.code == 0)
                    break;
                findPLace = findMovieByCode(movieArray ,QTY ,auxMovie.code);
                if(findPLace == LIBRE)
                {
                    printf("no existe\n");
                    break;
                }
                opcion = getValidInt("que queres modificar\n1.titulo\n2.actor\n3.fecha de estreno\n","tiene que ser numero\n",1,3);
                switch(opcion)
                {
                    case 1:
                        if(!getStringLetrasNumeros("cual es el titulo de la pelicula\n",auxMovie.title))
                            break;
                        strcpy(movieArray[findPLace].title , auxMovie.title);
                        break;
                    case 2:
                        auxMovie.actor = getValidInt("\nelija el actor\n\n1.Julieta Roberto , EEUU\n2.Roberto Deniro, EEUU\n3.Richar Darin,Argentina\n4.Tita Merelo,Argentina\n5.Sandro, Argentina\n6.sin autor\n","tiene que ser un numero\n",1,6);
                        if(auxMovie.actor == 0)
                            break;
                        movieArray[findPLace].actor = auxMovie.actor;
                        break;
                    case 3:
                        auxMovie.fechaDeEstreno = getValidInt("cual es su anio de estreno\n","desbes ser un  numero\n",1894 , 2025);
                        if(auxMovie.fechaDeEstreno == 0)
                            break;
                        movieArray[findPLace].fechaDeEstreno = auxMovie.fechaDeEstreno;
                        break;
                }
                break;
            case 4:
                system("cls");
                printf("listar\n");
                opcion = getValidInt("elija que mostrar\n1.mostrar ABM movie\n2.mostrar ABM actores\n","tiene que ser un numero",1,2);
                if(opcion == 0)
                    break;
                switch(opcion)
                {
                    case 1:
                        orderMovie(movieArray,QTY );
                        showMovieArray(  movieArray,QTY , actores , QTYAC , genero , QTYG ) ;
                        break;
                    case 2:
                        orderActor(actores , QTYAC - 1 );
                        showActoresArray(actores , QTYAC - 1);
                        break;
                }

                break;

            case 5:
                system("cls");
                printf("salir\n");
                break;
        }
    system("pause");
    }
    return 0;
}
