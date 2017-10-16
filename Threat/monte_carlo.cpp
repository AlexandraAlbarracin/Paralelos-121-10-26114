#include <iostream>
#include <thread>
#include <mutex>
#include <time.h>
#include <stdlib.h>

using namespace std;

long long int* a;
int ncirculo = 0;
mutex m;
void montecarlo(int nthread, int id){
	long long int pi;
	long long int x = ((long long int) ((rand()%3) - 1));
	long long int y = ((long long int) ((rand()%3) - 1));
	long long int d = x*x + y*y;
	if(d <= 1){
		m.lock();
			ncirculo++;
		m.unlock();
	}
	pi = 4*ncirculo / ((double) nthread);
	a[id] = pi;
}

int main(){
	int nthread = 4;
	thread * thr = new thread(nthread);
	a = new long long int(nthread);
	for(int i = 0; i < nthread; i++){
		thr[i] = thread(montecarlo,nthread,i);
	}

	for(int i = 0; i < nthread; i++){
		thr[i].join();
	}

	long long res = 0;

	for(int i = 0; i < nthread; i++){
		res += a[i];
	}

	cout << "res" << res << endl;
	return 0;
} 