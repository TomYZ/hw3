//
//  hw3.c
//  hw3
//
//  Created by Zhen Yang on 2/22/16.
//
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "keygen.c"
#include "crypt.c"
#include "invkey.c"
#include "histo.c"
#include "solve.c"

int main(int argc, char *argv[]) {
    int period=0,which=0,max_t;
    FILE* keyfile = NULL;
    FILE* file=NULL;
    if(argc <= 1) {
        fprintf(stderr,"malformed command\n");
        return 0;
    } else {
        if(strcmp(argv[1], "keygen") == 0) {//using keygen command
            if (argc<4) {
                fprintf(stderr,"malformed command\n");
                return 0;
            }
            else{
                keygen(atoi(argv[3]+3),argv[2]+3);
            }
            
        }
        else if(strcmp(argv[1], "crypt") == 0) {//using crypt command
            if(argc<=2){
                fprintf(stderr,"malformed command\n");
                return 0;
            }
            keyfile =fopen(argv[2]+3, "r");
            if (keyfile==NULL) {
                fprintf(stderr, "cannot open keyfile\n");//can not open key file
                return 0;
            }
            if(argv[argc-1][0]!= '-') {//input from file
                file=fopen(argv[argc-1], "r");
                crypt(keyfile, file);
            } else {
                crypt(keyfile, stdin);//input from stdin
            }
        
        }
    else if(strcmp(argv[1], "invkey") == 0) {//using invkey command
        if(argc<= 2) {
            fprintf(stderr,"malformed command\n");
            return 0;
        } else {
            file = fopen(argv[argc-1], "r");
            invkey(file);
        }
    }
    else if(strcmp(argv[1], "histo") == 0) {//using histo command
        period=atoi(argv[2]+3);
        which=atoi(argv[3]+3);
        if(period!=0&&which!=0) {
            if(argv[argc-1][0]!='-') {
                file = fopen(argv[4], "r");
                histo(period, which, file);
            } else {
                histo(period, which, stdin);
            }
        } else {
            fprintf(stderr,"malformed command\n");
        }
    }
    else if(strcmp(argv[1], "solve") == 0) {//using solve command
        max_t = atoi(argv[2]+3);
        if(max_t!=0) {
            file=fopen(argv[3], "r");
            if(file==NULL) {
                fprintf(stderr, "input file %s does not exist\n",argv[argc-1]);
                return 0;
            }
            solve(max_t, file);
        } else {
            fprintf(stderr,"malformed command\n");
            return 0;
        }
    }
    else {
        fprintf(stderr,"malformed command\n");//argument not right
    }
}
fclose(file);
fclose(keyfile);
return 0;
}


