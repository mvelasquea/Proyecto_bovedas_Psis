#include "Transaccion.h"

// Constructor con origen, destino
Transaccion::Transaccion(const std::string &fecha, int c200, int c100, int c50,
                         int c10, int c5, const std::string &tipoOperacion,
                         const std::string &transportadora, const std::string &plaza,
                         const std::string &origen, const std::string &destino)
    : fecha(fecha), tipoOperacion(tipoOperacion), transportadora(transportadora),
      plaza(plaza), origen(origen), destino(destino)
{
    cantidades[200] = c200;
    cantidades[100] = c100;
    cantidades[50] = c50;
    cantidades[10] = c10;
    cantidades[5] = c5;
}

// Constructor con origen, destino y moneda
Transaccion::Transaccion(const std::string &fecha, int c200, int c100, int c50,
                         int c10, int c5, const std::string &tipoOperacion,
                         const std::string &transportadora, const std::string &plaza,
                         const std::string &origen, const std::string &destino,
                         const std::string &moneda)
    : fecha(fecha), tipoOperacion(tipoOperacion), transportadora(transportadora),
      plaza(plaza), origen(origen), destino(destino), moneda(moneda)
{
    cantidades[200] = c200;
    cantidades[100] = c100;
    cantidades[50] = c50;
    cantidades[10] = c10;
    cantidades[5] = c5;
}

// Constructor con ruta y moneda
Transaccion::Transaccion(const std::string &fecha, int c200, int c100, int c50,
                         int c10, int c5, const std::string &tipoOperacion,
                         const std::string &transportadora, const std::string &plaza,
                         const std::vector<std::string> &ruta,
                         const std::string &moneda)
    : fecha(fecha), tipoOperacion(tipoOperacion), transportadora(transportadora),
      plaza(plaza), ruta(ruta), moneda(moneda)
{
    cantidades[200] = c200;
    cantidades[100] = c100;
    cantidades[50] = c50;
    cantidades[10] = c10;
    cantidades[5] = c5;
}

std::string Transaccion::getFecha() const { return fecha; }
std::string Transaccion::getTipoOperacion() const { return tipoOperacion; }
std::string Transaccion::getTransportadora() const { return transportadora; }
std::string Transaccion::getMoneda() const { return moneda; }
std::vector<std::string> Transaccion::getRuta() const { return ruta; }

double Transaccion::calcularMontoTotal() const
{
    double total = 0;
    for (auto &[denom, count] : cantidades)
    {
        total += denom * count;
    }
    return total;
}

std::string Transaccion::getResumen() const
{
    std::string rutaStr;
    if (!ruta.empty()) {
        rutaStr = "Ruta: ";
        for (size_t i = 0; i < ruta.size(); ++i) {
            rutaStr += ruta[i];
            if (i < ruta.size() - 1) rutaStr += " -> ";
        }
    } else {
        rutaStr = "No hay ruta definida";
    }
    return fecha + " | " + tipoOperacion + " | " + transportadora +
           " | " + plaza + " | " + origen + "->" + destino +
           " | Moneda=" + moneda +
           " | Total=" + std::to_string(calcularMontoTotal()) + "  " + rutaStr;
}