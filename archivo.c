#include <stdio.h>
#include "archivo.h"

// Mostrar arreglo de alumnos en pantalla
void mostrarAlumno(Alumno *a, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("NOMBRE: %s\n", a[i].nombre);
        printf("DIRECCION: %s %d %s\n",
               a[i].direccion.callePrincipal,
               a[i].direccion.numeroCasa,
               a[i].direccion.calleSecundaria);
        printf("EDAD: %d\n\n", a[i].edad);
    }
}

// Leer archivo CSV
void leerArchivoCSV()
{
    FILE *archivo = fopen("alumnos.csv", "r");

    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    Alumno alumno;

    while (fscanf(archivo,
                  " %49[^;];%49[^;];%d;%49[^;];%d",
                  alumno.nombre,
                  alumno.direccion.callePrincipal,
                  &alumno.direccion.numeroCasa,
                  alumno.direccion.calleSecundaria,
                  &alumno.edad) == 5)
    {
        printf("NOMBRE: %s\n", alumno.nombre);
        printf("DIRECCION: %s %d %s\n",
               alumno.direccion.callePrincipal,
               alumno.direccion.numeroCasa,
               alumno.direccion.calleSecundaria);
        printf("EDAD: %d\n\n", alumno.edad);
    }

    fclose(archivo);
}