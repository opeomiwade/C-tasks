
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
int compressOrExpand();// helper method used to decide if to compress or expand the txt file.
int main(void){
  char userInput;
  int i = 0;
  char previousChar = '\0';
  char currentChar;
  char nextChar = '\0';
  int loopCounter = 0;
  int currentCharCount = 1; // variable to store count of the characters
  int boolean = compressOrExpand();
  while(scanf("%c",&userInput) != EOF){
    currentChar = userInput;
    if(boolean == 1){ // compression happens in this if block
      if(currentChar == previousChar){
        currentCharCount++;
      }

      else{
        if(currentCharCount > 1){
          printf("%c%c%d*",previousChar,previousChar,currentCharCount);
          currentCharCount = 1;
        }

        else{
          if(previousChar != '\0'){
            printf("%c",previousChar);
          }
        }
      }
    }

    else{ // expansion happens here.
      if(currentChar == previousChar){
        printf("%c",previousChar); // print initial two charcters in RLE
        currentCharCount ++;
      }

      else{
        bool flag = false; // bool flag to check if the while loop has been entered
        if(currentCharCount > 1){
          while(scanf("%c",&nextChar) != EOF && nextChar != '*'){//for number greater than 2 digits
            loopCounter = ((((int) currentChar) - 48) * 10) + (((int) nextChar) - 48);
            flag = true;
          }
          if(flag == false){//for single digit numbers.
            loopCounter = ((int) currentChar - 48);
          }
          for(int i = 2 ; i < loopCounter ; i++){
            printf("%c",previousChar);
          }
          loopCounter = 0; // reset loopcounter variable.
          flag = false; //reset the boolean flag
          currentCharCount = 1; //reset count
        }

        else{
          printf("%c",currentChar); //if char occurs once print it
        }
      }
    }
    previousChar = currentChar; // set previous character to current character after every iteration.
  }

  if(currentCharCount > 1){// check if a sequence was being processed after EOF has been reached.
    printf("%c%c%d*",previousChar,previousChar,currentCharCount);
  }
  return 0;
 }

int compressOrExpand(){
  bool decision = true;//true value means compress while false is expand.
  char firstLine[6] = " "; // string array of first line in text file.
  fgets(firstLine,6,stdin);
  if(firstLine[0] == 'C'){
    decision = true;
  }
  else{
    decision = false;
  }
  return decision;
}
