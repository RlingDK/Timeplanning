/*
 * Player.cpp
 *
 *  Created on: May 26, 2016
 *      Author: rling
 */

#include "Player.h"

Player::Player() {
	// TODO Find and load in all the sounds needed

}

Player::~Player() {}

/**
 * Simulation of a sound player
 */
void Player::play(int sound) {
	printf("- Playing sound no. %i\n", sound);
	sleep(2);
}
