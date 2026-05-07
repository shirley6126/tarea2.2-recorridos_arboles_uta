import java.util.LinkedList;
import java.util.Queue;

// Cada nodo representa un módulo del sistema SmartCampus
class Nodo {
    String modulo;
    Nodo izq, der;

    // Al crear el nodo solo necesitamos el nombre del módulo
    public Nodo(String modulo) {
        this.modulo = modulo;
        this.izq = null;
        this.der = null;
    }
}

// Esta clase dibuja el árbol en consola para verlo más claro
class DibujanteArbol {
    public void imprimirEstructura() {
        System.out.println("\n-- ESTRUCTURA DEL SISTEMA SmartCampus UTA --");
        System.out.println("            [SmartCampus Web]              "); // raíz
        System.out.println("                 /      \\                 ");
        System.out.println("       [Usuarios]        [Academico]       "); // nivel 1
        System.out.println("        /     \\           /      \\        ");
        System.out.println("  [Auth]   [Roles]   [Materias] [Sesiones] "); // nivel 2
        System.out.println("                                   /       ");
        System.out.println("                              [Asistencia] "); // hoja más profunda
        System.out.println("--------------------------------------------");
    }
}

// Aquí está el árbol y todos sus recorridos
class GestionSistema {
    Nodo raiz;

    // Construimos el árbol con los módulos del proyecto SmartCampus
    public GestionSistema() {
        raiz = new Nodo("SmartCampus Web"); // raíz del sistema

        // Parte izquierda: gestión de usuarios
        raiz.izq = new Nodo("Gestion Usuarios");
        raiz.izq.izq = new Nodo("Auth JWT");          // nodo nuevo 1
        raiz.izq.der = new Nodo("Roles Docente/Est"); // nodo nuevo 2

        // Parte derecha: gestión académica
        raiz.der = new Nodo("Gestion Academica");
        raiz.der.izq = new Nodo("Materias (Vector)");      // nodo nuevo 3
        raiz.der.der = new Nodo("Sesiones (L.Circular)");  // nodo nuevo 4
        raiz.der.der.izq = new Nodo("Asistencia (Cola)");  // nodo nuevo 5
    }

    // Preorden: raíz primero, luego izquierda, luego derecha
    public void recorridoPreorden(Nodo r) {
        if (r == null) return; // si el nodo no existe, salimos
        System.out.print("[" + r.modulo + "] ");
        recorridoPreorden(r.izq); // bajamos por la izquierda
        recorridoPreorden(r.der); // luego por la derecha
    }

    // Inorden: izquierda, luego raíz, luego derecha
    public void recorridoInorden(Nodo r) {
        if (r == null) return;
        recorridoInorden(r.izq);
        System.out.print("[" + r.modulo + "] ");
        recorridoInorden(r.der);
    }

    // Postorden: primero los hijos, la raíz sale al final
    public void recorridoPostorden(Nodo r) {
        if (r == null) return;
        recorridoPostorden(r.izq);
        recorridoPostorden(r.der);
        System.out.print("[" + r.modulo + "] "); // raíz al último
    }

    // BFS: recorre nivel por nivel con ayuda de una cola
    public void recorridoBFS() {
        if (raiz == null) return;

        // LinkedList funciona bien como cola en Java
        Queue<Nodo> cola = new LinkedList<>();
        cola.add(raiz); // empezamos desde la raíz

        while (!cola.isEmpty()) {
            Nodo actual = cola.poll(); // sacamos el primero de la cola
            System.out.print("[" + actual.modulo + "] ");

            // Si tiene hijos los metemos a la cola para visitarlos después
            if (actual.izq != null) cola.add(actual.izq);
            if (actual.der != null) cola.add(actual.der);
        }
    }
}

// Clase principal donde corre el programa
public class Main {
    public static void main(String[] args) {
        GestionSistema smart = new GestionSistema();
        DibujanteArbol dibujo = new DibujanteArbol();

        // Primero mostramos la estructura visual del árbol
        dibujo.imprimirEstructura();

        // Ejecutamos cada recorrido con su explicación
        System.out.print("\nRecorrido Preorden del arbol:");
        System.out.print("\n(Orden: Raiz -> Izquierda -> Derecha)\n");
        smart.recorridoPreorden(smart.raiz);

        System.out.print("\n\nRecorrido Inorden del arbol:");
        System.out.print("\n(Orden: Izquierda -> Raiz -> Derecha)\n");
        smart.recorridoInorden(smart.raiz);

        System.out.print("\n\nRecorrido Postorden del arbol:");
        System.out.print("\n(Orden: Izquierda -> Derecha -> Raiz)\n");
        smart.recorridoPostorden(smart.raiz);

        System.out.print("\n\nRecorrido BFS - por niveles:");
        System.out.print("\n(Usa una Cola FIFO para ir nivel por nivel)\n");
        smart.recorridoBFS();

        System.out.println("\n");
    }
}