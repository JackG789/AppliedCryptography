#include <iostream>
#include <iostream>
#include "authlib.h"

int main() {
  std::string user;
  std::string userPassword;
  string storedUserData[];
  std::int i;
  
  bool auth = false;
  int loginAttempt =0;
  //todo read names from file into users array(split might not work)
  std::ifstream MyReadFile("Desktop/passwords.txt");


  while (getline ((MyReadFile, storedUserData, ":")&& auth == false )) {
   std:: cout << storedUserData;//TODO only usenames read in 
  }

  MyReadFile.close();
  while(i<sizeof(storedUserData)){
  while(loginAttempt < 3){
   std:: cout << "please enter usename: ";
    std::cin >> user;
   std:: cout << "please enter password: ";
    std::cin >> userPassword;
    auth == true;  
  if(  user != storedUserData){ //compare users entered to users from file
    auth == false;     
    i++
  }
  }
  loginAttempt = loginAttempt +1; //add to sign in attempt
 //todo read in password when users are correct  
 //TODO optional after rest is done salt before hashing
 //todo hash the passwords 
 //to do compare passwords 
  if (auth) authenticated("user");
 //sign in
  else rejected("user");
  }
}
