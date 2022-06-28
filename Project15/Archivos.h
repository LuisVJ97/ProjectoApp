#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <Windows.h>
#include "Arreglo.h"
#include "Grafos.h"
using namespace std;
class Archivos
{
public:
	void agregarUsuario(ofstream& archivo) {
		system("cls");
		cout << "Digite el destino a que se va dirigir : ";
		cin >> nameapp;
		archivo.open(nameapp.c_str(), ios::out | ios::app);
		cout << "Codigo de seguridad: " << endl;
		codigoS = rand() % 100 + 1;
		cout << codigoS << endl;
		cout << "Agregar el nombre del usuario" << endl;
		cin >> nombre;
		cout << "Agregar el apellido del usuario" << endl;
		cin >> apellido;
		cout << "Agregar DNI: " << endl;
		cin >> codigo;
		cout << "Agregar edad: " << endl;
		cin >> edad;
		cout << "Agregar distrito de residencia: " << endl;
		cin >> ruta;

        archivo << nombre << " " << apellido << " " << codigo << " " << edad << " " << ruta << " "<< codigoS<<"\n";
		archivo.close();
	}
	void verUsuarios(ifstream& archivo) {
		system("cls");
		cout << "Digite el destino que desea visualizar: ";
		cin >> nameapp;
		archivo.open(nameapp.c_str(), ios::in);
		cout << "\nUsuarios Registrados:" << endl;
		archivo >> nombre;
		while (!archivo.eof())
		{
			archivo >> apellido;
			archivo >> codigo;
			archivo >> edad;
			archivo >> ruta;
			archivo >> codigoS;
			cout << "Nombre-----:" << nombre << endl;
			cout << "Apellido---:" << apellido << endl;
			cout << "Codigo-----:" << codigo << endl;
			cout << "Edad-----:" << edad << endl;
			cout << "Ruta de desplazaciamiento-----:" << ruta << endl;
			cout << "Codigo de seguridad-----------: "<<codigoS<<endl;
			cout << "****************************************************" << endl;
			archivo >> nombre;

		}

		archivo.close();
		system("pause");
	}
	void Buscarusuario(ifstream& archivo) {
		system("cls");
		cout << "Digite la ruta en .txt para buscar el usuario: ";
		cin >> nameapp;
		archivo.open(nameapp.c_str(), ios::in);
		bool usuarioencontrado = false;
		cout << "Digite el codigo que desea buscar" << endl;
		cin >> codigoaux;
		archivo >> nombre;
		while (!archivo.eof() && !usuarioencontrado)
		{
			archivo >> apellido;
			archivo >> codigo;
			if (codigo == codigoaux)
			{
				cout << "Nombre-----:" << nombre << endl;
				cout << "Apellido---:" << apellido << endl;
				cout << "Codigo-----:" << codigo << endl;
				cout << "Edad-------:" << edad << endl;
				cout << "Ruta de desplazaciamiento-----:" << ruta << endl;
				cout << "Codigo de seguridad-----------:" << codigoS << endl;
				cout << "****************************************************" << endl;
				usuarioencontrado = true;
			}
			archivo >> nombre;
		}
		archivo.close();
		if (!usuarioencontrado)
		{
			cout << "*****El usuario que desea encontrar no existe o no esta registrado*****" << endl;

		}
		system("pause");
	}
	void Editarusuario(ifstream& archivo) {
		system("cls");
		cout << "Digite la ruta en .txt para editar el nombre de usuario: ";
		cin >> nameapp;
		archivo.open(nameapp.c_str(), ios::in);
		ofstream archivoaux("datosauxiliar.txt", ios::out);
		if (archivo.is_open())
		{
			cout << "\nDigite el DNI del usuario: ";
			cin >> codigoaux;
			archivo >> nombre;
			while (!archivo.eof())
			{
				archivo >> apellido;
				archivo >> codigo;
				if (codigo == codigoaux)
				{
					cout << "Digite el nuevo Nombre: " << endl;
					cin >> nombreaux;
					archivoaux << nombreaux << " " << apellido << " " << codigo << edad << " " << ruta << " " << codigoS << "\n";
				}
				else {
					archivoaux << nombre << " " << apellido << " " << codigo << edad << " " << ruta << " " << codigoS << "\n";
				}
				archivo >> nombre;
			}
			archivo.close();
			archivoaux.close();
		}
		remove(nameapp.c_str());
		rename("datosauxiliar.txt", nameapp.c_str());
	}
	void ElimintarUsuario(ifstream& archivo) {
		system("cls");
		cout << "Digite la App en .txt para eliminar el usuario: ";
		cin >> nameapp;
		archivo.open(nameapp.c_str(), ios::in);
		ofstream archivoaux("datosauxiliar.txt", ios::out);
		if (archivo.is_open())
		{
			cout << "\nDigite el DNI del usuario: ";
			cin >> codigoaux;
			archivo >> nombre;
			while (!archivo.eof())
			{
				archivo >> apellido;
				archivo >> codigo;
				if (codigo == codigoaux)
				{
					cout << "El usuario ha sido eliminado " << endl;
					system("pause");

				}
				else {
					archivoaux << nombre << " " << apellido << " " << codigo << edad << " " << ruta <<" " << codigoS<< "\n";
				}
				archivo >> nombre;
			}
			archivo.close();
			archivoaux.close();
		}
		remove(nameapp.c_str());
		rename("datosauxiliar.txt", nameapp.c_str());
	}

