/*
below program is implementation of benes network of 16*16 input-output. here i have make a 2-d table matrix with which we will pass our input from first column to last column.
*/
#include<bits/stdc++.h>

using namespace std;

int table [16][8] =   {{0   ,0  ,0  ,0  ,0  ,0  ,0  ,0  },
                       {1   ,2  ,2  ,2  ,2  ,4  ,8  ,1  },
                       {2   ,4  ,4  ,1  ,1  ,1  ,1  ,2  },
                       {3   ,6  ,6  ,3  ,3  ,5  ,9  ,3  },
                       {4   ,8  ,1  ,4  ,4  ,2  ,2  ,4  },
                       {5   ,10 ,3  ,6  ,6  ,6  ,10 ,5  },
                       {6   ,12 ,5  ,5  ,5  ,3  ,3  ,6  },
                       {7   ,14 ,7  ,7  ,7  ,7  ,11 ,7  },
                       {8   ,1  ,8  ,8  ,8  ,8  ,4  ,8  },
                       {9   ,3  ,10 ,10 ,10 ,12 ,12 ,9  },
                       {10  ,5  ,12 ,9  ,9  ,9  ,5  ,10 },
                       {11  ,7  ,14 ,11 ,11 ,13 ,13 ,11 },
                       {12  ,9  ,9  ,12 ,12 ,10 ,6  ,12 },
                       {13  ,11 ,11 ,14 ,14 ,14 ,14 ,13 },
                       {14  ,13 ,13 ,13 ,13 ,11 ,7  ,14 },
                       {15  ,15 ,15 ,15 ,15 ,15 ,15 ,15 }};

//we use below method to print the array containing character.
void printCharArray(char arrref[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arrref[i] << " ";
    }
    cout << endl;
}

// we use below method to print the array containing integer.
void printintArray(int arrref[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arrref[i] << " ";
    }
    cout << endl;
}

// below we do our operation, we pass variable one is input and another is table and we save it in reference variable.
string operation(char inputref[16], int confref[56]){
    int p;// this acts as a counter when p is 56 then it will getover and new operation will be called and this will reset to zero.
    char output[16];
    char inputToCopy[16];// this variable is used to copy the input. it will not change.
    int tableref[16][8];
    for(int i=0;i<16;i++){
        //cout<<inputref[i] << " ";
        inputToCopy[i]=inputref[i];
    }

    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tableref[i][j] = table[i][j];
        }
    }
    printCharArray(inputref, 16);
    //printintArray(confref, 56);

    for (int c = 0; c < 7; c++)
    {
        for (int r = 0; r < 16; r += 2)
        {
            if (confref[p] == 1)
            {
                swap(inputref[r],inputref[r+1]);
            }
            p++;
        }

        for (int i = 0; i < 16; i++)
        {
            int val = tableref[i][c + 1];
            output[i] = inputref[val];
        }
        for(int i=0;i<16;i++){
            cout<<inputref[i] << " ";
            inputref[i]=output[i];
        }
        cout << endl;
    }
    /*
    for(int i=0;i<16;i++){
        cout<<tableref[i][5];
        output[i]=tableref[i][6];
    }
    */
    //printCharArray(output,16);
    for(int i=0;i<16;i++){
        //cout<<inputref[i] << " ";
        inputref[i]=inputToCopy[i];
    }
    
    ostringstream os;
    for(int i=0;i<16;i++){
        os << output[i];
    }
    string str(os.str());
    cout << str << endl;
    
    return str;
}

int main(){

    char input[16]={'a' ,'b' ,'c' ,'d' ,'e' ,'f' ,'g' ,'h' ,'i' ,'j', 'k' ,'l' ,'m' ,'n' ,'o' ,'p' };
    int configurationMatrix[56];
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
                configurationMatrix[i] = line[i] - 48; //48 here is decimal value of zero(0).
                //cout<<configurationMatrix[i];                
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