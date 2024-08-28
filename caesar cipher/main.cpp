#include<iostream>
#include<string>
#include<sstream>
#include<cctype>
#include<limits>
#include<fstream>

#include "CaesarCipher.h"


using namespace std;

int main(){
    string text;
    string input;
    int key;

    cout << "Input a line of text, followed by enter. Input \"q\" to exit" << endl;

    getline(cin, input);
    while (input != "q"){
        text += input;
        text += '\n';
        getline(cin, input);
    }
    cout << endl;
    cout << "Input an encryption key (integer value):" << endl;

    cin >> key;
    while(!cin.good()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: key must be an integer value. Please enter a new key:" << endl;
        cin >> key;
    }

    CaesarCipher Cipher(key);
    text = Cipher.encrypt(text);
    cout << text << endl;


    ofstream cipherOFS;
    cipherOFS.open("text.txt");
    cipherOFS << text;
    cipherOFS.close();


    ifstream cipherIFS;
    cipherIFS.open("text.txt");
    string cipherText = "";
    string temp = "";

    while (getline(cipherIFS, temp)){
        cipherText += temp;
        cipherText += '\n';
    }
    cipherIFS.close();
    cout << "Opening encrypted text:" << endl << cipherText << endl;
    cipherText = Cipher.decrypt(cipherText);
    cout << "Opening decrypted text:" << endl << cipherText;





    return 0;
}
