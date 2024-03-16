// Estudiantes: Kevin Espinoza y José Carballo

#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class NodoPasillo
{
public:
    NodoPasillo(int _codPasillo, const string& _nombre)
    {
        codPasillo = _codPasillo;
        nombre = _nombre;
        siguiente = NULL;
    }

    NodoPasillo(int _codPasillo, const string& _nombre, NodoPasillo* _siguiente)
    {
        codPasillo = _codPasillo;
        nombre = _nombre;
        siguiente = _siguiente;
    }

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

    void InsertarInicio(int codPasillo, const string& nombre);
    void InsertarFinal(int codPasillo, const string& nombre);
    void InsertarPos(int codPasillo, const string& nombre, int pos);
    bool ListaVacia() { return primero == NULL; }
    void BorrarInicio();
    void BorrarFinal();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();
    void insertarMenuPasillo(int codPasillo, const string& nombre);
    bool pasilloRepetido(int codPasillo) const;
    void eliminarPasillo(int codPasillo);

private:
    pnodoPasillo primero;
};

void ListaSimplePas::insertarMenuPasillo(int codPasillo, const string& nombre)
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
        // Si no existe, inserta al inicio
        InsertarInicio(codPasillo, nombre);
        cout << "Pasillo insertado exitosamente." << endl;
    }
    else
        cout << "El pasillo ya existe en la lista." << endl;
}

bool ListaSimplePas::pasilloRepetido(int codPasillo) const
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
        cout << "La lista de pasillos esta vacia." << endl;
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
            cout << "Pasillo eliminado exitosamente." << endl;
            return;
        }

        actual = actual->siguiente;
        pos++;
    } while (actual != primero);

    // No se encontró el codPasillo en la lista
    cout << "No se encontro el pasillo con el codigo dado." << endl;
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

void ListaSimplePas::InsertarInicio(int codPasillo, const string& nombre)
{
    if (ListaVacia())
        primero = new NodoPasillo(codPasillo, nombre);
    else
    {
        pnodoPasillo nuevo = new NodoPasillo(codPasillo, nombre, primero);
        primero = nuevo;
    }
}

void ListaSimplePas::InsertarFinal(int codPasillo, const string& nombre)
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

void ListaSimplePas::InsertarPos(int codPasillo, const string& nombre, int pos)
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
        cout << "No hay elementos en la lista." << endl;
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
        cout << "No hay elementos en la lista." << endl;
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
        cout << aux->codPasillo << " - " << aux->nombre << " -> ";
        aux = aux->siguiente;
    }

    cout << endl;
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
    NodoProPasillo(int _codPasillo, int _codProducto, const string& _nombre)
    {
        codPasillo = _codPasillo;
        codProducto = _codProducto;
        nombre = _nombre;
        siguiente = NULL;
        anterior = NULL;
    }
    
    NodoProPasillo(int _codPasillo, int _codProducto, const string& _nombre, NodoProPasillo* _siguiente)
    {
        codPasillo = _codPasillo;
        codProducto = _codProducto;
        nombre = _nombre;
        siguiente = _siguiente;
        anterior = NULL;
    }

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

    void InsertarInicio(int codPasillo, int codProducto, const string& nombre);
    void InsertarFinal(int codPasillo, int codProducto, const string& nombre);
    void InsertarPos(int codPasillo, int codProducto, const string& nombre, int pos);
    bool ListaVacia() { return primero == NULL; }
    void BorrarInicio();
    void BorrarFinal();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();
    void insertarMenuProPasillo(int codPasillo, int codProducto, const string& nombre, ListaSimplePas& listaSimplePasillo);
    bool productoRepetido(int codProducto) const;
    void eliminarProducto(int codProducto);

private:
    pnodoProPasillo primero;
};

void ListaDobleProPasillos::insertarMenuProPasillo(int codPasillo, int codProducto, const string& nombre, ListaSimplePas &listaSimplePasillos)
{
    // Verifica si el pasillo existe en la lista simple
    if (listaSimplePasillos.pasilloRepetido(codPasillo))
    {
        if (!productoRepetido(codProducto))
        {
            // Inserta al inicio después de las validaciones
            InsertarInicio(codPasillo, codProducto, nombre);
            cout << "Producto insertado exitosamente." << endl;
        }
        else
            cout << "El codigo de producto ya existe en la lista." << endl;
    }
    else
        cout << "El pasillo no existe en la lista simple." << endl;
}

bool ListaDobleProPasillos::productoRepetido(int codProducto) const
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

void ListaDobleProPasillos::eliminarProducto(int codProducto)
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
            // Eliminar todas las marcas de ese producto
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

