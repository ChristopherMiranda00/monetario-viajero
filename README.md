# Tarea *3*. *Técnicas de diseño de algoritmos*

---

##### Integrantes:
1. *Christopher Luis Miranda Vanegas* - *A01022676* - *Campus Santa Fe*


---
## 1. Aspectos generales

Las orientaciones de la tarea se encuentran disponibles en la plataforma **Canvas**.

Este documento es una guía sobre qué información debe entregar como parte de la tarea, qué requerimientos técnicos debe cumplir y la estructura que debe seguir para organizar su entrega.


### 1.1 Requerimientos técnicos

A continuación se mencionan los requerimientos técnicos mínimos de la tarea, favor de tenerlos presente para que cumpla con todos.

* El código debe desarrollarse en C++, cumpliendo con el último estándar [C++17](https://isocpp.org/std/the-standard).
* Toda la programación debe realizarse utilizando Programación Genérica.
* Deben utilizarse las [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md).
* Todo el código debe estar correctamente documentado, siguiendo los lineamientos que aparecen en [Documenting C++ Code](https://developer.lsst.io/cpp/api-docs.html).
* Todo el código de la tarea debe alojarse en este repositorio de GitHub.
* Debe configurar su repositorio para que utilice el sistema de Integración Continua [Travis CI](https://travis-ci.org/).

### 1.2 Estructura del repositorio

El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz del repositorio
    - README.md			# Archivo con la información general de la actividad (este archivo)
    - sources  			# Códigos fuente con la solución
    - examples			# Archivos de ejemplo que pueden utilizarse para verificar que la solución funciona.
```

## 2. Solución
##### Problema del Sistema Monetario
El código del sistema monetario, monetario.cpp, tiene definido un arreglo del valor de las monedas, el cual en el método de 'darCambio' dependiendo de la cantidad ingresada comparará y agregará la solución a un vector. El resultado es la cantidad ingresada a evaluar, y abajo el cambio con e número de monedas utilizadas con el valor de moneda. 
##### Problema del Viajante


### 2.1 Pasos a seguir para utilizar la aplicación

##### Problema Sistema Monetario
1. Mediante la terminal, navegar a la carpeta [sources](../sources)
2. Correr el comando: `g++ -o monetario.cpp -std=c++17`
3. Correr el comando: `./monetario`
##### Problema del Viajero
1. Mediante la terminal, navegar a la carpeta [sources](../sources)
2. Correr el comando: `g++ -o viajero.cpp -std=c++17`
3. Correr el comando: `./viajero`

## 3. Referencias
> http://www.lcc.uma.es/~av/Libro/CAP4.pdf
> https://ocw.ehu.eus/pluginfile.php/9410/mod_resource/content/1/03_Algoritmos_Voraces/03_Algoritmos_Voraces.pdf

