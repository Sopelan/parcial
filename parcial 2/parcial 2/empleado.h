typedef struct
{
    int id;
    char nombre[128];
    int edad;
    char empleo[128];
    int horasTrabajadas;
    char dedicacion[128];
}empleado;
empleado* new_empleado();
void printOption(int option);
int laQueMapea(void*);
int ordenarPorNombre(void* emp1 , void* emp2);
int ordenarPorDedicacion(void* emp1 , void* emp2);
int setId(empleado* aux , int id);
int getId(empleado* aux , int* id);
int setNombre(empleado* aux , char* nombre);
int getNombre(empleado* aux , char* nombre);
int setEdad(empleado* aux , int edad);
int getEdad(empleado* aux , int* edad);
int setEmpleo(empleado* aux ,char* empleo);
int getEmpleo(empleado* aux ,char* empleo);
int setHorasTrabajadas(empleado* aux , int horasTrabajadas);
int getHorasTrabajadas(empleado* aux , int* horasTrabajadas);
int setDedicacion(empleado* aux , char* dedicacion);
int getDedicacion(empleado* aux , char* dedicacion);

