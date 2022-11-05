#include "the1.h"
#include <climits>


void SwapValue(int &a, int &b) {
   int t = a;
   a = b;
   b = t;
}
void heapify(int arr[], int N, int i,int indexarray[],long &swap,long &comparison)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
    if(arr[l]!=INT_MAX && l<N ){
    
        comparison++;}
        
    if (l < N && arr[l] < arr[largest] )
        largest = l;
    if(arr[r]!=INT_MAX && r<N ){
    
        comparison++;}
    if (r < N && arr[r] < arr[largest])
        largest = r;

    if (largest != i) {
        SwapValue(arr[i], arr[largest]);
        SwapValue(indexarray[i],indexarray[largest]);
        swap++;
        heapify(arr, N, largest,indexarray,swap,comparison);
    }
}

void buildHeap(int arr[], int N, int indexarray[],long &swap,long &comparison )
{
    int startIdx = (N / 2) - 1;
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, N, i,indexarray, swap,comparison);
    }
}
int kWayMergeSortWithHeap(int* arr, int K, int size, long& comparison, long& swap){
    int number_of_calls = 1;
    int toplam=1;
	int hesap=size;
	while(hesap>=K){
	    hesap=hesap/K;
	    toplam=toplam*K;
	    number_of_calls+=toplam;
	}
	if(size<K){
	    int n=size;
	    for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                swap++;
                j = j - 1;
            }
            arr[j + 1] = key;
        }
	}
	
	
	
	
	
	
	
	
	
	
	else{
	   for(int m = 0; m < K; m++)
	    {
	        
	        kWayMergeSortWithHeap(arr+m*size/K, K, size/K, comparison, swap);
	        
	        
	        
	    }
	    int arrayReal[size];
	    for(int i=0;i<size;i++){
	        arrayReal[i]=0;
	    }
	    
	    int array[K][size/K];
	    
	        for(int j=0;j<K;j++){
	            for(int t=0;t<size/K;t++){
	                array[j][t]=arr[t+j*size/K];
	            }
	        }
	        int heapArray[K];
	        int indexArray[K];
	        for(int j=0;j<K;j++){
	                
	                heapArray[j]=array[j][0];
                    indexArray[j]=j;
	        }
	        
	        
	        for(int l=0;l<size;l++){
	            
	        
	        
	        
	        
	        if(l==0) buildHeap(heapArray,K,indexArray,swap,comparison);
	        else heapify(heapArray,K,0,indexArray,swap,comparison);
	        
	        int index;
	    for(int i = 0; i < size; i++){
            if(arr[i] == heapArray[0]){
            index=i;
            
            arrayReal[l]=arr[index];
            
            break;
        }}
        
        int partition=indexArray[0];
        
        for(int y=0; y < size/K-1; y++)
        {
            array[partition][y] = array[partition][y+1];
        }
        array[partition][size/K-1]= INT_MAX;
        
        heapArray[0] = array[partition][0];
    }
    
	for(int q=0;q<size;q++){
	    arr[q]=arrayReal[q];
	}    
	}
	
	
	return number_of_calls;
}


