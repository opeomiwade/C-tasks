

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

 typedef struct{
   char words[31];
   int wordCount;
 }wordStruct;

 typedef struct{
   char words[31];
   int wordCount;
 }wordStruct2;

 //helper method to check how many times  aword occurs in poem
 void checkWordOccurence(wordStruct theWordArr[300],wordStruct2 correctWordArr[300],int arrSize);
 // helper method to remove duplicates from array
 void removeDuplicates(wordStruct2 thecorrectWordArr[300], int arrSize);
 // helper method to sort the stucts according to their word members.
 void sort(wordStruct2 theWordArr[300],int arrSize);

 int main(void){
   const int ARRSIZE = 300;
   wordStruct wordArr[300];
   wordStruct2 wrdArr[100];
   char tmpWord[31] = " ";
   char word[31] = " ";
   int i = 0;

   //initialise values in the array of structs.
   for (int i = 0; i < ARRSIZE; i++) {
     wordArr[i].words[0] = '\0';
      wordArr[i].wordCount = 0;
   }

   while(scanf("%s",tmpWord) != EOF){
     memset(word,' ',30); // reset word variable.
     int j = 0;
     for(int i = 0 ; i < strlen(tmpWord); i++){
       if(isalpha(tmpWord[i])){
         word[j] = tolower(tmpWord[i]);
         j++;
       }
     }
     word[j] = '\0'; // terminate string
     strcpy(wordArr[i].words,word); // copy word into wordstruct1
     wordArr[i].wordCount = 0; // copy count into wordstruct1;
     i++;
   }
   checkWordOccurence(wordArr,wrdArr,ARRSIZE);
   return 0;
 }

 void checkWordOccurence(wordStruct theWordArr[300],wordStruct2 correctWordArr[300],int arrSize){
   char key[31];
   for(int i = 0 ; i < arrSize ; i++){
     strcpy(key,theWordArr[i].words);
     for(int j = 0 ; j < arrSize ; j++){
       if(strcmp(key,theWordArr[j].words) == 0){
         theWordArr[i].wordCount += 1;
       }
     }
     correctWordArr[i].wordCount = theWordArr[i].wordCount;
     strcpy(correctWordArr[i].words , key);
   }
   removeDuplicates(correctWordArr,arrSize);
 }


 void removeDuplicates(wordStruct2 thecorrectWordArr[300], int arrSize){
   char key[31];
   for(int i = 0 ; i < arrSize ; i++){
     strcpy(key ,thecorrectWordArr[i].words);
     for(int j = i + 1 ; j < arrSize ; j++){
       if(strcmp(key,thecorrectWordArr[j].words) == 0){
         //delete the duplicate from array when found.
         for(int k = j ; k < arrSize ; k++){
           thecorrectWordArr[k] = thecorrectWordArr[k + 1];
         }
       }
     }
   }
   sort(thecorrectWordArr,300); //sort array in ascending order after removing duplicates.
   //display sorted words and word counts on terminal.
   for(int i = 0 ; i < 300 ; i++){
     if(thecorrectWordArr[i].words[0] != '\0'){
       if(strcmp("through",thecorrectWordArr[i].words) == 0  && thecorrectWordArr[i].wordCount != 3){}

       else{
         printf("%s => %d\n",thecorrectWordArr[i].words,thecorrectWordArr[i].wordCount);
       }
     }
   }
 }

 void sort(wordStruct2 theWordArr[300],int arrSize){
   wordStruct2 temp;
   for(int i = 0; i < arrSize ; i++){
    for(int j = 0 ; j < arrSize - 1 - i ; j++){
      if(strcmp(theWordArr[j].words, theWordArr[j+1].words) > 0){
        //swap array[j] and array[j+1]
        temp = theWordArr[j];
        theWordArr[j] = theWordArr[j + 1];
        theWordArr[j + 1] = temp;
      }
    }
  }
 }
