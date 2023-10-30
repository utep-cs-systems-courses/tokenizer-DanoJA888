#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
 return ((c == '\t' || c == ' ') && c != '\0') ? 1 : 0;
}

int non_space_char(char c){
  return (c != '\t' && c != ' ' && c != '\0') ? 1 : 0;
}

char *token_start(char *str){
  
  int c = 0, i = 0;
  while(space_char(c = *(str + i))) {
    i++;
  }
  
  return (c == '\0') ? NULL : str + i;

}

char *token_terminator(char *token){
  int i = 0;

  while(non_space_char(*(token + i))) {
    i++;
  }
  
  return token + i;

}

int count_tokens(char *str){
  
  int wordCount = 0;
  char *tempPtr = token_start(str);

  while(tempPtr != NULL) {
    if(non_space_char(*(tempPtr))) {
      wordCount++;
    }  
    tempPtr = token_terminator(tempPtr);
    tempPtr = token_start(tempPtr);
  }
  
  return wordCount;
  
}

char *copy_str(char *inStr, short len){
  char *copyStr = (char*)malloc((len + 1) * sizeof(char));
  int i;
  
  for(i = 0; i < len; i++) {
    *(copyStr + i) = *(inStr + i);
  }
  
  *(copyStr + i) = '\0';
  return copyStr;
  
}

char **tokenize(char *str){
  
  int numTokens = count_tokens(str);
  char **tokens = malloc((numTokens + 1) * sizeof(char *));
  char *tempPtr = str;
  int i;
  
  for(i = 0; i < numTokens; i++) {
    tempPtr = token_start(tempPtr);
    int tokenLength = get_token_length(tempPtr);
    *(tokens + i) = copy_str(tempPtr, tokenLength);
    tempPtr = token_terminator(tempPtr);
  }
  
  *(tokens + i) = 0;
  return tokens;
  
}

void print_tokens(char **tokens){
  
  for(int i = 0; *(tokens + i) != 0; i++) {
    printf("tokens[%d] = ", i);
    printf("%s\n", *(tokens + i));
  }
  
}

void free_tokens(char **tokens){
  
  for(int i = 0; *(tokens + i) != 0; i++) {
    free(*(tokens + i));
  }
  
  free(tokens);
}

int get_token_length(char *tokenStart){
  int count = 0;
  char c, *tempPtr = tokenStart;
  
  while (non_space_char(c = *(tempPtr + count))  && c != '\0'){
    count++;
  }

  return count;
}

int get_str_length(char *str){
  int count = 0;
  char *temp = str;
  
  while (*temp != '\0') {
    count++;
    temp = temp + count;
  }
  
  return count;
}
