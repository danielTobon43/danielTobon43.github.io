void confADC();
	void confADC(){
		//===================================================
		//CONFIGURACIÓN DEL ADC
		//===================================================
    
		ADMUX |= (1<<REFS0)|(1<<ADLAR); //REFERENCIA AVCC=5V,JUSTIFICACIÓN DEL DATO A LA IZQUIERDA
		ADCSRA |= (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); //HABILITACIÓN DEL ADC,PRESCALER DE 128
		ADCSRB |= 0x00; //SELECCIÓN DEL ADC (ADC0)
	}
void confTIMER();
	void confTIMER(){
		//===================================================
		//CONFIGURACIÓN DEL TIMER 1
		//===================================================
    	
		TCCR1B |= (1<<CS12)|(1<<CS10); //PRESCALER DE 1024
		TIMSK1 |= (1<<TOIE1); //HABILITACIÓN DE LA INTERRUPCIÓN POR OVERFLOW
		}
void confUSArt();
	void confUSArt(){
		//===================================================
		//CONFIGURACIÓN USART
		//===================================================
		 UCSR0B |= (1<<TXEN0);	//MODO RECEPCIÓN E INT_POR RECEPCIÓN,BOTON DE PARADA DE EMERGENCIA
		 UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);//MODO ASINCRONO, 8 BITS, 1 BIT DE PARADA, NO BITS DE PARIDAD
		 UBRR0L = 103;					//103 ->>VELOCIDAD DE 9600 BAUDIOS (BITS POR SEGUNDO)
	}