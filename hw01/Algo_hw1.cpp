//============================================================================
// Name        : Algo_hw1.cpp
// Author      : Semen Martynov
// Version     : 0.1
// Copyright   : The MIT license
// Description : Solution for the problem 1028 'Stars' from timus.ru
//               (http://acm.timus.ru/problem.aspx?space=1&num=1028)
//============================================================================

#include <cstdlib>
#include <cstring>
#include <iostream>

static const int STARTNUMBER = 15000;

struct Star {
	int x_;
	int y_;
};

static int levels[STARTNUMBER];
static Star stars[STARTNUMBER];

int main(void) {
	// Clean levels array
	std::memset(levels, 0, sizeof(int) * STARTNUMBER);

	// Get stars and calculate levels
	int size;
	std::cin >> size;
	for (int i = 0; i != size; ++i) {
		std::cin >> stars[i].x_;
		std::cin >> stars[i].y_;

		int current_level = 0;
		for(int j = 0; j <= i; j++)
			if (stars[j].x_ <= stars[i].x_)
				++current_level;
		++levels[current_level-1];
	}

	//show levels
	for(int i = 0; i != size; ++i)
		std::cout << levels[i] << std::endl;

	return EXIT_SUCCESS;
}
