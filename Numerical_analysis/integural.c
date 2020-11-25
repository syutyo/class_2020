#include <stdio.h>
#include <math.h>

#define f(x) (x*x*x*x-2*x*x*x+x*x-3*x+1)
#define g(x) (1/x)

//台形法とシンプソン法で積分してくれるプログラム

double daikei(double x1, double x2, double dx, int N){
    int n;
    double result = 0;

    for(n=0;n<N-1;n++){
    result += ((f(x1)+f(x2))*dx)/2;
    x1 += dx;
    x2 += dx;
    }
    return result;
}
double daikei2(double x1, double x2, double dx, int N){
    int n;
    double result = 0;

    for(n=0;n<N-1;n++){
    result += ((g(x1)+g(x2))*dx)/2;
    x1 += dx;
    x2 += dx;
    }
    return result;
}

double simpson(double x1, double x2, double dx, int N){
    int n;
    double z=0, result;

    for(n=0;n<N-1;n++){
        z += 4*f(x1)+ 2*f(x2);
        x1 += 2*dx;
        x2 += 2*dx;
    }
    result =((z + f(x1) + f(3) + f(0))*dx)/3; 

    return result;
}
double simpson2(double x1, double x2, double dx, int N){
    int n;
    double z=0, result;

    for(n=0;n<N-1;n++){
        z += 4*g(x1)+ 2*g(x2);
        x1 += 2*dx;
        x2 += 2*dx;
    }
    result = ((z + f(x1) + f(2) + f(1))*dx)/3;

    return result;
}

int main(void){
    
    int n, N;
    double x1, x2, r1, r2,dx;
    double x3, x4, r3, r4, dx2;
    double x5, x6, dx3;
    double x7, x8, dx4;
    double bef_result1, bef_result2, bef_result3, bef_result4;
    double result1, result2, result3, result4;

    while(N != -1){

        printf("積分範囲を何分割するか入力してください\n処理をやめたい場合は-1を入力してください：");
        scanf("%d", &N);

        printf("(1)の関数について\n");
        r1 = 3; r2 = 0;
        dx = (r1-r2)/N;
        x1 = r2; x2 = r2+dx;
        printf("微小区間Δx = %f\n", dx);
        result1 = daikei(x1,x2,dx,N);
        printf("answer1 = %8f   前回値との差分%f\n", result1, fabs(result1-bef_result1));

        dx3 = (r1-r2)/(2*N);
        x5 = r2+dx3; x6 = r2+2*dx3;

        result3 = simpson(x5,x6,dx3,N);
        printf("answer3 = %8f   前回値との差分%f\n\n", result3, fabs(result3-bef_result3));
        

        printf("(2)の関数について\n");
        r3 = 2; r4 = 1;
        dx2 = (r3-r4)/N;
        x3 = r4; x4 = r4+dx2;
        printf("微小区間Δx = %f\n", dx2);

        result2 = daikei2(x3,x4,dx2,N);
        printf("answer2 = %8f   前回値との差分%f\n", result2, fabs(result2-bef_result2));
    
        dx4 =(r3-r4)/(2*N);
        x7 = r4+dx4; x8 = r4+2*dx4;

        result4 = simpson2(x7,x8,dx4,N);
        printf("answer4 = %8f   前回値との差分%f\n\n", result4, fabs(result4-bef_result4));  

        bef_result1 = result1;
        bef_result2 = result2;
        bef_result3 = result3;      
        bef_result4 = result4;
    }

    return 0;
}