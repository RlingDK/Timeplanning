/*
 * Period.h
 *
 *  Created on: May 26, 2016
 *      Author: rling
 */

#ifndef PERIOD_H_
#define PERIOD_H_

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
	/** Length of the time period (in seconds) */
	int length;
	/** The type of activity for the time period */
	TYPE type;
	/** The sound played for the user, to indicate that this time period has started */
	int sound;

public:
	Period();
	/** Flexible in-line constructor */
	Period(int len=0, TYPE typ=work, int snd = 0):length(len), type(typ), sound(snd) {}
	virtual ~Period();

// ------------------------------------------------- Get & set for all members

	int getLength() const {
		return length;
	}

	void setLength(int length) {
		this->length = length;
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
};

#endif /* PERIOD_H_ */
