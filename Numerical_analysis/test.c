#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void){
    int count[27]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int i, n=0;
    float freq;
    char ch;
    FILE *fp1;

    if((fp1 = fopen("out_text.txt","r"))== NULL){
        printf("ファイルが開けませんでした");
        exit(1);
    }

    while(feof(fp1)==0){
        ch = fgetc(fp1);
        n++;
        for(i=0;i<26;i++){
            if(ch == 'a'+i){
                count[i]++;
                break;
            }
            if(ch == ' '){
                count[26]++;
                break;
            }
        }
    }
    printf("%d", n);

    for(i=0;i<27;i++){
        freq = (float)count[i]/(float)n;
        printf("%.2f %d\n", freq, count[i]);
    }
    

    fclose(fp1);

    return 0;
}