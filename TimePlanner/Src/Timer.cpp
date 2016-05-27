/*
 * Tracker.cpp
 *
 *  Created on: May 26, 2016
 *      Author: rling
 */

#include "Timer.h"

#include <stdio.h>

Timer::Timer() {}

Timer::~Timer() {}

/**
 * Doing a simple test, where the periods never fails
 */
bool Timer::runPeriod(Period period) {
	player.play(period.getSound());
	printf("Running type no. %i.\n", period.getType());
	return true;
}
