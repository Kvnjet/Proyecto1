// Estudiantes: José Carballo Martínez y Kevin Espinoza Barrantes

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class NodoPasillo
{
public:
    NodoPasillo(int _codPasillo, string _nombre)
    {
        codPasillo = _codPasillo;
        nombre = _nombre;
        siguiente = NULL;
    }

    NodoPasillo(int _codPasillo, string _nombre, NodoPasillo* _siguiente)
    {
        codPasillo = _codPasillo;
        nombre = _nombre;
        siguiente = _siguiente;
    }

	int getCodPasillo() { return codPasillo; }
	string getNombre() { return nombre; }

private:
    int codPasillo;
    string nombre;
    NodoPasillo* siguiente;

    friend class ListaSimplePas;
};

typedef NodoPasillo* pnodoPasillo;


class ListaSimplePas  
{
public:
    ListaSimplePas() { primero = NULL; }
    ~ListaSimplePas();

    void InsertarInicio(int codPasillo, string nombre);
    void InsertarFinal(int codPasillo, string nombre);
    void InsertarPos(int codPasillo, string nombre, int pos);
    bool ListaVacia() { return primero == NULL; }
    void BorrarInicio();
    void BorrarFinal();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();
    void insertarPasillo(int codPasillo, string nombre);
    bool pasilloRepetido(int codPasillo);
    void eliminarPasillo(int codPasillo);
    pnodoPasillo buscarPasillo(int codPasillo);
    void modificarPasillo(int codPasillo, string nombre);

private:
    pnodoPasillo primero;
};

void ListaSimplePas::insertarPasillo(int codPasillo, string nombre)
{
    // Verifica si el pasillo ya existe en la lista
    pnodoPasillo aux = primero;
    bool repetido = false;

    while (aux != NULL)
    {
        if (aux->codPasillo == codPasillo)
            // Si se encuentra el pasillo, es repetido
            repetido = true;

        aux = aux->siguiente;
    }

    if (repetido == false)
    {
        // Si no existe, inserta al final
        InsertarFinal(codPasillo, nombre);
        cout << "\nPasillo insertado exitosamente." << endl;
        cout << "Pasillo insertado:" << endl;
        cout << " --> CodPasillo: " << codPasillo << endl;
        cout << "     Nombre: " << nombre << endl;
    }
    else
        cout << "\nEl pasillo ya existe en la lista." << endl;
}

bool ListaSimplePas::pasilloRepetido(int codPasillo)
{
    pnodoPasillo aux = primero;

    while (aux != NULL)
    {
        if (aux->codPasillo == codPasillo)
            // Si se encuentra el pasillo, es repetido
            return true;

        aux = aux->siguiente;
    }

    // Si no se encuentra, no es repetido
    return false;
}

void ListaSimplePas::eliminarPasillo(int codPasillo)
{
    if (ListaVacia())
    {
        cout << "\nLa lista de pasillos esta vacia." << endl;
        return;
    }

    pnodoPasillo actual = primero;
    int pos = 1;

    do
    {
        if (actual->codPasillo == codPasillo)
        {
            // Si se encontró el nodo con el codPasillo dado, borra en esa posición
            BorrarPosicion(pos);
            cout << "\nPasillo eliminado exitosamente." << endl;
            return;
        }

        actual = actual->siguiente;
        pos++;
    } while (actual != primero);

    // No se encontró el codPasillo en la lista
    cout << "\nNo se encontro el pasillo con el codigo dado." << endl;
}

pnodoPasillo ListaSimplePas::buscarPasillo(int codPasillo)
{
    if (ListaVacia())
    {
        cout << "La lista de pasillos está vacía." << endl;
        return NULL;
    }

    pnodoPasillo aux = primero;

    while (aux != NULL)
	{
		if (aux->codPasillo == codPasillo)
            return aux;

        aux = aux->siguiente;
    }

    return NULL;
}

void ListaSimplePas::modificarPasillo(int codPasillo, string nombre)
{
	pnodoPasillo pasillo = buscarPasillo(codPasillo);

    if (pasillo == NULL)
    {
        cout << "\nPasillo no encontrado." << endl;
        return;
    }

    pasillo->codPasillo = codPasillo;
    pasillo->nombre = nombre;

    cout << "\nPasillo modificado exitosamente." << endl;
    cout << "Pasillo modificado:" << endl;
	cout << "--> CodPasillo: " << codPasillo << endl;
	cout << "    Nombre: " << nombre << endl << endl;
}


ListaSimplePas::~ListaSimplePas()
{
    pnodoPasillo aux;

    while (primero)
    {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

    primero = NULL;
}

void ListaSimplePas::InsertarInicio(int codPasillo, string nombre)
{
    if (ListaVacia())
        primero = new NodoPasillo(codPasillo, nombre);
    else
    {
        pnodoPasillo nuevo = new NodoPasillo(codPasillo, nombre, primero);
        primero = nuevo;
    }
}

void ListaSimplePas::InsertarFinal(int codPasillo, string nombre)
{
    if (ListaVacia())
        primero = new NodoPasillo(codPasillo, nombre);
    else
    {
        pnodoPasillo aux = primero;

        while (aux->siguiente != NULL)
            aux = aux->siguiente;

        aux->siguiente = new NodoPasillo(codPasillo, nombre);
    }
}

void ListaSimplePas::InsertarPos(int codPasillo, string nombre, int pos)
{
    if (ListaVacia())
        primero = new NodoPasillo(codPasillo, nombre);
    else
    {
        if (pos <= 1)
            InsertarInicio(codPasillo, nombre);
        else
        {
            pnodoPasillo aux = primero;
            int i = 2;

            while ((i != pos) && (aux->siguiente != NULL))
            {
                i++;
                aux = aux->siguiente;
            }

            pnodoPasillo nuevo = new NodoPasillo(codPasillo, nombre);
            nuevo->siguiente = aux->siguiente;
            aux->siguiente = nuevo;
        }
    }
}

void ListaSimplePas::BorrarInicio()
{
    if (ListaVacia())
        cout << "\nNo hay elementos en la lista." << endl;
    else
    {
        pnodoPasillo temp = primero;
        primero = primero->siguiente;
        delete temp;
    }
}

void ListaSimplePas::BorrarFinal()
{
    if (ListaVacia())
        cout << "\nNo hay elementos en la lista." << endl;
    else
    {
        if (primero->siguiente == NULL)
        {
            pnodoPasillo temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoPasillo aux = primero;

            while (aux->siguiente->siguiente != NULL)
                aux = aux->siguiente;

            pnodoPasillo temp = aux->siguiente;
            aux->siguiente = NULL;
            delete temp;
        }
    }
}

void ListaSimplePas::BorrarPosicion(int pos)
{
    if (ListaVacia())
        cout << "\nLa lista esta vacia." << endl;
    else
    {
        if ((pos > largoLista()) || (pos < 0))
            cout << "\nError en posicion." << endl;
        else
        {
            if (pos == 1)
                BorrarInicio();
            else
            {
                int cont = 2;
                pnodoPasillo aux = primero;

                while (cont < pos)
                {
                    aux = aux->siguiente;
                    cont++;
                }

                pnodoPasillo temp = aux->siguiente;
                aux->siguiente = aux->siguiente->siguiente;
                delete temp;
            }
        }
    }
}

void ListaSimplePas::Mostrar()
{
    pnodoPasillo aux = primero;

    while (aux)
    {	
        // cout << aux->codPasillo << ", " << aux->nombre << " --> " << endl;
        
        cout << "--> CodPasillo: " << aux->codPasillo << endl;
		cout << "    Nombre: " << aux->nombre << endl << endl;

        aux = aux->siguiente;
    }
}

int ListaSimplePas::largoLista()
{
    int cont = 0;
    pnodoPasillo aux = primero;

    while (aux != NULL)
    {
        aux = aux->siguiente;
        cont++;
    }

    return cont;
}



class NodoProPasillo
{
public:
    NodoProPasillo(int _codPasillo, int _codProducto, string _nombre)
    {
        codPasillo = _codPasillo;
        codProducto = _codProducto;
        nombre = _nombre;
        siguiente = NULL;
        anterior = NULL;
    }
    
    NodoProPasillo(int _codPasillo, int _codProducto, string _nombre, NodoProPasillo* _siguiente)
    {
        codPasillo = _codPasillo;
        codProducto = _codProducto;
        nombre = _nombre;
        siguiente = _siguiente;
        anterior = NULL;
    }
    
    int getCodPasillo() { return codPasillo; }
	int getCodProducto() { return codProducto; }
	string getNombre() { return nombre; }

private:
    int codPasillo;
    int codProducto;
    string nombre;
    NodoProPasillo* siguiente;
    NodoProPasillo* anterior;

    friend class ListaDobleProPasillos;
};

typedef NodoProPasillo* pnodoProPasillo;


class ListaDobleProPasillos
{
public:
    ListaDobleProPasillos() { primero = NULL; }
    ~ListaDobleProPasillos();

    void InsertarInicio(int codPasillo, int codProducto, string nombre);
    void InsertarFinal(int codPasillo, int codProducto, string nombre);
    void InsertarPos(int codPasillo, int codProducto, string nombre, int pos);
    bool ListaVacia() { return primero == NULL; }
    void BorrarInicio();
    void BorrarFinal();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();
    void insertarProPasillo(int codPasillo, int codProducto, string nombre, ListaSimplePas& listaPasillos);
    bool productoRepetido(int codProducto);
    void eliminarProPasillo(int codProducto);
    pnodoProPasillo buscarProPasillo(int codProducto);
    void modificarProPasillo(int codProducto, string nombre);

private:
    pnodoProPasillo primero;
};

void ListaDobleProPasillos::insertarProPasillo(int codPasillo, int codProducto, string nombre, ListaSimplePas& listaPasillos)
{
    // Verifica si el pasillo existe en la lista simple
    if (listaPasillos.pasilloRepetido(codPasillo))
    {
        if (!productoRepetido(codProducto))
            // Inserta al inicio después de las validaciones
            InsertarInicio(codPasillo, codProducto, nombre);
            
            cout << "\nProducto insertado exitosamente." << endl;
	        cout << "Producto insertado:" << endl;
	        cout << " --> CodPasillo: " << codPasillo << endl;
	        cout << "     CodProducto: " << codProducto << endl;
	        cout << "     Nombre: " << nombre << endl;
    }
    else
    	cout << "\nNo se pudo insertar el producto." << endl;
}

bool ListaDobleProPasillos::productoRepetido(int codProducto)
{
    pnodoProPasillo aux = primero;

    while (aux != NULL)
    {
        if (aux->codProducto == codProducto)
            // Si se encuentra el producto, es repetido
            return true;

        aux = aux->siguiente;
    }

    // Si no se encuentra, no es repetido
    return false;
}

void ListaDobleProPasillos::eliminarProPasillo(int codProducto)
{
    if (ListaVacia())
    {
        cout << "La lista de productos esta vacia." << endl;
        return;
    }

    pnodoProPasillo actual = primero;

    do
    {
        if (actual->codProducto == codProducto)
        {
            // Elimina todas las marcas de ese producto
            while (actual->anterior != NULL)
            {
                actual = actual->anterior;
                BorrarInicio();
            }
            
            while (actual->siguiente != NULL)
            {
                actual = actual->siguiente;
                BorrarFinal();
            }

            cout << "Producto y sus marcas eliminados exitosamente." << endl;
            return;
        }

        actual = actual->siguiente;
    } while (actual != primero);

    cout << "No se encontro el producto con el codigo dado." << endl;
}

pnodoProPasillo ListaDobleProPasillos::buscarProPasillo(int codProducto)
{
    if (ListaVacia())
	{
        cout << "La lista de pasillos esta vacia." << endl;
        return NULL;
    }

    pnodoProPasillo aux = primero;

    while (aux != NULL)
	{
        if (aux->codProducto == codProducto)
            return aux;

        aux = aux->siguiente;
    }

    return NULL;
}

void ListaDobleProPasillos::modificarProPasillo(int codProducto, string nombre)
{
	pnodoProPasillo proPasillo = buscarProPasillo(codProducto);

    if (proPasillo == NULL)
    {
        cout << "\nProducto no encontrado." << endl;
        return;
    }

    proPasillo->codProducto = codProducto;
    proPasillo->nombre = nombre;
}


ListaDobleProPasillos::~ListaDobleProPasillos()
{
    pnodoProPasillo aux;

    while (primero)
    {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

    primero = NULL;
}

void ListaDobleProPasillos::InsertarInicio(int codPasillo, int codProducto, string nombre)
{
    if (ListaVacia())
    {
        primero = new NodoProPasillo(codPasillo, codProducto, nombre);
        primero->anterior = NULL;
    }
    else
    {
        primero = new NodoProPasillo(codPasillo, codProducto, nombre, primero);
        primero->siguiente->anterior = primero;
    }
}

void ListaDobleProPasillos::InsertarFinal(int codPasillo, int codProducto, string nombre)
{
    if (ListaVacia())
    {
        primero = new NodoProPasillo(codPasillo, codProducto, nombre);
        primero->anterior = NULL;
    }
    else
    {
        pnodoProPasillo aux = primero;

        while (aux->siguiente != NULL)
            aux = aux->siguiente;

        aux->siguiente = new NodoProPasillo(codPasillo, codProducto, nombre);
        aux->siguiente->anterior = aux;
    }
}

void ListaDobleProPasillos::InsertarPos(int codPasillo, int codProducto, string nombre, int pos)
{
    if (ListaVacia())
    {
        primero = new NodoProPasillo(codPasillo, codProducto, nombre);
        primero->anterior = NULL;
    }
    else
    {
        if (pos <= 1)
        {
            // Ajusta el puntero anterior del nuevo nodo
            pnodoProPasillo nuevo = new NodoProPasillo(codPasillo, codProducto, nombre);
            nuevo->siguiente = primero;

            // Verifica si el siguiente nodo no es NULL antes de acceder al campo anterior
            if (primero != NULL)
                primero->anterior = nuevo;

            primero = nuevo;
        }
        else
        {
            pnodoProPasillo aux = primero;
            int i = 2;

            while ((i != pos) && (aux->siguiente != NULL))
            {
                i++;
                aux = aux->siguiente;
            }

            pnodoProPasillo nuevo = new NodoProPasillo(codPasillo, codProducto, nombre);
            nuevo->siguiente = aux->siguiente;

            // Verifica si el siguiente nodo no es NULL antes de acceder al campo anterior
            if (aux->siguiente != NULL)
                aux->siguiente->anterior = nuevo;

            aux->siguiente = nuevo;
            nuevo->anterior = aux;
        }
    }
}

void ListaDobleProPasillos::BorrarInicio()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista." << endl;
    else
    {
        if (primero->siguiente == NULL)
        {
            pnodoProPasillo temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoProPasillo aux = primero;
            primero = primero->siguiente;
            primero->anterior = NULL;
            delete aux;
        }
    }
}

void ListaDobleProPasillos::BorrarFinal()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista." << endl;
    else
    {
        if (primero->siguiente == NULL)
        {
            pnodoProPasillo temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoProPasillo aux = primero;
            while (aux->siguiente->siguiente != NULL)
                aux = aux->siguiente;

            pnodoProPasillo temp = aux->siguiente;
            aux->siguiente = NULL;
            delete temp;
        }
    }
}

