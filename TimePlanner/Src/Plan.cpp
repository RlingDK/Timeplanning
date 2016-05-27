/*
 * Plan.cpp
 *
 *  Created on: May 26, 2016
 *      Author: rling
 */

#include "Plan.h"

/**
 * Creates a hard coded time period list.
 */
Plan::Plan() {
	// Creation the time period for the plan
	Period periodF(10, fail, 0);		// The special plan failed indicator
	Period period1(5 * 60, work, 1);
	Period period2(5 * 60, relax, 2);
	Period period3(10 * 60, work, 1);
	Period period4(5 * 60, relax, 2);
	Period periodE(10, end, 3);		// The special plan completed indicator

	// Inserting the time periods into the plan list
	list.push_back(periodF);
	list.push_back(period1);
	list.push_back(period2);
	list.push_back(period3);
	list.push_back(period4);
	list.push_back(periodE);

	// Using max. 120 minutes on running this plan
	maxTimeUseage = 120 * 60;

	// Indicate that the plan is ready. curPos = 0 -> Plan failed
	curPos = 1;
}

Plan::~Plan() {}

/**
 * Performs a sanity check for the plan
 * checking
 * - start and end
 * - period length
 * - maxTime initiated
 */
bool Plan::sanityCheck() {
	// Getting start and end data
	TYPE frontType = list.front().getType();
	TYPE backType  = list.back().getType();
	int minLength  = list.front().getMinLength(); // Just to have an instance of period (to get min. length)

	// Check that the start and end elements are either fail or end
	if(frontType!=fail && frontType!=end) {
		printf("");	// TODO Should throw an exception
		return false;
	}
	if(backType!=fail && backType!=end) {
		printf(""); // TODO Should throw an exception
		return false;
	}

	// Checking the length of all the elements in the plan
	std::vector<Period>::iterator it = list.begin();
	for(;it != list.end(); it++) {
		if(it->getLength() < minLength){
			printf(""); // TODO Should throw an exception
			return false;
		}
	}

	if(maxTimeUseage <= 0) return false;

	return true;
}

/**
 * Keeps track of the time usage
 * Return true if all the time for the time plan has been used
 */
bool Plan::timeUsed() {
	timeUsage += list.at(curPos).getLength(); // Only count completed time periods
	if(timeUsage > maxTimeUseage) return true;
	return false;
}

/**
 * If failing the same time period twice the plan goes back one step (returning the previous period)
 * If the plan goes back to time period 0 the Fail plan indicator is returned
 *
 * If a time period is completed, the plan goes forward one step (returning the next period)
 * If the plan goes forward to the End period, this period is returned (to the tracker)
 */
Period Plan::nextPeriod(bool OldPeriodCompleted) {
	if(curPos == -1) {
		// Throw a trying to run the plan too early (plan not ready)
	}
	if(OldPeriodCompleted) {	// Last time period completed, failure forgotten and on to the next period
		if(timeUsed()) return list.back(); // Use the time is all used go to the end
		twiceInRow = false;
		return list.at(++curPos); // Go to next period
	} else {					// Time period failed.
		if(!twiceInRow) {		// Give a chance more this period
			twiceInRow = true;
			return list.at(curPos);
		} else {				// Period failed twice, go back to previous period
			twiceInRow = false;
			return list.at(--curPos);
		}
	}
}


