#include <stdio.h>



#include<math.h>



#include<limits.h>



int main()



{



    int n,s=0,avg,max=INT_MIN,min=INT_MAX,p=0,t=0;



    printf("Enter 0 for escape");



    while(1)

    {



    scanf("%d",&n);



    s=s+n;



    t++;



    if(max<n)



    max=n;

        

    if(min>n)



     min=n;

   

     if(n==0||n<0)



     break;



     p++;



        

    }



     printf("total number of +ve values are %d\n",p);

printf("Minimum value is %d\n",min);



     printf("Maximum value is %d\n",max);



     printf("Avg value of all number is %d\n",s/t);



    return 0;



}