void ListaDobleProPasillos::BorrarPosicion(int pos)
{
    if (ListaVacia())
        cout << "La lista esta vacia." << endl;
    else
    {
        if ((pos > largoLista()) || (pos < 0))
            cout << "Error en posicion." << endl;
        else
        {
            if (pos == 1)
                BorrarInicio();
            else
            {
                if (pos == largoLista())
                    BorrarFinal();
                else
                {
                    int cont = 2;
                    pnodoProPasillo aux = primero;

                    while (cont < pos)
                    {
                        aux = aux->siguiente;
                        cont++;
                    }

                    pnodoProPasillo temp = aux->siguiente;
                    aux->siguiente = aux->siguiente->siguiente;
                    aux->siguiente->anterior = aux;
                    delete temp;
                }
            }
        }
    }
}

void ListaDobleProPasillos::Mostrar()
{
    pnodoProPasillo aux;
    aux = primero;

    while (aux)
    {
        // cout << aux->codPasillo << ", " << aux->codProducto
		// 	<< ", " << aux->nombre << " --> " << endl;
		
		cout << "--> CodPasillo: " << aux->codPasillo << endl;
		cout << "    CodProducto: " << aux->codProducto << endl;
		cout << "    Nombre: " << aux->nombre << endl << endl;
        
		aux = aux->siguiente;
    }
}

int ListaDobleProPasillos::largoLista()
{
    int cont = 0;

    pnodoProPasillo aux;
    aux = primero;

    if (ListaVacia())
        return cont;
    else
    {
        while (aux != NULL)
        {
            aux = aux->siguiente;
            cont++;
        }

        return cont;
    }
}



class NodoMarcaProducto
{
public:
    NodoMarcaProducto(int _codPasillo, int _codProducto, int _codMarca, string _nombre, int _cantGondola, int _precio)
    {
        codPasillo = _codPasillo;
        codProducto = _codProducto;
        codMarca = _codMarca;
        nombre = _nombre;
        cantGondola = _cantGondola;
        precio = _precio;
        siguiente = NULL;
        anterior = NULL;
    }
    
    int getCodPasillo() { return codPasillo; }
    int getCodProducto() { return codProducto; }
    int getCodMarca() { return codMarca; }
	string getNombre() { return nombre; }
	int getCantGondola() { return cantGondola; }
	int getPrecio() { return precio; }

private:
    int codPasillo;
    int codProducto;
    int codMarca;
    string nombre;
    int cantGondola;
    int precio;
    NodoMarcaProducto* siguiente;
    NodoMarcaProducto* anterior;

    friend class ListaCircularDMarcasProductos;
};

typedef NodoMarcaProducto* pnodoMarcaProducto;


class ListaCircularDMarcasProductos
{
public:
    ListaCircularDMarcasProductos() { primero = NULL; }
    ~ListaCircularDMarcasProductos();

    void InsertarInicio(int codPasillo, int codProducto, int codMarca, string nombre, int cantGondola, int precio);
    void InsertarFinal(int codPasillo, int codProducto, int codMarca, string nombre, int cantGondola, int precio);
    void InsertarPos(int codPasillo, int codProducto, int codMarca, string nombre, int cantGondola, int precio, int pos);
    bool ListaVacia() { return primero == NULL; }
    void BorrarInicio();
    void BorrarFinal();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();
    void insertarMarcaProducto(int codPasillo, int codProducto, int codMarca, string nombre, int cantGondola, int precio, ListaSimplePas& listaPasillos, ListaDobleProPasillos& listaProductos);
    bool marcaProductoRepetida(int codMarca);
    void eliminarMarcasProductos();
    pnodoMarcaProducto buscarMarcaProducto(int codMarca);
    void modificarMarcaProducto(int codMarca, string nombre, int cantGondola, int precio);

private:
    pnodoMarcaProducto primero;
};

void ListaCircularDMarcasProductos::insertarMarcaProducto(int codPasillo, int codProducto, int codMarca, string nombre, int cantGondola, int precio, ListaSimplePas& listaPasillos, ListaDobleProPasillos& listaProductos)
{
    // Valida si el pasillo existe en la lista simple de pasillos
    if (!listaPasillos.pasilloRepetido(codPasillo))
    {
    	cout << "Pasillo no existe" << endl;
    	return;
	}

    // Valida si el producto existe en la lista doble de productos
    if (!listaProductos.productoRepetido(codProducto))
    {
    	cout << "Producto no existe" << endl;
    	return;
	}

    // Valida si el codMarca está repetido en la lista circular doble de marcas
    if (marcaProductoRepetida(codMarca))
	{
    	cout << "La marca ya existe" << endl;
    	return;
	}
    
    // Inserta en la lista circular doble de marcas después de las validaciones
    InsertarFinal(codPasillo, codProducto, codMarca, nombre, cantGondola, precio);
    cout << "\nMarca insertada exitosamente." << endl;
    cout << "Marca insertada:" << endl;
    cout << " --> CodPasillo: " << codPasillo << endl;
    cout << "     CodProducto: " << codProducto << endl;
    cout << "     CodMarca: " << codMarca << endl;
    cout << "     Nombre: " << nombre << endl;
    cout << "     CantGondola: " << cantGondola << endl;
    cout << "     Precio: " << precio << endl;
}

bool ListaCircularDMarcasProductos::marcaProductoRepetida(int codMarca)
{
    if (ListaVacia())
        return false; // La lista está vacía, por lo que no hay marcas repetidas

    pnodoMarcaProducto aux = primero;

    do
	{
        if (aux->codMarca == codMarca)
            // El código de marca ya existe en la lista
            return true;
            
        aux = aux->siguiente;
    } while (aux != primero);

    // El código de marca no está repetido en la lista
    return false;
}

void ListaCircularDMarcasProductos::eliminarMarcasProductos()
{
    if (ListaVacia())
    {
        cout << "La lista esta vacia." << endl;
        return;
    }

    pnodoMarcaProducto actual = primero;
    pnodoMarcaProducto siguiente;

    do
    {
        siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    } while (actual != primero);

    primero = NULL; // Establece primero como NULL después de eliminar todos los nodos
    cout << "Todos los nodos han sido eliminados." << endl;
}

pnodoMarcaProducto ListaCircularDMarcasProductos::buscarMarcaProducto(int codMarca)
{
	if (ListaVacia())
	{
        cout << "La lista de marcas esta vacia." << endl;
        return NULL;
    }

    pnodoMarcaProducto aux = primero;

    do
	{
        if (aux->codMarca == codMarca)
            return aux;

        aux = aux->siguiente;
    } while (aux != primero);

    return NULL;
}

void ListaCircularDMarcasProductos::modificarMarcaProducto(int codMarca, string nombre, int cantGondola, int precio)
{
    pnodoMarcaProducto marcaProducto = buscarMarcaProducto(codMarca);

    if (marcaProducto == NULL)
    {
        cout << "\nMarca no encontrada." << endl;
        return;
    }

    marcaProducto->codMarca = codMarca;
    marcaProducto->nombre = nombre;
    marcaProducto->cantGondola = cantGondola;
    marcaProducto->precio = precio;
}


ListaCircularDMarcasProductos::~ListaCircularDMarcasProductos()
{
    if (primero != NULL)
    {
        pnodoMarcaProducto aux = primero->siguiente;
        primero->siguiente = NULL; // Corta el enlace circular
        aux->anterior = NULL;
        primero = aux;

        while (aux != NULL)
		{
            pnodoMarcaProducto temp = aux;
            aux = aux->siguiente;
            delete temp;
        }
    }
}

void ListaCircularDMarcasProductos::InsertarInicio(int codPasillo, int codProducto, int codMarca, string nombre, int cantGondola, int precio)
{
    pnodoMarcaProducto nuevo = new NodoMarcaProducto(codPasillo, codProducto, codMarca, nombre, cantGondola, precio);

    if (ListaVacia())
    {
        primero = nuevo;
        primero->siguiente = primero; // Enlace circular
        primero->anterior = primero;  // Enlace circular
    }
    else
    {
        nuevo->siguiente = primero;
        nuevo->anterior = primero->anterior;
        primero->anterior->siguiente = nuevo;
        primero->anterior = nuevo;
        primero = nuevo; // Actualiza el puntero al último elemento
    }
}

