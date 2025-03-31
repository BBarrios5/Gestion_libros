#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class libro {
private:
	string titulo;
	string autor;
	int anio_publicacion;

public:
	libro(string t, string a, int anio) {
		titulo = t;
		autor = a;
		anio_publicacion = anio;
	}

void guardar_Archivo() {
	ofstream archivo("libro.txt", ios::app);
	if (archivo.is_open()) {
		archivo << titulo << " " << autor << " " << anio_publicacion << endl;
		archivo.close();
		cout << "Libro Guardado exitosamente. \n";
	}
	else {
		cout << "Error al abrir el archivo. \n ";
	}
}
 static void Actualizar_Libro(string Titulo_Buscar, string Nuevo_Autor, int Nuevo_anio ){
	 ifstream archivo("libro.txt");
	 ofstream archivoTemp("temp.txt");
	 string t, a;
	 int anio;
	 bool encontrado = false;

	 if (archivo.is_open() && archivoTemp.is_opem()){
		 while (archivo >> t >> a >> anio) {
			 if ( t == Titulo_Buscar){
				 archivo << t << " " << Nuevo_Autor << " " << Nuevo_Autor << endl;
				 encontrado = 
