#ifndef KEY_H_
#define KEY_H_

#include <string>
using std::string;

namespace UndavKey {
	struct Key;

	/*
	 * Precondicion: -
	 * Postcondicion: Devuelve una instancia valida de Key de tipo string
	 */
	Key* Create(string key);

	/*
	 * Precondicion: -
	 * Postcondicion: Devuelve el valor de key
	 */
	string Get(const Key* key);

	/*
	 * Precondicion: -
	 * Postcondicion: Devuelve el valor (hash code) de @key
	 */
	int GetHash(const Key* key);

	/*
	 * Precondicion: keyA y keyB son instancias validas
	 * Postcondioin: Devuleve true si KeyA y KeyB son iguales. Caso contrario devuelve false
	 */
	bool AreEquals(const Key* keyA, const Key* keyB);

	/*
	 * Precondicion: @keyA y @keyB son instancias validas
	 * Postcondioin: Devuleve true si KeyA es menos a KeyB. Caso contrario devuelve false
	 */
	bool IsLess(const Key* keyA, const Key* keyB);

	/*
	 * Precondicion: @key es una instancia valida
	 * Postcondicion: Libera todos los recursos asociados de @key
	 */
	void Destroy(Key* key);
}

#endif
