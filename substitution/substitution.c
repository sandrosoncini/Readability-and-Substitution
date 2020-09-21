//CS50 Problem Set 2: Substitution
//Author: Sandro Soncini

#include<cs50.h>
#include<stdio.h>
#include <string.h>
#include <ctype.h>


string validate_key(string str);
string crypt(string code_word, string str);

int main(int argc, string argv[])
{
    //Get the key from the prompt.
    string str = argv[1];
    
    // calling the validate_key function, check if the conditions are valid.
    if (validate_key(str))
    {
        printf("%s\n", validate_key(str));
        return 1;
    }
    // get the string to be converted.
    string code_word = get_string("plaintext: ");
    
    // initialize the converted string.
    char new_str[strlen(code_word)];
    
    string alpha_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alpha_lower = "abcdefghijklmnopqrstuvwxyz";
    
    printf("ciphertext: ");
    
    // Loop througth the string to be converted.
    for (int i = 0; i < strlen(code_word); i++)
    {
        // Check if the all the char are alphabetic.
        if (!isalpha(code_word[i]))
        {
            //if not alpha print the char.
            new_str[i] = code_word[i];
            printf("%c", new_str[i]);
        }
        // Two loops through the Upper and Lower case char, and print the correspondet one.
        for (int j = 0; j < strlen(alpha_upper); j++)
        {
            if (code_word[i] == alpha_upper[j] && isalpha(code_word[i]))
            {
                
                new_str[i] = toupper(str[j]);
                printf("%c", new_str[i]);
            }
        }
        
        for (int l = 0; l < strlen(alpha_lower); l++)
        {
            if (code_word[i] == alpha_lower[l] && isalpha(code_word[i]))
            {
                new_str[i] = tolower(str[l]);
                printf("%c", new_str[i]);
            }
        }
    }
    printf("\n");
    return 0;
}


string validate_key(string str)
{
    // check if the key is empty.
    if (str == NULL)
    {
        return "Usage: ./substitution key";
    }
    // check if the key is 26 char.
    else if (strlen(str) != 26)
    {
        return "Key must contain 26 characters.";
    }
    else 
    {
        for (int i = 0; i < strlen(str); i++)
        {
            //check if all char of teh key are alphabetic.
            if (!isalpha(str[i]))
            {
                return "Key must be alphabetic";
            }
            //check if there are repeted char in the key.
            for (int j = 0; j < strlen(str); j++)
            {
                
                if (i == j)
                {
                    
                }
                else if (str[i] == str[j]) 
                {
                    return "key has repeated characters";
                }
            }
        }
    }
    return 0;
}



