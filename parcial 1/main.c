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
#define QTY 300
#define LIBRE -2
#define OCUPADO -3
#include <stdio.h>
#include <stdlib.h>
#include "bibloteca.h"
#include "peliculas.h"
int main()
{
    int option = 1;
    int opcion = 1;
    int emptyPlace;
    movie movieArray[QTY];
    movie auxMovie;
    setMovieStatus(movieArray , QTY , LIBRE);
    while (option != 3)
    {
        system("cls");
        option = getValidInt("\n1.alta\n2.listar\n3.salir","tiene que contener numeros\n",1,3);
        switch(option)
        {
            case 1:
                system("cls");
                printf("alta\n");
                emptyPlace = findMovieEmptyPlace(movieArray , QTY);
                if(emptyPlace == OCUPADO)
                {
                    printf("no quedan lugares\n");
                }
                auxMovie.code  = getValidCodigoInt("cual es el codigo\n");
                if(auxMovie.code == 0)
                {
                    system("pause");
                    break;
                }
                getStringLetrasNumeros("cual es el titulo de la pelicula\n",auxMovie.title);
                if(auxMovie.title == 0)
                {
                    system("pause");
                    break;
                }
                system("pause");
                opcion = getValidInt("\n1.Julieta Roberto , EEUU\n2.Roberto Deniro, EEUU\n3.Richar Darin,Argentina\n4.Tita Merelo,Argentina\n5.Sandro, Argentina\n6.sin autor\n","tiene que ser un numero\n",1,6);
                setActor(auxMovie , opcion);
                setMovie(movieArray , emptyPlace  , auxMovie.code, auxMovie.title ,auxMovie.actor);
                break;
            case 2:
                system("cls");
                printf("listar\n");

                break;
            case 3:
                system("cls");
                printf("salir\n");
                break;
        }

    }
    return 0;
}
