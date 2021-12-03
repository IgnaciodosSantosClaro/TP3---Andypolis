#include "Nodo_ABB.h"
#include <iostream>

using namespace std;

#ifndef ABB_H
#define ABB_H

template <class Dato>
class ABB {

    private:

        // Atributos

        Nodo_ABB<Dato>* raiz;

        // Metodos
        

        /*
        PRE: el objeto ABB fue creado y no esta vacio
        POST: inserta el nodo pasado por parametro en el ABB y le asigna el 2do parametro como dato
        */
        Nodo_ABB<Dato>* insertar_nodo(Nodo_ABB<Dato>* nodo, Dato dato);

        /*
        PRE: el objeto ABB fue creado y no esta vacio
        POST: imprime el recorrido in order del ABB a tomando como raiz al nodo cuya direccion de memoria es pasada por parametro
        */
        void imprimir_in_order(Nodo_ABB<Dato> * nodo);        

        /*
        PRE: el objeto ABB fue creado y no esta vacio
        POST: busca recursivamente para su subarbol izquierdo o derecho del nodo cuya direccion de memoria es pasada por parametro, y devuelve la dirección de memoria del nodo cuyo dato coincida con el dato pasado por parametro
        */
        Nodo_ABB<Dato>* buscar(Nodo_ABB<Dato>* nodo, Dato dato);        

        /*
        PRE: el objeto ABB fue creado y no esta vacio
        POST: devuelve el dato del nodo mas izquierdo del subarbol izquiero del nodo cuya direccion de memoria es pasada por parametro
        */
        Dato buscar_min(Nodo_ABB<Dato>* nodo);        

        /*
        PRE: el objeto ABB fue creado y no esta vacio
        POST: devuelve el dato del nodo mas derecho del subarbol derecho del nodo cuya direccion de memoria es pasada por parametro
        */
        Dato buscar_max(Nodo_ABB<Dato>* nodo);        

        /*
        PRE: el objeto ABB fue creado y no esta vacio
        POST: devuelve el dato del menor de los hijos derechos, o en su defecto, a la raiz del subarbol que tenga como unico hijo izquierdo al sucesor del nodo pasado por parametro
        */
        Dato sucesor(Nodo_ABB<Dato>* nodo);        

        /*
        PRE: el objeto ABB fue creado y no esta vacio
        POST: devuelve el dato del mayor de los hijos izquierdos, o en su defecto, a la raiz del subarbol que tenga como unico hijo derecho al predecesor del nodo pasado por parametro
        */
        Dato predecesor(Nodo_ABB<Dato>* nodo);        

        /*
        PRE: el objeto ABB fue creado y no esta vacio
        POST: crea una instancia de la clase ABB
        */
        Nodo_ABB<Dato>* remover_nodo(Nodo_ABB<Dato>* nodo, Dato dato);        

        /*
        PRE: el objeto ABB fue creado y no esta vacio
        POST: crea una instancia de la clase ABB
        */
        void borrar_todos(Nodo_ABB<Dato>* nodo);        

    public:

        //metodos

        /*
        constructor
        PRE: el objeto ABB fue creado y no esta vacio
        POST: crea una instancia de la clase ABB
        */
        ABB();

        /*
        PRE: el objeto ABB fue creado y no esta vacio
        POST: llama al metodo privado insertar_nodo(Nodo_ABB<Dato>*, Dato), e insertar a partir de la raiz del ABB el dato pasado por parametro
        */
        void insertar_nodo(Dato dato);

        /*
        PRE: el objeto ABB fue creado y no esta vacio
        POST: llama al metodo privado imprimir_in_order(Nodo_ABB<Dato>*) pasando como parametro a la raiz del ABB e imprime por pantalla el recorrido in order del arbol  
        */
        void imprimir_in_order();
        
        /*
        PRE: el objeto ABB fue creado y no esta vacio
        POST: busca a partir de la raiz el dato pasado por parametro y devuelve true en caso de hallarlo, y falso en caso de no hacerlo
        */
        bool buscar(Dato dato);

        /*
        PRE: el objeto ABB fue creado y no esta vacio
        POST: llama al metodo privado buscar_min(Nodo_ABB<Dato>*) y busca el hijo mas izquierdo de la raiz del ABB y devuelve el dato que el mismo posee
        */
        Dato buscar_min();

        /*
        PRE: el objeto ABB fue creado y no esta vacio
        POST: llama al metodo privado buscar_max(Nodo_ABB<Dato>*) y busca el hijo mas derecho de la raiz del ABB y devuelve el dato que el mismo posee
        */
        Dato buscar_max();

        /*
        PRE: el objeto ABB fue creado y no esta vacio
        POST: llama a la definicion privada de sucesor, aplicando la busqueda del nodo que se desea buscar a partir de la raiz, y devuelve el dato del sucesor de dicho nodo   
        */
        Dato sucesor(Dato dato);

