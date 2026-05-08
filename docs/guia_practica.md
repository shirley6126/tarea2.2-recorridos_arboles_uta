# Guía Práctica: Recorridos de Árboles Binarios

# Guía Práctica: Recorridos de Árboles Binarios

## Datos Generales

| Campo | Información |
|---|---|
| **Asignatura** | Estructura de Datos |
| **Curso** | Tercero "B" |
| **Tema** | Recorridos Inorden, Preorden, Postorden y BFS |
| **Lenguajes** | C++ y Java |
| **Modalidad** | Trabajo grupal con GitHub |
| **Integrantes** | Amaguaña Shirley, Coello Leslie, Fernando Llerena |
| **Fecha** | Mayo 2026 |

## Introducción

Un recorrido de árbol es un proceso para visitar todos los nodos de una estructura
jerárquica en un orden específico. En árboles binarios se usan principalmente los
recorridos en profundidad (DFS): Inorden, Preorden y Postorden. Además, el recorrido
BFS permite visitar los nodos nivel por nivel usando una cola.

Cada recorrido tiene un propósito diferente y entender cuándo usar cada uno es clave
para aplicarlos en problemas reales de software.

---

## Caso Aplicado

La guía propone usar un árbol para organizar módulos de un sistema web. Para esta
práctica adaptamos ese ejemplo al proyecto final **SmartCampus UTA**, que es el
sistema que estamos desarrollando este semestre.

### Caso original de la guía

```
              [Sistema Principal]
                   /         \
       [Gestión Usuarios]  [Gestión Inventario]
           /       \             /        \
      [Registrar] [Buscar] [Actualizar] [Eliminar]
```

### Caso adaptado: SmartCampus UTA (nuestro proyecto)

```
                 [SmartCampus Web]               <- Nivel 0 (Raíz)
                      /      \
         [Gestion Usuarios]  [Gestion Academica] <- Nivel 1
              /      \            /      \
        [Auth JWT] [Roles]  [Materias] [Sesiones] <- Nivel 2 (Nodos nuevos 1-4)
                                          /
                                    [Asistencia]  <- Nivel 3 (Nodo nuevo 5)
```

| Nodo | Descripción |
|---|---|
| SmartCampus Web | Raíz del sistema, punto de entrada principal |
| Gestion Usuarios | Módulo que administra docentes y estudiantes |
| Auth JWT | *(Nodo nuevo 1)* Autenticación con tokens JWT |
| Roles Docente/Est | *(Nodo nuevo 2)* Permisos según tipo de usuario |
| Gestion Academica | Módulo de clases, materias y asistencia |
| Materias (Vector) | *(Nodo nuevo 3)* Lista de materias con Vector |
| Sesiones (L.Circular) | *(Nodo nuevo 4)* Sesiones activas con Lista Circular |
| Asistencia (Cola) | *(Nodo nuevo 5)* Registro de asistencia con Cola FIFO |

---

## Reglas de Recorrido

| Recorrido | Orden | Estructura usada |
|---|---|---|
| Preorden  | Raíz → Izquierda → Derecha | Recursividad (DFS) |
| Inorden   | Izquierda → Raíz → Derecha | Recursividad (DFS) |
| Postorden | Izquierda → Derecha → Raíz | Recursividad (DFS) |
| BFS       | Nivel por nivel            | Cola (Queue FIFO)  |

---

## Pasos de Trabajo — Desarrollo

### 1. Crear el repositorio en GitHub

Se creó el repositorio del grupo en GitHub con la siguiente estructura:

```
recorridos-arboles/
├── src/
│   ├── cpp/
│   │   └── main.cpp
│   └── java/
│       └── Main.java
├── docs/
│   └── guia_practica.md  
│   ├── captura_cpp.png
│   └── captura_java.png
└── README.md
```
---

### 2. Copiar la estructura del proyecto base

Se copió la estructura de carpetas indicada en la guía y se verificó que los archivos
`main.cpp` y `Main.java` estuvieran en sus carpetas correctas antes de empezar a
modificar el código.

---

### 3. Ejecutar el programa en C++ y en Java

