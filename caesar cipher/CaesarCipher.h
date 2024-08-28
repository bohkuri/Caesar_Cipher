
#ifndef CAESARCIPHER_H_INCLUDED
#define CAESARCIPHER_H_INCLUDED

#include <iostream>
#include <cctype>
using namespace std;

class CaesarCipher
{
public:
    CaesarCipher(int _key);
    string encrypt(string text);
    string decrypt(string text);
private:
    int key;
};
#endif // CAESARCIPHER_H_INCLUDED
