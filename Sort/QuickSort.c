#include <stdio.h>
#include <stdlib.h>
/* Quick sort �ֳt�Ƨ� �����Ƨ� O(nlogn) */
/* ��PK��m�������k�ⵥ�����̨α��p O(nlogn) , �_�h�̮t��O(n^) */
/* �קK�̮t�ɶ������ץi�ϥ� median of three �@��PK, left median(pk) right , median = (left+right)/2 */

void swap(int* a,int* b){
    int temp= *a;
    *a= *b;
    *b= temp;
}

void quicksort(int* a,int l,int r){
    int pk,i,j;

    if(l >= r){ return; }

    pk=a[l];

    i=l + 1;
    j=r;

    while(1){
        while(i <= r){ // r to l
            if (a[i]>pk){
                break;
            }
            i++;
        }
        while(j > l){ // l to r
            if (a[j]<pk){
                break;
            }
            j--;
        }
        if(i > j){ break; } // cross then exit...
        swap(&a[i], &a[j]);
    }

    swap(&a[l], &a[j]); // put pk to correct position

    quicksort(a, l, j - 1); // left union
    quicksort(a, j + 1, r); // right union
}

main(void){

    int i,n,a[30];

    printf("Quick sort\n");
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    printf("\nEnter the elements\n");

    for(i=0;i<n;i++){
        printf("%d th data: ",i+1);
        scanf("%d",&a[i]);
    }
    
    quicksort(a,0,n);

    printf("\nSorted list: \n\n");

    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    system("pause");
}