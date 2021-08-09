// Using Linear Search

#include<iostream>
using namespace std;

class Array{
public:
	int data;
	void Set(int a[],int size){
		cout<< "Enter Elements into the array: \n";
		for(int i=0;i<size;i++){
			cin>>data;
			a[i]=data;

		}
	}

	void Display(int a[],int size){
		cout<<"Elements are:"<<endl;
		for(int i=0;i<size;i++){
		cout<<a[i]<<" ";
		}
	}

	void findMaxMin(int a[],int size){
		int max, min, smax, smin, m, n;
		min = a[0];
		max = a[0];
		for(int i = 1;i<size;i++){
		if(a[i]>max){
			smax = max;
			max = a[i];
		}
		else if(a[i]>smax && a[i]!= max){
			smax = a[i];
		}
		}
		for(int i =1;i<size;i++){
			if(a[i]<min){
				smin = min;
				min = a[i];
			}
			else if(a[i]<smin && a[i]!= min){
				smin = a[i];
			}
		}

		cout << endl<<"The Maximum element in the array is: " << max << endl;
		cout << endl<<"The Minimum element in the array is: " << min << endl;
		cout << endl<<"The 2nd Maximum element in the array is: " << smax << endl;
		cout << endl<<"The 2nd Minimum element in the array is: " << smin << endl;
	}
};

int main(){
	int size;
	cout<<"Enter Size: \n";
	cin>>size;
	int *a= new int[size];
	Array arr;
	arr.Set(a,size);
	arr.findMaxMin(a,size);
	return 0;
}