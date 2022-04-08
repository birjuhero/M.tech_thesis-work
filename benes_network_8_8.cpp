//below is the implementation of bene's 8 bit network. it is implemented for 8 integer input and sucessfully output permuted output. here i am taking input in input array in main fuction and congiguraton matrix  from input file and saving my permuted result to result file. 
#include<bits/stdc++.h>
#include <fstream>
#include <iostream>

using namespace std;

// this table defines from column 1 to column 6 how the 8 intput number is being permutted. column 1 contains the input and after the operation executeed column 6 contains the permutted result of the corresponding input.
//A Benes network with N input and N output is shown Benes (N×N) which is made of a 2×2 switch. This
//network has 2logN-1 switch layer and each layer has N/2 switch.
int table[8][6] = {{0, 0, 0, 0, 0, 0},
                   {1, 2, 2, 2, 4, 1},
                   {2, 4, 1, 1, 1, 2},
                   {3, 6, 3, 3, 5, 3},
                   {4, 1, 4, 4, 2, 4},
                   {5, 3, 6, 6, 6, 5},
                   {6, 5, 5, 5, 3, 6},
                   {7, 7, 7, 7, 7, 7}};

// this function print the array.
void printArray(int arrref[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arrref[i] << " ";
    }
    cout << endl;
}

// here bene's network is implemented. operation function takes two input as- one is inputref which contains the input array that we want to permut the value and confref contains the configuration matrix.confref contains the switch value.
string operation(int inputref[8], int confref[20])
{
    int p;
    //string s="";
    int output[8];
    int tableref[8][6];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            tableref[i][j] = table[i][j];
        }
    }

    //printArray(inputref, 8);
    //printArray(confref, 20);
    for (int i = 0; i < 8; i++)
    {
        tableref[i][0] = inputref[i];
    }
    for (int c = 0; c < 5; c++)
    {
        for (int r = 0; r < 8; r += 2)
        {
            if (confref[p] == 1)
            {
                int temp = tableref[r][c];
                tableref[r][c] = tableref[r + 1][c];
                tableref[r + 1][c] = temp;
            }
            p++;
        }

        for (int i = 0; i < 8; i++)
        {
            int val = tableref[i][c + 1];
            tableref[i][c + 1] = tableref[val][c];
        }
    }
    
    for(int i=0;i<8;i++){
        output[i]=tableref[i][4];
    }
   // printArray(output,8);

    ostringstream os;
    for(int i: output){
        os << i;
    }
    string str(os.str());
    //cout << str << endl;
    return str;
}
int main()
{
    int input[8] = {2, 3, 4, 5, 6, 7, 8, 9};

    int configurationMatrix[20];
    string line, outline;
    ifstream MyReadFile("inputfile.txt");
    ofstream MyWriteFile("resultfile.txt");
    if (MyReadFile.is_open())
    {
        while (getline(MyReadFile, line))
        {
            cout << line << endl;

            for (int i = 0; i < line.length(); i++)
            {
                configurationMatrix[i] = line[i] - 48;
            }
            outline=operation(input, configurationMatrix);
            outline+='\n';
            MyWriteFile << outline ;
        }
    }
    MyReadFile.close();
    MyWriteFile.close();
    return 0;
}