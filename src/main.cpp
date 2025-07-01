#include "Banco.h"
#include "Transaccion.h"
#include <iostream>

int main()
{
  Banco banco;
  try
  {
    // Depositi inicial
    Transaccion t1("2025-06-26", 1, 0, 0, 0, 0,
                   "deposito", "Hermes", "Lima",
                   "Banco Central", "Sucursal A","Soles");
    banco.procesarTransaccion(t1);

    // Transferencia
    Transaccion t2("2025-06-26", 0, 2, 0, 0, 0,
                   "traslado", "Prosegur", "Arequipa",
                   "Sucursal A", "Sucursal B","Soles");
    banco.procesarTransaccion(t2);

    // Retiro
    Transaccion t3("2025-06-26", 0, 0, 0, 3, 0,
                   "retiro", "Hermes", "Lima",
                   "Sucursal B", "Cliente X","Soles");
    banco.procesarTransaccion(t3);
    // Depósito en Dólares
    Transaccion t4("2025-06-27", 0, 1, 1, 0, 0,
                   "deposito", "Prosegur", "Lima",
                   "Banco Central", "Sucursal C", "Dolares");
    banco.procesarTransaccion(t4);

    // Retiro en Dólares
    Transaccion t5("2025-06-27", 0, 0, 1, 0, 0,
                   "retiro", "Hermes", "Lima",
                   "Sucursal C", "Cliente Y", "Dolares");
    banco.procesarTransaccion(t5);
    std::vector<std::string> rutaTraslado = {"Sucursal A", "Centro de Distribucion", "Sucursal B"};
    Transaccion t6("2025-06-28", 0, 1, 0, 0, 0,
                   "traslado", "Hermes", "Lima",
                   rutaTraslado, "Soles");
    banco.procesarTransaccion(t6);

    // Traslado con ruta en Dólares
    std::vector<std::string> rutaDolares = {"Sucursal C", "Agencia Intermedia", "Sucursal D"};
    Transaccion t7("2025-06-28", 0, 0, 2, 0, 0,
                   "traslado", "Prosegur", "Lima",
                   rutaDolares, "Dolares");
    banco.procesarTransaccion(t7);
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
