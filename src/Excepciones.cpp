#include "include/Excepciones.h"

SaldoInsuficienteException::SaldoInsuficienteException(const std::string& mensaje)
    : std::runtime_error(mensaje) {}

TransportadoraInvalidaException::TransportadoraInvalidaException(const std::string& mensaje)
    : std::runtime_error(mensaje) {}

FechaInvalidaException::FechaInvalidaException(const std::string& mensaje)
    : std::runtime_error(mensaje) {}

OperacionNoReconocidaException::OperacionNoReconocidaException(const std::string& mensaje)
    : std::runtime_error(mensaje) {}

EntidadNoRegistradaException::EntidadNoRegistradaException(const std::string& mensaje)
    : std::runtime_error(mensaje) {}
