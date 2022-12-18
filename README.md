
# FileCryptoManager

A homemade micro-program written in C++ that encrypts a file byte by byte with your own password


## Features
- Encrypt a file with a password as long and complex as you want, even if it contains spaces
- Encrypts files by completely overwriting the file with the new bytes
- Colored output
- Easy-to-understand usage
## Compatibility
- `Linux/macOS` As long as you have c++17 and you can compile a C++ program using clang++ or g++, you are good to go!
- `Windows` You will need g++. If you do not have it, see [this video](https://www.youtube.com/watch?v=ACqnO0PJB4c) to get it working. After that, open cmd as administrator and run this command: `reg add HKEY_CURRENT_USER\Console /v VirtualTerminalLevel /t REG_DWORD /d 0x00000001 /f`. This will get the colored output working, so that it doesn't look like giberish when you run the program. No, you do not need this, but it makes the experience cleaner.

**Now you can head to the compiling stage!**
## Compiling
**Now you're ready to compile the program. Open up your terminal if you're on macOS or Linux, or the cmd if you're on Windows, and change the directory to the root folder. Use the following command to compile the program on your system.**

```g++ main.cpp encrypter.cpp decrypter.cpp -I. -o fileCryptoManager -std=c++17```

## Usage
**The program shows you how to use it if you make a mistake while using it, but if you want to see how to use it now, see the table below.**


|Argument|                         Description                         | 
|--------| ------------------------------------------------------------|
| -e     | Encryption mode                                             |
| -d     | Decryption mode                                             |
| -f     | Specify the file you want to work with                      |
| -k     | Specify the key you want to use to encrypt/decrypt your file|

**Tip: Put your key in quotes so that you can use special characters like these: !, @, #, $, &, *, etc.***

**{!} YOU CAN ONLY DECRYPT FILES ENCRYPTED BY THIS PROGRAM**

**YOU ARE RESPONSIBLE FOR A LOSS OF DATA!**

## Demo
**Here's a demo of using the program on a plain text file.**

![](https://github.com/XboxOneSogie720/FileCryptoManager/blob/main/Other/demo.gif)

## Credits
The encryption and decryption functions used in this program are based off of [this YouTube video.](https://www.youtube.com/watch?v=DOlcAVlUbdk&t=164s)