**Salida obtenida:**
Al ejecutar el programa (tanto en C++ como en Java) se obtiene la siguiente salida:
```
=== ESTRUCTURA DEL SISTEMA SmartCampus UTA ===
            [SmartCampus Web]              
                 /      \                 
       [Usuarios]        [Academico]       
        /     \           /      \        
  [Auth]   [Roles]   [Materias] [Sesiones] 
                                   /       
                              [Asistencia] 
===============================================

Recorrido Preorden del arbol:
(Orden: Raiz -> Izquierda -> Derecha)
[SmartCampus Web] [Gestion Usuarios] [Auth JWT] [Roles Docente/Est] [Gestion Academica] [Materias (Vector)] [Sesiones (L.Circular)] [Asistencia (Cola)]

Recorrido Inorden del arbol:
(Orden: Izquierda -> Raiz -> Derecha)
[Auth JWT] [Gestion Usuarios] [Roles Docente/Est] [SmartCampus Web] [Materias (Vector)] [Gestion Academica] [Asistencia (Cola)] [Sesiones (L.Circular)]

Recorrido Postorden del arbol:
(Orden: Izquierda -> Derecha -> Raiz)
[Auth JWT] [Roles Docente/Est] [Gestion Usuarios] [Materias (Vector)] [Asistencia (Cola)] [Sesiones (L.Circular)] [Gestion Academica] [SmartCampus Web]

Recorrido BFS - por niveles:
(Usa una Cola FIFO para ir nivel por nivel)
[SmartCampus Web] [Gestion Usuarios] [Gestion Academica] [Auth JWT] [Roles Docente/Est] [Materias (Vector)] [Sesiones (L.Circular)] [Asistencia (Cola)]
```

### 5. Comparar las salidas

Después de ejecutar ambos programas verificamos que:

- Los cuatro recorridos (Preorden, Inorden, Postorden, BFS) coinciden exactamente
  en C++ y Java.
- El orden de los nodos en cada recorrido es correcto según las reglas de cada uno.
- La única diferencia entre los dos programas es la sintaxis: `cout` en C++ vs
  `System.out.print` en Java, y `queue<Nodo*>` vs `Queue<Nodo>` con `LinkedList`.

> La lógica de los algoritmos es completamente igual en ambos lenguajes. Esto
> confirma que los recorridos de árboles son independientes del lenguaje de
> programación.

---

### 6. Insertar 5 nodos nuevos relacionados con el proyecto final

Se reemplazó el árbol de enteros del código base por el árbol de módulos SmartCampus.
Los 5 nodos nuevos agregados son:

```cpp
// C++ — dentro del constructor de GestionSistema
raiz->izq->izq = new Nodo("Auth JWT");          // nodo nuevo 1: autenticación
raiz->izq->der = new Nodo("Roles Docente/Est"); // nodo nuevo 2: roles del sistema
raiz->der->izq = new Nodo("Materias (Vector)"); // nodo nuevo 3: lista de materias
raiz->der->der = new Nodo("Sesiones (L.Circular)"); // nodo nuevo 4: sesiones activas
raiz->der->der->izq = new Nodo("Asistencia (Cola)"); // nodo nuevo 5: registro asistencia
```

```java
// Java — dentro del constructor de GestionSistema
raiz.izq.izq = new Nodo("Auth JWT");           // nodo nuevo 1
raiz.izq.der = new Nodo("Roles Docente/Est");  // nodo nuevo 2
raiz.der.izq = new Nodo("Materias (Vector)");  // nodo nuevo 3
raiz.der.der = new Nodo("Sesiones (L.Circular)");  // nodo nuevo 4
raiz.der.der.izq = new Nodo("Asistencia (Cola)");  // nodo nuevo 5
```

---

### 7. Documentar la solución en README.md

Se redactó el `README.md` del grupo con:
- Objetivos y resultados de aprendizaje
- Instrucciones de ejecución para C++ y Java
- Ejemplo de salida en consola
- Explicación del caso real SmartCampus
- Declaración del uso de IA

El README está disponible en la raíz del repositorio.

---

### 8. Capturas de ejecución

Se tomaron capturas de pantalla de la consola mostrando los cuatro recorridos
completos en C++ y Java, y se subieron a la carpeta `assets/`:

