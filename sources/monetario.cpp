
#include <iostream>
#include <vector>
using namespace std;
struct Solucion{
    int valor;
    int cantidad;
};
void imprimirSol(vector<Solucion> sol){
    for(int i=0;i<sol.size();i++){
        cout<<sol.at(i).valor<<" ";
        cout<<sol.at(i).cantidad<<endl;
    }

}
void darCambio(int monedas[], int cantidad, int tamaño)
{
    vector <Solucion> solucion;
    Solucion aux;
    int total=0;
    int i=0;
    int contMon=0;
    while(total<cantidad && i<tamaño){  //
        while(total + monedas[i]<=cantidad){
            total+=monedas[i];
            contMon++;
        }
        if(contMon!=0){
            aux.cantidad=contMon;
            aux.valor=monedas[i];
            solucion.push_back(aux);

        }
        i++;
        contMon=0;
    }
    imprimirSol(solucion);

}//end of darCambio

int main(){
    int monedas []={11,5,1};
    int size = *(&monedas + 1) - monedas;
    darCambio(monedas,15,size);
    return 0;
}