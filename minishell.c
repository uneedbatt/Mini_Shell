#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <sys/wait.h>  



#define BUFFER_SIZE 1024 
#define  MAX_ARGS 100 


int main(){
        while(1){

        
        printf("myshell>");

        char buffer[BUFFER_SIZE];
        char *argv[MAX_ARGS];

        if(fgets(buffer,sizeof(buffer),stdin)!= NULL){
            buffer[strcspn(buffer,"\n")] = '\0' ;
          
            
            char *token ;
            token = strtok(buffer," ");

            int found = 0 ;
            
            while(token!=NULL){
                 argv[found] = token ;
                found ++;
                token = strtok(NULL," ");
            }
            
            argv[found] = NULL ;
            

            if(found == 0 ) continue;

            if(strcmp(argv[0],"exit")==0) break;
            
            pid_t pid = fork();

            if(pid < 0){
                perror("Fork failed");
                exit(EXIT_FAILURE);
            }else if (pid == 0 ){

                if(execvp(argv[0],argv) < 0 ){

                        perror("Execution failed");
                        exit(EXIT_FAILURE);

                }
            }else{
                wait(NULL);
            }


        }else{
            printf("\nNo input received .\n");
        }


    }
  printf("Bye!\n");

    return 0 ;

}