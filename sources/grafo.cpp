/*
   Christopher Luis Miranda Vanegas 
   Problema 4:Dado un grafo g conexo y ponderado y dado uno de sus vértices v0, 
   encontrar el ciclo Hamiltoniano de coste mínimo que comienza y termina en v0.

*/

#include <iostream>
#include <iomanip>
#include <list>
using namespace std;

/* 
   Estructura donde se define el número de nodo, coste total, y el nodo previo
*/
struct label {
   int nro;	//numero del nodo 
   int prev;	//nodo previo -1 para el nodo inicial )
   int peso;	//peso 
   int yaEsta;	
};