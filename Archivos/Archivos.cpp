#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    int anioPublicacion;

public:
    Libro(string t, string a, int anio) {
        titulo = t;
        autor = a;
        anioPublicacion = anio;
    }

    void guardarEnArchivo() {
        ofstream archivo("libros.txt", ios::app);
        if (archivo.is_open()) {
            archivo << titulo << " " << autor << " " << anioPublicacion << endl;
            archivo.close();
            cout << "Libro guardado exitosamente.\n";
        }
        else {
            cout << "Error al abrir el archivo.\n";
        }
    }

    static void leerDesdeArchivo() {
        ifstream archivo("libros.txt");
        string t, a;
        int anio;
        if (archivo.is_open()) {
            cout << "\nLista de Libros:\n";
            while (archivo >> t >> a >> anio) {
                cout << "Titulo: " << t << ", Autor: " << a << ", Año: " << anio << endl;
            }
            archivo.close();
        }
        else {
            cout << "Error al abrir el archivo o el archivo no existe.\n";
        }
    }

    static void actualizarLibro(string tituloBuscar, string nuevoAutor, int nuevoAnio) {
        ifstream archivo("libros.txt");
        ofstream archivoTemp("temp.txt");
        string t, a;
        int anio;
        bool encontrado = false;

        if (archivo.is_open() && archivoTemp.is_open()) {
            while (archivo >> t >> a >> anio) {
                if (t == tituloBuscar) {
                    archivoTemp << t << " " << nuevoAutor << " " << nuevoAnio << endl;
                    encontrado = true;
                }
                else {
                    archivoTemp << t << " " << a << " " << anio << endl;
                }
            }
            archivo.close();
            archivoTemp.close();
            remove("libros.txt");
            rename("temp.txt", "libros.txt");

            if (encontrado) {
                cout << "Libro actualizado exitosamente.\n";
            }
            else {
                cout << "Libro no encontrado.\n";
            }
        }
        else {
            cout << "Error al abrir el archivo.\n";
        }
    }

    static void eliminarLibro(string tituloBuscar) {
        ifstream archivo("libros.txt");
        ofstream archivoTemp("temp.txt");
        string t, a;
        int anio;
        bool eliminado = false;

        if (archivo.is_open() && archivoTemp.is_open()) {
            while (archivo >> t >> a >> anio) {
                if (t == tituloBuscar) {
                    eliminado = true;
                }
                else {
                    archivoTemp << t << " " << a << " " << anio << endl;
                }
            }
            archivo.close();
            archivoTemp.close();
            remove("libros.txt");
            rename("temp.txt", "libros.txt");

            if (eliminado) {
                cout << "Libro eliminado exitosamente.\n";
            }
            else {
                cout << "Libro no encontrado.\n";
            }
        }
        else {
            cout << "Error al abrir el archivo.\n";
        }
    }
};

int main() {
    int opcion;
    do {
        cout << "\n--- Biblioteca ---\n";
        cout << "1. Agregar nuevo libro\n";
        cout << "2. Mostrar libros\n";
        cout << "3. Actualizar libro\n";
        cout << "4. Eliminar libro\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            string titulo, autor;
            int anio;
            cout << "Ingrese titulo: ";
            cin >> titulo;
            cout << "Ingrese autor: ";
            cin >> autor;
            cout << "Ingrese año de publicacion: ";
            cin >> anio;
            Libro nuevo(titulo, autor, anio);
            nuevo.guardarEnArchivo();
        }
        else if (opcion == 2) {
            Libro::leerDesdeArchivo();
        }
        else if (opcion == 3) {
            string titulo, autor;
            int anio;
            cout << "Ingrese titulo del libro a actualizar: ";
            cin >> titulo;
            cout << "Ingrese nuevo autor: ";
            cin >> autor;
            cout << "Ingrese nuevo año de publicacion: ";
            cin >> anio;
            Libro::actualizarLibro(titulo, autor, anio);
        }
        else if (opcion == 4) {
            string titulo;
            cout << "Ingrese titulo del libro a eliminar: ";
            cin >> titulo;
            Libro::eliminarLibro(titulo);
        }
        else if (opcion == 5) {
            cout << "Saliendo...\n";
        }
        else {
            cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 5);
    return 0;
}
