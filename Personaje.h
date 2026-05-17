//
// Created by cbalb on 17/05/2026.
//

#ifndef MODELO2_PERSONAJE_H
#define MODELO2_PERSONAJE_H
#include <iostream>
#include <stdexcept>
using namespace std;

class Personaje {
protected:
    string nombre;
    int vida;
    int poderBase;
    char elemento;
public:
    //constructores
    Personaje();
    Personaje(const string& nombre, const int& vida, const int& poderBase, const char& elemento);
    Personaje(const Personaje& personaje);
    virtual ~Personaje()=default;
    //getters
    string getNombre() const;
    int getVida() const;
    int getPoderBase() const;
    char getElemento() const;
    //setters
    void setNombre(const string& nombre);
    void setVida(const int& vida);
    void setPoderBase(const int& poderBase);
    void setElemento(const char& elemento);
    //sobrecargas
    friend ostream& operator<<(ostream& os, const Personaje& personaje);
    bool operator==(const Personaje &personaje) const;
    //metodos
    virtual void recibirDanio(int cantidad);
};


#endif //MODELO2_PERSONAJE_H