void ListaDobleProPasillos::InsertarInicio(int codPasillo, int codProducto, const string& nombre)
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

void ListaDobleProPasillos::InsertarFinal(int codPasillo, int codProducto, const string& nombre)
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

void ListaDobleProPasillos::InsertarPos(int codPasillo, int codProducto, const string& nombre, int pos)
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

void ListaDobleProPasillos::Mostrar()
{
    pnodoProPasillo aux;
    aux = primero;

    while (aux)
    {
        cout << aux->codPasillo << " - " << aux->codProducto << " - " << aux->nombre << " -> ";
        aux = aux->siguiente;
    }

    cout << endl;
}



class NodoMarcaProducto
{
public:
    NodoMarcaProducto(int _codPasillo, int _codProducto, int _codMarca, const string& _nombre, int _cantidadGondola, int _precio)
    {
        codPasillo = _codPasillo;
        codProducto = _codProducto;
        codMarca = _codMarca;
        nombre = _nombre;
        cantidadGondola = _cantidadGondola;
        precio = _precio;
        siguiente = NULL;
        anterior = NULL;
    }

private:
    int codPasillo;
    int codProducto;
    int codMarca;
    string nombre;
    int cantidadGondola;
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

    void InsertarInicio(int codPasillo, int codProducto, int codMarca, const string& nombre, int cantidadGondola, int precio);
    void InsertarFinal(int codPasillo, int codProducto, int codMarca, const string& nombre, int cantidadGondola, int precio);
    void InsertarPos(int codPasillo, int codProducto, int codMarca, const string& nombre, int cantidadGondola, int precio, int pos);
    bool ListaVacia() const { return primero == NULL; }
    void BorrarInicio();
    void BorrarFinal();
    void BorrarPosicion(int pos);
    void Mostrar() const;
    int largoLista() const;
    bool marcaRepetida(int codMarca) const;
    void insertarMarcaMenu(int codPasillo, int codProducto, int codMarca, const string& nombre, int cantidadGondola, int precio, ListaSimplePas&ListaPasillo, ListaDobleProPasillos&ProductosPas);
    void eliminarMarcas();

private:
    pnodoMarcaProducto primero;
};

bool ListaCircularDMarcasProductos::marcaRepetida(int codMarca) const
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

void ListaCircularDMarcasProductos::insertarMarcaMenu(int codPasillo, int codProducto, int codMarca, const string& nombre, int cantidadGondola, int precio, ListaSimplePas& ListaPasillo, ListaDobleProPasillos& ProductosPas)
{
    // Valida si el pasillo existe en la lista simple de pasillos
    if (!ListaPasillo.pasilloRepetido(codPasillo))
    {
        cout << "El pasillo no existe en la lista simple de pasillos." << endl;
        return;
    }
    cout << "El pasillo existe en la lista simple de pasillos." << endl;
    // Valida si el producto existe en la lista doble de productos
    if (!ProductosPas.productoRepetido(codProducto))
    {
        cout << "El producto no existe en la lista doble de productos." << endl;
        return;
    }
    cout << "El producto existe en la lista doble de productos." << endl;
    // Valida si el codMarca está repetido en la lista circular doble de marcas
    if (marcaRepetida(codMarca))
    {
        cout << "El codigo de marca ya existe en la lista circular doble de marcas." << endl;
        return;
    }
    cout << "El codigo de marca no existe en la lista circular doble de marcas." << endl;
    // Inserta en la lista circular doble de marcas después de las validaciones
    InsertarInicio(codPasillo, codProducto, codMarca, nombre, cantidadGondola, precio);
    cout << "Marca insertada en el menu de marcas exitosamente." << endl;
}

void ListaCircularDMarcasProductos::eliminarMarcas()
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

