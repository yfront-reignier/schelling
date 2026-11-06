#include "schelling_naive.hpp"
#include <cstdint>
#include <algorithm>
#include <random>

std::vector<uint8_t> init_grid(uint8_t L, uint8_t density, uint8_t A_percent, uint8_t tolerance) {
	std::random_device rdm_dev;
	auto size = L*L;
	auto nb_agent = size * density / 100;
	auto nb_A = nb_agent * A_percent / 100;

	std::vector<uint8_t> grid(size, 0);

	for(auto i = 0; i < nb_agent; ++i) {
		if(i < nb_A) {
			grid[i] = 1;
		} else {
			grid[i] = 2;
		}
	}

	std::mt19937 gen{rdm_dev()};
	std::shuffle(grid.begin(), grid.end(),gen);

	return grid;
}
