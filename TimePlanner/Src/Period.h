/*
 * Period.h
 *
 *  Created on: May 26, 2016
 *      Author: rling
 */

#ifndef PERIOD_H_
#define PERIOD_H_

#include <stdio.h>

/**
 * Enumeration for the time period types (work and relax)
 */
enum TYPE {
	fail,	// Indicator type for when the whole plan has failed
	work,
	relax,
	end		// Indicator type for when the whole plan was completed
};

/**
 * This class represents each of the time periods in the time plan.
 */
class Period {
	/** The minimum length of a time period. */
	const static int minLength = 10;
	/** Length of the time period (in seconds) */
	int length;
	/** The type of activity for the time period e.g work or relaxation*/
	TYPE type;
	/** The sound played for the user, to indicate that the time period has started. There should be a sound for each of activity types */
	int sound;

public:
	Period();
	/** Flexible constructor*/
	Period(int len = minLength, TYPE typ=work, int snd = 0);
	virtual ~Period();

// ------------------------------------------------- Get & set for all members

	int getLength() const {
		return length;
	}

	/** Enforces the min length */
	bool setLength(int length) {	// Check length (min.)
		if(length < minLength) {
			printf("Time length too small (minimum %i sec.)\n", minLength);
			return false;
		}
		this->length = length;
		return true;
	}

	int getSound() const {
		return sound;
	}

	void setSound(int sound) {
		this->sound = sound;
	}

	TYPE getType() const {
		return type;
	}

	void setType(TYPE type) {
		this->type = type;
	}

	int getMinLength() const {
		return minLength;
	}
};

#endif /* PERIOD_H_ */
