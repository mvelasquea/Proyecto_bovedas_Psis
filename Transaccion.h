#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <string>

class Transaccion {
private:
    std::string fecha;
    int cantidad200, cantidad100, cantidad50, cantidad10, cantidad5;
    std::string tipoOperacion;
    std::string transportadora;
    std::string plaza;
    std::string origen;
    std::string destino;

public:
    // Constructor
    Transaccion(const std::string& fecha, int c200, int c100, int c50,
                int c10, int c5, const std::string& tipoOperacion,
                const std::string& transportadora, const std::string& plaza,
                const std::string& origen, const std::string& destino);

    // Métodos Getters
    std::string getFecha() const;
    std::string getTipoOperacion() const;
    std::string getTransportadora() const;
    std::string getResumen() const;

    // Cálculo del monto total en base a denominaciones
    double calcularMontoTotal() const;
};

#endif
