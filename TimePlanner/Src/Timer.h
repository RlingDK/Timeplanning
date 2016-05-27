/*
 * Tracker.h
 *
 *  Created on: May 26, 2016
 *      Author: rling
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "Period.h"
#include "Player.h"
#include <stdio.h>
#include <unistd.h>

/**
 * Handles a single time period.
 * - At the moment it only prints out what type of time period it is running.
 */
class Timer {
	Player player;

	/** Method to update and display period data) */
	void showPeriod(const Period& period);

public:
	Timer();
	virtual ~Timer();

	/** Do a single period */
	bool runPeriod (Period period);

};

#endif /* TIMER_H_ */
