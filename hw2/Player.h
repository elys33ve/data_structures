#pragma once

class Player : public Wheel {
    public:
        double money; //Players money
        Player();
        Player(int Values);
        Player(int Values, double Money);
};





/*#ifndef PLAYER_H
#define PLAYER_H

class Player : public Wheel {
	private:
		double money; 		// player's current money

    public:
        Player();
        Player(int Values);
        Player(int Values, double Money);

		void set_money(double m);

		double get_money();

};

#endif*/