/*
 * Tracker.cpp
 *
 *  Created on: May 26, 2016
 *      Author: rling
 */

#include "Timer.h"

Timer::Timer() {}

Timer::~Timer() {}

/** Update the shown data on screen */
void Timer::showPeriod(const Period& period) {
	// TODO When Gui is implemented, this will keep the user updated
	printf("Running type no. %i.\n", period.getType()); // Just prints to the screen for now
}

/**
 * Handles each time period
 * 1) Show period data
 * 2) Play period sound
 * 3) Wait for period to complete or fail
 */
bool Timer::runPeriod(Period period) {
	showPeriod(period);
	player.play(period.getSound());
	int time = period.getLength();
	time /= 60;		// To reduce simulation time - TODO remove before release
	// TODO Should fork out to a keep the users informed method (showPeriod).
	sleep(time);
	return true;
}
