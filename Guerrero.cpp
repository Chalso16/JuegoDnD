//
// Created by cbalb on 17/05/2026.
//

#include "Guerrero.h"

Guerrero::Guerrero():Personaje(), armadura(0) {
}

Guerrero::Guerrero(const string &nombre, const int &vida, const int &poderBase, const char &elemento, const int &armadura)
    : Personaje(nombre, vida, poderBase, elemento), armadura(armadura){
    if (armadura<0) {
        throw invalid_argument("Armadura fuera de parametro");
    }
}

Guerrero::Guerrero(const Guerrero &guerrero):Personaje(guerrero), armadura(guerrero.armadura) {

}

//getters
int Guerrero::getArmadura() const {
    return armadura;
}

//setters
void Guerrero::setArmadura(const int &armadura) {
    if (armadura<0) {
        throw invalid_argument("Armadura fuera de parametro");
    }
    this->armadura=armadura;
}

//sobrecarga
Guerrero &Guerrero::operator++() {
    setPoderBase(getPoderBase()+5);
    setArmadura(getArmadura()+2);
    return *this;
}

Guerrero Guerrero::operator+(const Guerrero &guerrero) {
    Guerrero otro;
    otro.nombre = getNombre()+guerrero.nombre;
    otro.vida = getVida()+guerrero.vida;
    if (getPoderBase()>=guerrero.poderBase) {
        otro.poderBase = getPoderBase();
    }else {
        otro.poderBase = guerrero.poderBase;
    }
    otro.armadura = (getArmadura()+guerrero.armadura)/2;
    otro.elemento='F';
    return otro;
}
