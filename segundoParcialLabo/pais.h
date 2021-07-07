#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED
#include "LinkedList.h"

struct
{
   int id;
   char nombre[50];
   int vac1Dosis;
   int vac2Dosis;
   int sinVacunar;
}typedef ePais;

#endif // PAIS_H_INCLUDED

ePais* nuevoPais();

ePais* nuevoPaisParamStr(char* strId, char* nombre, char* primeraDosisStr, char* segundaDosisStr, char* sinVacunarStr);

void mostrarPais(ePais* p);

void mostrarPaises(LinkedList* list);

ePais* datosRamdon(ePais* pais);

int filtrarPaisesMejor(void* pElement);

int filtrarPaisesPeor(void* pElement);
