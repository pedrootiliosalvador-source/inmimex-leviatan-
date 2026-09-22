#ifndef CONTROL_H
#define CONTROL_H

#include "seguridad.h"
#include <string>

class ControlMaquina {
private:
    SistemaSeguridad* seguridad;
    int velocidadRPM;
    int flujoAlimentacion;
    bool procesoActivo;
    std::string estado;

public:
    ControlMaquina(SistemaSeguridad* seg) : seguridad(seg) {
        velocidadRPM = 0;
        flujoAlimentacion = 0;
        procesoActivo = false;
        estado = "DETENIDO";
    }

    std::string iniciarProceso(int vel, int flujo) {
        if (!seguridad->estaSeguro()) {
            return "❌ NO SE PUEDE INICIAR — " + seguridad->estadoSeguridad();
        }
        velocidadRPM = vel;
        flujoAlimentacion = flujo;
        procesoActivo = true;
        estado = "OPERANDO";
        return "✅ PROCESO INICIADO — Velocidad: " + std::to_string(vel) + 
               " RPM | Flujo: " + std::to_string(flujo) + "%";
    }

    std::string detenerTotal() {
        velocidadRPM = 0;
        flujoAlimentacion = 0;
        procesoActivo = false;
        estado = "DETENIDO";
        return "🛑 SISTEMA DETENIDO — Discos frenados correctamente";
    }

    std::string cicloLimpieza() {
        detenerTotal();
        estado = "LIMPIEZA";
        velocidadRPM = 150;
        return "🧹 INICIANDO LIMPIEZA AUTOMÁTICA — Velocidad reducida, sin riesgo";
    }

    std::string paroEmergencia() {
        seguridad->forzarParada();
        detenerTotal();
        estado = "EMERGENCIA";
        return "⚠️ PARO DE EMERGENCIA ACTIVADO — TODOS LOS SISTEMAS DETENIDOS";
    }

    std::string getEstado() {
        return estado + " | RPM: " + std::to_string(velocidadRPM) + 
               " | Flujo: " + std::to_string(flujoAlimentacion) + "%";
    }

    bool procesoActivoYN() { return procesoActivo; }
    int getVelocidad() { return velocidadRPM; }
};

#endif
