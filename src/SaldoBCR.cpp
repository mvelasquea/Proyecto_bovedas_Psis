#include "SaldoBCR.h"
#include "Excepciones.h"
#include <iostream>
//cambio para el punto del saldo final ( agregado extra de la calse)
void SaldoBCR::agregarSaldo(const std::string &tipo, double monto)
{
  saldoPorTipo[tipo] += monto;
  std::cout << "[Saldo actualizado] " << tipo << ": " << saldoPorTipo[tipo] << std::endl;
}

void SaldoBCR::descontarSaldo(const std::string &tipo, double monto)
{
  if (saldoPorTipo[tipo] < monto)
    throw SaldoInsuficienteException("Insufficient balance for " + tipo); //rango para cumplirlo 
  saldoPorTipo[tipo] -= monto;
  std::cout << "[Saldo actualizado] " << tipo << ": " << saldoPorTipo[tipo] << std::endl;
}

//hasta aca 



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