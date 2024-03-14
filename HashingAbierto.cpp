#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Clase NodoCliente para almacenar la información de clientes
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

private:
    int cedula;
    string nombre;
    int codCiudad;
    string telefono;
    string correo;
    NodoCliente* siguiente; // Clase de Autoreferencia

    friend class ListaSimpleCte;
    friend class HashingClientes;
};

typedef NodoCliente* pnodoCte;



class ListaSimpleCte
{
public:
    ListaSimpleCte() { primero = NULL; } // Constructor
    ~ListaSimpleCte();                   // Destructor

    bool ListaVacia() { return primero == NULL; }
    int largoLista();
    void InsertarInicio(int cedula, string nombre, int codCiudad, string telefono, string correo);
    void InsertarFinal(int cedula, string nombre, int codCiudad, string telefono, string correo);
    void InsertarPos(int cedula, string nombre, int codCiudad, string telefono, string correo, int pos);
    void BorrarInicio();
    void BorrarFinal();
    void BorrarPosicion(int pos);
    void Mostrar();

private:
    pnodoCte primero;
};

ListaSimpleCte::~ListaSimpleCte()
{
    pnodoCte aux;

    while (primero)
    {
        aux = primero;
        primero = primero->siguiente;

        delete aux;
    }

    primero = NULL;
}

int ListaSimpleCte::largoLista()
{
    int cont = 0;
    pnodoCte aux = primero;

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

void ListaSimpleCte::InsertarInicio(int cedula, string nombre, int codCiudad, string telefono, string correo)
{
    if (ListaVacia())
        primero = new NodoCliente(cedula, nombre, codCiudad, telefono, correo);
    else
        primero = new NodoCliente(cedula, nombre, codCiudad, telefono, correo, primero);
}

void ListaSimpleCte::InsertarFinal(int cedula, string nombre, int codCiudad, string telefono, string correo)
{
    if (ListaVacia())
        primero = new NodoCliente(cedula, nombre, codCiudad, telefono, correo);
    else
    {
        pnodoCte aux = primero;

        while (aux->siguiente != NULL)
            aux = aux->siguiente;

        aux->siguiente = new NodoCliente(cedula, nombre, codCiudad, telefono, correo);
    }
}

void ListaSimpleCte::InsertarPos(int cedula, string nombre, int codCiudad, string telefono, string correo, int pos)
{
    if (ListaVacia())
        primero = new NodoCliente(cedula, nombre, codCiudad, telefono, correo);
    else
    {
        if (pos <= 1)
            InsertarInicio(cedula, nombre, codCiudad, telefono, correo);
        else
        {
            pnodoCte aux = primero;
            int i = 2;
            
            while ((i != pos) && (aux->siguiente != NULL))
            {
                i++;
                aux = aux->siguiente;
            }

            pnodoCte nuevo = new NodoCliente(cedula, nombre, codCiudad, telefono, correo);
            nuevo->siguiente = aux->siguiente;
            aux->siguiente = nuevo;
        }
    }
}

void ListaSimpleCte::BorrarInicio()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista." << endl;
    else
    {
        if (primero->siguiente == NULL)
        {
            pnodoCte temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoCte aux = primero;
            primero = primero->siguiente;
            delete aux;
        }
    }
}

void ListaSimpleCte::BorrarFinal()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista." << endl;
    else
    {
        if (primero->siguiente == NULL)
        {
            pnodoCte temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoCte aux = primero;
            
            while (aux->siguiente->siguiente != NULL)
                aux = aux->siguiente;

            pnodoCte temp = aux->siguiente;
            aux->siguiente = NULL;
            delete temp;
        }
    }
}

void ListaSimpleCte::BorrarPosicion(int pos)
{
    if (ListaVacia())
        cout << "La lista esta vacia." << endl;
    else
    {
        if ((pos > largoLista()) || (pos < 0))
            cout << "Error en posición." << endl;
        else
        {
            if (pos == 1)
            {
                pnodoCte temp = primero;
                primero = primero->siguiente;
                delete temp; // BorrarInicio();
            }
            else
            {
                pnodoCte aux = primero;
                int cont = 2;
                
                while (cont < pos)
                {
                    aux = aux->siguiente;
                    cont++;
                }

                pnodoCte temp = aux->siguiente;
                aux->siguiente = aux->siguiente->siguiente;
                delete temp;
            }
        }
    }
}

void ListaSimpleCte::Mostrar()
{
    pnodoCte aux;

    if (primero == NULL)
        cout << "No hay elementos.";
    else
    {
        aux = primero;
        
        while (aux)
        {
            cout << aux->cedula << " - " <<
                aux->nombre << " - " <<
                aux->codCiudad << " - " <<
                aux->telefono << " - " <<
                aux->correo << " -> " << endl;

            aux = aux->siguiente;
        }

        cout << endl;
    }
}



class HashingClientes
{
public:
    HashingClientes(int N); // Constructor
    ~HashingClientes();     // Destructor

    void insertarCliente(int cedula, string nombre, int codCiudad, string telefono, string correo);
    void mostrarHash();

private:
    int numCubos;   	 // Número de cubos
    pnodoCte* tablaHash; // Puntero a un arreglo que contiene cubos

