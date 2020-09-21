//CS50 Problem Set 2: Readability
//Author: Sandro Soncini

#include<cs50.h>
#include<stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string str);
int count_words(string txt);
int count_sentences(string txt);
int grade(int letter, int word, int setence);

// Print the correct Grade.
int main(void)
{

    string txt = get_string("Text: ");
    
    int letters = count_letters(txt);
    int words = count_words(txt);
    int sentences = count_sentences(txt);
    
    int r = grade(letters, words, sentences);
    
    if (r < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (r >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", r);
    }

}

// count letters
int count_letters(string txt)
{
    int count = 0;
    for (int i = 0; i < strlen(txt); i++)
    {
        if (isalpha(txt[i]))
        {
            count += 1;
        }
    }

    return count;
}

//count words
int count_words(string txt)
{
    int count = 0;
    for (int i = 0; i < strlen(txt); i++)
    {
        if ((isalpha(txt[i]) || ispunct(txt[i])) && (isspace(txt[i + 1])))
        {
            count += 1;
        }
    }
    return count + 1;
}

//count sentences 
int count_sentences(string txt)
{
    int count = 0;
    for (int i = 0; i < strlen(txt); i++)
    {
        if (txt[i] && (txt[i + 1] == '.' || txt[i + 1] == '?' || txt[i + 1] == '!'))
        {
            count += 1;
        }
    }
    return count;
}

//Define the Grade
int grade(int letter, int word, int sentence)
{

    float avg_letters = (float) letter * 100 / (float) word;
    float avg_sentences = (float) sentence * 100 / (float) word;

    float index = 0.0588 * avg_letters - 0.296 * avg_sentences - 15.8;
    

    return roundf(index);
}