#include<iostream>
#include"Dictionary.h"
#include"Key.h"
#include"Item.h"


using std::cout;
using std::endl;
using UndavDictionary::Dictionary;
using UndavKey::Key;
using UndavItem::Item;

#define Clave Key*
#define Valor Item*


struct UndavDictionary::Dictionary {
	Clave* dominio;
	Valor* direccionIp;
	int cantidadElementos;
	int capacidad;
};

/*
 * Comienzo de firmas privadas de 'Dictionary.cpp'
*/
int GetPosition(Clave* dominio, Clave dominioBuscado,
	int indiceComienzo,
	int indiceFin);

void Agregar(Dictionary* diccionario, Clave clave, Item* valor);

void Redimensionar(Dictionary* diccionario, int capacidadNueva);

void Insertar(Dictionary* dictionary, Clave clave, Valor valor, int indice);

/*
 * Fin de firmas privadas de 'Dictionary.cpp'
*/

Dictionary* UndavDictionary::Create() {
	Dictionary* nuevoDiccionario = new Dictionary;
	nuevoDiccionario->capacidad = 10;
	nuevoDiccionario->cantidadElementos = 0;
	nuevoDiccionario->direccionIp = new Valor[nuevoDiccionario->capacidad];
	nuevoDiccionario->dominio = new Clave[nuevoDiccionario->capacidad];
	return nuevoDiccionario;
}

void UndavDictionary::Put(Dictionary* dictionary, Key* key, Item* item) {
	Agregar(dictionary, key, item);
}

void Agregar(Dictionary* diccionario, Clave clave, Item* valor) {
	int indicePosicionValor = GetPosition(
		diccionario->dominio,
		clave,
		0,
		diccionario->cantidadElementos
	);

	if (indicePosicionValor > 0 && diccionario->dominio[indicePosicionValor] == clave) {
		diccionario->direccionIp[indicePosicionValor] = valor;
	}
	else {
		if (diccionario->capacidad == diccionario->cantidadElementos) {
			Redimensionar(diccionario, diccionario->capacidad * 2);
		}
		//insertarlo
		Insertar(diccionario, clave, valor, indicePosicionValor);
	}
}

void Redimensionar(Dictionary* diccionario, int capacidadNueva) {
	Clave* nuevasClaves = new Clave[capacidadNueva];
	Valor* nuevosValores = new Valor[capacidadNueva];

	for (int i = 0; i < diccionario->cantidadElementos; i++) {
		nuevasClaves[i] = diccionario->dominio[i];
		nuevosValores[i] = diccionario->direccionIp[i];
	}

	delete[] diccionario->direccionIp;
	delete[] diccionario->dominio;

	diccionario->dominio = nuevasClaves;
	diccionario->direccionIp = nuevosValores;
	diccionario->capacidad = capacidadNueva;
}

Item* UndavDictionary::Get(const Dictionary* dictionary, Key* key) {
	Item* valor = NULL;
	int indicePosicionValor = GetPosition(
		dictionary->dominio,
		key,
		0,
		dictionary->cantidadElementos - 1
	);

	if (dictionary->dominio[indicePosicionValor] == key) {
		valor = dictionary->direccionIp[indicePosicionValor];
	}

	return valor;

}

bool UndavDictionary::Contains(const Dictionary* dictionary, Key* key) {
	int indicePosicionValor = GetPosition(
		dictionary->dominio,
		key,
		0,
		dictionary->cantidadElementos - 1
	);
	return dictionary->dominio[indicePosicionValor] == key;
}

bool UndavDictionary::IsEmpty(const Dictionary* dictionary) {
	return dictionary->cantidadElementos == 0;
}

int UndavDictionary::Count(const Dictionary* dictionary) {
	return dictionary->cantidadElementos;
}

void UndavDictionary::Destroy(Dictionary* dictionary) {
	delete dictionary;
}

void Insertar(Dictionary* dictionary, Clave clave, Valor valor, int indice) {
	if (dictionary == NULL) {
		UndavDictionary::Create();
	}

	for (int i = 0; i < dictionary->cantidadElementos; i++) {
		if (UndavKey::AreEquals(dictionary->dominio[i], clave)) {
			dictionary->direccionIp[i] = valor;
		}
	}
	dictionary->cantidadElementos = dictionary->cantidadElementos + 1;
	dictionary->direccionIp[indice] = valor;
	dictionary->dominio[indice] = clave;
}

int GetPosition(Clave* dominio, Clave dominioBuscado, int indiceComienzo, int indiceFin)
{
	while (indiceComienzo <= indiceFin) {
		int indiceMitad = indiceComienzo + ((indiceFin - indiceComienzo) / 2);
		if (dominio[indiceMitad] == dominioBuscado) {
			return indiceMitad;
		}
		else {
			if (dominioBuscado < dominio[indiceMitad]) {
				indiceFin = indiceMitad - 1;
			}
			else {
				indiceComienzo = indiceMitad + 1;
			}
		}
	}

	return indiceComienzo;
}
