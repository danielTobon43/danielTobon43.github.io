/*
 * ProyectoFinalMicro.cpp
 *
 * Created: 09/11/2016 07:42:51 p. m.
 * Author : Daniel Tobón, Camilo Perez & David Fernandez 
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "include/funciones.c"


#define F_CPU 16000000UL
void proceso();
unsigned char contador=0;
unsigned char estado;
unsigned char estadoFinal=0;
unsigned char estadoFinal2=0;
unsigned char temp;
#include <util/delay.h>


int main(void)
{
    //===================================================
    //INICIO PROGRAMA
    //===================================================
    cli();
	DDRB = 0xFF; //DEFINE CÓMO SALIDA EL PUERTO B,PUERTOS QUE ENVIARA LAS SEÑALES DE ACTIVACION DEL MOTOR Y LA ELECTROVALVULA
	DDRF = 0x00; //DEFINE CÓMO ENTRADA EL PUERTO F (PUERTO DEL ADC), ENTRARA LA SEÑAL ENVIADA POR EL LM35
	DDRA = 0x00;
	PORTA = 0xFF;
	//===================================================
	//CONFIGURACIÓN DEL ADC
	//===================================================
	confADC();
	//===================================================
	//CONFIGURACIÓN TIMER 1
	//===================================================
	confTIMER();
	//===================================================
	//CONFIGURACIÓN USART
	//===================================================
	confUSArt();	 
    sei(); 
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADSC); //INICIO DE CONVERSIÓN
	 
	 while(1){
		 proceso();
	 }
	 
	 }//Fin MAIN
	
ISR(TIMER1_OVF_vect){
	TCNT1L=0xF4;
	TCNT1H=0xFF;
}	

void proceso(){
	
	asm("FinCONV:");
	asm("LDS R16,0x7A");	//DIRECCIÓN DEL REGISTRO ADCSRA
	asm("SBRS R16,4");		//SKIP NEXT INSTRUCTION IF BIT 4 IS SET IN R16
	asm("JMP FinCONV");
	
	temp=ADCH+0x22;	
	UDR0 = temp;
	asm("TRANSEND:");
	asm("LDS R16,0xC0");//CARGA LA DIRECCIÓN DEL REGISTRO UCSR0A
	asm("SBRS R16,6");	//SKIP NEXT INTRUCTION IF BIT 7 IS SET IN R16 (BIT DE BANDERA DATO RECIBIDO)
	asm("JMP TRANSEND");
	UCSR0A=(1<<UDRE0);
	
	contador++;	
	estado=PINA;
	if(estado==0B11001010){
		estado=0B11001010;
	}else if (estadoFinal2==0B10000000)
	{
		estado=0B11110101;
	}
	else if(estado==0B11101010)
	{
		estado=0B11101010;
	}else if(estadoFinal==(0B10000000)){
		estado=(0B11110101);		
	}else if(estadoFinal==0B11000000){
		estado=(0B11100000);
	}else{
		estado=PINA;
	}
	
	if(contador<8){
			switch(contador)
			{					
				//======================================================================
				//CASO 1
				//======================================================================
							case 1:							
							if (estado==0B11111110)
							{
								PORTB=(0B00000001);		
							}else{		
							break;
							}						
				//======================================================================
				//CASO 2
				//======================================================================		
							case 2:
								if (estado==0B11111100)
								{
									PORTB=(0B00000011);																			
								}else {
								break;
							}							
				//======================================================================
				//CASO 3
				//======================================================================							
							case 3:
							if (estado==0B11111000)
							{											
								PORTB=(0B00000111);																													
							}else{
							break;
							}
				//======================================================================
				//CASO 4
				//======================================================================												
						case 4:						
						if(estado==0B11110010){							
							PORTB=0B00001001;
							_delay_ms(2000);
							estadoFinal=(0B10000000);
							
						}else{
							break;
						}
						break;
				//======================================================================
				//CASO 5
				//======================================================================		
						case 5:
						if(estado==(0B11110101)){
							PORTB=0B00000101;							
							estadoFinal=(0B10000000);							
						}else{
							break;
						}
						break;
				//======================================================================
				//CASO 6
				//======================================================================		
						case 6:
						if(estado==0B11101010){
							PORTB=0B00010001;
							_delay_ms(1000);
							estadoFinal2=(0B10000000);
							
							
						}else{
							break;
						}
						break;
				//======================================================================
				//CASO 7
				//======================================================================											
						case 7:
						if(estado==0B11001010){
							PORTB=0B00100000;
						}else{
							break;
						}
						break;
					
		}//Fin switch case
		}else{
			contador=0;
		}//Fin contador
		ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADSC); //INICIO DE CONVERSIÓN
	}//Fin subrutina
	

		
		 
	

