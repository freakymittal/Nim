#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <time.h>

using namespace std;

const int no_heap[3] = {3, 5, 7};
const int heap_length[3] = {9, 11, 13};
string players[2] = {"Computer", "Human"};
int heaps,heap[3];
void choose(string player)
{
	int x,y;
	string msg="Player Human enter the number of objects (Y) to take from what heap (X) - in order: Y X\nHuman Enters : ";
	string err="\nPlayer Human that is an invalid move, try again\n";
	if(player=="Computer")
	{
		x = rand() % heaps;
		y = rand() % 13;
		while(y>heap[x-1] && heap[x-1]!=0){
			y = rand() % 13;
		}
	}
	else if(player=="Human")
	{
		cout<<msg;
		cin>>y>>x;
		while(y>heap[x-1]){
			cout<<err<<msg;
			cin>>y>>x;		
		}
		x--;
	}
	cout<<"Player "<<player<<" took "<< y <<" objects from heap "<<x+1<<"\n";
	heap[x]-=y;
}
void print_heap()
{
	for(int i=0;i<heaps;i++)
	{
		cout<<heap[i]<<setw(4);
	}
	cout<<"\n";
}
int check(const int a[], int n)
{   
    while(--n>0 && a[n]==a[0]);
    return n!=0;
}
int main()
{
	srand ( time(NULL) );
	heaps = no_heap[rand() % 3];
	int i;
	string chance;//Chance is variable for storing whose chance it is
	for(i=0;i<heaps;i++)
	{
		heap[i] = heap_length[rand() % 3];
	}
	cout<<"Created " <<heaps<<" heaps of sizes ";
	print_heap();
	chance = players[rand()%2];
	cout<<"\nPlayer "<<chance<<" goes first\n";
	do{
		choose(chance);
		print_heap();
		if(check(heap, heaps) == 0){
			cout<<"Player "<<chance<<" has won\n";
			break;
		}
		if(chance=="Computer") chance = "Human";
		else chance = "Computer";
	}while(1==1);
	return 0;
}
