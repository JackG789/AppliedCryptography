#include <iostream>
#include "authlib.h"

int main() {
  string userName;
  string userPassword;
  string storedUserData[];
  bool auth = true;
  int loginAttempt =0;
  //todo read names from file into usernames array(split might not work)
  ifstream MyReadFile("usernames.txt");
  while (getline (MyReadFile, storedUserData, ":")) {
  cout << storedUserData;//TODO only usenames read in 
  }
  MyReadFile.close();

  while(loginAttempt < 3){
    cout << "please enter usename: ";
    cin >> userName;
    cout << "please enter password: ";
    cin >> userPassword;
  if(  userName != storedUserData[]){ //compare usernames entered to usernames from file
    auth == false;     
  }
  loginAttempt = loginAttempt +1; //add to sign in attempt
 //todo read in password when usernames are correct  
 //todo hash the passwords 
 //to do compare passwords 
  if (auth) authenticated("user");
 //sign in
  else rejected("user");
  }
}
