#ifndef PLAYER_H
#define PLAYER_H

class Player : public Wheel {
	private:
		double money; 			// player's current money
		bool keepPlaying;		// player choice to continue
    public:
        Player();
        Player(int Values);						// house constructor
        Player(int Values, double Money);		// player constructor

		void set_money(double m);
		double get_money();
		
		bool end_game();			// method to test if game has ended
};

#endif