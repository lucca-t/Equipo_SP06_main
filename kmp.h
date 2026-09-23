/*
Descripción: Búsqueda de patrones con el algoritmo KMP.
Autores: Lucca Traslosheros Abascal A01713944 y Oscar Lopez Cardoso A01713355
Responsable principal: Lucca Traslosheros Abascal
Fecha: 21/09/2026
*/

#ifndef KMP_H
#define KMP_H

#include <string>
#include <vector>

// Crea la tabla de prefijos. Recibe el patrón y regresa su tabla.
std::vector<int> prefixTable(const std::string& pattern) {
	std::vector<int> table(pattern.length(), 0);
	int matched = 0;
	for (int index = 1; index < pattern.length(); index++) {
		while (matched > 0 && pattern[index] != pattern[matched]) {
			matched = table[matched - 1];
		}
		if (pattern[index] == pattern[matched]) {
			matched++;
		}
		table[index] = matched;
	}
	return table;
}

// Busca la primera coincidencia. Recibe el texto y patrón. Regresa su posición desde cero o -1.
int kmpSearch(const std::string& text, const std::string& pattern) {
	if (pattern.empty()) {
		return -1;
	}
	std::vector<int> table = prefixTable(pattern);
	int matched = 0;
	for (int index = 0; index < text.length(); index++) {
		while (matched > 0 && text[index] != pattern[matched]) {
			matched = table[matched - 1];
		}
		if (text[index] == pattern[matched]) {
			matched++;
		}
		if (matched == pattern.length()) {
			return index - matched + 1;
		}
	}
	return -1;
}

#endif
