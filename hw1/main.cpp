#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

struct file {
	std::string title;				// title
	std::string author;				// author full name
	int wordCount = 0;				// word count
	double frequency[26] = {0.0};	// letter frequency
	int lineCount = 0;				// line count
};

int main() {
    std::ifstream text;			// input file txt
    std::ofstream data;			// output file data
    std::string fileName;
    char repeat = 'Y';

    //open the output file
    data.open("CardCatalog.txt", std::ios::app);

    //repeat until the user says No
    while (repeat == 'Y') {
		struct file newEntry;					// new struct instance
        std::string AuthorFName;
        std::string AuthorLName;
        std::string line;
		std::string word;
        char response;
        int letterCount = 0;    // total letters
		int letter;				// letter ascii value
        int position;
		int i;


        //prompt the user to give a file name
        std::cout << "What file do you want to read?: ";
        std::cin >> fileName;


        //open the text file
        text.open(fileName);


        //if the file fails to open ask again until they give a valid file
        while (text.fail()) {
            std::cout << std::endl << "That file doesn't exist. Please give a different file: ";
            std::cin >> fileName;
            text.open(fileName);
        }
        std::cout << std::endl;


        //print out the title
        data << "Title: ";
        //while the title variable is empty keep getting lines until it is assigned a value
        while (newEntry.title.empty()) {
            std::getline(text, newEntry.title);
            newEntry.lineCount++;
        }
        data << newEntry.title << std::endl;


        //print out the full authors name
        data << "Author Full Name: ";
        //while the author variable is empty keep getting lines until it is assigned a value
        while (newEntry.author.empty()) {
            std::getline(text, newEntry.author);
            newEntry.lineCount++;
        }
        data << newEntry.author << std::endl;


        //separate author first and last name
        position = newEntry.author.find(" ");			// find position of space in fullname
        //assign first and last from fullname substring
        AuthorFName = newEntry.author.substr(0, position);
		AuthorLName = newEntry.author.substr(position+1, newEntry.author.length());
        data << "Author First Name: " << AuthorFName << std::endl;			// print author first name
		data << "Author Last Name: " << AuthorLName << std::endl;			// print author last name


        //while there is still text in the file run this loop
        while (!text.eof()) {
			//keep getting lines until the contents variable matches the keyword
			while (line != "Contents:") {
                std::getline(text, line);
				line = line.substr(0,9);
				newEntry.lineCount++;
			}
			//take in each word and increment the word counter
	        text >> word;
            newEntry.wordCount++;
			//get character frequency
			for (i=0; i<word.length(); i++){
				if (isalpha(word[i]) == 1 || isalpha(word[i]) == 2){	// if current character is a letter
					letterCount++;							// increment total letter counter
					letter = int(tolower(word[i])-97);		// get ascii value of lowercase letter (minus 'a' or 97)
					newEntry.frequency[letter]++;			// increment individual letter counter
				}
			}
        }
        data << "Word Count: " << newEntry.wordCount << std::endl;	// print word count
		
        
        //get line count
        text.clear();       //clear the stream object and start at the top of the file
    	text.seekg(0);
        for (i=0; i<newEntry.lineCount; i++){       // get back to line after contents
            std::getline(text, line);
        }
        newEntry.lineCount = 0;                     // reset line count to zero
		while (std::getline(text, line)){
			newEntry.lineCount++;		//increment line count
		}
		data << "Line Count: " << newEntry.lineCount << std::endl;	// print line count


        //ask the user if they want to see the letter frequency
        std::cout << "Do you want to see the letter frequency? (Y/N): ";
        std::cin >> response;
        std::cout << std::endl;
        if (response == 'Y') {
            // print letter frequency header
            data << std::endl << newEntry.title + " Letter Frequency:" << std::endl;
            data << std::fixed << std::showpoint << std::setprecision(2);
            //calculate and  letter frequencies
            for (i=0; i<26; i++){
                newEntry.frequency[i] /= letterCount;
                newEntry.frequency[i] *= 100;
                data << char(i+97) << ": ";
                data << newEntry.frequency[i] << "%" << std::endl;
            }
        }


        //ask the user if they want to process another book
        std::cout << "Do you want to process another book? (Y/N): ";
        std:: cin >> repeat;
        std::cout << std::endl;
        if (repeat != 'Y') {
            repeat = 'N';
        }
        data << std::endl;
        text.close();
    }
	return 0;
}