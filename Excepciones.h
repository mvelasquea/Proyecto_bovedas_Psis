#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H

#include <stdexcept>
#include <string>

class SaldoInsuficienteException : public std::runtime_error {
public:
    explicit SaldoInsuficienteException(const std::string& mensaje);
};

class TransportadoraInvalidaException : public std::runtime_error {
public:
    explicit TransportadoraInvalidaException(const std::string& mensaje);
};

class FechaInvalidaException : public std::runtime_error {
public:
    explicit FechaInvalidaException(const std::string& mensaje);
};

class OperacionNoReconocidaException : public std::runtime_error {
public:
    explicit OperacionNoReconocidaException(const std::string& mensaje);
};

class EntidadNoRegistradaException : public std::runtime_error {
public:
    explicit EntidadNoRegistradaException(const std::string& mensaje);
};

#endif
