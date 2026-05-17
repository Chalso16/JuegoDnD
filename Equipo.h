//
// Created by cbalb on 17/05/2026.
//

#ifndef MODELO2_EQUIPO_H
#define MODELO2_EQUIPO_H
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Equipo {
private:
    vector<T> team;
public:
    //constructores
    Equipo(){}
    Equipo(const vector<T> equipos):team(equipos){}
    Equipo(const Equipo& equipo):team(equipo.team){}
    ~Equipo() = default;
    //getter
    vector<T> getTeam() const {
        return team;
    }
    //setter
    void setTeam(const vector<T>& team) {
        this->team=team;
    }
    //metodos
    void reclutar(const T& miembro) {
        team.push_back(miembro);
    }
    void mostrarEquipo() const {
        cout << "Lista del equipo: " << endl;
        for (const T& miembro: team) {
            cout << *miembro << endl;
        }
    }
};


#endif //MODELO2_EQUIPO_H
