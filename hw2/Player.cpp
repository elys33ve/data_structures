#include <cstdlib>
#include "Wheel.h"
#include "Player.h"



// --------------------- class Player

Player::Player() {
    values = 10;
    money = 100.0;
}

Player::Player(int Values) {
    values = Values;
}

Player::Player(int Values, double Money) {
    values = Values;
    money = Money;
}


// set player money
void Player::set_money(double m){
    money = m;
}
// get player money
double Player::get_money(){
    return money;
}



// --------------------- class Wheel

int Wheel::spin() {
    return rand() % values + 1;
}