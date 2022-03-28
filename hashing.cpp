#include<iostream>
#include<string.h>
using namespace std;
class HashFunction{
    typedef struct hash{
    long key;
    char name[10];
    }hash;
    hash h[10];
    public:
        HashFunction();
        void insert();
        void display();
        int find(long);
        void Delete(long);

};

HashFunction::HashFunction(){
int i;
for (i = 0; i<10; i++){
    h[i].key = -1;
    strcpy(h[i].name, "NULL");    
    
    }
}

void HashFunction::Delete(long k){
int index = find(k);
if (index==-1){
    cout<<"\n\tKey not found!"     
    }
else{
    h[index].key = -1;
    strcpy(h[index].name, "NULL")
    cout<<"Key is deleted..."
    }
}

int HashFunction::find(long k){
    int i;
}
