#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string strip (string x){
	int s = int(' '); int t = 9;
	if (x.length() == 0){ return "\n"; }
    while (int(x[0]) == s || int(x[0]) == t){	// left strip()
        x.replace(0,1,"");
    }
	int j = x.length();
    while (int(x[j]) == s || int(x[j]) == t || int(x[j]) == 0){	// right strip()
        x.replace(j,1,"");
        j--;
    }
	if (x.length() == 0){ return "\n"; }
	else { return x; }
}

int main (){
	string x = "weir fff alken";
	double v[6] = {0.0};

	x = strip(x);
	//cout << x << endl;
	//cout << x.length()<<endl;
	cout << tolower('y') << endl;

	bool nw = true;


	//text.clear();
    //text.seekg(0);

	return 0;
}