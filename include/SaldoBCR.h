#ifndef SALDOBCR_H
#define SALDOBCR_H

#include <map>
#include <string>

class SaldoBCR {
private:
    std::map<std::string, double> saldoPorTipo; //soles o dolares  (mapita con el tippo de moneda)(con una cantidad de cada tio obviametne)

public:
    void agregarSaldo(const std::string& tipo, double monto);
    void descontarSaldo(const std::string& tipo, double monto); 
    double obtenerSaldo(const std::string& tipo) const;
    void mostrarSaldos() const;
};

#endif
