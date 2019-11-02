#include<iostream>
#include"Hashing.h"
#include <string>

using std::string;
using std::cout;
using std::endl;
using namespace UndavHashing;

int HashMe(string clave, int M);

/*
 * Precondicion: -
 * Postcondicion: Devuelve el valor (hash code) de @hashMe
*/
int UndavHashing::Hash(string hashMe) {
	return HashMe(hashMe, 80000);
}

int HashMe(string clave, int M) {
	int hashValue = 0, a = 127;
	for (int i = 0; clave[i] != '\0'; ++i) {
		hashValue = (a * hashValue + (int)clave[i]) % M;
	}
	return hashValue;
}
