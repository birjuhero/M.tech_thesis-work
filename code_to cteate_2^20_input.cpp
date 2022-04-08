// this is the program to find all the possible value of 20 bit binary value.
#include <iostream>
#include <bits/stdc++.h>
#include <bitset>

using namespace std;

int main()
{
  ofstream file("file.txt");
  bitset<20> bs;
  for (long i = 0; i < 1048576; i++)
  {
    bs = i;
    file << bs << endl;
  }
  file.close();
  return 0;
}