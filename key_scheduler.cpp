#include "key_utils.h"
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;


// function to shift the bits of the key to the left
// used in DES key schedule to generate subkeys
// takes a subkey as input and returns the shifted subkey
string shift_left(string sub_key){
     
    // if string is empty, return it, theres nothing to shift
    if (sub_key.empty(){
        return sub_key;
    })

    // store the first character of the string, then shift all characters to the left
    char first = sub_key[0];
    for(int i = 0; i < sub_key.legth() - 1; i++){
        sub_key[i] = sub_key[i + 1];
    }
    // place the first character at the end of the string
    sub_key[sub_key.length() - 1] = first;
    
    return sub_key;
} 

vector<string> key_gen(string key){
    vector<string> sub_keys;
    //write code from here
    
    return sub_keys;
}
