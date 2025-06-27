#include "include/Banco.h"
#include <iostream>
#include <algorithm>
#include <regex>
#include <fstream>

Banco::Banco() {}

void Banco::validarFecha(const std::string &fecha)
{
  if (!std::regex_match(fecha, std::regex("\\d{4}-\\d{2}-\\d{2}")))
    throw FechaInvalidaException("Invalid date format: " + fecha);
}

void Banco::validarTransportadora(const std::string &nombre)
{
  static std::vector<std::string> allowed{"Hermes", "Prosegur", "Otro"};
  if (std::find(allowed.begin(), allowed.end(), nombre) == allowed.end())
    throw TransportadoraInvalidaException("Unknown transporter: " + nombre);
}

void Banco::validarOperacion(const std::string &tipo)
{
  static std::vector<std::string> ops{"retiro", "deposito", "traslado", "canje", "pago", "interbancaria"};
  if (std::find(ops.begin(), ops.end(), tipo) == ops.end())
    throw OperacionNoReconocidaException("Unknown operation: " + tipo);
}

void Banco::procesarTransaccion(const Transaccion &t)
{
  validarFecha(t.getFecha());
  validarTransportadora(t.getTransportadora());
  validarOperacion(t.getTipoOperacion());

  double amt = t.calcularMontoTotal();
  if (t.getTipoOperacion() == "retiro")
    saldo.descontarSaldo("Soles", amt);
  else
    saldo.agregarSaldo("Soles", amt);

  historialTransacciones.push_back(t);
  log.registrarEvento("Processed: " + t.getResumen());
}

void Banco::mostrarHistorial() const
{
  std::cout << "== Transaction History ==\n";
  for (auto &t : historialTransacciones)
    std::cout << t.getResumen() << std::endl;
  log.mostrarEventos();
}

void Banco::mostrarSaldos() const
{
  saldo.mostrarSaldos();
}

void Banco::exportarBitacora(const std::string &archivo) const
{
  log.guardarEnArchivo(archivo);
}
void Banco::exportarBitacoraCSV(const std::string &archivo) const
{
    std::ofstream out(archivo);
    out << "Evento,Detalle\n"; // Cabecera para Excel

    for (const auto& evento : log.getEventos()) {
        // Suponiendo que el formato es "Processed: fecha | tipo | transportadora | plaza | origen->destino | Total=xxx"
        size_t pos = evento.find(": ");
        std::string tipo = (pos != std::string::npos) ? evento.substr(0, pos) : "";
        std::string detalle = (pos != std::string::npos) ? evento.substr(pos + 2) : evento;
        // Reemplaza '|' por ',' para separar columnas en el detalle
        std::replace(detalle.begin(), detalle.end(), '|', ',');
        out << tipo << "," << detalle << "\n";
    }
}