void ListaCircularDMarcasProductos::InsertarFinal(int codPasillo, int codProducto, int codMarca, string nombre, int cantGondola, int precio)
{
    pnodoMarcaProducto nuevo = new NodoMarcaProducto(codPasillo, codProducto, codMarca, nombre, cantGondola, precio);

    if (ListaVacia())
    {
        primero = nuevo;
        primero->siguiente = primero; // Enlace circular
        primero->anterior = primero;  // Enlace circular
    }
    else
    {
        nuevo->siguiente = primero;
        nuevo->anterior = primero->anterior;
        primero->anterior->siguiente = nuevo;
        primero->anterior = nuevo; // Actualiza el puntero al último elemento
    }
}

void ListaCircularDMarcasProductos::InsertarPos(int codPasillo, int codProducto, int codMarca, string nombre, int cantGondola, int precio, int pos)
{
    if (ListaVacia() || pos <= 1)
        InsertarInicio(codPasillo, codProducto, codMarca, nombre, cantGondola, precio);
    else
    {
        pnodoMarcaProducto aux = primero;
        int i = 2;

        while ((i != pos) && (aux->siguiente != primero))
        {
            i++;
            aux = aux->siguiente;
        }

        pnodoMarcaProducto nuevo = new NodoMarcaProducto(codPasillo, codProducto, codMarca, nombre, cantGondola, precio);
        nuevo->siguiente = aux->siguiente;
        nuevo->anterior = aux;
        aux->siguiente->anterior = nuevo;
        aux->siguiente = nuevo;

        if (aux == primero)
            primero = nuevo; // Actualiza el puntero al último elemento
    }
}

void ListaCircularDMarcasProductos::BorrarInicio()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista." << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            delete primero;
            primero = NULL;
        }
        else
        {
            pnodoMarcaProducto aux = primero;

            aux->anterior->siguiente = primero->siguiente;
            primero->siguiente->anterior = aux->anterior;

            primero = primero->siguiente;

            delete aux;
        }
    }
}

void ListaCircularDMarcasProductos::BorrarFinal()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista." << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            delete primero;
            primero = NULL;
        }
        else
        {
            pnodoMarcaProducto aux = primero->anterior;

            aux->anterior->siguiente = primero;
            primero->anterior = aux->anterior;

            delete aux;
        }
    }
}

void ListaCircularDMarcasProductos::BorrarPosicion(int pos)
{
    if (ListaVacia())
        cout << "La lista esta vacia." << endl;
    else
    {
        if (pos == 1)
            BorrarInicio();
        else
        {
            int cont = 2;
            pnodoMarcaProducto aux = primero->siguiente;

            while (cont < pos && aux != primero)
            {
                aux = aux->siguiente;
                cont++;
            }

            if (cont == pos)
            {
                aux->anterior->siguiente = aux->siguiente;
                aux->siguiente->anterior = aux->anterior;

                if (aux == primero)
                    primero = aux->siguiente; // Actualiza el puntero al último elemento

                delete aux;
            }
            else
                cout << "Posicion no valida." << endl;
        }
    }
}

void ListaCircularDMarcasProductos::Mostrar()
{
    if (ListaVacia())
        cout << "La lista esta vacia." << endl;
    else
    {
        pnodoMarcaProducto aux = primero;

        do
        {
            // cout << aux->codPasillo << ", " << aux->codProducto
			// 	<< ", " << aux->codMarca << ", "  << aux->nombre
			// 	<< ", " << aux->cantGondola << ", " << aux->precio
			// 	<< " --> " << endl;
				
			cout << "--> CodPasillo: " << aux->codPasillo << endl;
			cout << "    CodProducto: " << aux->codProducto << endl;
			cout << "    CodMarca: " << aux->codMarca << endl;
			cout << "    Nombre: " << aux->nombre << endl;
			cout << "    CantGondola: " << aux->cantGondola << endl;
			cout << "    Precio: " << aux->precio << endl << endl;

            aux = aux->siguiente;
        } while (aux != primero);
    }
}

int ListaCircularDMarcasProductos::largoLista()
{
    if (ListaVacia())
        return 0;
    else
    {
        int cont = 0;
        pnodoMarcaProducto aux = primero;

        do
        {
            cont++;
            aux = aux->siguiente;
        } while (aux != primero);

        return cont;
    }
}



class NodoInventario
{
public:
    NodoInventario(int _codPasillo, int _codProducto, int _codMarca, int _codInventario, string _nombre, int _cantStock, bool _codCanasta)
    {
        codPasillo = _codPasillo;
        codProducto = _codProducto;
        codMarca = _codMarca;
        codInventario = _codInventario;
        nombre = _nombre;
        cantStock = _cantStock;
        codCanasta = _codCanasta;
        siguiente = NULL;
        anterior = NULL;
    }
    
    int getCodPasillo() { return codPasillo; }
    int getCodProducto() { return codProducto; }
    int getCodMarca() { return codMarca; }
    int getCodInventario() { return codInventario; }
	string getNombre() { return nombre; }
	int getCantStock() { return cantStock; }
	bool getCodCanasta() { return codCanasta; }

private:
    int codPasillo;
    int codProducto;
    int codMarca;
    int codInventario;
    string nombre;
    int cantStock;
    bool codCanasta;
    NodoInventario* siguiente;
    NodoInventario* anterior;

    friend class ListaDobleInventario;
};

typedef NodoInventario* pnodoInventario;


class ListaDobleInventario
{
public:
    ListaDobleInventario() { primero = NULL; }
    ~ListaDobleInventario();

    void InsertarInicio(int codPasillo, int codProducto, int codMarca, int codInventario, string nombre, int cantStock, bool codCanasta);
    void InsertarFinal(int codPasillo, int codProducto, int codMarca, int codInventario, string nombre, int cantStock, bool codCanasta);
    void InsertarPos(int codPasillo, int codProducto, int codMarca, int codInventario, string nombre, int cantStock, bool codCanasta, int pos);
    bool ListaVacia() { return primero == NULL; }
    void BorrarInicio();
    void BorrarFinal();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();
    void insertarInventario(int codPasillo, int codProducto, int codMarca, int codInventario, string nombre, int cantStock, bool codCanasta, ListaSimplePas& listaPasillos, ListaDobleProPasillos& listaProductos, ListaCircularDMarcasProductos& listaMarcasProductos);
    bool inventarioRepetido(int codInventario);
    void eliminarInventario(int codInventario, ListaSimplePas& listaPasillos);
    pnodoInventario buscarInventario(int codInventario);
    void modificarInventario(int codInventario, string nombre, int cantStock, bool codCanasta);

private:
    pnodoInventario primero;
};

void ListaDobleInventario::insertarInventario(int codPasillo, int codProducto, int codMarca, int codInventario, string nombre, int cantStock, bool codCanasta, ListaSimplePas& listaPasillos, ListaDobleProPasillos& listaProductos, ListaCircularDMarcasProductos& listaMarcasProductos)
{
    // Valida si el codPasillo existe en la lista simple de pasillos
    if (listaPasillos.pasilloRepetido(codPasillo) == false)
    {
    	cout << "Pasillo no exite" << endl;
        return;	
	}

    // Valida si el codProducto existe en la lista doble de productos de pasillo
    if (listaProductos.productoRepetido(codProducto) == false)
    {
    	cout << "Producto no exite" << endl;
        return;	
	}

    // Valida si el codMarca existe en la lista circular de marcas de productos
    if (!listaMarcasProductos.marcaProductoRepetida(codMarca))
    {
    	cout << "Marca no exite" << endl;
        return;	
	}

    // Valida si el codInventario no está repetido en la lista doble de inventario
    if (inventarioRepetido(codInventario))
    {
    	cout << "Codigo de inventario ya exite" << endl;
        return;	
	}

    // Inserta en la lista doble de inventario después de las validaciones
    InsertarFinal(codPasillo, codProducto, codMarca, codInventario, nombre, cantStock, codCanasta);
    
    cout << "\nInventario insertado exitosamente." << endl;
    cout << "Inventario insertado:" << endl;
    cout << " --> CodPasillo: " << codPasillo << endl;
    cout << "     CodProducto: " << codProducto << endl;
    cout << "     CodMarca: " << codMarca << endl;
    cout << "     CodInventario: " << codInventario << endl;
    cout << "     Nombre: " << nombre << endl;
    cout << "     CantStock: " << cantStock << endl;
    cout << "     CodCanasta: " << codCanasta << endl;
}

bool ListaDobleInventario::inventarioRepetido(int codInventario)
{
    pnodoInventario aux = primero;

    while (aux != NULL)
    {
        if (aux->codInventario == codInventario)
            // El código de inventario ya existe en la lista
            return true;

        aux = aux->siguiente;
    }

    // El código de inventario no está repetido en la lista
    return false;
}

void ListaDobleInventario::eliminarInventario(int codInventario, ListaSimplePas& listaPasillos)
{
    if (ListaVacia())
    {
        cout << "La lista esta vacia." << endl;
        return;
    }

    pnodoInventario actual = primero;

    while (actual != NULL)
    {
        if (actual->codInventario == codInventario)
        {
            // Verifica si el producto existe en el pasillo antes de eliminarlo
            int codPasillo = actual->codPasillo;

            // Verifica si el codPasillo existe en la lista simple de pasillos
            if (listaPasillos.pasilloRepetido(codPasillo))
            {
                cout << "El producto se mantiene en el pasillo." << endl;
                return;
            }
            else
            {
                // Como el pasillo no existe, elimina el producto del inventario
                BorrarPosicion(actual->codInventario);
                cout << "Producto eliminado del inventario exitosamente." << endl;
                return;
            }
        }

        actual = actual->siguiente;
    }
    
    cout << "No se encontro el producto con el codigo de inventario dado." << endl;
}

pnodoInventario ListaDobleInventario::buscarInventario(int codInventario)
{
	if (ListaVacia())
	{
        cout << "La lista de inventario esta vacia." << endl;
        return NULL;
    }

    pnodoInventario aux = primero;

    while (aux != NULL)
	{
        if (aux->codInventario == codInventario)
            return aux;

        aux = aux->siguiente;
    }

    return NULL;
}

void ListaDobleInventario::modificarInventario(int codInventario, string nombre, int cantStock, bool codCanasta)
{
    pnodoInventario inventario = buscarInventario(codInventario);

    if (inventario == NULL)
    {
        cout << "\nInventario no encontrado." << endl;
        return;
    }

    inventario->codInventario = codInventario;
    inventario->nombre = nombre;
    inventario->cantStock = cantStock;
    inventario->codCanasta = codCanasta;
}


