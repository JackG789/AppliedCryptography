#include <iostream>
#include "authlib.h"

int main() {
  string user;
  string userPassword;
  string storedUserData[];
  
  bool auth = true;
  int loginAttempt =0;
  //todo read names from file into users array(split might not work)
  ifstream MyReadFile("users.txt");
  while (getline (MyReadFile, storedUserData, ":")) {
  cout << storedUserData;//TODO only usenames read in 

  }
  MyReadFile.close();

  while(loginAttempt < 3){
    cout << "please enter usename: ";
    cin >> user;
    cout << "please enter password: ";
    cin >> userPassword;
  if(  user != storedUserData[]){ //compare users entered to users from file
    auth == false;     
  }
  loginAttempt = loginAttempt +1; //add to sign in attempt
 //todo read in password when users are correct  
 //todo hash the passwords 
 //to do compare passwords 
  if (auth) authenticated("user");
 //sign in
  else rejected("user");
  }
}
