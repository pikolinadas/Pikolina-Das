#include<stdio.h>
#include<math.h>
#include<string.h>
int calculatebase(char *arr,int len)
{
    int maximum=arr[0],basevalue,i;
    for(i=1;i<len;i++)
    {
        if(arr[i]>maximum)
            maximum=arr[i];
    }
    if(maximum>=65)
        basevalue=(maximum-55)+1;
    else
        basevalue=maximum-48+1;
}

int convertingbase(int n,int base)
{
    int exponent=0,sum=0,r;
    while(n!=0)
    {
        r=n%10;
        sum+=r*pow(base,exponent);
        exponent++;
        n=n/10;
    }
    return sum;
}

int main()
{
    char arr[100];
    int x,len,sum=0,ba,i;
    scanf("%s",arr);
    len=strlen(arr);
    ba=calculatebase(arr,len);
    for(i=0;i<len;i++)
    {
        if(arr[i]>=65)
            sum+=(arr[len-1-i]-55)*pow(ba,i);
        else
            sum+=(arr[len-1-i]-48)*pow(ba,i);
    }
    
    while(1)
    {
        int check,base,result, d,maxvalue;
    maxvalue=sum%10;
    sum=sum/10;
    while(sum!=0)
    {
        d=sum%10;
        if(d>maxvalue)
            maxvalue=d;
        sum=sum/10;
    }
        check=sum;
        base=check+1;
        result=convertingbase(sum,base);
        if(sum==result)
            break;
        else
            sum=result;
        
    }
    printf("%d",sum);      
}
