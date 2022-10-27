#include "stdafx.h"
void Delay(float dSecond)
{
	clock_t goal = ((clock_t)(dSecond * CLOCKS_PER_SEC));
	goal += clock();
	while (goal >clock())
		;				
}