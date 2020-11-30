#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//確率的自然言語生成プログラムです
int main(void){

    FILE *fp1,*fp2;
    int count[27]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int i, j, n=0;
    float freq;
    char ch;
    
    //テキストファイルを読み込んでスペースと半角アルファベットのみを別のテキストファイルに書くプログラム
    if((fp1 = fopen("tom_sawyer.txt","r"))== NULL){
        printf("ファイルを開けませんでした");
        exit(1);
    }
    if((fp2 = fopen("out_text.txt","w"))==NULL){
        printf("ファイルを開けませんでした");
        exit(1);
    }

    while(feof(fp1)==0){
        ch = tolower(fgetc(fp1));
        if(isalpha(ch)!= 0 || ch == ' ' || ch == '\n'){
            if(fputc(ch,fp2) == EOF){
            printf("ファイルに書き込めませんでした");
            exit(1);
            }
        }else{
            ch=' ';
            fputc(ch,fp2);
        }
        if(n<=700){
            putchar(ch);
        }
        n++;
    }
    fclose(fp1);
    fclose(fp2);

    //読み込み、変換したテキストファイルから文字の出現頻度を調べるプログラム
    if((fp1 = fopen("out_text.txt","r"))== NULL){
        printf("ファイルが開けませんでした");
        exit(1);
    }
    if((fp2 = fopen("out_text.txt","rb"))== NULL){
        printf("ファイルが開けませんでした");
        exit(1);
    }

    printf("\n\n文字の出現頻度");

    n=0;
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
    printf("\n");


    for(i=0;i<26;i++){
        freq = (float)count[i]/(float)n;
        printf("%c.  %.3f %d\n", 'a'+i, freq, count[i]);
    }
    freq = (float)count[i]++/(float)n;
    printf(" .  %.3f %d\n", freq, count[i]++);
    

    //簡便法を使ってランダム生成のプログラム
    printf("\n100文字出力\n");
    for(j=0;j<100;j++){
        i = rand();
        //printf("%d ", i/5111);
        i = i/5111;
        fseek(fp2, i, SEEK_SET);
        printf("%c", fgetc(fp2));
    }
    printf("\n");
    
    fclose(fp1);
    fclose(fp2);
    return 0;

}