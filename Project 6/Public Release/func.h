#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int adduser(char UID[100], char GID[100], char comments[100], char username[]);
int join(char path[], char filename[]);
int execpasswd(FILE* passwdfile, char passwdline[200], char UID[100], char GID[100], char comments[100], char username[]);
int verifypasswd(FILE* file, char username[], char UID[],char GID[]);
int Write(char username[], FILE* shadowfile);
