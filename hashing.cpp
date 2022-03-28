#include <bits/stdc++.h>
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

HashFunction :: HashFunction(){
	int i;
	for(i = 0 ; i < 10; ++i){
		h[i].key = -1;
		strcpy(h[i].name, "NULL");
	}
}

void HashFunction :: Delete(long k){
	int idx = find(k);
	if(idx == -1){
		cout << "\n\t key not found";
	}
	else{
		h[idx].key = -1;
		strcpy(h[idx].name, "NULL");
		cout << "\n\t key is deleted" ;
	}
}

int HashFunction :: find(long k ){
	int i;
	for(i = 0 ; i < 10; ++i){
		if(h[i].key == k){
			cout << "\n\t" << h[i].key << "is FOund at" << i << "location with name " << h[i].name;
			return i;
		}
		
	}
	if(i == 10){
		return -1;
	}
	return i;
}

void HashFunction :: display(){
	int i;
	cout << "\n\t\t key \t\t name ";
	for(i= 0; i < 10; ++i){
		cout << "\n\t h[ " << i << "]\t" << h[i].key << "\t\t" << h[i].name;
	}
}

void HashFunction :: insert(){
	char ans, n[10], ntemp[10];
	long k, temp;
	int v, hi, cnt = 0, flag = 0, i ;
	
	do{
		if(cnt > 10){
			cout << "\n\t hash table is full ";
			break;
		}
		cout << "\n\t Enter a telephone number : ";
		cin >> k;
		cout << "\n\t Enter a client name : ";
		cin >> n;
		hi = k % 10;
		if(h[hi].key == -1){
			h[hi].key = k;
			strcpy(h[hi].name, n);
		}
		else{
			if(h[hi].key % 10 != hi){
				temp = h[hi].key;
				strcpy(ntemp,h[hi].name);
				h[hi].key = k;
				strcpy(h[hi].name, n);
				for(i = hi + 1; i < 10; i++){
					if(h[i].key == -1){
						h[i].key = temp;
						strcpy(h[i].name, ntemp);
						flag = 1;
						break;
					}
				}
				for(i = 0; i < hi && flag == 0; i++){
					h[i].key = temp;
					strcpy(h[i].name, ntemp);
					break;
				}
			}
			else{
				for(i = hi + 1; i < 10 ; i++){
					if(h[i].key == -1){
						h[i].key = k;
						strcpy(h[i].name, n);
						flag = 1;
						break;
					}
				}
				for(i = 0; i < hi && flag == 0; i++){
					if(h[i].key == -1){
						h[i].key = k;
						strcpy(h[i].name, n);
						break;
					}
				}
			}
		}
		flag = 0;
		cnt++;
		cout << "\n\t Do you want to insert more key : y/n ";
		cin >> ans;
		
	}
	while(ans == 'y' || ans == 'Y');
}


int main(){
	long k;
	int ch, idx;
	char ans;
	HashFunction obj;
	do{
		cout<<"\n\t**TELEPHONE(ADT)** ";
		cout << "\n\t 1. insert \n\t 2.display \n\t 3.find \n\t 4.Delete \n\t 5. Exit ";
		
		cout << "\n\t...... Enter YOur choice : " ;
		cin >> ch;
		
		switch(ch){
			case 1 : obj.insert();
				break;
			case 2 : obj.display();
				break;
			case 3 : cout << "\n\t... Enter a key you want to seacrh ";
				cin >> k ;
				idx = obj.find(k);
				if(idx == -1){
					cout << "\n\t NOt FOund " ;
				}	
				break;
			case 4 : cout << "\n\t.... Enter a key Which you want to delete";
			cin >> k;
			obj.Delete(k);
			break;
			case 5 :
			 	break;
		}
		cout << "\n\t Do you want to continue to main menu ? : y/n " ;
		cin >> ans ;
	}			
	while(ans == 'y' || ans == 'Y');	
	return 0;
}