void ListaCircularDMarcasProductos::InsertarInicio(int codPasillo, int codProducto, int codMarca, const string& nombre, int cantidadGondola, int precio)
{
    pnodoMarcaProducto nuevo = new NodoMarcaProducto(codPasillo, codProducto, codMarca, nombre, cantidadGondola, precio);

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

void ListaCircularDMarcasProductos::InsertarFinal(int codPasillo, int codProducto, int codMarca, const string& nombre, int cantidadGondola, int precio)
{
    pnodoMarcaProducto nuevo = new NodoMarcaProducto(codPasillo, codProducto, codMarca, nombre, cantidadGondola, precio);

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

void ListaCircularDMarcasProductos::InsertarPos(int codPasillo, int codProducto, int codMarca, const string& nombre, int cantidadGondola, int precio, int pos)
{
    if (ListaVacia() || pos <= 1)
        InsertarInicio(codPasillo, codProducto, codMarca, nombre, cantidadGondola, precio);
    else
    {
        pnodoMarcaProducto aux = primero;
        int i = 2;

        while ((i != pos) && (aux->siguiente != primero))
        {
            i++;
            aux = aux->siguiente;
        }

        pnodoMarcaProducto nuevo = new NodoMarcaProducto(codPasillo, codProducto, codMarca, nombre, cantidadGondola, precio);
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

void ListaCircularDMarcasProductos::Mostrar() const
{
    if (ListaVacia())
        cout << "La lista esta vacia." << endl;
    else
    {
        pnodoMarcaProducto aux = primero;

        do
        {
            cout << "CodPasillo: " << aux->codPasillo << " - "
                << "CodProducto: " << aux->codProducto << " - "
                << "CodMarca: " << aux->codMarca << " - "
                << "Nombre: " << aux->nombre << " - "
                << "CantidadGondola: " << aux->cantidadGondola << " - "
                << "Precio: " << aux->precio << endl;

            aux = aux->siguiente;
        } while (aux != primero);
    }
}

int ListaCircularDMarcasProductos::largoLista() const
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
    NodoInventario(int _codPasillo, int _codProducto, int _codMarca, int _codInventario, const string& _nombre, int _cantidadStock, bool _codigoCanasta)
        : codPasillo(_codPasillo), codProducto(_codProducto), codMarca(_codMarca), codInventario(_codInventario),
        nombre(_nombre), cantidadStock(_cantidadStock), codigoCanasta(_codigoCanasta), siguiente(NULL), anterior(NULL) {}

private:
    int codPasillo;
    int codProducto;
    int codMarca;
    int codInventario;
    string nombre;
    int cantidadStock;
    bool codigoCanasta;
    NodoInventario* siguiente;
    NodoInventario* anterior;

    friend class ListaDobleInventario;
};

typedef NodoInventario* pnodoInventario;


class ListaDobleInventario
{
public:
    ListaDobleInventario() : primero(NULL) {}
    ~ListaDobleInventario();

    void InsertarInicio(int codPasillo, int codProducto, int codMarca, int codInventario, const string& nombre, int cantidadStock, bool codigoCanasta);
    void InsertarFinal(int codPasillo, int codProducto, int codMarca, int codInventario, const string& nombre, int cantidadStock, bool codigoCanasta);
    void InsertarPos(int codPasillo, int codProducto, int codMarca, int codInventario, const string& nombre, int cantidadStock, bool codigoCanasta, int pos);
    bool ListaVacia() const { return primero == NULL; }
    void BorrarInicio();
    void BorrarFinal();
    void BorrarPosicion(int pos);
    void Mostrar() const;
    int largoLista() const;
    void insertarInventario(int codPasillo, int codProducto, int codMarca, int codInventario, const string& nombre, int cantidadStock, bool codigoCanasta, ListaSimplePas& ListaPasillo, ListaDobleProPasillos& ProductosPas, ListaCircularDMarcasProductos&Marcas);
    bool listaInventarioRepetido(int codInventario) const;
    void eliminarInventario(int codInventario, ListaSimplePas& listaPasillo);

private:
    pnodoInventario primero;
};

void ListaDobleInventario::insertarInventario(int codPasillo, int codProducto, int codMarca, int codInventario, const string& nombre, int cantidadStock, bool codigoCanasta, ListaSimplePas& ListaPasillo, ListaDobleProPasillos& ProductosPas, ListaCircularDMarcasProductos& Marcas)
{
    // Valida si el codPasillo existe en la lista simple de pasillos
    if (ListaPasillo.pasilloRepetido(codPasillo) == false)
    {
        cout << "El pasillo no existe en la lista simple de pasillos." << endl;
        return;
    }

    // Valida si el codProducto existe en la lista doble de productos de pasillo
    if (ProductosPas.productoRepetido(codProducto) == false)
    {
        cout << "El producto no existe en la lista doble de productos." << endl;
        return;
    }

    // Valida si el codMarca existe en la lista circular de marcas de productos
    if (!Marcas.marcaRepetida(codMarca))
    {
        cout << "El codigo de marca no existe en la lista circular de marcas de productos." << endl;
        return;
    }

    // Valida si el codInventario no está repetido en la lista doble de inventario
    if (listaInventarioRepetido(codInventario)) {
        cout << "El codigo de inventario ya existe en la lista doble de inventario." << endl;
        return;
    }

    // Inserta en la lista doble de inventario después de las validaciones
    InsertarInicio(codPasillo, codProducto, codMarca, codInventario, nombre, cantidadStock, codigoCanasta);
    cout << "Producto insertado en el inventario exitosamente." << endl;
}

bool ListaDobleInventario::listaInventarioRepetido(int codInventario) const
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

void ListaDobleInventario::eliminarInventario(int codInventario, ListaSimplePas& listaPasillo)
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
            if (listaPasillo.pasilloRepetido(codPasillo))
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

void ListaDobleInventario::InsertarInicio(int codPasillo, int codProducto, int codMarca, int codInventario, const string& nombre, int cantidadStock, bool codigoCanasta)
{
    if (ListaVacia())
    {
        primero = new NodoInventario(codPasillo, codProducto, codMarca, codInventario, nombre, cantidadStock, codigoCanasta);
        primero->anterior = NULL;
    }
    else
    {
        pnodoInventario nuevo = new NodoInventario(codPasillo, codProducto, codMarca, codInventario, nombre, cantidadStock, codigoCanasta);
        nuevo->siguiente = primero;
        primero->anterior = nuevo;
        primero = nuevo;
    }
}

void ListaDobleInventario::InsertarFinal(int codPasillo, int codProducto, int codMarca, int codInventario, const string& nombre, int cantidadStock, bool codigoCanasta)
{
    if (ListaVacia())
    {
        primero = new NodoInventario(codPasillo, codProducto, codMarca, codInventario, nombre, cantidadStock, codigoCanasta);
        primero->anterior = NULL;
    }
    else
    {
        pnodoInventario aux = primero;

        while (aux->siguiente != NULL)
            aux = aux->siguiente;

        aux->siguiente = new NodoInventario(codPasillo, codProducto, codMarca, codInventario, nombre, cantidadStock, codigoCanasta);
        aux->siguiente->anterior = aux;
    }
}

void ListaDobleInventario::InsertarPos(int codPasillo, int codProducto, int codMarca, int codInventario, const string& nombre, int cantidadStock, bool codigoCanasta, int pos)
{
    if (ListaVacia())
    {
        primero = new NodoInventario(codPasillo, codProducto, codMarca, codInventario, nombre, cantidadStock, codigoCanasta);
        primero->anterior = NULL;
    }
    else
    {
        if (pos <= 1)
        {
            pnodoInventario nuevo = new NodoInventario(codPasillo, codProducto, codMarca, codInventario, nombre, cantidadStock, codigoCanasta);
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

            pnodoInventario nuevo = new NodoInventario(codPasillo, codProducto, codMarca, codInventario, nombre, cantidadStock, codigoCanasta);
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

void ListaDobleInventario::Mostrar() const
{
    pnodoInventario aux = primero;

    while (aux) {
        cout << "CodPasillo: " << aux->codPasillo << " - "
            << "CodProducto: " << aux->codProducto << " - "
            << "CodMarca: " << aux->codMarca << " - "
            << "CodInventario: " << aux->codInventario << " - "
            << "Nombre: " << aux->nombre << " - "
            << "CantidadStock: " << aux->cantidadStock << " - "
            << "CodigoCanasta: " << aux->codigoCanasta << " -> ";
        aux = aux->siguiente;
    }

    cout << endl;
}

int ListaDobleInventario::largoLista() const
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



// Clase para almacenar la información de los clientes y administradores
class NodoPersona
{
public:
    int cedula;
    string nombre;
    int codCiudad;
    string telefono;
    string correo;
    NodoPersona* siguiente;

    NodoPersona(int _cedula, string _nombre, int _codCiudad, string _telefono, string _correo)
        : cedula(_cedula), nombre(_nombre), codCiudad(_codCiudad), telefono(_telefono), correo(_correo), siguiente(NULL) {}
    
    NodoPersona(int _cedula, string _nombre, int _codCiudad, string _telefono, string _correo, NodoPersona* _siguiente)
        : cedula(_cedula), nombre(_nombre), codCiudad(_codCiudad), telefono(_telefono), correo(_correo), siguiente(_siguiente) {}
};

typedef NodoPersona* pnodoPersona;


class ListaSimplePersona
{
public:
    ListaSimplePersona() { primero = NULL; } // Constructor
    ~ListaSimplePersona();                   // Destructor

    void InsertarInicio(int cedula, string nombre, int codCiudad, string telefono, string correo);
    void InsertarFinal(int cedula, string nombre, int codCiudad, string telefono, string correo);
    void InsertarPos(int cedula, string nombre, int codCiudad, string telefono, string correo, int pos);
    bool ListaVacia() { return primero == NULL; }
    void BorrarInicio();
    void BorrarFinal();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();

private:
    pnodoPersona primero;
};

ListaSimplePersona::~ListaSimplePersona()
{
    pnodoPersona aux;

    while (primero)
    {
        aux = primero;
        primero = primero->siguiente;

        delete aux;
    }

    primero = NULL;
}

void ListaSimplePersona::InsertarInicio(int cedula, string nombre, int codCiudad, string telefono, string correo)
{
    if (ListaVacia())
        primero = new NodoPersona(cedula, nombre, codCiudad, telefono, correo);
    else
        primero = new NodoPersona(cedula, nombre, codCiudad, telefono, correo, primero);
}

void ListaSimplePersona::InsertarFinal(int cedula, string nombre, int codCiudad, string telefono, string correo)
{
    if (ListaVacia())
        primero = new NodoPersona(cedula, nombre, codCiudad, telefono, correo);
    else
    {
        pnodoPersona aux = primero;

        while (aux->siguiente != NULL)
            aux = aux->siguiente;

        aux->siguiente = new NodoPersona(cedula, nombre, codCiudad, telefono, correo);
    }
}

void ListaSimplePersona::InsertarPos(int cedula, string nombre, int codCiudad, string telefono, string correo, int pos)
{
    if (ListaVacia())
        primero = new NodoPersona(cedula, nombre, codCiudad, telefono, correo);
    else
    {
        if (pos <= 1)
            InsertarInicio(cedula, nombre, codCiudad, telefono, correo);
        else
        {
            pnodoPersona aux = primero;

            int i = 2;
            while ((i != pos) && (aux->siguiente != NULL))
            {
                i++;
                aux = aux->siguiente;
            }

            pnodoPersona nuevo = new NodoPersona(cedula, nombre, codCiudad, telefono, correo);
            nuevo->siguiente = aux->siguiente;
            aux->siguiente = nuevo;
        }
    }
}

void ListaSimplePersona::BorrarInicio()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista." << endl;
    else
    {
        if (primero->siguiente == NULL)
        {
            pnodoPersona temp = primero;
            primero = NULL;

            delete temp;
        }
        else
        {
            pnodoPersona aux = primero;
            primero = primero->siguiente;

            delete aux;
        }
    }
}

void ListaSimplePersona::BorrarFinal()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista." << endl;
    else
    {
        if (primero->siguiente == NULL)
        {
            pnodoPersona temp = primero;
            primero = NULL;

            delete temp;
        }
        else
        {
            pnodoPersona aux = primero;
            while (aux->siguiente->siguiente != NULL)
                aux = aux->siguiente;

            pnodoPersona temp = aux->siguiente;
            aux->siguiente = NULL;

            delete temp;
        }
    }
}

void ListaSimplePersona::BorrarPosicion(int pos)
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
            {
                pnodoPersona temp = primero;
                primero = primero->siguiente;

                delete temp; // BorrarInicio();
            }
            else
            {
                pnodoPersona aux = primero;

                int cont = 2;
                while (cont < pos)
                {
                    aux = aux->siguiente;
                    cont++;
                }

                pnodoPersona temp = aux->siguiente;
                aux->siguiente = aux->siguiente->siguiente;

                delete temp;
            }
        }
    }
}

void ListaSimplePersona::Mostrar()
{
    pnodoPersona aux;

    if (primero == NULL)
        cout << "No hay elementos.";
    else
    {
        aux = primero;
        while (aux)
        {
            cout << aux->cedula << ", " <<
                aux->nombre << ", " <<
                aux->codCiudad << ", " <<
                aux->telefono << ", " <<
                aux->correo << " -> " << endl;

            aux = aux->siguiente;
        }

        cout << endl;
    }
}

int ListaSimplePersona::largoLista()
{
    int cont = 0;

    pnodoPersona aux = primero;

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
        cout << endl;
    }
}



