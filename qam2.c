b0VIM 7.4      �]Y0� �  ewa                                     ewa-VirtualBox                          ~ewa/ofdm/qam2.c                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             utf-8U3210    #"! U                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 tp           j                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             ad  �  R     j       �  �  �  �  �  �  �  �  L  5      �  �  �  �  �  �  �  �  �  �  y  j  f  N  ?  ;  #      �  �  �  �  �  �  �  �  �  �  u  f  ]  N  K  I  (  '  �  �  �  w  v  R  (  �  �  �  �  �  �  i  @        �
  �
  �
  �
  �
  �
  q
  j
  S
  )
  (
  	
  �	  �	  �	  �	  z	  i	  J	  '	  	  �  �  �  [  "      �  �  �  �  �  �  a  _  ^  T  R  S                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                } return 0;  } 	printf("%f\n", cimag(modulatedSignalComplex[i])); 	printf("%f\n", creal(modulatedSignalComplex[i])); for (int i=0;i<n;i++){  printf("po fft");    }       }             }           w = w * wm;           modulatedSignalComplex[k + j + (m/2)] = u - t;           modulatedSignalComplex[k + j] = u + t;           u = modulatedSignalComplex[k + j];           t = w * modulatedSignalComplex[k + j + (m/2)];         for(int j=0; j<= (m/2)-1; j++){       w = 1;     for(int k = 0; k<= n-1; k+=m){   wm = exp((-2 * 3.14 * i)/m);   m = pow(2, i); for(int i = 1; i <= log(n); i++){  } 	modulatedSignalComplex[i] = modulatedSignalRe[rev] + modulatedSignalIm[rev] * I; 	int rev = bitrev(i,2); for(unsigned int i=0;i<n;i++){  double complex modulatedSignalComplex[4]; double w, wm, t, b, u; int m; int n = SIGNAL_LENGTH;   }   printf("%d\n", modulatedSignalIm[i]);   printf("%d\n", modulatedSignalRe[i]); for(int i=0; i< SIGNAL_LENGTH; i++){ printf("zmodulowany\n"); }   printf("%d\n", dividedSignal[i]); for(int i=0; i< SIGNAL_LENGTH * 2; i++){ printf("podzielony\n"); }   j++;   modulatedSignalIm[i] = modulateQ(dividedSignal[j]);   dividedSignal[j] = inputSignal[i] & 0x3;   j++;   modulatedSignalRe[i] = modulateI(dividedSignal[j]);   dividedSignal[j] = inputSignal[i] >> 2; for(int i=0; i<SIGNAL_LENGTH; i++){  int j=0; uint8_t dividedSignal[SIGNAL_LENGTH * 2]; uint8_t  inputSignal[SIGNAL_LENGTH] = {11, 3, 6, 0}; int modulatedSignalRe[SIGNAL_LENGTH], modulatedSignalIm[SIGNAL_LENGTH];  int main(int argc, char **argv){ }  }     return -1;   }else{     return -3;   }else if(signal == 2){     return 1;   else if(signal == 1){   }     return 3;   if(signal== 0){ int modulateQ(uint8_t signal){  }    }   return 1;   } else{     return 3;   else if(signal == 2){   }     return -1;   else if(signal == 1){   }     return -3;   if(signal == 0){ int modulateI(uint8_t signal){  } 	return nrev; 	nrev &= N-1; 	} 		nrev |= n & 1; 		nrev <<= 1; 		n >>= 1; 	for(i=1; i<bits; i++){ 	nrev = n; 	unsigned int N = 1<<bits; 	unsigned int i, nrev; unsigned int bitrev(unsigned int n, unsigned int bits){  #define SIGNAL_LENGTH 4  #include <complex.h> #include <stdint.h> #include <math.h> #include <string.h> #include <stdio.h> 