/* commend line argument is 26 letter
according to this encrypt plain text to chipper text
*/

#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int main(int argc,string argv[])
{
    string key = argv[1];
    
    //check agrv[1] is it there or not
    if(argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //argv[1] must contain 26 characters
    if(strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //check argv[1] contain any digit or same character
    for(int i=0,b=strlen(key);i<b;i++)
    {
        if(isdigit(key[i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        
        for(int check = 1; check<27; check++)
        {
            if(i!=check)
            {
                if(key[i] == key[check])
                {
                    return 1;
                }
            }
        }


    }
    
    // encryptor
    
    string ptext = get_string("plaintext: ");

    int seq;

    for( int i=0,b=strlen(ptext);i<b;i++)
    {

        if (islower(ptext[i]))
        {
            seq=ptext[i]-97; // to find out which order in the alphabet ptext[i]
            //use seq in key because key is a new alphabet
            ptext[i]=tolower(key[seq]);
        }
        else if(isupper(ptext[i]))
        {
            seq=ptext[i]-65; // to find out which order in the alphabet ptext[i]
            //use seq in key because key is a new alphabet
            ptext[i]=toupper(key[seq]);
        }
        else
        {   
            //for space or some punctuation
            ptext[i]=ptext[i];
        }

    }
    printf("ciphertext: %s\n",ptext);
}
