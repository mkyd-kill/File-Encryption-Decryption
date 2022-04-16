#include<bits/stdc++.h>
#include<fstream> // for file reading and file writing
using namespace std;

/**
 * class Cryptography
 * method: encrypt & decrypt* 
*/

class Cryptography {
    int key; // used to both encrypt and decrypt a file

    char c;
    // input file streams
    fstream file_in, file_out;

    public:
        string file;
        void encrypt();
        void decrypt();
};

// method definitions
void Cryptography::encrypt() {
    // ask for user encryption key
    cout << "Key :> ";
    cin >> key;

    // open the given file

    file_in.open(file, fstream::in);
    file_out.open("encrypt.txt", fstream::out);

    // reading the original file
    while(file_in >> noskipws >> c) {
        int temp = (c + key);

        // writing temp as a char in output file
        file_out << (char)temp;
    }
    cout << "File Encryption Successful" << endl;
    // close the stream
    file_in.close();
    file_out.close();
}

void Cryptography::decrypt() {
    cout << "Key :> ";
    cin >> key;

    file_in.open("encrypt.txt", fstream::in);
    file_out.open("decrypt.txt", fstream::out);

    while(file_in >> noskipws >> c) {
        // remove the key from characters
        int temp = (c - key);

        file_out << (char)temp;
    }
    cout << "File Decryption Successful" << endl;
    file_in.close();
    file_out.close();
}


int main() {
    Cryptography crypt;
    char c;
    
    cout << "Enter File Name :> ";
    cin >> crypt.file;

    cout << "\n Choose From Options \n";
    cout << "1. Encrypt File \n";
    cout << "2. Decrypt File \n";
    cout << "3. Exit \n";
    cout << "\n :--> ";
    cin >> c;
    cin.ignore();

    switch (c)
    {
    case '1':
        crypt.encrypt();
        break;
    case '2':
        crypt.decrypt();
        break;
    case '3':
        cout << "Exiting Program" << endl;
        exit(1);
    default:
        cout << "No File Choosen" << endl;
        break;
    }
}