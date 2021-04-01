def main():

    text = input("Text: ")

    letter = letters(text)
    word = words(text)
    sentence = sentences(text)
    L = 100*letter/word
    S = 100*sentence/word

    index = 0.0588 * L - 0.296 * S - 15.8
    grade = round(index)

    if grade < 1:
        print("Before Grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print("Grade "+str(grade))



def letters(text):

    countlet=0
    for i in range(len(text)-1,-1,-1):

        if text[i].isalpha():
            countlet+=1

    return countlet


def words(text):

    countword=0
    for i in range(len(text)-1,-1,-1):

        if text[i].isspace()==True:
            countword+=1

    return countword+1


def sentences(text):

    countsen=0
    for i in range(len(text)-1,-1,-1):

        if text[i]=='.' or text[i]=='?' or text[i]=='!':

            countsen+=1

    return countsen

main()
