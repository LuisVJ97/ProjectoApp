#ifndef __ARREGLO_HPP__
#define __ARREGLO_HPP__
#include<iostream>
#include <string>
#include <stdlib.h>
using namespace std;
template <class T>
class Nodo {
public:
	//int valor;
	T valor;
	T data;
	Nodo* izq;
	Nodo* der;
	Nodo* next;
};

template <class T>
class Arreglo
{
public:
	Nodo<T>* raiz;
	Nodo<T>* aux;
	Nodo<T>* first;
	Nodo<T>* last;
	void(*procesar)(T);
	int tam;
	Arreglo<T>() {
		first = NULL;
		last = NULL;
	}
	T get(int index) {

		if (index == 0) {
			return this->first->data;
		}
		else {
			Nodo<T>* curr = this->first;
			for (int i = 0; i < index; ++i) {
				curr = curr->next;
			}
			return curr->data;
		}
	}
	
	void buscare () {
		aux = first;
		while (aux != NULL)
		{
			cout << " " << aux->data;
			aux = aux->next;
		}
		cout << endl;
	}


	void editare() {
		aux = first;
		while (aux != NULL) {
			cout << " " << aux->data;
			aux = aux->next;
		}
		cout << endl;
	}


	void push() {
		aux = new Nodo<T>;
		aux->data = data;
		aux->next = first;
		first = aux;
		tam++;
	}


	void agregar() {
		if (!first)
		{
			first = new Nodo<T>;
			first->data = data;
			first->next = NULL;
		}
		else {
			if (last == first) {
				last = new Nodo<T>;
				last->data = data;
				last->next = NULL;
				first->next = last;
			}
			else {
				Nodo<T>* aux = new Nodo<T>;
				aux->data = data;
				aux->next = NULL;
				last->next = aux;
				last = aux;
			}
		}tam++;
	}


	void eliminare() {
		if (first->data == data) {
			first = first->next;
		}
		else {
			Nodo<T>* aux = first;
			while (aux->next != NULL) {
				if (aux->next->data == data) {
					aux->next = aux->next->next;
				}
				else {
					aux = aux->next;
				}
			}
		}
		tam--;
	}


	void list() {
		Nodo<T>* aux = first;
		while (aux != NULL) {
			cout << " " << aux->data;
			aux = aux->next;
		}
		cout << endl;
	}


private:
	
};
template <class T>
class Arbol
{	
public:
	Nodo<T>* raiz;
	Arbol() {
		raiz = NULL;
	}
	void insertarArbol(T valor, Nodo<T>* raiz) {
		if (raiz == NULL)
		{
			Nodo<T>* nuevo = new Nodo<T>;
			nuevo->valor = valor;
			nuevo->izq = NULL;
			nuevo->der = NULL;
			raiz = nuevo;
		}
		else
		{
			if (valor < raiz->valor)
			{
				insertarArbol(valor, raiz->izq);
			}
			else if (valor > raiz->valor) {
				insertarArbol(valor, raiz->der);
			}
		}
	}
	void enOrdenA(Nodo<T>* raiz) {
		if (raiz != NULL)
		{
			enOrdenA(raiz->izq);
			cout << raiz->valor<<" ";
			enOrdenA(raiz->der);
		}
	}

private:
	
	bool vacio() {
		return raiz == NULL;
	}
};

#endif