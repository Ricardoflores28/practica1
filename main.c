#include <include/18F4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#define __DEBUG_SERIAL__ //Si comentas esta linea se deshabilita el debug por serial y el PIN_C6 puede ser usado en forma digital I/O
#ifdef __DEBUG_SERIAL__
   #define TX_232        PIN_D6
   #use RS232(BAUD=9600, XMIT=TX_232, BITS=8,PARITY=N, STOP=1)
#endif
void main (void){
   setup_oscillator(OSC_16MHZ);//Configuramos el oscilador a la frecuencia que querramos            
   int contador= 0b10000000; //nuestro contador estara igualado a base binario
       set_tris_d(0x00);//ingresamos set_tris para asignar el puerto que estara todos en 0  
   while(1){//nuestra condicion en este caso
       output_d(contador);//la salida del puerto d sera nuestro contador
       delay_ms(500);//tendra un retraso de 500 mm          
       output_d(0x00);//El puerto sera todos de salida por eso tenemos todos en "0"
       contador/=0b10;//lo dividiremos en 2 para que vaya decrementando
   if (contador ==0){
       contador=0b10000000;
   }
