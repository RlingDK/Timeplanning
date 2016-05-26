/*
 * Tracker.h
 *
 *  Created on: May 26, 2016
 *      Author: rling
 */

#ifndef TRACKER_H_
#define TRACKER_H_

#include "Plan.h"

/**
 * The Tracker keeps track of time (one time period at time) and also acts as a controller for the hold application.
 * Tracker should be uniq. Tracker sets up all the other main classes and holds the main function for the whole application.
 * At the moment the Tracker class only holds one Plan instance, but in later versions there should be an array/vector of planes for the use to choose from.
 */
class Tracker {
public:
	Tracker();
	virtual ~Tracker();

	/** Do a single period */
	bool runPeriod (Period period);

	/**
	 * The (chosen) plan that the application will run through.
	 */
	Plan plan;
};

#endif /* TRACKER_H_ */
