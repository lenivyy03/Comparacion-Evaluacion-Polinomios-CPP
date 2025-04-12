# Comparacion-Evaluacion-Polinomios-CPP

Comparación de evaluación de polinomios

Autor(a): Angel David Ortega Felix


Requisitos del sistema:
Compilador C++ (g++ versión 9 o superior)
Sistema operativo: Windows

Compilación y Ejecución

g++ main.cpp -o NombreDeArchivo -O3
./NombreDeArchivo


Algoritmos
Método Estándar: Calcula cada término por separado (x², x³, etc.) y los suma. Complejidad: O(n²)
Método Horner: Evalúa el polinomio anidando las operaciones. Complejidad: O(n)

Resultados experimentales y gráfica comparativa: 
<img width="843" alt="image" src="https://github.com/user-attachments/assets/8538215c-d477-4d9a-bb35-93bdca718c3e" />

Análisis: 
El análisis de los resultados demuestra claramente la superioridad del método de Horner en términos de eficiencia computacional. Al comparar ambos métodos, observamos que el algoritmo de Horner mantiene un tiempo de ejecución significativamente menor en todos los grados de polinomios evaluados, siendo esta diferencia más pronunciada a medida que aumenta el grado del polinomio. Para polinomios de grado 1000, el método de Horner llega a ser hasta 27 veces más rápido que el enfoque estándar, lo que confirma plenamente su ventaja en escenarios de polinomios de alto grado. 


Conclusiones: El metodo horner es un metodo mucho mas eficiente ya que utiliza complejidad O (n^2) y al observarse los tiempos a comparación de los grados nos percatamos de como esto es notorio al ser una linea completamente linea y el estandar es una linea curveada debido a que es una ecuación cuadratica su complejidad. Dando a comprender como hay algoritmos que con el uso de la razón y la lógica pueden llegar a mejorar la eficiencia de problemas que utilizarían mucha capacidad.