ListaDobleInventario::~ListaDobleInventario()
{
    pnodoInventario aux;

    while (primero)
    {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

    primero = NULL;
}

void ListaDobleInventario::InsertarInicio(int codPasillo, int codProducto, int codMarca, int codInventario, string nombre, int cantStock, bool codCanasta)
{
    if (ListaVacia())
    {
        primero = new NodoInventario(codPasillo, codProducto, codMarca, codInventario, nombre, cantStock, codCanasta);
        primero->anterior = NULL;
    }
    else
    {
        pnodoInventario nuevo = new NodoInventario(codPasillo, codProducto, codMarca, codInventario, nombre, cantStock, codCanasta);
        nuevo->siguiente = primero;
        primero->anterior = nuevo;
        primero = nuevo;
    }
}

void ListaDobleInventario::InsertarFinal(int codPasillo, int codProducto, int codMarca, int codInventario, string nombre, int cantStock, bool codCanasta)
{
    if (ListaVacia())
    {
        primero = new NodoInventario(codPasillo, codProducto, codMarca, codInventario, nombre, cantStock, codCanasta);
        primero->anterior = NULL;
    }
    else
    {
        pnodoInventario aux = primero;

        while (aux->siguiente != NULL)
            aux = aux->siguiente;

        aux->siguiente = new NodoInventario(codPasillo, codProducto, codMarca, codInventario, nombre, cantStock, codCanasta);
        aux->siguiente->anterior = aux;
    }
}

void ListaDobleInventario::InsertarPos(int codPasillo, int codProducto, int codMarca, int codInventario, string nombre, int cantStock, bool codCanasta, int pos)
{
    if (ListaVacia())
    {
        primero = new NodoInventario(codPasillo, codProducto, codMarca, codInventario, nombre, cantStock, codCanasta);
        primero->anterior = NULL;
    }
    else
    {
        if (pos <= 1)
        {
            pnodoInventario nuevo = new NodoInventario(codPasillo, codProducto, codMarca, codInventario, nombre, cantStock, codCanasta);
            nuevo->siguiente = primero;

            if (primero != NULL)
                primero->anterior = nuevo;

            primero = nuevo;
        }
        else
        {
            pnodoInventario aux = primero;
            int i = 2;

            while ((i != pos) && (aux->siguiente != NULL))
            {
                i++;
                aux = aux->siguiente;
            }

            pnodoInventario nuevo = new NodoInventario(codPasillo, codProducto, codMarca, codInventario, nombre, cantStock, codCanasta);
            nuevo->siguiente = aux->siguiente;

            if (aux->siguiente != NULL)
                aux->siguiente->anterior = nuevo;

            aux->siguiente = nuevo;
            nuevo->anterior = aux;
        }
    }
}

void ListaDobleInventario::BorrarInicio()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista." << endl;
    else
    {
        if (primero->siguiente == NULL) {
            pnodoInventario temp = primero;
            primero = NULL;
            delete temp;
        }
        else {
            pnodoInventario temp = primero;
            primero = primero->siguiente;
            primero->anterior = NULL;
            delete temp;
        }
    }
}

void ListaDobleInventario::BorrarFinal()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista." << endl;
    else
    {
        if (primero->siguiente == NULL)
        {
            pnodoInventario temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoInventario aux = primero;
            while (aux->siguiente->siguiente != NULL)
                aux = aux->siguiente;

            pnodoInventario temp = aux->siguiente;
            aux->siguiente = NULL;
            delete temp;
        }
    }
}

void ListaDobleInventario::BorrarPosicion(int pos)
{
    if (ListaVacia())
        cout << "La lista esta vacia." << endl;
    else
    {
        if ((pos > largoLista()) || (pos < 0))
            cout << "Error en posicion." << endl;
        else
        {
            if (pos == 1)
                BorrarInicio();
            else
            {
                if (pos == largoLista())
                    BorrarFinal();
                else
                {
                    int cont = 2;
                    pnodoInventario aux = primero;

                    while (cont < pos)
                    {
                        aux = aux->siguiente;
                        cont++;
                    }

                    pnodoInventario temp = aux->siguiente;
                    aux->siguiente = aux->siguiente->siguiente;

                    if (aux->siguiente != NULL)
                        aux->siguiente->anterior = aux;

                    delete temp;
                }
            }
        }
    }
}

void ListaDobleInventario::Mostrar()
{
    pnodoInventario aux = primero;

    while (aux) {
        // cout << aux->codPasillo << ", " << aux->codProducto << ", " << aux->codMarca
        //     << ", " << aux->codInventario << ", " << aux->nombre << ", " << aux->cantStock
        //     << ", " << aux->codCanasta << " --> " << endl;
            
        cout << "--> CodPasillo: " << aux->codPasillo << endl;
		cout << "    CodProducto: " << aux->codProducto << endl;
		cout << "    CodMarca: " << aux->codMarca << endl;
		cout << "    CodInventario: " << aux->codInventario << endl;
		cout << "    Nombre: " << aux->nombre << endl;
		cout << "    CantStock: " << aux->cantStock << endl;
		cout << "    CodCanasta: " << aux->codCanasta << endl << endl;

        aux = aux->siguiente;
    }
}

int ListaDobleInventario::largoLista()
{
    int cont = 0;
    pnodoInventario aux = primero;

    while (aux != NULL)
    {
        aux = aux->siguiente;
        cont++;
    }

    return cont;
}



class NodoCiudad
{
public:
    NodoCiudad(int _codCiudad, string _nombre)
    {
        codCiudad = _codCiudad;
        nombre = _nombre;
        siguiente = NULL;
    }

	int getCodCiudad() { return codCiudad; }
	string getNombre() { return nombre; }

private:
    int codCiudad;
    string nombre;
    NodoCiudad* siguiente;

    friend class ListaCircularCiudades;
};

typedef NodoCiudad* pnodoCiudad;


class ListaCircularCiudades
{
public:
    ListaCircularCiudades() { primero = NULL; }
    ~ListaCircularCiudades();

    void InsertarInicio(int codCiudad, string nombre);
    void InsertarFinal(int codCiudad, string nombre);
    void InsertarPos(int codCiudad, string nombre, int pos);
    bool ListaVacia() { return primero == NULL; }
    void BorrarInicio();
    void BorrarFinal();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();
    void insertarCiudad(int codCiudad, string nombre);
    bool ciudadRepetida(int codCiudad);    
    void eliminarCiudad(int codCiudad);
    pnodoCiudad buscarCiudad(int codCiudad);
    void modificarCiudad(int codCiudad, string nombre);

private:
    pnodoCiudad primero;
};

void ListaCircularCiudades::insertarCiudad(int codCiudad, string nombre)
{
    // Valida si el codCiudad no está repetido
    if (ciudadRepetida(codCiudad) == false)
    {
        InsertarInicio(codCiudad, nombre);
        
        cout << "\nCiudad insertada exitosamente." << endl;
        cout << "Ciudad insertada:" << endl;
        cout << " --> CodCiudad: " << codCiudad << endl;
        cout << "     Nombre: " << nombre << endl;
    }
    else
        cout << "El codigo de ciudad ya existe en la lista." << endl;
}

bool ListaCircularCiudades::ciudadRepetida(int codCiudad)
{
    if (ListaVacia())
        return false; // La lista está vacía, no hay ciudades repetidas

    pnodoCiudad aux = primero;

    do
    {
        if (aux->codCiudad == codCiudad)
            // El código de ciudad ya existe en la lista
            return true;

        aux = aux->siguiente;
    } while (aux != primero);

    // El código de ciudad no está repetido en la lista
    return false;
}

void ListaCircularCiudades::eliminarCiudad(int codCiudad)
{
    if (ListaVacia())
    {
        cout << "La lista esta vacia." << endl;
        return;
    }

    pnodoCiudad actual = primero;
    int pos = 1;

    do
    {
        if (actual->codCiudad == codCiudad)
        {
            // Se encontró el nodo con el codCiudad dado, borrar en esa posición
            BorrarPosicion(pos);
            cout << "Ciudad eliminada exitosamente." << endl;
            return;
        }

        actual = actual->siguiente;
        pos++;
    } while (actual != primero);

    // No se encontró el codCiudad en la lista
    cout << "No se encontro la ciudad con el codigo dado." << endl;
}

pnodoCiudad ListaCircularCiudades::buscarCiudad(int codCiudad)
{
	if (ListaVacia())
	{
        cout << "La lista de inventario esta vacia." << endl;
        return NULL;
    }

    pnodoCiudad aux = primero;

    while (aux != NULL)
	{
        if (aux->codCiudad == codCiudad)
            return aux;

        aux = aux->siguiente;
    }

    return NULL;
}

void ListaCircularCiudades::modificarCiudad(int codCiudad, string nombre)
{
    // Busca la ciudad con el código dado
    pnodoCiudad ciudad = buscarCiudad(codCiudad);

    // Verifica si la ciudad no existe
    if (ciudad == NULL)
    {
        cout << "\nCiudad no encontrada." << endl;
        return;
    }

    // Modificar los atributos de la ciudad encontrado
    ciudad->codCiudad = codCiudad;
    ciudad->nombre = nombre;
}


ListaCircularCiudades::~ListaCircularCiudades()
{
    if (primero != NULL)
    {
        pnodoCiudad aux = primero->siguiente;
        primero->siguiente = NULL; // Corta el enlace circular
        primero = aux;

        while (aux != NULL)
        {
            pnodoCiudad temp = aux;
            aux = aux->siguiente;
            delete temp;
        }
    }
}

void ListaCircularCiudades::InsertarInicio(int codCiudad, string nombre)
{
    pnodoCiudad nuevo = new NodoCiudad(codCiudad, nombre);

    if (ListaVacia())
    {
        primero = nuevo;
        primero->siguiente = primero; // Enlace circular
    }
    else
    {
        nuevo->siguiente = primero->siguiente;
        primero->siguiente = nuevo;
    }
}

void ListaCircularCiudades::InsertarFinal(int codCiudad, string nombre)
{
    pnodoCiudad nuevo = new NodoCiudad(codCiudad, nombre);

    if (ListaVacia())
    {
        primero = nuevo;
        primero->siguiente = primero; // Enlace circular
    }
    else
    {
        nuevo->siguiente = primero->siguiente;
        primero->siguiente = nuevo;
        primero = nuevo; // Actualiza el puntero al último elemento
    }
}

void ListaCircularCiudades::InsertarPos(int codCiudad, string nombre, int pos)
{
    if (ListaVacia() || pos <= 1)
        InsertarInicio(codCiudad, nombre);
    else
    {
        pnodoCiudad aux = primero;
        int i = 2;

        while ((i != pos) && (aux->siguiente != primero))
        {
            i++;
            aux = aux->siguiente;
        }

        pnodoCiudad nuevo = new NodoCiudad(codCiudad, nombre);
        nuevo->siguiente = aux->siguiente;
        aux->siguiente = nuevo;

        if (aux == primero)
            primero = nuevo; // Actualiza el puntero al último elemento
    }
}

void ListaCircularCiudades::BorrarInicio()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista." << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            delete primero;
            primero = NULL;
        }
        else
        {
            pnodoCiudad aux = primero;

            while (aux->siguiente != primero)
                aux = aux->siguiente;

            pnodoCiudad temp = primero;
            aux->siguiente = primero->siguiente;
            primero = primero->siguiente;
            delete temp;
        }
    }
}

void ListaCircularCiudades::BorrarFinal()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista." << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            delete primero;
            primero = NULL;
        }
        else
        {
            pnodoCiudad aux = primero;

            while (aux->siguiente->siguiente != primero)
                aux = aux->siguiente;

            pnodoCiudad temp = aux->siguiente;
            aux->siguiente = primero;
            delete temp;
        }
    }
}

void ListaCircularCiudades::BorrarPosicion(int pos)
{
    if (ListaVacia())
        cout << "La lista esta vacia." << endl;
    else
    {
        if (pos == 1)
            BorrarInicio();
        else
        {
            int cont = 2;
            pnodoCiudad aux = primero;

            while (cont < pos)
            {
                aux = aux->siguiente;
                cont++;
            }

            pnodoCiudad temp = aux->siguiente;
            aux->siguiente = aux->siguiente->siguiente;

            if (temp == primero)
                primero = aux; // Actualiza el puntero al último elemento

            delete temp;
        }
    }
}

void ListaCircularCiudades::Mostrar()
{
    if (ListaVacia())
        cout << "La lista esta vacia." << endl;
    else
    {
        pnodoCiudad aux = primero;

        do
        {
            // cout << aux->codCiudad << ", " << aux->nombre << " --> " << endl;
            
			cout << "--> codCiudad: " << aux->codCiudad << endl;
			cout << "    Nombre: " << aux->nombre << endl << endl;

            aux = aux->siguiente;
        } while (aux != primero);
    }
}

int ListaCircularCiudades::largoLista()
{
    if (ListaVacia())
        return 0;
    else
    {
        int cont = 0;
        pnodoCiudad aux = primero;

        do
        {
            aux = aux->siguiente;
            cont++;
        } while (aux != primero);

        return cont;
    }
}



// Clase NodoCliente para la información de clientes
class NodoCliente
{
public:
    NodoCliente(int _cedula, string _nombre, int _codCiudad, string _telefono, string _correo)
    {
        cedula = _cedula;
        nombre = _nombre;
        codCiudad = _codCiudad;
        telefono = _telefono;
        correo = _correo;
        siguiente = NULL;
    }

