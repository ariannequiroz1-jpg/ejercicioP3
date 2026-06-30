#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "busqueda.h"

void convertirMinusculas(char *cad)
{
    for (int i = 0; cad[i] != '\0'; i++)
    {
        cad[i] = tolower(cad[i]);
    }
}

void buscarAlumno(char *nombreBuscado)
{
    FILE *archivo = fopen("alumnos.csv", "r");

    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    Alumno alumno;
    int encontrado = 0;

    char buscado[50];
    strcpy(buscado, nombreBuscado);
    convertirMinusculas(buscado);

    while (fscanf(archivo,
                  " %49[^;];%49[^;];%d;%49[^;];%d",
                  alumno.nombre,
                  alumno.direccion.callePrincipal,
                  &alumno.direccion.numeroCasa,
                  alumno.direccion.calleSecundaria,
                  &alumno.edad) == 5)
    {
        char temp[50];
        strcpy(temp, alumno.nombre);
        convertirMinusculas(temp);

        if (strcmp(temp, buscado) == 0)
        {
            printf("\n===== ALUMNO ENCONTRADO =====\n");
            printf("NOMBRE: %s\n", alumno.nombre);
            printf("DIRECCION: %s %d %s\n",
                   alumno.direccion.callePrincipal,
                   alumno.direccion.numeroCasa,
                   alumno.direccion.calleSecundaria);
            printf("EDAD: %d\n", alumno.edad);

            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("\nAlumno no encontrado.\n");
    }

    fclose(archivo);
}