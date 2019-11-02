#include<iostream>
#include"Key.h"
#include"Hashing.h"

using std::cout;
using std::endl;
using UndavKey::Key;
using namespace UndavHashing;



struct UndavKey::Key {
	string domainName;
};


/*
 * Precondicion: -
 * Postcondicion: Devuelve una instancia valida de Key de tipo string
 */
Key* UndavKey::Create(string key) {
	Key* NuevaKey = new Key;
	NuevaKey->domainName = key;
	return NuevaKey;

}

/*
 * Precondicion: -
 * Postcondicion: Devuelve el valor de key
 */

string UndavKey::Get(const Key* key) {
	return key->domainName;
}

/*
 * Precondicion: -
 * Postcondicion: Devuelve el valor (hash code) de @key
 */

int UndavKey::GetHash(const Key* key) {
	return UndavHashing::Hash(key->domainName);
}

/*
 * Precondicion: keyA y keyB son instancias validas
 * Postcondioin: Devuleve true si KeyA y KeyB son iguales. Caso contrario devuelve false
 */
bool UndavKey::AreEquals(const Key* keyA, const Key* keyB) {
	return (UndavHashing::Hash(keyA->domainName) == UndavHashing::Hash(keyB->domainName));

}

/*
 * Precondicion: @keyA y @keyB son instancias validas
 * Postcondioin: Devuleve true si KeyA es menor que  Keyb. Caso contrario devuelve false
 */

bool UndavKey::IsLess(const Key* keyA, const Key* keyB) {
	return (UndavHashing::Hash(keyA->domainName) < UndavHashing::Hash(keyB->domainName));
}

/*
 * Precondicion: @key es una instancia valida
 * Postcondicion: Libera todos los recursos asociados de @key
 */

void UndavKey::Destroy(Key* key) {
	delete key;
}

