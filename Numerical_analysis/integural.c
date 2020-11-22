#include <stdio.h>
#include <math.h>

#define N 300

#define f(x) (x*x+2*x-1)//(x*x*x*x-2*x*x*x+x*x-3*x+1)
#define g(x) (1/x)

//台形法、シンプソン則を使って積分を行う

int main(void){

    //台形法による数値積分    //完成
    int n;
    double x1, x2, y1, y2, r1, r2, result, result2, dx;
    double x3, x4, r3, r4, dx2;
 
    r1 = 4; r2 = 0;
    result = 0;
    dx = (r1-r2)/N;

    x1 = r2; x2 = r2+dx;

    for(n=0;n<N;n++){
        result += ((f(x1)+f(x2))*dx)/2;
        x1 += dx;
        x2 += dx;
    }
    printf("answer1 = %f\n", result);

    r3 = 2; r4 = 1;
    result2 = 0;
    dx2 = (r3-r4)/N;

    x1 = r4; x2 = r4+dx2;

    for(n=0;n<N-1;n++){
        result2 += ((g(x1)+g(x2))*dx2)/2;
        x1 += dx2;
        x2 += dx2;
    }
    printf("answer2 = %f\n", result2);
    
    //シンプソン法

    
    return 0;
}