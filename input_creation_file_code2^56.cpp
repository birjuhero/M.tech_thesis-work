// this is the program to find all the possible value of 56 bit binary value.
#include <iostream>
#include <bits/stdc++.h>
#include <bitset>

using namespace std;

int main()
{
  ofstream file("inputfile.txt");
  bitset<56> bs;
  for (long i = 0; i < 72057594037927936; i++)
  {
    bs = i;
    file << bs << endl;
  }
  file.close();
  return 0;
}