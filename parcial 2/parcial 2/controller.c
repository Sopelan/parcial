#include <stdio.h>
#include <stdlib.h>
#include "bibloteca.h"
#include "empleado.h"
#include "LinkedList.h"
#include "controller.h"

int parser(FILE* fp ,LinkedList* pArrayListEmployee)
{
    char nombres[5][128];
    empleado* aux;
    int tam;
    int i = 0;
    if(fp != NULL)
    {
        while(!feof(fp))
        {
            aux = new_empleado();
            tam = fscanf(fp,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",nombres[0],nombres[1],nombres[2],nombres[3],nombres[4]);
            setId(aux , atoi(nombres[0]));
            setNombre(aux , (nombres[1]));
            setEmpleo(aux , (nombres[2]));
            setEdad(aux , atoi(nombres[3]));
            setHorasTrabajadas(aux , atoi(nombres[4]));
            if(aux != NULL && tam == 5)
            {
                ll_add(pArrayListEmployee , aux);
                i++;
            }
        }
        return i;

    }
    else
        return -1;

}
int cargar(char* path ,LinkedList* pArrayListEmployee)
{
    FILE* fp;
    int tam;
    fp = fopen(path , "r");
    if(fp == NULL)
    {
        printf("no se cargaron los archivo\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        tam = parser(fp , pArrayListEmployee);
        if(tam == -1 || tam == 0)
        {
            printf("no se cargo ningun archivo\n");
            exit(EXIT_FAILURE);
        }
        else
            printf("se cargaron %d empleado\n",tam);
        fclose(fp);
        return 1;
    }
}
int listar(LinkedList* pArrayListEmployee)
{
    int i;
    empleado* aux;
    int len;
    int id;
    char nombre[128];
    int edad;
    char empleo[128];
    int horasTrabajadas;
    int option  = 1;
    char dedicacion[120];
    len = ll_len(pArrayListEmployee);
    ll_map(pArrayListEmployee,laQueMapea(aux));
    ll_sort(pArrayListEmployee,ordenarPorNombre,option);
    printf("\n ordenar por nombre\n");
    printOption(3);
    for(i = 0 ; i < len ; i++)
    {
        aux = new_empleado();
        aux = (empleado*) ll_get(pArrayListEmployee , i);
        ll_map(pArrayListEmployee,laQueMapea(aux));
        getId(aux,&id);
        getNombre(aux,nombre);
        getEdad(aux,&edad);
        getEmpleo(aux, empleo);
        getHorasTrabajadas(aux,&horasTrabajadas);
        getDedicacion(aux,dedicacion);
        printf("|%5d|\t|%10s|\t|%15s|\t|%10d|\t|%10d|\t|%15s|\n",id,nombre,empleo,edad,horasTrabajadas,dedicacion);
    }
    printf("\n.ordenar por dedicacion\n");
    printOption(3);
    ll_sort(pArrayListEmployee,ordenarPorDedicacion,1);
    for(i = 0 ; i < len ; i++)
    {
        aux = new_empleado();
        aux = (empleado*) ll_get(pArrayListEmployee , i);
        ll_map(pArrayListEmployee,laQueMapea(aux));
        getId(aux,&id);
        getNombre(aux,nombre);
        getEdad(aux,&edad);
        getEmpleo(aux, empleo);
        getHorasTrabajadas(aux,&horasTrabajadas);
        getDedicacion(aux,dedicacion);
        printf("|%5d|\t|%10s|\t|%15s|\t|%10d|\t|%10d|\t|%15s|\n",id,nombre,empleo,edad,horasTrabajadas,dedicacion);
    }
}