// Hashing abierto para clientes
class HashingClientes
{
private:
    int tamTabla;
    pnodoPersona* tablaHash;

    int encontrarPrimoInferior(int N);
    bool ciudadExiste(int codCiudad);

public:
    HashingClientes(int N);
    ~HashingClientes();

    void insertarCliente(int cedula, string nombre, int codCiudad, string telefono, string correo);
    void mostrarHash();
};

HashingClientes::HashingClientes(int N)
{
    tamTabla = encontrarPrimoInferior(N);
    tablaHash = new pnodoPersona[tamTabla]();

    // Inicializa la tabla hash con NULL
    for (int i = 0; i < tamTabla; i++)
        tablaHash[i] = NULL;
}

HashingClientes::~HashingClientes()
{
    for (int i = 0; i < tamTabla; i++)
    {
        pnodoPersona actual = tablaHash[i];

        while (actual != NULL)
        {
            pnodoPersona siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }

    delete[] tablaHash;
}

int HashingClientes::encontrarPrimoInferior(int N)
{
    for (int primo = N - 1; primo > 1; --primo)
    {
        bool esPrimo = true;

        for (int i = 2; i <= primo / 2; ++i)
        {
            if (primo % i == 0)
            {
                esPrimo = false;
                break;
            }
        }

        if (esPrimo)
            return primo;
    }

    return 2;
}

bool HashingClientes::ciudadExiste(int codCiudad)
{
    return true;
}

void HashingClientes::insertarCliente(int cedula, string nombre, int codCiudad, string telefono, string correo)
{
    // Valida que la ciudad exista
    if (!ciudadExiste(codCiudad))
    {
        cout << "Ciudad no valida." << endl;
        return;
    }

    // Aplica la función de hashing
    int indice = (cedula % tamTabla) + 1;

    pnodoPersona nuevoCliente = new NodoPersona(cedula, nombre, codCiudad, telefono, correo);

    // Verifica si ya hay un nodo en esa posición
    if (tablaHash[indice - 1] == NULL)
        tablaHash[indice - 1] = nuevoCliente;
    else
    {
        // Si ya hay un nodo, lo coloca al final de la lista
        pnodoPersona actual = tablaHash[indice - 1];

        while (actual->siguiente != NULL)
            actual = actual->siguiente;

        actual->siguiente = nuevoCliente;
    }
}

void HashingClientes::mostrarHash()
{
    for (int i = 0; i < tamTabla; ++i)
    {
        cout << i;
        pnodoPersona actual = tablaHash[i];

        while (actual != NULL)
        {
            cout << " --> Cedula: " << actual->cedula << ", Nombre: " << actual->nombre;
            actual = actual->siguiente;
        }

        cout << endl;
    }
}


// Hashing abierto para administradores
class HashingAdmins
{
private:
    int tamTabla;
    pnodoPersona* tablaHash;

    int encontrarPrimoInferior(int N);
    bool ciudadExiste(int codCiudad);

public:
    HashingAdmins(int N);
    ~HashingAdmins();

    void insertarAdministrador(int cedula, string nombre, int codCiudad, string telefono, string correo);
    void mostrarHash();
};

HashingAdmins::HashingAdmins(int N)
{
    tamTabla = encontrarPrimoInferior(N);
    tablaHash = new pnodoPersona[tamTabla]();

    // Inicializa la tabla hash con NULL
    for (int i = 0; i < tamTabla; i++)
        tablaHash[i] = NULL;
}

HashingAdmins::~HashingAdmins()
{
    for (int i = 0; i < tamTabla; i++)
    {
        pnodoPersona actual = tablaHash[i];

        while (actual != NULL)
        {
            pnodoPersona siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }

    delete[] tablaHash;
}

int HashingAdmins::encontrarPrimoInferior(int N)
{
    for (int primo = N - 1; primo > 1; --primo)
    {
        bool esPrimo = true;
        
        for (int i = 2; i <= primo / 2; ++i)
        {
            if (primo % i == 0)
            {
                esPrimo = false;
                break;
            }
        }

        if (esPrimo)
            return primo;
    }

    return 2;
}

bool HashingAdmins::ciudadExiste(int codCiudad)
{
    return true;
}

void HashingAdmins::insertarAdministrador(int cedula, string nombre, int codCiudad, string telefono, string correo)
{
    // Valida que la ciudad exista
    if (!ciudadExiste(codCiudad))
    {
        cout << "Ciudad no valida." << endl;
        return;
    }

    // Aplica la función de hashing
    int indice = (cedula % tamTabla) + 1;

    pnodoPersona nuevoAdministrador = new NodoPersona(cedula, nombre, codCiudad, telefono, correo);

    // Verifica si ya hay un nodo en esa posición
    if (tablaHash[indice - 1] == NULL)
        tablaHash[indice - 1] = nuevoAdministrador;
    else
    {
        // Si ya hay un nodo, lo coloca al final de la lista
        pnodoPersona actual = tablaHash[indice - 1];

        while (actual->siguiente != NULL)
            actual = actual->siguiente;
        
        actual->siguiente = nuevoAdministrador;
    }
}

void HashingAdmins::mostrarHash()
{
    for (int i = 0; i < tamTabla; ++i)
    {
        cout << i;
        pnodoPersona actual = tablaHash[i];

        while (actual != NULL)
        {
            cout << " --> Cedula: " << actual->cedula << ", Nombre: " << actual->nombre;
            actual = actual->siguiente;
        }

        cout << endl;
    }
}



class NodoCiudad
{
public:
    NodoCiudad(int _codCiudad, const string& _nombre)
    {
        codCiudad = _codCiudad;
        nombre = _nombre;
        siguiente = NULL;
    }

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

    void InsertarInicio(int codCiudad, const string& nombre);
    void InsertarFinal(int codCiudad, const string& nombre);
    void InsertarPos(int codCiudad, const string& nombre, int pos);
    bool ListaVacia() const { return primero == NULL; }
    void BorrarInicio();
    void BorrarFinal();
    void BorrarPosicion(int pos);
    void Mostrar() const;
    int largoLista() const;
    bool ciudadRepetida(int codCiudad) const;
    void insertarCiudadMenu(int codCiudad, const string& nombre);
    void eliminarCiudad(int codCiudad);

private:
    pnodoCiudad primero;
};

bool ListaCircularCiudades::ciudadRepetida(int codCiudad) const
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

void ListaCircularCiudades::insertarCiudadMenu(int codCiudad, const string& nombre)
{
    // Valida si el codCiudad no está repetido
    if (ciudadRepetida(codCiudad) == false)
        InsertarInicio(codCiudad, nombre);
    else
        cout << "El codigo de ciudad ya existe en la lista." << endl;
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

void ListaCircularCiudades::InsertarInicio(int codCiudad, const string& nombre)
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

void ListaCircularCiudades::InsertarFinal(int codCiudad, const string& nombre)
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

void ListaCircularCiudades::InsertarPos(int codCiudad, const string& nombre, int pos)
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

void ListaCircularCiudades::Mostrar() const
{
    if (ListaVacia())
        cout << "La lista esta vacia." << endl;
    else
    {
        pnodoCiudad aux = primero;

        do
        {
            cout << "CodCiudad: " << aux->codCiudad << " - " << "Nombre: " << aux->nombre << " -> ";
            aux = aux->siguiente;
        } while (aux != primero);

        cout << endl;
    }
}

int ListaCircularCiudades::largoLista() const
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


// Función para convertir cadena a entero
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

bool stringABool(string str)
{
    istringstream iss(str);
    bool res;
    
    if (!(iss >> boolalpha >> res))
	{
        cout << "No se pudo convertir la cadena a bool." << endl;
        return false;
	}

    return res;
}

// Funciones para leer y procesar los archivos
void leerArchivo(string nombreArchivo, ListaSimplePas& listaPasillos)
{
    ifstream archivo(nombreArchivo.c_str());

    if (!archivo)
	{
        cout << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    string linea;
    int contador = 0;

    while (getline(archivo, linea))
	{
        if (linea == "")
            continue;

        contador++;

        if (contador > 1)
		{
            stringstream ss(linea);
            int codPasillo;
            string nombre;

            if (ss >> codPasillo >> nombre) {
                // Verifica si el pasillo ya existe antes de insertarlo
                if (!listaPasillos.pasilloRepetido(codPasillo))
                    listaPasillos.InsertarFinal(codPasillo, nombre);
                else
                    cout << "El pasillo con codigo " << codPasillo << " ya existe." << endl;
            }
			else
                cout << "Error al parsear la linea: " << linea << endl;
        }
    }

    archivo.close();
}



class ManejadorEstructuras
{
public:
	void crearListaPasillos(ListaSimplePas& listaPasillos);
	void crearListaProductos(ListaDobleProPasillos& listaProductos, ListaSimplePas& listaPasillos);
	void crearListaMarcas(ListaCircularDMarcasProductos& listaMarcas, ListaSimplePas& listaPasillos, ListaDobleProPasillos& listaProductos);
	void crearListaInventario(ListaDobleInventario& listaInventario, ListaSimplePas& listaPasillos, ListaDobleProPasillos& listaProductos, ListaCircularDMarcasProductos& listaMarcas);
	void crearListaCiudades(ListaCircularCiudades& listaCiudades);
};

void ManejadorEstructuras::crearListaPasillos(ListaSimplePas& listaPasillos)
{
	ifstream archivo("Pasillos.txt");

    if (!archivo)
	{
        cout << "No se pudo abrir el archivo Pasillos.txt" << endl;
        return;
    }

    cout << "Contenido del archivo Pasillos.txt:" << endl;

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
            cout << "Insertando pasillo: " << codPasillo << ", " << nombre << endl;
            listaPasillos.insertarMenuPasillo(stringAInt(codPasillo), nombre);
        }
    }

    archivo.close();
}

void ManejadorEstructuras::crearListaProductos(ListaDobleProPasillos& listaProductos, ListaSimplePas& listaPasillos)
{
    ifstream archivo("ProductosPasillos.txt");

    if (!archivo)
    {
        cout << "No se pudo abrir el archivo ProductosPasillos.txt" << endl;
        return;
    }

    cout << "Contenido del archivo ProductosPasillos.txt:" << endl;

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
            cout << "Insertando producto: " << codPasillo << ", " << codProducto << ", " << nombre << endl;
            listaProductos.insertarMenuProPasillo(stringAInt(codPasillo), stringAInt(codProducto), nombre, listaPasillos);
        }
    }

    cout << "Lista de productos creada correctamente." << endl;
    archivo.close();
}

