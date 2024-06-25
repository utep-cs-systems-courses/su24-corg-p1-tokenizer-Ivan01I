#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 100
int get_input(char *p);
int get_input(char *p){
    char current_char;
    int i = 0;
    while(i < MAX){
        current_char = getchar();
        if(current_char == '\n'){
            p[i] = '\0';
            break;
        }
        p[i++] = current_char;
    }
    if(i == MAX - 1){
        p[i] = '\0';
    }
    return i;
}
int main()
{
  List *history = init_history();
  char input[MAX];
    char *p = input;
    while(1){
        int length = 0;
        printf("Word, History: 'h', Item: '!n', or Quit: 'q'\n");
        printf("$ ");
        length = get_input(p);
        if(p[0] == 'h' && length < 2){
            print_history(history);
        }
        else if(p[0] == '!'){
            int id = atoi(&p[1]);
            char *recalled = get_history(history, id);
            if(recalled){
                printf("%s\n", recalled);
            }
        }
        else if(p[0] == 'q' && length < 2) {
            break;
        }
        else{
            add_history(history, p);
            printf("%s\n", p);
	    char **tokens = tokenize(p);
            if(tokens != NULL){
                free_tokens(tokens);
            }
	}
    }
    free_history(history);
    return 0;
}
