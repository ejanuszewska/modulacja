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
uint8_t  inputSignal[SIGNAL_LENGTH] = {4, 3, 6, 0};
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

for(int i = 1; i <= log(n); i++){
  m = pow(2, i);
  wm = exp((-2 * 3.14 * i)/m);
    for(int k = 0; k<= n-1; k+=m){
      w = 1;
        for(int j=0; j<= (m/2)-1; j++){
          t = w * modulatedSignalComplex[k + j + (m/2)];
          u = modulatedSignalComplex[k + j];
          modulatedSignalComplex[k + j] = u + t;
          modulatedSignalComplex[k + j + (m/2)] = u - t;
          w = w * wm;
         }
      }   
   }
printf("po fft");

for (int i=0;i<n;i++){
	printf("%f\n", creal(modulatedSignalComplex[i]));
	printf("%f\n", cimag(modulatedSignalComplex[i]));
}

return 0;
}
