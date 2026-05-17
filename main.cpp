#include <iostream>
#include <vector>
#include <memory>
#include "Personaje.h"
#include "Guerrero.h"
#include "Mago.h"
#include "Equipo.h"
using namespace std;

int main() {
    //1
    vector<shared_ptr<Personaje>> personajes;
    try {
        //2
        shared_ptr<Guerrero> g1 = make_shared<Guerrero>("Fineas", 100, 15, 'F', 30);
        shared_ptr<Guerrero> g2 = make_shared<Guerrero>("Ferb", 100, 20, 'A', 20);
        personajes.push_back(g1);
        personajes.push_back(g2);
        //3
        cout << "¿Son ambos guerreros iguales? ";
        if (g1==g2) {
            cout << "SI" << endl;
        }else {
            cout << "NO" << endl;
        }
        //4
        shared_ptr<Guerrero> g3 = make_shared<Guerrero>(*g1+*g2);
        ++(*g3);
        personajes.push_back(g3);
        //5
        shared_ptr<Mago> m1 = make_shared<Mago>("Elias", 75, 35, 'P', 20);
        personajes.push_back(m1);
        //6
        try {
            try {
                m1->lanzarHechizo(1, *g3);
            }catch (const logic_error& error1) {
                cout << "ERROR, "<<error1.what()<<endl;
            }
        }catch (const invalid_argument& error2) {
            cout << "ERROR, "<<error2.what()<<endl;
        }
        //7
        Equipo<shared_ptr<Personaje>> team;
        team.reclutar(g1);
        team.reclutar(g2);
        team.reclutar(m1);
        team.mostrarEquipo();

    }catch (const invalid_argument& e) {
        cout << "ERROR, " << e.what()<<endl;
    }
    return 0;
}