    bool ciudadExiste(int codCiudad);
};

HashingClientes::HashingClientes(int N)
{
    numCubos = 13;
    tablaHash = new pnodoCte[numCubos]();

    // Inicializa la tabla hash con NULL
    for (int i = 0; i < numCubos; i++)
        tablaHash[i] = NULL;
}

HashingClientes::~HashingClientes()
{
    for (int i = 0; i < numCubos; i++)
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

bool HashingClientes::ciudadExiste(int codCiudad)
{
    return true;
}

// Método que inserta un nuevo cliente en la tabla hash
void HashingClientes::insertarCliente(int cedula, string nombre, int codCiudad, string telefono, string correo)
{
    // Valida que la ciudad exista
    if (!ciudadExiste(codCiudad))
    {
        cout << "Ciudad no valida." << endl;
        return;
    }

    // Aplica la función de hashing
    int indice = cedula % 13;

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


void HashingClientes::mostrarHash()
{
    for (int i = 0; i < numCubos; ++i)
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



// Clase NodoAdmin para almacenar la información de administradores
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

private:
    int cedula;
    string nombre;
    int codCiudad;
    string telefono;
    string correo;
    NodoAdmin* siguiente; // Clase de Autoreferencia

    friend class ListaSimpleAdmin;
    friend class HashingAdmins;
};

typedef NodoAdmin* pnodoAdmin;



class ListaSimpleAdmin
{
public:
    ListaSimpleAdmin() { primero = NULL; } // Constructor
    ~ListaSimpleAdmin();                   // Destructor

    bool ListaVacia() { return primero == NULL; }
    int largoLista();
    void InsertarInicio(int cedula, string nombre, int codCiudad, string telefono, string correo);
    void InsertarFinal(int cedula, string nombre, int codCiudad, string telefono, string correo);
    void InsertarPos(int cedula, string nombre, int codCiudad, string telefono, string correo, int pos);
    void BorrarInicio();
    void BorrarFinal();
    void BorrarPosicion(int pos);
    void Mostrar();

private:
    pnodoAdmin primero;
};

ListaSimpleAdmin::~ListaSimpleAdmin()
{
    pnodoAdmin aux;

    while (primero)
    {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

    primero = NULL;
}

int ListaSimpleAdmin::largoLista()
{
    int cont = 0;
    pnodoAdmin aux = primero;

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

void ListaSimpleAdmin::InsertarInicio(int cedula, string nombre, int codCiudad, string telefono, string correo)
{
    if (ListaVacia())
        primero = new NodoAdmin(cedula, nombre, codCiudad, telefono, correo);
    else
        primero = new NodoAdmin(cedula, nombre, codCiudad, telefono, correo, primero);
}

void ListaSimpleAdmin::InsertarFinal(int cedula, string nombre, int codCiudad, string telefono, string correo)
{
    if (ListaVacia())
        primero = new NodoAdmin(cedula, nombre, codCiudad, telefono, correo);
    else
    {
        pnodoAdmin aux = primero;

        while (aux->siguiente != NULL)
            aux = aux->siguiente;

        aux->siguiente = new NodoAdmin(cedula, nombre, codCiudad, telefono, correo);
    }
}

void ListaSimpleAdmin::InsertarPos(int cedula, string nombre, int codCiudad, string telefono, string correo, int pos)
{
    if (ListaVacia())
        primero = new NodoAdmin(cedula, nombre, codCiudad, telefono, correo);
    else
    {
        if (pos <= 1)
            InsertarInicio(cedula, nombre, codCiudad, telefono, correo);
        else
        {
            pnodoAdmin aux = primero;
            int i = 2;
            
            while ((i != pos) && (aux->siguiente != NULL))
            {
                i++;
                aux = aux->siguiente;
            }

            pnodoAdmin nuevo = new NodoAdmin(cedula, nombre, codCiudad, telefono, correo);
            nuevo->siguiente = aux->siguiente;
            aux->siguiente = nuevo;
        }
    }
}

void ListaSimpleAdmin::BorrarInicio()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista." << endl;
    else
    {
        if (primero->siguiente == NULL)
        {
            pnodoAdmin temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoAdmin aux = primero;
            primero = primero->siguiente;
            delete aux;
        }
    }
}

void ListaSimpleAdmin::BorrarFinal()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista." << endl;
    else
    {
        if (primero->siguiente == NULL)
        {
            pnodoAdmin temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoAdmin aux = primero;
            
            while (aux->siguiente->siguiente != NULL)
                aux = aux->siguiente;

            pnodoAdmin temp = aux->siguiente;
            aux->siguiente = NULL;
            delete temp;
        }
    }
}

void ListaSimpleAdmin::BorrarPosicion(int pos)
{
    if (ListaVacia())
        cout << "La lista esta vacia." << endl;
    else
    {
        if ((pos > largoLista()) || (pos < 0))
            cout << "Error en posición." << endl;
        else
        {
            if (pos == 1)
            {
                pnodoAdmin temp = primero;
                primero = primero->siguiente;
                delete temp; // BorrarInicio();
            }
            else
            {
                pnodoAdmin aux = primero;
                int cont = 2;
                
                while (cont < pos)
                {
                    aux = aux->siguiente;
                    cont++;
                }

                pnodoAdmin temp = aux->siguiente;
                aux->siguiente = aux->siguiente->siguiente;
                delete temp;
            }
        }
    }
}

void ListaSimpleAdmin::Mostrar()
{
    pnodoAdmin aux;

    if (primero == NULL)
        cout << "No hay elementos.";
    else
    {
        aux = primero;
        
        while (aux)
        {
            cout << aux->cedula << " - " <<
                aux->nombre << " - " <<
                aux->codCiudad << " - " <<
                aux->telefono << " - " <<
                aux->correo << " -> " << endl;

            aux = aux->siguiente;
        }

        cout << endl;
    }
}



class HashingAdmins
{
public:
    HashingAdmins(int N); // Constructor
    ~HashingAdmins();     // Destructor

    void insertarAdmin(int cedula, string nombre, int codCiudad, string telefono, string correo);
    void mostrarHash();

private:
    int numCubos;   	 // Número de cubos
    pnodoAdmin* tablaHash; // Puntero a un arreglo que contiene cubos

    bool ciudadExiste(int codCiudad);
};

HashingAdmins::HashingAdmins(int N)
{
    numCubos = 13;
    tablaHash = new pnodoAdmin[numCubos]();

    // Inicializa la tabla hash con NULL
    for (int i = 0; i < numCubos; i++)
        tablaHash[i] = NULL;
}

HashingAdmins::~HashingAdmins()
{
    for (int i = 0; i < numCubos; i++)
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

bool HashingAdmins::ciudadExiste(int codCiudad)
{
    return true;
}

// Método que inserta un nuevo administrador en la tabla hash
void HashingAdmins::insertarAdmin(int cedula, string nombre, int codCiudad, string telefono, string correo)
{
    // Valida que la ciudad exista
    if (!ciudadExiste(codCiudad))
    {
        cout << "Ciudad no valida." << endl;
        return;
    }

    // Aplica la función de hashing
    int indice = cedula % 13;

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


void HashingAdmins::mostrarHash()
{
    for (int i = 0; i < numCubos; ++i)
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


// Función auxiliar para convertir de string a entero
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



int main()
{
	ifstream archivoClientes("Clientes.txt");

    if (!archivoClientes)
	{
        cout << "No se pudo abrir el archivo Clientes.txt" << endl;
        return 1;
    }

    cout << "Contenido del archivo Clientes.txt:" << endl;

    string linea1;
    int contador = 0;
    HashingClientes hashClientes(13);

    while (getline(archivoClientes, linea1))
	{
        // Ignora líneas vacías
        if (linea1 == "")
            continue;

        // Incrementa el contador para ignorar la primera línea
        contador++;

        // Comienza a procesar las líneas a partir de la segunda
        if (contador > 1)
		{
            istringstream ss(linea1);
            string cedula, nombre, codCiudad, telefono, correo;
            
            getline(ss, cedula, ';'); ss >> ws;
            getline(ss, nombre, ';'); ss >> ws;
            getline(ss, codCiudad, ';'); ss >> ws;
            getline(ss, telefono, ';'); ss >> ws;
            getline(ss, correo, ';'); ss >> ws;

            // Inserta en el hash de clientes después de las validaciones
            cout << "Insertando cliente: " << cedula << ", " << nombre << ", " << codCiudad << ", " << telefono << ", " << correo << endl;
            hashClientes.insertarCliente(stringAInt(cedula), nombre, stringAInt(codCiudad), telefono, correo);
        }
    }

    archivoClientes.close();
    
    hashClientes.mostrarHash();
    
    cout << endl;
    
    ifstream archivoAdmins("Administradores.txt");

    if (!archivoAdmins)
	{
        cout << "No se pudo abrir el archivo Administradores.txt" << endl;
        return 1;
    }

    cout << "Contenido del archivo Administradores.txt:" << endl;

    string linea2;
    HashingAdmins hashAdmins(13);

    while (getline(archivoAdmins, linea2))
	{
        // Ignora líneas vacías
        if (linea2 == "")
            continue;
        
        istringstream ss(linea2);
        string cedula, nombre, codCiudad, telefono, correo;
        
        getline(ss, cedula, ';'); ss >> ws;
        getline(ss, nombre, ';'); ss >> ws;
        getline(ss, codCiudad, ';'); ss >> ws;
        getline(ss, telefono, ';'); ss >> ws;
        getline(ss, correo, ';'); ss >> ws;

        // Inserta en el hash de administradores después de las validaciones
        cout << "Insertando administrador: " << cedula << ", " << nombre << ", " << codCiudad << ", " << telefono << ", " << correo << endl;
        hashAdmins.insertarAdmin(stringAInt(cedula), nombre, stringAInt(codCiudad), telefono, correo);
    }

    archivoAdmins.close();
    
    hashAdmins.mostrarHash();

    return 0;
}
