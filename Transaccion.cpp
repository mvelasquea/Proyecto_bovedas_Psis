#include "include/Transaccion.h"

Transaccion::Transaccion(const std::string &f, int c200, int c100, int c50,
                         int c10, int c5, const std::string &tipoOp,
                         const std::string &transp, const std::string &pl,
                         const std::string &orig, const std::string &dest)
    : fecha(f), tipoOperacion(tipoOp), transportadora(transp),
      plaza(pl), origen(orig), destino(dest)
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
  return fecha + " | " + tipoOperacion + " | " + transportadora +
         " | " + plaza + " | " + origen + "->" + destino +
         " | Total=" + std::to_string(calcularMontoTotal());
}
