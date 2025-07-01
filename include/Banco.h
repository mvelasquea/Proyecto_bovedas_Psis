#ifndef BANCO_H
#define BANCO_H

#include "Transaccion.h"
#include "SaldoBCR.h"
#include "Bitacora.h"
#include "Excepciones.h"
#include <vector>

class Banco {
private:
    std::vector<Transaccion> historialTransacciones;
    SaldoBCR saldo;
    Bitacora log;

    // Validaciones internas(metodos)
    void validarTransportadora(const std::string& nombre);
    void validarOperacion(const std::string& tipo);
    void validarFecha(const std::string& fecha);

public:
    Banco();

    
    void procesarTransaccion(const Transaccion& t);

    // Acciones administrativas
    void mostrarHistorial() const;
    void mostrarSaldos() const;
    void exportarBitacora(const std::string& archivo) const;
};

#endif
