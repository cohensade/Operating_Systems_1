#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>


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
    if (argc != 2) { // checking that we have the right number of args 
         printf("Invalid input (correct input need to: \"name\"\n");
        return 1; // Exit with error code
    }
    const char *name = argv[1]; //name

    if (!is_valid_name(name)) { //checking if the name is valid
        printf("Error: Name cannot contain commas and numbers.\n");
        return 1;
    }

    int pipe1[2], pipe2[2], pipe3[2]; // Declare pipes 

    if (pipe(pipe1) == -1) { // Create the first pipe
        perror("pipe1"); // Print error message if pipe creation fails
        return 1; 
    }

    if (pipe(pipe2) == -1) { // Create the second pipe
        perror("pipe2"); // Print error message if pipe creation fails
        close(pipe1[0]); // Close the first pipe if second pipe creation fails
        close(pipe1[1]);
        return 1; 
    }

    if (pipe(pipe3) == -1) { // Create the third pipe
        perror("pipe3"); // Print error message if pipe creation fails
        close(pipe1[0]); // Close the first and second pipes if third pipe creation fails
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);
        return 1; 
    }

    pid_t pid1 = fork(); // Create the first child process
    if (pid1 == -1) { // Check if fork failed
        perror("fork1"); // Print error message if fork fails
        return 1; 
    }

    if (pid1 == 0) { // First child process:"grep(name) from phonebook.txt"
        dup2(pipe1[1], STDOUT_FILENO); // Redirect stdout to the write end of the first pipe
        close(pipe1[0]); // Close unused read end of the first pipe
        close(pipe1[1]); // Close the write end after duplication
        close(pipe2[0]); // Close all other pipe ends
        close(pipe2[1]);
        close(pipe3[0]);
        close(pipe3[1]);
        execlp("grep", "grep", name, "phonebook.txt", (char *) NULL); //execlp ( command to execute, the program , name,the file, end of argument list)
        perror("execlp grep"); // Print error message if execlp fails
        exit(1); 
    }

    pid_t pid2 = fork(); // Create the second child process
    if (pid2 == -1) { // Check if fork failed
        perror("fork2"); // Print error message if fork fails
        return 1; 
    }

    if (pid2 == 0) { // Second child process: execute "sed 's/ /#/g'" (aka replace space with #)
        dup2(pipe1[0], STDIN_FILENO); // stdin read from pipe1[0](stdin read from end of first pipe)
        dup2(pipe2[1], STDOUT_FILENO); // pipe2[1] writing to stdout
        close(pipe1[1]); // Close the unused write end of the first pipe
        close(pipe1[0]); // Close the read end after duplication
        close(pipe2[0]); // Close the unused read end of the second pipe
        close(pipe2[1]); // Close the write end after duplication
        close(pipe3[0]); // Close all other pipe ends
        close(pipe3[1]);
        execlp("sed", "sed", "s/ /#/g", (char *) NULL); //execlp ( command to execute, the program , replace space to #,the file, end of argument list)
        perror("execlp sed1"); // Print error message if execlp fails
        exit(1); 
    }

    close(pipe1[0]); // Close the read end of the first pipe in the parent process
    close(pipe1[1]); // Close the write end of the first pipe in the parent process

    pid_t pid3 = fork(); // Create the third child process
    if (pid3 == -1) { // Check if fork failed
        perror("fork3"); // Print error message if fork fails
        return 1; 
    }

    if (pid3 == 0) { // Third child process: execute "sed 's/,/ /'" (replace , with space)
        dup2(pipe2[0], STDIN_FILENO); // stdin read from pipe2[0]
        dup2(pipe3[1], STDOUT_FILENO); // pipe3[1] writing to stdout
        close(pipe2[1]); // Close the unused write end of the second pipe
        close(pipe2[0]); // Close the read end after duplication
        close(pipe3[0]); // Close the unused read end of the third pipe
        close(pipe3[1]); // Close the write end after duplication
        execlp("sed", "sed", "s/,/ /", (char *) NULL); //execlp ( command to execute, the program , replace , to space,the file, end of argument list)
        perror("execlp sed2"); // Print error message if execlp fails
        exit(1); 
    }

    close(pipe2[0]); // Close the read end of the second pipe in the parent process
    close(pipe2[1]); // Close the write end of the second pipe in the parent process

    pid_t pid4 = fork(); // Create the fourth child process
    if (pid4 == -1) { // Check if fork failed
        perror("fork4"); // Print error message if fork fails
        return 1; 
    }

    if (pid4 == 0) { // Fourth child process:awk(print the output from our privious process )
        dup2(pipe3[0], STDIN_FILENO); // stdin read from pipe3[0]
        close(pipe3[1]); // Close the unused write end of the third pipe
        close(pipe3[0]); // Close the read end after duplication
        execlp("awk", "awk", "{printf \"%s %s %s\\n\", $1, $2, $3}", (char *) NULL); 
        ////execlp ( command to execute, the program , print,  end of argument list)
        perror("execlp awk"); // Print error message if execlp fails
        exit(1); 
    }

    close(pipe3[0]); // Close the read end of the third pipe in the parent process
    close(pipe3[1]); // Close the write end of the third pipe in the parent process

    // Wait for all child processes to finish
    wait(NULL);
    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0; 
}
