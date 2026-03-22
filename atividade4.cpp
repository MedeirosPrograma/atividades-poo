#include <iostream>
#include <string>

using namespace std;

class AtivoCampo {
private:
    string tag;
    bool bloqueado;

protected:
    string area;

    void redefinirArea(string novaArea) {
        area = novaArea;
    }

public:
    AtivoCampo(string novaTag, string novaArea)
        : tag(novaTag), bloqueado(false), area(novaArea) {}

    string getTag() const {
        return tag;
    }

    bool estaBloqueado() const {
        return bloqueado;
    }

    void bloquear() {
        bloqueado = true;
    }

    void liberar() {
        bloqueado = false;
    }
};

class SensorNivel : public AtivoCampo {
private:
    double nivelAtual;
    double limiteAlto;

public:
    SensorNivel(string novatag, string novaarea, double nlimiteAlto)
        : AtivoCampo(novatag,novaarea), nivelAtual(0.0), limiteAlto(nlimiteAlto){}
    void atualizarnivel (double nnivel){
        if(estaBloqueado()){
            cout << "o sensor está bloqueado\n";
            return;
        }
        if (nnivel < 0)
        {
            nivelAtual = 0.0 ;
            return;
        }
        nivelAtual = nnivel ;
    }
    void exibirResumo() const {
            cout << "[SensorNivel] " << getTag()
                << " | area: " << area
                << " | nivel: " << nivelAtual
                << " | limite alto: " << limiteAlto << "\n";
    }

        friend void inspecao (const SensorNivel& sensor);
};
    void inspecao (const SensorNivel& sensor){
        cout << "|tag|" << sensor.getTag()
             << "|nivel atual|" << sensor.nivelAtual << "\n"
             << "|limite alto|" << sensor.limiteAlto;
    };

class BombaDosadora : public AtivoCampo {
private:
    double vazaoPercentual;
public:
    BombaDosadora(string novaTag, string novaArea)
            : AtivoCampo(novaTag, novaArea), vazaoPercentual(0.0) {}

        void ajustarVazao(double nVazao) {
            if (estaBloqueado()) {
                return;
            }

            if (nVazao < 0.0) {
                nVazao = 0.0;
            }

            if (nVazao > 100.0) {
                nVazao = 100.0;
            }

            vazaoPercentual = nVazao;
        }

        void moverParaArea(string novaArea) {
            redefinirArea(novaArea);
        }

        void exibirResumo() const {
            cout << "[BombaDosadora] " << getTag()
                << " | area: " << area
                << " | vazao: " << vazaoPercentual << "%\n";
        }
};

int main() {
    SensorNivel sensor("LT-501", "Tanque de preparo", 85.0);
    BombaDosadora bomba("P-501", "Skid de dosagem");

    sensor.atualizarnivel(62.5);
    bomba.ajustarVazao(47.0);
    bomba.moverParaArea("Utilidades");

    sensor.exibirResumo();
    bomba.exibirResumo();
    inspecao(sensor);

    return 0;
}