/*******************************************************
This program was created by the
CodeWizardAVR V3.14 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 12/10/2024
Author  : 
Company : 
Comments: 


Chip type               : ATmega32A
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/

#include <string.h>
#include <mega32a.h>
#include <delay.h>
#define RS PORTB2  // Register Select
#define RW PORTB1  // Read/Write
#define EN PORTB0  // Enable
#define LCD_CTRL PORTB
#define LCD_CTRL_DIR DDRB
#define LCD_DATA PORTD
#define LCD_DATA_DIR DDRD

void init_LCD(void);
void LCD_data(unsigned char);
void LCD_cmd(unsigned char); 
        // ICs Function Prototype                             
void HEF4071BP (unsigned char *);
void SN74LS279NDS (unsigned char *);
void CD4000AE (unsigned char *);
void SN7482 (unsigned char *);
void SN75492AN (unsigned char *);
void DM74366 (unsigned char *);
void SN74AS298N (unsigned char *);
void CD4007UBE (unsigned char *);
// Declare your global variables here

// Declare your global variables here

void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);
/***********************
// Port D initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRD=0xFF;
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);
*************************/
// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (0<<CS01) | (0<<CS00);
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0<<AS2;
TCCR2=(0<<PWM2) | (0<<COM21) | (0<<COM20) | (0<<CTC2) | (0<<CS22) | (0<<CS21) | (0<<CS20);
TCNT2=0x00;
OCR2=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
MCUCSR=(0<<ISC2);

// USART initialization
// USART disabled
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (0<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);

// Analog Comparator initialization
// Analog Comparator: Off
// The Analog Comparator's positive input is
// connected to the AIN0 pin
// The Analog Comparator's negative input is
// connected to the AIN1 pin
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
SFIOR=(0<<ACME);

// ADC initialization
// ADC disabled
ADCSRA=(0<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);

// SPI initialization
// SPI disabled
SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);

// TWI initialization
// TWI disabled
TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);

while (1)
      {
      unsigned char IC_Flag = 0;
      unsigned char i = 0;
      unsigned char IC_Name[20];
      memset(IC_Name,0, sizeof(IC_Name));
      DDRA=0;
      DDRC=0;
      PORTA=0xFF;
      PORTC=0xFF;
      if(IC_Flag == 0)  
        CD4000AE(&IC_Flag);
      if(IC_Flag == 0)  
        HEF4071BP(&IC_Flag);
      if(IC_Flag == 0)  
        SN7482(&IC_Flag);
      if(IC_Flag == 0)  
        SN75492AN(&IC_Flag);
      if(IC_Flag == 0)  
        DM74366(&IC_Flag);
      if(IC_Flag == 0)  
        CD4007UBE(&IC_Flag); 
      if(IC_Flag == 0)  
        SN74AS298N(&IC_Flag);
      if(IC_Flag == 0)  
        SN74LS279NDS(&IC_Flag);
      if(IC_Flag == 1)
         strcpy((char *)IC_Name,"HEF4071BP ");
      else if(IC_Flag == 2)
          strcpy((char *)IC_Name,"CD4000AE ");
      else if(IC_Flag == 3)
          strcpy((char *)IC_Name,"SN74LS279NDS "); 
      else if(IC_Flag == 4)
          strcpy((char *)IC_Name,"SN7482 "); 
      else if(IC_Flag == 5)
          strcpy((char *)IC_Name,"SN75492AN "); 
      else if(IC_Flag == 6)
          strcpy((char *)IC_Name,"DM74366 "); 
      else if(IC_Flag == 7)
          strcpy((char *)IC_Name,"SN74AS298N ");
      else if(IC_Flag == 8)
          strcpy((char *)IC_Name,"CD4007UBE ");
      else if(IC_Flag == 0)
          strcpy((char *)IC_Name,"Unknown IC "); 
      init_LCD();
      LCD_cmd(0x01); // Clear the LCD screen (optional but recommended to remove old data)
      LCD_cmd(0x80);
      while(1)  
      {
            LCD_data(IC_Name[i]);
            if(IC_Name[i] == 0)
                    break;
            else i++;
      }
      delay_ms(200);
      }
}



