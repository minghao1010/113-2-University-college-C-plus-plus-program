#include <stdio.h>

// clientData structure definition               
typedef struct student {   
    char    name[20];
    int     ID;
    int     math, comput;
    double   AVG;
}stu;

int main(void)
{
    FILE* cfPtr=NULL; // accounts.dat file pointer

    // fopen opens the file; exits if file cannot be opened
    if ((fopen_s(&cfPtr,"accounts.dat", "rb+"))!=0) {
        puts("File could not be opened.");
    }
    else {
        // create clientData with default information
        struct student client = {" ", 0,0,0,0.0};

        // require user to specify account number
        printf("%s", "Enter ID"
            " (1 to 100, 0 to end input): ");
        scanf_s("%d", &client.ID);

        // user enters information, which is copied into file
        while (client.ID != 0) {
            // user enters last name, first name and balance
            printf("%s", "Enter name, math, comput: ");

            // set record lastName, firstName and balance value
            fscanf_s(stdin, "%19s %d %d", client.name,19,&client.math, &client.comput);
            client.AVG = (client.math + client.comput) / 2;

            // seek position in file to user-specified record   
            fseek(cfPtr, (client.ID - 1) *
                sizeof(struct student), SEEK_SET);

            // write user-specified information in file              
            fwrite(&client, sizeof(struct student), 1, cfPtr);

            // enable user to input another account number
            printf("%s", "Enter ID: ");
            scanf_s("%d", &client.ID);
        }

        fclose(cfPtr); // fclose closes the file
        return 0;
    }
}