    NodoCliente(int _cedula, string _nombre, int _codCiudad, string _telefono, string _correo, NodoCliente* _siguiente)
    {
        cedula = _cedula;
        nombre = _nombre;
        codCiudad = _codCiudad;
        telefono = _telefono;
        correo = _correo;
        siguiente = _siguiente;
    }
    
    int getCedula() { return cedula; }
    string getNombre() { return nombre; }
    int getCodCiudad() { return codCiudad; }
    string getTelefono() { return telefono; }
    string getCorreo() { return correo; }

private:
    int cedula;
    string nombre;
    int codCiudad;
    string telefono;
    string correo;
    NodoCliente* siguiente; // Clase de Autoreferencia

    friend class HashingClientes;
};

typedef NodoCliente* pnodoCte;



class HashingClientes
{
public:
    HashingClientes(int N); // Constructor
    ~HashingClientes();     // Destructor

	int funcionHash(int cedula) { return cedula % 13; }
    void insertarCliente(int cedula, string nombre, int codCiudad, string telefono, string correo);
    void eliminarCliente(int cedula);
    pnodoCte buscarCliente(int cedula);
    void modificarCliente(int cedula, string nombre, int codCiudad, string telefono, string correo);
    void mostrarHash();
    bool loginCliente(int cedula);

private:
	pnodoCte* tablaHash; // Puntero al arreglo que contiene los clientes
};

HashingClientes::HashingClientes(int N)
{
    tablaHash = new pnodoCte[13]();

    // Inicializa la tabla hash con NULL
    for (int i = 0; i < 13; i++)
        tablaHash[i] = NULL;
}

HashingClientes::~HashingClientes()
{
    for (int i = 0; i < 13; i++)
    {
        pnodoCte actual = tablaHash[i];

        while (actual != NULL)
        {
            pnodoCte siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }

    delete[] tablaHash;
}

// Método que inserta un nuevo cliente en la tabla hash
void HashingClientes::insertarCliente(int cedula, string nombre, int codCiudad, string telefono, string correo)
{
    // Falta validar que la ciudad exista

    // Aplica la función de hashing
    int indice = funcionHash(cedula);

    pnodoCte nuevoCliente = new NodoCliente(cedula, nombre, codCiudad, telefono, correo);

    // Verifica si ya hay un nodo en esa posición
    if (tablaHash[indice] == NULL)
        tablaHash[indice] = nuevoCliente;
    else
    {
        // Si ya hay un nodo, lo coloca al final de la lista
        pnodoCte actual = tablaHash[indice];

        while (actual->siguiente != NULL)
            actual = actual->siguiente;

        actual->siguiente = nuevoCliente;
    }
}

void HashingClientes::eliminarCliente(int cedula)
{
    int indice = funcionHash(cedula);

    pnodoCte actual = tablaHash[indice];
    pnodoCte anterior = NULL;

    while ((actual != NULL) && (actual->cedula != cedula))
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL)
    {
        cout << "Cliente no encontrado." << endl;
        return;
    }

    if (anterior == NULL)
        tablaHash[indice] = actual->siguiente;
    else
        anterior->siguiente = actual->siguiente;

    delete actual;
}

pnodoCte HashingClientes::buscarCliente(int cedula)
{
    int indice = funcionHash(cedula);

    pnodoCte actual = tablaHash[indice];

    while ((actual != NULL) && (actual->cedula != cedula))
        actual = actual->siguiente;

    return actual;
}

void HashingClientes::modificarCliente(int cedula, string nombre, int codCiudad, string telefono, string correo)
{
    pnodoCte cliente = buscarCliente(cedula);

    if (cliente == NULL)
    {
        cout << "\nCliente no encontrado." << endl;
        return;
    }

    cliente->nombre = nombre;
    cliente->codCiudad = codCiudad;
    cliente->telefono = telefono;
    cliente->correo = correo;
}

void HashingClientes::mostrarHash()
{
    for (int i = 0; i < 13; ++i)
    {
        cout << i;
        pnodoCte actual = tablaHash[i];

        while (actual != NULL)
        {
            cout << " --> Cedula: " << actual->cedula << endl;
			cout << "     Nombre: " << actual->nombre << endl;
			cout << "     Ciudad: " << actual->codCiudad << endl;
			cout << "     Telefono: " << actual->telefono << endl;
			cout << "     Correo: " << actual->correo << endl;
			
            actual = actual->siguiente;
        }

        cout << endl;
    }
}

bool HashingClientes::loginCliente(int cedula)
{
    pnodoCte cliente = buscarCliente(cedula);

    return ((cliente != NULL) && (cliente->cedula == cedula));
}



// Clase NodoAdmin para la información de administradores
class NodoAdmin
{
public:
    NodoAdmin(int _cedula, string _nombre, int _codCiudad, string _telefono, string _correo)
    {
        cedula = _cedula;
        nombre = _nombre;
        codCiudad = _codCiudad;
        telefono = _telefono;
        correo = _correo;
        siguiente = NULL;
    }

    NodoAdmin(int _cedula, string _nombre, int _codCiudad, string _telefono, string _correo, NodoAdmin* _siguiente)
    {
        cedula = _cedula;
        nombre = _nombre;
        codCiudad = _codCiudad;
        telefono = _telefono;
        correo = _correo;
        siguiente = _siguiente;
    }
    
    int getCedula() { return cedula; }
    string getNombre() { return nombre; }
    int getCodCiudad() { return codCiudad; }
    string getTelefono() { return telefono; }
    string getCorreo() { return correo; }

private:
    int cedula;
    string nombre;
    int codCiudad;
    string telefono;
    string correo;
    NodoAdmin* siguiente; // Clase de Autoreferencia

    friend class HashingAdmins;
};

typedef NodoAdmin* pnodoAdmin;



class HashingAdmins
{
public:
    HashingAdmins(int N); // Constructor
    ~HashingAdmins();     // Destructor

	int funcionHash(int cedula) { return cedula % 13; }
    void insertarAdmin(int cedula, string nombre, int codCiudad, string telefono, string correo);
    void eliminarAdmin(int cedula);
    pnodoAdmin buscarAdmin(int cedula);
    void modificarAdmin(int cedula, string nombre, int codCiudad, string telefono, string correo);
    void mostrarHash();
    bool loginAdmin(int cedula);

private:
    pnodoAdmin* tablaHash; // Puntero al arreglo que contiene los administradores
};

HashingAdmins::HashingAdmins(int N)
{
    tablaHash = new pnodoAdmin[13]();

    // Inicializa la tabla hash con NULL
    for (int i = 0; i < 13; i++)
        tablaHash[i] = NULL;
}

HashingAdmins::~HashingAdmins()
{
    for (int i = 0; i < 13; i++)
    {
        pnodoAdmin actual = tablaHash[i];

        while (actual != NULL)
        {
            pnodoAdmin siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }

    delete[] tablaHash;
}

// Método que inserta un nuevo administrador en la tabla hash
void HashingAdmins::insertarAdmin(int cedula, string nombre, int codCiudad, string telefono, string correo)
{
    // Validar que la ciudad exista

    // Aplica la función de hashing
    int indice = funcionHash(cedula);

    pnodoAdmin nuevoAdmin = new NodoAdmin(cedula, nombre, codCiudad, telefono, correo);

    // Verifica si ya hay un nodo en esa posición
    if (tablaHash[indice] == NULL)
        tablaHash[indice] = nuevoAdmin;
    else
    {
        // Si ya hay un nodo, lo coloca al final de la lista
        pnodoAdmin actual = tablaHash[indice];

        while (actual->siguiente != NULL)
            actual = actual->siguiente;

        actual->siguiente = nuevoAdmin;
    }
}

void HashingAdmins::eliminarAdmin(int cedula)
{
    int indice = funcionHash(cedula);

    pnodoAdmin actual = tablaHash[indice];
    pnodoAdmin anterior = NULL;

    while ((actual != NULL) && (actual->cedula != cedula))
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL)
    {
        cout << "Administrador no encontrado." << endl;
        return;
    }

    if (anterior == NULL)
        tablaHash[indice] = actual->siguiente;
    else
        anterior->siguiente = actual->siguiente;

    delete actual;
}

pnodoAdmin HashingAdmins::buscarAdmin(int cedula)
{
    int indice = funcionHash(cedula);

    pnodoAdmin actual = tablaHash[indice];

    while ((actual != NULL) && (actual->cedula != cedula))
        actual = actual->siguiente;

    return actual;
}

void HashingAdmins::modificarAdmin(int cedula, string nombre, int codCiudad, string telefono, string correo)
{
    pnodoAdmin admin = buscarAdmin(cedula);

    if (admin == NULL)
    {
        cout << "Administrador no encontrado." << endl;
        return;
    }

    admin->nombre = nombre;
    admin->codCiudad = codCiudad;
    admin->telefono = telefono;
    admin->correo = correo;
}

void HashingAdmins::mostrarHash()
{
    for (int i = 0; i < 13; ++i)
    {
        cout << i;
        pnodoAdmin actual = tablaHash[i];

        while (actual != NULL)
        {
            cout << " --> Cedula: " << actual->cedula << endl;
			cout << "     Nombre: " << actual->nombre << endl;
			cout << "     Ciudad: " << actual->codCiudad << endl;
			cout << "     Telefono: " << actual->telefono << endl;
			cout << "     Correo: " << actual->correo << endl;
			
            actual = actual->siguiente;
        }

        cout << endl;
    }
}

bool HashingAdmins::loginAdmin(int cedula)
{
    pnodoAdmin admin = buscarAdmin(cedula);

    return ((admin != NULL) && (admin->cedula == cedula));
}



// Función que convierte un string a entero
int stringAInt(string str)
{
    istringstream iss(str);
    int res;
    
    if (!(iss >> res))
	{
        cout << "No se pudo convertir la cadena a entero." << endl;
        return 0;
    }
    
    return res;
}

// Función que convierte "1" o "0" a booleano 
bool stringABool(string str)
{
    istringstream iss(str);
    bool res;

    if (str == "1")
        return true;
    else if (str == "0")
        return false;
    else
    {
        cout << "No se puede convertir la cadena a bool." << endl;
        return false;
    }
}



void crearListaPasillos(ListaSimplePas& listaPasillos)
{
	ifstream archivo("Pasillos.txt");

    if (!archivo)
	{
        cout << "\nNo se pudo abrir el archivo Pasillos.txt" << endl;
        return;
    }

    string linea;
    int contador = 0;

    while (getline(archivo, linea))
	{
        // Ignora líneas vacías
        if (linea == "")
            continue;

        // Incrementa el contador para ignorar la primera línea
        contador++;

        // Comienza a procesar las líneas a partir de la segunda
        if (contador > 1)
		{
            istringstream ss(linea);
            string codPasillo, nombre;
            
            getline(ss, codPasillo, ';'); ss >> ws;
            getline(ss, nombre, ';'); ss >> ws;

			// Inserta en la lista simple de pasillos después de las validaciones
            listaPasillos.insertarPasillo(stringAInt(codPasillo), nombre);
        }
    }

    archivo.close();
}

void crearListaProductos(ListaDobleProPasillos& listaProductos, ListaSimplePas& listaPasillos)
{
    ifstream archivo("ProductosPasillos.txt");

    if (!archivo)
    {
        cout << "No se pudo abrir el archivo ProductosPasillos.txt" << endl;
        return;
    }

    string linea;
    int contador = 0;

    while (getline(archivo, linea))
    {
        // Ignora líneas vacías
        if (linea == "")
            continue;

        // Incrementa el contador para ignorar la primera línea
        contador++;

        // Comienza a procesar las líneas a partir de la segunda
        if (contador > 1)
        {
            istringstream ss(linea);
            string codPasillo, codProducto, nombre;
            
            getline(ss, codPasillo, ';'); ss >> ws;
            getline(ss, codProducto, ';'); ss >> ws;
            getline(ss, nombre, ';'); ss >> ws;

            // Inserta en la lista doble de productos después de las validaciones
            listaProductos.insertarProPasillo(stringAInt(codPasillo), stringAInt(codProducto), nombre, listaPasillos);
        }
    }

    archivo.close();
}

