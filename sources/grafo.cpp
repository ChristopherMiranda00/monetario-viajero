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
   int nodo;	//numero del nodo 
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
void dijkstram (int N, int **A, int a, int b)
{
    etiqueta *Flags;
    int i,marca,j,peso;
    int *camino; //arreglo con el camino minimo 

    if((Flags = new etiqueta[N]) == NULL){ //crea dinamicamente arreglo de flags
        return;
    }
       
    for ( i = 0; i < N; i++ ) {// inicializa las flags del nodo
      Flags[i].nodo = i;
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
            }
            else if(Flags[i].peso <= peso){
                peso= Flags[i].peso;
                marca=i;
            }// end else if
        }// end if
    }//end for

    if(marca ==-1){ //termina si ya no hay nodos
        cout<<"Ya se han analizado todos los nodos "<<endl;
        break;
    }

    cout<< "---- Nodo a analizar: " <<marca << "----" <<endl;

   //este for es para que se actualizen los pesos si hay prevs del nodo encontrado
   // y después lo marca como yaEsta
   for(i=0;i<N;i++){
      if(A[marca][i]>0){
         //si el costo total + la suma del costo del enlace del nodo marca al counter i
         // es menor al del nodo i ( o si es -1), se debe de actualizar
         if(Flags[i].peso==-1 || Flags[marca].peso + A[marca][i] < Flags[i].peso){
            if(Flags[marca].peso + A[marca][i] < Flags[i].peso){
               cout<<" [ mejorando costo de nodo "<<i<<" ]"<<endl;
            Flags[i].peso =Flags[marca].peso + A[marca][i];
            Flags[i].prev=marca;
            cout<<" costo de nodo "<<i<< "desde nodo "<<marca<<": "<<Flags[i].peso<<endl;
            }//if3
         }//if2
      }//if1
   }//end for 

   Flags[marca].yaEsta=1;
   cout<<" costo de nodo "<<marca<< " marcado ]"<< endl;

   // este for verificará los costes 
    for(i=0;i<N;i++){
       cout<<i<< ": [ ";
       if(Flags[i].peso==-1){
          cout<<"Peso -1, infinito";
       }else{
          cout<< Flags[i].peso;
       }
       cout << ", " << Flags[i].prev ;
       if(Flags[i].yaEsta==1){
          cout<< ", x] "<<endl;
       } else{
          cout<<"j"<< endl;
       }
       cout<< ""<<endl;
    }//end of for 
   }//end while

   // Ahora la ruta del nodo a vo al nodo b vf
   int longi = 2;
   i=b;
   while((i=Flags[i].prev)!= a){
      longi++;
      if((camino =new int[longi])==NULL){
         return;
      }
      camino[longi-1]=b;
      i=b;
      j=0;
      for(j=1;j<longi;j++){
         i=Flags[i].prev;
         camino[longi-1-j]=i;
      }
   }//end while
   
   cout<<"-----------------------------------------------------------"<<endl;
   cout<<"\n Ruta más corta entre el nodo "<<a<< " y el nodo "<<b<<":"<<endl;
   for(i=0;i<longi;i++){
      cout<< camino[i];
      if(i<longi-1){
         cout<<" - ";
      }
   }
    cout<< "\n  Costo total: " << Flags[b].peso <<endl;

}// end disktram

int main(){
   int noNodos=0; // cantidad total de los nodos
   int i,j, **A;// matriz

    if(( A = new int*[noNodos] ) == NULL ){
      return 1;
    }
    for(i=0;i<noNodos;i++){
       if((A[i]=new int[noNodos])==NULL){
          return 1;
       }
    }
    for(i=0;i<8;i++){ // en este caso es 8 pero se podría cambiar
      for(j=0;j<8;j++){
         A[i][j]=0;
      }
    }
    //Matriz de adyaciencia
    A[0][1] = 16;
   A[0][2] = 10;
   A[0][3] = 5;
 
   A[1][0] = 16;
   A[1][2] = 2;
   A[1][5] = 4;
   A[1][6] = 6;
   
   A[2][0] = 10;
   A[2][1] = 2;
   A[2][3] = 4;
   A[2][4] = 10;
   A[2][5] = 12;
 
   A[3][0] = 5;
   A[3][2] = 4;
   A[3][4] = 15;
 
   A[4][2] = 10;
   A[4][3] = 15;
   A[4][5] = 3;
   A[4][7] = 5;
 
   A[5][1] = 4;
   A[5][2] = 12;
   A[5][4] = 3;
   A[5][6] = 8;
   A[5][7] = 16;
 
   A[6][1] = 6;
   A[6][5] = 8;
   A[6][7] = 7;
 
   A[7][4] = 5;
   A[7][5] = 16;
   A[7][6] = 7; 
   
   //para Imprimir la matriz
   cout<< " Matriz de adyaciencia \n "<<endl;
   for(i=0;i<8;i++){ 
      for(j=0;j<8;j++){
         cout<< setw(2)<<A[i][j]<<" "; // set width http://www.c4learn.com/cplusplus/cpp-setw-setting-field-width/
      }
      cout<<endl;
    }
    cout<<endl;

    dijkstram(noNodos ,A,0,4);
   
   return 0;

}//end of main