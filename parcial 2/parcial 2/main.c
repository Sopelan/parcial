/*
1.Realizar un programa que lea de un archivo .csv los datos de empleados y los guarde de
manera din�mica en un arraylist de entidades eEmpleado (id, nombre,
empleo,edad,horasTrabajadas).
2. Listar todos los empleados ordenados de manera ascendente por nombre.
Nota: Utilizar constructores, Getters y Setter.
3. Luego, deber� cargar su �Dedicaci�n� a cada uno de los empleados le�dos, seg�n las horas
que trabajaron, con el siguiente criterio:
entre 1 y 200 Dedicaci�n �est�ndar�
hasta 300 �sobre la media�
el resto �excesivo�
Para hacer esta operaci�n, se deber� desarrollar la funci�n "map" en la biblioteca LinkedList, la
cual recibe la lista y una funci�n.
int ll_map(LinkedList* lista,int (*pFunc)(void*));
La funci�n map ejecutar� la funci�n recibida como par�metro por cada item de la lista, y le
pasar� en cada llamada, uno de los items.
int laQueMapea(void*)
De esta manera la funci�n pasada como par�metro podr� realizar un c�lculo con el item
recibido, en este caso, calcular el sueldo.
4. Listar los empleados ordenados de manera ascendente por dedicaci�n.
*/
#include <stdio.h>
#include <stdlib.h>
#include "bibloteca.h"
#include "empleado.h"
#include "LinkedList.h"
#include "controller.h"
int main()
{
    int option = 0;
    int flag = 0;
    LinkedList* empleados = ll_newLinkedList();
    while(option != 10)
    {
        option = getValidIntChar("\n1.cargar los datos\n2.listar\n","tiene que ser un numero\n",1,10);
        switch(option)
        {
            case 1:
                if(flag == 0)
                {
                    cargar("datos.csv" , empleados);
                    flag = 1;
                }
                else
                    printOption(2);
                break;

            case 2:
                if(flag == 1)
                    listar(empleados);
                else
                    printOption(1);
                break;
            case 10:
                option = 10;
                break;
            default:
                printf("numero equivocado\n");
                break;

        }
        system("pause");
        system("cls");
    }
    return 0;
}
