#include <cstdlib>
#include "Wheel.h"
#include "Player.h"

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


int Wheel::spin() {
    return rand() % values + 1; //(rand() % (up - low + 1)) + low;
}

/*#include "Wheel.h"
#include "Player.h"



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



// set money
void Player::set_money(double m){
    money = m;
}

// get money
double Player::get_money(){
    return money;
}




*/