void ManejadorEstructuras::crearListaMarcas(ListaCircularDMarcasProductos& listaMarcas, ListaSimplePas& listaPasillos, ListaDobleProPasillos& listaProductos)
{
    ifstream archivo("MarcasProductos.txt");

    if (!archivo)
    {
        cout << "No se pudo abrir el archivo MarcasProductos.txt" << endl;
        return;
    }

    cout << "Contenido del archivo MarcasProductos.txt:" << endl;

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
            string codPasillo, codProducto, codMarca, nombre, cantidadGondola, precio;
            
            getline(ss, codPasillo, ';'); ss >> ws;
            getline(ss, codProducto, ';'); ss >> ws;
            getline(ss, codMarca, ';'); ss >> ws;
            getline(ss, nombre, ';'); ss >> ws;
            getline(ss, cantidadGondola, ';'); ss >> ws;
            getline(ss, precio, ';'); ss >> ws;

            // Inserta en la lista circular doble de marcas después de las validaciones
            cout << "Insertando marca: " << codPasillo << ", " << codProducto << ", " << codMarca << ", " << nombre << ", " << cantidadGondola << ", " << precio << endl;
            listaMarcas.insertarMarcaMenu(stringAInt(codPasillo), stringAInt(codProducto), stringAInt(codMarca), nombre, stringAInt(cantidadGondola), stringAInt(precio), listaPasillos, listaProductos);
        }
    }

    archivo.close();
}

