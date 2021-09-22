#include <stdio.h>
#include <string.h>

void printTheAmountOfWords(char *fileName){

}
void printTheFileSize(char *fileName){

}
int checkIfCommand(char *command){
    printf("%s",command);
    char *listOfCommands[] = {"-l","--lines","-c","--bytes", "-w","--words"};
    for(int i=0; i<sizeof listOfCommands / sizeof *listOfCommands; i++){
        if(strcmp(command, listOfCommands[i]) == 0)
            return 1;
    }
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("not required amount of params passed");
        return 0;
    }
    char *command = argv[1];
    printf("%d", checkIfCommand(command));

}





