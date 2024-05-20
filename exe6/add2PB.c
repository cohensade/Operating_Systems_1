#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



// Function to check if the phone number is valid
int is_valid_phone_number(const char *phone) {
    while (*phone) {
        if (!isdigit(*phone) && *phone != '-' )  {
            return 0;
        }
        phone++;
    }
    return 1;
}

// Function to check if the name is valid (no commas allowed)
int is_valid_name(const char *name) {
    while (*name) {
        if (*name == ',' || isdigit(*name)) {
            return 0;
        }
        name++;
    }
    return 1;
}


int main(int argc, char *argv[]) {
    if (argc != 3) { //checking that we have the right number of args
        printf("Invalid input (correct input need to: \"name\" phone-number)\n");

        return 1;
    }

    const char *name = argv[1]; //name
    const char *phone_number = argv[2]; // phone number

    if (!is_valid_name(name)) { //checking if the name is valid
        printf("Error: Name cannot contain commas and numbers.\n");
        return 1;
    }

    if (!is_valid_phone_number(phone_number)) { ////checking if the phone number is valid
        printf("Error: Phone number can only contain digits and dashes.\n");
        return 1;
    }

    // Open the phonebook file in append mode
     FILE *file = fopen("phonebook.txt", "a");
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }

    fputs(name, file);
    fputc(',', file);
    fputs(phone_number, file);
    fputc('\n', file);

    fclose(file);

    return 0; 
}