## Preguntas de Reflexión 

### 1. ¿Qué recorrido sirve para ordenar valores en un BST?

El **recorrido Inorden** (Izquierda → Raíz → Derecha) es el que permite obtener
los valores en orden ascendente en un Árbol Binario de Búsqueda (BST).

Esto funciona porque en un BST la regla es que el hijo izquierdo siempre tiene un
valor menor que la raíz, y el hijo derecho siempre tiene un valor mayor. Entonces,
si seguimos el orden Izquierda → Raíz → Derecha, automáticamente visitamos los
nodos del más pequeño al más grande.
---

### 2. ¿Qué diferencia existe entre DFS y BFS?

La diferencia principal está en la **dirección del recorrido** y en la
**estructura de datos** que cada uno necesita:

| | DFS (Profundidad) | BFS (Anchura) |
|---|---|---|
| Dirección | Baja profundo por una rama primero | Visita nivel por nivel |
| Estructura | Recursividad (pila implícita) | Cola (Queue FIFO) |
| Variantes | Preorden, Inorden, Postorden | Solo BFS |
| Bueno para | Buscar nodos específicos | Ver la jerarquía por niveles |

Al implementar el código notamos que las tres funciones DFS son muy parecidas entre
sí (solo cambia el lugar de una línea), pero BFS tiene una estructura completamente
diferente con el ciclo `while` y la cola.

---

### 3. ¿Por qué BFS requiere una cola?

BFS necesita una cola porque tiene que procesar los nodos **en el mismo orden en
que los va descubriendo**. Cuando visitamos un nodo encontramos sus dos hijos, pero
no podemos visitarlos de inmediato porque primero tenemos que terminar con todos los
nodos del nivel actual. Los metemos a la cola y los dejamos esperando su turno.

La cola es **FIFO** (First In, First Out): el primer nodo que metemos es el primero
en salir. Esto garantiza que procesemos los nodos nivel por nivel y no saltemos de
rama en rama.

Si usáramos una pila (LIFO) en vez de una cola, el comportamiento cambiaría
automáticamente a DFS, que es exactamente lo contrario de lo que queremos.

```
Cola en BFS paso a paso (SmartCampus):

Inicio:      [SmartCampus Web]
Saco raíz, meto sus hijos:  [Gestion Usuarios, Gestion Academica]
Saco Usuarios, meto sus hijos: [Gestion Academica, Auth JWT, Roles]
Saco Academica, meto sus hijos: [Auth JWT, Roles, Materias, Sesiones]
... y así hasta vaciar la cola
```

---

### 4. ¿En qué caso real se puede usar Preorden?

**Preorden** visita la raíz antes que los hijos, lo que lo hace útil cuando
necesitamos procesar el elemento padre antes de trabajar con sus dependencias.

**En nuestro proyecto SmartCampus:** Preorden sería útil para **inicializar los
módulos del sistema al arrancar la aplicación**. Primero se carga `SmartCampus Web`
(la raíz), luego `Gestión de Usuarios` y `Gestión Académica`, y finalmente los
submódulos como `Auth JWT`, `Materias`, etc. Tiene sentido porque no puedes
inicializar `Auth JWT` si el módulo de Usuarios todavía no existe.

---

### 5. ¿En qué caso real se puede usar Postorden?

**Postorden** visita los hijos antes que la raíz, lo que lo hace ideal cuando hay
que procesar las dependencias internas antes de trabajar con el elemento que las
contiene.

**En nuestro proyecto SmartCampus:** Postorden sería útil para **apagar o desconectar
módulos del sistema de forma segura**. Primero se cierra `Asistencia (Cola)`, luego
`Sesiones (L.Circular)`, luego `Materias`, y finalmente `Gestión Académica`. Si
intentáramos cerrar `Gestión Académica` primero, dejaríamos sus submódulos sin módulo
padre, generando referencias sueltas en memoria.
---

## Uso de IA

Se utilizó **Claude (Anthropic)** como herramienta de apoyo para:
- Revisión de comentarios del código
- Estructura de la documentación

El código fue escrito, entendido y ejecutado por el grupo. Toda la
documentación fue revisada y adaptada por los integrantes antes de subir al
repositorio.

---