#include <iostream>
#include <string>

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

    void insertarAlInicio(int codPasillo, const string& nombre);
    void insertarAlFinal(int codPasillo, const string& nombre);
    void insertarEnPosicion(int codPasillo, const string& nombre, int pos);
    bool listaVacia() { return primero == NULL; }
    void borrarAlFinal();
    void borrarAlInicio();
    void borrarEnPosicion(int pos);
    void mostrar();
    int largoLista();
    void InsertarMenuPasillo(int codPasillo, const string& nombre);
    bool pasilloRepetido(int codPasillo) const;

private:
    pnodoPasillo primero;
};

bool ListaSimplePas::pasilloRepetido(int codPasillo) const {
    pnodoPasillo aux = primero;

    while (aux != nullptr) {
        if (aux->codPasillo == codPasillo) {
            // Si se encuentra el pasillo, es repetido
            return true;
        }
        aux = aux->siguiente;
    }

    // Si no se encuentra, no es repetido
    return false;
}

void ListaSimplePas::InsertarMenuPasillo(int codPasillo, const string& nombre) {
    // Verificar si el pasillo ya existe en la lista
    pnodoPasillo aux = primero;
    bool rep = false;

    while (aux != nullptr) {
        if (aux->codPasillo == codPasillo) {
            // Si se encuentra el pasillo, es repetido
            rep = true;
        }
        aux = aux->siguiente;
    }
    if (rep==false) {
        // Si no existe, insertar al inicio
        insertarAlInicio(codPasillo, nombre);
        cout << "Pasillo insertado exitosamente." << endl;
    }
    else {
        cout << "El pasillo ya existe en la lista." << endl;
    }
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

void ListaSimplePas::insertarAlInicio(int codPasillo, const string& nombre)
{
    if (listaVacia())
    {
        primero = new NodoPasillo(codPasillo, nombre);
    }
    else
    {
        pnodoPasillo nuevo = new NodoPasillo(codPasillo, nombre, primero);
        primero = nuevo;
    }
}

void ListaSimplePas::insertarAlFinal(int codPasillo, const string& nombre)
{
    if (listaVacia())
    {
        primero = new NodoPasillo(codPasillo, nombre);
    }
    else
    {
        pnodoPasillo aux = primero;
        while (aux->siguiente != NULL)
            aux = aux->siguiente;

        aux->siguiente = new NodoPasillo(codPasillo, nombre);
    }
}

void ListaSimplePas::insertarEnPosicion(int codPasillo, const string& nombre, int pos)
{
    if (listaVacia())
    {
        primero = new NodoPasillo(codPasillo, nombre);
    }
    else
    {
        if (pos <= 1)
        {
            insertarAlInicio(codPasillo, nombre);
        }
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

void ListaSimplePas::borrarAlFinal()
{
    if (listaVacia())
    {
        cout << "No hay elementos en la lista." << endl;
    }
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

void ListaSimplePas::borrarAlInicio()
{
    if (listaVacia())
    {
        cout << "No hay elementos en la lista." << endl;
    }
    else
    {
        pnodoPasillo temp = primero;
        primero = primero->siguiente;
        delete temp;
    }
}

void ListaSimplePas::borrarEnPosicion(int pos)
{
    if (listaVacia())
    {
        cout << "La lista está vacía." << endl;
    }
    else
    {
        if ((pos > largoLista()) || (pos < 0))
        {
            cout << "Error en posición." << endl;
        }
        else
        {
            if (pos == 1)
            {
                borrarAlInicio();
            }
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

void ListaSimplePas::mostrar()
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

    void insertarAlInicio(int codPasillo, int codProducto, const string& nombre);
    void insertarAlFinal(int codPasillo, int codProducto, const string& nombre);
    void insertarEnPosicion(int codPasillo, int codProducto, const string& nombre, int pos);
    bool listaVacia() { return primero == NULL; }
    void borrarAlFinal();
    void borrarAlInicio();
    void borrarEnPosicion(int pos);
    void mostrar();
    int largoLista();
    void InsertarMenuProPasillo(int codPasillo, int codProducto, const string& nombre, ListaSimplePas listaSimplePasillo);
    bool productoRepetido(int codProducto) const;

private:
    pnodoProPasillo primero;
};


bool ListaDobleProPasillos::productoRepetido(int codProducto) const {
    pnodoProPasillo aux = primero;

    while (aux != nullptr) {
        if (aux->codProducto == codProducto) {
            // Si se encuentra el producto, es repetido
            return true;
        }
        aux = aux->siguiente;
    }

    // Si no se encuentra, no es repetido
    return false;
}

void ListaDobleProPasillos::InsertarMenuProPasillo(int codPasillo, int codProducto, const string& nombre, ListaSimplePas listaSimplePasillos) {
    // Verificar si el pasillo existe en la lista simple

    if (listaSimplePasillos.pasilloRepetido(codPasillo)==true) {
        if (productoRepetido(codProducto)==false) {
            // Insertar al inicio después de las validaciones
            insertarAlInicio(codPasillo, codProducto, nombre);
            cout << "Producto insertado exitosamente." << endl;
        }
        else {
            cout << "El código de producto ya existe en la lista." << endl;
        }
    }
    else {
        cout << "El pasillo no existe en la lista simple." << endl;
    }
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

void ListaDobleProPasillos::insertarAlInicio(int codPasillo, int codProducto, const string& nombre)
{
    if (listaVacia())
    {
        primero = new NodoProPasillo(codPasillo, codProducto, nombre);
        primero->anterior = NULL;
    }
    else
    {
        primero = new NodoProPasillo(codPasillo, codProducto, nombre);
        primero->siguiente->anterior = primero;
    }
}

void ListaDobleProPasillos::insertarAlFinal(int codPasillo, int codProducto, const string& nombre)
{
    if (listaVacia())
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

void ListaDobleProPasillos::insertarEnPosicion(int codPasillo, int codProducto, const string& nombre, int pos)
{
    if (listaVacia())
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

void ListaDobleProPasillos::borrarAlFinal()
{
    if (listaVacia())
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

void ListaDobleProPasillos::borrarAlInicio()
{
    if (listaVacia())
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

void ListaDobleProPasillos::borrarEnPosicion(int pos)
{
    if (listaVacia())
        cout << "La lista está vacía." << endl;
    else
    {
        if ((pos > largoLista()) || (pos < 0))
            cout << "Error en posición." << endl;
        else
        {
            if (pos == 1)
                borrarAlInicio();
            else
            {
                if (pos == largoLista())
                    borrarAlFinal();
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

    if (listaVacia())
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

void ListaDobleProPasillos::mostrar()
{
    pnodoProPasillo aux;

    aux = primero;
    while (aux)
    {
        cout << aux->codPasillo << ";" << aux->codProducto << ";" << aux->nombre << " -> ";
        aux = aux->siguiente;
    }

    cout << endl;
}

class NodoInventario {
public:
    NodoInventario(int _codPasillo, int _codProducto, int _codMarca, int _codInventario, const string& _nombre, int _cantidadStock, bool _codigoCanasta)
        : codPasillo(_codPasillo), codProducto(_codProducto), codMarca(_codMarca), codInventario(_codInventario),
        nombre(_nombre), cantidadStock(_cantidadStock), codigoCanasta(_codigoCanasta), siguiente(nullptr), anterior(nullptr) {}

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

class ListaDobleInventario {
public:
    ListaDobleInventario() : primero(nullptr) {}
    ~ListaDobleInventario();

    void insertarAlInicio(int codPasillo, int codProducto, int codMarca, int codInventario, const string& nombre, int cantidadStock, bool codigoCanasta);
    void insertarAlFinal(int codPasillo, int codProducto, int codMarca, int codInventario, const string& nombre, int cantidadStock, bool codigoCanasta);
    void insertarEnPosicion(int codPasillo, int codProducto, int codMarca, int codInventario, const string& nombre, int cantidadStock, bool codigoCanasta, int pos);
    bool listaVacia() const { return primero == nullptr; }
    void borrarAlFinal();
    void borrarAlInicio();
    void borrarEnPosicion(int pos);
    void mostrar() const;
    int largoLista() const;
    void insertarInventario(ListaSimplePas& listaSimplePasillos, ListaDobleProPasillos& listaSimpleProductos, int codPasillo, int codProducto, ListaCircularDMarcasProductos& marca, int codMarca, int codInventario, const string& nombre, int cantidadStock, bool codigoCanasta);

private:
    pnodoInventario primero;
};

void ListaDobleInventario::insertarInventario(ListaSimplePas& listaSimplePasillos,  ListaDobleProPasillos&listaSimpleProductos, int codPasillo, int codProducto, ListaCircularDMarcasProductos& marca, int codMarca, int codInventario, const string& nombre, int cantidadStock, bool codigoCanasta) {
    // Validar si el codPasillo existe en la lista simple de pasillos
    if (listaSimplePasillos.pasilloRepetido(codPasillo)==false) {
        cout << "El pasillo no existe en la lista simple de pasillos." << endl;
    }

    // Validar si el codProducto existe en la lista simple de productos
    if (listaSimpleProductos.productoRepetido(codProducto)==false) {
        cout << "El producto no existe en la lista simple de productos." << endl;
    }

    // Validar si el codMarca no está repetido en la lista doble de inventario
    if (marca.marcaRepetida(codMarca)==false) {
        cout << "El código de marca no existe en la lista doble de inventario." << endl;
    }
    if (marca.marcaRepetida(codMarca) == true && listaSimpleProductos.productoRepetido(codProducto) == true && listaSimplePasillos.pasilloRepetido(codPasillo) == true) {

        // Insertar en la lista doble de inventario después de las validaciones
        insertarAlInicio(codPasillo, codProducto, codMarca, codInventario, nombre, cantidadStock, codigoCanasta);
        cout << "Producto insertado en el inventario exitosamente." << endl;
    }
}


ListaDobleInventario::~ListaDobleInventario() {
    pnodoInventario aux;

    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

    primero = nullptr;
}

void ListaDobleInventario::insertarAlInicio(int codPasillo, int codProducto, int codMarca, int codInventario, const string& nombre, int cantidadStock, bool codigoCanasta) {
    if (listaVacia()) {
        primero = new NodoInventario(codPasillo, codProducto, codMarca, codInventario, nombre, cantidadStock, codigoCanasta);
        primero->anterior = nullptr;
    }
    else {
        pnodoInventario nuevo = new NodoInventario(codPasillo, codProducto, codMarca, codInventario, nombre, cantidadStock, codigoCanasta);
        nuevo->siguiente = primero;
        primero->anterior = nuevo;
        primero = nuevo;
    }
}

void ListaDobleInventario::insertarAlFinal(int codPasillo, int codProducto, int codMarca, int codInventario, const string& nombre, int cantidadStock, bool codigoCanasta) {
    if (listaVacia()) {
        primero = new NodoInventario(codPasillo, codProducto, codMarca, codInventario, nombre, cantidadStock, codigoCanasta);
        primero->anterior = nullptr;
    }
    else {
        pnodoInventario aux = primero;

        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }

        aux->siguiente = new NodoInventario(codPasillo, codProducto, codMarca, codInventario, nombre, cantidadStock, codigoCanasta);
        aux->siguiente->anterior = aux;
    }
}

void ListaDobleInventario::insertarEnPosicion(int codPasillo, int codProducto, int codMarca, int codInventario, const string& nombre, int cantidadStock, bool codigoCanasta, int pos) {
    if (listaVacia()) {
        primero = new NodoInventario(codPasillo, codProducto, codMarca, codInventario, nombre, cantidadStock, codigoCanasta);
        primero->anterior = nullptr;
    }
    else {
        if (pos <= 1) {
            pnodoInventario nuevo = new NodoInventario(codPasillo, codProducto, codMarca, codInventario, nombre, cantidadStock, codigoCanasta);
            nuevo->siguiente = primero;

            if (primero != nullptr)
                primero->anterior = nuevo;

            primero = nuevo;
        }
        else {
            pnodoInventario aux = primero;

            int i = 2;
            while ((i != pos) && (aux->siguiente != nullptr)) {
                i++;
                aux = aux->siguiente;
            }

            pnodoInventario nuevo = new NodoInventario(codPasillo, codProducto, codMarca, codInventario, nombre, cantidadStock, codigoCanasta);
            nuevo->siguiente = aux->siguiente;

            if (aux->siguiente != nullptr)
                aux->siguiente->anterior = nuevo;

            aux->siguiente = nuevo;
            nuevo->anterior = aux;
        }
    }
}

void ListaDobleInventario::borrarAlFinal() {
    if (listaVacia()) {
        cout << "No hay elementos en la lista." << endl;
    }
    else {
        if (primero->siguiente == nullptr) {
            pnodoInventario temp = primero;
            primero = nullptr;
            delete temp;
        }
        else {
            pnodoInventario aux = primero;
            while (aux->siguiente->siguiente != nullptr) {
                aux = aux->siguiente;
            }

            pnodoInventario temp = aux->siguiente;
            aux->siguiente = nullptr;
            delete temp;
        }
    }
}

void ListaDobleInventario::borrarAlInicio() {
    if (listaVacia()) {
        cout << "No hay elementos en la lista." << endl;
    }
    else {
        if (primero->siguiente == nullptr) {
            pnodoInventario temp = primero;
            primero = nullptr;
            delete temp;
        }
        else {
            pnodoInventario temp = primero;
            primero = primero->siguiente;
            primero->anterior = nullptr;
            delete temp;
        }
    }
}

void ListaDobleInventario::borrarEnPosicion(int pos) {
    if (listaVacia()) {
        cout << "La lista está vacía." << endl;
    }
    else {
        if ((pos > largoLista()) || (pos < 0)) {
            cout << "Error en posición." << endl;
        }
        else {
            if (pos == 1) {
                borrarAlInicio();
            }
            else {
                if (pos == largoLista()) {
                    borrarAlFinal();
                }
                else {
                    int cont = 2;
                    pnodoInventario aux = primero;
                    while (cont < pos) {
                        aux = aux->siguiente;
                        cont++;
                    }

                    pnodoInventario temp = aux->siguiente;
                    aux->siguiente = aux->siguiente->siguiente;

                    if (aux->siguiente != nullptr)
                        aux->siguiente->anterior = aux;

                    delete temp;
                }
            }
        }
    }
}

void ListaDobleInventario::mostrar() const {
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

int ListaDobleInventario::largoLista() const {
    int cont = 0;
    pnodoInventario aux = primero;

    while (aux != nullptr) {
        aux = aux->siguiente;
        cont++;
    }

    return cont;
}

class NodoCiudad {
public:
    NodoCiudad(int _codCiudad, const string& _nombre) {
        codCiudad = _codCiudad;
        nombre = _nombre;
        siguiente = nullptr;
    }

private:
    int codCiudad;
    string nombre;
    NodoCiudad* siguiente;

    friend class ListaCircularCiudades;
};

typedef NodoCiudad* pnodoCiudad;

class ListaCircularCiudades {
public:
    ListaCircularCiudades() { primero = nullptr; }
    ~ListaCircularCiudades();

    void insertarAlInicio(int codCiudad, const string& nombre);
    void insertarAlFinal(int codCiudad, const string& nombre);
    void insertarEnPosicion(int codCiudad, const string& nombre, int pos);
    bool listaVacia() const { return primero == nullptr; }
    void borrarAlFinal();
    void borrarAlInicio();
    void borrarEnPosicion(int pos);
    void mostrar() const;
    int largoLista() const;

private:
    pnodoCiudad primero;
};

ListaCircularCiudades::~ListaCircularCiudades() {
    if (primero != nullptr) {
        pnodoCiudad aux = primero->siguiente;
        primero->siguiente = nullptr; // Cortamos el enlace circular
        primero = aux;

        while (aux != nullptr) {
            pnodoCiudad temp = aux;
            aux = aux->siguiente;
            delete temp;
        }
    }
}

void ListaCircularCiudades::insertarAlInicio(int codCiudad, const string& nombre) {
    pnodoCiudad nuevo = new NodoCiudad(codCiudad, nombre);

    if (listaVacia()) {
        primero = nuevo;
        primero->siguiente = primero; // Enlace circular
    }
    else {
        nuevo->siguiente = primero->siguiente;
        primero->siguiente = nuevo;
    }
}

void ListaCircularCiudades::insertarAlFinal(int codCiudad, const string& nombre) {
    pnodoCiudad nuevo = new NodoCiudad(codCiudad, nombre);

    if (listaVacia()) {
        primero = nuevo;
        primero->siguiente = primero; // Enlace circular
    }
    else {
        nuevo->siguiente = primero->siguiente;
        primero->siguiente = nuevo;
        primero = nuevo; // Actualizamos el puntero al último elemento
    }
}

void ListaCircularCiudades::insertarEnPosicion(int codCiudad, const string& nombre, int pos) {
    if (listaVacia() || pos <= 1) {
        insertarAlInicio(codCiudad, nombre);
    }
    else {
        pnodoCiudad aux = primero;
        int i = 2;

        while ((i != pos) && (aux->siguiente != primero)) {
            i++;
            aux = aux->siguiente;
        }

        pnodoCiudad nuevo = new NodoCiudad(codCiudad, nombre);
        nuevo->siguiente = aux->siguiente;
        aux->siguiente = nuevo;

        if (aux == primero) {
            primero = nuevo; // Actualizamos el puntero al último elemento
        }
    }
}

void ListaCircularCiudades::borrarAlFinal() {
    if (listaVacia()) {
        cout << "No hay elementos en la lista." << endl;
    }
    else {
        if (primero->siguiente == primero) {
            delete primero;
            primero = nullptr;
        }
        else {
            pnodoCiudad aux = primero;

            while (aux->siguiente->siguiente != primero) {
                aux = aux->siguiente;
            }

            pnodoCiudad temp = aux->siguiente;
            aux->siguiente = primero;
            delete temp;
        }
    }
}

void ListaCircularCiudades::borrarAlInicio() {
    if (listaVacia()) {
        cout << "No hay elementos en la lista." << endl;
    }
    else {
        if (primero->siguiente == primero) {
            delete primero;
            primero = nullptr;
        }
        else {
            pnodoCiudad aux = primero;

            while (aux->siguiente != primero) {
                aux = aux->siguiente;
            }

            pnodoCiudad temp = primero;
            aux->siguiente = primero->siguiente;
            primero = primero->siguiente;
            delete temp;
        }
    }
}

void ListaCircularCiudades::borrarEnPosicion(int pos) {
    if (listaVacia()) {
        cout << "La lista está vacía." << endl;
    }
    else {
        if (pos == 1) {
            borrarAlInicio();
        }
        else {
            int cont = 2;
            pnodoCiudad aux = primero;

            while (cont < pos) {
                aux = aux->siguiente;
                cont++;
            }

            pnodoCiudad temp = aux->siguiente;
            aux->siguiente = aux->siguiente->siguiente;

            if (temp == primero) {
                primero = aux; // Actualizamos el puntero al último elemento
            }

            delete temp;
        }
    }
}

void ListaCircularCiudades::mostrar() const {
    if (listaVacia()) {
        cout << "La lista está vacía." << endl;
    }
    else {
        pnodoCiudad aux = primero;

        do {
            cout << "CodCiudad: " << aux->codCiudad << " - "
                << "Nombre: " << aux->nombre << " -> ";
            aux = aux->siguiente;
        } while (aux != primero);

        cout << endl;
    }
}

int ListaCircularCiudades::largoLista() const {
    if (listaVacia()) {
        return 0;
    }
    else {
        int cont = 0;
        pnodoCiudad aux = primero;

        do {
            aux = aux->siguiente;
            cont++;
        } while (aux != primero);

        return cont;
    }
}

class NodoMarcaProducto {
public:
    NodoMarcaProducto(int _codPasillo, int _codProducto, int _codMarca, const string& _nombre, int _cantidadGondola, int _precio) {
        codPasillo = _codPasillo;
        codProducto = _codProducto;
        codMarca = _codMarca;
        nombre = _nombre;
        cantidadGondola = _cantidadGondola;
        precio = _precio;
        siguiente = nullptr;
        anterior = nullptr;
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

class ListaCircularDMarcasProductos {
public:
    ListaCircularDMarcasProductos() { primero = nullptr; }
    ~ListaCircularDMarcasProductos();

    void insertarAlInicio(int codPasillo, int codProducto, int codMarca, const string& nombre, int cantidadGondola, int precio);
    void insertarAlFinal(int codPasillo, int codProducto, int codMarca, const string& nombre, int cantidadGondola, int precio);
    void insertarEnPosicion(int codPasillo, int codProducto, int codMarca, const string& nombre, int cantidadGondola, int precio, int pos);
    bool listaVacia() const { return primero == nullptr; }
    void borrarAlFinal();
    void borrarAlInicio();
    void borrarEnPosicion(int pos);
    void mostrar() const;
    int largoLista() const;
    bool marcaRepetida(int codMarca) const;

private:
    pnodoMarcaProducto primero;
};

bool ListaCircularDMarcasProductos::marcaRepetida(int codMarca) const {
    pnodoMarcaProducto aux = primero;

    while (aux != nullptr) {
        if (aux->codMarca == codMarca) {
            return true;
        }
        aux = aux->siguiente;
    }

    return false;
}

ListaCircularDMarcasProductos::~ListaCircularDMarcasProductos() {
    if (primero != nullptr) {
        pnodoMarcaProducto aux = primero->siguiente;
        primero->siguiente = nullptr; // Cortamos el enlace circular
        aux->anterior = nullptr;
        primero = aux;

        while (aux != nullptr) {
            pnodoMarcaProducto temp = aux;
            aux = aux->siguiente;
            delete temp;
        }
    }
}

void ListaCircularDMarcasProductos::insertarAlInicio(int codPasillo, int codProducto, int codMarca, const string& nombre, int cantidadGondola, int precio) {
    pnodoMarcaProducto nuevo = new NodoMarcaProducto(codPasillo, codProducto, codMarca, nombre, cantidadGondola, precio);

    if (listaVacia()) {
        primero = nuevo;
        primero->siguiente = primero; // Enlace circular
        primero->anterior = primero; // Enlace circular
    }
    else {
        nuevo->siguiente = primero;
        nuevo->anterior = primero->anterior;
        primero->anterior->siguiente = nuevo;
        primero->anterior = nuevo;
        primero = nuevo; // Actualizamos el puntero al último elemento
    }
}

void ListaCircularDMarcasProductos::insertarAlFinal(int codPasillo, int codProducto, int codMarca, const string& nombre, int cantidadGondola, int precio) {
    pnodoMarcaProducto nuevo = new NodoMarcaProducto(codPasillo, codProducto, codMarca, nombre, cantidadGondola, precio);

    if (listaVacia()) {
        primero = nuevo;
        primero->siguiente = primero; // Enlace circular
        primero->anterior = primero; // Enlace circular
    }
    else {
        nuevo->siguiente = primero;
        nuevo->anterior = primero->anterior;
        primero->anterior->siguiente = nuevo;
        primero->anterior = nuevo; // Actualizamos el puntero al último elemento
    }
}

void ListaCircularDMarcasProductos::insertarEnPosicion(int codPasillo, int codProducto, int codMarca, const string& nombre, int cantidadGondola, int precio, int pos) {
    if (listaVacia() || pos <= 1) {
        insertarAlInicio(codPasillo, codProducto, codMarca, nombre, cantidadGondola, precio);
    }
    else {
        pnodoMarcaProducto aux = primero;
        int i = 2;

        while ((i != pos) && (aux->siguiente != primero)) {
            i++;
            aux = aux->siguiente;
        }

        pnodoMarcaProducto nuevo = new NodoMarcaProducto(codPasillo, codProducto, codMarca, nombre, cantidadGondola, precio);
        nuevo->siguiente = aux->siguiente;
        nuevo->anterior = aux;
        aux->siguiente->anterior = nuevo;
        aux->siguiente = nuevo;

        if (aux == primero) {
            primero = nuevo; // Actualizamos el puntero al último elemento
        }
    }
}

void ListaCircularDMarcasProductos::borrarAlFinal() {
    if (listaVacia()) {
        cout << "No hay elementos en la lista." << endl;
    }
    else {
        if (primero->siguiente == primero) {
            delete primero;
            primero = nullptr;
        }
        else {
            pnodoMarcaProducto aux = primero->anterior;

            aux->anterior->siguiente = primero;
            primero->anterior = aux->anterior;

            delete aux;
        }
    }
}

void ListaCircularDMarcasProductos::borrarAlInicio() {
    if (listaVacia()) {
        cout << "No hay elementos en la lista." << endl;
    }
    else {
        if (primero->siguiente == primero) {
            delete primero;
            primero = nullptr;
        }
        else {
            pnodoMarcaProducto aux = primero;

            aux->anterior->siguiente = primero->siguiente;
            primero->siguiente->anterior = aux->anterior;

            primero = primero->siguiente;

            delete aux;
        }
    }
}

void ListaCircularDMarcasProductos::borrarEnPosicion(int pos) {
    if (listaVacia()) {
        cout << "La lista está vacía." << endl;
    }
    else {
        if (pos == 1) {
            borrarAlInicio();
        }
        else {
            int cont = 2;
            pnodoMarcaProducto aux = primero->siguiente;

            while (cont < pos && aux != primero) {
                aux = aux->siguiente;
                cont++;
            }

            if (cont == pos) {
                aux->anterior->siguiente = aux->siguiente;
                aux->siguiente->anterior = aux->anterior;

                if (aux == primero) {
                    primero = aux->siguiente; // Actualizamos el puntero al último elemento
                }

                delete aux;
            }
            else {
                cout << "Posición no válida." << endl;
            }
        }
    }
}

void ListaCircularDMarcasProductos::mostrar() const {
    if (listaVacia()) {
        cout << "La lista está vacía." << endl;
    }
    else {
        pnodoMarcaProducto aux = primero;

        do {
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

int ListaCircularDMarcasProductos::largoLista() const {
    if (listaVacia()) {
        return 0;
    }
    else {
        int cont = 0;
        pnodoMarcaProducto aux = primero;

        do {
            cont++;
            aux = aux->siguiente;
        } while (aux != primero);

        return cont;
    }
}

//Inserción
