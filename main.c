#include <stdio.h>
#include <string.h>

#include "alumno.h"
#include "archivo.h"
#include "busqueda.h"

int main()
{
    Alumno p1[2];

    strcpy(p1[0].nombre, "Juanito");
    strcpy(p1[0].direccion.callePrincipal, "Av. Prensa");
    p1[0].direccion.numeroCasa = 123;
    strcpy(p1[0].direccion.calleSecundaria, "Florida");
    p1[0].edad = 20;

    strcpy(p1[1].nombre, "Maria");
    strcpy(p1[1].direccion.callePrincipal, "Av. Galo Plaza");
    p1[1].direccion.numeroCasa = 456;
    strcpy(p1[1].direccion.calleSecundaria, "Borja");
    p1[1].edad = 22;

    guardarArchivo(p1, 2);

    leerArchivoCSV();

    char nombreBuscado[50];

    printf("\nIngrese el nombre a buscar: ");
    fgets(nombreBuscado, sizeof(nombreBuscado), stdin);
    nombreBuscado[strcspn(nombreBuscado, "\n")] = '\0';

    buscarAlumno(nombreBuscado);

    return 0;
}
 