void ManejadorEstructuras::crearListaInventario(ListaDobleInventario& listaInventario, ListaSimplePas& listaPasillos, ListaDobleProPasillos& listaProductos, ListaCircularDMarcasProductos& listaMarcas)
{
	ifstream archivo("Inventario.txt");

    if (!archivo)
    {
        cout << "No se pudo abrir el archivo Inventario.txt" << endl;
        return;
    }

    cout << "Contenido del archivo Inventario.txt:" << endl;

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
            cout << "Insertando inventario: " << codPasillo << ", " << codProducto << ", " << codMarca << ", " << codInventario << ", " << nombre << ", " << cantidadStock << ", " << codigoCanasta << endl;
            listaInventario.insertarInventario(stringAInt(codPasillo), stringAInt(codProducto), stringAInt(codMarca), stringAInt(codInventario), nombre, stringAInt(cantidadStock), stringABool(cantidadStock), listaPasillos, listaProductos, listaMarcas);
        }
    }

    archivo.close();
}

void ManejadorEstructuras::crearListaCiudades(ListaCircularCiudades& listaCiudades)
{
	ifstream archivo("Ciudades.txt");
	
	if (!archivo)
	{
	    cout << "No se pudo abrir el archivo Ciudades.txt" << endl;
	    return;
	}
	
	cout << "Contenido del archivo Ciudades.txt:" << endl;
	
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
            cout << "Insertando ciudad: " << codCiudad << ", " << nombre << endl;
	        listaCiudades.insertarCiudadMenu(stringAInt(codCiudad), nombre);
	    }
	}
}







int main()
{
    ManejadorEstructuras manejador;
    ListaSimplePas listaPasillos;
    ListaDobleProPasillos listaProductos;
    ListaCircularDMarcasProductos listaMarcas;
    ListaDobleInventario listaInventario;
    ListaCircularCiudades listaCiudades;
    
    manejador.crearListaPasillos(listaPasillos);
    listaPasillos.Mostrar();
    cout << endl;
    manejador.crearListaProductos(listaProductos, listaPasillos);
    listaProductos.Mostrar();
    cout << endl;
    manejador.crearListaMarcas(listaMarcas, listaPasillos, listaProductos);
    listaMarcas.Mostrar();
    cout << endl;
    manejador.crearListaInventario(listaInventario, listaPasillos, listaProductos, listaMarcas);
    listaInventario.Mostrar();
    cout << endl;
    manejador.crearListaCiudades(listaCiudades);
    listaCiudades.Mostrar();

    return 0;
}

