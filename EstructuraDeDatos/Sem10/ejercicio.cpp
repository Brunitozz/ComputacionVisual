#include <iostream>
#include <windows.h>
void RedirectIOToConsole() {
    AllocConsole();  // Asigna una nueva consola al proceso actual
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);  // Redirige stdout a la nueva consola
    freopen_s(&fp, "CONOUT$", "w", stderr);  // Redirige stderr a la nueva consola
    freopen_s(&fp, "CONIN$", "r", stdin);    // Redirige stdin a la nueva consola
}

struct Nodo
{
    int valor;
    struct Nodo* derecha;
    struct Nodo* izquierda;
};

typedef Nodo* TpTree;

void
crearNodoArbol(TpTree& raiz)
{
    int valorNuevo;
    TpTree nuevo = new struct Nodo;
    std::cout << "Ingrese un valor -> "; std::cin >> valorNuevo;
    nuevo->valor = valorNuevo;
    nuevo->derecha = NULL;
    nuevo->izquierda = NULL;
    raiz = nuevo;
}

void recorridoPreorden(TpTree arbol) {
    if (arbol != NULL) {
        std::cout << arbol->valor << " ";
        recorridoPreorden(arbol->izquierda);
        recorridoPreorden(arbol->derecha);
    }
}

void recorridoInorden(TpTree arbol) {
    if (arbol != NULL) {
        recorridoInorden(arbol->izquierda);
        std::cout << arbol->valor << " ";
        recorridoInorden(arbol->derecha);
    }
}

void recorridoPostorden(TpTree arbol) {
    if (arbol != NULL) {
        recorridoPostorden(arbol->izquierda);
        recorridoPostorden(arbol->derecha);
        std::cout << arbol->valor << " ";
    }
}

void mostrarArbol(TpTree arbol) {
    std::cout << "Recorrido Preorden: ";
    recorridoPreorden(arbol);
    std::cout << std::endl;

    std::cout << "Recorrido Inorden: ";
    recorridoInorden(arbol);
    std::cout << std::endl;

    std::cout << "Recorrido Postorden: ";
    recorridoPostorden(arbol);
    std::cout << std::endl;
}



void insertarNodo(TpTree& raiz) {
    int valorNuevo;

    TpTree nuevo = NULL;
    crearNodoArbol(nuevo);

    valorNuevo = nuevo->valor;
    if (raiz == NULL) {
        raiz = nuevo;
    }
    else {
        TpTree actual = raiz;
        while (true) {
            if (valorNuevo > actual->valor) {
                if (actual->derecha == NULL) {
                    actual->derecha = nuevo;
                    break;
                }
                else {
                    actual = actual->derecha;
                }
            }
            else {
                if (actual->izquierda == NULL) {
                    actual->izquierda = nuevo;
                    break;
                }
                else {
                    actual = actual->izquierda;
                }
            }
        }
    }
}

void menu() {
    system("cls");
    std::cout << "\tArbol Binario" << std::endl;
    std::cout << "1) Crear Raiz " << std::endl;
    std::cout << "2) Insertar un nuevo nodo al arbol " << std::endl;
    std::cout << "3) Mostrar los recorrido PreOrden, InOrden y PostOrden " << std::endl;
    std::cout << "0) Salir " << std::endl;
    std::cout << "Ingresar una opcion -> " << std::endl;
}

int main(int argc, char** argv) {
    RedirectIOToConsole();
    TpTree raiz = NULL;
    int opc;
    do {
        menu();
        std::cin >> opc;
        switch (opc) {
        case 1:
            crearNodoArbol(raiz);
            system("PAUSE");
            break;
        case 2:
            insertarNodo(raiz);
            system("PAUSE");
            break;
        case 3:
            mostrarArbol(raiz);
            system("PAUSE");
            break;
        default:
            std::cout << "Opción incorrecta" << std::endl;
            system("PAUSE");
            break;
        }
    } while (opc != 0);
    system("pause");
    return 0;
}