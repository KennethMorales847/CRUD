#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class MiembroClub {
private:
    int edad;
    string nombre, correo;
public:
    MiembroClub(int _edad, string _nombre, string _correo):
        edad(_edad), nombre(_nombre), correo(_correo){ }

    //Escribir datos en Archivo

    void guardarEnArchivo() {
        ofstream archivo("club.txt", ios::app);

        if (archivo.is_open()) {
            archivo << nombre << " " << " " << edad << " " << correo << endl;
            archivo.close();
            cout << "Datos guardados exitosamente!" << endl;

        }
        else {
            cout << "Error al abrir l archivo" << endl;
        }
    }

    //Leer datos en Archivo
    void leerDesdeArchivo() {
        
        ifstream archivo("club.txt");
        string n, c;
        int e;

        if (archivo.is_open()) {
            cout << endl << "Lista de Miembros:" << endl;
            while (archivo >> n >> e >> c) {
                cout << "Nombre: " << n << ", Edad: " << e << ", Correo: " << c << endl;
            }
            archivo.close();
        }
        else {
            cout << "Error al abrir el archivo o el archivo no existe" << endl;
        }
    }


    //Modificar información de un miembro
    static void actualizarMiembro(string nombreBuscar, int nuevaEdad, string nuevoCorreo) {
        ifstream archivo("club.txt");
        ofstream archivoTemp("temp.txt");
        string n, c;
        int e;
        bool encontrado = false;
        if (archivo.is_open() && archivoTemp.is_open()) {
            while (archivo >> n >> e >> c) {
                if (n == nombreBuscar) {
                    archivoTemp << n << " " << nuevaEdad << " " << nuevoCorreo << endl;
                    encontrado = true;
                }
                else {
                    archivoTemp << n << " " << e << " " << c << endl;
                }
            }
            archivo.close();
            archivoTemp.close();
            remove("club.txt");
            rename("temp.txt", "club.txt");
            if (encontrado) {
                cout << "Miembro actualizado exitosamente.\n";
            }
            else {
                cout << "Miembro no encontrado.\n";
            }
        }
        else {
            cout << "Error al abrir el archivo.\n";
        }
    }

    //Eliminar un miembro del Archivo
    static void eliminarMiembro(string nombreBuscar) {

    }


};

int main()
{
    std::cout << "Hello World!\n";
}