void HEF4071BP (unsigned char * IC_Flag)        
{
      DDRA=(0<<DDA7) | (1<<DDA6) | (1<<DDA5) | (1<<DDA4) | (0<<DDA3) | (0<<DDA2) | (1<<DDA1) | (1<<DDA0);
      DDRC=(0<<DDC7) | (1<<DDC6) | (1<<DDC5) | (0<<DDC4) | (0<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
      PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (1<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (1<<PORTA1) | (1<<PORTA0);
      PORTC=(0<<PORTC7) | (0<<PORTC6) | (1<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (1<<PORTC0);
      if ((PINA & (1 << PINA2)) != 0 && (PINA & (1 << PINA3)) != 0 && (PINC & (1 << PINC4)) != 0 && (PINC & (1 << PINC3)) == 0)
                               *IC_Flag = 1; 
}



void CD4000AE (unsigned char * IC_Flag)          
{
      DDRA=(0<<DDA7) | (1<<DDA6) | (0<<DDA5) | (1<<DDA4) | (1<<DDA3) | (1<<DDA2) | (0<<DDA1) | (0<<DDA0);
      DDRC=(0<<DDC7) | (1<<DDC6) | (0<<DDC5) | (0<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
      PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);
      PORTC=(0<<PORTC7) | (1<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (1<<PORTC3) | (0<<PORTC2) | (1<<PORTC1) | (1<<PORTC0);
      if ((PINC & (1 << PINC5)) == 0 )
      {
             if ((PINA & (1 << PINA5)) != 0  &&  (PINC & (1 << PINC4)) == 0) 
             {
                     *IC_Flag = 2;    
             }
      }
}




void SN74LS279NDS (unsigned char * IC_Flag)          
{

      DDRA=(1<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (1<<DDA1) | (1<<DDA0);
      DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
      PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (1<<PORTA0);
      PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (1<<PORTC1) | (1<<PORTC0);
      if(((PINA & (1<<PINA3)) != 0 ) && ((PINC & (1<<PINC3))) == 0 )
      {
      PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (1<<PORTA1) | (1<<PORTA0);   // S=0 R=0
      PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (1<<PORTC2) | (1<<PORTC1) | (1<<PORTC0);   // S=0 R=0
      delay_ms(10);
      if(((PINA & (1<<PINA3)) != 0 ) && ((PINC & (1<<PINC3))) == 0 )
                            *IC_Flag = 3;                      
      }
}




void SN7482(unsigned char * IC_Flag)          
{
    // Set up the directions for PORTA and PORTC pins
    DDRA = (0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (1<<DDA4) | (1<<DDA3) | (1<<DDA2) | (1<<DDA1) | (0<<DDA0);  
    DDRC = (0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (1<<DDC3) | (0<<DDC2) | (1<<DDC1) | (1<<DDC0);  

    // Initialize PORTA and PORTC
    PORTA = (0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (1<<PORTA4) | (1<<PORTA3) | (1<<PORTA2) | (1<<PORTA1) | (1<<PORTA0); // A1 = B1 = C0 = HIGH
    PORTC = (0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (1<<PORTC1) | (1<<PORTC0);  // A2 = B2 = HIGH
    if (((PINA & (1<<PINA0)) != 0) && ((PINC & (1<<PINC2)) != 0) && ((PINC & (1<<PINC4)) != 0))  // Check if PA2 is high
    {    
        PORTA &= ~(1<<PORTA4);
        delay_ms(10);
        if (((PINA & (1<<PINA0)) == 0) && ((PINC & (1<<PINC2)) != 0) && ((PINC & (1<<PINC4)) != 0))  // Check if PA2 is high
                *IC_Flag = 4;
    }
}



void SN75492AN(unsigned char * IC_Flag)         
{
    // Set up the directions for PORTA and PORTC pins
    DDRA = (0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (1<<DDA4) | (1<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);  
    DDRC = (0<<DDC7) | (1<<DDC6) | (0<<DDC5) | (1<<DDC4) | (1<<DDC3) | (1<<DDC2) | (0<<DDC1) | (1<<DDC0);  

    // Initialize PORTA and PORTC
    PORTA = (0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (1<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0); 
    PORTC = (0<<PORTC7) | (1<<PORTC6) | (0<<PORTC5) | (1<<PORTC4) | (1<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0); 
    if (((PINA & (1<<PINA5)) == 0)  && ((PINA & (1<<PINA6)) == 0) && ((PINA & (1<<PINA0)) != 1) && ((PINC & (1<<PINC5)) == 0))            
                *IC_Flag = 5;     

}



void DM74366(unsigned char * IC_Flag)          
{
    // Set up the directions for PORTA and PORTC pins
    DDRA = (1<<DDA7) | (0<<DDA6) | (1<<DDA5) | (0<<DDA4) | (1<<DDA3) | (0<<DDA2) | (1<<DDA1) | (1<<DDA0);  
    DDRC = (0<<DDC7) | (1<<DDC6) | (0<<DDC5) | (1<<DDC4) | (0<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);  

    // Initialize PORTA and PORTC
    PORTA = (0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0); 
    PORTC = (0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (1<<PORTC0);
    delay_ms(10); 
    if (((PINA & (1<<PINA2)) != 0))
    {  
        PORTA|=(1<<PORTA1);
        delay_ms(10);
        if (((PINA & (1<<PINA2)) == 0))
             *IC_Flag = 6; 
    }            
}


void SN74AS298N(unsigned char * IC_Flag)          
{
    // Set up the directions for PORTA and PORTC pins
    DDRA = (1<<DDA7) | (1<<DDA6) | (1<<DDA5) | (1<<DDA4) | (1<<DDA3) | (1<<DDA2) | (1<<DDA1) | (1<<DDA0);  
    DDRC = (1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (1<<DDC0);  

    // Initialize PORTA and PORTC
    PORTA = (0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (1<<PORTA4) | (1<<PORTA3) | (1<<PORTA2) | (1<<PORTA1) | (0<<PORTA0);  // a1 b1 c1 d1 1100
    PORTC = (0<<PORTC7) | (0<<PORTC6) | (1<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (1<<PORTC0);  // a2 b2 c2 d2 1010
    delay_ms(1);
    PORTC &= ~((1<<PORTC5)); // Pulse  
    delay_ms(10);
    if (((PINC & (1<<PINC1)) != 0)  && ((PINC & (1<<PINC2)) != 0) && ((PINC & (1<<PINC3)) == 0) && ((PINC & (1<<PINC4)) == 0))
    {  
             PORTC |= (1<<PORTC6);
             PORTC |= ((1<<PORTC5)); // Pulse
             delay_ms(1);
             PORTC &= ~((1<<PORTC5));
             delay_ms(10);
             if (((PINC & (1<<PINC1)) != 0)  && ((PINC & (1<<PINC2)) == 0) && ((PINC & (1<<PINC3)) != 0) && ((PINC & (1<<PINC4)) == 0))
                                 *IC_Flag = 7; 
    }            
}


void CD4007UBE(unsigned char * IC_Flag)          
{
    // Set up the directions for PORTA and PORTC pins
    DDRA = (0<<DDA7) | (1<<DDA6) | (0<<DDA5) | (0<<DDA4) | (1<<DDA3) | (1<<DDA2) | (0<<DDA1) | (0<<DDA0);  
    DDRC = (0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (1<<DDC0);  

    // Initialize PORTA and PORTC
    PORTA = (0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (1<<PORTA4) | (0<<PORTA3) | (1<<PORTA2) | (0<<PORTA1) | (0<<PORTA0); 
    PORTC = (0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (1<<PORTC0);
    delay_ms(10); 
    if (((PINA & (1<<PINA4)) == 0))            
    {
     PORTA &= ~(1<<PORTA2);
     delay_ms(10);
     if (((PINA & (1<<PINA4)) != 0))
           *IC_Flag = 8;
    }                

}
 
/**********************************************************/                                 

void LCD_cmd(unsigned char cmd) {
    LCD_DATA = cmd;          // Send command to data lines
    LCD_CTRL &= ~(1 << RS);  // RS = 0 for command
    LCD_CTRL &= ~(1 << RW);  // RW = 0 for write
    LCD_CTRL |= (1 << EN);   // Generate a high-to-low pulse on EN
    delay_ms(1);
    LCD_CTRL &= ~(1 << EN); // EN = 0
    delay_ms(2);            // Small delay for the LCD to process
}

// Function to send data to the LCD
void LCD_data(unsigned char data) {
    LCD_DATA = data;          // Send data to data lines
    LCD_CTRL |= (1 << RS);    // RS = 1 for data
    LCD_CTRL &= ~(1 << RW);   // RW = 0 for write
    LCD_CTRL |= (1 << EN);    // Generate a high-to-low pulse on EN
    delay_ms(1);
    LCD_CTRL &= ~(1 << EN);   // EN = 0
    delay_ms(2);             // Small delay for the LCD to process
}

// Initialize the LCD
void init_LCD() {
    LCD_CTRL_DIR |= (1 << RS) | (1 << RW) | (1 << EN); // Set control pins as output
    LCD_DATA_DIR = 0xFF;                               // Set PORTD as output for data

    delay_ms(20);       // Wait for LCD to power up
    LCD_cmd(0x38);       // Set 8-bit mode, 2-line display, 5x8 font
    LCD_cmd(0x0C);       // Display ON, Cursor OFF
    LCD_cmd(0x01);       // Clear display
    delay_ms(2);        // Wait for the clear command to complete
    LCD_cmd(0x06);       // Entry mode: Increment cursor, no shift
}
