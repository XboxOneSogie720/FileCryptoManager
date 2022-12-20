#include <iostream>
#include <include/encrypter.hpp>
#include <include/decrypter.hpp>
#include <include/colors.hpp>
#include <cstring>
using namespace std;

void showUsage(string currentProgramName) {
    cout << BOLDCYAN << "Usage: " << currentProgramName << " [-e] [-d] -f {file} -k {key}" << RESET << endl;
    cout << YELLOW << "\n-e    Encryption mode" << RESET << endl;
    cout << YELLOW << "-d    Decryption mode" << RESET << endl;
    cout << YELLOW << "-f    Specify the file you want to work with" << RESET << endl;
    cout << YELLOW << "-k    Specify the key you want to use to encrypt/decrypt your file" << RESET << endl;
    cout << BOLDGREEN << "\nTip: Put your key in quotes so that you can use special characters like these: !, @, #, $, &, *, etc." << RESET << endl;
    cout << BOLDRED << "\n{!} YOU CAN ONLY DECRYPT FILES ENCRYPTED BY THIS PROGRAM\nYOU ARE RESPONSIBLE FOR A LOSS OF DATA!" << RESET << endl;
}

int main(int argc, char** argv) {

    //Store the information from the arguments to be used later
    string mode;
    string file;

    string key;
    string translatedKey;

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

    //Create the translated key
    for(int i = 0; i < size(key); i++) {
        translatedKey.push_back(int(int(key[i]) - (size(key) - i)));
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
