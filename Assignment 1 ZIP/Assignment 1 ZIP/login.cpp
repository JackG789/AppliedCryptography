#include <iostream>
#include "authlib.h"

int main() {
  string userName;
  string userPassword;
  string storedUserData[];
  bool auth = true;
  int loginAttempt =0;
  //todo read names from file into usernames array
  ifstream MyReadFile("usernames.txt");
  while (getline (MyReadFile, storedUserData, ":")) {
  cout << storedUserData;
  }
  MyReadFile.close();

  while(loginAttempt < 3){
    cout << "please enter usename: ";
    cin >> userName;
    cout << "please enter password: ";
    cin >> userPassword;
  if(  userName != "user"){ //compare usernames entered to usernames from file
    auth == false;     
  }
  loginAttempt = loginAttempt +1; //add to sign in attempt

  if (auth) authenticated("user");
 //sign in
  else rejected("user");
  }
}
