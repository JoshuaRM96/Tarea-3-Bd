
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

struct nodo{
      char dato;
      struct nodo *siguiente;
};

typedef struct nodo *TPila;

//crear nodo

TPila crearNodo(char x)
{
      TPila newNodo = new(struct nodo);
      newNodo->dato = x;
      return newNodo;
}

void push(TPila &top, char x)
{
     TPila aux = crearNodo(x);
     aux->siguiente = top;
     top = aux;
}
//desapilar
char pop(TPila &top)
{
     int c ;
     TPila aux;
     
     aux = top ;
     c = aux->dato;   // asignamos el primer vamor de la pila
     top = aux->siguiente ;
     delete(aux);
     return c;
}

void verificarPalindroma( TPila &p, string cad)
{
     TPila aux;     
     
     for(int i=0; i<cad.size(); i++)
          if(cad[i]==32)
              cad.erase(i,1);   // borramos el caracter espacio(ASCII 32)
     
     //Apilamos cada uno de los caracteres, el ultimo sera el primero en la pila
     for(int i=0; i<cad.size(); i++)
          push(p, cad[i]);    


    
     for(int i=0; i<cad.size(); i++)
     {
          aux = p;// apunta siempre a la cima de la pila para comparar 
          
          if(cad[i]== aux->dato)
               pop( p );
          else
             break;
     }
     
     if( p==NULL)
        cout << "\n\t Si es Palindromo" << endl;
     else
        cout << "\n\t No es Palindromo" << endl;
}


int main()
{
    TPila pila = NULL;    // creando Pila
    string cad;
    
    cout<<"\nEl siguiente programa muestra si una palabra o frase";
    cout<<"\n\t\t es palindromo\n\n";
    
    cout << " Por favor escribe la palabra o frese \n que quieres comprobar si es palindromo:  ";
    getline(cin, cad);
    
    verificarPalindroma( pila, cad );
    
    system("pause");
    return 0;
}
