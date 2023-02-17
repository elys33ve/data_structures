#ifndef HARD_H
#define HARD_H

class Hard : public Wheel {
	private:
		int incr;		// amount to increase or decrease values by
		int winLoss;	// house wins or losses of previous round(s)

	public:
		int spin(int playerResult);		// overload of spin method
};

#endif