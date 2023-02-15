//  Homework 1
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* 
- prompt user for input file
- test if file can be opened
    - if not, print error msg and prompt for new file
- read info into structure
    - title, author full name, word count, letter frequency, line count
- open file CardCatalog.txt 
    - if file exists, append -- if not, create new
    - leave blank line between each entry
- ask user if they want to see letter freq
    - if yes, return freq in percent for each letter
- ask user if they want to process another entry
    - if yes, repeat -- if no, quit
*/

typedef struct file {
    string title;
    string author;
    int words = 0;
    double l_freq[27];
    int lines = 0;
} file;

// attempt at making smthn like python's .strip() method
string strip (string x) {
	int s = int(' '); int t = 9;
	if (x.length() == 0){ return "\0"; }
    while (int(x[0]) == s || int(x[0]) == t){	// left strip()
        x.replace(0,1,"");
    }
	int j = x.length();
    while (int(x[j]) == s || int(x[j]) == t || int(x[j]) == 0){	// right strip()
        x.replace(j,1,"");
        j--;
    }
	if (x.length() == 0){ return "\0"; }
	else { return x; }
}


int main (){
    // prompt user for name of input file
    string filename;
    cout << "filename:  ";
    //cin >> filename;
    filename = "MobyDick.txt";

    // test if file can be opened
    fstream readfile;
    readfile.open(filename, ios::in);
    while (readfile.fail()){                  // prompt for new file until valid file
        cout << "\ncould not open file " << filename << endl;
        cout << "filename:  ";
        cin >> filename;
        readfile.open(filename, ios::in);
    }

    // with file open, read into structure
    file newfile;
    string line;        // current line
    int letters = 0;
    int i;

    // title
    getline(readfile, line);        // get first non-empy line
    while(strip(line) == "\0"){
        getline(readfile, line);
        newfile.lines++;
    }
    newfile.title = line;

    // author
    getline(readfile, line);        // get second non-empy line
    while(strip(line) == "\0"){
        getline(readfile, line);
        newfile.lines++;
    }
    newfile.author = line;


    // word count and char freq
    fill_n(newfile.l_freq, 27, 0);      // fill letter freq array w zero
    while (getline(readfile, line)){
        if (strip(line) != "\0" && line != "Contents:"){
            for (i=0; i<line.length(); i++){
                if (isalpha(line[i]) == 1 || isalpha(line[i]) == 2){    // if current char is letter     
                    newfile.l_freq[tolower(line[i])-97]++;                  // add 1 for letter
                    letters++;
                }
                else if (line[i] != '\''){      // count word
                    newfile.words++; 
                }
            }
            newfile.words++;  
        }
        newfile.lines++;
    }
    newfile.lines += 3;

    cout << endl << newfile.title << endl << newfile.author << endl;
    cout << newfile.words << endl;
    cout << newfile.lines << endl;
    
    for (i=0; i<27; i++){               // letter frequency
        newfile.l_freq[i] /= letters;
        newfile.l_freq[i] *= 100;
        cout << char(i+97) << ": " << newfile.l_freq[i] << endl;
    }

    //string filename = "CardCatalog.txt";    // output file
    //ifstream ifexist(filename);             // test if file exists

    return 0;
}


/*
cd Documents\UC\data_struc\hw1
make && hw1
*/
