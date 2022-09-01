#include "Alumno.h"
Alumno::Alumno(string nombre, string apellido, string carrera, string CP, string matricula, string pais, string estado)
{
    this->nombre = nombre;
    this->apellido = apellido;
    this->carrera = carrera;
    this->CP = CP;
    this->matricula = matricula;
    this->pais = pais;
    this->estado = estado;
}
string Alumno::getNombre()
{
    return this->nombre;
}
string Alumno::getApellido()
{
    return this->apellido;
}
string Alumno::getCarrera()
{
    return this->carrera;
}
string Alumno::getCP()
{
    return this->CP;
}

string Alumno::getMatricula()
{
    return this->matricula;
}

string Alumno::getPais()
{
    return this->pais;
}

string Alumno::getEstado()
{
    return this->estado;
}

void Alumno::setNombre(string nombre)
{
    this->nombre = nombre;
}
void Alumno::setApellido(string apellido)
{
    this->apellido = apellido;
}
void Alumno::setCarrera(string carrera)
{
    this->carrera = carrera;
}
void Alumno::setCP(string CP)
{
    this->CP = CP;
}

void Alumno::setMatricula(string matricula)
{
    this->matricula = matricula;
}

void Alumno::setPais(string pais)
{
    this->pais = pais;
}

void Alumno::setEstado(string estado)
{
    this->estado = estado;
}

