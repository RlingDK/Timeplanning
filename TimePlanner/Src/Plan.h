/*
 * Plan.h
 *
 *  Created on: May 26, 2016
 *      Author: rling
 */

#ifndef PLAN_H_
#define PLAN_H_

#include <vector>
#include "Period.h"
#include <stdio.h>


/** This class is a container for the time periods and there chronological order (stored in member list).
 * Also this class has the next period  and plan sanity checker methods.
 */

class Plan {

	/**
	 * The chronological list of time periods.
	 */
	std::vector <Period> list;

	/**
	 *  The current position of the plan
	 *  - Indicating which period is running at the moment
	 *
	 *  -1 : Plan not started yet
	 *  0  : Plan failed
	 *  1  : First time period
	 *  2  : Second time period
	 *  ...
	 */
	int curPos = -1;

	/**
	 * Indicator for failing at a time period twice in row
	 */
	bool twiceInRow = false;

	/**
	 * The max seconds to be used in the plan. Application will stop if maximum is reached
	 * - It is only the successful periods that will be counted
	 */
	int maxTimeUseage = 120 * 60;

	/**
	 * Count showing how much time has been used (on completed periods) on this plan until now
	 */
	int timeUsage = 0;

	/**
	 * Counting used time and checking if max time use is reached
	 */
	bool timeUsed();

public:
	/**
	 * Not an empty constructor implementation
	 * Generates the periods and stores them in member list, in chronological order.
	 */
	Plan();
	virtual ~Plan();

	/**
	 * Used to "step" intelligent through the plan one period at time
	 *
	 * @return the next period.
	 * @arg OldPeriodEnded:
	 * - true if current time period is completed.
	 * - false if current time period failed
	 */
	Period nextPeriod(bool OldPeriodCompleted);

	/**
	 * Makes a sanity check for the plan
	 * checks:
	 * - Start and end elements
	 * - Length of period (minimum 10 seconds)
	 *
	 * @return result from check
	 * True  : all checks passed
	 * False : a check failed
	 */
	bool sanityCheck();

// ---------------------------------------------------------------- getter / setter

	/** Returns the full list of time periods for the plan */
	const std::vector<Period>& getList() const {
		return list;
	}

	int getCurPos() const {
		return curPos;
	}


};

#endif /* PLAN_H_ */
