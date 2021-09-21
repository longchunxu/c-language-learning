#include<iostream>
using namespace std;

template<typename T>
void sort_arry(T a[],int len )//选择排序
{   
    for (int i = 0; i < len; i++)
    {   
        int min = i;
        for (int j = i + 1; j < len  ; j++)
        {
            if(a[j]<a[min])
            {
               min=j;
            }
        }
        if(min!=i)
        {
            int temp =a[min];
            a[min]=a[i];
            a[i]=temp;
        }
  
    }
    for (int i = 0; i <len; i++)
    {
        cout<<"a["<<i<<"]="<<a[i]<<endl;
    }
    
}
int main(void)
{   
    int a[]={1,5,6,3,2};
    sort_arry(a,5);
    
    cout<<endl;

    char b[]="adfgcf";
    sort_arry(b,6);
    
    
    return 0;
}
    
