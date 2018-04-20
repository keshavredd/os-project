#include<stdio.h>

struct process
{
	int pid,bt,wt,tat;
};

int main()
{
  int n=3,i,j;
  int total_wt=0,total_tat=0;
  

  printf("\nENTER Pid of 3 students and Burst Time : ");
  struct process a[n];
  for( i=1;i<=n;i++)
  {
  	struct process pd;
  	printf("\n\t process ID : ");
  	scanf("%d",&pd.pid);
  	printf("\n\t Burst Time : ");
  	scanf("%d",&pd.bt);
  	a[i] = pd;
  }
int rem[3]; 
  
 for(i=1;i<=3;i++)
{
  rem[i]=a[i].bt; a[i].wt=0;
}

//--SORTING THE PROCESS BASED ON PRIORITY-----------------------------------------------------------------------
int t=0;
printf("\n Order Of Execution : ");
while(true)
{
   if(rem[1]>rem[2] && rem[1]>rem[3])
   {
   		printf("\n P1 will execute"); rem[1]-=1;  t+=1; //rem[1]-= 1; a[2].wt+=1 ; a[3].wt+=1;
   }
   else if(rem[2]>rem[1] && rem[2]>rem[3])
   {
   		printf("\n P2 will execute"); rem[2]-= 1; t+=1;// a[3].wt+=1 ; a[1].wt+=1; 
   }
   else if(rem[3]>rem[1] && rem[3]>rem[2])
   {
   		printf("\n P3 will execute"); rem[3]-= 1;  t+=1; // a[2].wt+=1 ; a[1].wt+=1; t+=1;
   }
   else if(rem[1]==rem[2] && rem[1]!=0 && rem[2]!=0 )
   {
   		if(a[1].pid<a[2].pid)
   		{
   		  rem[1]-= 1;	printf("\n P1 will execute"); //a[2].wt+=1 ; a[3].wt+=1;
		   }
		else
		{
			rem[2]-= 1;  printf("\n P2 will execute"); //a[3].wt+=1 ; a[1].wt+=1;
		}
		t+=1;
   }
   else if(rem[2]==rem[3] && rem[2]!=0 && rem[3]!=0 )
   {
   		if(a[2].pid<a[3].pid)
   		{
   		  rem[2]-= 1; 	printf("\n P2 will execute"); // a[1].wt+=1 ; a[3].wt+=1;
		   }
		else
		{
			rem[3]-= 1;  printf("\n P3 will execute"); //a[2].wt+=1 ; a[1].wt+=1;
		}
		t+=1;
   }
   else if(rem[1]==rem[3] && rem[1]!=0 && rem[3]!=0 )
   {
   		if(a[1].pid<a[3].pid)
   		{
   		  rem[1]-= 1;	printf("\n P1 will execute");  // a[2].wt+=1 ; a[3].wt+=1;
		   }
		else
		{
			rem[3]-= 1;  printf("\n P3 will execute");	//a[2].wt+=1 ; a[1].wt+=1;
		}
		t+=1;
   }
   
   if(rem[1]==0 && a[1].tat==0)
   		a[1].tat= t;
   if(rem[2]==0 && a[2].tat==0)
   		a[2].tat= t;
   if(rem[3]==0 && a[3].tat==0)
   		a[3].tat= t;
   
   if(rem[1]==0 && rem[2]==0 && rem[3]==0)
     break;
   	
 }
    
    
//-CALCULATING WAITING TIME--------------------------------------------------------------------------------------

        
// Calculating turnaround time by adding bt[i] + wt[i]
    for (i = 1; i <= n ; i++)
    {
        a[i].wt = a[i].tat-a[i].bt;
        
        total_wt = total_wt + a[i].wt;   //SUM waiting and TURn around Time.
        total_tat = total_tat + a[i].tat;
     }
//----------------------------------------------------------------------------------------------------------------
// printing all details : 
 printf("\n\nProcess Number \tBurst Time \tWaiting Time \tTurn Around Time");
 for (int i = 1; i <= n ; i++)
 {
	printf("\n%d \t\t%d \t\t%d \t\t%d",a[i].pid,a[i].bt,a[i].wt,a[i].tat);
 }
//-----------------------------------------------------------------------------------------------------------------
printf("\n\n AVERAGE WAITING TIME : %.2f",(float)total_wt/(float)n);
printf("\n\n AVERAGE TURN AROUND TIME : %.2f",(float)total_tat/(float)n);

}
