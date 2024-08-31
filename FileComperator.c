#include "string.h"
#include <unistd.h>
#include "stdlib.h"
#include <fcntl.h>

//function that prints the error type if it occurs
void printError(char *errType) {
    if(write(1, errType, strlen(errType)) == -1){

    }
    exit(-1);
}

int main(int argc, char *argv[]) {
    //checks if there are 2 parameters
    if (argc < 3) {
        printError("Error in: parameters\n");
    }
    //the two files received from user.
    char *file1 = argv[1];
    char *file2 = argv[2];
    int fd1 = 1, fd2 = 1;
    //checks if there is file1 and if there is permission to read from this file
    if (access(file1, F_OK) == 0 && access(file1, R_OK) == 0) {
        //opens in read only mode file1
        fd1 = open(file1, O_RDONLY);
        if (fd1 == -1) {
            printError("Error in: open\n");
        }
    } else {
        printError("Error in: access\n");
    }
    //checks if there is file2 and if there is permission to read from this file
    if (access(file2, F_OK) == 0 && access(file2, R_OK) == 0) {
        //opens in read only mode file2
        fd2 = open(file2, O_RDONLY);
        if (fd2 == -1) {
            printError("Error in: open\n");
        }
    } else {
        printError("Error in: access\n");
    }

    //3 flags
    int flag = 0, rF1 = 0, rF2 = 0;
    char c1, c2;
    int r1,r2;

    while(1){
        //reads files 1,2
        r1 = read(fd1, &c1, 1);
        r2 = read(fd2, &c2, 1);

        if(r1 < 0){
            printError("Error in: read\n");
        }
        if(r2 < 0){
            printError("Error in: read\n");
        }

        //if both end of file
        if(r1 == 0 && r2 == 0){
            //if both files equal
            if ( flag == 0){
                if (close(fd1) == -1) {
                    printError("Error in: close\n");
                }
                if (close(fd2) == -1) {
                    printError("Error in: close\n");
                }
                return 1;
            //if both file similar
            } else{
                if (close(fd1) == -1) {
                    printError("Error in: close\n");
                }
                if (close(fd2) == -1) {
                    printError("Error in: close\n");
                }
                return 3;
            }
        }
        //end of first file
        if(r1 == 0){
            break;
        }
        //end of 2nd file
        if(r2 == 0){
            break;
        }

        //both chars exact go to read next char
        if(c1 == c2){
            continue;
        }
        //both files are not exactly the same
        flag = 1;


        //read until end of file1 or not enter or space
        while(c1 == ' ' || c1 == '\n'){
            r1 = read(fd1, &c1, 1);
            if(r1<0){
                printError("Error in: read\n");
            }
            else if(r1 == 0){
                rF1 = 1;
                break;
            }
        }
        //read until end of file2 or not enter or space
        while(c2 == ' ' || c2 == '\n'){
            r2 = read(fd2, &c2, 1);
            if(r2 < 0){
                printError("Error in: read\n");
            }
            else if(r2 == 0){
                rF2 = 1;
                break;
            }
        }
        //if one of files are in the end of file
        if(rF1 == 1 || rF2 == 1){
            break;
        }

        //if both chars the same
        if(c1 == c2){
            continue;
        }
        //if both the letters are not equal and not differ by capitality return 2 for different files
        if (c1 < 65 || (c1 > 90 && c1 < 97) || c1 > 122) {
            if (close(fd1) == -1) {
                printError("Error in: close\n");
            }
            if (close(fd2) == -1) {
                printError("Error in: close\n");
            }
            return 2;
            //if both the letters are not equal and not differ by capitality return 2 for different files
        } else if (c2 < 65 || (c2 > 90 && c2 < 97) || c2 > 122) {
            if (close(fd1) == -1) {
                printError("Error in: close\n");
            }
            if (close(fd2) == -1) {
                printError("Error in: close\n");
            }
            return 2;
            //if those letters are differ by capitality
        } else if (c1 > c2 && (c1 - c2 == 32)) {
            continue;
            //if those letters are differ by capitality
        } else if (c2 > c1 && (c2 - c1 == 32)) {
            continue;
        }
        return 2;
    }

    //if file1 done reading
    if(r1 == 0 && r2 > 0){
        while(c2 == ' ' || c2 == '\n'){
            r2 = read(fd2, &c2, 1);
            if(r2<0){
                printError("Error in: read\n");
            }
            else if(r2 == 0){
                if (close(fd1) == -1) {
                    printError("Error in: close\n");
                }
                if (close(fd2) == -1) {
                    printError("Error in: close\n");
                }
                return 3;
            }
        }
        if (close(fd1) == -1) {
            printError("Error in: close\n");
        }
        if (close(fd2) == -1) {
            printError("Error in: close\n");
        }
        //both files different
        return 2;
    }
    //if file2 done reading
    if(r1 > 0 && r2 == 0){
        while(c1 == ' ' || c1 == '\n'){
            r1 = read(fd1, &c1, 1);
            if(r1 < 0){
                printError("Error in: read\n");
            }
            else if(r1 == 0){
                if (close(fd1) == -1) {
                    printError("Error in: close\n");
                }
                if (close(fd2) == -1) {
                    printError("Error in: close\n");
                }
                return 3;
            }
        }
        if (close(fd1) == -1) {
            printError("Error in: close\n");
        }
        if (close(fd2) == -1) {
            printError("Error in: close\n");
        }
        //both files different
        return 2;
    }
    if (close(fd1) == -1) {
        printError("Error in: close\n");
    }
    if (close(fd2) == -1) {
        printError("Error in: close\n");
    }
    //both files are similar
    return 2;
}