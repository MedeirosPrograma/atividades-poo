#include <iostream>
#include <string>

using namespace std;

class SensorNivel {
private:
    string tag;
    double minimo;
    double maximo;
    double valorAtual;

public:
    SensorNivel(string ntag)
        : tag(ntag), minimo(0.0), maximo(100.0), valorAtual(0.0){}
        //carrega o sensor com os valores padrão
    SensorNivel(string ntag, double nminimo, double nmaximo, double nvaloratual)
        : tag(ntag), minimo(nminimo), maximo(nmaximo), valorAtual(nvaloratual){}
        //carrega os sensor com os valores fora de padrão
    void exibirResumo() const {
        cout << "[SensorNivel] " << tag
             << " | faixa: " << minimo << " a " << maximo
             << " | valor atual: " << valorAtual << "\n";
    }
};

class Bomba {
private:
    string tag;
    double velocidade;

public:

    Bomba(string ntag)
        : tag(ntag), velocidade(0.0){}
    //carrega bomba com velocidade padrão
    Bomba(string ntag, double nvelocidade)
        : tag(ntag), velocidade(nvelocidade){}
    //carrega bomba com velocidade inicial fora de padrão.

    void exibirResumo() const {
        cout << "[Bomba] " << tag
             << " | velocidade: " << velocidade << "%\n";
    }
};

class ControladorTanque {
private:
    string tag;
    double setpoint;
    double kp;

public:
    ControladorTanque(string ntag)
        :tag(ntag), setpoint(20.0),kp(3.0) {}
        //carrega um controlador com "kp" e setpoint padrão
    ControladorTanque(string ntag, double nsetpoint, double nkp)
        : tag(ntag), setpoint(nsetpoint),kp(nkp){}
        //carrega um controlador com "kp" e setpoint fora de padrão

    void exibirResumo() const {
        cout << "[ControladorTanque] " << tag
             << " | SP=" << setpoint
             << " | Kp=" << kp << "\n";
    }
};

int main() {
    SensorNivel sn1("MH-1609");
    SensorNivel sn2("MH-1610", 0.0, 1000.0, 230.0);
    
    sn1.exibirResumo();
    sn2.exibirResumo();
    // TODO: chame exibirResumo() para todos os objetos.

    return 0;
}