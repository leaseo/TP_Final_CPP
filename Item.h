#ifndef ITEM_H_
#define ITEM_H_

#include <string>
using std::string;

namespace UndavItem {
	struct Item;
	/*
	 * Precondicion: -
	 * Postcondicion: Devuelve una instancia valida de Item de tipo string
	 */
	Item* Create(string item);

	/*
	 * Precondicion: -
	 * Postcondicion: Devuelve el valor de item
	 */
	string Get(const Item* item);

	/*
	 * Precondicion: -
	 * Postcondicion: Devuelve true si @itemA es igual a @itemB
	 */
	bool AreEquals(const Item* itemA, const Item* itemB);

	/*
	 * Precondicion: @item es una instancia valida
	 * Postcondicion: Libera todos los recursos asociados de @item
	 */
	void Destroy(Item* item);
}

#endif
