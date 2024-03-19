#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

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

    void insertarCliente(int cedula, string nombre, int codCiudad, string telefono, string correo);
    void eliminarCliente(int cedula);
    pnodoCte buscarCliente(int cedula);
    void modificarCliente(int cedula, string nombre, int codCiudad, string telefono, string correo);
    void mostrarHash();

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

void HashingClientes::eliminarCliente(int cedula)
{
    int indice = cedula % 13;

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
    int indice = cedula % 13;

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
        
        if (tablaHash[i] == 0)
			cout << " No hay clientes." << endl;

        cout << endl;
    }
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

    void insertarAdmin(int cedula, string nombre, int codCiudad, string telefono, string correo);
    void eliminarAdmin(int cedula);
    pnodoAdmin buscarAdmin(int cedula);
    void modificarAdmin(int cedula, string nombre, int codCiudad, string telefono, string correo);
    void mostrarHash();

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

void HashingAdmins::eliminarAdmin(int cedula)
{
    int indice = cedula % 13;

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
    int indice = cedula % 13;

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
        
        if (tablaHash[i] == 0)
			cout << " No hay administradores." << endl;

        cout << endl;
    }
}



// Clase Nodo para almacenar el nombre y la contraseña del usuario
class NodoUsuario
{
public:
    string nombre;
    string contrasena;
    NodoUsuario* siguiente;

    NodoUsuario(string nombre, string contrasena) : nombre(nombre), contrasena(contrasena), siguiente(NULL) {}
};

// Clase ListaUsuarios para manejar la lista de usuarios
class ListaUsuarios {
public:
    ListaUsuarios() : cabeza(nullptr) {}
    ~ListaUsuarios();

    void agregarUsuario(string nombre, string contrasena);
    bool verificarCredenciales(string nombre, string contrasena);

private:
    NodoUsuario* cabeza;
};

ListaUsuarios::~ListaUsuarios() {
    NodoUsuario* actual = cabeza;
    while (actual != nullptr) {
        NodoUsuario* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

void ListaUsuarios::agregarUsuario(string nombre, string contrasena) {
    NodoUsuario* nuevoUsuario = new NodoUsuario(nombre, contrasena);
    if (cabeza == nullptr) {
        cabeza = nuevoUsuario;
    } else {
        nuevoUsuario->siguiente = cabeza;
        cabeza = nuevoUsuario;
    }
}

bool ListaUsuarios::verificarCredenciales(string nombre, string contrasena) {
    NodoUsuario* actual = cabeza;
    while (actual != nullptr) {
        if (actual->nombre == nombre && actual->contrasena == contrasena) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
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

void mostrarMenuPrincipal()
{
    cout << "******* MENU PRINCIPAL *******" << endl;
    cout << "  1. Gestionar Pasillos" << endl;
    cout << "  2. Gestionar Productos" << endl;
    cout << "  3. Gestionar Marcas" << endl;
    cout << "  4. Gestionar Inventarios" << endl;
    cout << "  5. Gestionar Clientes" << endl;
    cout << "  6. Gestionar Administradores" << endl;
    cout << "  7. Gestionar Ciudades" << endl;
    cout << "  8. Salir" << endl;
}



int main()
{
	// Crea un objeto HashingClientes y un objeto HashingAdmins de tamaño 13
	HashingClientes hashClientes(13);
    HashingAdmins hashAdmins(13);
    
    cargarClientesDesdeArchivo(hashClientes);
    cargarAdminsDesdeArchivo(hashAdmins);
    
    int opcion, opcion2;
    do
	{
        mostrarMenuPrincipal();
        cout << "\nIngrese la opcion deseada: ";
        cin >> opcion;

        switch (opcion)
		{
			case 1: // Pasillo
            case 2: // Producto
            case 3: // Marca
            case 4: // Inventario
            case 5: // Clientes
            {
        		do
        		{
        			cout << "\n******* CLIENTES *******" << endl;
				    cout << "  1. Insertar cliente" << endl;
				    cout << "  2. Eliminar cliente" << endl;
				    cout << "  3. Buscar cliente" << endl;
				    cout << "  4. Modificar cliente" << endl;
				    cout << "  5. Mostrar clientes" << endl;
				    cout << "  6. Volver" << endl;
				    
				    cout << "\nIngrese la opcion deseada: ";
	        		cin >> opcion2;
	        		
	        		switch (opcion2)
					{
		        		case 1:
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
			            case 2:
						{
			                int cedulaAEliminar;
			                
							cout << "Ingrese la cedula del cliente a eliminar: "; cin >> cedulaAEliminar;
			                
							hashClientes.eliminarCliente(cedulaAEliminar);
			                break;
			            }
			            case 3:
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
			            case 4:
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
			            case 5:
						{
			                cout << "\nClientes:" << endl;
			                hashClientes.mostrarHash();
			                break;
			            }
			            case 6: cout << endl; break;
			            default: cout << "Ingrese una opcion valida.\n" << endl;
		        	}
				} while (opcion2 != 6);
				
				break;
			}
			
            case 6: // Administradores
            {
            	do
        		{
        			cout << "\n******* ADMINISTRADORES *******" << endl;
				    cout << "  1. Insertar administrador" << endl;
				    cout << "  2. Eliminar administrador" << endl;
				    cout << "  3. Buscar administrador" << endl;
				    cout << "  4. Modificar administrador" << endl;
				    cout << "  5. Mostrar administradores" << endl;
				    cout << "  6. Volver" << endl;
				    
				    cout << "\nIngrese la opcion deseada: ";
	        		cin >> opcion2;
	        		
	        		switch (opcion2)
					{
		        		case 1:
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
			            case 2:
						{
			                int cedulaAEliminar;
			                
							cout << "Ingrese la cedula del administrador a eliminar: "; cin >> cedulaAEliminar;
			                
							hashAdmins.eliminarAdmin(cedulaAEliminar);
			                break;
			            }
			            case 3:
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
			            case 4:
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
			            case 5:
						{
			                cout << "\nAdministradores:" << endl;
			                hashAdmins.mostrarHash();
			                break;
			            }
			            case 6: cout << endl; break;
			            default: cout << "Ingrese una opcion valida.\n" << endl;
		        	}
				} while (opcion2 != 6);
				
				break;
			}
            case 7: // Ciudad
            case 8: // Salir
            {
                cout << "Saliendo del programa...\n" << endl;
                break;
            }
            default: cout << "Ingrese una opcion valida.\n" << endl;
		}
    } while (opcion != 8);

    return 0;
}
