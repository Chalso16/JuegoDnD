//
// Created by cbalb on 17/05/2026.
//

#include "Mago.h"

//Constructores
Mago::Mago():Personaje(), mana(0) {

}

Mago::Mago(const string &nombre, const int &vida, const int &poderBase, const char &elemento, const int &mana)
    : Personaje(nombre, vida, poderBase, elemento), mana(mana){
    if (mana<0) {
        throw invalid_argument("Mana fuera de rango");
    }
}

Mago::Mago(const Mago &mago):Personaje(mago), mana(mago.mana) {

}

//getters
int Mago::getMana() const {
    return mana;
}

//setters
void Mago::setMana(const int& mana) {
    if (mana<0) {
        throw invalid_argument("Mana fuera de rango");
    }
    this->mana=mana;
}

//metodos
void Mago::lanzarHechizo(int idHechizo, Personaje &objetivo) {
    if (mana<10) {
        throw logic_error("Mana menor a 10");
    }else {
        setMana(getMana()-10);
    }
    double danio=0;
    char elementoHechizo;
    switch (idHechizo) {
        case 1:
            danio = getPoderBase()*1.5;
            elementoHechizo = 'F';
            break;
        case 2:
            danio = getPoderBase()*1.2;
            elementoHechizo = 'A';
            break;
        case 3:
            danio = getPoderBase()*1.0;
            elementoHechizo = 'P';
            break;
        default: throw invalid_argument("Hechizo desconocido");
    }
    if (objetivo.getElemento()=='P' && elementoHechizo=='F' ||
        objetivo.getElemento()=='F' && elementoHechizo=='A' ||
        objetivo.getElemento()=='A' && elementoHechizo=='P'){
        danio = danio*2.0;
    }
    objetivo.recibirDanio(danio);
}
