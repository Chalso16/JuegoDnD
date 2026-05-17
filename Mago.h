//
// Created by cbalb on 17/05/2026.
//

#ifndef MODELO2_MAGO_H
#define MODELO2_MAGO_H
#include "Personaje.h"
#include <iostream>
using namespace std;

class Mago :public Personaje{
private:
    int mana;
public:
    //constructores
    Mago();
    Mago(const string& nombre, const int& vida, const int& poderBase, const char& elemento, const int& mana);
    Mago(const Mago& mago);
    ~Mago() override = default;
    //getters
    int getMana() const;
    //setters
    void setMana(const int& mana);
    //metodos
    void lanzarHechizo(int idHechizo, Personaje& objetivo);
};


#endif //MODELO2_MAGO_H
