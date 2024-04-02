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
        contVisitas = 0;
        siguiente = NULL;
    }

    NodoPasillo(int _codPasillo, string _nombre, NodoPasillo* _siguiente)
    {
        codPasillo = _codPasillo;
        nombre = _nombre;
        contVisitas = 0;
        siguiente = _siguiente;
    }

	int getCodPasillo() { return codPasillo; }
	string getNombre() { return nombre; }

private:
    int codPasillo;
    string nombre;
    int contVisitas;
    NodoPasillo* siguiente;

    friend class ListaSimplePas;
};

typedef NodoPasillo* pnodoPasillo;


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
    
    NodoProPasillo(int _codPasillo, int _codProducto, string _nombre,
        NodoProPasillo* _siguiente)
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


class NodoMarcaProducto
{
public:
    NodoMarcaProducto(int _codPasillo, int _codProducto, int _codMarca, string _nombre,
        int _cantGondola, int _precio)
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


class NodoInventario
{
public:
    NodoInventario(int _codPasillo, int _codProducto, int _codMarca, int _codInventario,
        string _nombre, int _cantStock, bool _codCanasta)
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


class NodoCliente
{
public:
    NodoCliente(int _cedula, string _nombre, int _codCiudad, string _telefono,
		string _correo)
    {
        cedula = _cedula;
        nombre = _nombre;
        codCiudad = _codCiudad;
        telefono = _telefono;
        correo = _correo;
        siguiente = NULL;
    }

    NodoCliente(int _cedula, string _nombre, int _codCiudad, string _telefono,
		string _correo, NodoCliente* _siguiente)
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
    friend class ListaCircularCiudades;
};

typedef NodoCliente* pnodoCte;


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

    NodoAdmin(int _cedula, string _nombre, int _codCiudad, string _telefono, string _correo,
		NodoAdmin* _siguiente)
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
    friend class ListaCircularCiudades;
};

typedef NodoAdmin* pnodoAdmin;


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
    void reportePasillos();
    void reportePasilloMasVisitado();
    void reportePasilloMenosVisitado();

private:
    pnodoPasillo primero;
};

void ListaSimplePas::insertarPasillo(int codPasillo, string nombre)
{
    if (!pasilloRepetido(codPasillo))
    {
        // Si no existe, inserta al final
        InsertarFinal(codPasillo, nombre);
        cout << "\nPasillo insertado exitosamente." << endl;
        cout << "\nPasillo insertado:" << endl;
        cout << "--> CodPasillo: " << codPasillo << endl;
        cout << "    Nombre: " << nombre << endl << endl;
    }
    else
        cout << "\nEl pasillo ya existe en la lista.\n" << endl;
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
        cout << "\nLa lista de pasillos esta vacia.\n" << endl;
        return;
    }

    pnodoPasillo actual = primero;
    int pos = 1;

    do
    {
        if (actual->codPasillo == codPasillo)
        {
            BorrarPosicion(pos);
            cout << "\nPasillo eliminado exitosamente.\n" << endl;
            return;
        }

        actual = actual->siguiente;
        pos++;
    } while (actual != primero);
}

pnodoPasillo ListaSimplePas::buscarPasillo(int codPasillo)
{
    if (ListaVacia())
    {
        cout << "\nLa lista de pasillos esta vacia.\n" << endl;
        return NULL;
    }

    pnodoPasillo aux = primero;

    while (aux != NULL)
	{
		if (aux->codPasillo == codPasillo)
		{
			aux->contVisitas++; // Incrementa el contador de búsquedas
            return aux;
    	}

        aux = aux->siguiente;
    }

    return NULL;
}

void ListaSimplePas::modificarPasillo(int codPasillo, string nombre)
{
	pnodoPasillo pasillo = buscarPasillo(codPasillo);
	
	if (pasillo == NULL)
	{
		cout << "\nPasillo no encontrado.\n";
		return;
	}
	
    pasillo->codPasillo = codPasillo;
    pasillo->nombre = nombre;

    cout << "\nPasillo modificado exitosamente." << endl;
    cout << "\nPasillo modificado:" << endl;
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
        cout << "\nNo hay elementos en la lista.\n" << endl;
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
        cout << "\nNo hay elementos en la lista.\n" << endl;
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
        cout << "\nLa lista esta vacia.\n" << endl;
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
    void insertarProPasillo(int codPasillo, int codProducto, string nombre,
        ListaSimplePas& listaPasillos);
    bool productoRepetido(int codProducto);
    void eliminarProPasillo(int codProducto);
    int obtenerPosicion(pnodoProPasillo producto);
    pnodoProPasillo buscarProPasillo(int codProducto);
    void modificarProPasillo(int codProducto, string nombre);
    void reporteProPasillos();

private:
    pnodoProPasillo primero;
};

void ListaDobleProPasillos::insertarProPasillo(int codPasillo, int codProducto,
    string nombre, ListaSimplePas& listaPasillos)
{
    // Verifica si el producto ya está repetido
    if (!productoRepetido(codProducto))
    {
        if (listaPasillos.pasilloRepetido(codPasillo))
            // Inserta al inicio después de las validaciones
            InsertarFinal(codPasillo, codProducto, nombre);
            
            cout << "\nProducto insertado exitosamente." << endl;
	        cout << "\nProducto insertado:" << endl;
	        cout << "--> CodPasillo: " << codPasillo << endl;
	        cout << "    CodProducto: " << codProducto << endl;
	        cout << "    Nombre: " << nombre << endl << endl;
    }
    else
    	cout << "\nEl producto ya existe en el pasillo.\n" << endl;
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
        cout << "\nLa lista de productos esta vacia.\n" << endl;
        return;
    }

    pnodoProPasillo actual = primero;

    do
    {
        if (actual->codProducto == codProducto)
        {
            pnodoProPasillo siguienteNodo;
            // Elimina todas las marcas de ese producto
            while (actual != NULL && actual->codProducto == codProducto)
            {
                pnodoProPasillo siguienteNodo = actual->siguiente;
                BorrarPosicion(obtenerPosicion(actual));
                actual = siguienteNodo;
            }

            cout << "\nProducto y sus marcas eliminados exitosamente.\n" << endl;
            return;
        }

        actual = actual->siguiente;
    } while (actual != NULL);

    cout << "\nEl producto no se encuentra en la lista.\n" << endl;
}

int ListaDobleProPasillos::obtenerPosicion(pnodoProPasillo producto)
{
    int pos = 1;
    pnodoProPasillo actual = primero;

    while (actual != NULL)
    {
        if (actual == producto)
            return pos;

        actual = actual->siguiente;
        pos++;
    }

    return -1; // -1 si el producto no se encuentra en la lista
}

