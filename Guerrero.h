//
// Created by cbalb on 17/05/2026.
//

#ifndef MODELO2_GUERRERO_H
#define MODELO2_GUERRERO_H
#include "Personaje.h"
#include <iostream>
using namespace std;

class Guerrero : public Personaje{
private:
    int armadura;
public:
    //contructores
    Guerrero();
    Guerrero(const string& nombre, const int& vida, const int& poderBase, const char& elemento, const int& armadura);
    Guerrero(const Guerrero& guerrero);
    ~Guerrero() override = default;
    //getter
    int getArmadura() const;
    //setter
    void setArmadura(const int& armadura);
    //sobrecarga
    Guerrero& operator++();
    Guerrero operator+ (const Guerrero& guerrero);
};


#endif //MODELO2_GUERRERO_H
