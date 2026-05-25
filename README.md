MazeSolver (Navegacion de Laberintos)
===

Este programa es una herramienta diseñada para modelar y resolver problemas de planificación de rutas en entornos bidimensionales con obstáculos. Su característica principal es el modelado del problema como un Grafo Implícito y la implementación de tres algoritmos clásicos de Inteligencia Artificial: Búsqueda en Profundidad (DFS), Búsqueda en Anchura (BFS) y Búsqueda Heurística (A*).

---
# Compilación y ejecución

El programa fue desarrollado en lenguaje C de forma modular, organizando el código en carpetas distintas para separar las declaraciones (DeclarationFiles), la lógica ejecutable (ExecutableFiles) y las estructuras de datos (tdas).

## Requisitos previos

1. Tener un compilador de C (como `gcc`).
2. Mantener la estructura de directorios original del proyecto. 

### Compilación

Para compilar el proyecto, se debe de estar en la carpeta raíz y ejecutar el siguiente comando en la terminal:

```bash
gcc ExecutableFiles/main.c ExecutableFiles/maze.c ExecutableFiles/search.c ExecutableFiles/state.c tdas/stack.c tdas/queue.c tdas/priority_queue.c -o laberinto -lm -IDeclarationFiles -Itdas
```

Este comando generará un archivo ejecutable llamado laberinto.

### Ejecución

Una vez compilado, inicia el programa con el siguiente comando:

```bash
./laberinto
```
---
# Funcionalidades implementadas

## Funcionan Correctamente

1. **Generación Dinámica de Entornos:** Crea una cuadrícula de hasta 50x50 (definida por el usuario) e inserta obstáculos basándose en un porcentaje de dificultad. 
2. **Modelado por Grafo Implícito:** El programa descubre los nodos adyacentes conforme los algoritmos exploran el tablero. Las conexiones se calculan en cada paso, filtrando cualquier movimiento hacia un obstáculo o fuera de la cuadrícula.
3. **Búsqueda en Profundidad (DFS):** Permite visualizar el algoritmo avanza en profundidad y encuentra soluciones subóptimas y excesivamente largas en espacios abiertos.
4. **Búsqueda en Anchura (BFS):** xplora el mapa en ondas concéntricas, garantizando siempre encontrar la ruta más corta matemáticamente posible, aunque con un alto número de iteraciones.
5. **Búsqueda A (A):** Utiliza el TDA Priority Queue y la Distancia (Manhattan) como función heurística optimista. Garantiza encontrar la ruta más corta hacia la meta, reduciendo la cantidad de iteraciones en comparación con BFS.


---
# Ejemplo de uso

El siguiente ejemplo con dificultad 0 (mapa vacío) demuestra las características teóricas de cada algoritmo de IA.

### Nota : 
    I = Inicio
    M = Meta
    + = Camino Recorrido
    . = Camino sin recorrer

### Paso 1: Configurar el Laberinto
El usuario inicia el programa y define un tablero de 10x10 sin obstáculos para evaluar el comportamiento puro de los algoritmos.

    Ingrese el tamaño del laberinto (maximo 50): 10
    Ingrese la dificultad (0-100): 0
    Ingrese coordenada X de INICIO (0 a 9): 0
    Ingrese coordenada Y de INICIO (0 a 9): 0
    Ingrese coordenada X de META (0 a 9): 9
    Ingrese coordenada Y de META (0 a 9): 9

    Generando laberinto N=10 con dificultad 0...

### Paso 2: Análisis con Búsqueda en Profundidad (DFS)
DFS no busca el camino más corto, avanza hasta no poder más. Al no haber paredes, rodea el tablero y hace zigzag encontrando un camino muy ineficiente.


    --- Resultados DFS ---
    I + + + + + + + + + 
    + + + + + + + + + + 
    + + + + + + + + + + 
    + + + + + + + + + + 
    + + + + + + + + + + 
    + + + + + + + + + + 
    + + + + + + + + + + 
    + + + + + + + + + + 
    + + + + + + + + + + 
    . . . . . . . . . M 
    Costo del camino: 90
    Iteraciones: 91

### Paso 3: Análisis con Búsqueda en Anchura (BFS)
BFS se expande paso a paso en todas direcciones. Encuentra el camino óptimo (18 pasos), pero para lograrlo procesa una gran cantidad de estados.

    --- Resultados BFS ---
    I . . . . . . . . . 
    + . . . . . . . . . 
    + . . . . . . . . . 
    + . . . . . . . . . 
    + . . . . . . . . . 
    + . . . . . . . . . 
    + . . . . . . . . . 
    + . . . . . . . . . 
    + . . . . . . . . . 
    + + + + + + + + + M 
    Costo del camino: 18
    Iteraciones: 180

### Paso 4: Análisis con Búsqueda Heurística (A*)
A* guiado por la heurística de Manhattan, sabe exactamente dónde está la meta y camina directamente hacia ella, logrando la ruta óptima de 18 pasos evaluando la cantidad mínima posible de estados.

    --- Resultados A* ---
    I + + + + + + + + + 
    . . . . . . . . . + 
    . . . . . . . . . + 
    . . . . . . . . . + 
    . . . . . . . . . + 
    . . . . . . . . . + 
    . . . . . . . . . + 
    . . . . . . . . . + 
    . . . . . . . . . + 
    . . . . . . . . . M 
    Costo del camino: 18
    Iteraciones: 19

---

# Áreas de Mejora:

1. **Limite del mapa:** El programa utiliza memoria estática para la matriz del laberinto (int maze[MAX_N][MAX_N]), con un máximo fijado en 50x50. Si el usuario ingresa un número mayor a 50, el sistema no colapsa, sino que restringe el valor a 50 para evitar errores. Para soportar laberintos masivos, se requeriría implementar asignación dinámica de memoria.
2. **Validación de tipos de entrada:** scanf asume que el usuario ingresará números enteros. Si el usuario ingresa caracteres o texto, el flujo de entrada puede corromperse y causar un bucle infinito en la consola.
3. **Ejecución de un solo uso:** Actualmente, el programa se ejecuta linealmente y se cierra tras mostrar los resultados de los tres algoritmos. No cuenta con un menú en bucle que permita generar otro laberinto sin tener que volver a ejecutar el comando ./laberinto desde cero.
