#include "Bitacora.h"
#include <iostream>
#include <fstream>

void Bitacora::registrarEvento(const std::string &mensaje)
{
  registros.push_back(mensaje);
}

void Bitacora::mostrarEventos() const
{
  std::cout << "-- Log Events --\n";
  for (auto &r : registros)
    std::cout << r << std::endl;
}

void Bitacora::guardarEnArchivo(const std::string &archivo) const
{
  std::ofstream out(archivo);
  for (auto &r : registros)
    out << r << std::endl;
}
