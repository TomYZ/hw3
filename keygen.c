//
//  keygen.c
//  hw3
//
//  Created by Zhen Yang on 2/20/16.
//
//

#include <stdio.h>
#include "stream.c"
#include <string.h>

void keygen(int period, char* pphrase){
    char *key=(char*)malloc(27);
    int i,L,R,temp,k;
    unsigned int X;
    char* state="abcdefghijklmnopqrstuvwxyz";
    unsigned char *keybuffer=(unsigned char*)malloc(200*period);
    stream(pphrase,200*period,keybuffer);
//    keybuffer[200*period]='\0';
    //printf("pphaars%d\n",period);
    
    
    // folowing code is modified from http://merlot.usc.edu/cs531-s16/homeworks/hw3/  Random Permutation
    for (i=0; i<period; i++) {//period of permutation
        strcpy(key, state);
        for (k=0; k<2; k++) {
        L=26;
        while(L>1){
            X=((*keybuffer)<<24)+((*(keybuffer+1))<<16)+((*(keybuffer+2))<<8)+(*(keybuffer+3));
            //get 4 bytes to generate a integer X
            keybuffer+=4;
            R=X%L;
            if(R!=L-1){//swap R and L-1
                temp=key[L-1];
                key[L-1]=key[R];
                key[R]=temp;
            }
            L=L-1;
            // citation end
        }
        }
        key[26]='\0';
        printf("%s\n",key);
    }
    free(key);
    free(keybuffer);
}
