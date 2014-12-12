#include<stdio.h>
#include<conio.h>
radix_sort(int arr[], int n)
{
    int i,j,k,maximum;
    int index, nb_of_digits=0;

    int digit;
    int m1=10,m2=1;
    maximum=arr[0];

    int **bucket=(int **)malloc(10*sizeof(int*));
    for(i=0;i<10;i++)
    {
        bucket[i]=(int *)malloc(n*sizeof(int));
    }

    int *nb_of_elements=(int *)malloc(10*sizeof(int));

     /** finds the maximum number from the array **/
    for(i=1; i<n; i++)
    {
        if(arr[i]>maximum)
        {
            maximum=arr[i];
        }
    }

    /** finds the number of digits of the maximum
        number from the array **/
    while(maximum>0)
    {
        nb_of_digits++;
        maximum=maximum/10;
    }

    for(index=0; index<nb_of_digits; index++)
    {
        /** nb_of_elements[i] is the numbers of
            elements in the bucket[i][]**/
        for(i=0; i<10; i++)
        {
            nb_of_elements[i]=0;
        }

        /** takes each element, finds its place in the
            bucket table and inserts it there **/
        for(i=0; i<n; i++)
        {
            digit=arr[i]%m1;
            digit=digit/m2;
            bucket[digit][nb_of_elements[digit]]=arr[i];
            nb_of_elements[digit]++;
        }

        /** rearranges the elements in the array
            taking them in order from the bucket **/
        i=0;
        for(k=0; k<10; k++)
        {
            for(j=0; j<nb_of_elements[k]; j++)
            {
                arr[i]=bucket[k][j];
                i++;
            }
        }

        m1*=10;
        m2*=10;
    }

    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n,i;

    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    radix_sort(arr,n);
    return 0;
}