void crearListaMarcasProductos(ListaCircularDMarcasProductos& listaMarcas, ListaSimplePas& listaPasillos, ListaDobleProPasillos& listaProductos)
{
    ifstream archivo("MarcasProductos.txt");

    if (!archivo)
    {
        cout << "No se pudo abrir el archivo MarcasProductos.txt" << endl;
        return;
    }

    string linea;
    int contador = 0;

    while (getline(archivo, linea))
    {
        // Ignora líneas vacías
        if (linea == "")
            continue;

        // Incrementa el contador para ignorar la primera línea
        contador++;

        // Comienza a procesar las líneas a partir de la segunda
        if (contador > 1)
        {
            istringstream ss(linea);
            string codPasillo, codProducto, codMarca, nombre, cantGondola, precio;
            
            getline(ss, codPasillo, ';'); ss >> ws;
            getline(ss, codProducto, ';'); ss >> ws;
            getline(ss, codMarca, ';'); ss >> ws;
            getline(ss, nombre, ';'); ss >> ws;
            getline(ss, cantGondola, ';'); ss >> ws;
            getline(ss, precio, ';'); ss >> ws;

            // Inserta en la lista circular doble de marcas después de las validaciones
            listaMarcas.insertarMarcaProducto(stringAInt(codPasillo), stringAInt(codProducto), stringAInt(codMarca), nombre, stringAInt(cantGondola), stringAInt(precio), listaPasillos, listaProductos);
        }
    }

    archivo.close();
}

void crearListaInventario(ListaDobleInventario& listaInventario, ListaSimplePas& listaPasillos, ListaDobleProPasillos& listaProductos, ListaCircularDMarcasProductos& listaMarcas)
{
	ifstream archivo("Inventario.txt");

    if (!archivo)
    {
        cout << "No se pudo abrir el archivo Inventario.txt" << endl;
        return;
    }

    string linea;
    int contador = 0;

    while (getline(archivo, linea))
    {
        // Ignora líneas vacías
        if (linea == "")
            continue;

        // Incrementa el contador para ignorar la primera línea
        contador++;

        // Comienza a procesar las líneas a partir de la segunda
        if (contador > 1)
        {
            istringstream ss(linea);
            string codPasillo, codProducto, codMarca, codInventario, nombre, cantidadStock, codigoCanasta;
            
            getline(ss, codPasillo, ';'); ss >> ws;
            getline(ss, codProducto, ';'); ss >> ws;
            getline(ss, codMarca, ';'); ss >> ws;
            getline(ss, codInventario, ';'); ss >> ws;
            getline(ss, nombre, ';'); ss >> ws;
            getline(ss, cantidadStock, ';'); ss >> ws;
            getline(ss, codigoCanasta, ';'); ss >> ws;

            // Inserta en la lista doble de inventario después de las validaciones
            listaInventario.insertarInventario(stringAInt(codPasillo), stringAInt(codProducto), stringAInt(codMarca), stringAInt(codInventario), nombre, stringAInt(cantidadStock), stringABool(codigoCanasta), listaPasillos, listaProductos, listaMarcas);
        }
    }

    archivo.close();
}

void crearListaCiudades(ListaCircularCiudades& listaCiudades)
{
	ifstream archivo("Ciudades.txt");
	
	if (!archivo)
	{
	    cout << "No se pudo abrir el archivo Ciudades.txt" << endl;
	    return;
	}

	string linea;
	int contador = 0;
	
	while (getline(archivo, linea))
	{
	    // Ignora líneas vacías
	    if (linea == "")
	        continue;
	
	    // Incrementa el contador para ignorar la primera línea
	    contador++;
	
	    // Comienza a procesar las líneas a partir de la segunda
	    if (contador > 1)
	    {
	        istringstream ss(linea); ss >> ws;
	        string codCiudad, nombre;
	        
	        getline(ss, codCiudad, ';'); ss >> ws;
	        getline(ss, nombre, ';'); ss >> ws;
	
	        // Inserta en la lista circular simple de ciudades después de las validaciones
	        listaCiudades.insertarCiudad(stringAInt(codCiudad), nombre);
	    }
	}
}



void cargarClientesDesdeArchivo(HashingClientes& hashClientes)
{
    ifstream archivo("Clientes.txt");

    if (!archivo)
	{
        cout << "No se pudo abrir el archivo Clientes.txt" << endl;
        return;
    }

    string linea;
    int contador = 0;

    while (getline(archivo, linea))
	{
        // Ignora líneas vacías
        if (linea == "")
            continue;

        // Incrementa el contador para ignorar la primera línea
        contador++;

        // Comienza a procesar las líneas a partir de la segunda
        if (contador > 1)
		{
            istringstream ss(linea);
            string cedula, nombre, codCiudad, telefono, correo;
            
            getline(ss, cedula, ';'); ss >> ws;
            getline(ss, nombre, ';'); ss >> ws;
            getline(ss, codCiudad, ';'); ss >> ws;
            getline(ss, telefono, ';'); ss >> ws;
            getline(ss, correo, ';'); ss >> ws;

            // Inserta en el hash de clientes después de las validaciones
            hashClientes.insertarCliente(stringAInt(cedula), nombre, stringAInt(codCiudad), telefono, correo);
        }
    }

    archivo.close();
}

void cargarAdminsDesdeArchivo(HashingAdmins& hashAdmins)
{
    ifstream archivo("Administradores.txt");

    if (!archivo)
	{
        cout << "No se pudo abrir el archivo Administradores.txt" << endl;
        return;
    }

    string linea;
    int contador = 0;

    while (getline(archivo, linea))
	{
        // Ignora líneas vacías
        if (linea == "")
            continue;

        istringstream ss(linea);
        string cedula, nombre, codCiudad, telefono, correo;
        
        getline(ss, cedula, ';'); ss >> ws;
        getline(ss, nombre, ';'); ss >> ws;
        getline(ss, codCiudad, ';'); ss >> ws;
        getline(ss, telefono, ';'); ss >> ws;
        getline(ss, correo, ';'); ss >> ws;

        // Inserta en el hash de administradores después de las validaciones
        hashAdmins.insertarAdmin(stringAInt(cedula), nombre, stringAInt(codCiudad), telefono, correo);
    }

    archivo.close();
}



void menuAdiministrador()
{
	cout << "************MENU************" << endl;
    cout << "1. Insertar" << endl;
    cout << "2. Eliminar" << endl;
    cout << "3. Buscar" << endl;
    cout << "4. Modificar" << endl;
    cout << "5. Listar" << endl;
    cout << "6. Reportes" << endl;
    cout << "7. Salir" << endl;
}

void menuCliente()
{
    cout << "************MENU************" << endl;
    cout << "1. Buscar" << endl;
    cout << "2. Algunos reportes" << endl;
    cout << "3. Salir" << endl;
}



