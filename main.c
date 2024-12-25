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
    int difficulty,noWords;

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
            noWords = 12;
        break;
    case 2: strcpy(textToBeTyped, "Quick-thinking adventurers often escape perilous situations with resourceful improvisation.");
            noWords = 10;
        break;
    case 3: strcpy(textToBeTyped, "Typing fluidly on a keyboard requires synchronized hand movements and consistent focus on accuracy.");
            noWords = 14;
        break;
    case 4: strcpy(textToBeTyped, "Complex sentences, like this one, challenge your typing skills by mixing uncommon punctuation, tricky finger placements, and shifting hand positions.");
            noWords = 18;
        break;
    case 5: strcpy(textToBeTyped, "Astonishingly, experienced typists can effortlessly navigate lengthy and intricate passages containing diverse vocabulary, alternating patterns, and unexpectedly placed symbols such as @, &, or %.");
            noWords = 22;
        break;
    default: printf("invalid input\n");
         goto start_here; // go back to the start of the program if invalid input
        break;
    }

    getchar();// to read the /n character after the integer input when we press enter key

    printf("type the following text:%s \n",textToBeTyped);

    printf("..................wait..........wait........................\n");
    sleep(5);

    printf("start typing: \n");

    clock_t start = clock();//start the clock
    // input the setence
    gets(userInput);
    clock_t end = clock();//end the clock


    //--input ends here

    //copying original string to copy
    strcpy(copyText,textToBeTyped);
    
    //calls for the fuction to remove spaces
    remove_space(copyText);
    remove_space(userInput);

   double time_taken = ((double)end - start)/CLOCKS_PER_SEC;//calculate the time taken

   //call for the function to calculate speed and accuracy
    Info(copyText,userInput, time_taken ,noWords);
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
void Info(const char *givetext,const char *userInput, double time_taken, int noWords)
{
    int correctChar=0; // number of correct characters
    int totalCharacters = strlen(userInput);//total characters

    //loop which checks if the characters are same in both the strings
    for(int i=0;i<totalCharacters;i++)
        if ((givetext[i]==userInput[i]))
            correctChar++;//increase if the character is correct
        
    // caculate the accuracy 
    double accuracy = (double)correctChar/totalCharacters *100.0;

    // caculate the speed
    double speed = (double)(totalCharacters/noWords)/(time_taken/60.0);


    // -- final output
    printf("user accuracy = %lf \t",accuracy);
    printf("number of words per minute = %lf \n",speed);

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
