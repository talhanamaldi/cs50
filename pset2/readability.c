// get a text
// calculate letter, word, sentence
// index = 0.0588 * L - 0.296 * S - 15.8
//  L average of letters per 100 words,S average of sentences per 100 words

#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

// create fuctions for calculate
int letters(string a);
int words(string b);
int sentences(string c);

string text;

int main(void)
{



    text=get_string("Text: ");
    float letter=letters(text);
    float word=words(text);
    float sentence=sentences(text);

    float L = 100*letter/word;
    float S = 100*sentence/word;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    int grade = round(index);

    //check grade
    if(grade<1)
    {
        printf("Before Grade 1\n");
    }
    else if(grade>16)
    {
        printf("Grade 16+\n");
    }
    else
    {
    printf("Grade %i\n",grade);
    }
}

int letters(string a)
{

    int countlet=0;
    for(int i=0 , b=strlen(a) ; i<=b ; i++)
    {
        if(isalpha(a[i]))
        {
          countlet++;
        }
    }
    return countlet;
}

int words(string a)
{

    int countword=0;
    for(int i=0 , b=strlen(a) ; i<=b ; i++)
    {
        if(a[i]==' ')
        {
          countword++;
        }
    }
    return countword+1;
}

int sentences(string a)
{
    int countsen=0;
    for(int i=0 , b=strlen(a) ; i<=b ; i++)
    {
        if(a[i]=='.'||a[i]=='?'||a[i]=='!')
        {
          countsen++;
        }
    }
    return countsen;
}
