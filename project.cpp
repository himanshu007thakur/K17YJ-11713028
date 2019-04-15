#include<bits/stdc++.h>
#include<windows.h>
#define max 10000000
using namespace std;
int main()
{
	int n,i,j,k,temp,temp2,total,count=0,avgW=0,avgT=0;
	cout<<"============================================================================================================"<<endl;
	cout<<"\t\t\t\tOPERATING SYSTEM PROJECT"<<endl;
	cout<<"============================================================================================================"<<endl;
	cout<<"ENTER THE NUMBER OF THE PROCESS-: "<<endl<<endl;
	cin>>n;
	int p[n],at[n],bt[n];
	int wt[n+1]={0};
	int tt[n+1]={0};
	int r[n]={0};
	cout<<"\tARRIVAL TIME-:\n";
	for(i=0;i<n;i++)
	{
		cout<<"\tP"<<i+1<<"\t";
		cin>>at[i];
		p[i]=i+1;
	}
	cout<<"\tBURST TIME-:\n";
		for(i=0;i<n;i++)
	{
		cout<<"\tP"<<i+1<<"\t";
		cin>>bt[i];
		p[i]=i+1;
	}
	cout<<"==================================================================================="<<endl;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(at[j]>at[j+1])
			{
				int c=at[j];
				at[j]=at[j+1];
				at[j+1]=c;
				c=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=c;
				c=p[j];
				p[j]=p[j+1];
				p[j+1]=c;
			}
		}
	}
	for(i=0;i<n;i++)
	{ 
		Sleep(2500);
		if(at[i]==0)
		{
			cout<<"\tP"<<p[i]<<"\twont be executed\n";
		}
		else
		{
			
			cout<<"\tP"<<p[i]<<"\twill be executed\n";
			
		}
	}
	cout<<endl;
	cout<<"==================================================================================="<<endl;
	cout<<"PROCESS\tARRIVAL TIME\tBURST TIME"<<endl<<endl;
	
	for(i=0;i<n;i++)
	{
		Sleep(1500);
		cout<<"P"<<p[i]<<"\t"<<at[i]<<"\t\t"<<bt[i]<<endl<<endl;;
	}
	
	
	for(i=0;i<n;i++)
	{
		if(at[i]!=0)
		break;
		wt[p[i]]=-1;
		count++;
	}
	k=count;
	for(total=1;n-count>0;)
	{
		for(i=k;i<n;i++)
		{
			if(at[i]>total)
			{
				total++;
				i=i-1;
				continue;
			}
			temp=max;temp2=i;
			for(j=i;j<n && at[j]<=total;j++)
			{
				if(bt[j]<temp&&r[j]!=1)
				{
					temp=bt[j];
					temp2=j;
				}
			}
			wt[p[temp2]]=total-at[temp2];
			tt[p[temp2]]=wt[p[temp2]]+temp;
			total=total+bt[temp2]+2;
			r[temp2]=1;
			count++;
			break;
		}
	}
	
	cout<<"PROCESS\tWAITING TIME\t TURNAROUND TIME\n\n";
	
	for(i=1;i<=n;i++)
	{
		if(wt[i]==-1)
		cout<<"P"<<i<<"\t"<<"DISCARD"<<"\t\t"<<"DISCARD"<<endl<<endl;
		else
		{
			cout<<"P"<<i<<"\t"<<wt[i]<<"\t\t"<<tt[i]<<endl<<endl;;
			avgW+=wt[i];avgT+=tt[i];
		}
		
	}
	cout<<"==================================================================================="<<endl;
	cout<<"\tAVERAGE WAITING TIME-:";
	cout<<(avgW*1.0)/(n-k)<<endl<<endl;
	cout<<"==================================================================================="<<endl;
	
	cout<<"\tAVERAGE TURNAROUNG TIME-:";
	cout<<(avgT*1.0/(n-k))<<endl;
	cout<<"==================================================================================="<<endl;
	return 0;
}
