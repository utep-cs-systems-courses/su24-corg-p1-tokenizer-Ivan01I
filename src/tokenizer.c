#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
int space_char(char c){
  return (c == ' ' || c == '\t');
}
int non_space_char(char c){
    return !space_char(c) && c != '\0';
}
char *token_start(char *s){
    if(s == NULL){
        return NULL;
    }
    while(*s != '\0'){
        if(non_space_char(*s)){
            return s;
        }
        s++;
    }
    return NULL;
}
char *token_terminator(char *token){
    if(token == NULL){
        return NULL;
    }
    while(*token != '\0' && !space_char(*token)){
        token++;
    }
    return token;
}
int count_tokens(char *s){
    if(s == NULL){
        return 0;
    }
    int count = 0;
    int in_token = 0;
    while(*s != '\0'){
        if(non_space_char(*s)){
            if(!in_token){
                count++;
                in_token = 1;
            }
        }
        else{
            in_token = 0;
        }
        s++;
    }
    return count;
}
char *copy_str(char *inStr, short len){
    if(inStr == NULL || len <= 0){
        return NULL;
    }
    char *copy = (char *)malloc((len + 1) * sizeof(char));
    if(copy == NULL){
        return NULL;
    }
    for(short i = 0; i < len; i++){
        copy[i] = inStr[i];
    }
    copy[len] = '\0';
    return copy;
}
char **tokenize(char *s){
    if(s == NULL){
        return NULL;
    }
    int num_tokens = count_tokens(s);
    if(num_tokens == 0){
        return NULL;
    }
    char **tokens = (char **)malloc((num_tokens + 1) * sizeof(char *));
    if(tokens == NULL){
        return NULL;
    }
    int token_index = 0;
    char *start = token_start(s);
    while(start != NULL){
        char *end = token_terminator(start);
        short token_len = end - start;
        tokens[token_index++] = copy_str(start, token_len);
        start = token_start(end);
    }
    tokens[num_tokens] = NULL;
    return tokens;
}
void print_tokens(char **tokens){
    if(tokens == NULL){
        return;
    }
    for(int i = 0; tokens[i] != NULL; i++){
        printf("%s\n", tokens[i]);
    }
}
void free_tokens(char **tokens){
    if(tokens == NULL){
        return;
    }
    for(int i = 0; tokens[i] != NULL; i++){
        free(tokens[i]);
    }
    free(tokens);
}
