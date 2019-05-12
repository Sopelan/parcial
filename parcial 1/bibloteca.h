#include <string.h>
#include "time.h"
int getInt(char mensaje[]);
float getfloat(char mensaje[]);
char getchart(char mensaje[]);
char getNumeroAleatorio(int desde , int hasta , int iniciar );
int soloNumeros(char str[]);
int soloLetras(char str[]);
int alfanumericos(char str[]);
int telefono(char str[]);
void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumero(char mensaje[],char input[]);
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
void getValidString(char requestMessage[],char errorMessage[], char input[]);
void cleanStdin(void);
int codigoNumeros(char stra[]);
int getValidCodigoInt(char requestMessage[]);
int alfanumericostitulo(char str[]);
int getStringLetrasNumeros(char mensaje[],char input[]);
void getValidStringTitulo(char requestMessage[],char errorMessage[], char input[]);
int codigoMayor(char mensaje[], int valor);
#include "bibloteca.c"
