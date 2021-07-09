#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main(int argc, char *argv[]){

    //There Is Arguments
    if(argc>1 && (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)  ){

        printf("$HELP FOR THIS PROGRAM$");


    }else{

        //Our Program Is Here

        printf("*PROCESS MANAGER* <Enter your choice>"
               "\nA. List all the processes in the system."
               "\nB. List all the processes grouped by user."
               "\nC. Display process ID of all the processes."
               "\nD. Run/stop a specific process."
               "\nE. Send specific signal to specific process."
               "\nTo Quit Press Q."
               "\n=> ");


        char choice;
        scanf("%s", &choice);

        choice = toupper(choice);

        char *signal, *pid, flag;

        switch(choice){

            case 'A':
                system("ps -la");break;

            case 'B':
                system("ps -ua");break;

            case 'C':
                system("");break;
            case 'D':
                printf("Enter process ID => ");
                scanf("%s", &pid);
                printf("R for Run / S for Stop => ");
                scanf("%s", &signal);
                if(flag == 'S'){
                    signal = "STOP";
                }else if(flag == 'R'){
                    signal = "CONT";
                }
                system(strcat("kill [",strcat(signal,strcat("] ",pid))));break;
            case 'E':
                printf("Signal => ");
                scanf("%d", &signal);
                printf("PID => ");
                scanf("%d", &pid);
                system(strcat("kill [",strcat(signal,strcat("] ",pid))));break;
            case 'Q':
                exit(0);break;
            default:
                printf("Enter valid value!");
        }

    }

return 0;
}
