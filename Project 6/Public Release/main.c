#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "func.h"

int main(int argc, char **argv ,char *envp[]){
    int opt;
    M_PASSWORD mpass;
    M_SHADOW mshadow;
    setenv(("PFILE", "./etc/"));
    char UID[20] = "";              // Specify UserID
    char GID[20] = "";              // Specify GroupID
    char comments[200] = "";
    char username[200] = "";
    char *temp;
    FILE *fpasswd, *fshadow, *fgroup;        // opening password, shadow and group  files

    fpasswd = openfile (temp, "passwd");
    fgroup = openfile (temp, "group");
    fshadow = openfile (temp, "shadow");


  if (argc < 8)
    {
        printf ("Insufficient number of arguments\n");
        printf ("Usage: %s <-u> <UID) <-g> <GID> <-c> <Comments> <Name>\n");
        exit (1);
    }
memset (&mpass, 0, sizeof (M_PASSWORD));

    printf ("%d command line arguments are passed\n", argc);
    while((opt = getopt(argc, argv, ":u:g:c:")) != -1){
        printf("Enter 'u' for UID , 'g' for GID, or 'c' for entering comments");
        switch(opt)  {                      // Allows user to pick whether they want to check UserId, GroupID or Comments
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

    fclose (fpasswd);               // closing all files
    fclose (fgroup);
    fclose (fshadow);


    return 0;
}


