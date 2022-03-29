
/*NAME: Aaishwarya Darandale

ROLL NO:71
Problem statement :B11
You have a business with several offices; you want to lease phone lines to connect them up with each other;
and the phone company charges different amounts of money to connect different pairs of cities.
You want a set of lines that connects all your offices with a minimum total cost. Solve the problem by suggesting appropriate data structures.*/

#include <iostream>

using namespace std;

class gp

{

public:

        int v,j,i,c,k,min,row,col,mc;

        int a[10],visit[10];

        int m[10][10];

        gp()

        {

                v=j=c=k=min=row=col=mc=0;

                for(i=0;i<10;i++)

                {

                        for(j=0;j<10;j++)

                        {

                                m[i][j]=-1;

                        }

                }

        }

        void create();

        void display();

        void prims();

};

void gp :: create()

{

        cout<<"\nEnter the numbers of entries: ";

        cin>>v;

        for(i=0;i<v;i++)

        {

                cout<<"\nEnter the numbers: ";

                cin>>a[i];

        }

        cout<<"\nIf edge is not present then enter the value -1";

        for(i=0;i<v;i++)

        {

                for(j=i+1;j<v;j++)

                {

                        cout<<"\nEnter the weight of the edge between "<<a[i]<<" & "<<a[j]<<": ";

                        cin>>c;

                        m[i][j]=m[j][i]=c;

                }

        }

}

void gp :: display()

{

        cout<<endl;

        for(i=0;i<v;i++)

        {

                cout<<"\t"<<a[i];

        }

        cout<<endl;

        for(i=0;i<v;i++)

        {

                cout<<a[i]<<"\t";

                for(j=0;j<v;j++)

                {

                        cout<<m[i][j]<<"\t";

                }

                cout<<endl;

        }

}

void gp :: prims()

{

        for(i=0;i<=v;i++)

        {

                visit[i]=0;

        }

        visit[1]=1;

        for(k=0;k<v-1;k++)

        {

                min=999;

                for(i=0;i<v;i++)

                {

                        for(j=0;j<=v;j++)

                        {

                                if(visit[i]==1 && visit[j]==0)

                                {

                                        if(m[i][j]!=-1 && min>m[i][j])

                                        {

                                                min=m[i][j];

                                                row=i;

                                                col=j;

                                        }

                                }

                        }

                }

                cout<<"\n Min : "<<min;

                mc=mc+min;

                visit[col]=1;

                m[row][col]=-1;

                m[col][row]=-1;

        }

        cout<<"\n Final shortest cost in graph is :"<<mc;

}

int main(void) {

        gp g;

        g.create();

        g.display();

        g.prims();

        return 0;

}
