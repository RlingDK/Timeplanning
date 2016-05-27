/*
 * Player.h
 *
 *  Created on: May 26, 2016
 *      Author: rling
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <stdio.h>
#include <unistd.h>

/**
 * This class plays a sound
 * - at the moment it only prints out the sound id on screen
 */
class Player {
public:
	Player();
	virtual ~Player();

	/**
	 * Play sound
	 */
	void play(int sound);
};

#endif /* PLAYER_H_ */
