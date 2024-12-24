#include <stdio.h>
//library for string functions
#include <string.h>
//library for time related functions --clock()
#include <time.h>
//function for character functions --isspace()
#include <ctype.h>

#define MAX_TEXT_LENGTH 10000

// function in which the text is shown and input is taken , also the time interval between the typing is recorded
void start_typ()
{
    // original text
    char textToBeTyped[MAX_TEXT_LENGTH];

    //text that the user inputs
    char userInput[MAX_TEXT_LENGTH];
    //copy of original text to operate on
    char copyText[MAX_TEXT_LENGTH];

    //variable to store the difficulty level
    int difficulty;

    //label to go back to the start of the program
    start_here:

    // -- input starts from here--
    printf("typing speed\n");

    printf("choose difficulty on a scale of 1 to 5\n");
    scanf("%d",&difficulty);

    //check if the difficulty is in the range and choose it accordingly
    switch (difficulty)
    {
    case 1: strcpy(textToBeTyped, "The bright sun slowly sinks behind the vast, tranquil ocean.");
        break;
    case 2: strcpy(textToBeTyped, "Quick-thinking adventurers often escape perilous situations with resourceful improvisation.");
        break;
    case 3: strcpy(textToBeTyped, "Typing fluidly on a keyboard requires synchronized hand movements and consistent focus on accuracy.");
        break;
    case 4: strcpy(textToBeTyped, "Complex sentences, like this one, challenge your typing skills by mixing uncommon punctuation, tricky finger placements, and shifting hand positions.");
        break;
    case 5: strcpy(textToBeTyped, "Astonishingly, experienced typists can effortlessly navigate lengthy and intricate passages containing diverse vocabulary, alternating patterns, and unexpectedly placed symbols such as @, &, or %.");
        break;
    default: printf("invalid input\n");
         goto start_here; // go back to the start of the program if invalid input
        break;
    }

    getchar();// to read the /n character after the integer input when we press enter key

    printf("type the following text:%s \n",textToBeTyped);

    printf("start typing: \n");
    // input the setence
    gets(userInput);


    //--input ends here

    //copying original string to copy
    strcpy(copyText,textToBeTyped);
    
    //calls for the fuction to remove spaces
    remove_space(copyText);
    remove_space(userInput);

   
   //call for the function to calculate speed and accuracy
    Info(copyText,userInput);
}

// this function remove space from the given string
void remove_space(char *str)
{
    int count = 0;

    // the condition is the character is not null
    for (int i = 0;str[i] !='\0'; i++)
    {
        //changes the current charcter place if the current characte is not space
        if(!isspace(str[i]))
            str[count++] = str[i];
    }
}

// this function claculates the accuracy and speed
void Info(const char *givetext,const char *userInput)
{
    int correctChar=0; // number of correct characters
    int totalCharacters = strlen(userInput);//total characters

    //loop which checks if the characters are same in both the strings
    for(int i=0;i<totalCharacters;i++)
        if ((givetext[i]==userInput[i]))
            correctChar++;//increase if the character is correct
        
    // caculate the accuracy 
    double accuracy = (double)correctChar/totalCharacters *100.0;

    // -- final output
    printf("user accuracy = %lf \n",accuracy);

    //check if the accuracy is less than 90
    if (accuracy < 90)
        printf("you need to improve your accuracy\n");
    else
        printf("you are doing good\n");

    // go back to the start of the program
    start_typ();
}


// main function -- calls for the first function
int main()
{
    // calling the start tping functions
    start_typ();

    return 0;
}
