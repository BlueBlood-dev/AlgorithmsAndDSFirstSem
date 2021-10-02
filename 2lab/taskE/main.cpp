#include <iostream>
#include <cstdio>

using namespace std;

void findTheOrderOfK(int array[], int k,int left, int right) {
    int left_cash = left;
    int right_cash = right;
    int middle = array[(left+right)/2];
        while(left_cash<=right_cash) {
            while (array[left_cash] < middle)
                left_cash++;
            while (array[right_cash] > middle)
                right_cash--;
            if (left_cash <= right_cash)
                swap(array[left_cash++], array[right_cash--]);
        }
        if (right_cash > left &&  k <=right_cash) {
            findTheOrderOfK(array, k, left, right_cash);
        }
        if (left_cash < right && k>= right_cash) {
            findTheOrderOfK(array, k, right_cash + 1, right);
        }
    }

int main() {
    int amount, k,a,b,c,array1,array2;
    FILE *in = fopen("kth.in","r");//почему то с++ вывод в файл не работает, пришлось писать на с
    FILE *out = fopen("kth.out","w");
    fscanf(in, "%d %d", &amount, &k);
    fscanf(in, "%d %d %d %d %d", &a,&b,&c,&array1,&array2);
    int array[amount];
    array[0] = array1;
    if(amount!=1)
         array[1] = array2;
    for(int i = 2; i < amount; ++i){
        array[i] = a * array[i-2] +  b * array[i-1] + c;
    }
    findTheOrderOfK(array,k-1,0,amount-1);
    fprintf(out,"%d",array[k-1]);
    fclose(in);
    fclose(out);
}

