#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <string>
#include <map>
#include <vector> //para las rutas 

class Transaccion
{
private:
    std::string fecha;
    std::map<int, int> cantidades; //{200: 1, 100: 0, 5}
    std::string tipoOperacion;
    std::string transportadora;
    std::string plaza;
    std::string origen;
    std::string destino;
    std::vector<std::string> ruta; // donde cada transaccicon  tenga una lista de puntos 
    std::string moneda;        

public:
    // Constructor clásico (origen y destino)
    Transaccion(const std::string &fecha, int c200, int c100, int c50,
                int c10, int c5, const std::string &tipoOperacion,
                const std::string &transportadora, const std::string &plaza,
                const std::string &origen, const std::string &destino);

    // Constructor con origen, destino y moneda
    Transaccion(const std::string &fecha, int c200, int c100, int c50,
                int c10, int c5, const std::string &tipoOperacion,
                const std::string &transportadora, const std::string &plaza,
                const std::string &origen, const std::string &destino,
                const std::string &moneda);

    // Constructor con ruta y moneda
    Transaccion(const std::string &fecha, int c200, int c100, int c50,
                int c10, int c5, const std::string &tipoOperacion,
                const std::string &transportadora, const std::string &plaza,
                const std::vector<std::string> &ruta,
                const std::string &moneda);

    std::string getFecha() const;
    std::string getTipoOperacion() const;
    std::string getTransportadora() const;
    std::string getResumen() const;
    std::vector<std::string> getRuta() const;
    std::string getMoneda() const;
    double calcularMontoTotal() const;
};

#endif