void menuInsertar(int opcion, ListaSimplePas& listaPasillos, ListaDobleProPasillos& listaProductos,
	ListaCircularDMarcasProductos& listaMarcasProductos, ListaDobleInventario& listaInventario,
	HashingClientes& hashClientes, HashingAdmins& hashAdmins, ListaCircularCiudades& listaCiudades)
{
	do
    {
        cout << "\n************INSERTAR:************" << endl;
	    cout << "1. Pasillo" << endl;
	    cout << "2. Producto" << endl;
	    cout << "3. Marca" << endl;
	    cout << "4. Inventario" << endl;
	    cout << "5. Cliente" << endl;
	    cout << "6. Administrador" << endl;
	    cout << "7. Ciudad" << endl;
	    cout << "8. Volver" << endl;
	    
	    cout << "\nIngrese la opcion deseada: ";
		cin >> opcion;

        switch (opcion)
        {
            case 1:
			{
                int codPasillo;
                string nombre;
                
                cout << "Ingrese el codigo del pasillo: "; cin >> codPasillo;
                cout << "Ingrese el nombre del pasillo: "; cin.ignore(); getline(cin, nombre);
                
				listaPasillos.insertarPasillo(codPasillo, nombre); 
				break;
			}

            case 2:
            {
                int codPasillo, codProducto;
                string nombre;
                
                cout << "Ingrese el codigo del pasillo: "; cin >> codPasillo;
                cout << "Ingrese el codigo del producto: "; cin >> codProducto;
                cout << "Ingrese el nombre del producto: "; cin.ignore(); getline(cin, nombre);
                
				listaProductos.insertarProPasillo(codPasillo, codProducto, nombre, listaPasillos); 
				break;
			}

            case 3:
            {
                int codPasillo, codProducto, codMarca, cantGondola, precio;
                string nombre;
                
                cout << "Ingrese el codigo del pasillo: "; cin >> codPasillo;
                cout << "Ingrese el codigo del producto: "; cin >> codProducto;
                cout << "Ingrese el codigo de la marca: "; cin >> codMarca;
                cout << "Ingrese el nombre del producto: "; cin.ignore(); getline(cin, nombre);
                cout << "Ingrese el cantidad en gondola: "; cin >> cantGondola;
                cout << "Ingrese el precio del producto: "; cin >> precio;
                
				listaMarcasProductos.insertarMarcaProducto(codPasillo, codProducto, codMarca, nombre, cantGondola, precio, listaPasillos, listaProductos); 
				break;
			}

            case 4:
            {
                int codPasillo, codProducto, codMarca, codInventario, cantStock;
                string nombre;
                bool codCanasta;
                
                cout << "Ingrese el codigo del pasillo: "; cin >> codPasillo;
                cout << "Ingrese el codigo del producto: "; cin >> codProducto;
                cout << "Ingrese el codigo de la marca: "; cin >> codMarca;
                cout << "Ingrese el codigo del inventario: "; cin >> codInventario;
                cout << "Ingrese el nombre del producto: "; cin.ignore(); getline(cin, nombre);
                cout << "Ingrese el cantidad de stock: "; cin >> cantStock;
                cout << "Ingrese el codigo de canasta: "; cin >> codCanasta;
                
				listaInventario.insertarInventario(codPasillo, codProducto, codMarca, codInventario, nombre, cantStock, codCanasta, listaPasillos, listaProductos, listaMarcasProductos); 
				break;
			}

            case 5:
            {
                int cedula, codCiudad;
                string nombre, telefono, correo;
                
                cout << "Ingrese la cedula del cliente: "; cin >> cedula;
                cout << "Ingrese el nombre del cliente: "; cin.ignore(); getline(cin, nombre);
                cout << "Ingrese el codigo de la ciudad del cliente: "; cin >> codCiudad;
                cout << "Ingrese el telefono del cliente: "; cin >> telefono;
                cout << "Ingrese el correo del cliente: "; cin >> correo;
                
				hashClientes.insertarCliente(cedula, nombre, codCiudad, telefono, correo);
                break;
            }
            
            case 6:
            {
                int cedula, codCiudad;
                string nombre, telefono, correo;
                
                cout << "Ingrese la cedula del administrador: "; cin >> cedula;
                cout << "Ingrese el nombre del administrador: "; cin.ignore(); getline(cin, nombre);
                cout << "Ingrese el codigo de la ciudad del administrador: "; cin >> codCiudad;
                cout << "Ingrese el telefono del administrador: "; cin >> telefono;
                cout << "Ingrese el correo del administrador: "; cin >> correo;
                
				hashAdmins.insertarAdmin(cedula, nombre, codCiudad, telefono, correo);
                break;
            }
            
            case 7:
            {
                int codCiudad;
                string nombre;
                
                cout << "Ingrese el codigo de la ciudad: "; cin >> codCiudad;
                cout << "Ingrese el nombre de la ciudad: "; cin.ignore(); getline(cin, nombre);
                
				listaCiudades.insertarCiudad(codCiudad, nombre); 
				break;
			}
            
            case 8:
				system("cls");
				cout << endl; break;
            
            default:
				system("cls");
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 8);
}

void menuEliminar(int opcion, ListaSimplePas& listaPasillos, ListaDobleProPasillos& listaProductos,
	ListaCircularDMarcasProductos& listaMarcasProductos, ListaDobleInventario& listaInventario,
	HashingClientes& hashClientes, HashingAdmins& hashAdmins, ListaCircularCiudades& listaCiudades)
{
	do
    {
        cout << "\n************ELIMINAR:************" << endl;
	    cout << "1. Pasillo" << endl;
	    cout << "2. Producto" << endl;
	    cout << "3. Marca" << endl;
	    cout << "4. Inventario" << endl;
	    cout << "5. Cliente" << endl;
	    cout << "6. Administrador" << endl;
	    cout << "7. Ciudad" << endl;
	    cout << "8. Volver" << endl;
	    
	    cout << "\nIngrese la opcion deseada: ";
		cin >> opcion;

        switch (opcion)
        {
            case 1:
            {
            	int pasilloAEliminar;
				
                cout << "\nPasillos:" << endl;
                listaPasillos.Mostrar();

				cout << "Ingrese el codigo del pasillo a eliminar: "; cin >> pasilloAEliminar;
                
				listaPasillos.eliminarPasillo(pasilloAEliminar);
                break;
            }

            case 2:
            {
            	int productoAEliminar;
				
                cout << "\nProductos:" << endl;
                listaProductos.Mostrar();

				cout << "Ingrese el codigo del producto a eliminar: "; cin >> productoAEliminar;
                
				listaProductos.eliminarProPasillo(productoAEliminar);
                break;
			}

            case 3:
            {
            	cout << "\nMarcas:" << endl;
                listaMarcasProductos.Mostrar();

				listaMarcasProductos.eliminarMarcasProductos();
				
				cout << "\nMarcas:" << endl;
                listaMarcasProductos.Mostrar();
                break;
			}

            case 4:
            {
            	int inventarioAEliminar;
				
                cout << "\nInventario:" << endl;
                listaInventario.Mostrar();

				cout << "Ingrese el codigo del inventario a eliminar: "; cin >> inventarioAEliminar;
                
				listaInventario.eliminarInventario(inventarioAEliminar, listaPasillos);
                break;
			}
            
            case 5:
            {
                int cedulaAEliminar;
                
				cout << "Ingrese la cedula del cliente a eliminar: "; cin >> cedulaAEliminar;
                
				hashClientes.eliminarCliente(cedulaAEliminar);
                break;
            }
            
            case 6:
        	{
                int cedulaAEliminar;
                
				cout << "Ingrese la cedula del administrador a eliminar: "; cin >> cedulaAEliminar;
                
				hashAdmins.eliminarAdmin(cedulaAEliminar);
                break;
            }
            
            case 7:
            {
            	int ciudadAEliminar;
				
                cout << "\nCiudades:" << endl;
                listaCiudades.Mostrar();

				cout << "Ingrese el codigo de la ciudad a eliminar: "; cin >> ciudadAEliminar;
                
				listaCiudades.eliminarCiudad(ciudadAEliminar);
                break;
			}
            
            case 8:
				system("cls");
				cout << endl; break;
            
            default:
				system("cls");
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 8);
}

void menuBuscar(int opcion, ListaSimplePas& listaPasillos, ListaDobleProPasillos& listaProductos,
	ListaCircularDMarcasProductos& listaMarcasProductos, ListaDobleInventario& listaInventario,
	HashingClientes& hashClientes, HashingAdmins& hashAdmins, ListaCircularCiudades& listaCiudades)
{
	do
    {
        cout << "\n************BUSCAR:************" << endl;
	    cout << "1. Pasillo" << endl;
	    cout << "2. Producto" << endl;
	    cout << "3. Marca" << endl;
	    cout << "4. Inventario" << endl;
	    cout << "5. Cliente" << endl;
	    cout << "6. Administrador" << endl;
	    cout << "7. Ciudad" << endl;
	    cout << "8. Volver" << endl;
	    
	    cout << "\nIngrese la opcion deseada: ";
		cin >> opcion;

        switch (opcion)
        {
            case 1:
            {
            	int codPasilloABuscar;
                
				cout << "Ingrese el codigo del pasillo a buscar: "; cin >> codPasilloABuscar;
                
				pnodoPasillo pasilloBuscado = listaPasillos.buscarPasillo(codPasilloABuscar);
				
                if (pasilloBuscado != NULL)
				{
                    cout << "\nPasillo encontrado:" << endl;
                    cout << "CodPasillo: " << pasilloBuscado->getCodPasillo() << endl;
                    cout << "Nombre: " << pasilloBuscado->getNombre() << endl;
                }
				else
                    cout << "\nPasillo con codigo " << codPasilloABuscar << " no encontrado." << endl;
                break;
			}
			
            case 2:
            {
            	int codProductoABuscar;
                
				cout << "Ingrese el codigo del producto a buscar: "; cin >> codProductoABuscar;
                
				pnodoProPasillo productoBuscado = listaProductos.buscarProPasillo(codProductoABuscar);
				
                if (productoBuscado != NULL)
				{
                    cout << "\nProducto encontrado:" << endl;
                    cout << "CodPasillo: " << productoBuscado->getCodPasillo() << endl;
                    cout << "CodProducto: " << productoBuscado->getCodProducto() << endl;
                    cout << "Nombre: " << productoBuscado->getNombre() << endl;
                }
				else
                    cout << "\nPasillo con codigo " << codProductoABuscar << " no encontrado." << endl;
                break;
			}

            case 3:
            {
            	int codMarcaABuscar;
                
				cout << "Ingrese el codigo de la marca a buscar: "; cin >> codMarcaABuscar;
                
				pnodoMarcaProducto marcaBuscada = listaMarcasProductos.buscarMarcaProducto(codMarcaABuscar);
				
                if (marcaBuscada != NULL)
				{
					cout << "\nMarca encontrada:" << endl;
                    cout << "Codigo de pasillo: " << marcaBuscada->getCodPasillo() << endl;
		            cout << "Codigo de producto: " << marcaBuscada->getCodProducto() << endl;
		            cout << "Codigo de marca: " << marcaBuscada->getCodMarca() << endl;
		            cout << "Nombre: " << marcaBuscada->getNombre() << endl;
		            cout << "Cantidad en góndola: " << marcaBuscada->getCantGondola() << endl;
		            cout << "Precio: " << marcaBuscada->getPrecio() << endl;
                }
				else
                    cout << "\nMarca con codigo " << codMarcaABuscar << " no encontrada." << endl;
                break;
			}

            case 4:
            {
            	int codInventarioABuscar;
                
				cout << "Ingrese el codigo del inventario a buscar: "; cin >> codInventarioABuscar;
                
				pnodoInventario inventarioBuscado = listaInventario.buscarInventario(codInventarioABuscar);
				
                if (inventarioBuscado != NULL)
				{
					cout << "\nMarca encontrada:" << endl;
                    cout << "Codigo de pasillo: " << inventarioBuscado->getCodPasillo() << endl;
		            cout << "Codigo de producto: " << inventarioBuscado->getCodProducto() << endl;
		            cout << "Codigo de marca: " << inventarioBuscado->getCodMarca() << endl;
		            cout << "Codigo de inventario: " << inventarioBuscado->getCodInventario() << endl;
		            cout << "Nombre: " << inventarioBuscado->getNombre() << endl;
		            cout << "Cantidad en stock: " << inventarioBuscado->getCantStock() << endl;
		            cout << "Codigo de canasta: " << inventarioBuscado->getCodCanasta() << endl;
                }
				else
                    cout << "\nInventario con codigo " << codInventarioABuscar << " no encontrado." << endl;
                break;
			}
            
            case 5:
            {
	            int cedulaABuscar;
	            
				cout << "Ingrese la cedula del cliente a buscar: "; cin >> cedulaABuscar;
	            
				pnodoCte clienteBuscado = hashClientes.buscarCliente(cedulaABuscar);
				
	            if (clienteBuscado != NULL)
				{
	                cout << "\nCliente encontrado:" << endl;
	                cout << "Cedula: " << clienteBuscado->getCedula() << endl;
	                cout << "Nombre: " << clienteBuscado->getNombre() << endl;
	                cout << "Ciudad: " << clienteBuscado->getCodCiudad() << endl;
	                cout << "Telefono: " << clienteBuscado->getTelefono() << endl;
	                cout << "Correo: " << clienteBuscado->getCorreo() << endl;
	            }
				else
	                cout << "\nCliente con cedula " << cedulaABuscar << " no encontrado." << endl;
	            break;
	        }
            
            case 6:
            {
                int cedulaABuscar;
                
				cout << "Ingrese la cedula del administrador a buscar: "; cin >> cedulaABuscar;
                
				pnodoAdmin adminBuscado = hashAdmins.buscarAdmin(cedulaABuscar);
				
                if (adminBuscado != NULL)
				{
                    cout << "\nAdministrador encontrado:" << endl;
                    cout << "Cedula: " << adminBuscado->getCedula() << endl;
                    cout << "Nombre: " << adminBuscado->getNombre() << endl;
                    cout << "Ciudad: " << adminBuscado->getCodCiudad() << endl;
                    cout << "Telefono: " << adminBuscado->getTelefono() << endl;
                    cout << "Correo: " << adminBuscado->getCorreo() << endl;
                }
				else
                    cout << "\nAdministrador con cedula " << cedulaABuscar << " no encontrado." << endl;
                break;
            }
            
            case 7:
            {
            	int codCiudadABuscar;
                
				cout << "Ingrese el codigo de la ciudad a buscar: "; cin >> codCiudadABuscar;
                
				pnodoCiudad ciudadBuscada = listaCiudades.buscarCiudad(codCiudadABuscar);
				
                if (ciudadBuscada != NULL)
				{
                    cout << "\nCiudad encontrada:" << endl;
                    cout << "Codigo de ciudad: " << ciudadBuscada->getCodCiudad() << endl;
                    cout << "Nombre: " << ciudadBuscada->getNombre() << endl;
                }
				else
                    cout << "\nCiudad con codigo " << codCiudadABuscar << " no encontrada." << endl;
                break;
			}
            
            case 8:
				system("cls");
				cout << endl; break;
            
            default:
				system("cls");
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 8);
}

void menuModificar(int opcion, ListaSimplePas& listaPasillos, ListaDobleProPasillos& listaProductos,
	ListaCircularDMarcasProductos& listaMarcasProductos, ListaDobleInventario& listaInventario,
	HashingClientes& hashClientes, HashingAdmins& hashAdmins, ListaCircularCiudades& listaCiudades)
{
	do
    {
        cout << "\n************MODIFICAR:************" << endl;
	    cout << "1. Pasillo" << endl;
	    cout << "2. Producto" << endl;
	    cout << "3. Marca" << endl;
	    cout << "4. Inventario" << endl;
	    cout << "5. Cliente" << endl;
	    cout << "6. Administrador" << endl;
	    cout << "7. Ciudad" << endl;
	    cout << "8. Volver" << endl;
	    
	    cout << "\nIngrese la opcion deseada: ";
		cin >> opcion;

        switch (opcion)
        {
            case 1:
            {
                int codPasilloAModificar;
                string nombre;
                
                cout << "\nPasillos:" << endl;
                listaPasillos.Mostrar();
                
                cout << "Ingrese el codigo del pasillo a modificar: "; cin >> codPasilloAModificar;
                cout << "Ingrese el nuevo nombre del pasillo: "; cin.ignore(); getline(cin, nombre);
                
                listaPasillos.modificarPasillo(codPasilloAModificar, nombre);
                break;
            }

            case 2:
            {
            	int codProductoAModificar;
                string nombre;
                
                cout << "\nProductos:" << endl;
                listaProductos.Mostrar();
                
                cout << "Ingrese el codigo del producto a modificar: "; cin >> codProductoAModificar;
                cout << "Ingrese el nuevo nombre del producto: "; cin.ignore(); getline(cin, nombre);
                
                listaProductos.modificarProPasillo(codProductoAModificar, nombre);
                
                cout << "\nProductos:" << endl;
                listaProductos.Mostrar();
                break;
			}

            case 3:
            {
            	int codMarcaAModificar, cantGondola, precio;
                string nombre;
                
                cout << "\nMarcas:" << endl;
                listaMarcasProductos.Mostrar();
                
                cout << "Ingrese el codigo de la marca a modificar: "; cin >> codMarcaAModificar;
                cout << "Ingrese el nuevo nombre de la marca: "; cin.ignore(); getline(cin, nombre);
                cout << "Ingrese la nueva cantidad de producto en la gondola: "; cin >> cantGondola;
                cout << "Ingrese el nuevo precio del producto: "; cin >> precio;
                
                listaMarcasProductos.modificarMarcaProducto(codMarcaAModificar, nombre, cantGondola, precio);
                
                cout << "\nMarcas:" << endl;
                listaMarcasProductos.Mostrar();
                break;
			}

            case 4:
            {
            	int codInventarioAModificar, cantStock;
                string nombre;
                bool codCanasta;
                
                cout << "\nInventario:" << endl;
                listaInventario.Mostrar();
                
                cout << "Ingrese el codigo del inventario a modificar: "; cin >> codInventarioAModificar;
                cout << "Ingrese el nuevo nombre de la marca: "; cin.ignore(); getline(cin, nombre);
                cout << "Ingrese la nueva cantidad de stock: "; cin >> cantStock;
                cout << "Indique si el producto es de canasta basica: "; cin >> codCanasta;
                
                listaInventario.modificarInventario(codInventarioAModificar, nombre, cantStock, codCanasta);
                
                cout << "\nInventario:" << endl;
                listaInventario.Mostrar();
                break;
			}
            
            case 5:
            {
                int cedulaAModificar, codCiudad;
                string nombre, telefono, correo;
                
                cout << "Ingrese la cedula del cliente a modificar: "; cin >> cedulaAModificar;
                cout << "Ingrese el nuevo nombre del cliente: "; cin.ignore(); getline(cin, nombre);
                cout << "Ingrese el nuevo codigo de la ciudad del cliente: "; cin >> codCiudad;
                cout << "Ingrese el nuevo telefono del cliente: "; cin >> telefono;
                cout << "Ingrese el nuevo correo del cliente: "; cin >> correo;
                
                hashClientes.modificarCliente(cedulaAModificar, nombre, codCiudad, telefono, correo);
                break;
            }
            
            case 6:
            {
                int cedulaAModificar, codCiudad;
                string nombre, telefono, correo;
                
                cout << "Ingrese la cedula del administrador a modificar: "; cin >> cedulaAModificar;
                cout << "Ingrese el nuevo nombre del administrador: "; cin.ignore(); getline(cin, nombre);
                cout << "Ingrese el nuevo codigo de la ciudad del administrador: "; cin >> codCiudad;
                cout << "Ingrese el nuevo telefono del administrador: "; cin >> telefono;
                cout << "Ingrese el nuevo correo del administrador: "; cin >> correo;
                
                hashAdmins.modificarAdmin(cedulaAModificar, nombre, codCiudad, telefono, correo);
                break;
            }
            
            case 7:
            {
            	int codCiudadAModificar;
                string nombre;
                
                cout << "\nCiudades:" << endl;
                listaCiudades.Mostrar();
                
                cout << "Ingrese el codigo de la ciudad a modificar: "; cin >> codCiudadAModificar;
                cout << "Ingrese el nuevo nombre de la ciudad: "; cin.ignore(); getline(cin, nombre);
                
                listaCiudades.modificarCiudad(codCiudadAModificar, nombre);
                
                cout << "\nCiudades:" << endl;
                listaCiudades.Mostrar();
                break;
			}
            
            case 8:
				system("cls");
				cout << endl; break;
            
            default:
				system("cls");
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 8);
}

void menuListar(int opcion, ListaSimplePas& listaPasillos, ListaDobleProPasillos& listaProductos,
	ListaCircularDMarcasProductos& listaMarcasProductos, ListaDobleInventario& listaInventario,
	HashingClientes& hashClientes, HashingAdmins& hashAdmins, ListaCircularCiudades& listaCiudades)
{
	do
    {
        cout << "\n************LISTAR:************" << endl;
	    cout << "1. Pasillos" << endl;
	    cout << "2. Productos" << endl;
	    cout << "3. Marcas" << endl;
	    cout << "4. Inventario" << endl;
	    cout << "5. Clientes" << endl;
	    cout << "6. Administradores" << endl;
	    cout << "7. Ciudades" << endl;
	    cout << "8. Volver" << endl;
	    
	    cout << "\nIngrese la opcion deseada: ";
		cin >> opcion;

        switch (opcion)
        {
            case 1:
            	system("cls");
            	cout << "\nPasillos:" << endl;
                listaPasillos.Mostrar();
                break;

            case 2:
            	system("cls");
            	cout << "\nProductos:" << endl;
                listaProductos.Mostrar();
                break;

            case 3:
            	system("cls");
            	cout << "\nMarcas de Productos:" << endl;
                listaMarcasProductos.Mostrar();
                break;

            case 4:
            	system("cls");
            	cout << "\nInventario:" << endl;
                listaInventario.Mostrar();
                break;
            
            case 5:
            	system("cls");
            	cout << "\nClientes:" << endl;
                hashClientes.mostrarHash();
                break;
            
            case 6:
            	system("cls");
            	cout << "\nAdministradores:" << endl;
                hashAdmins.mostrarHash();
                break;
            
            case 7:
            	system("cls");
            	cout << "\nCiudades:" << endl;
                listaCiudades.Mostrar();
                break;
            
            case 8:
				system("cls");
				cout << endl; break;
            
            default:
				system("cls");
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 8);
}

void menuReportes(int opcion, ListaSimplePas& listaPasillos, ListaDobleProPasillos& listaProductos,
	ListaCircularDMarcasProductos& listaMarcasProductos, ListaDobleInventario& listaInventario,
	HashingClientes& hashClientes, HashingAdmins& hashAdmins, ListaCircularCiudades& listaCiudades)
{
	do
    {
        cout << "\n************REPORTES:************" << endl;
	    cout << "1. Pasillo" << endl;
	    cout << "2. Producto" << endl;
	    cout << "3. Marca" << endl;
	    cout << "4. Inventario" << endl;
	    cout << "5. Cliente" << endl;
	    cout << "6. Administrador" << endl;
	    cout << "7. Ciudad" << endl;
	    cout << "8. Volver" << endl;
	    
	    cout << "\nIngrese la opcion deseada: ";
		cin >> opcion;

        switch (opcion)
        {
            case 1: break;

            case 2: break;

            case 3: break;

            case 4: break;
            
            case 5: break;
            
            case 6: break;
            
            case 7: break;
            
            case 8:
				system("cls");
				cout << endl; break;
            
            default:
				system("cls");
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 8);
}



int main()
{
    ListaSimplePas listaPasillos;
    ListaDobleProPasillos listaProductos;
    ListaCircularDMarcasProductos listaMarcasProductos;
    ListaDobleInventario listaInventario;
    ListaCircularCiudades listaCiudades;

    crearListaPasillos(listaPasillos);
    crearListaProductos(listaProductos, listaPasillos);
    crearListaMarcasProductos(listaMarcasProductos, listaPasillos, listaProductos);
    crearListaInventario(listaInventario, listaPasillos, listaProductos, listaMarcasProductos);
    crearListaCiudades(listaCiudades);
    
    HashingClientes hashClientes(13);
    cargarClientesDesdeArchivo(hashClientes);
    HashingAdmins hashAdmins(13);
    cargarAdminsDesdeArchivo(hashAdmins);
    
    int cedula, opcion, opcion2;
    
    bool credencialesValidas = false;
	
	system("cls");
	cout << "\n************BIENVENID(@)S************" << endl;
	do
	{
		cout << "\nIngrese su numero de cedula para ingresar." << endl;
        cout << "Ingrese su cedula: "; cin >> cedula;
        
        // Valida credenciales de usuario en HashingAdmins
	    if (hashAdmins.loginAdmin(cedula))
	    {
	    	system("cls");
	    	cout << "\nBienvenid(@), administrador(@) "
				<< hashAdmins.buscarAdmin(cedula)->getNombre() << endl << endl;
	        do
			{
		        menuAdiministrador();
		        cout << "\nIngrese la opcion deseada: ";
		        cin >> opcion;
		
		        switch (opcion)
				{
					case 1: // Insertar
		        		system("cls");
		                menuInsertar(opcion2, listaPasillos, listaProductos,
							listaMarcasProductos, listaInventario, hashClientes,
							hashAdmins, listaCiudades);
		                break;
		
		            case 2: // Eliminar
		            	system("cls");
		                menuEliminar(opcion2, listaPasillos, listaProductos,
							listaMarcasProductos, listaInventario, hashClientes,
							hashAdmins, listaCiudades);
		                break;
		
		            case 3: // Buscar
		            	system("cls");
		                menuBuscar(opcion2, listaPasillos, listaProductos,
							listaMarcasProductos, listaInventario, hashClientes,
							hashAdmins, listaCiudades);
		            	break;
		
		            case 4: // Modificar
		            	system("cls");
		                menuModificar(opcion2, listaPasillos, listaProductos,
							listaMarcasProductos, listaInventario, hashClientes,
							hashAdmins, listaCiudades);
		            	break;
		
		            case 5: // Listar
		            	system("cls");
		                menuListar(opcion2, listaPasillos, listaProductos,
							listaMarcasProductos, listaInventario, hashClientes,
							hashAdmins, listaCiudades);
		            	break;
		
		            case 6: // Reportes
		            	system("cls");
		                menuReportes(opcion2, listaPasillos, listaProductos,
							listaMarcasProductos, listaInventario, hashClientes,
							hashAdmins, listaCiudades);
		            	break;
		
		            case 7: // Salir
		                cout << "Saliendo del programa..." << endl; break;
		
		            default:
		            	system("cls");
						cout << "Ingrese una opcion valida.\n" << endl;
				}
		    } while (opcion != 7);
		    
		    credencialesValidas = true;
		}
		else if (hashClientes.loginCliente(cedula))
		{
			system("cls");
			cout << "\nBienvenid(@) estimad(@) cliente, "
				<< hashClientes.buscarCliente(cedula)->getNombre() << endl << endl;
	        // Implementar acciones del menú para el Cliente
	        do
			{
		        menuCliente();
		        cout << "\nIngrese la opcion deseada: ";
		        cin >> opcion;
		
		        switch (opcion)
				{
					case 1: // Buscar
		        		// system("cls");
		                // menuBuscar(opcion2, listaPasillos, listaProductos, listaMarcas, listaInventario,
						// 	hashClientes, hashAdmins, listaCiudades);
		                break;
		
		            case 2: // Algunos reportes
		            	system("cls");
		                menuReportes(opcion2, listaPasillos, listaProductos, listaMarcasProductos, listaInventario,
							hashClientes, hashAdmins, listaCiudades);
		            	break;
		
		            case 3: // Salir
		                cout << "Saliendo del programa..." << endl; break;
		
		            default:
		            	system("cls");
						cout << "Ingrese una opcion valida.\n" << endl;
				}
		    } while (opcion != 3);
		    
		    credencialesValidas = true;
		}
		else
			cout << "\nNombre de usuario o cedula incorrectos. Intente nuevamente." << endl;
    } while (!credencialesValidas);

    return 0;
}

