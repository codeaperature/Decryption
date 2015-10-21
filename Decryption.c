/*
 https://www.codeeval.com/open_challenges/61/
 
 Decryption
 Description:
 For this challenge you are given an encrypted message and a key. You have to determine the encryption and encoding technique and then print out the corresponding plaintext message. You can assume that the plaintext corresponding to this message, and all messages you must handle, will be comprised of only the characters A-Z and spaces; no digits or punctuation.
 Input sample:
 There is no input for this program. The encrypted message and key is:
 message: "012222 1114142503 0313012513 03141418192102 0113 2419182119021713 06131715070119",
 keyed_alphabet: "BHISOECRTMGWYVALUZDNFJKPQX"
 Output sample:
 Print out the plaintext message. (in CAPS)
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    
    const char * const key = "BHISOECRTMGWYVALUZDNFJKPQX";
    const char * const message = "012222 1114142503 0313012513 03141418192102 0113 2419182119021713 06131715070119";
    char xform[26];
    
    
    for(char i = 0; i < 26; ++i) {
        xform[key[i] - 'A'] = i + 'A';
    }
    
    char i = 0;
    while (message[i]) {
        // blank
        if (message[i] == ' ') {
            putchar(' ');
        }
        //
        else {
            // code = 2 * the first digit
            char code = (message[i++] - '0') << 1;
            // code = code + code * 4 + digit (or 10 * code + digit)
            code += (code << 2) + (message[i] - '0');
            putchar(xform[code]);
        }
        i++;
    }
    putchar('\n');
    
    return 0;
}