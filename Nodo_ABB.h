#ifndef NODO_ABB_H
#define NODO_ABB_H

#include <string>

using namespace std;

template <class Dato>
class Nodo_ABB {

    private:
        
        //atributos
        string clave_nodo;
        Dato* dato;
        Nodo_ABB<Dato>* hijo_izquierdo;
        Nodo_ABB<Dato>* hijo_derecho;
        Nodo_ABB<Dato>* padre;

    public:

        //metodos

        /*
        constructor
        PRE: -
        POST: crea una instancia de la clase Nodo_ABB con el dato pasado por parametro como dato del nodo
        */
        Nodo_ABB(string clave, Dato dato);

        /*
        PRE: el objeto Nodo_ABB fue creado
        POST: devuelve el dato del nodo
        */
        Dato* obtener_dato();

        /*
        PRE: el objeto Nodo_ABB fue creado
        POS: devuelve la clave del nodo
        */
        string obtener_clave();

        /*
        PRE: el objeto Nodo_ABB fue creado
        POS: establece el parametro como clave del nodo
        */
        void setear_clave(string clave);
        
        /*
        PRE: el objeto Nodo_ABB fue creado
        POST: establece el parametro pasado como dato del nodo 
        */
        void setear_dato(Dato* dato);
        
        /*
        PRE: el objeto Nodo_ABB fue creado
        POST: establece el primer parametro como hijo derecho del nodo en cuestion y usa el segundo parametro como dato de dicho hijo derecho
        */
        void setear_hijo_derecho(Nodo_ABB<Dato>* hijo_derecho, Nodo_ABB<Dato>* padre);
        
        /*
        PRE: el objeto Nodo_ABB fue creado
        POST: establece el parametro como hijo derecho del nodo en cuestion
        */
        void setear_hijo_derecho(Nodo_ABB<Dato>* hijo_derecho); //metodo sobrecargado
        
        /*
        PRE: el objeto Nodo_ABB fue creado
        POST: establece el primer parametro como hijo izquierdo del nodo en cuestion y usa el segundo parametro como dato de dicho hijo izquierdo
        */
        void setear_hijo_izquierdo(Nodo_ABB<Dato>* hijo_izquierdo, Nodo_ABB<Dato>* padre);
        
        /*
        PRE: el objeto Nodo_ABB fue creado
        POST: establece el parametro como hijo izquierdo del nodo en cuestion
        */
        void setear_hijo_izquierdo(Nodo_ABB<Dato>* hijo_izquierdo); //metodo sobrecargado
        
        /*
        PRE: el objeto Nodo_ABB fue creado
        POST: establece el parametro como padre del nodo en cuestion
        */
        void setear_padre(Nodo_ABB<Dato>* padre);
        
        /*
        PRE: el objeto Nodo_ABB fue creado
        POST: devuelve la direccion de memoria del nodo hijo derecho del nodo en cuestion o devuelve NULL en caso de que no tenga hijo derecho
        */
        Nodo_ABB<Dato>* obtener_hijo_derecho();
        
        /*
        PRE: el objeto Nodo_ABB fue creado
        POST: devuelve la direccion de memoria del nodo hijo izquierdo del nodo en cuestion o devuelve NULL en caso de que no tenga hijo izquierdo
        */
        Nodo_ABB<Dato>* obtener_hijo_izquierdo();
        
        /*
        PRE: el objeto Nodo_ABB fue creado
        POST: devuelve la direccion de memoria del nodo padre del nodo en cuestion o devuelve NULL en caso de que trate de la raiz
        */
        Nodo_ABB<Dato>* obtener_padre();
        
        /*
        PRE: el objeto Nodo_ABB fue creado
        POST: devuelve true en caso de que el nodo en cuestion no tenga hijos y false en caso de que tenga por lo menos uno
        */
        bool es_hoja();
        
        /*
        PRE: el objeto Nodo_ABB fue creado
        POST: devuelve true en caso de que el nodo en cuestion tenga unicamente un hijo derecho y false en cualquier otro caso
        */
        bool solo_hijo_derecho();
        
        /*
        PRE: el objeto Nodo_ABB fue creado
        POST: devuelve true en caso de que el nodo en cuestion tenga unicamente un hijo izquierdo y false en cualquier otro caso
        */
        bool solo_hijo_izquierdo();

        ~Nodo_ABB();
};

template <class Dato>
Nodo_ABB<Dato>::Nodo_ABB(string clave, Dato elemento) {
    this->dato = new Dato;
    *dato = elemento;
    this->clave_nodo = clave;
    this->hijo_izquierdo = nullptr;
    this->hijo_derecho = nullptr;
    this->padre = nullptr;
}

template <class Dato>
Dato* Nodo_ABB<Dato>::obtener_dato() {
    return this->dato;
}

template <class Dato>
string Nodo_ABB<Dato>::obtener_clave() {
    return this->clave_nodo;
}

template <class Dato>
void Nodo_ABB<Dato>::setear_clave(string clave) {
    this->clave_nodo = clave;
}

template <class Dato>
void Nodo_ABB<Dato>::setear_hijo_derecho(Nodo_ABB<Dato>* hijo_derecho, Nodo_ABB<Dato>* padre){
    this->hijo_derecho = hijo_derecho;
    this->padre = padre;
}

template <class Dato>
void Nodo_ABB<Dato>::setear_hijo_derecho(Nodo_ABB<Dato>* hijo_derecho){
    this->hijo_derecho = hijo_derecho;
}

template <class Dato>
void Nodo_ABB<Dato>::setear_hijo_izquierdo(Nodo_ABB<Dato>* hijo_izquierdo, Nodo_ABB<Dato>* padre){
    this->hijo_izquierdo = hijo_izquierdo;
    this->padre = padre;
}

template <class Dato>
void Nodo_ABB<Dato>::setear_padre(Nodo_ABB<Dato> *padre) {
    this->padre = padre;
}

template <class Dato>
void Nodo_ABB<Dato>::setear_dato(Dato* dato) {
    this->dato = dato;
}

template <class Dato>
void Nodo_ABB<Dato>::setear_hijo_izquierdo(Nodo_ABB<Dato>* hijo_izquierdo){
    this->hijo_izquierdo = hijo_izquierdo;
}

template <class Dato>
Nodo_ABB<Dato>* Nodo_ABB<Dato>::obtener_hijo_derecho() {
    return this->hijo_derecho;
}

template <class Dato>
Nodo_ABB<Dato>* Nodo_ABB<Dato>::obtener_hijo_izquierdo() {
    return this->hijo_izquierdo;
}

template <class Dato>
Nodo_ABB<Dato>* Nodo_ABB<Dato>::obtener_padre() {
    return this->padre;
}

template <class Dato>
bool Nodo_ABB<Dato>::es_hoja() {
    return (this->obtener_hijo_izquierdo() == nullptr && this->obtener_hijo_derecho() == nullptr);
}

template <class Dato>
bool Nodo_ABB<Dato>::solo_hijo_derecho() {
    return (this->obtener_hijo_izquierdo() == nullptr && this->obtener_hijo_derecho() != nullptr);
}

template <class Dato>
bool Nodo_ABB<Dato>::solo_hijo_izquierdo() {
    return (this->obtener_hijo_izquierdo() != nullptr && this->obtener_hijo_derecho() == nullptr);
}

template <class Dato>
Nodo_ABB<Dato>::~Nodo_ABB() {
    delete dato;
}
#endif //NODO_ABB_H