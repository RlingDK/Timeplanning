/*
 * Period.cpp
 *
 *  Created on: May 26, 2016
 *      Author: rling
 */

#include "Period.h"

Period::Period() {}

Period::Period(int len, TYPE typ, int snd) {
	if(!setLength(len)) setLength(minLength);	// Force length to minimum length
	setType(typ);
	setSound(snd);
}

Period::~Period() {}

