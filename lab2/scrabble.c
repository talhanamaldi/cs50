#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    
    //compare
    if(score1>score2)
    {
        printf("Player 1 wins!\n");
    }
    else if(score1<score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }





}

int compute_score(string word)
{
    int seq,p,o=0;
    int total=0;

     for(int i=0,b=strlen(word);i<b;i++)
    {
        p=0; //when user input some punctuation, program remember last value of p and o but it should not be value
        o=0;
        
        if (islower(word[i]))
        {
            seq=word[i]-97; // to find out which order in the alphabet ptext[i]
            p = POINTS[seq];


        }
        else if(isupper(word[i]))
        {
            seq=word[i]-65; // to find out which order in the alphabet ptext[i]
            o = POINTS[seq];

        }

        total=total+p+o;
    }
       

    

    return total;

}
