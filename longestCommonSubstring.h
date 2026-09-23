/*
Descripción: Búsqueda del substring común más largo con programación dinámica.
Autores: Lucca Traslosheros Abascal A01713944 y Oscar Lopez Cardoso A01713355
Responsable principal: Lucca Traslosheros Abascal
Fecha: 21/09/2026
*/

#ifndef LONGEST_COMMON_SUBSTRING_H
#define LONGEST_COMMON_SUBSTRING_H

#include <algorithm>
#include <string>
#include <utility>
#include <vector>

// Busca el primer substring común máximo. Recibe dos textos y regresa el rango en el primero.
std::pair<int, int> longestCommonSubstring(const std::string& first,
	const std::string& second) {
	std::vector<int> previous(second.length() + 1, 0);
	std::vector<int> current(second.length() + 1, 0);
	int bestStart = 0;
	int bestLength = 0;

	for (int firstIndex = 1; firstIndex <= first.length(); firstIndex++) {
		std::fill(current.begin(), current.end(), 0);
		for (int secondIndex = 1; secondIndex <= second.length(); secondIndex++) {
			if (first[firstIndex - 1] == second[secondIndex - 1]) {
				current[secondIndex] = previous[secondIndex - 1] + 1;
				int start = firstIndex - current[secondIndex];
				if (current[secondIndex] > bestLength ||
					(current[secondIndex] == bestLength && start < bestStart)) {
					bestStart = start;
					bestLength = current[secondIndex];
				}
			}
		}
		previous.swap(current);
	}
	return {bestStart, bestStart + bestLength - 1};
}

#endif
