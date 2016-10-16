#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int Partition (int r[], int low , int high )
{
        //交换顺序表L中子表r high的记录 枢轴记录到位，并返回其所在的位置，
        //此时在它之前 （后）的记录均不大（小）于它
        int cache;
        int pivotkey;

        cache = r[low];
        pivotkey = r[low];   //用子表的第一个记录作枢轴记录

        while (low < high) //从表的两段交替向中间扫描
        {
                while ((low < high) && (r[high] >= pivotkey))
                {
                        high--; //比枢轴记录小的移到低端
                }
                r[low] = r[high];
                while ((low < high) && (r[low] <= pivotkey))
                {
                        low++;//比枢轴记录大的移到高端
                }
                r[high] = r[low];

        }


        r[low] = cache;
        r[low] = pivotkey;
        return low ; //返回枢轴位置

}

void QSort (int L, int low, int high)
{
        int pivotloc = 0;
        //对顺序表L中 子序列 low high 做快速排序

        if (low < high) //长度大于一
        {
                pivotloc = Partition(L, low, high);  //将L一分为二
                QSort(L, low, pivotloc - 1);      //对低子表递归排序
                QSort(L, pivotloc + 1, high);    //对高子表递归排序

        }

}


void QuickSort(int L[], int len)
{

        //对顺序表L   做快速排序
        // printf ("  len=%d ", len);
        QSort(L, 0, len);


}



//冒泡函数

int bubble (int a[], int n)
{
        int i, j, t;


        for (i = 1; i < n; i++)
        {


                for (j = 0; j < n - i; j++)
                        if (a[j] > a[j + 1])
                        {
                                t = a[j];
                                a[j] = a[j + 1];
                                a[j + 1] = t;
                        }

        }

        return 0;
}


int main()
{

        int a[1000] = {0};
        int i;
        int len;


        for (i = 0; i < 1000; i++)
        {
                //  a[i] = i * i * i - 20 * i * i + 10 * i + 20;
                a[i] = 60 - i * 2;
        }





        for (i = 0; i < 1000; i++)
        {
                if (i % 10 == 0)
                {
                        //       printf("\n");
                }
                //    printf (" %d ", a[i]);
        }
        printf("\n");

        len = 999;

        QuickSort (a, len);
        //      bubble (a, len);



        printf (" \n");
        for (i = 0; i < 1000; i++)
        {

                if (i % 10 == 0)
                {

                        //        printf("\n");
                }
                 //    printf (" %d ", a[i]);
        }

        printf("\n\n");
        return 0;
}
