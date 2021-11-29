#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "func.h"

int main(int argc, char **argv ,char *envp[]){
    int opt;
    setenv("PFILE", "./etc/", 1);
    char UID[20] = "";
    char GID[20] = "";
    char comments[200] = "";
    char username[200] = "";

    while((opt = getopt(argc, argv, ":u:g:c:")) != -1){  
        switch(opt)  {  
            case 'u':
                strcpy(UID, optarg);
                break;  
            case 'g':
                strcpy(GID, optarg);
                break;  
            case 'c':
                strcpy(comments, optarg);
                break;
            default:
                printf("Invalid parameters\n");
        }  
    } 
    strcpy(username, argv[optind]);
    if (!strcmp(UID, "") || !strcmp(GID,"") || !strcmp(username,"")){
        printf("Missing parameters\n");
    }
    adduser(UID, GID, comments, username);
}

