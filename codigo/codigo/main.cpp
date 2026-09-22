/*
 * ⚙️ INMIMEX LEVIATÁN — SISTEMA DE AUTOMATIZACIÓN INTELIGENTE
 * Versión: 1.0
 * Creador: Pedro Otilio Salvador Méndez
 * Propósito: Control y monitoreo de molinos pulverizadores, coloidales y mezcladoras
 * Compilación: g++ main.cpp -o leviatan -std=c++17 -pthread
 */

#include <iostream>
#include <string>
#include "seguridad.h"
#include "control.h"
#include "monitoreo.h"

void mostrarMenu() {
    std::cout << "\n";
    std::cout << "╔══════════════════════════════════════════════════════════╗\n";
    std::cout << "║          ⚙️  INMIMEX LEVIATÁN — SISTEMA PRINCIPAL         ║\n";
    std::cout << "║  Control Inteligente • Seguridad Total • Monitoreo 24/7  ║\n";
    std::cout << "╚══════════════════════════════════════════════════════════╝\n";
    std::cout << "\n  1. ▶️  Iniciar Proceso\n";
    std::cout << "  2. ⏹️  Detener Total\n";
    std::cout << "  3. 🔄 Ciclo de Limpieza Automática\n";
    std::cout << "  4. 📊 Ver Estado y Monitoreo\n";
    std::cout << "  5. 📷 Revisar Cámaras (Entrada/Salida)\n";
    std::cout << "  6. 📋 Reporte de Lotes\n";
    std::cout << "  7. 🛑 PARO DE EMERGENCIA\n";
    std::cout << "  0. ❌ Salir\n";
    std::cout << "═══════════════════════════════════════════════════════════\n";
    std::cout << "Selecciona una opción: ";
}

int main() {
    SistemaSeguridad seguridad;
    ControlMaquina control(&seguridad);
    Monitoreo monitoreo;

    std::cout << "\n🔄 INICIANDO SISTEMA LEVIATÁN...\n";
    std::cout << "✅ Módulo de Seguridad cargado\n";
    std::cout << "✅ Módulo de Control activo\n";
    std::cout << "✅ Módulo de Monitoreo conectado\n";
    std::cout << "✅ Sistema LISTO — INMIMEX LEVIATÁN v1.0\n";

    int opcion;
    while (true) {
        mostrarMenu();
        std::cin >> opcion;

        if (opcion == 0) {
            std::cout << "\n👋 Cerrando sistema LEVIATÁN...\n";
            std::cout << "🛑 Deteniendo todos los procesos...\n";
            std::cout << "✅ Sistema apagado correctamente. ¡Hasta luego!\n";
            break;
        }

        switch (opcion) {
            case 1: {
                int vel, flujo;
                std::cout << "\n🎛️  INICIAR PROCESO\n";
                std::cout << "Velocidad (RPM recomendado: 1500-3000): ";
                std::cin >> vel;
                std::cout << "Flujo de alimentación (0-100%): ";
                std::cin >> flujo;
                std::cout << control.iniciarProceso(vel, flujo) << "\n";
                break;
            }
            case 2: {
                std::cout << "\n⏹️  DETENER TOTAL\n";
                std::cout << control.detenerTotal() << "\n";
                break;
            }
            case 3: {
                std::cout << "\n🧹 LIMPIEZA AUTOMÁTICA\n";
                std::cout << control.cicloLimpieza() << "\n";
                break;
            }
            case 4: {
                std::cout << "\n📊 ESTADO DEL SISTEMA\n";
                std::cout << "------------------------------------\n";
                std::cout << "Estado: " << control.getEstado() << "\n";
                std::cout << seguridad.estadoSeguridad() << "\n";
                std::cout << "Temperatura motor: " << seguridad.getTemperatura() << "°C\n";
                std::cout << "------------------------------------\n";
                break;
            }
            case 5: {
                std::cout << "\n📷 MONITOREO DE CÁMARAS\n";
                std::cout << "Cámara 1 — Zona de Llenado: " << monitoreo.analizarCamaraEntrada() << "\n";
                std::cout << "Cámara 2 — Producto Terminado: " << monitoreo.analizarCamaraSalida() << "\n";
                break;
            }
            case 6: {
                std::cout << "\n📋 REGISTRO DE LOTES\n";
                std::cout << monitoreo.generarReporteLotes() << "\n";
                break;
            }
            case 7: {
                std::cout << "\n⚠️  PARO DE EMERGENCIA\n";
                std::cout << control.paroEmergencia() << "\n";
                break;
            }
            default:
                std::cout << "\n❌ Opción no válida. Intenta de nuevo.\n";
        }
        std::cout << "\nPresiona ENTER para continuar...";
        std::cin.ignore();
        std::cin.get();
    }
    return 0;
}