pnodoProPasillo ListaDobleProPasillos::buscarProPasillo(int codProducto)
{
    if (ListaVacia())
	{
        cout << "\nLa lista de pasillos esta vacia.\n" << endl;
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
        cout << "\nProducto no encontrado.\n" << endl;
        return;
    }

    proPasillo->codProducto = codProducto;
    proPasillo->nombre = nombre;

    cout << "\nProducto modificado exitosamente." << endl;
    cout << "\nProducto modificado:" << endl;
	cout << "--> CodProducto: " << codProducto << endl;
	cout << "    Nombre: " << nombre << endl << endl;
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
        cout << "\nNo hay elementos en la lista.\n" << endl;
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
        cout << "\nNo hay elementos en la lista.\n" << endl;
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
        cout << "\nLa lista esta vacia.\n" << endl;
    else
    {
        if ((pos > largoLista()) || (pos < 0))
            cout << "\nError en posicion.\n" << endl;
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


class ListaCircularDMarcasProductos
{
public:
    ListaCircularDMarcasProductos() { primero = NULL; }
    ~ListaCircularDMarcasProductos();

    void InsertarInicio(int codPasillo, int codProducto, int codMarca, string nombre,
        int cantGondola, int precio);
    void InsertarFinal(int codPasillo, int codProducto, int codMarca, string nombre,
        int cantGondola, int precio);
    void InsertarPos(int codPasillo, int codProducto, int codMarca, string nombre,
        int cantGondola, int precio, int pos);
    bool ListaVacia() { return primero == NULL; }
    void BorrarInicio();
    void BorrarFinal();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();
    void insertarMarcaProducto(int codPasillo, int codProducto, int codMarca,
        string nombre, int cantGondola, int precio, ListaSimplePas& listaPasillos,
        ListaDobleProPasillos& listaProductos);
    bool marcaProductoRepetida(int codMarca);
    void eliminarMarcasProductos();
    pnodoMarcaProducto buscarMarcaProducto(int codMarca);
    void modificarMarcaProducto(int codMarca, string nombre, int cantGondola, int precio);
    void reporteMarcasProductos();

private:
    pnodoMarcaProducto primero;
};

void ListaCircularDMarcasProductos::insertarMarcaProducto(int codPasillo, int codProducto,
    int codMarca, string nombre, int cantGondola, int precio, ListaSimplePas& listaPasillos,
    ListaDobleProPasillos& listaProductos)
{
    // Valida si el pasillo existe en la lista simple de pasillos
    if (!listaPasillos.pasilloRepetido(codPasillo))
    {
    	cout << "\nEl pasillo no existe.\n" << endl;
    	return;
	}

    // Valida si el producto existe en la lista doble de productos
    if (!listaProductos.productoRepetido(codProducto))
    {
    	cout << "\nEl producto no existe.\n" << endl;
    	return;
	}

    // Valida si el codMarca está repetido en la lista circular doble de marcas
    if (!marcaProductoRepetida(codMarca))
	{
    	// Inserta en la lista circular doble de marcas después de las validaciones
	    InsertarFinal(codPasillo, codProducto, codMarca, nombre, cantGondola, precio);
	
	    cout << "\nMarca insertada exitosamente." << endl;
	    cout << "\nMarca insertada:" << endl;
	    cout << "--> CodPasillo: " << codPasillo << endl;
	    cout << "    CodProducto: " << codProducto << endl;
	    cout << "    CodMarca: " << codMarca << endl;
	    cout << "    Nombre: " << nombre << endl;
	    cout << "    CantGondola: " << cantGondola << endl;
	    cout << "    Precio: " << precio << endl << endl;
	}
	else
	{
		cout << "\nLa marca de producto ya existe.\n" << endl;
    	return;
	}
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
        cout << "\nLa lista esta vacia.\n" << endl;
        return;
    }

    pnodoMarcaProducto actual = primero;
    pnodoMarcaProducto siguiente;

    do
    {
        siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    } while (actual->siguiente != NULL);

    primero = NULL; // Establece primero como NULL después de eliminar todos los nodos
    cout << "\nTodas las marcas han sido eliminadas.\n" << endl;
}

pnodoMarcaProducto ListaCircularDMarcasProductos::buscarMarcaProducto(int codMarca)
{
	if (ListaVacia())
	{
        cout << "\nLa lista de marcas esta vacia.\n" << endl;
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

void ListaCircularDMarcasProductos::modificarMarcaProducto(int codMarca, string nombre,
	int cantGondola, int precio)
{
	pnodoMarcaProducto marcaProducto = buscarMarcaProducto(codMarca);

    if (marcaProducto == NULL)
    {
        cout << "\nMarca de producto no encontrada.\n" << endl;
        return;
    }

    marcaProducto->codMarca = codMarca;
    marcaProducto->nombre = nombre;
    marcaProducto->cantGondola = cantGondola;
    marcaProducto->precio = precio;
    
    cout << "\nMarca modificada exitosamente." << endl;
    cout << "\nMarca modificada:" << endl;
	cout << "--> CodMarca: " << codMarca << endl;
	cout << "    Nombre: " << nombre << endl;
	cout << "    CantGondola: " << cantGondola << endl;
	cout << "    Precio: " << precio << endl << endl;
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

void ListaCircularDMarcasProductos::InsertarInicio(int codPasillo, int codProducto,
    int codMarca, string nombre, int cantGondola, int precio)
{
    pnodoMarcaProducto nuevo = new NodoMarcaProducto(codPasillo, codProducto,
		codMarca, nombre, cantGondola, precio);

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

void ListaCircularDMarcasProductos::InsertarFinal(int codPasillo, int codProducto,
    int codMarca, string nombre, int cantGondola, int precio)
{
    pnodoMarcaProducto nuevo = new NodoMarcaProducto(codPasillo, codProducto,
		codMarca, nombre, cantGondola, precio);

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

void ListaCircularDMarcasProductos::InsertarPos(int codPasillo, int codProducto,
    int codMarca, string nombre, int cantGondola, int precio, int pos)
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

        pnodoMarcaProducto nuevo = new NodoMarcaProducto(codPasillo, codProducto,
			codMarca, nombre, cantGondola, precio);
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
        cout << "\nNo hay elementos en la lista.\n" << endl;
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
        cout << "\nNo hay elementos en la lista.\n" << endl;
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
        cout << "\nLa lista esta vacia.\n" << endl;
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
                cout << "\nPosicion no valida.\n" << endl;
        }
    }
}

void ListaCircularDMarcasProductos::Mostrar()
{
    if (ListaVacia())
        cout << "\nLa lista esta vacia.\n" << endl;
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


class ListaDobleInventario
{
public:
    ListaDobleInventario() { primero = NULL; }
    ~ListaDobleInventario();

    void InsertarInicio(int codPasillo, int codProducto, int codMarca, int codInventario,
        string nombre, int cantStock, bool codCanasta);
    void InsertarFinal(int codPasillo, int codProducto, int codMarca, int codInventario,
        string nombre, int cantStock, bool codCanasta);
    void InsertarPos(int codPasillo, int codProducto, int codMarca, int codInventario,
        string nombre, int cantStock, bool codCanasta, int pos);
    bool ListaVacia() { return primero == NULL; }
    void BorrarInicio();
    void BorrarFinal();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();
    void insertarInventario(int codPasillo, int codProducto, int codMarca, int codInventario,
		string nombre, int cantStock, bool codCanasta, ListaSimplePas& listaPasillos,
		ListaDobleProPasillos& listaProductos, ListaCircularDMarcasProductos& listaMarcasProductos);
    bool inventarioRepetido(int codInventario);
    void eliminarInventario(int codInventario, ListaSimplePas& listaPasillos);
    pnodoInventario buscarInventario(int codInventario);
    void modificarInventario(int codInventario, string nombre, int cantStock, bool codCanasta);

private:
    pnodoInventario primero;
};

void ListaDobleInventario::insertarInventario(int codPasillo, int codProducto,
	int codMarca, int codInventario, string nombre, int cantStock, bool codCanasta,
	ListaSimplePas& listaPasillos, ListaDobleProPasillos& listaProductos,
	ListaCircularDMarcasProductos& listaMarcasProductos)
{
    // Valida si el codPasillo existe en la lista simple de pasillos
    if (!listaPasillos.pasilloRepetido(codPasillo))
    {
        cout << "\nEl pasillo no existe.\n" << endl;
        return;    
    }

    // Valida si el codProducto existe en la lista doble de productos de pasillo
    if (!listaProductos.productoRepetido(codProducto))
    {
        cout << "\nEl producto no existe.\n" << endl;
        return;    
    }

    // Valida si el codMarca existe en la lista circular de marcas de productos
    if (!listaMarcasProductos.marcaProductoRepetida(codMarca))
    {
        cout << "\nLa marca del producto no existe.\n" << endl;
        return;    
    }

    // Valida si el codInventario está repetido en la lista doble de inventario
    if (!inventarioRepetido(codInventario))
    {
    	// Inserta en la lista doble de inventario después de las validaciones
	    InsertarFinal(codPasillo, codProducto, codMarca, codInventario, nombre,	cantStock, codCanasta);
	
	    cout << "\nInventario insertado exitosamente." << endl;
	    cout << "\nInventario insertado:" << endl;
	    cout << "--> CodPasillo: " << codPasillo << endl;
	    cout << "    CodProducto: " << codProducto << endl;
	    cout << "    CodMarca: " << codMarca << endl;
	    cout << "    CodInventario: " << codInventario << endl;
	    cout << "    Nombre: " << nombre << endl;
	    cout << "    CantStock: " << cantStock << endl;
	    cout << "    CodCanasta: " << codCanasta << endl << endl;
	}
	else
	{
        cout << "\nEl inventario ya existe.\n" << endl;
        return;    
    }
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
        cout << "\nLa lista esta vacia.\n" << endl;
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
                cout << "\nEl producto se mantiene en el pasillo.\n" << endl;
                return;
            }
            else
            {
                // Como el pasillo no existe, elimina el producto del inventario
                BorrarPosicion(actual->codInventario);
                cout << "\nProducto eliminado del inventario exitosamente.\n" << endl;
                return;
            }
        }

        actual = actual->siguiente;
    }
}

pnodoInventario ListaDobleInventario::buscarInventario(int codInventario)
{
	if (ListaVacia())
	{
        cout << "\nLa lista de inventario esta vacia.\n" << endl;
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

void ListaDobleInventario::modificarInventario(int codInventario, string nombre,
	int cantStock, bool codCanasta)
{
	pnodoInventario inventario = buscarInventario(codInventario);

    if (inventario == NULL)
    {
        cout << "\nInventario no encontrado.\n" << endl;
        return;
    }

    inventario->codInventario = codInventario;
    inventario->nombre = nombre;
    inventario->cantStock = cantStock;
    inventario->codCanasta = codCanasta;

    cout << "\nInventario modificado exitosamente." << endl;
    cout << "\nInventario modificado:" << endl;
	cout << "--> CodInventario: " << codInventario << endl;
	cout << "    Nombre: " << nombre << endl;
	cout << "    CantStock: " << cantStock << endl;
	cout << "    CodCanasta: " << codCanasta << endl << endl;
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

void ListaDobleInventario::InsertarInicio(int codPasillo, int codProducto, int codMarca,
	int codInventario, string nombre, int cantStock, bool codCanasta)
{
    if (ListaVacia())
    {
        primero = new NodoInventario(codPasillo, codProducto, codMarca, codInventario,
            nombre, cantStock, codCanasta);
        primero->anterior = NULL;
    }
    else
    {
        pnodoInventario nuevo = new NodoInventario(codPasillo, codProducto, codMarca,
			codInventario, nombre, cantStock, codCanasta);
        nuevo->siguiente = primero;
        primero->anterior = nuevo;
        primero = nuevo;
    }
}

void ListaDobleInventario::InsertarFinal(int codPasillo, int codProducto, int codMarca,
	int codInventario, string nombre, int cantStock, bool codCanasta)
{
    if (ListaVacia())
    {
        primero = new NodoInventario(codPasillo, codProducto, codMarca, codInventario,
            nombre, cantStock, codCanasta);
        primero->anterior = NULL;
    }
    else
    {
        pnodoInventario aux = primero;

        while (aux->siguiente != NULL)
            aux = aux->siguiente;

        aux->siguiente = new NodoInventario(codPasillo, codProducto, codMarca,
			codInventario, nombre, cantStock, codCanasta);
        aux->siguiente->anterior = aux;
    }
}

void ListaDobleInventario::InsertarPos(int codPasillo, int codProducto, int codMarca,
    int codInventario, string nombre, int cantStock, bool codCanasta, int pos)
{
    if (ListaVacia())
    {
        primero = new NodoInventario(codPasillo, codProducto, codMarca, codInventario,
            nombre, cantStock, codCanasta);
        primero->anterior = NULL;
    }
    else
    {
        if (pos <= 1)
        {
            pnodoInventario nuevo = new NodoInventario(codPasillo, codProducto,
				codMarca, codInventario, nombre, cantStock, codCanasta);
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

            pnodoInventario nuevo = new NodoInventario(codPasillo, codProducto,
				codMarca, codInventario, nombre, cantStock, codCanasta);
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
        cout << "\nNo hay elementos en la lista.\n" << endl;
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
        cout << "\nNo hay elementos en la lista.\n" << endl;
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
        cout << "\nLa lista esta vacia.\n" << endl;
    else
    {
        if ((pos > largoLista()) || (pos < 0))
            cout << "\nError en posicion.\n" << endl;
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


class HashingClientes
{
public:
    HashingClientes(int N); // Constructor
    ~HashingClientes();     // Destructor

	int funcionHash(int cedula) { return cedula % 13; }
    void insertarCliente(int cedula, string nombre, int codCiudad, string telefono,
		string correo);
    void eliminarCliente(int cedula);
    pnodoCte buscarCliente(int cedula);
    void modificarCliente(int cedula, string nombre, int codCiudad, string telefono,
		string correo);
	void reporteClientes();
    void mostrarHash();
    bool loginCliente(int cedula);

private:
	pnodoCte* tablaHash; // Puntero al arreglo que contiene los clientes
	
	friend class ListaCircularCiudades;
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
void HashingClientes::insertarCliente(int cedula, string nombre, int codCiudad,
	string telefono, string correo)
{
    // Aplica la función de hashing
    int indice = funcionHash(cedula);

    pnodoCte clienteNuevo = new NodoCliente(cedula, nombre, codCiudad, telefono, correo);

    // Verifica si ya hay un nodo en esa posición
    if (tablaHash[indice] == NULL)
        tablaHash[indice] = clienteNuevo;
    else
    {
        // Si ya hay un nodo, lo coloca al final de la lista
        pnodoCte actual = tablaHash[indice];

        while (actual->siguiente != NULL)
            actual = actual->siguiente;

        actual->siguiente = clienteNuevo;
    }
    
    cout << "\nCliente insertado exitosamente." << endl;
    cout << "\nCliente insertado:" << endl;
    cout << indice << " --> Cedula: " << cedula << endl;
    cout << "      Nombre: " << nombre << endl;
    cout << "      CodCiudad: " << codCiudad << endl;
    cout << "      Telefono: " << telefono << endl;
    cout << "      Correo: " << correo << endl << endl;
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
        cout << "\nCliente no encontrado.\n" << endl;
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

void HashingClientes::modificarCliente(int cedula, string nombre, int codCiudad,
	string telefono, string correo)
{
    pnodoCte cliente = buscarCliente(cedula);

    if (cliente == NULL)
    {
        cout << "\nCliente no encontrado.\n" << endl;
        return;
    }

    cliente->nombre = nombre;
    cliente->codCiudad = codCiudad;
    cliente->telefono = telefono;
    cliente->correo = correo;
    
    cout << "\nCliente modificado exitosamente." << endl;
    cout << "\nCliente modificado:" << endl;
    cout << funcionHash(cedula) << " --> Cedula: " << cedula << endl;
    cout << "      Nombre: " << nombre << endl;
    cout << "      CodCiudad: " << codCiudad << endl;
    cout << "      Telefono: " << telefono << endl;
    cout << "      Correo: " << correo << endl << endl;
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
			cout << "      Nombre: " << actual->nombre << endl;
			cout << "      Ciudad: " << actual->codCiudad << endl;
			cout << "      Telefono: " << actual->telefono << endl;
			cout << "      Correo: " << actual->correo << endl;
			cout << "      ----------------------------" << endl;
            
            actual = actual->siguiente;
        }

        cout << endl;
    }

    cout << endl;
}

bool HashingClientes::loginCliente(int cedula)
{
    pnodoCte cliente = buscarCliente(cedula);

    return ((cliente != NULL) && (cliente->cedula == cedula));
}


class HashingAdmins
{
public:
    HashingAdmins(int N); // Constructor
    ~HashingAdmins();     // Destructor

	int funcionHash(int cedula) { return cedula % 13; }
    void insertarAdmin(int cedula, string nombre, int codCiudad, string telefono,
		string correo);
    void eliminarAdmin(int cedula);
    pnodoAdmin buscarAdmin(int cedula);
    void modificarAdmin(int cedula, string nombre, int codCiudad, string telefono,
		string correo);
	void reporteAdmins();
    void mostrarHash();
    bool loginAdmin(int cedula);

private:
    pnodoAdmin* tablaHash; // Puntero al arreglo que contiene los administradores
    
    friend class ListaCircularCiudades;
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
void HashingAdmins::insertarAdmin(int cedula, string nombre, int codCiudad,	string telefono,
	string correo)
{
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
    
    cout << "\nAdministrador insertado exitosamente." << endl;
    cout << "\nAdministrador insertado:" << endl;
    cout << indice << " --> Cedula: " << cedula << endl;
    cout << "      Nombre: " << nombre << endl;
    cout << "      CodCiudad: " << codCiudad << endl;
    cout << "      Telefono: " << telefono << endl;
    cout << "      Correo: " << correo << endl << endl;
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
        cout << "\nAdministrador no encontrado.\n" << endl;
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

void HashingAdmins::modificarAdmin(int cedula, string nombre, int codCiudad, string telefono,
	string correo)
{
    pnodoAdmin admin = buscarAdmin(cedula);

    if (admin == NULL)
    {
        cout << "\nAdministrador no encontrado.\n" << endl;
        return;
    }

    admin->nombre = nombre;
    admin->codCiudad = codCiudad;
    admin->telefono = telefono;
    admin->correo = correo;
    
    cout << "\nAdministrador modificado exitosamente." << endl;
    cout << "\nAdministrador modificado:" << endl;
    cout << funcionHash(cedula) << " --> Cedula: " << cedula << endl;
    cout << "      Nombre: " << nombre << endl;
    cout << "      CodCiudad: " << codCiudad << endl;
    cout << "      Telefono: " << telefono << endl;
    cout << "      Correo: " << correo << endl << endl;
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
			cout << "      Nombre: " << actual->nombre << endl;
			cout << "      Ciudad: " << actual->codCiudad << endl;
			cout << "      Telefono: " << actual->telefono << endl;
			cout << "      Correo: " << actual->correo << endl;
			cout << "      ----------------------------" << endl;
			
            actual = actual->siguiente;
        }

        cout << endl;
    }
    
    cout << endl;
}

bool HashingAdmins::loginAdmin(int cedula)
{
    pnodoAdmin admin = buscarAdmin(cedula);

    return ((admin != NULL) && (admin->cedula == cedula));
}


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
    void eliminarCiudad(int codCiudad, HashingClientes& hashClientes,
		HashingAdmins& hashAdmins);
    pnodoCiudad buscarCiudad(int codCiudad);
    void modificarCiudad(int codCiudad, string nombre);
    void reporteCiudades();

private:
    pnodoCiudad primero;
};

void ListaCircularCiudades::insertarCiudad(int codCiudad, string nombre)
{
    // Valida si el codCiudad no está repetido
    if (!ciudadRepetida(codCiudad))
    {
        InsertarInicio(codCiudad, nombre);
        
        cout << "\nCiudad insertada exitosamente." << endl;
        cout << "\nCiudad insertada:" << endl;
        cout << "--> CodCiudad: " << codCiudad << endl;
        cout << "    Nombre: " << nombre << endl << endl;
    }
    else
        cout << "\nLa ciudad ya existe en la lista.\n" << endl;
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

void ListaCircularCiudades::eliminarCiudad(int codCiudad, HashingClientes& hashClientes,
	HashingAdmins& hashAdmins)
{
    if (ListaVacia())
    {
        cout << "\nLa lista esta vacia.\n" << endl;
        return;
    }

    pnodoCiudad actual = primero;
    int pos = 1;

    do
    {
        if (actual->codCiudad == codCiudad)
        {
        	for (int i = 0; i < 13; ++i)
			{
		        pnodoCte actualCte = hashClientes.tablaHash[i];
		        
				while (actualCte != NULL)
				{
		            if (actualCte->getCodCiudad() == codCiudad)
		                hashClientes.eliminarCliente(actualCte->getCedula());

		            actualCte = actualCte->siguiente;
		        }
		    }
		    
		    for (int j = 0; j < 13; ++j)
			{
		        pnodoAdmin actualAdmin = hashAdmins.tablaHash[j];
		        
		        while (actualAdmin != NULL)
				{
		            if (actualAdmin->getCodCiudad() == codCiudad)
		                hashAdmins.eliminarAdmin(actualAdmin->getCedula());

		            actualAdmin = actualAdmin->siguiente;
		        }
		    }

            // Se encontró el nodo con el codCiudad dado, borrar en esa posición
            BorrarPosicion(pos);
            cout << "\nCiudad eliminada exitosamente.\n" << endl;
            return;
        }

        actual = actual->siguiente;
        pos++;
    } while (actual != primero);
}

pnodoCiudad ListaCircularCiudades::buscarCiudad(int codCiudad)
{
    if (ListaVacia())
    {
        cout << "\nLa lista de inventario esta vacia.\n" << endl;
        return NULL;
    }

    pnodoCiudad aux = primero;

    do
    {
        if (aux->codCiudad == codCiudad)
            return aux;

        aux = aux->siguiente;
    } while (aux != primero);

    return NULL;
}

void ListaCircularCiudades::modificarCiudad(int codCiudad, string nombre)
{
    // Busca la ciudad con el código dado
    pnodoCiudad ciudad = buscarCiudad(codCiudad);

    // Verifica si la ciudad no existe
    if (ciudad == NULL)
    {
        cout << "\nCiudad no encontrada.\n" << endl;
        return;
    }

    // Modifica los atributos de la ciudad encontrado
    ciudad->nombre = nombre;

    cout << "\nCiudad modificada: " << endl;
    cout << "--> CodCiudad: " << codCiudad << endl;
    cout << "    Nombre: " << nombre << endl << endl;
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
        cout << "\nNo hay elementos en la lista.\n" << endl;
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
        cout << "\nNo hay elementos en la lista.\n" << endl;
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
        cout << "\nLa lista esta vacia.\n" << endl;
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
        cout << "\nLa lista esta vacia.\n" << endl;
    else
    {
        pnodoCiudad aux = primero;

        do
        {
            // cout << aux->codCiudad << ", " << aux->nombre << " --> " << endl;
            
			cout << "--> CodCiudad: " << aux->codCiudad << endl;
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



int stringAInt(string str)
{
    istringstream iss(str);
    int res;
    
    if (!(iss >> res))
	{
        cout << "\nNo se pudo convertir la cadena a entero.\n" << endl;
        return 0;
    }
    
    return res;
}

string intAString(int num)
{
    ostringstream convertir;  // Objeto de stringstream para la conversión

    // Agrega el número a la secuencia de caracteres de la stringstream
    convertir << num;

    // Convierte la secuencia de caracteres en un string y devolverlo
    return convertir.str();
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
        cout << "\nNo se puede convertir la cadena a bool.\n" << endl;
        return false;
    }
}



void crearListaPasillos(ListaSimplePas& listaPasillos)
{
	ifstream archivo("Pasillos.txt");

    if (!archivo)
	{
        cout << "\nNo se pudo abrir el archivo Pasillos.txt\n" << endl;
        return;
    }

    string linea;

    while (getline(archivo, linea))
	{
        // Ignora líneas vacías
        if (linea == "")
            continue;

        istringstream ss(linea);
        string codPasillo, nombre;

        getline(ss, codPasillo, ';'); ss >> ws;
        getline(ss, nombre, ';'); ss >> ws;

		// Inserta en la lista simple de pasillos después de las validaciones
        listaPasillos.insertarPasillo(stringAInt(codPasillo), nombre);
    }

    archivo.close();
}

void crearListaProductos(ListaDobleProPasillos& listaProductos, ListaSimplePas& listaPasillos)
{
    ifstream archivo("ProductosPasillos.txt");

    if (!archivo)
    {
        cout << "\nNo se pudo abrir el archivo ProductosPasillos.txt\n" << endl;
        return;
    }

    string linea;

    while (getline(archivo, linea))
    {
        // Ignora líneas vacías
        if (linea == "")
            continue;

        istringstream ss(linea);
        string codPasillo, codProducto, nombre;
        
        getline(ss, codPasillo, ';'); ss >> ws;
        getline(ss, codProducto, ';'); ss >> ws;
        getline(ss, nombre, ';'); ss >> ws;

        // Inserta en la lista doble de productos después de las validaciones
        listaProductos.insertarProPasillo(stringAInt(codPasillo), stringAInt(codProducto),
            nombre, listaPasillos);
    }

    archivo.close();
}

void crearListaMarcasProductos(ListaCircularDMarcasProductos& listaMarcas, ListaSimplePas& listaPasillos,
	ListaDobleProPasillos& listaProductos)
{
    ifstream archivo("MarcasProductos.txt");

    if (!archivo)
    {
        cout << "\nNo se pudo abrir el archivo MarcasProductos.txt\n" << endl;
        return;
    }

    string linea;

    while (getline(archivo, linea))
    {
        // Ignora líneas vacías
        if (linea == "")
            continue;

        istringstream ss(linea);
        string codPasillo, codProducto, codMarca, nombre, cantGondola, precio;
        
        getline(ss, codPasillo, ';'); ss >> ws;
        getline(ss, codProducto, ';'); ss >> ws;
        getline(ss, codMarca, ';'); ss >> ws;
        getline(ss, nombre, ';'); ss >> ws;
        getline(ss, cantGondola, ';'); ss >> ws;
        getline(ss, precio, ';'); ss >> ws;

        // Inserta en la lista circular doble de marcas después de las validaciones
        listaMarcas.insertarMarcaProducto(stringAInt(codPasillo), stringAInt(codProducto),
            stringAInt(codMarca), nombre, stringAInt(cantGondola), stringAInt(precio),
            listaPasillos, listaProductos);
    }

    archivo.close();
}

void crearListaInventario(ListaDobleInventario& listaInventario, ListaSimplePas& listaPasillos,
    ListaDobleProPasillos& listaProductos, ListaCircularDMarcasProductos& listaMarcas)
{
	ifstream archivo("Inventario.txt");

    if (!archivo)
    {
        cout << "\nNo se pudo abrir el archivo Inventario.txt\n" << endl;
        return;
    }

    string linea;

    while (getline(archivo, linea))
    {
        // Ignora líneas vacías
        if (linea == "")
            continue;

        istringstream ss(linea);
        string codPasillo, codProducto, codMarca, codInventario, nombre, cantStock, codCanasta;
        
        getline(ss, codPasillo, ';'); ss >> ws;
        getline(ss, codProducto, ';'); ss >> ws;
        getline(ss, codMarca, ';'); ss >> ws;
        getline(ss, codInventario, ';'); ss >> ws;
        getline(ss, nombre, ';'); ss >> ws;
        getline(ss, cantStock, ';'); ss >> ws;
        getline(ss, codCanasta, ';'); ss >> ws;

        // Inserta en la lista doble de inventario después de las validaciones
        listaInventario.insertarInventario(stringAInt(codPasillo), stringAInt(codProducto),
            stringAInt(codMarca), stringAInt(codInventario), nombre, stringAInt(cantStock),
            stringABool(codCanasta), listaPasillos, listaProductos, listaMarcas);
    }

    archivo.close();
}

void crearHashingClientes(HashingClientes& hashClientes, ListaCircularCiudades& listaCiudades)
{
    ifstream archivo("Clientes.txt");

    if (!archivo)
	{
        cout << "\nNo se pudo abrir el archivo Clientes.txt\n" << endl;
        return;
    }

    string linea;

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

        if (listaCiudades.ciudadRepetida(stringAInt(codCiudad)))
			// Inserta en el hash de clientes después de las validaciones
	        hashClientes.insertarCliente(stringAInt(cedula), nombre, stringAInt(codCiudad),
				telefono, correo);
		else
			cout << "\nEl codigo de la ciudad no existe.\n" << endl;
    }

    archivo.close();
}

void crearHashingAdmins(HashingAdmins& hashAdmins, ListaCircularCiudades& listaCiudades)
{
    ifstream archivo("Administradores.txt");

    if (!archivo)
	{
        cout << "\nNo se pudo abrir el archivo Administradores.txt\n" << endl;
        return;
    }

    string linea;

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

		if (listaCiudades.ciudadRepetida(stringAInt(codCiudad)))
			// Inserta en el hash de administradores después de las validaciones
	        hashAdmins.insertarAdmin(stringAInt(cedula), nombre, stringAInt(codCiudad),
				telefono, correo);
		else
			cout << "\nEl codigo de la ciudad no existe.\n" << endl;
    }

    archivo.close();
}


void crearListaCiudades(ListaCircularCiudades& listaCiudades)
{
	ifstream archivo("Ciudades.txt");
	
	if (!archivo)
	{
	    cout << "\nNo se pudo abrir el archivo Ciudades.txt\n" << endl;
	    return;
	}

	string linea;
	
	while (getline(archivo, linea))
	{
	    // Ignora líneas vacías
	    if (linea == "")
	        continue;

        istringstream ss(linea); ss >> ws;
        string codCiudad, nombre;
        
        getline(ss, codCiudad, ';'); ss >> ws;
        getline(ss, nombre, ';'); ss >> ws;

        // Inserta en la lista circular simple de ciudades después de las validaciones
        listaCiudades.insertarCiudad(stringAInt(codCiudad), nombre);
	}
}



void crearReporte(string nombreReporte, string distintivo, string texto)
{
	ofstream archivoNuevo;
	
	string titulo = "Reporte-" + nombreReporte + distintivo + ".txt";
	
	archivoNuevo.open(titulo.c_str(), ios::out);
	
	// Comprueba si el archivo se abrió correctamente
    if (!archivoNuevo.is_open())
    {
        cout << "\nError al abrir el archivo para escritura.\n" << endl;
        return;
    }
	
	archivoNuevo << "Reporte: ";
	archivoNuevo << nombreReporte << endl << endl;
	archivoNuevo << texto << endl;
	
	cout << "Reporte " << nombreReporte << " creado con exito.\n" << endl;
	
	archivoNuevo.close();
}

void ListaSimplePas::reportePasillos()
{
    string nombreReporte = "Pasillos";
    string texto = "";

    // Itera sobre la lista de pasillos y guarda en el archivo
    pnodoPasillo temp = primero;
    bool listaVacia = true;

	while (temp != NULL)
	{
		listaVacia = false;

        texto += "CodPasillo: " + intAString(temp->codPasillo) +
				"\nNombre: " + temp->nombre + "\n\n";

        temp = temp->siguiente;
    }

    if (!listaVacia)
    {
	    cout << "Reporte: " << nombreReporte << endl << endl;
	    cout << texto; // Imprime en consola
	    crearReporte(nombreReporte, "", texto); // Escribe en el archivo
	}
	else
		cout << "No hay pasillos registrados.\n" << endl;
}

void ListaDobleProPasillos::reporteProPasillos()
{
    int codigoPasillo;
    cout << "Ingrese el codigo del pasillo: ";
    cin >> codigoPasillo;

	string nombreReporte = "Productos";
    string texto = "";

    pnodoProPasillo temp = primero;
    bool encontrado = false;

    while (temp != NULL)
    {
        if (temp->codPasillo == codigoPasillo)
        {
            encontrado = true;
            texto += "CodPasillo: " + intAString(temp->codPasillo) +
                     "\nCodProducto: " + intAString(temp->codProducto) +
                     "\nNombre: " + temp->nombre + "\n\n";
        }

        temp = temp->siguiente;
    }

    if (encontrado)
    {
        cout << "\nReporte: " << nombreReporte << endl << endl;
        cout << texto; // Muestra en consola
        crearReporte(nombreReporte, ("-" + intAString(codigoPasillo)), texto); // Escribe en el archivo
    }
    else
        cout << "\nNo se encontraron productos en el pasillo.\n" << endl;
}

void ListaCircularDMarcasProductos::reporteMarcasProductos()
{
    int codigoPasillo, codigoProducto;
    cout << "Ingrese el codigo del pasillo: ";
    cin >> codigoPasillo;
    cout << "Ingrese el codigo del producto: ";
    cin >> codigoProducto;

    string nombreReporte = "Marcas de Productos";
    string texto = "";

    pnodoMarcaProducto temp = primero;
    bool encontrado = false;

    // Avanza hasta el último nodo de la lista circular
    while (temp->siguiente != primero)
        temp = temp->siguiente;

    // Recorre la lista en sentido inverso para encontrar el pasillo y el producto
    do
	{
        if ((temp->codPasillo == codigoPasillo) && (temp->codProducto == codigoProducto))
		{
            encontrado = true;
            texto += "CodPasillo: " + intAString(temp->codPasillo) +
                     "\nCodProducto: " + intAString(temp->codProducto) +
                     "\nCodMarca: " + intAString(temp->codMarca) +
                     "\nNombre: " + temp->nombre +
                     "\nCantGondola: " + intAString(temp->cantGondola) +
                     "\nPrecio: " + intAString(temp->precio) + "\n\n";
        }

        temp = temp->anterior;
    } while (temp != primero->anterior);

    if (encontrado)
    {
        cout << "\nReporte: " << nombreReporte << endl << endl;
        cout << texto; // Muestra en consola
        crearReporte(nombreReporte, ("-" + temp->nombre), texto); // Escribe en el archivo
    }
    else
        cout << "\nNo se encontraron marcas asociadas al producto.\n" << endl;
}

void HashingClientes::reporteClientes()
{
	string nombreReporte = "Clientes";
    string texto = "";
    bool listasVacias = true;

	// Itera sobre cada posición de la tabla de hashing
    for (int i = 0; i < 13; ++i)
	{
        pnodoCte temp = tablaHash[i];
        
        while (temp != NULL)
		{
			listasVacias = false;

            // Imprime los clientes de esta posición en la tabla
            texto += "Cedula: " + intAString(temp->cedula) +
            		 "\nNombre: " + temp->nombre +
                     "\nCodCiudad: " + intAString(temp->codCiudad) +
					 "\nTelefono: " + temp->telefono +
					 "\nCorreo: " + temp->correo + "\n\n";

            temp = temp->siguiente;
        }
    }

	if (!listasVacias)
	{
	    cout << "Reporte: " << nombreReporte << endl << endl;
	    cout << texto; // Imprime en consola
	    crearReporte(nombreReporte, "", texto); // Escribe en el archivo
	}
	else
		cout << "No hay clientes registrados.\n" << endl;
}

void HashingAdmins::reporteAdmins()
{
	string nombreReporte = "Administradores";
    string texto = "";
    bool listasVacias = true;

	// Itera sobre cada posición de la tabla de hashing
    for (int i = 0; i < 13; ++i)
	{
        pnodoAdmin temp = tablaHash[i];
        
        while (temp != NULL)
		{
			listasVacias = false;

            // Imprime los clientes de esta posición en la tabla
            texto += "Cedula: " + intAString(temp->cedula) +
            		 "\nNombre: " + temp->nombre +
                     "\nCodCiudad: " + intAString(temp->codCiudad) +
					 "\nTelefono: " + temp->telefono +
					 "\nCorreo: " + temp->correo + "\n\n";

            temp = temp->siguiente;
        }
    }

	if (!listasVacias)
	{
	    cout << "Reporte: " << nombreReporte << endl << endl;
	    cout << texto; // Imprime en consola
	    crearReporte(nombreReporte, "", texto); // Escribe en el archivo
	}
	else
		cout << "No hay administradores registrados.\n" << endl;
}

void ListaCircularCiudades::reporteCiudades()
{
	string nombreReporte = "Ciudades";
    string texto = "";

    // Itera sobre la lista de ciudades y guarda en el archivo
    pnodoCiudad temp = primero;
    bool listaVacia = true;

	if (temp != NULL)
    {
    	listaVacia = false;
        pnodoCiudad inicio = temp;

        do
        {
            texto += "CodCiudad: " + intAString(temp->codCiudad) +
                     "\nNombre: " + temp->nombre + "\n\n";

            temp = temp->siguiente;
        } while (temp != inicio);
    }

    if (!listaVacia)
    {
	    cout << "Reporte: " << nombreReporte << endl << endl;
	    cout << texto; // Imprime en consola
	    crearReporte(nombreReporte, "", texto); // Escribe en el archivo
	}
	else
		cout << "No hay ciudades registradas.\n" << endl;
}

void ListaSimplePas::reportePasilloMasVisitado()
{
    string nombreReporte = "Pasillo mas visitado";
    string texto = "";

    pnodoPasillo temp = primero;
    int maxVisitas = 0;

    // Encuentra el número máximo de visitas
    while (temp != NULL)
	{
        if (temp->contVisitas > maxVisitas)
            maxVisitas = temp->contVisitas;

        temp = temp->siguiente;
    }

    // Agrega al texto los pasillos más visitados
    temp = primero;
    bool pasilloMasVisitado = false;

    while (temp != NULL)
	{
        if (temp->contVisitas == maxVisitas)
		{
            if (!pasilloMasVisitado)
			{
                texto += "Pasillo(s) mas visitado(s):\n";
                pasilloMasVisitado = true;
            }

            texto += "CodPasillo: " + intAString(temp->codPasillo) +
                    "\nNombre: " + temp->nombre +
                    "\nCantidad de visitas: " + intAString(temp->contVisitas) + "\n\n";
        }

        temp = temp->siguiente;
    }

    if (pasilloMasVisitado && maxVisitas > 0)
	{
        cout << "Reporte: " << nombreReporte << endl << endl;
        cout << texto; // Imprime en consola
        crearReporte(nombreReporte, "", texto); // Escribe en el archivo
    }
	else
        cout << "No hay pasillos mas visitados.\n" << endl;
}

void ListaSimplePas::reportePasilloMenosVisitado()
{
    string nombreReporte = "Pasillo menos visitado";
    string texto = "";

    pnodoPasillo temp = primero;
    int minVisitas = 1;
    bool pasilloMenosVisitado = false;

    // Encuentra el número mínimo de visitas
    while (temp != NULL)
	{
        if (temp->contVisitas >= 1)
		{
            if (!pasilloMenosVisitado || (temp->contVisitas < minVisitas))
			{
                minVisitas = temp->contVisitas;
                pasilloMenosVisitado = true;
            }
        }
        temp = temp->siguiente;
    }

    // Agrega al texto los pasillos menos visitados
    temp = primero;

    while (temp != NULL)
	{
        if (temp->contVisitas == minVisitas)
		{
            texto += "Pasillo(s) menos visitado(s):\n";
            texto += "CodPasillo: " + intAString(temp->codPasillo) +
                    "\nNombre: " + temp->nombre +
                    "\nCantidad de visitas: " + intAString(temp->contVisitas) + "\n\n";
        }

        temp = temp->siguiente;
    }

    if (pasilloMenosVisitado)
	{
        cout << "Reporte: " << nombreReporte << endl << endl;
        cout << texto; // Imprime en consola
        crearReporte(nombreReporte, "", texto); // Escribe en el archivo
    }
	else
        cout << "No hay pasillos menos visitados.\n" << endl;
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
        cout << "************INSERTAR:************" << endl;
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
                
                cout << "Ingrese el codigo del pasillo: ";
				cin >> codPasillo;
		    	cout << "Ingrese el nombre del pasillo: ";
				cin.ignore();
				getline(cin, nombre);
                
				listaPasillos.insertarPasillo(codPasillo, nombre); 
				break;
			}

            case 2:
            {
                int codPasillo, codProducto;
                string nombre;
                
                cout << "Ingrese el codigo del pasillo: ";
				cin >> codPasillo;
                cout << "Ingrese el codigo del producto: ";
				cin >> codProducto;
                cout << "Ingrese el nombre del producto: ";
				cin.ignore();
				getline(cin, nombre);
                
				listaProductos.insertarProPasillo(codPasillo, codProducto, nombre, listaPasillos); 
				break;
			}

            case 3:
            {
                int codPasillo, codProducto, codMarca, cantGondola, precio;
                string nombre;
                
                cout << "Ingrese el codigo del pasillo: ";
				cin >> codPasillo;
                cout << "Ingrese el codigo del producto: ";
				cin >> codProducto;
                cout << "Ingrese el codigo de la marca: ";
				cin >> codMarca;
                cout << "Ingrese el nombre del producto: ";
				cin.ignore();
				getline(cin, nombre);
                cout << "Ingrese el cantidad en gondola: ";
				cin >> cantGondola;
                cout << "Ingrese el precio del producto: ";
				cin >> precio;
                
				listaMarcasProductos.insertarMarcaProducto(codPasillo, codProducto, codMarca,
					nombre, cantGondola, precio, listaPasillos, listaProductos); 
				break;
			}

            case 4:
            {
                int codPasillo, codProducto, codMarca, codInventario, cantStock;
                string nombre;
                bool codCanasta;
                
                cout << "Ingrese el codigo del pasillo: ";
				cin >> codPasillo;
                cout << "Ingrese el codigo del producto: ";
				cin >> codProducto;
                cout << "Ingrese el codigo de la marca: ";
				cin >> codMarca;
                cout << "Ingrese el codigo del inventario: ";
				cin >> codInventario;
                cout << "Ingrese el nombre del producto: ";
				cin.ignore();
				getline(cin, nombre);
                cout << "Ingrese el cantidad de stock: ";
				cin >> cantStock;
                cout << "Ingrese el codigo de canasta: ";
				cin >> codCanasta;
                
				listaInventario.insertarInventario(codPasillo, codProducto, codMarca,
					codInventario, nombre, cantStock, codCanasta, listaPasillos, listaProductos,
					listaMarcasProductos); 
				break;
			}

            case 5:
            {
                int cedula, codCiudad;
                string nombre, telefono, correo;

                do
				{
	                cout << "Ingrese la cedula del cliente: ";
					cin >> cedula;
	                cout << "Ingrese el nombre del cliente: ";
					cin.ignore();
					getline(cin, nombre);
	                cout << "Ingrese el codigo de la ciudad: ";
					cin >> codCiudad;
	                cout << "Ingrese el telefono del cliente: ";
					cin >> telefono;
	                cout << "Ingrese el correo del cliente: ";
					cin >> correo;

					if (!listaCiudades.ciudadRepetida(codCiudad))
						cout << "\nEl codigo de la ciudad no existe. Intente de nuevo.\n" << endl;
            	} while(!listaCiudades.ciudadRepetida(codCiudad));

				hashClientes.insertarCliente(cedula, nombre, codCiudad, telefono, correo);
                break;
            }
            
            case 6:
            {
                int cedula, codCiudad;
                string nombre, telefono, correo;

				do
				{
					cout << "Ingrese la cedula del administrador: ";
					cin >> cedula;
	                cout << "Ingrese el nombre del administrador: ";
					cin.ignore();
					getline(cin, nombre);
	                cout << "Ingrese el codigo de la ciudad: ";
					cin >> codCiudad;
	                cout << "Ingrese el telefono del administrador: ";
					cin >> telefono;
	                cout << "Ingrese el correo del administrador: ";
					cin >> correo;

					if (!listaCiudades.ciudadRepetida(codCiudad))
						cout << "\nEl codigo de la ciudad no existe. Intente de nuevo.\n" << endl;
				} while(!listaCiudades.ciudadRepetida(codCiudad));

				hashAdmins.insertarAdmin(cedula, nombre, codCiudad, telefono, correo);
                break;
            }
            
            case 7:
            {
                int codCiudad;
                string nombre;
                
                cout << "Ingrese el codigo de la ciudad: ";
				cin >> codCiudad;
                cout << "Ingrese el nombre de la ciudad: ";
				cin.ignore();
				getline(cin, nombre);
                
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
        cout << "************ELIMINAR:************" << endl;
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
            	int codPasilloAEliminar;
				
				cout << "Ingrese el codigo del pasillo a eliminar: ";
				cin >> codPasilloAEliminar;
				
				pnodoPasillo pasilloEncontrado = listaPasillos.buscarPasillo(codPasilloAEliminar);
				
                if (pasilloEncontrado != NULL)
					listaPasillos.eliminarPasillo(codPasilloAEliminar);
				else
    				cout << "\nNo se encontro el pasillo con el codigo dado.\n" << endl;
                break;
            }

            case 2:
            {
            	int codProductoAEliminar;
				
                cout << "Ingrese el codigo del producto a eliminar: ";
				cin >> codProductoAEliminar;
                
                pnodoProPasillo productoEncontrado = listaProductos.buscarProPasillo(codProductoAEliminar);
                
                if (productoEncontrado != NULL)
					listaProductos.eliminarProPasillo(codProductoAEliminar);
				else
    				cout << "\nNo se encontro el producto con el codigo dado.\n" << endl;
                break;
			}

            case 3:
            {
				listaMarcasProductos.eliminarMarcasProductos();
                break;
			}

            case 4:
            {
            	int codInventarioAEliminar;

				cout << "Ingrese el codigo del inventario a eliminar: ";
				cin >> codInventarioAEliminar;
				
				pnodoInventario inventarioEncontrado = listaInventario.buscarInventario(codInventarioAEliminar);
                
                if (inventarioEncontrado != NULL)
					listaInventario.eliminarInventario(codInventarioAEliminar, listaPasillos);
				else
    				cout << "\nNo se encontro el producto con el codigo de inventario dado.\n" << endl;
                break;
			}

            case 5:
            {
                int cedulaAEliminar;
                
				cout << "Ingrese la cedula del cliente a eliminar: ";
				cin >> cedulaAEliminar;

				hashClientes.eliminarCliente(cedulaAEliminar);
                break;
            }

            case 6:
        	{
                int cedulaAEliminar;
                
				cout << "Ingrese la cedula del administrador a eliminar: ";
				cin >> cedulaAEliminar;
                
				hashAdmins.eliminarAdmin(cedulaAEliminar);
                break;
            }

            case 7:
            {
            	int codCiudadAEliminar;

				cout << "Ingrese el codigo de la ciudad a eliminar: ";
				cin >> codCiudadAEliminar;

                pnodoCiudad ciudadEncontrada = listaCiudades.buscarCiudad(codCiudadAEliminar);

                if (ciudadEncontrada != NULL)
					listaCiudades.eliminarCiudad(codCiudadAEliminar, hashClientes, hashAdmins);
				else
    				cout << "\nNo se encontro la ciudad con el codigo dado.\n" << endl;
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

void menuBuscarClientes(int opcion, ListaSimplePas& listaPasillos, ListaDobleProPasillos& listaProductos,
	ListaCircularDMarcasProductos& listaMarcasProductos)
{
	do
    {
        cout << "************BUSCAR:************" << endl;
	    cout << "1. Pasillo" << endl;
	    cout << "2. Producto" << endl;
	    cout << "3. Marca" << endl;
	    cout << "4. Volver" << endl;
	    
	    cout << "\nIngrese la opcion deseada: ";
		cin >> opcion;

        switch (opcion)
        {
            case 1:
            {
            	int codPasilloABuscar;
                
				cout << "Ingrese el codigo del pasillo a buscar: ";
				cin >> codPasilloABuscar;
                
				pnodoPasillo pasilloBuscado = listaPasillos.buscarPasillo(codPasilloABuscar);
				
                if (pasilloBuscado != NULL)
				{
                    cout << "\nPasillo encontrado:" << endl;
                    cout << "CodPasillo: " << pasilloBuscado->getCodPasillo() << endl;
                    cout << "Nombre: " << pasilloBuscado->getNombre() << endl << endl;
                }
				else
                    cout << "\nPasillo con codigo " << codPasilloABuscar << " no encontrado.\n" << endl;
                break;
			}
			
            case 2:
            {
            	int codProductoABuscar;
                
				cout << "Ingrese el codigo del producto a buscar: ";
				cin >> codProductoABuscar;
                
				pnodoProPasillo productoBuscado = listaProductos.buscarProPasillo(codProductoABuscar);
				
                if (productoBuscado != NULL)
				{
                    cout << "\nProducto encontrado:" << endl;
                    cout << "CodPasillo: " << productoBuscado->getCodPasillo() << endl;
                    cout << "CodProducto: " << productoBuscado->getCodProducto() << endl;
                    cout << "Nombre: " << productoBuscado->getNombre() << endl << endl;
                }
				else
                    cout << "\nPasillo con codigo " << codProductoABuscar << " no encontrado.\n" << endl;
                break;
			}

            case 3:
            {
            	int codMarcaABuscar;
                
				cout << "Ingrese el codigo de la marca a buscar: ";
				cin >> codMarcaABuscar;
                
				pnodoMarcaProducto marcaBuscada = listaMarcasProductos.buscarMarcaProducto(codMarcaABuscar);
				
                if (marcaBuscada != NULL)
				{
					cout << "\nMarca encontrada:" << endl;
                    cout << "CodPasillo: " << marcaBuscada->getCodPasillo() << endl;
		            cout << "CodProducto: " << marcaBuscada->getCodProducto() << endl;
		            cout << "CodMarca: " << marcaBuscada->getCodMarca() << endl;
		            cout << "Nombre: " << marcaBuscada->getNombre() << endl;
		            cout << "CantGondola: " << marcaBuscada->getCantGondola() << endl;
		            cout << "Precio: " << marcaBuscada->getPrecio() << endl << endl;
                }
				else
                    cout << "\nMarca con codigo " << codMarcaABuscar << " no encontrada.\n" << endl;
                break;
			}

            case 4:
				system("cls");
				cout << endl; break;

            default:
				system("cls");
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 4);
}

void menuBuscarAdmins(int opcion, ListaSimplePas& listaPasillos, ListaDobleProPasillos& listaProductos,
	ListaCircularDMarcasProductos& listaMarcasProductos, ListaDobleInventario& listaInventario,
	HashingClientes& hashClientes, HashingAdmins& hashAdmins, ListaCircularCiudades& listaCiudades)
{
	do
    {
        cout << "************BUSCAR:************" << endl;
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
                
				cout << "Ingrese el codigo del pasillo a buscar: ";
				cin >> codPasilloABuscar;
                
				pnodoPasillo pasilloBuscado = listaPasillos.buscarPasillo(codPasilloABuscar);
				
                if (pasilloBuscado != NULL)
				{
                    cout << "\nPasillo encontrado:" << endl;
                    cout << "CodPasillo: " << pasilloBuscado->getCodPasillo() << endl;
                    cout << "Nombre: " << pasilloBuscado->getNombre() << endl << endl;
                }
				else
                    cout << "\nPasillo con codigo " << codPasilloABuscar << " no encontrado.\n" << endl;
                break;
			}
			
            case 2:
            {
            	int codProductoABuscar;
                
				cout << "Ingrese el codigo del producto a buscar: ";
				cin >> codProductoABuscar;
                
				pnodoProPasillo productoBuscado = listaProductos.buscarProPasillo(codProductoABuscar);
				
                if (productoBuscado != NULL)
				{
                    cout << "\nProducto encontrado:" << endl;
                    cout << "CodPasillo: " << productoBuscado->getCodPasillo() << endl;
                    cout << "CodProducto: " << productoBuscado->getCodProducto() << endl;
                    cout << "Nombre: " << productoBuscado->getNombre() << endl << endl;
                }
				else
                    cout << "\nPasillo con codigo " << codProductoABuscar << " no encontrado.\n" << endl;
                break;
			}

            case 3:
            {
            	int codMarcaABuscar;
                
				cout << "Ingrese el codigo de la marca a buscar: ";
				cin >> codMarcaABuscar;
                
				pnodoMarcaProducto marcaBuscada = listaMarcasProductos.buscarMarcaProducto(codMarcaABuscar);
				
                if (marcaBuscada != NULL)
				{
					cout << "\nMarca encontrada:" << endl;
                    cout << "CodPasillo: " << marcaBuscada->getCodPasillo() << endl;
		            cout << "CodProducto: " << marcaBuscada->getCodProducto() << endl;
		            cout << "CodMarca: " << marcaBuscada->getCodMarca() << endl;
		            cout << "Nombre: " << marcaBuscada->getNombre() << endl;
		            cout << "CantGondola: " << marcaBuscada->getCantGondola() << endl;
		            cout << "Precio: " << marcaBuscada->getPrecio() << endl << endl;
                }
				else
                    cout << "\nMarca con codigo " << codMarcaABuscar << " no encontrada.\n" << endl;
                break;
			}

            case 4:
            {
            	int codInventarioABuscar;
                
				cout << "Ingrese el codigo del inventario a buscar: ";
				cin >> codInventarioABuscar;
                
				pnodoInventario inventarioBuscado = listaInventario.buscarInventario(codInventarioABuscar);
				
                if (inventarioBuscado != NULL)
				{
					cout << "\nMarca encontrada:" << endl;
                    cout << "CodPasillo: " << inventarioBuscado->getCodPasillo() << endl;
		            cout << "CodProducto: " << inventarioBuscado->getCodProducto() << endl;
		            cout << "CodMarca: " << inventarioBuscado->getCodMarca() << endl;
		            cout << "CodInventario: " << inventarioBuscado->getCodInventario() << endl;
		            cout << "Nombre: " << inventarioBuscado->getNombre() << endl;
		            cout << "CantStock: " << inventarioBuscado->getCantStock() << endl;
		            cout << "CodCanasta: " << inventarioBuscado->getCodCanasta() << endl << endl;
                }
				else
                    cout << "\nInventario con codigo " << codInventarioABuscar << " no encontrado.\n" << endl;
                break;
			}
            
            case 5:
            {
	            int cedulaABuscar;
	            
				cout << "Ingrese la cedula del cliente a buscar: ";
				cin >> cedulaABuscar;
	            
				pnodoCte clienteBuscado = hashClientes.buscarCliente(cedulaABuscar);
				
	            if (clienteBuscado != NULL)
				{
	                cout << "\nCliente encontrado:" << endl;
	                cout << hashClientes.funcionHash(cedulaABuscar) << " --> Cedula: "
						<< clienteBuscado->getCedula() << endl;
	                cout << "      Nombre: " << clienteBuscado->getNombre() << endl;
	                cout << "      Ciudad: " << clienteBuscado->getCodCiudad() << endl;
	                cout << "      Telefono: " << clienteBuscado->getTelefono() << endl;
	                cout << "      Correo: " << clienteBuscado->getCorreo() << endl << endl;
	            }
				else
	                cout << "\nCliente con cedula " << cedulaABuscar << " no encontrado.\n" << endl;
	            break;
	        }
            
            case 6:
            {
                int cedulaABuscar;
                
				cout << "Ingrese la cedula del administrador a buscar: ";
				cin >> cedulaABuscar;
                
				pnodoAdmin adminBuscado = hashAdmins.buscarAdmin(cedulaABuscar);
				
                if (adminBuscado != NULL)
				{
                    cout << "\nAdministrador encontrado:" << endl;
                    cout << hashAdmins.funcionHash(cedulaABuscar) << " --> Cedula: "
						<< adminBuscado->getCedula() << endl;
                    cout << "      Nombre: " << adminBuscado->getNombre() << endl;
                    cout << "      Ciudad: " << adminBuscado->getCodCiudad() << endl;
                    cout << "      Telefono: " << adminBuscado->getTelefono() << endl;
                    cout << "      Correo: " << adminBuscado->getCorreo() << endl << endl;
                }
				else
                    cout << "\nAdministrador con cedula " << cedulaABuscar << " no encontrado.\n" << endl;
                break;
            }
            
            case 7:
            {
            	int codCiudadABuscar;
                
				cout << "Ingrese el codigo de la ciudad a buscar: ";
				cin >> codCiudadABuscar;
                
				pnodoCiudad ciudadBuscada = listaCiudades.buscarCiudad(codCiudadABuscar);
				
                if (ciudadBuscada != NULL)
				{
                    cout << "\nCiudad encontrada:" << endl;
                    cout << "CodCiudad: " << ciudadBuscada->getCodCiudad() << endl;
                    cout << "Nombre: " << ciudadBuscada->getNombre() << endl << endl;
                }
				else
                    cout << "\nCiudad con codigo " << codCiudadABuscar << " no encontrada.\n" << endl;
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
        cout << "************MODIFICAR:************" << endl;
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

				cout << "Ingrese el codigo de pasillo a modificar: ";
				cin >> codPasillo;
		    	cout << "Ingrese el nuevo nombre del pasillo: ";
				cin.ignore();
				getline(cin, nombre);

				listaPasillos.modificarPasillo(codPasillo, nombre);
				break;
			}

            case 2:
            {
            	int codProducto;
				string nombre;
				
				cout << "Ingrese el codigo del producto a modificar: ";
				cin >> codProducto;
		    	cout << "Ingrese el nuevo nombre del producto: ";
				cin.ignore();
				getline(cin, nombre);
            	
            	listaProductos.modificarProPasillo(codProducto, nombre);
                break;
            }

            case 3:
            {
            	int codMarca, cantGondola, precio;
				string nombre;
				
				cout << "Ingrese el codigo de la marca a modificar: ";
				cin >> codMarca;
				cout << "Ingrese el nuevo nombre de la marca: ";
				cin.ignore();
				getline(cin, nombre);
		        cout << "Ingrese la nueva cantidad de producto en la gondola: ";
				cin >> cantGondola;
		    	cout << "Ingrese el nuevo precio del producto: ";
				cin >> precio;

            	listaMarcasProductos.modificarMarcaProducto(codMarca, nombre, cantGondola, precio);
                break;
            }

            case 4:
            {
            	int codInventario, cantStock;
				string nombre;
				bool codCanasta;
			
				cout << "Ingrese el codigo del inventario a modificar: ";
				cin >> codInventario;
		        cout << "Ingrese el nuevo nombre de la marca: ";
				cin.ignore();
				getline(cin, nombre);
		        cout << "Ingrese la nueva cantidad de stock: ";
				cin >> cantStock;
		        cout << "Ingrese el codigo de canasta basica: ";
				cin >> codCanasta;

            	listaInventario.modificarInventario(codInventario, nombre, cantStock, codCanasta);
                break;
            }

            case 5:
            {
                int cedulaAModificar, codCiudad;
                string nombre, telefono, correo;
                
                cout << "Ingrese la cedula del cliente a modificar: ";
				cin >> cedulaAModificar;
                cout << "Ingrese el nuevo nombre del cliente: ";
				cin.ignore();
				getline(cin, nombre);
                cout << "Ingrese el nuevo codigo de la ciudad del cliente: ";
				cin >> codCiudad;
                cout << "Ingrese el nuevo telefono del cliente: ";
				cin >> telefono;
                cout << "Ingrese el nuevo correo del cliente: ";
				cin >> correo;
                
                hashClientes.modificarCliente(cedulaAModificar, nombre,
					codCiudad, telefono, correo);
                break;
            }
            
            case 6:
            {
                int cedulaAModificar, codCiudad;
                string nombre, telefono, correo;
                
                cout << "Ingrese la cedula del administrador a modificar: ";
				cin >> cedulaAModificar;
                cout << "Ingrese el nuevo nombre del administrador: ";
				cin.ignore();
				getline(cin, nombre);
                cout << "Ingrese el nuevo codigo de la ciudad del administrador: ";
				cin >> codCiudad;
                cout << "Ingrese el nuevo telefono del administrador: ";
				cin >> telefono;
                cout << "Ingrese el nuevo correo del administrador: ";
				cin >> correo;
                
                hashAdmins.modificarAdmin(cedulaAModificar, nombre, codCiudad,
					telefono, correo);
                break;
            }
            
            case 7:
            {
            	int codCiudad;
				string nombre;
				
				cout << "Ingrese el codigo de la ciudad a modificar: ";
				cin >> codCiudad;
				cout << "Ingrese el nuevo nombre de la ciudad: ";
		    	cin.ignore();
		    	getline(cin, nombre);

            	listaCiudades.modificarCiudad(codCiudad, nombre);
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
        cout << "************LISTAR:************" << endl;
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
            	cout << "Pasillos:" << endl;
                listaPasillos.Mostrar();
                break;

            case 2:
            	system("cls");
            	cout << "Productos:" << endl;
                listaProductos.Mostrar();
                break;

            case 3:
            	system("cls");
            	cout << "Marcas de Productos:" << endl;
                listaMarcasProductos.Mostrar();
                break;

            case 4:
            	system("cls");
            	cout << "Inventario:" << endl;
                listaInventario.Mostrar();
                break;
            
            case 5:
            	system("cls");
            	cout << "Clientes:" << endl;
                hashClientes.mostrarHash();
                break;
            
            case 6:
            	system("cls");
            	cout << "Administradores:" << endl;
                hashAdmins.mostrarHash();
                break;
            
            case 7:
            	system("cls");
            	cout << "Ciudades:" << endl;
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

void menuReportesClientes(int opcion, ListaSimplePas& listaPasillos, ListaDobleProPasillos& listaProductos,
	ListaCircularDMarcasProductos& listaMarcasProductos)
{
	do
    {
        cout << "************REPORTES:************" << endl;
	    cout << "1. Pasillos" << endl;
	    cout << "2. Productos" << endl;
	    cout << "3. Marcas" << endl;
	    cout << "4. Volver" << endl;
	    
	    cout << "\nIngrese la opcion deseada: ";
		cin >> opcion;

        switch (opcion)
        {
            case 1:
				system("cls");
				listaPasillos.reportePasillos();
				break;

            case 2:
				system("cls");
				listaProductos.reporteProPasillos();
				break;

            case 3:
				system("cls");
            	listaMarcasProductos.reporteMarcasProductos();
				break;

            case 4:
				system("cls");
				cout << endl; break;

            default:
				system("cls");
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 4);
}

void menuReportesAdmins(int opcion, ListaSimplePas& listaPasillos, ListaDobleProPasillos& listaProductos,
	ListaCircularDMarcasProductos& listaMarcasProductos, ListaDobleInventario& listaInventario,
	HashingClientes& hashClientes, HashingAdmins& hashAdmins, ListaCircularCiudades& listaCiudades)
{
	do
    {
        cout << "************REPORTES:************" << endl;
	    cout << "1. Pasillos" << endl;
	    cout << "2. Productos" << endl;
	    cout << "3. Marcas" << endl;
	    cout << "4. Clientes" << endl;
	    cout << "5. Administradores" << endl;
	    cout << "6. Ciudades" << endl;
	    cout << "7. Pasillo mas visitado" << endl;
	    cout << "8. Pasillo menos visitado" << endl;
	    cout << "9. Producto mas buscado" << endl;
	    cout << "10. Marcas mas buscadas" << endl;
	    cout << "11. Volver" << endl;
	    
	    cout << "\nIngrese la opcion deseada: ";
		cin >> opcion;

        switch (opcion)
        {
            case 1:
				system("cls");
				listaPasillos.reportePasillos();
				break;

            case 2:
				system("cls");
				listaProductos.reporteProPasillos();
				break;

            case 3:
				system("cls");
            	listaMarcasProductos.reporteMarcasProductos();
				break;

            case 4:
				system("cls");
            	hashClientes.reporteClientes();
				break;
            
            case 5:
				system("cls");
            	hashAdmins.reporteAdmins();
				break;
            
            case 6:
				system("cls");
            	listaCiudades.reporteCiudades();
				break;
			
			case 7:
				system("cls");
            	listaPasillos.reportePasilloMasVisitado();
				break;
				
			case 8:
				system("cls");
            	listaPasillos.reportePasilloMenosVisitado();
				break;
				
			case 9: break;
			
			case 10: break;
            
            case 11:
				system("cls");
				cout << endl; break;
            
            default:
				system("cls");
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 11);
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
    crearHashingClientes(hashClientes, listaCiudades);
    HashingAdmins hashAdmins(13);
    crearHashingAdmins(hashAdmins, listaCiudades);
    
    int cedula, opcion, opcion2, opcion3;
    
    bool salirPrograma = false;
    bool credencialesValidas = false;
    
    do
    {
    	system("cls");
        cout << "************BIENVENID(@)************\n" << endl;
        cout << "1. Iniciar sesion" << endl;
        cout << "2. Salir del programa" << endl;
		cout << "\nIngrese la opcion deseada: ";
		cin >> opcion;

        switch (opcion)
		{
            case 1: // Loguearse
            {
                credencialesValidas = false;

				do
				{
					cout << "\nIngrese su numero de cedula para ingresar." << endl;
			        cout << "Ingrese su cedula: ";
					cin >> cedula;

                    if (hashClientes.loginCliente(cedula))
                    {
                        system("cls");
						cout << "Bienvenid(@) estimad(@) cliente, "
							<< hashClientes.buscarCliente(cedula)->getNombre() << endl << endl;
					    credencialesValidas = true;

				        do
						{
					        menuCliente();
					        cout << "\nIngrese la opcion deseada: ";
							cin >> opcion2;
					
					        switch (opcion2)
							{
								case 1: // Buscar
									system("cls");
					        		menuBuscarClientes(opcion3, listaPasillos, listaProductos,
										listaMarcasProductos);
					            	break;
					
					            case 2: // Algunos reportes
					            	system("cls");
					                menuReportesClientes(opcion3, listaPasillos, listaProductos,
										listaMarcasProductos);
					            	break;
					
					            case 3: // Salir
					                cout << "Saliendo del sistema..." << endl;
									break;

					            default:
					            	system("cls");
									cout << "Ingrese una opcion valida.\n" << endl;
							}
					    } while (opcion2 != 3);
					    
					    credencialesValidas = true;
                    }
                    else if (hashAdmins.loginAdmin(cedula))
				    {
				    	system("cls");
				    	cout << "Bienvenid(@), administrador(@) "
							<< hashAdmins.buscarAdmin(cedula)->getNombre() << endl << endl;
					    credencialesValidas = true;

				        do
						{
					        menuAdiministrador();
					        cout << "\nIngrese la opcion deseada: ";
							cin >> opcion2;
					
					        switch (opcion2)
							{
								case 1: // Insertar
					        		system("cls");
					                menuInsertar(opcion3, listaPasillos, listaProductos,
										listaMarcasProductos, listaInventario, hashClientes,
										hashAdmins, listaCiudades);
					                break;
					
					            case 2: // Eliminar
					            	system("cls");
					                menuEliminar(opcion3, listaPasillos, listaProductos,
										listaMarcasProductos, listaInventario, hashClientes,
										hashAdmins, listaCiudades);
					                break;
					
					            case 3: // Buscar
					            	system("cls");
					                menuBuscarAdmins(opcion3, listaPasillos, listaProductos,
										listaMarcasProductos, listaInventario, hashClientes,
										hashAdmins, listaCiudades);
					            	break;
					
					            case 4: // Modificar
					            	system("cls");
					                menuModificar(opcion3, listaPasillos, listaProductos,
										listaMarcasProductos, listaInventario, hashClientes,
										hashAdmins, listaCiudades);
					            	break;
					
					            case 5: // Listar
					            	system("cls");
					                menuListar(opcion3, listaPasillos, listaProductos,
										listaMarcasProductos, listaInventario, hashClientes,
										hashAdmins, listaCiudades);
					            	break;
					
					            case 6: // Reportes
					            	system("cls");
					                menuReportesAdmins(opcion3, listaPasillos, listaProductos,
										listaMarcasProductos, listaInventario, hashClientes,
										hashAdmins, listaCiudades);
					            	break;
					
					            case 7: // Salir
					                cout << "Saliendo del sistema..." << endl;
									break;
					
					            default:
					            	system("cls");
									cout << "Ingrese una opcion valida.\n" << endl;
							}
					    } while (opcion2 != 7);
					}
					else
						cout << "\nNombre de usuario o cedula incorrectos. Intente nuevamente." << endl;
			    } while (!credencialesValidas); break;
			}
			
            case 2: // Salir del programa
                cout << "Saliendo del programa..." << endl;
                salirPrograma = true;
                break;

            default:
                cout << "Ingrese una opción válida.\n" << endl;
                break;
        }
	} while (!salirPrograma);

    return 0;
}

