#include <iostream>
#include <fstream>
#include <conio.h>
#include"Archivos.h"
#include "Arreglo.h"
using namespace std;

int menu() {
	int men;
	system("cls");
	cout << "<-----Bienvenido a la base de Datos de APPs----->" << endl;
	cout << "1.- Agregar Usuario" << endl;
	cout << "2.- Ver Usuarios" << endl;
	cout << "3.- Buscar Usuarios" << endl;
	cout << "4.- Editar Usuarios" << endl;
	cout << "5.- Eliminar Usuarios" << endl;
	cout << "6.- Calcular ruta"<<endl;
	cout << "7.- Ver rutas calculadas" << endl;
	cout << "8.- Asistencia al cliente " << endl;
	cout << "9.- Salir" << endl;
	cout << "Opcion:";
	cin >> men;
	return men;
}
int menu2() {
	int men2;
	cout << "<-----Bienvenido al asistencia al cliente----->" << endl;
	cout << "1.- Digitar su codigo de seguridad" << endl;
	cout << "2.- Visualizar cuanto tiempo demora su recorrido" << endl;
	cout << "3.- Volver al meno principal" << endl;
	cout << "4.- Salir" << endl;
	cin >> men2;
	return men2;
}


int main() {
	ofstream Escritura;
	ifstream lectura;
	Archivos* archivo = new Archivos();
	int m;
	int n;
	do
	{
		m = menu();
		
		switch (m)
		{
		case 1:archivo->agregarUsuario(Escritura); break;
		case 2:archivo->verUsuarios(lectura); break;
		case 3:archivo->Buscarusuario(lectura); break;
		case 4:archivo->Editarusuario(lectura); break;
		case 5:archivo->ElimintarUsuario(lectura); break;
		case 6:archivo->escribirGrafo(Escritura); break;
		case 7:archivo->leerGrafo(lectura); break;
		case 8:
			do
			{
				system("cls");
				n = menu2();
				switch (n)
				{
				case 1:archivo->CSregistrados(Escritura); break;
				case 2:archivo->mostrarCSregistrados(lectura); break;
				case 3:menu(); break;
				}
			} while (n != 4);
		}; break;
		
	} while (m != 9);

	
	return 0;
}

