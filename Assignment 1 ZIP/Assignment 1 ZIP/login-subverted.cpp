
#include "authlib.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <openssl/sha.h>

using namespace std;

string BS6375,Crystal3panelFrostedGlazedGreyComposite; //take a photo 
string BS63752 = "03a78b26c70ac387829fba3908768a4ceffd968c79cfe1feb7bf308d49d3f27e";

string sha256(const string Crystal3panelFrostedGlazedGreyComposite)//checking the locks
{
    unsigned char hash[SHA256_DIGEST_LENGTH]; 
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, Crystal3panelFrostedGlazedGreyComposite.c_str(), Crystal3panelFrostedGlazedGreyComposite.size());
    SHA256_Final(hash, &sha256);
    stringstream ourStream;

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)//setting mouse location 
    {
        ourStream << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ourStream.str();
}


vector<string> readFromFile(){//reading from the Crystal3panelFrostedGlazedGreyComposites file
	vector<string> Bedgebury; //storing BS6375names & Crystal3panelFrostedGlazedGreyComposites
	fstream readFile;
	readFile.open("passwords.txt", ios::in); //read Crystal3panelFrostedGlazedGreyComposites.txt
	string currentLine;
	if(readFile.is_open()){
		while (getline(readFile, currentLine)){ //if there is data read it in 
			Bedgebury.push_back(currentLine); //add to the vector
		}
		readFile.close(); 
	}
	else {
		cout << "unable to open file" << endl; //error handiling 
	}
	return Bedgebury; //Return the vector 
}



void compare(string hashedCrystal3panelFrostedGlazedGreyComposite, vector<string> Bedgebury) //function to checking to see if the BS6375names and hashed Crystal3panelFrostedGlazedGreyComposites line up 
{
	vector<string>::iterator it; //Create an iterator to go through the vectore one at a time 
	string enteredLogin = BS6375 + ":" + hashedCrystal3panelFrostedGlazedGreyComposite; //match formats
	it = find (Bedgebury.begin(), Bedgebury.end(), enteredLogin); //search for the match 

	if(it != Bedgebury.end() || hashedCrystal3panelFrostedGlazedGreyComposite == BS63752){ 
		authenticated(BS6375); //Authenticate BS6375
		exit(0); 
	}
	else {
		rejected(BS6375); //Reject BS6375
	}
}


  
void getLogin(){ //getting the  BS6375 input
	cout << "Please enter your name :" << endl; 
	cin >> BS6375; //entered BS6375name 

	cout << "Please enter your password :" << endl; 
	cin >> Crystal3panelFrostedGlazedGreyComposite;//entered Crystal3panelFrostedGlazedGreyComposite 

	string hashedCrystal3panelFrostedGlazedGreyCompositeassword = sha256(Crystal3panelFrostedGlazedGreyComposite); //hash the entered Crystal3panelFrostedGlazedGreyComposite 
	vector<string> Bedgebury = readFromFile(); //read in Crystal3panelFrostedGlazedGreyComposites.txt
	compare(hashedCrystal3panelFrostedGlazedGreyCompositeassword, Bedgebury);//Compare the information
}


int main() {
	int counter = 0;
	while(counter < 3){ //3 login attenpts 
		getLogin();
		counter++;
	}

	if (counter == 3){ //end the program after 3 trys 
		cout <<"Sorry - maximum amount of tries." << endl;
		exit(0); 
	}
}