        /*
        PRE: el objeto ABB fue creado y no esta vacio
        POST: llama a la definicion privada de predecesor, aplicando la busqueda del nodo que se desea buscar a partir de la raiz, y devuelve el dato del predecesor de dicho nodo   
        */
        Dato predecesor(Dato dato);

        /*
        PRE: el objeto ABB fue creado y no esta vacio
        POST: busca partiendo de la raiz y utiliza el metodo privado remover_nodo(Nodo_ABB<Dato>*, Dato) para eliminar el nodo que tenga por dato el que se pasa por parametro
        */
        void remover_nodo(Dato dato);

        /*
        PRE: el objeto ABB fue creado y no esta vacio
        POST: devuelve la posicion de memoria de la raiz del ABB
        */
        Nodo_ABB<Dato>* obtener_raiz();

        /*
        PRE: el objeto ABB fue creado
        POST: devuelve true en caso de que el ABB no tenga ningún nodo, y false en caso contrario
        */
        bool vacio();

        /*
        PRE: el objeto ABB fue creado y no esta vacio
        POST: usa el metodo privado borrar_todos para llamar a partir de la raiz del ABB y recursivamente hacia sus subarboles tanto izauiero como derecho, borrando de "abajo para arriba" los nodos del arbol partiendo de las hojas y llegando a la raiz.
        */
        void borrar_todos();

        /*
        desructor
        PRE: el objeto ABB fue creado
        POST: se destruye el objeto ABB y se libera la memoria que este ocupaba
        */
        ~ABB<Dato>();

};

template <class Dato>
ABB<Dato>::ABB() {
    this->raiz = NULL;
}

template <class Dato>
Nodo_ABB<Dato>* ABB<Dato>::insertar_nodo(Nodo_ABB<Dato>* nodo, Dato dato) {

    if (nodo == NULL) {
        nodo = new Nodo_ABB<Dato>(dato);
    }

    else if (dato > nodo->obtener_dato()) {
        nodo->setear_hijo_derecho(insertar_nodo(nodo->obtener_hijo_derecho(), dato), nodo);
    }

    else {
        nodo->setear_hijo_izquierdo(insertar_nodo(nodo->obtener_hijo_izquierdo(), dato), nodo);
    }
    return nodo;
}

template <class Dato>
void ABB<Dato>::insertar_nodo(Dato dato) {
    this->raiz = insertar_nodo(this->raiz, dato);
}

template <class Dato>
void ABB<Dato>::imprimir_in_order(Nodo_ABB<Dato>* nodo) {
    if (nodo != NULL){
        imprimir_in_order(nodo->obtener_hijo_izquierdo());
        cout<<nodo->obtener_dato()<<' ';
        imprimir_in_order(nodo->obtener_hijo_derecho());
    }
}

template <class Dato>
void ABB<Dato>::imprimir_in_order() {
    this->imprimir_in_order(this->raiz);
}

template <class Dato>
Nodo_ABB<Dato>* ABB<Dato>::buscar(Nodo_ABB<Dato>* nodo, Dato dato) {
    if (nodo == NULL || nodo->obtener_dato() == dato){
        return nodo;
    }
    if (dato > nodo->obtener_dato()){
        return buscar(nodo->obtener_hijo_derecho(), dato);
    }
    return buscar(nodo->obtener_hijo_izquierdo(), dato);
}

template <class Dato>
bool ABB<Dato>::buscar(Dato dato) {
    Nodo_ABB<Dato>* resultado_de_busqueda = buscar(this->raiz, dato);

    return resultado_de_busqueda != NULL;
}

template <class Dato>
Dato ABB<Dato>::buscar_min(Nodo_ABB<Dato>* nodo) {
    if(nodo == NULL){
        return -1;
    }
    else if(nodo->obtener_hijo_izquierdo() == NULL){
        return nodo->obtener_dato();
    }
    else{
        return buscar_min(nodo->obtener_hijo_izquierdo());
    }
}

template <class Dato>
Dato ABB<Dato>::buscar_min() {
    return buscar_min(this->raiz);
}

template <class Dato>
Dato ABB<Dato>::buscar_max(Nodo_ABB<Dato>* nodo) {
    if(nodo == NULL){
        return -1;
    }
    else if(nodo->obtener_hijo_derecho() == NULL){
        return nodo->obtener_dato();
    }
    else{
        return buscar_max(nodo->obtener_hijo_derecho());
    }
}

template <class Dato>
Dato ABB<Dato>::buscar_max() {
    return buscar_max(this->raiz);
}

template <class Dato>
Dato ABB<Dato>::sucesor(Nodo_ABB<Dato>* nodo) {
    if (nodo->obtener_hijo_derecho() != NULL){
        return buscar_min(nodo->obtener_hijo_derecho());
    }


    Nodo_ABB<Dato>* sucesor = NULL;
    Nodo_ABB<Dato>* ancestro = this->raiz;


    while(ancestro != nodo) {
        if(nodo->obtener_dato() < ancestro->obtener_dato()) {
            sucesor = ancestro;
            ancestro = ancestro->obtener_hijo_izquierdo();
        }
        else{
            ancestro = ancestro->obtener_hijo_derecho();
        }
    }
    return sucesor->obtener_dato();
}

