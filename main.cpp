/*
Descripción: Analiza dos transmisiones para encontrar códigos maliciosos,
palíndromos y el substring común más largo.
Autores: Lucca Traslosheros Abascal A01713944 y Oscar Lopez Cardoso A01713355
Responsable principal: Oscar Lopez Cardoso
Fecha: 21/09/2026
*/

#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include "kmp.h"
#include "longestCommonSubstring.h"
#include "manacher.h"

using namespace std;

// Lee un archivo sin saltos de línea. Recibe su nombre y guarda el texto. Regresa si pudo abrirlo.
bool readFile(const string& filename, string& text) {
	ifstream file(filename);
	char character = '\0';
	if (!file.is_open()) {
		return false;
	}
	while (file.get(character)) {
		if (character != '\n' && character != '\r') {
			text += character;
		}
	}
	return true;
}

// Imprime un rango desde uno. Recibe posiciones desde cero y no regresa un valor.
void printRange(const pair<int, int>& range) {
	cout << range.first + 1 << " " << range.second + 1 << endl;
}

// Ejecuta el análisis completo. No recibe parámetros y regresa el estado del programa.
int main() {
	const string transmissionFiles[2] = {"transmission1.txt", "transmission2.txt"};
	const string mcodeFiles[3] = {"mcode1.txt", "mcode2.txt", "mcode3.txt"};
	string transmissions[2] = {"", ""};
	string mcodes[3] = {"", "", ""};

	for (int index = 0; index < 2; index++) {
		if (!readFile(transmissionFiles[index], transmissions[index])) {
			cout << "Error: no se pudo abrir " << transmissionFiles[index] << endl;
			return 1;
		}
	}
	for (int index = 0; index < 3; index++) {
		if (!readFile(mcodeFiles[index], mcodes[index])) {
			cout << "Error: no se pudo abrir " << mcodeFiles[index] << endl;
			return 1;
		}
	}

	cout << boolalpha;
	for (int transmission = 0; transmission < 2; transmission++) {
		for (int code = 0; code < 3; code++) {
			int position = kmpSearch(transmissions[transmission], mcodes[code]);
			cout << (position != -1);
			if (position != -1) {
				cout << " " << position + 1;
			}
			cout << endl;
		}
	}

	printRange(longestPalindrome(transmissions[0]));
	printRange(longestPalindrome(transmissions[1]));
	printRange(longestCommonSubstring(transmissions[0], transmissions[1]));
	return 0;
}
