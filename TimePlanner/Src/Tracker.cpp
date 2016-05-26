/*
 * Tracker.cpp
 *
 *  Created on: May 26, 2016
 *      Author: rling
 */

#include "Tracker.h"
#include <stdio.h>

Tracker::Tracker() {}

Tracker::~Tracker() {}

/**
 * Doing a simple test, where the periods never fails
 */
bool Tracker::runPeriod(Period period) {
	printf("Running type no. %i\n", period.getType());
	return true;
}

/**
 * Main loop of the application. Loops through the time plan, one period at the time
 */
int main(int argc, char ** argv) {

	Tracker track;
	Period period = track.plan.getList().at(1); // Points to the first element in the plan

	do {	// Loop through the plan until the end is reached of the plan has failed
		bool result = track.runPeriod(period);
		period = track.plan.nextPeriod(result);
	} while (period.getType() != fail && period.getType() != end);

	if(period.getType() == fail) printf("Plan failed");
	else printf("Plan completed");
}
