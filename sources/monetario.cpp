/*
    Christopher Luis Miranda Vanegas 
    Suponiendo que el sistema monetario de un país está formado por monedas de valores v1,v2,...,vn, 
    el problema del cambio de dinero consiste en descomponer cualquier cantidad dada M en monedas de 
    ese país utilizando el menor número posible de monedas.
*/

#include <iostream>
#include <vector>
using namespace std;

/*
    Stuctura Solución 
*/
struct Solucion{
    int valor; // valor de la moeda
    int cantidad; // cantidad de ese valor de moeda
};// end Solucion 

/*
    Imprimir sol: imprime la solución del problema
    @param el vector con la solución del cambio
    @param int cantidad:la cantidad ingresa
    @return void 
*/
void imprimirSol(vector<Solucion> sol, int cantidad)
{   
    cout<<"      "<<endl;
    cout<< "Cantidad ingresada: "<< cantidad<<endl;
    cout<< "---------------------------------------"<<endl;
    cout<< "Cambio: "<<endl;
    for(int i=0;i<sol.size();i++)
    {
        
        cout<<"Número de monedas: "<<sol.at(i).cantidad<<"  | ";
        cout<<" valor de moneda :  "<<sol.at(i).valor<<endl;
    }
}// end imprimirSol

/*
    darCambio: es el corazón de la solución ya que compara la cantidad y agrega la solucion en el vector. También la imprime.
    @param el arreglo de monedas, 
    @param int cantidad que es la cantidad de la que se quiere el cambio
    @param tamaño del arreglo
    @return void 
*/
void darCambio(int monedas[], int cantidad, int size)
{
    vector <Solucion> solucion;
    Solucion sol;
    int total=0;
    int i=0;
    int counterMon=0;
    while(total<cantidad && i<size{ 
        while(total + monedas[i]<=cantidad){
            total+=monedas[i];
            counterMon++;
        }
        if(counterMon!=0){
            sol.cantidad=counterMon;
            sol.valor=monedas[i];
            solucion.push_back(sol);

        }
        i++;
        counterMon=0;
    }
    imprimirSol(solucion,cantidad);
}//end of darCambio

int main(){
    int monedas []={11,5,1}; //arreglo de enteros 
    int size = *(&monedas + 1) - monedas; // tamaño del arreglo 
    darCambio(monedas,20,size);
    return 0;
}