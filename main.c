#include <stdio.h>
#include <string.h>
#include <math.h>
#include "add.h"  //引入自己写的头文件

//p10 9函数


/*int main() {

    //strlen(); 字符串长度
    //strcpy(); 字符串copy:(包括结束标志 \0)
    char arr1[] = "bit";
    char arr2[] = "***";

    strcpy(arr2,arr1); //覆盖 arr2的内容

   printf("%s\n",arr2);
    return 0;
}*/
/*
int main()
{
    // void memset(void * ptr, int value,size_t num);
    char arr[] = "hello world";
    memset(arr,'*',5);

    printf("%s\n",arr);
    return 0;
}*/

//使用指针接收
//形参-形式参数： 只有被调用时才被初始化
//形参其实是实参的临时拷贝
//对形参的修改是不会影响实参的
void swap(int *a, int *b) {
    int temp = *a;
    //*a进行解引用
    *a = *b;
    *b = temp;
}

int is_leap_year(int year) {
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        return 1;
    } else {
        return 0;
    }
}

//判断一个数是否为素数
int isPrime(int n) {
    //试触法  13    2-12
    for (int j = 2; j <= sqrt(n); j++) {
        //不是素数
        if (n % j == 0) {
            return 0;
        }

    }
    return 1;
}

//二分查找  返回下表 没有 -1
//数组在传递参数时，仅仅传递的是第一个元素的地址，主要是c语言为了避免内存浪费
//本质上是一个指针32  4字节
int binary_search(int arr[], int key, int sz) {
    int left = 0;
//    int sc = sizeof(arr) / sizeof(arr[0]);   //4/4=1
    int right = sz - 1;


    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] > key) {
            //收缩右边
            right = mid - 1;
        }
        if (arr[mid] < key) {
            //递进左边
            left = mid + 1;
        } else {
            return mid;
        }

    }
    //找不到 返回-1
    return -1;
}

/*int main()
{

    int a = 20;
    int b = 10;

//    printf("a=%d b=%d\n",a,b);
    //函数实现交换变量
    swap(&a,&b);  //将a  b的地址传递

//    printf("a=%d b=%d\n",a,b);

    int year = 400;
    if(is_leap_year(year))
    {
        printf("湿润年");
    }else
    {
        printf("不是润年");
    }

} */
void add(int* p)
{
//    *p+=1;
    (*p)++;
}


int main() {
    /*for (int i = 100; i <= 200; i++) {
        if (isPrime(i)) {
            printf("%d\n", i);
        }
    }*/

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 5;
    //传递长度 ： 因为arr实际传递的是指针  32 4个字节，不能进行运算的
    int sz = sizeof(arr) / sizeof(arr[0]);

    int ret = binary_search(arr, key, sz);

    if (ret != -1) {
        printf("找到了，下标为%d", ret);
    } else {
        printf("找不到");
    }



    //调用一个函数  num+1
    int num = 0;
    add(&num);
    printf("%d\n",num);
    add(&num);
    printf("%d\n",num);

    //4321
    //int printf()
    printf("%d\n",printf("%d", printf("%d",43)));

    printf("%d\n",ADD(10,20));

}


