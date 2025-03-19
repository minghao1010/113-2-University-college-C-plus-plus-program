#include <stdio.h>

// clientData structure definition               
typedef struct student {
    char    name[20];
    int     ID;
    int     math, comput;
    float   AVG;
}stu;

int main(void)
{
    FILE* cfPtr=NULL; // accounts.dat file pointer

    // fopen opens the file; exits if file cannot be opened
    if ((fopen_s(&cfPtr,"accounts.dat", "rb")) !=0) {
        puts("File could not be opened.");
    }
    else {
        printf("%-6s%-16s%-11s%-16s%10s\n", "ID", "name",
            "math","comput", "AVG");

        // read all records from file (until eof)
        while (!feof(cfPtr)) {
            // create clientData with default information
            struct student client = { " ", 0,0,0,0.0};

            int result = fread(&client, sizeof(struct student), 1, cfPtr);

            // display record
            if (result != 0 && client.ID != 0) {
                printf("%-6d%-16s%-11d%-16d%10.2f\n",
                    client.ID, client.name,
                    client.math,client.comput, client.AVG);
            }
        }

        fclose(cfPtr); // fclose closes the file
    }
}