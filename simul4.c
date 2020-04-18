#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    int burst[30],at[20],n,i,j,temp,st[20],ft[20],wt[20],ta[20];
    int totwt=0,totta=0;
    float awt,ata;
    char pn[20][20],t[20];
    printf("Enter the number of process:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter process name, arrival time& burst time(horizontally in their respective order):");
        scanf("%s%d%d",pn[i],&at[i],&burst[i]);
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(burst[i]<burst[j])
            {
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=burst[i];
                burst[i]=burst[j];
                burst[j]=temp;
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    for(i=0; i<n; i++)
    {
        if(i==0)
            st[i]=at[i];
        else
            st[i]=ft[i-1];
        wt[i]=st[i]-at[i];
        ft[i]=st[i]+burst[i];
        ta[i]=ft[i]-at[i];
        totwt+=wt[i];
        totta+=ta[i];
    }
    awt=(float)totwt/n;
    ata=(float)totta/n;
    printf("\nPname\tarrivaltime\tbursttime\twaitingtime\ttatime");
    for(i=0; i<n; i++)
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],at[i],burst[i],wt[i],ta[i]);
    printf("\nAverage waiting time is:%f",awt);
    printf("\nAverage turnaround time is:%f",ata);
    getch();
}
