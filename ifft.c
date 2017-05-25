#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <complex.h>

#define SIGNAL_LENGTH 4

unsigned int bitrev(unsigned int n, unsigned int bits){
	unsigned int i, nrev;
	unsigned int N = 1<<bits;
	nrev = n;
	for(i=1; i<bits; i++){
		n >>= 1;
		nrev <<= 1;
		nrev |= n & 1;
	}
	nrev &= N-1;
	return nrev;
}

int modulateI(uint8_t signal){
  if(signal == 0){
    return -3;
  }
  else if(signal == 1){
    return -1;
  }
  else if(signal == 2){
    return 3;
  } else{
  return 1;
   }
}

int modulateQ(uint8_t signal){
  if(signal== 0){
    return 3;
  }
  else if(signal == 1){
    return 1;
  }else if(signal == 2){
    return -3;
  }else{
    return -1;
 }
}
int main(int argc, char **argv){

int modulatedSignalRe[SIGNAL_LENGTH], modulatedSignalIm[SIGNAL_LENGTH];
uint8_t  inputSignal[SIGNAL_LENGTH] = {1, 2, 3, 4};
uint8_t dividedSignal[SIGNAL_LENGTH * 2];
int j=0;

for(int i=0; i<SIGNAL_LENGTH; i++){
  dividedSignal[j] = inputSignal[i] >> 2;
  modulatedSignalRe[i] = modulateI(dividedSignal[j]);
  j++;
  dividedSignal[j] = inputSignal[i] & 0x3;
  modulatedSignalIm[i] = modulateQ(dividedSignal[j]);
  j++;
}
printf("podzielony\n");
for(int i=0; i< SIGNAL_LENGTH * 2; i++){
  printf("%d\n", dividedSignal[i]);
}
printf("zmodulowany\n");
for(int i=0; i< SIGNAL_LENGTH; i++){
  printf("%d\n", modulatedSignalRe[i]);
  printf("%d\n", modulatedSignalIm[i]);
}


int n = SIGNAL_LENGTH;
int m;
double b, w, wm;
double complex modulatedSignalComplex[4], t, u;

for(unsigned int i=0;i<n;i++){
	int rev = bitrev(i,2);
	modulatedSignalComplex[i] = modulatedSignalRe[rev] + modulatedSignalIm[rev] * I;
}

/*for(int i = 1; i < log2(n); i++){
  m = pow(2, i);
  wm = exp((-2 * M_PI * I)/m);
    for(int k = 0; k<= n; k+=m){
      w = 1;
        for(int l=0; l<= (m/2) -1; l++){
          t = w * modulatedSignalComplex[k + l + (m/2)];
          u = modulatedSignalComplex[k + l];
          modulatedSignalComplex[k + l] = u + t;
          modulatedSignalComplex[k + l + (m/2)] = u - t;
          w = w * wm;
         }
      }   
   }*/
double complex W[n/2];
W[1] = 1.* cos(-2 * M_PI / n) + I * 1. * sin(-2 * M_PI /n); 
W[0] = 1;
for(int i=2; i< n/2; i++){
W[i] = pow(W[1], i);
}
int n2=1;
int a = n/2;
for(int j = 0; j < log2(n); j++){
//  m = pow(2, i);
//  wm = exp((-2 * M_PI * I)/m);
    for(int i = 0; i< n; i++){
	if(!(i & n2)){
	
          t = modulatedSignalComplex[i];
          u = W[(i*2) % (n2 * a)] * modulatedSignalComplex[i+n2];
          modulatedSignalComplex[i] = u + t;
          modulatedSignalComplex[i+n2] = t - u;
         }
      }   
n2 *= 2;
a = a/2;
}

printf("po fft");

for (int i=0;i<n;i++){
	printf("%f\n", creal(modulatedSignalComplex[i]));
	printf("%f\n", cimag(modulatedSignalComplex[i]));
}

return 0;
}
