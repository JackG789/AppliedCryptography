
#include "authlib.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <ctime>
#include <openssl/sha.h>

using namespace std;

string user,password; //initialise 

string sha256(const string password)//hashing in sha256 function
{
    unsigned char hash[SHA256_DIGEST_LENGTH]; 
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.size());
    SHA256_Final(hash, &sha256);
    stringstream ourStream;

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)//hashing each charcater
    {
        ourStream << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ourStream.str();
}


vector<string> readFromFile(){//reading from the passwords file
	vector<string> savedDetails; //vector storing usernames & passwords
	fstream readFile;
	readFile.open("passwords.txt", ios::in); //read passwords.txt
	string currentLine;
	if(readFile.is_open()){
		while (getline(readFile, currentLine)){ //if there is data read it in 
			savedDetails.push_back(currentLine); //add to the vector
		}
		readFile.close(); 
	}
	else {
		cout << "unable to open file" << endl; //error handiling 
	}
	return savedDetails; //Return the vector 
}



void compare(string hashedPassword, vector<string> savedDetails) //function to checking to see if the usernames and hashed passwords line up 
{
	vector<string>::iterator it; //Create an iterator to go through the vectore one at a time 
	string enteredLogin = user + ":" + hashedPassword; //match formats
	it = find (savedDetails.begin(), savedDetails.end(), enteredLogin); //search for the match 

	if(it != savedDetails.end()){ 
		authenticated(user); //Authenticate user
		exit(0); 
	}
	else {
		rejected(user); //Reject user
	}
}


  
void getLogin(){ //getting the  user input
	cout << "Please enter your username :" << endl; 
	cin >> user; //entered username 

	cout << "Please enter your password :" << endl; 
	cin >> password;//entered password 

	string hashedPasswordassword = sha256(p); //hash the entered password 
	vector<string> savedDetails = readFromFile(); //read in passwords.txt
	compare(hashedPasswordassword, savedDetails);//Compare the information
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
