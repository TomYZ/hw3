//
//  histo.c
//  hw3
//
//  Created by Zhen Yang on 2/20/16.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
void histo(int period,int which,FILE *input){
    int table[26];
    int count=0;
    int tempi=-1,temp=-1,j,k;
    for(j=0; j<26; j++) {
        table[j] = 0;
    }
    char* in=(char*)malloc(period);
    fread(in,1,which-1,input);//which
    while (fread(in,1,period,input)) {
        if((*in)<='z'&&(*in)>='a'){//if it is a letter, then table it
            table[(*in)-'a']++;
            count++;
        }
    }
    printf("L=%d\n",count);
    for (j=0;j<26; j++) {
        table[tempi]=-1;
        tempi=-1;
        temp=-1;
        for (k=0; k<26; k++) {// pick up the largest one
            if (table[k]>temp) {
                temp=table[k];
                tempi=k;
            }
        }
        printf("%c: %d (%.2f%%)\n", 'a'+tempi,temp,((double)(temp*100)/count));//output the letter and its frenquency
        
    }
}
