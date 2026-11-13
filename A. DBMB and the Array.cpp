#include <bits/stdc++.h>

using namespace std;

class Nodo{
public:
    int dato;
    Nodo* siguiente;

    Nodo(int valor){
        dato = valor;
        siguiente = NULL;
    }
};

class ListaLigada{
private:
    Nodo* inicio;

public:

    ListaLigada(){
        inicio = NULL;
    }

    void insertar(int valor){
        Nodo* nuevo = new Nodo(valor);

        if(inicio == NULL){
            inicio = nuevo;
        }
        else{
            Nodo* actual = inicio;

            while(actual->siguiente != NULL){
                actual = actual->siguiente;
            }

            actual->siguiente = nuevo;
        }
    }

    void fibonacci(int cantidad){

        int a = 0;
        int b = 1;
        int c;

        for(int i=0; i<cantidad; i++){

            insertar(a);

            c = a + b;
            a = b;
            b = c;
        }
    }

    void mostrar(){

        Nodo* actual = inicio;

        while(actual != NULL){
            cout<<actual->dato<<" -> ";
            actual = actual->siguiente;
        }

        cout<<"NULL"<<endl;
    }
};

int main(){

    ListaLigada lista;

    int n;

    cout<<"Cuantos numeros Fibonacci quieres: ";
    cin>>n;

    lista.fibonacci(n);

    cout<<"Lista Fibonacci:"<<endl;
    lista.mostrar();

    return 0;
}
