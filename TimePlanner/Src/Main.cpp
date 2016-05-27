/*
 * Main.cpp
 *
 *  Created on: May 26, 2016
 *      Author: rling
 */

#include "Plan.h"
#include "Timer.h"
#include <stdio.h>

/**
 * Main loop of the application. Loops through the time plan, one period at the time
 */
int main(int argc, char ** argv) {

	Plan plan;	// The plan. In version 2 users may choose
	if(!plan.sanityCheck()) { // Check the sanity of the plan
		printf("Plan failed sanity check. The structure of the plan is invalid. Check period time length (minimum 10 sec.)");
		return 0; // TODO Handle exceptions from the sanity check
	}
	Timer time; // Handler for each period
	Period period = plan.getList().at(plan.getCurPos()); // Points to the first element in the plan (if the plan is "reset").
	Player player; // Sound player

	do {	// Loop through the plan until the end is reached of the plan has failed
		bool result = time.runPeriod(period); // Handle a time period - returns true only period was completed
		period = plan.nextPeriod(result);     // Find the right period using the implemented rules
	} while (period.getType() != fail && period.getType() != end);

	// Handle the end result : either plan failed or plan completed successfully.
	// - period points to the resulting time period
	player.play(period.getSound());
	if(period.getType() == fail) printf("Plan failed");
	else printf("Plan completed");
}


