# 💰 Bóvedas Bancarias - Sistema de Gestión de Transacciones

Este proyecto simula la gestión de transacciones bancarias entre bóvedas, incluyendo depósitos, traslados y retiros de dinero físico, utilizando C++ y Programación Orientada a Objetos.

## 🗂 Estructura del Proyecto

```
Bovedas/
├── include/
│   ├── Banco.h
│   ├── Bitacora.h
│   ├── Excepciones.h
│   ├── SaldoBCR.h
│   └── Transaccion.h
├── src/
│   ├── Banco.cpp
│   ├── Bitacora.cpp
│   ├── Excepciones.cpp
│   ├── SaldoBCR.cpp
│   ├── Transaccion.cpp
│   └── main.cpp
└── README.md
```

## 🔧 Requisitos

- Compilador compatible con C++11 o superior.
- `make` (opcional, si usas un Makefile).

## 🛠 Compilación Manual

Puedes compilar el proyecto usando `g++` desde la carpeta `src`:

```bash
g++ Banco.cpp Bitacora.cpp Excepciones.cpp SaldoBCR.cpp Transaccion.cpp main.cpp -o program
````

## ▶️ Ejecución

```bash
./program.exe
```

## 💼 Funcionalidades

* Registro de transacciones por fecha, tipo, transportadora, plaza, origen y destino.
* Validación de transportadoras, operaciones y formato de fecha.
* Control de saldo total por tipo de moneda (actualmente: "Soles").
* Bitácora de eventos con opción para exportar a archivo.

## 📁 Archivos generados

* `bitacora.txt`: Archivo exportado con el historial de operaciones registradas.

## 🧪 Ejemplo de Uso

```cpp
Transaccion t1("2025-06-26", 1, 0, 0, 0, 0, "deposito", "Hermes", "Lima", "Banco Central", "Sucursal A");
banco.procesarTransaccion(t1);
```

## 📌 Notas

* Se pueden extender tipos de moneda o activos fácilmente desde `SaldoBCR`.
* Fechas deben seguir el formato `YYYY-MM-DD`.
* Transportadoras válidas: `"Hermes"`, `"Prosegur"`, `"Otro"`.