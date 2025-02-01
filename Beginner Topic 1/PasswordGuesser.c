#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH 10

int main
{
    //initialize variables
    char *file_name = NULL;
    char *path = NULL;
    char *password = NULL;
    char *dest_dir = NULL;
    int pswd_index = 0;
    //Get the file name and path from the user
    printf("Enter the file name: ");
    scanf("%[^\n]", file_name);
    printf("Enter path: ");
    scanf("%s", path);
    //Create a temporary directory to store the extracted files.
    dest_dir = malloc(strlen(path)+ 10);
    strcpy(dest_dir, path);
    strcat(dest_dir, "\\temp");
    mkdir(dest_dir);

    //start the password cracking loop.
    while(1)
    {
        //generate a random password
        password = malloc(10);
        for(int i; i < 10; i++)
        {
            password[i] = (char)rand() % 256;
        }
        //try to extract the file with the generated password
        pswd_index++;
        int ret = unrar_extract(file_name, path, password, dest_dir);
        //if the file was extracted successfully, then break out of the loop
        if(ret == 0)
        {
            printf("Password found! Password %s\n", password);
            break;
        }
    }

    //free the allocated memory
    free(file_name);
    free(path);
    free(password);
    free(dest_dir);

    return 0;

}
