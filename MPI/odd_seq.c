#include <stdio.h>

void Odd_even_sort(int a[], int n){
	int phase, i, temp;
	for(phase = 0; phase < n; phase++){
		if(phase % 2 == 0){
			for(i = 1; i < n; i+=2){
				if(a[i-1] > a[i]){
					temp = a[i];
					a[i] = a[i-1];
					a[i-1] = temp;				
				}
			}
		}
		else{
		for(i = 1; i < n-1; i+=2){
			if(a[i] > a[i+1]){
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
			}
		}
	}
	}	
}

int main(){
	int a[8];
	int j = 8;
	for(int i = 0; i < 8; i++){
		a[i] = j;
		j--;
	}

	for(int i = 0; i < 8; i++){
		printf("%d\t", a[i]);
	}
	printf("\n");

	Odd_even_sort(a,8);

	for(int i = 0; i < 8; i++){
		printf("%d\t", a[i]);
	}
	printf("\n");
	return 0;
}