	void CSregistrados(ofstream& archivo) {
		system("cls");
		vector<int>numb; 
		Arbol<int>* arbol = new Arbol<int>();
		int num;
		archivo.open("codigos.txt", ios::in | ios::app);
		cout << "Ingrese cuantos codigo va digitar: " << endl;
		cin>>num;
		cout << "Ingrese los codigos" << endl;
		for (int i = 0; i < num; i++)
		{
			cin >> data;
			arbol->insertarArbol(data, arbol->raiz);
			numb.push_back(data);
			archivo << data<< " ";
		}
		cout << "Codigos de registro guardados exitosamente";
		archivo.close();
		system("pause");
	}

	void mostrarCSregistrados(ifstream& archivo) {
		system("cls");
		vector<int>numb;
		Arbol<int>* arbol = new Arbol<int>();
		archivo.open("codigos.txt", ios::in | ios::app);
		cout << "Cantidad de datos almanecados: " << endl;
		cout << numb.size()<<endl;
		cout << "Codigos ordenados:" <<endl;
		while (!archivo.eof())
		{
			while (archivo >> data)
			{
				numb.push_back(data);
			}

			for (int i =0; i< numb.size(); i++)
			{
				arbol->enOrdenA(arbol->raiz);
				cout << " " << numb[i];

			}
		}
		cout << endl;
		archivo.close();
		system("pause");
	}
	void escribirGrafo(ofstream& archivo) {
		system("cls");
		int selec;
		int ruta = 0;
		int viajes = 0;
		CGrafo<int>* G = new CGrafo<int>();
		archivo.open("grafos.txt", ios::in | ios::app);
		cout << "Ingrese el numero en donde estas ubicado: " << endl;
		cout << "1.- CHORRILLOS" << endl;
		cout << "2.- SURCO     " << endl;
		cout << "3.- BARRANCO  " << endl;
		cout << "4.- MIRAFLORES" << endl;
		cout << "5.- SAN ISIDRO" << endl;
		cout << "6.- Salir" << endl;
		cout << "Opcion - ";
		cin >> selec;
		cout << endl;

		switch (selec)
		{
		case 1: 
			do
			{
				G->adicionarVertice(selec);
				cout << "Seleccione la ruta que va a viajar : " << endl;
				cout << "2.- SURCO     " << endl;
				cout << "3.- BARRANCO  " << endl;
				cout << "4.- MIRAFLORES" << endl;
				cout << "5.- SAN ISIDRO" << endl;
				cout << "Opcion - ";
				cin >> ruta;
				cout << endl;
			} while (ruta == 0);
			if (ruta == 2)
			{
				G->adicionarArco(0,ruta);
				G->modificarArco(0,1,10);
				cout << "El viaje cuesta 10 soles" << endl;
			}
			if (ruta==3)
			{
				G->adicionarArco(0, ruta);
				G->modificarArco(0,3,15);
				cout << "El viaje cuesta 15 soles" << endl;
			}
			if (ruta == 4)
			{
				G->adicionarArco(0, ruta);
				G->modificarArco(0, 4, 18);
				cout << "El viaje cuesta 18 soles" << endl;
			}
			if (ruta == 5)
			{
				G->adicionarArco(0, ruta);
				G->modificarArco(0, 5, 20);
				cout << "El viaje cuesta 20 soles" << endl;
			};
			break;
		case 2:
			do
			{
				G->adicionarVertice(selec);
				cout << "Seleccione la ruta que va a viajar : " << endl;
				cout << "1.- CHORRILLOS" << endl;
				cout << "3.- BARRANCO  " << endl;
				cout << "4.- MIRAFLORES" << endl;
				cout << "5.- SAN ISIDRO" << endl;
				cout << "Opcion - ";
				cin >> ruta;
				cout << endl;
			} while (ruta == 0);
			if (ruta == 1)
			{
				G->adicionarArco(1,ruta);
				G->modificarArco(1, 1, 10);
				cout << "El viaje cuesta 10 soles" << endl;
			}
			if (ruta == 3)
			{
				G->adicionarArco(1, ruta);
				G->modificarArco(1, 3, 12);
				cout << "El viaje cuesta 12 soles" << endl;
			}
			if (ruta == 4)
			{
				G->adicionarArco(1, ruta);
				G->modificarArco(1, 4, 17);
				cout << "El viaje cuesta 17 soles" << endl;
			}
			if (ruta == 5)
			{
				G->adicionarArco(1, ruta);
				G->modificarArco(1, 5, 20);
				cout << "El viaje cuesta 20 soles" << endl;
			};
			break;
		case 3:
			do
			{
				G->adicionarVertice(selec);
				cout << "Seleccione la ruta que va a viajar : " << endl;
				cout << "1.- CHORRILLOS" << endl;
				cout << "2.- SURCO     " << endl;
				cout << "4.- MIRAFLORES" << endl;
				cout << "5.- SAN ISIDRO" << endl;
				cout << "Opcion - ";
				cin >> ruta;
				cout << endl;
			} while (ruta == 0);
			if (ruta == 1)
			{
				G->adicionarArco(2, ruta);
				G->modificarArco(2, 1, 15);
				cout << "El viaje cuesta 15 soles" << endl;
			}
			if (ruta == 2)
			{
				G->adicionarArco(2, ruta);
				G->modificarArco(2, 2, 12);
				cout << "El viaje cuesta 12 soles" << endl;
			}
			if (ruta == 4)
			{
				G->adicionarArco(2, ruta);
				G->modificarArco(2, 4, 22);
				cout << "El viaje cuesta 22 soles" << endl;
			}
			if (ruta == 5)
			{
				G->adicionarArco(2, ruta);
				G->modificarArco(2, 5, 20);
				cout << "El viaje cuesta 20 soles" << endl;
			};
			break;
		case 4:
			do
			{
				G->adicionarVertice(selec);
				cout << "Seleccione la ruta que va a viajar : " << endl;
				cout << "1.- CHORRILLOS" << endl;
				cout << "2.- SURCO     " << endl;
				cout << "3.- BARRANCO  " << endl;
				cout << "5.- SAN ISIDRO" << endl;
				cout << "Opcion - ";
				cin >> ruta;
				cout << endl;
			} while (ruta == 0);
			if (ruta == 1)
			{
				G->adicionarArco(3, ruta);
				G->modificarArco(3, 1, 10);
				cout << "El viaje cuesta 10 soles" << endl;
			}
			if (ruta == 2)
			{
				G->adicionarArco(3, ruta);
				G->modificarArco(3, 2, 15);
				cout << "El viaje cuesta 15 soles" << endl;
			}
			if (ruta == 3)
			{
				G->adicionarArco(3, ruta);
				G->modificarArco(3, 3, 20);
				cout << "El viaje cuesta 20 soles" << endl;
			}
			if (ruta == 5)
			{
				G->adicionarArco(3, ruta);
				G->modificarArco(3, 5, 18);
				cout << "El viaje cuesta 18 soles" << endl;
			};
			break;
		case 5:
			do
			{
				G->adicionarVertice(selec);
				cout << "Seleccione la ruta que va a viajar : " << endl;
				cout << "1.- CHORRILLOS" << endl;
				cout << "2.- SURCO     " << endl;
				cout << "3.- BARRANCO  " << endl;
				cout << "4.- MIRAFLORES" << endl;
				cout << "Opcion - ";
				cin >> ruta;
				cout << endl;
			} while (ruta == 0);
			if (ruta == 1)
			{
				G->adicionarArco(4, ruta);
				G->modificarArco(4, 1, 10);
				cout << "El viaje cuesta 10 soles" << endl;
			}
			if (ruta == 2)
			{
				G->adicionarArco(4, ruta);
				G->modificarArco(4, 2, 15);
				cout << "El viaje cuesta 15 soles" << endl;
			}
			if (ruta == 3)
			{
				G->adicionarArco(4, ruta);
				G->modificarArco(4, 3, 20);
				cout << "El viaje cuesta 20 soles" << endl;
			}
			if (ruta == 4)
			{
				G->adicionarArco(4, ruta);
				G->modificarArco(4, 4, 10);
				cout << "El viaje cuesta 10 soles" << endl;
			}; break;
		case 6:
			break;
		}
		for (int i = 0; i < G->cantidadVertices(); ++i) {
			cout << "Origen : " << G->obtenerVertice(i) << endl;
			for (int j = 0; j < G->cantidadArcos(i); j++)
			{
				cout << "Destino :" << G->obtenerArco(i, j) << " ";
			}
			cout << endl;
		}
		archivo << " "<< selec <<" "<< ruta <<" "<< viajes << "\n";
		archivo.close();
		system("pause");
	}
	void leerGrafo(ifstream& archivo) {
		system("cls");
		int selec;
		int ruta;
		int viajes;
		CGrafo<int>* G = new CGrafo<int>();
		archivo.open("grafos.txt", ios::in | ios::app);
		cout << "\nCalculo Registrados:" << endl;
		archivo >> selec;
		while (!archivo.eof())
		{
			archivo >> ruta;
			archivo >> viajes;
			cout << "Origen  :" <<selec<< endl;
			cout << "Destino :" << ruta << endl;
			cout << "Precio  :" << viajes << endl;
		}
		archivo >> selec;
		archivo.close();
		system("pause");
	}
private:
	string nombre, apellido, nombreaux, codigo, codigoaux, edad, ruta, nameapp;
	int codigoS, data;
};



