#include <gtest/gtest.h>
#include "schelling_naive.hpp"

TEST(GridTest, GridInitDefaultTest) {
	uint8_t nb_empty = 0, nb_A = 0, nb_B = 0, size = 10;
	std::vector<uint8_t> grid = init_grid(size);

	for(int i = 0; i < size*size; ++i) {
		if(grid[i]==0) {
			++nb_empty;
		} else if (grid[i]==1) {
			++nb_A;
		} else {
			++nb_B;
		}
	}

	EXPECT_EQ(grid.size(), size*size);
	EXPECT_EQ(nb_empty, 10);
	EXPECT_EQ(nb_A, 45);
	EXPECT_EQ(nb_B, 45);
}

TEST(GridTest, GridInitWithArgsTest) {
	uint8_t nb_empty = 0, nb_A = 0, nb_B = 0, size = 10;
	std::vector<uint8_t> grid = init_grid(size, 50, 30, 10);

	for(int i = 0; i < size*size; ++i) {
		if(grid[i]==0) {
			++nb_empty;
		} else if (grid[i]==1) {
			++nb_A;
		} else {
			++nb_B;
		}
	}

	EXPECT_EQ(grid.size(), size*size);
	EXPECT_EQ(nb_empty, 50);
	EXPECT_EQ(nb_A, 15);
	EXPECT_EQ(nb_B, 35);
}
