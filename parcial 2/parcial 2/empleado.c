#include <stdio.h>
#include <stdlib.h>
#include "bibloteca.h"
#include "empleado.h"
empleado* new_empleado()
{
    empleado* retorno =(empleado*) calloc(sizeof(empleado),1);
    return retorno;
}
int setId(empleado* aux , int id)
{
    aux->id = id;
    return 1;
}
int setNombre(empleado* aux , char* nombre)
{
    strcpy(aux->nombre , nombre);
    return 1;
}
int setEdad(empleado* aux , int edad)
{
    aux->edad = edad;
    return 1;
}
int setEmpleo(empleado* aux ,char* empleo)
{
    strcpy(aux->empleo, empleo);
    return 1;
}
int setHorasTrabajadas(empleado* aux , int horasTrabajadas)
{
    aux->horasTrabajadas = horasTrabajadas;
    return 1;
}
int getId(empleado* aux , int* id)
{
    *id = aux->id;
    return 1;
}
int getNombre(empleado* aux , char* nombre)
{
    if(aux != NULL)
    {
        strcpy(nombre , aux->nombre);
        return 1;
    }
    return 0;
}
int getEdad(empleado* aux , int* edad)
{
    *edad = aux->edad;
    return 1;
}
int getEmpleo(empleado* aux ,char* empleo)
{
    strcpy(empleo , aux->empleo);
    return 1;
}
int getHorasTrabajadas(empleado* aux , int* horasTrabajadas)
{
    *horasTrabajadas = aux->horasTrabajadas;
    return 1;
}
int setDedicacion(empleado* aux , char* dedicacion)
{
    strcpy(aux->dedicacion,dedicacion);
    return 1;
}
int getDedicacion(empleado* aux , char* dedicacion)
{
    strcpy(dedicacion , aux->dedicacion);
    return 1;
}
void printOption(int option)
{
    switch(option)
    {
        case 1:
            printf("no se cargaron los archivos\n");
            break;
        case 2:
            printf("ya se cargaron los archivos\n");
            break;
        case 3:
            printf("|%5s|\t|%10s|\t|%15s|\t|%10s|\t|%10s|\t|%10s|\n","id","nombre","empleo","edad","horas trabajadas", "dedicacion");
            break;
    }

}
int ordenarPorNombre(void* emp1 , void* emp2)
{
    int ret;
    empleado* aux = (empleado*)emp1;
    empleado* auxEmp = (empleado*)emp2;

    char nombre1[128];
    char nombre2[128];
    getNombre(aux , nombre1);
    getNombre(auxEmp , nombre2);
    ret = stricmp(nombre1 , nombre2);

    return ret;
}
int ordenarPorDedicacion(void* emp1 , void* emp2)
{
    int ret;
    empleado* aux = (empleado*)emp1;
    empleado* auxEmp = (empleado*)emp2;

    char nombre1[128];
    char nombre2[128];
    getDedicacion(aux , nombre1);
    getDedicacion(auxEmp , nombre2);
    ret = stricmp(nombre1 , nombre2);

    return ret;
}
int laQueMapea(void* emp)
{
    int retorno= -1;
    if(emp != NULL)
    {
        empleado* emp2 = (empleado*) emp;
        int horasTrabajadas;
        getHorasTrabajadas(emp2 , &horasTrabajadas);
        if(horasTrabajadas <= 200 && horasTrabajadas > 1)
            setDedicacion(emp2,"estandar");
        if(horasTrabajadas > 200 && horasTrabajadas <= 300)
            setDedicacion(emp2,"sobre la media");
        if(horasTrabajadas > 300)
            setDedicacion(emp2,"excesivo");

        retorno= 0;
    }
    return retorno;
}