template <class Dato>
Dato ABB<Dato>::sucesor(Dato dato) {
    Nodo_ABB<Dato>* nodo_aux = this->buscar(this->raiz, dato);
    if(nodo_aux == NULL){
        return -1;
    }
    return sucesor(nodo_aux);
}

template <class Dato>
Dato ABB<Dato>::predecesor(Nodo_ABB<Dato> * nodo) {
    if (nodo->obtener_hijo_izquierdo() != NULL){
        return buscar_max(nodo->obtener_hijo_izquierdo());
    }

    Nodo_ABB<Dato>* sucesor = NULL;
    Nodo_ABB<Dato>* ancestro = this->raiz;

    while(ancestro != nodo) {
        if(nodo->obtener_dato() > ancestro->obtener_dato()) {
            sucesor = ancestro;
            ancestro = ancestro->obtener_hijo_derecho();
        }
        else{
            ancestro = ancestro->obtener_hijo_izquierdo();
        }
    }
    return sucesor->obtener_dato();
}

template <class Dato>
Dato ABB<Dato>::predecesor(Dato dato) {
    Nodo_ABB<Dato> * nodo_aux = this->buscar(this->raiz, dato);

    if(nodo_aux == NULL){
        return -1;
    }
    else{
        return predecesor(nodo_aux);
    }
}

template <class Dato>
Nodo_ABB<Dato> * ABB<Dato>::remover_nodo(Nodo_ABB<Dato>* nodo, Dato dato) {

    if (nodo == NULL){
        return nullptr;
    }
    if (nodo->obtener_dato() == dato){

        if (nodo->es_hoja()){
            delete nodo;
            return nullptr;
        }
        else if (nodo->solo_hijo_derecho()){

            // se establece al padre del nodo a remover como padre del nodo hijo del que se removerá
            nodo->obtener_hijo_derecho()->setear_padre(nodo->obtener_padre());
            // se omite el nodo a eliminar dentro de la estructura del ABB
            Nodo_ABB<Dato>* aux = nodo;
            nodo = nodo->obtener_hijo_derecho();
            delete aux;
        }
        else if (nodo->solo_hijo_izquierdo()){
            
            // se establece al padre del nodo a remover como padre del nodo hijo del que se removerá
            nodo->obtener_hijo_izquierdo()->setear_padre(nodo->obtener_padre());
            // se omite el nodo a eliminar dentro de la estructura del ABB
            Nodo_ABB<Dato>* aux = nodo;
            nodo = nodo->obtener_hijo_izquierdo();
            delete aux;
        }

        // en caso de que el nodo a remover tiene tanto hijo izquierdo como derecho
        else{

            // para reemplazar al nodo a eliminar se busca un sucesor, es decir, al nodo mas izquierdo del subarbol derecho de que tiene por raiz al nodo a eliminar
            Dato dato_del_sucesor = this->sucesor(dato);

            /* se reemplaza el dato que contiene el nodo a eliminar por el dato que contenga el sucesor (esto de solo reemplazar el dato y el resto dejarlo tal cual es porque si se 
            eliminara el nodo directaente y se lo reemplazara con el sucesor. o predecesor, habría que reacomodar todos los punteros y sería una re fiaca)
            */
            nodo->set_dato(dato_del_sucesor);

            // se remueve al nodo sucesor y del nodo a eliminar y se ajustan los punteros del mismo
            nodo->setear_hijo_derecho(remover_nodo(nodo->obtener_hijo_derecho(), dato_del_sucesor));
        }
    }

    else if (nodo->obtener_dato() < dato){
        nodo->setear_hijo_derecho(remover_nodo(nodo->obtener_hijo_derecho(), dato));
    }
    else{
        nodo->setear_hijo_izquierdo(remover_nodo(nodo->obtener_hijo_izquierdo(), dato));
    }
    return nodo;
}

template <class Dato>
void ABB<Dato>::remover_nodo(Dato dato) {
    this->raiz = remover_nodo(this->raiz, dato);
}

template <class Dato>
Nodo_ABB<Dato>* ABB<Dato>::obtener_raiz(){
    return this->raiz;
}

template <class Dato>
bool ABB<Dato>::vacio() {
    return this->raiz == NULL;
}

template <class Dato>
void ABB<Dato>::borrar_todos(Nodo_ABB<Dato>* nodo) {
    if(nodo == NULL){
        return;
    }
    this->borrar_todos(nodo->obtener_hijo_izquierdo());
    this->borrar_todos(nodo->obtener_hijo_derecho());
    delete nodo;
}

template <class Dato>
void ABB<Dato>::borrar_todos() {
    this->borrar_todos(this->raiz);
}

template <class Dato>
ABB<Dato>::~ABB<Dato>() {
    this->borrar_todos();
}

#endif //ABB_H