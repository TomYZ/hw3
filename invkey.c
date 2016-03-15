//
//  invkey.c
//  hw3
//
//  Created by Zhen Yang on 2/20/16.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
void invkey(FILE* keyfile){
    char* key=(char*)malloc(27);//keyfile buffer
    char*invkey=(char*)malloc(27);//invkey buffer
    int i=0,temp;
    while(fgets(key,30,keyfile)){
        if(strlen(key)!=27){
            fprintf(stderr,"malformed key file\n");//every line in keyfile can be divided by 27: 26+1
            return;
        }
        for (i=0;i<26;i++) {
            temp=key[i]-'a';
            invkey[temp]='a'+i;
            //printf("temp:%d ",temp);
        }
        invkey[i]='\0';
        printf("%s\n",invkey);
    }
}

