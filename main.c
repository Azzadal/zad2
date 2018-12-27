#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//создание массива X
int *masX(int n){
    int *x;
    x = (int*) malloc(sizeof(int)*n);
    for(int i = 0;i < n;i++){
        x[i] = -40+rand() % 90;
    }
    return x;
}
//создание массива Y
int *masY(int m){
    int *y;
    y = (int*) malloc(sizeof(int)*m);
    for(int i = 0;i < m;i++){
        y[i] = -40+rand() % 90;
    }
    return y;
}
//сумма положительных элементов массива X
float SumX(int *x,int n){
    float sumpx = 0;
    for(int i = 0;i < n;i++){
        if(x[i] > 0){ sumpx += x[i];}
    }
    return sumpx;
}
//сумма положительных элементов массива Y
float SumY(int *y,int m){
    float sumpy = 0;
    for(int j = 0;j < m;j++){
        if(y[j] > 0){sumpy += y[j];}
    }
    return sumpy;
}
//кол-во отрицательных элементов массива X
int Amount_negX(int *x, int n){
    int minx = 0;
    for(int i = 0;i < n;i++){
        if(x[i] < 0){ minx++;}
    }
    return minx;
}
//кол-во отрицательных элементов массива Y
int Amount_negY(int *y, int m){
    int miny = 0;
    for(int j = 0;j < m;j++){
        if(y[j] < 0){ miny++;}
    }
    return miny;
}
float result(float sumpx, float sumpy, int minx, int miny){
    float result;
    if(miny < 5){
        result = sumpx/(sumpy + minx * sqrt(sumpy));
    }
    if(miny >= 5){
        result = 0.014 + sumpy * minx;
    }
    return result;
}
//очистка памяти
void Delete(int *x,int *y)
{
free(x);
free(y);
}
int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    int *x;
    int *y;
    int n,m;
    printf("Ввести n\n");
    scanf("%d",&n);
    printf("Ввести m\n");
    scanf("%d",&m);
    x = masX(n);
    y = masY(m);
    float summa_posX = SumX(x,n);
    float summa_posY = SumY(y,m);
    int number_negX = Amount_negX(x,n);
    int number_negY = Amount_negY(y,m);
    float z = result(summa_posX, summa_posY, number_negX, number_negY);
    printf("z = %.2f", z);
    Delete(x,y);
    return 0;
}
