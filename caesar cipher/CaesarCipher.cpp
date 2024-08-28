#include<iostream>
#include"CaesarCipher.h"
#include<string>
#include<sstream>
#include<cctype>

CaesarCipher::CaesarCipher(int _key){
    key = _key;
    while(key < 0){
        key += 26;
    }
    key = key % 26;
}

string CaesarCipher::encrypt(string text){
    string result;
    for (int i = 0;i < text.length(); i++){
        if (isalpha(text[i])){
            char ascii = islower(text[i])?'a':'A';
            text[i] = (((text[i] - ascii) + key) % 26) + ascii;
            result += text[i];
        }
        else{
            result += text[i];
        }
    }
    return result;
}

string CaesarCipher::decrypt(string text){
    string result;
    for (int i = 0;i < text.length(); i++){
        if (isalpha(text[i])){
            char ascii = islower(text[i])?'a':'A';
            text[i] = (((text[i] - ascii) + (26 - key)) % 26) + ascii;
            result += text[i];
        }
        else{
            result += text[i];
        }
    }
    return result;
}
