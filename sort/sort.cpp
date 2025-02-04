//sorts  n for size in all case
#include<iostream>
#include<stdlib.h>
using namespace std;

void bubbleSort(int a[],int n){
	for(int i=0;i<n;i++){
		int flag=0;
		for(int j=0;j<n-(i+1);j++){
			if(a[j]>a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag=1;
			}
		}
		if(!flag)break;
	}
}

void swap(int a[],int i,int j){
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

void insertionSort(int a[],int n){
	for(int i=1;i<n;i++){
		int key=a[i];
		int j=i-1;
		while(j>=0 && a[j]>key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}

void selectionSort(int a[],int n){
	for(int i=0;i<n-1;i++){
		int minIndex=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[minIndex]){
				minIndex=j;
			}
		}
		if(minIndex!=i)swap(a,i,minIndex);
	}
}

int partition(int arr[],int low,int high){
	int pivot=arr[high];
	int i=low-1;
	int j;
	for(j=low;j<=high-1;j++){
		if(arr[j]<pivot){
			i++;
			swap(arr,i,j);
		}
	}
	swap(arr,i+1,high);
	return i+1;
}

void quickSort(int arr[],int low,int high){
	if(low<high){
		int j=partition(arr,low,high);
		quickSort(arr,low,j-1);
		quickSort(arr,j+1,high);
	}
}

void marge(int arr[],int low,int mid,int high){
	int i=low;
	int j=mid+1;
	int k=low;
	int B[1000];
	while(i<=mid && j<=high){
		if(arr[i]<=arr[j]) B[k++]=arr[i++];
		else B[k++]=arr[j++];
	}
	while(i<=mid)B[k++]=arr[i++];
	while(j<=high)B[k++]=arr[j++];
	for(int i=low;i<=high;i++){
		arr[i]=B[i];
	}
}
void margeSort(int arr[],int left,int right){
	if(left<right){
		int mid=(left+right)/2;
		margeSort(arr,left,mid);
		margeSort(arr,mid+1,right);
		marge(arr,left,mid,right);
	}
}


void heap(int arr[],int n,int i){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n && arr[left]>arr[largest]) largest=left;
	if(right<n && arr[right]>arr[largest]) largest=right;
	if(largest !=i){
		swap(arr,i,largest);
		heap(arr,n,largest);
	}
}

void heapSort(int arr[],int n){
	for(int i=n/2-1;i>=0;i--) heap(arr,n,i);
	for(int i=n-1;i>0;i--){
		swap(arr,0,i);
		heap(arr,i,0);
	}
}
void display(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void insert(int a[],int n){
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	//cout<<endl;
}

int main(){
	int arr[]={};
	cout<<"Enter 0 for exit"<<endl;
	cout<<"Enter 1 for input"<<endl;
	cout<<"Enter 2 for bubble Sort"<<endl;
	cout<<"Enter 3 for insertion Sort"<<endl;
	cout<<"Enter 4 for selection Sort"<<endl;
	cout<<"Enter 5 for quick Sort"<<endl;
	cout<<"Enter 6 for marge Sort"<<endl;
	cout<<"Enter 7 for heap Sort"<<endl;
	cout<<"Enter 8 for display"<<endl;
	while(1){
		int p;
		cout<<"Enter your choice ";
		cin>>p;
		switch(p){
			case 1:
				int size;
				cout<<"Enter size ";
				cin>>size;
				cout<<"Enter the array"<<endl;
				insert(arr,size);
				break;
			case 2:
				bubbleSort(arr,size);
				break;
			case 3:
				insertionSort(arr,size);
				break;
			case 4:
				selectionSort(arr,size);
				break;
			case 5:
				quickSort(arr,0,size-1);
				break;
			case 6:
				margeSort(arr,0,size-1);
				break;
			case 7:
				heapSort(arr,size);
				break;
			case 8:
				display(arr,size);
				break;
			case 0:
				exit(0);
			default:
				cout<<"Invalid input"<<endl;
				break;
		}
	}
	
	return 0;
}
