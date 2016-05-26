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

/** This class is a container for the time periods and there chronological order (stored in member list).
 * Also this class has the next period method.
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

public:
	/**
	 * Generates the periods and stores them in member list, in chronological order.
	 */
	Plan();
	virtual ~Plan();

	/**
	 * @return the next period.
	 * @arg OldPeriodEnded:
	 * - true if current time period is completed.
	 * - false if current time period failed
	 */
	Period nextPeriod(bool OldPeriodCompleted);

	/** Returns the full list of time periods for the plan */
	const std::vector<Period>& getList() const {
		return list;
	}
};

#endif /* PLAN_H_ */
