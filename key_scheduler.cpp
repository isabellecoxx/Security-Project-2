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
    if (sub_key.empty()){
        return sub_key;
    }

    // store the first character of the string, then shift all characters to the left
    char first = sub_key[0];
    for(int i = 0; i < sub_key.length() - 1; i++){
        sub_key[i] = sub_key[i + 1];
    }
    // place the first character at the end of the string
    sub_key[sub_key.length() - 1] = first;
    
    return sub_key;
} 

// function to generate sub keys
// outputs a vector of strings, containing the 16 subkeys 
vector<string> key_gen(string key){
    vector<string> sub_keys;

    // DES shift schedule for 16 rounds
    int shift_table[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

    // apply PC-1 to get 56-bit permuted key
    string permuted_key = "";
    for (int i = 0; i < 56; i++) {
        permuted_key += key[PC1[i] - 1];
    }

    // split into halves
    string l_half = permuted_key.substr(0, 28);
    string r_half = permuted_key.substr(28, 28);

    // generate 16 round keys
    for (int round = 0; round < 16; round++) {
        for (int shift = 0; shift < shift_table[round]; shift++) {
            l_half = shift_left(l_half);
            r_half = shift_left(r_half);
        }

        // combine halves and apply PC-2 to get 48-bit subkey
        string combined_key = l_half + r_half;
        string round_key = "";
        for (int i = 0; i < 48; i++) {
            round_key += combined_key[PC2[i] - 1];
        }
        sub_keys.push_back(round_key);
    }

    return sub_keys;
}
