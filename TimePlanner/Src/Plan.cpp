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
	Period periodF(0, fail, 0);		// The special plan failed indicator
	Period period1(5, work, 0);
	Period period2(5, relax, 0);
	Period period3(10, work, 0);
	Period period4(5, relax, 0);
	Period periodE(0, end, 0);		// The special plan completed indicator

	// Inserting the time periods into the plan list
	list.push_back(periodF);
	list.push_back(period1);
	list.push_back(period2);
	list.push_back(period3);
	list.push_back(period4);
	list.push_back(periodE);

	// Indicate that the plan is ready. Pos = 0 -> Plan failed
	curPos = 1;
}

Plan::~Plan() {}

/**
 * If failing the same time period twice the plan goes back one step (returning the previous period)
 * If the plan goes back to time period 0 the Fail plan indicator is returned
 *
 * If a time period is completed, the plan goes forward one step (returning the next period)
 * If the plan goes forward to the End period, this period is returned (to the tracker)
 */
Period Plan::nextPeriod(bool OldPeriodCompleted) {
// TODO Implement after Period class has been implemented
	if( curPos == -1) {
		// Throw a trying to run the plan too early (plan not ready)
	}
	if(OldPeriodCompleted) {	// Last time period completed, failure forgotten and on to the next period
		twiceInRow = false;
		return list.at(++curPos);
	} else {					// Last time period failed.
		if(!twiceInRow) {		// Give a chance more this period
			twiceInRow = true;
			return list.at(curPos);
		} else {				// Period failed twice, go back to previous period
			twiceInRow = false;
			return list.at(--curPos);
		}
	}
}


