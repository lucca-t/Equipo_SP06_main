/*
Descripción: Búsqueda del palíndromo más largo con Manacher.
Autores: Lucca Traslosheros Abascal A01713944 y Oscar Lopez Cardoso A01713355
Responsable principal: Oscar Lopez Cardoso
Fecha: 21/09/2026
*/

#ifndef MANACHER_H
#define MANACHER_H

#include <algorithm>
#include <string>
#include <utility>
#include <vector>

// Busca el primer palíndromo máximo. Recibe el texto y regresa su rango desde cero.
std::pair<int, int> longestPalindrome(const std::string& text) {
	std::string transformed = "@";
	for (char character : text) {
		transformed += '#';
		transformed += character;
	}
	transformed += "#$";
	std::vector<int> radius(transformed.length(), 0);
	int center = 0;
	int right = 0;
	int bestStart = 0;
	int bestLength = 0;

	for (int index = 1; index < transformed.length() - 1; index++) {
		int mirror = 2 * center - index;
		if (index < right) {
			radius[index] = std::min(right - index, radius[mirror]);
		}
		while (transformed[index + radius[index] + 1] ==
			transformed[index - radius[index] - 1]) {
			radius[index]++;
		}
		if (index + radius[index] > right) {
			center = index;
			right = index + radius[index];
		}
		int start = (index - radius[index]) / 2;
		if (radius[index] > bestLength ||
			(radius[index] == bestLength && start < bestStart)) {
			bestStart = start;
			bestLength = radius[index];
		}
	}
	return {bestStart, bestStart + bestLength - 1};
}

#endif
