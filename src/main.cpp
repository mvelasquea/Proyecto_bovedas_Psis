#include "Banco.h"
#include "Transaccion.h"
#include <iostream>

int main()
{
  Banco banco;
  try
  {
    // Initial deposit
    Transaccion t1("2025-06-26", 1, 0, 0, 0, 0,
                   "deposito", "Hermes", "Lima",
                   "Banco Central", "Sucursal A");
    banco.procesarTransaccion(t1);

    // Transfer
    Transaccion t2("2025-06-26", 0, 2, 0, 0, 0,
                   "traslado", "Prosegur", "Arequipa",
                   "Sucursal A", "Sucursal B");
    banco.procesarTransaccion(t2);

    // Withdrawal
    Transaccion t3("2025-06-26", 0, 0, 0, 3, 0,
                   "retiro", "Hermes", "Lima",
                   "Sucursal B", "Cliente X");
    banco.procesarTransaccion(t3);
  }
  catch (const std::exception &ex)
  {
    std::cerr << "Error: " << ex.what() << std::endl;
  }

  // Show results
  banco.mostrarHistorial();
  banco.mostrarSaldos();
  banco.exportarBitacora("bitacora.txt");
  std::cout << "Bitacora exported to bitacora.txt\n";
  banco.exportarBitacoraCSV("bitacora.csv");
  std::cout << "Bitacora exported to bitacora.csv\n";

  return 0;
}
