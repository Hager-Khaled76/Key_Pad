/*
 * main.c
 *
 *  Created on: Aug 16, 2024
 *      Author: !?
 */





#include <avr/io.h>

char key_pad_GETKey(void){
    char key='a';    // ÊÑÌÚ áí ÇáÒÑÇÑ ÇáãÏÇÓ


         PORTD= 0b00001110;  // col 1
         if (((PINC>>0)&1)==0)
         {
         key=7;
         }


         else if (((PINC>>1)&1)==0)
         {
         key=4;
         }


         else if (((PINC>>2)&1)==0)
         {
         key=1;
         }

         else if (((PINC>>3)&1)==0)
         {
         key=' ';
         }

         PORTD= 0b00001101;  // col 2
         if (((PINC>>0)&1)==0)
         {
         key=8;
         }


         else if (((PINC>>1)&1)==0)
         {
         key=5;
         }


          else if (((PINC>>2)&1)==0)
         {
         key=2;
         }


         else if (((PINC>>3)&1)==0)
         {
         key=0;
         }


         PORTD= 0b00001011;  // col 3
         if (((PINC>>0)&1)==0)
         {
         key=9;
         }


         else if (((PINC>>1)&1)==0)
         {
         key=6;
         }


          else if (((PINC>>2)&1)==0)
         {
         key=3;
         }


         else if (((PINC>>3)&1)==0)
         {
         key='=';
         }

         PORTD= 0b00000111;  // col 4
         if (((PINC>>0)&1)==0)
         {
         key='/';
         }


         else if (((PINC>>1)&1)==0)
         {
         key='*';
         }


          else if (((PINC>>2)&1)==0)
         {
         key='-';
         }


         else if (((PINC>>3)&1)==0)
         {
         key='+';
         }

    return key;
}

void seg_display(unsigned char data)
{
    PORTA = data;

}

int main()
{
  DDRC= 0x00; // INPUT
  DDRD=0x0f;   //out
  DDRA= 0x0f;  //   pullup Çæá 4 out

  char res;
  while(1)
  {
    res= key_pad_GETKey();
    if (res>=0 && res<=9)
    {
    	seg_display(res);
    	 while( key_pad_GETKey()!= 'a');  //ÈíÓÊäÇäí áÍÏ ÇãÇ ÇÔíá ÇíÏí

    }

 }

 }




