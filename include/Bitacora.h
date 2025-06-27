#ifndef BITACORA_H
#define BITACORA_H

#include <string>
#include <vector>

class Bitacora {
private:
    std::vector<std::string> registros;

public:
    void registrarEvento(const std::string& mensaje);
    void mostrarEventos() const;
    void guardarEnArchivo(const std::string& archivo) const;
};

#endif
