#include <iostream>
#include <string>
#include <queue>

using namespace std;

// Cada nodo guarda el nombre de un módulo del sistema SmartCampus
class Nodo {
public:
    string modulo;
    Nodo *izq, *der;

    // Constructor: cuando creamos un nodo solo le damos el nombre del módulo
    Nodo(string m) : modulo(m), izq(nullptr), der(nullptr) {}
};

// Esta clase solo sirve para mostrar cómo queda el árbol visualmente
class DibujanteArbol {
public:
    // Imprime el árbol en consola con forma de árbol de verdad
    void imprimirEstructura() {
        cout << "\n-- ESTRUCTURA DEL SISTEMA SmartCampus UTA --" << endl;
        cout << "            [SmartCampus Web]              " << endl; // raíz principal
        cout << "                 /      \\                 " << endl;
        cout << "       [Usuarios]        [Academico]       " << endl; // primer nivel de ramas
        cout << "        /     \\           /      \\        " << endl;
        cout << "  [Auth]   [Roles]   [Materias] [Sesiones] " << endl; // segundo nivel
        cout << "                                   /       " << endl;
        cout << "                              [Asistencia] " << endl; // hoja más profunda
        cout << "-------------------------------------------" << endl;
    }
};

// Aquí está toda la lógica del árbol y sus recorridos
class GestionSistema {
public:
    Nodo* raiz;

    // Armamos el árbol con los módulos del SmartCampus
    // Los 5 nodos nuevos son: Auth JWT, Roles, Materias, Sesiones y Asistencia
    GestionSistema() {
        raiz = new Nodo("SmartCampus Web");           // raíz del sistema

        // Rama izquierda: todo lo de usuarios
        raiz->izq = new Nodo("Gestion Usuarios");
        raiz->izq->izq = new Nodo("Auth JWT");          // nodo nuevo 1: autenticación
        raiz->izq->der = new Nodo("Roles Docente/Est"); // nodo nuevo 2: roles del sistema

        // Rama derecha: todo lo académico
        raiz->der = new Nodo("Gestion Academica");
        raiz->der->izq = new Nodo("Materias (Vector)");      // nodo nuevo 3: lista de materias
        raiz->der->der = new Nodo("Sesiones (L.Circular)");  // nodo nuevo 4: sesiones activas
        raiz->der->der->izq = new Nodo("Asistencia (Cola)"); // nodo nuevo 5: registro de asistencia
    }

    // Preorden: primero visita la raíz, luego va a la izquierda y después a la derecha
    void recorridoPreorden(Nodo* r) {
        if (r == nullptr) return; // si no hay nodo, no hace nada
        cout << "[" << r->modulo << "] ";
        recorridoPreorden(r->izq); // baja por la izquierda
        recorridoPreorden(r->der); // luego por la derecha
    }

    // Inorden: primero izquierda, luego raíz, luego derecha
    void recorridoInorden(Nodo* r) {
        if (r == nullptr) return;
        recorridoInorden(r->izq);
        cout << "[" << r->modulo << "] ";
        recorridoInorden(r->der);
    }

    // Postorden: primero los hijos y al final la raíz
    void recorridoPostorden(Nodo* r) {
        if (r == nullptr) return;
        recorridoPostorden(r->izq);
        recorridoPostorden(r->der);
        cout << "[" << r->modulo << "] "; // la raíz sale de última
    }

    // BFS: recorre nivel por nivel usando una cola (queue)
    void recorridoBFS() {
        if (raiz == nullptr) return;

        queue<Nodo*> cola; // usamos una cola para ir guardando los nodos pendientes
        cola.push(raiz);   // empezamos desde la raíz

        while (!cola.empty()) {
            Nodo* actual = cola.front(); // tomamos el primero de la cola
            cola.pop();

            cout << "[" << actual->modulo << "] ";

            // Si tiene hijos, los agregamos a la cola para visitarlos después
            if (actual->izq) cola.push(actual->izq);
            if (actual->der) cola.push(actual->der);
        }
    }
};

int main() {
    GestionSistema smart;
    DibujanteArbol dibujo;

    // Primero mostramos cómo se ve el árbol visualmente
    dibujo.imprimirEstructura();

    // Ahora ejecutamos cada tipo de recorrido
    cout << "\nRecorrido Preorden del arbol:";
    cout << "\n(Orden: Raiz -> Izquierda -> Derecha)\n";
    smart.recorridoPreorden(smart.raiz);

    cout << "\n\nRecorrido Inorden del arbol:";
    cout << "\n(Orden: Izquierda -> Raiz -> Derecha)\n";
    smart.recorridoInorden(smart.raiz);

    cout << "\n\nRecorrido Postorden del arbol:";
    cout << "\n(Orden: Izquierda -> Derecha -> Raiz)\n";
    smart.recorridoPostorden(smart.raiz);

    cout << "\n\nRecorrido BFS - por niveles:";
    cout << "\n(Usa una Cola FIFO para ir nivel por nivel)\n";
    smart.recorridoBFS();

    cout << "\n\n";
    return 0;
}