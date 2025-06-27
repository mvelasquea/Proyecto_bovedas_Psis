#include "include/SaldoBCR.h"
#include "include/Excepciones.h"
#include <iostream>

void SaldoBCR::agregarSaldo(const std::string &tipo, double monto)
{
  saldoPorTipo[tipo] += monto;
}

void SaldoBCR::descontarSaldo(const std::string &tipo, double monto)
{
  if (saldoPorTipo[tipo] < monto)
    throw SaldoInsuficienteException("Insufficient balance for " + tipo);
  saldoPorTipo[tipo] -= monto;
}

double SaldoBCR::obtenerSaldo(const std::string &tipo) const
{
  auto it = saldoPorTipo.find(tipo);
  return (it != saldoPorTipo.end() ? it->second : 0.0);
}

void SaldoBCR::mostrarSaldos() const
{
  std::cout << "-- Current Balances --\n";
  for (auto &[tipo, monto] : saldoPorTipo)
  {
    std::cout << tipo << ": " << monto << std::endl;
  }
}
