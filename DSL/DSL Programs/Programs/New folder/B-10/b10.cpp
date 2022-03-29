
/*NAME: Aaishwarya Darandale

ROLL NO: 71
Problem statement :B10

There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities.
The cost of the edge can be the time that flight takes to reach city B from A, or the amount of fuel used for the journey.
Represent this as a graph. The node can be represented by airport name or name of the city. Use adjacency list representation of the graph or
use adjacency matrix representation of the graph. Justify the storage representation used.  */

#include<iostream>
using namespace std;
 class graph
 {
	int matrix[20][20],visit[50];
	int i,j,n,y,x,f,l1,l2;
	string v1,v2,ver[50];
  	public:
       	void create()
        	{
         		cout<<"\nEnter no. of cities : ";
		cin>>n;
	  	cout<<"\n Enter Cities : ";
        		for(i=0;i<n;i++)
         		{
	  		cin>>ver[i];
          		}
  		cout<<"\n The Cities are : ";
  		for(i=0;i<n;i++)
  		{
	  		cout<<ver[i]<< " ";
  		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				matrix[i][j]=0;
			}
		}
      	}
    	void edge()
    	{
      		cout<<"\nEnter cities where flights are present : ";
		cin>>v1>>v2;
        		for(i=0;v1 != ver[i];i++);
        		for(j=0;v2 != ver[j];j++);
		cout<<"\nAmount of fuel required to make the flight : ";
		cin>>f;
		cout<<"\nAmount of fuel required"<<" "<<f<<" "<<"From cities"<<" "<<v1<<v2;
		matrix[i][j]=matrix[j][i]=f;
     	}
     	void dis()
     	{
		//for(int k=0;k<n;k++)
     	    	//cout<<" "<<ver[k];
       		for(i=0;i<n;i++)
		{
			cout<<endl;
			for(j=0;j<n;j++)
			{
				cout<<" "<<matrix[i][j];
			}
		}
      	}
     	void bft()
	   {
	 int visit[5]={0};
		 for(int j = 0; j < n; j++)
		 for(int i = 0; i < n; i++)
		 if(ver[j][i]!=-1&&visit[i]!=1)
		{
 		cout<<"\n\t"<<ver[i];
 		visit[i]=1;
 		}
 	    }
 	    void dft(int x)
 	    {
 		cout<<"\n\t"<<ver[x];
 		visit[x] = 1;
		for(int i = 0; i < n; i++)
		{
			if(ver[x][i]!=-1&&visit[i]!=1)
		dft(i);
		}
 	}
};
int main()
{
       	int y,i,n;
	graph obj;
	obj.create();
	x:
cout<<"\n1.Press 1 if flight path is present between these two cities\n2.Press 2 to Display the matrix representing flight path n fuel required\n3.Press 3 for BFT\n4.Press 4 for DFT\nYour choice is : ";
	cin>>y;
	switch(y)
	{
		case 1:
	 	obj.edge();
		goto x;
		break;
		case 2:
	 	obj.dis();
		goto x;
		break;
		case 3:
		obj.bft();
		goto x;
		break;
		case 4:
		obj.dft(0);
		goto x;
		break;
		case 5:
		break;
	}
	return 0;
}

