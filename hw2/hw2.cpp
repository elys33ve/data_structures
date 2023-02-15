#include <iostream>
#include "Wheel.h"
#include "Player.h"


//-------------------- constructors

// empty constructor
Wheel::Wheel(){						
	range_low = 1;
	range_high = 10;
}

// constructor: set range
Wheel::Wheel(int rl, int rh){
	range_low = rl;
	range_high = rh;
}


//-------------------- setters

// set lower and higher bounds for range
void Wheel::set_range(int rl, int rh){
	range_low = rl;
	range_high = rh;
}

// set number of values on wheel
void Wheel::set_values(int v){
	values = v;
}

// set money
void Player::set_money(int m){
	money += m;
}


//-------------------- getters

// get range
int Wheel::get_range(){
	return range_low, range_high;
}

// get values
int Wheel::get_values(){
	return values;
}


// get money -- Player
int Player::get_money(){
	return money;
}


//-------------------- other

// check if game is ongoing (if player has not yet lost or cashed out)
bool Player::check_endgame(){
	if (money < 0){
		return true;
	}
	else{
		return false;
	}
}


