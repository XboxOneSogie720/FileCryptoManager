#include <iostream>
#include <vector>
#include <include/encrypter.hpp>
#include <include/decrypter.hpp>
#include <include/colors.hpp>
using namespace std;

void showUsage(string currentProgramName) {
    cout << BOLDCYAN << "Usage: " << currentProgramName << " [-e] [-d] -f {file} -k {key}" << RESET << endl;
    cout << YELLOW << "\n-e    Encryption mode" << RESET << endl;
    cout << YELLOW << "-d    Decryption mode" << RESET << endl;
    cout << YELLOW << "-f    Specify the file you want to work with" << RESET << endl;
    cout << YELLOW << "-k    Specify the key you wnat to use to encrypt/decrypt your file" << RESET << endl;
    cout << BOLDGREEN << "\nTip: Put your key in quotes so that you can use special characters like these: !, @, #, $, &, *, etc." << RESET << endl;
    cout << BOLDRED << "\n{!} YOU CAN ONLY DECRYPT FILES ENCRYPTED BY THIS PROGRAM\nYOU ARE RESPONSIBLE FOR A LOSS OF DATA!" << RESET << endl;
}

int main(int argc, char** argv) {

    //Store the information from the arguments to be used later
    string mode;
    string file;

    string key;
    vector<int> eachKeyCharInInt;
    int translatedKey;
    

    if(argc < 6 || argc > 6) {
        showUsage((string)*(&argv[0]));
        return 0;
    }
    
    //Determine the mode
    for(int i = 0; i < argc; i++) {
        if(!strcmp(argv[i], "-e") || !strcmp(argv[i], "-E")) {
            mode = "ENCRYPT";
            break;
        }
        if(!strcmp(argv[i], "-d") || !strcmp(argv[i], "-D")) {
            mode = "DECRYPT";
            break;
        }
    }

    //Determine the file path
    for(int i = 0; i < argc; i++) {
        if(!strcmp(argv[i], "-f") || !strcmp(argv[i], "-F")) {
            file = argv[i+1];
            break;
        }
    }

    //Note the key for encrypting/decrypting
    for(int i = 0; i < argc; i++) {
        if(!strcmp(argv[i], "-k") || !strcmp(argv[i], "-K")) {
            key = argv[i+1];
            break;
        }
    }

    //Update the key with the ASCII equivilent number for each character
    for(int i = 0; i < key.length(); i++) {
        eachKeyCharInInt.push_back(int(key[i]));
    }
    for(int i = 0; i < size(eachKeyCharInInt); i++) {
        translatedKey += eachKeyCharInInt[i];
    }

    if(mode == "ENCRYPT") {
        encrypt(file, translatedKey);
    } else if(mode == "DECRYPT") {
        decrypt(file, translatedKey);
    } else {
        cout << "\nFATAL ERROR" << endl;
    }

    return 0;
}