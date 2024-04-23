#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;
int main(){
    
    //if and of stream variable declaration
    ifstream inputFile;
    ofstream outputFile;
    char ch;

    //open text data, associating with inputFile and checking for failure
    inputFile.open("data.txt");
    if (inputFile.fail()){
        cout << "Error: file not found" << endl;
        exit(0);
    }
    // opening output stream
    outputFile.open("data_out.txt");


    while (!inputFile.eof()){
        inputFile.get(ch);
        // is lowercase
        if (islower(ch)){
            outputFile << static_cast<char>(toupper(ch));
            continue;
        }
        // is uppercase
        if (ch >= 'A' && ch <= 'Z'){
            outputFile << ch;
            continue;
        }
        // is digit?
        if (ch >= '0' && ch <= '9'){
            outputFile << "*";
            continue;
        }
        // any other character outputted as is
        outputFile << ch;
    }

    // close files 
    inputFile.close();
    outputFile.close();

    

}
