#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Alumno
{
    private:
        string nombre;
        string apellido;
        string carrera;
        string CP;
        string matricula;
        string pais;
        string estado;
    public:
        Alumno(string nombre, string apellido, string carrera, string CP, string matricula, string pais, string estado);
        string getNombre();
        string getApellido();
        string getCarrera();
        string getCP();
        string getMatricula();
        string getPais();
        string getEstado();
        void setNombre(string nombre);
        void setApellido(string apellido);
        void setCarrera(string carrera);
        void setCP(string CP);
        void setMatricula(string matricula);
        void setPais(string pais);
        void setEstado(string estado);
};