#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <fstream>

// Método estándar de evaluación polinomial
double evaluarPolinomioStandard(const std::vector<double>& coeficientes, double x) {
    double resultado = 0.0;
    for (size_t i = 0; i < coeficientes.size(); ++i) {
        double termino = coeficientes[i];
        for (size_t j = 0; j < i; ++j) {
            termino *= x;
        }
        resultado += termino;
    }
    return resultado;
}

// Método de Horner para evaluación polinomial
double evaluarPolinomioHorner(const std::vector<double>& coeficientes, double x) {
    double resultado = coeficientes.back();
    for (auto it = coeficientes.rbegin() + 1; it != coeficientes.rend(); ++it) {
        resultado = resultado * x + *it;
    }
    return resultado;
}

// Generar coeficientes aleatorios
std::vector<double> generarCoeficientes(int grado) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-10, 10);
    
    std::vector<double> coeficientes(grado + 1);
    for (auto& coef : coeficientes) {
        coef = dist(gen);
    }
    return coeficientes;
}

// Medir tiempo de ejecución
double medirTiempo(double (*metodo)(const std::vector<double>&, double), 
                  const std::vector<double>& coefs, 
                  double x, 
                  int repeticiones = 1000) {
    auto inicio = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < repeticiones; ++i) {
        metodo(coefs, x);
    }
    
    auto fin = std::chrono::high_resolution_clock::now();
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio);
    
    return duracion.count() / static_cast<double>(repeticiones);
}

int main() {
    // Configuración
    const int grado_min = 10;
    const int grado_max = 1000;
    const int paso = 10;
    const std::string archivo_salida = "resultados.csv";
    
    // Archivo de resultados
    std::ofstream resultados(archivo_salida);
    resultados << "grado,tiempo_standard_us,tiempo_horner_us\n";
    
    // Generador de números aleatorios para x
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist_x(-10.0, 10.0);
    
    std::cout << "Iniciando comparacion de metodos...\n";
    
    for (int grado = grado_min; grado <= grado_max; grado += paso) {
        // Generar polinomio aleatorio
        auto coefs = generarCoeficientes(grado);
        double x = dist_x(gen);
        while (x == 0.0) x = dist_x(gen); // Evitar x=0
        
        // Medir tiempos
        double tiempo_std = medirTiempo(evaluarPolinomioStandard, coefs, x);
        double tiempo_horner = medirTiempo(evaluarPolinomioHorner, coefs, x);
        
        // Guardar resultados
        resultados << grado << "," << tiempo_std << "," << tiempo_horner << "\n";
        
        // Mostrar progreso
        std::cout << "Grado " << grado << " - Standard: " << tiempo_std 
                  << " µs, Horner: " << tiempo_horner << " µs\n";
    }
    
    resultados.close();
    std::cout << "Comparacion completada. Resultados guardados en " << archivo_salida << "\n";
    
    return 0;
}