#include <stdio.h>

// clientData structure definition               
typedef struct data {
    char name[20];
    int ID;
    int math, comput;
    float AVG;
}stu;

int main(void)
{
    FILE* cfPtr = NULL; // accounts.dat file pointer

    // fopen opens the file; exits if file cannot be opened
    if ((fopen_s(&cfPtr,"accounts.dat", "rb")) != 0) {
        puts("File could not be opened.");
    }
    else {
        printf("%-6s%-19s%-6s%-6s%10s\n", 
            "ID", 
            "name",
            "math", 
            "comput", 
            "AVG");


        while (!feof(cfPtr)) {
            stu BlankData = { "", 0, 0, 0, 0.0 };

            int result = fread(&BlankData, sizeof(struct data), 1, cfPtr);

            // display record
            if (result != 0 && BlankData.ID != 0) 
            {
                printf("%-6d%-19s%-6d%-6d%10.2f\n",
                    BlankData.ID, 
                    BlankData.name,
                    BlankData.math, 
                    BlankData.comput, 
                    BlankData.AVG);
            }
        }

        fclose(cfPtr); 
    }
}