# Recorridos de Árboles Binarios - Estructura de Datos

**Universidad Técnica de Ambato**  
**Carrera:** Ingeniería de Software  
**Asignatura:** Estructura de Datos  
**Curso:** Tercero B  
**Tema:** Recorridos de árboles binarios: Inorden, Preorden, Postorden y BFS

## Objetivo general
Implementar y analizar los principales recorridos de árboles binarios utilizando C++ y Java, aplicando estructuras de datos dinámicas, recursividad y colas.

## Resultados de aprendizaje
Al finalizar la práctica, el estudiante será capaz de:

1. Explicar la diferencia entre recorridos DFS y BFS.
2. Implementar recorridos Inorden, Preorden y Postorden con recursividad.
3. Implementar BFS usando una cola.
4. Comparar la implementación en C++ y Java.
5. Aplicar recorridos de árboles a un caso real del proyecto final.

## ¿Qué son los recorridos de árboles?

Un árbol binario es una estructura de datos donde cada nodo puede tener hasta dos hijos
(izquierda y derecha). Hay cuatro formas principales de recorrer todos sus nodos:

### Preorden (DFS)
Visita primero la raíz, luego baja por la izquierda y después por la derecha.
```
Orden: Raíz → Izquierda → Derecha
```

### Inorden (DFS)
Baja primero por la izquierda, visita la raíz y sigue por la derecha.
```
Orden: Izquierda → Raíz → Derecha
```

### Postorden (DFS)
Visita primero todos los hijos y al final llega a la raíz.
```
Orden: Izquierda → Derecha → Raíz
```

### BFS - Por niveles
Visita todos los nodos nivel por nivel, usando una cola (Queue FIFO).
```
Nivel 0: Raíz
Nivel 1: Hijos de la raíz
Nivel 2: Nietos de la raíz
...
```
---
### Diferencia entre DFS y BFS

| | DFS | BFS |
|---|---|---|
| Cómo recorre | Baja profundo por una rama primero | Va nivel por nivel |
| Qué usa | Recursividad | Cola (Queue FIFO) |
| Variantes | Preorden, Inorden, Postorden | BFS por niveles |

---
## Contenido

| Carpeta | Descripción |
|---|---|
| `docs/` | Guía práctica para la clase |
| `src/cpp/` | Implementación completa en C++ |
| `src/java/` | Implementación completa en Java |
| `exercises/` | Ejercicios para trabajo grupal |
| `moodle/` | Banco de preguntas tipo Moodle |
| `assets/` |captura_cpp.png |
│           |captura_java.png |

## Reglas de recorrido

| Recorrido | Orden |
|---|---|
| Inorden | Izquierda → Raíz → Derecha |
| Preorden | Raíz → Izquierda → Derecha |
| Postorden | Izquierda → Derecha → Raíz |
| BFS | Nivel por nivel usando cola |

## Ejecución en C++

```bash
cd src/cpp
g++ main.cpp -o recorridos
./recorridos
```

## Ejecución en Java

```bash
cd src/java
javac Main.java
java Main
```

---

## Ejemplo de salida en consola

```
--- ESTRUCTURA DEL SISTEMA SmartCampus UTA ---
            [SmartCampus Web]              
                 /      \                 
       [Usuarios]        [Academico]       
        /     \           /      \        
  [Auth]   [Roles]   [Materias] [Sesiones] 
                                   /       
                              [Asistencia] 
----------------------------------------------

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

---

## Caso Real: SmartCampus UTA

El árbol del código representa la arquitectura del proyecto SmartCampus, que es el
sistema que estamos desarrollando este semestre. Cada nodo es un módulo real del sistema:

| Nodo | Descripción |
|---|---|
| SmartCampus Web | Raíz del sistema, punto de entrada principal |
| Gestion Usuarios | Módulo de todo lo relacionado con usuarios |
| Auth JWT | Submódulo de autenticación con tokens |
| Roles Docente/Est | Define los permisos según el tipo de usuario |
| Gestion Academica | Módulo de clases, materias y asistencia |
| Materias (Vector) | Lista de materias usando Vector como estructura |
| Sesiones (L.Circular) | Sesiones activas con Lista Circular |
| Asistencia (Cola) | Registro de asistencia usando Cola FIFO |

Usamos un árbol porque el sistema SmartCampus tiene una jerarquía natural: el sistema
tiene áreas, las áreas tienen módulos, y los módulos tienen submódulos. El árbol
refleja exactamente esa relación.

---
## Capturas de ejecución:
**Ejecución en C++**

<img width="1382" height="570" alt="captura_cpp" src="https://github.com/user-attachments/assets/8157c012-a475-4d4c-b100-9ca105c05d84" />

**Ejecución en Java**

<img width="1398" height="632" alt="captura_java" src="https://github.com/user-attachments/assets/8f6a4cb1-d9fc-455b-b61a-0753c622fe42" />

## Uso de GitHub e IA
**Uso de GitHub**

Todo el trabajo de la práctica fue versionado y subido al repositorio del grupo en GitHub. 

**Uso de Inteligencia Artificial**

Se utilizó la herramienta de IA Claude (Anthropic) como apoyo durante el desarrollo de la práctica.

Se uso en:

**Revisión de comentarios del código**

- La IA sugirió comentarios más claros y naturales. El grupo los revisó y adaptó al contexto del proyecto SmartCampus.

**Estructura del informe**

- Se consultó a la IA sobre cómo organizar las secciones. El grupo decidió qué incluir según los requisitos del README del docente.

**Redacción del README**

- La IA apoyó en el formato y redacción. El contenido (nodos, caso real, salida de consola) fue definido por el grupo.

## Actividad  sugerida:

1. Clonar el repositorio.
2. Ejecutar el código base.
3. Agregar mínimo 5 nodos nuevos.
4. Mostrar los cuatro recorridos.
5. Modificar el caso de aplicación al proyecto final.
6. Subir evidencias al repositorio GitHub del grupo.

## Entregables

- Captura de ejecución en consola.
- Código fuente comentado.
- README del grupo.
- Explicación del caso real.
- Link del repositorio GitHub.

## Rúbrica breve sobre 10 puntos

| Criterio | Puntaje |
|---|---:|
| Implementación correcta de recorridos | 3 |
| Uso correcto de recursividad y cola | 2 |
| Código comentado y organizado | 1.5 |
| Aplicación al proyecto final | 2 |
| Uso de GitHub e IA documentada | 1.5 |

