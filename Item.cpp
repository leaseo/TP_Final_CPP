#include<iostream>
#include"Item.h"

using std::cout;
using std::endl;
using UndavItem::Item;


struct UndavItem::Item {
	string ipAddress;
};

/*
 * Precondicion: -
 * Postcondicion: Devuelve una instancia valida de Item de tipo string
*/

Item* UndavItem::Create(string item) {
	Item* NuevoItem = new Item;
	NuevoItem->ipAddress = item;
	return NuevoItem;
}

/*
 * Precondicion: -
 * Postcondicion: Devuelve el valor de item
*/

string UndavItem::Get(const Item* item) {
	return item->ipAddress;
}


/*
 * Precondicion: -
 * Postcondicion: Devuelve true si @itemA es igual a @itemB
 */
bool UndavItem::AreEquals(const Item* itemA, const Item* itemB) {
	return (itemA->ipAddress == itemB->ipAddress);
}

/*
 * Precondicion: @item es una instancia valida
 * Postcondicion: Libera todos los recursos asociados de @item
*/

void UndavItem::Destroy(Item* item) {
	delete item;
}
