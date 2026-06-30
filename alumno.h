#ifndef ALUMNO_H
#define ALUMNO_H

#include <stdio.h>

typedef struct Direccion
{
    char callePrincipal[50];
    int numeroCasa;
    char calleSecundaria[50];
} Direccion;

typedef struct
{
    char nombre[50];
    Direccion direccion;
    int edad;
} Alumno;

#endif