#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#define SIGNAL_LENGTH 4
#define SWAP(x, y) do {int SWAP = x; x = y; y = SWAP;} while(0)

unsigned int reverse(unsigned int x){
x = ((x >> 1) & 0x55555555u) | ((x & 0x55555555u) << 1);
x = ((x >> 2) & 0x33333333u) | ((x & 0x33333333u) <<2);
x = ((x >> 4) & 0x0f0f0f0fu) | ((x & 0x0f0f0f0fu) << 4);
x = ((x >> 8) & 0x00ff00ffu) | ((x & 0x00ff00ffu) << 8);
x = ((x >> 16) & 0xffffu) | ((x & 0xffffu) << 16);
return x;
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

int modulatedSignal[SIGNAL_LENGTH * 2];
uint8_t  inputSignal[SIGNAL_LENGTH] = {1, 3, 4, 0};
uint8_t dividedSignal[SIGNAL_LENGTH * 2];
int j=1;

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
int nn = (n*2) << 1;
/*int a = 0;

for(int i = 1; i < nn; i+=2){
  if (a > i){
    SWAP(modulatedSignal[a-1], modulatedSignal[i-1]);
    SWAP(modulatedSignal[a], modulatedSignal[i]);
 }
  b = n*2;
  while (b >= 2 && a > b){
    a -= b;
    //b = b/2;
    b >>= 1;
  }  
  a += b;
}
*/

printf("po zamianie\n");
for(unsigned int i=0;i<n*2;i++){
unsigned int x=i;
x = ((x >> 1) & 0x55555555u) | ((x & 0x55555555u) << 1);
x = ((x >> 2) & 0x33333333u) | ((x & 0x33333333u) <<2);
x = ((x >> 4) & 0x0f0f0f0fu) | ((x & 0x0f0f0f0fu) << 4);
x = ((x >> 8) & 0x00ff00ffu) | ((x & 0x00ff00ffu) << 8);
x = ((x >> 16) & 0xffffu) | ((x & 0xffffu) << 16);
if(x > i){
//int temp = modulatedSignal[i];
//modulatedSignal[i] = modulatedSignal[x];
//modulatedSignal[x] = temp;
}
}

for (int i=0; i<n*2; i++){
printf("%d", modulatedSignal[i]);
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
