#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <math.h>
#include <filesystem>

using namespace std;
int*  InsertElements(int arrayParametrs[]){
    for (int i = 0; i < 6; i++) {
        cin >> arrayParametrs[i];
    }
    return arrayParametrs;
}
bool CheckFile() {
    ifstream  resWrite;
    string nameFile;
    cin >> nameFile;
    resWrite.open(nameFile);
    if (resWrite) return 1;
}
int main()
{    
    if (CheckFile() == 1) {
        int parametrs[7];
        int* arrayParametrs = InsertElements(parametrs);

        ofstream TestFile("C:/Users/user/Desktop/Test/Test.txt");

        double values[1000];

        for (int i = 0; i < parametrs[1]; i++) {
            values[i] = (parametrs[5] + rand() % parametrs[4]);
            for (int strInrterval = 0; strInrterval < (int)(values[i]) % parametrs[3] + parametrs[2]; strInrterval++) {
                values[i] = (parametrs[5] + rand() % parametrs[4]);
                TestFile << round((values[i])) << " ";
            }
            TestFile << round(values[i]) << " " << "\n";
        }

        for (int i = 0; i < parametrs[0] - parametrs[1]; i++) {
            values[i] = 0 + rand() % 100;
            for (int strInrterval = 0; strInrterval < (int)(values[i]) % parametrs[3] + parametrs[2]; strInrterval++) {
                values[i] = 0 + rand() % 100;
                int value = ((RAND_MAX) / values[i]);
                TestFile << (double((value) % 100)) / (rand() % 201 - 100) << " ";
            }
            int value = ((RAND_MAX) / values[i]);
            TestFile << (double((value) % 100)) / (rand() % 201 - 100) << " " << "\n";
        }
        cout << "success";
    }
    else {
        cout << "No such file exists :(";
    }
}
