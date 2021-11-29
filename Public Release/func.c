
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "func.h"

int adduser(char UID[100], char GID[100], char comments[100], char username[]){
    char spath[100];
    char ppath[100];
    join(spath, "shadow");
    join(ppath, "passwd");
    FILE *shadow = fopen(spath, "a+");
    FILE *passwd = fopen(ppath, "a+");
    if (!shadow){
        printf("FAILED\n");
        return 0;
    }
    if (!passwd){
        printf("FAILED\n");
        return 0;
    }


    char passwdline[200] = "";
    if (execpasswd(passwd, passwdline, UID, GID, comments, username)){
        Write(username, shadow);
    }
    fclose(shadow);
    fclose(passwd)
;    
}

int join(char path[], char filename[]){
    
    if (!getenv("PFILE")){
    }
    else{
        strcpy(path, getenv("PFILE"));
        strcat(path, filename);  
    }
}

int execpasswd(FILE* passwdfile, char passwdline[200], char UID[100], char GID[100], char comments[100], char username[]){
    if (verifypasswd(passwdfile, username, UID)){
        strcat(passwdline, username);
        strcat(passwdline, ":x:");
        strcat(passwdline, UID);
        strcat(passwdline, ":");
        strcat(passwdline, GID);
        strcat(passwdline, ":");
        strcat(passwdline, comments);
        strcat(passwdline, "/home/");
        strcat(passwdline, username);
        strcat(passwdline, ":/bin/bash\n");
        fprintf(passwdfile, "\n%s", passwdline);
        return 1;
    }
    else{
        printf("Non Unique username or UID\n");
        return 0;
    }
}




int verifypasswd(FILE* file, char username[], char UID[]){  
    int lines = 0;
    int flag = 0;
    char line[100];  
    char lineduplicate[100];
    //int size = strlen(username);
    //printf("WOO");
    char word[100] = "";
    while(fgets(line, 100, file) != NULL) { 
        strcpy(lineduplicate, line);
        strcpy(word, strtok(lineduplicate, ":"));
        //printf("%s %s\n", word, username);
        if (strcmp(word, username) == 0){
            
            return 0;
        }
        strcpy(word, strtok(NULL, ":"));
        strcpy(word, strtok(NULL, ":"));
        //printf("%s %s\n", word, UID);
        if (strcmp(word, UID) == 0){
            
            return 0;
        }
    }
    return 1;

}

int Write(char username[], FILE* shadowfile){

    if (shadowfile){
        fprintf(shadowfile, "\n%s::0:18372:9999:7:::", username);
        return 1; 
    }
    
}

