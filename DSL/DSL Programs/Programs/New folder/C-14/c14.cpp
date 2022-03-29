
/*NAME: Aaishwarya Darandale

ROLL NO: 71
Problem statement :C14

Problem Statement : Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up client‘s telephone
number.*/

#include<iostream>
using namespace std;

int main()
{
	int i,z,n,a[20],key,val[20],com;
	cout<<"Enter number of elements:";
	cin>>n;
	for(i=0;i<n;i++)
		cin>>val[i];

	for(i=0;i<10;i++)
		a[i]=-1;

	
	for(i=0;i<n;i++)
	{	
		if(i==10)
		break;

		com=val[i];
		key=com%10;
		for(z=0;z<n;z++)
		{
			if(a[key]==-1)
			{
a[key]=com;	
break;
}
else
{
key++;
if(key==10)
    key=0;
}
}
}
cout<<"linear: \n";
for(i=0;i<10;i++)
cout<<a[i]<<endl;

for(i=0;i<10;i++)
a[i]=-1;

for(i=0;i<n;i++)
{
com=val[i];
key=com%10;
for(z=0;z<n;z++)
{
if(a[key]==-1)
{
a[key]=com;
break;
}
else
{
for(int z=0;z<10;z++)
{
key=key+(z*z);
if(key==10)
key=0;
if(a[key]==-1)
break;
}
}
}
}
cout<<"quadratic: \n";
for(i=0;i<10;i++)
cout<<a[i]<<endl;
return 0;
}
