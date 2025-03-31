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
    MiembroClub(string _nombre, int _edad,  string _correo):
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
    static void leerDesdeArchivo() {
        
        ifstream archivo("club.txt");
        string n, c;
        int e;

        if (archivo.is_open()) {
            cout << endl << "Lista de Miembros:" << endl;
            while (archivo >> n >> e >> c) {
                cout << "Nombre: " << n <<endl<< ", Edad: " << e <<endl<< ", Correo: " << c <<endl<< endl;
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
        ifstream archivo("club.txt");
        ofstream archivoTemp("temp.txt");
        string n, c;
        int e;
        bool eliminado = false;

        if (archivo.is_open() && archivoTemp.is_open()) {
            while (archivo >> n >> e >> c) {
                if (n == nombreBuscar) {
                    eliminado = true;
                }
                else {
                    archivoTemp << n << "" << e << "" << c << endl;
                }
            }

            archivo.close();
            archivoTemp.close();
            remove("club.txt");
            rename("temp.txt", "club.txt");

            if (eliminado) {
                cout << "Miembro eliminado exitosamente!" << endl;
            }
            else {
                cout << "Miembro no encontrado." << endl;
            }
        }
        else {
            cout << "Error al abrir el archivo" << endl;
        }
    }

};

//Implementación del Menú Principal

int main(){
    int opcion;
    string nombre, correo;
    int edad;

    do {
        cout << endl 
            <<"*-*-*- Menu del Club -*-*-*" << endl <<
            "1. Agregar nuevo miembro" << endl <<
            "2. Mostrar miembros" << endl <<
            "3. Actualizar miembro" << endl <<
            "4. Eliminar miembro" << endl <<
            "5. Salir" << endl <<
            "Seleccione una opcion: " << endl;
        cin >> opcion;

        if (opcion == 1) {
            cout << "Ingresa el nombre: "; cin >> nombre;
            cout << "Ingresa la edad: "; cin >> edad;
            cout << "Ingresa el correo electronico: "; cin >> correo;

            MiembroClub nuevo(nombre, edad, correo);
            nuevo.guardarEnArchivo();
        }
        else  if (opcion == 2) {
            MiembroClub::leerDesdeArchivo();
        }
        else  if (opcion == 3) {
            cout << "Ingresa el nombre: "; cin >> nombre;
            cout << "Ingresa la edad: "; cin >> edad;
            cout << "Ingresa el correo electronico: "; cin >> correo;

            MiembroClub::actualizarMiembro(nombre, edad, correo);
        }
        else  if (opcion == 4) {
            cout << "Ingresa el nombre del miembro a eliminar: "; cin >> nombre;
            MiembroClub::eliminarMiembro(nombre);
        }
        else  if (opcion == 5) {
            cout << "Saliendo..." << endl;
        }
        else {
            cout << "Opcion invalida. Intenta de nuevo." << endl;
        }
       
    } while (opcion != 5);

    return 0;
}
