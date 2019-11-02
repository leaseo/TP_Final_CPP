#include <iostream>
#include "Key.h"
#include "Hashing.h"
#include "Dictionary.h"
#include "Item.h"

using std::cout;
using std::endl;
using UndavKey::Key;
using UndavItem::Item;
using UndavDictionary::Dictionary;
using UndavHashing::Hash;

const int CantidadEntradas = 5;

Dictionary* CrearDiccionario(Key* claves[], Item* valores[]);
void MostrarEntradaDNS(Dictionary* tablaDns, Key* dominio);
void Destruir(Key* dominios[CantidadEntradas], Item* valores[CantidadEntradas]);

int main() {
	Key* dominios[CantidadEntradas] = {
			UndavKey::Create("www.undav.edu.ar"),
			UndavKey::Create("www.git.kernel.org"),
			UndavKey::Create("www.twitter.com"),
			UndavKey::Create("www.google.com"),
			UndavKey::Create("www.twitter.com") };

	Item* direccionesIp[CantidadEntradas] = {
			UndavItem::Create("18.216.74.20"),
			UndavItem::Create("147.75.58.133"),
			UndavItem::Create("1.1.1.1"),
			UndavItem::Create("216.58.222.36"),
			UndavItem::Create("104.244.42.129") };
	Key* dominioNoRegistrado = UndavKey::Create("www.ayp1.edu.ar");
	Dictionary* tablaDNS = CrearDiccionario(dominios, direccionesIp);

	cout << "Esta es la salida esperada\nLo unico diferente que deberian tener son los codigos de hashing\n\n";
	MostrarEntradaDNS(tablaDNS, dominios[0]);
	MostrarEntradaDNS(tablaDNS, dominios[1]);
	MostrarEntradaDNS(tablaDNS, dominios[3]);
	MostrarEntradaDNS(tablaDNS, dominios[4]);
	MostrarEntradaDNS(tablaDNS, dominios[2]);
	MostrarEntradaDNS(tablaDNS, dominioNoRegistrado);

	Destroy(tablaDNS);
	Destruir(dominios, direccionesIp);
	UndavKey::Destroy(dominioNoRegistrado);

	return 0;
}

void MostrarEntradaDNS(Dictionary* tablaDns, Key* dominio) {
	Item* direccionIp = UndavDictionary::Get(tablaDns, dominio);
	if (direccionIp != NULL) {
		cout << "[" << UndavKey::Get(dominio) << "] -> [" << UndavItem::Get(direccionIp) << "], hash(dominio) -> [" << UndavKey::GetHash(dominio) << "], hash(ip) -> [" << UndavHashing::Hash(UndavItem::Get(direccionIp)) << "]" << endl;
	}
	else {
		cout << "[" << UndavKey::Get(dominio) << "] -> [NULL], hash(dominio) -> [" << UndavKey::GetHash(dominio) << "]" << endl;
	}
}

Dictionary* CrearDiccionario(Key* claves[], Item* valores[]) {
	Dictionary* diccionario = UndavDictionary::Create();
	for (int i = 0; i < CantidadEntradas; ++i) {
		Put(diccionario, claves[i], valores[i]);
	}

	return diccionario;
}

void Destruir(Key* dominios[CantidadEntradas], Item* valores[CantidadEntradas]) {
	for (int i = 0; i < 2; ++i) {
		UndavKey::Destroy(dominios[i]);
		UndavItem::Destroy(valores[i]);
	}
}
