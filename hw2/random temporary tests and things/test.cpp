#include <iostream>
#include <cstdlib>

using namespace std;

int r(int up, int low){
	return rand() % up + 1;
	//return (rand() % (up - low + 1)) + low;
}

int main(){
	int up = 10;
	int low = 1;
	int i;

	for (i=0; i<5; i++){
		cout << r(up, low) << " ";
	}

	cout << endl;

	return 0;
}