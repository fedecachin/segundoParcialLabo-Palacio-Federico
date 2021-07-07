#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parse.h"
#include "pais.h"

int menu();

int main()
{
    char rta = 'n';
    int bandera = 0;

    LinkedList* lista = ll_newLinkedList();
    LinkedList* mejorSegundaDosis = ll_newLinkedList;
    LinkedList* peorDosis = ll_newLinkedList;



    do
    {
        switch(menu())
        {

        case 1:

            cargarArchivoTxt("vacunas.csv", lista);
            bandera = 1;

            break;
        case 2:
            if(bandera >=1)
            {
                mostrarPaises(lista);
            }

            break;
        case 3:
            if(bandera)
            {
                lista = ll_map(lista,datosRamdon);
                bandera = 2;
            }


            break;
        case 4:

            if(bandera == 2)
            {
                mejorSegundaDosis = ll_filter(lista, filtrarPaisesMejor);
                mostrarPaises(mejorSegundaDosis);
            }

            break;

        case 5:
            if(bandera == 2)
            {
                peorDosis = ll_filter(lista, filtrarPaisesPeor);
                mostrarPaises(peorDosis);
            }

            break;

        case 6:

            break;
        case 7:

            break;

        case 8:
            rta = 's';
            free(lista);
            free(mejorSegundaDosis);
            free(peorDosis);

            break;
        default:
            printf("opcion invalida.\n");
            break;

        }

        system("pause");
        system("cls");

    }
    while(rta != 's');

    return 0;
}

int menu()
{
    int opcion;

    printf("****   menu  *****\n\n");
    printf("1. Cargar archivo\n");
    printf("2. imprimir lista\n");
    printf("3. Asignar estadísticas\n");
    printf("4. Filtrar por países exitosos\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}
