#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#define SIGNAL_LENGTH 4
#define SWAP(x, y) do {int SWAP = x; x = y; y = SWAP;} while(0)

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

int modulatedSignal[SIGNAL_LENGTH * 2];
uint8_t  inputSignal[SIGNAL_LENGTH] = {1, 3, 4, 0};
uint8_t dividedSignal[SIGNAL_LENGTH * 2];
int j=0;

for(int i=0; i<SIGNAL_LENGTH; i++){
  dividedSignal[j] = inputSignal[i] >> 2;
  modulatedSignal[j] = modulateI(dividedSignal[j]);
  j++;   
  dividedSignal[j] = inputSignal[i] & 0x3;
  modulatedSignal[j] = modulateQ(dividedSignal[j]);
  j++;
}
printf("podzielony\n");
for(int i=0; i< SIGNAL_LENGTH * 2; i++){
  printf("%d\n", dividedSignal[i]);
}
printf("zmodulowany\n");
for(int i=0; i< SIGNAL_LENGTH * 2; i++){
  printf("%d\n", modulatedSignal[i]);
}


int n = SIGNAL_LENGTH;
int m, w, wm, t, u, b;
int nn = (n*2);
int a = 0;

for(int i = 0; i < (nn); i+=2){
  if (a > i){
    SWAP(modulatedSignal[a], modulatedSignal[a]);
    SWAP(modulatedSignal[a+1], modulatedSignal[i+1]);
 }
  b = n;
  while (b >= 2 && a > b){
    a -= b;
    b = b/2;
  }  
  a += b;
}
printf("po zamianie\n");
for(int i=0;i<n*2;i++){
printf("%d\n", modulatedSignal[i]);
}
for(int i = 1; i <= log(n); i++){
  m = pow(2, i);
  wm = exp((-2 * 3.14 * i)/m);
    for(int k = 0; k<= n-1; k+=m){
      w = 1;
        for(int j=0; j<= (m/2)-1; j++){
          t = w * modulatedSignal[k + j + (m/2)];
          u = modulatedSignal[k + j];
          modulatedSignal[k + j] = u + t;
          modulatedSignal[k + j + (m/2)] = u - t;
          w = w * wm;
         }
      }   
   }
printf("po fft");
for (int i=0;i<n*2;i++){
printf("%d\n", modulatedSignal[i]);
}
return 0;
}