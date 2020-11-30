#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void){
        int count[27][27]={{0, 'a'},{0,'b'},{0,'c'},{0, 'd'},{0, 'e'},{0,'f'},{0,'g'},{0,'h'},{0,'i'},{0,'j'},{0,'k'},{0,'l'},{0,'m'},{0,'n'},{0,'o'},
                    {0,'p'},{0,'q'},{0,'r'},{0,'s'},{0,'t'},{0,'u'},{0,'v'},{0,'w'},{0,'x'},{0,'y'},{0,'z'}};
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
                count[i][i]++;
                break;
            }
            if(ch == ' '){
                count[26][26]++;
                break;
            }
        }
    }
    printf("%d", n);

    for(i=0;i<27;i++){
        freq = (float)count[i][i]/(float)n;
        printf("%.2f %d\n", freq, count[i][i]);
    }
    fclose(fp1);

    for(i=0;i<27;i++){
        
    }

    return 0;
}