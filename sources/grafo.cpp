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
struct grafo {
   int nro;	//numero del nodo 
   int prev;	//nodo previo -1 para el nodo inicial )
   int peso;	//peso 
   int yaEsta;	
};

//declaraciones
typedef struct grafo etiqueta;
  
void dijkstram( int, int **, int, int );
 
/*
   void dikstram: calculara el coste minimo con la matriz de adyacencia del grafo
   con los nodos N, del nodo inicial a al nodo final b
   @param int N: número de nodos del grafo
   @param int **A: apuntador a la matriz de adyaciencia
   @param int a: nodo inicial vo
   @param int b: nodo final vf
   @return void
      Nota: https://stackoverflow.com/questions/2893129/what-does-mean-in-c 
      porque no entendí el **A
*/
void dikstram (int N, int **A, int a, int b)
{
    graf *Flags;
    int i,marca,j,peso;
    int *camino; //arreglo con el camino minimo 

    if((Flags=new etiqueta[N] == NULL)){ //crea dinamicamente arreglo de flags
        return;
    }

    for ( i = 0; i < N; i++ ) {// inicializa las flags del nodo
      Flags[i].nro = i;
      if ( i != a ) {
         Flags[i].prev = -1;	// no tiene prev
         Flags[i].peso = -1;	
         Flags[i].yaEsta = 0;
      }
      else {
         Flags[i].prev = -1;	// no tiene prev
         Flags[i].peso = 0;		//cost0 del nodo vo a si mismo es cero 
         Flags[i].yaEsta = 0;
      }
   }
   while(1){ // mientras que existan nodos no marcados
    peso=-1;
    marca=-1;
    for(i=0;i<N;i++){
        if(Flags[i].yaEsta ==0 && Flags[i].peso >=0){
            if(peso ==-1){
                peso=Flags[i].peso;
                marca=i;
            }else if(Flags[i].peso <= peso){
                peso= Flags[i].peso;
                marca=1;
            }// end else if
        }// end if
    }//end for
    if(marca ==-1){ //termina si ya no hay nodos
        cout<<"Ya se han analizado todos los nodos "<<endl;
        break;
    }
    cout<< " Nodo a analizar: " <<marca << endl;

   }//end while



}// end disktram