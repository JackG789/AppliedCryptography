#include <iostream>
#include "authlib.h"

int main() {
  bool auth = true;
 
  if (auth) authenticated("user");
  else rejected("user");
}
