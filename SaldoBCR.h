#ifndef SALDOBCR_H
#define SALDOBCR_H

#include <map>
#include <string>

class SaldoBCR {
private:
    std::map<std::string, double> saldoPorTipo;  // Ej: {"Soles": 5000.0}

public:
    void agregarSaldo(const std::string& tipo, double monto);
    void descontarSaldo(const std::string& tipo, double monto); // Puede lanzar excepción
    double obtenerSaldo(const std::string& tipo) const;
    void mostrarSaldos() const;
};

#endif
