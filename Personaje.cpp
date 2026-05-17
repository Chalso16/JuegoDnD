//
// Created by cbalb on 17/05/2026.
//

#include "Personaje.h"

//constructores
Personaje::Personaje():nombre(""), vida(100), poderBase(0), elemento('F') {
}

Personaje::Personaje(const string &nombre, const int &vida, const int &poderBase, const char &elemento):nombre(nombre), vida(vida), poderBase(poderBase), elemento(elemento) {
    if (vida<0) {
        throw invalid_argument("Vida fuera de parametros");
    }
    if (poderBase<0) {
        throw invalid_argument("PoderBase fuera de parametros");
    }
    if (elemento!='F' && elemento!='A' && elemento!='P') {
        throw invalid_argument("Elemento no reconocido");
    }
}

Personaje::Personaje(const Personaje &personaje):nombre(personaje.nombre), vida(personaje.vida),
    poderBase(personaje.poderBase), elemento(personaje.elemento){
}

//getters
string Personaje::getNombre() const {
    return nombre;
}

int Personaje::getVida() const {
    return vida;
}

int Personaje::getPoderBase() const {
    return poderBase;
}

char Personaje::getElemento() const {
    return elemento;
}

//setters
void Personaje::setNombre(const string &nombre) {
    this->nombre=nombre;
}

void Personaje::setVida(const int &vida) {
    if (vida<0) {
        throw invalid_argument("Vida fuera de parametros");
    }
    this->vida=vida;
}

void Personaje::setPoderBase(const int &poderBase) {
    if (poderBase<0) {
        throw invalid_argument("Vida fuera de parametros");
    }
    this->poderBase=poderBase;
}

void Personaje::setElemento(const char &elemento) {
    if (elemento!='F' && elemento!='A' && elemento!='P') {
        throw invalid_argument("Elemento no reconocido");
    }
    this->elemento=elemento;
}

//sobrecarga
ostream &operator<<(ostream &os, const Personaje &personaje) {
    os << "-->Nombre: " << personaje.nombre << endl;
    os << "-->Vida: " << personaje.vida << endl;
    os << "-->PoderBase: " << personaje.poderBase << endl;
    os << "-->Elemento: " << personaje.elemento << endl;
}

bool Personaje::operator==(const Personaje &personaje) const {
    if (this->nombre==personaje.nombre && this->elemento==personaje.elemento) {
        return true;
    }
    return false;
}

void Personaje::recibirDanio(int cantidad) {
    if (vida==0) {
        throw runtime_error("Personaje ya esta muerto");
    }
    if (cantidad>=vida) {
        setVida(0);
    }
    else {
        setVida(getVida()-cantidad);
    }
}
