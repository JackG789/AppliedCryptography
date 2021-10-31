#include <iostream>
#include "authlib.h"
#include <fstream>
#include<vector>

using namespace std;



int main() {
  string user;
  string userPassword;
  string storedUserData;
  int i=0;
  bool auth = false;
  int loginAttempt =0;
  string line;
  std::vector<std::string> lines;
  ifstream MyReadFile ("passwords.txt");

  if (MyReadFile.is_open())
  {
     for (std::string line; std::getline(MyReadFile, line, ':');) 
        {
            lines.push_back(line); //adds to end of the vector

        }
    MyReadFile.close();
  }

  
  while(i<sizeof(storedUserData)&& auth == false){

    while(loginAttempt < 3){

      std:: cout << "please enter usename: ";

      std::cin >> user;

      std:: cout << "please enter password: ";

     std::cin >> userPassword;

     auth == true;  

      if(  user != storedUserData){ //compare users entered to users from file

         auth == false;     

          i++;

      }

      loginAttempt = loginAttempt +1;

    }   

  } //add to sign in attempt

 //todo read in password when users are correct  

 //TODO optional after rest is done salt before hashing

 //todo hash the passwords 

 //to do compare passwords 

  if (auth) authenticated("user");

 //sign in

  else rejected("user");

  }

