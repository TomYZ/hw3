//
//  crypt.c
//  hw3
//
//  Created by Zhen Yang on 2/20/16.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
void crypt(FILE *keyfile,FILE *input){
    char* keybuffer=(char*)malloc(27);//keybuffer
    char* in=(char*)malloc(1);
    char temp;
    int i=0,count=0;
    
    // the following code is modified from http://stackoverflow.com/questions/238603/how-can-i-get-a-files-size-in-c
    fseek(keyfile, 0, SEEK_END);
    int len = ftell(keyfile);//get the length of keyfile
    fseek(keyfile, 0, SEEK_SET);
    //citation end
    
    if(len%27!=0){
        fprintf(stderr,"malformed keyfile\n");
        return;
    }
    

    int line=len/27;//how many lines of keyfile
    fread(keybuffer,27,1,keyfile);
    while (fread(in,1,1,input)) {
        if (i%line==0) {
            fseek(keyfile,0,SEEK_SET);//after a period (lines), seek to the starting point
        }
        fread(keybuffer,27,1,keyfile);//read one permutation key (27) each time
        if(*in=='\n'){//if '\n', output '\n'
            printf("\n");
            break;
        }
        else if ((*in)>='a'&&(*in)<='z') {// if it is a letter
            count=(*in-'a');
            temp=*(keybuffer+count);//encrypt in using keybuffer
            printf("%c",temp);
        }else{
            printf("%c",*in);
        }
        i++;
    }
    free(in);
    free(keybuffer);
}

