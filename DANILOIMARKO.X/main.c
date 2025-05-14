/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.6
        Device            :  PIC18F87K22
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <xc.h> 
/*
                         Main application
 */
//IN2 RC0  IN1 RE0   PWM RC1  STDBY RB0

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    
    #define Button      RD0

    #define IN1         RE0
    #define IN2         RC0

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    //volatile int16_t duty_cycle = 0;
    //volatile bool flag;
    while (1)
    {
        //OVO ISPOD NE VALJA 
        /*if(flag)
        {
            flag = false;
            EPWM3_LoadDutyValue(duty_cycle);
            
        }
         * NI OVO ISPOD 
        for(duty_cycle=0;duty_cycle<=89;duty_cycle++)
            {
            EPWM3_LoadDutyValue(duty_cycle);
            __delay_ms (10);
        } */
        /*void set_pwm_duty(uint16_t pwm_duty)
        {
          CCP1CON = ((pwm_duty << 4) & 0x30) | 0x0C;
          CCPR1L  =   pwm_duty >> 2;
        }
        //DEBOUNCE
        __bit debounce ()
        {
          uint8_t br = 0;
          for(uint8_t i = 0; i < 5; i++) {
            if (Button == 0)
              br++;
            __delay_ms(10);
          }
          if(br > 2){ 
              return 1;
          }
          else           return 0;
        }
        
        
        
         */
         //CW
        LATEbits.LATE0=0xFF;
        LATCbits.LATC0=0x00;
        LATCbits.LATC1=0xFF;
        LATBbits.LATB0=0xFF;
        __delay_ms(2000);
        
        //stop
        LATEbits.LATE0=0x00;
        LATCbits.LATC0=0x00;
        LATCbits.LATC1=0x00;
        LATBbits.LATB0=0xFF;
        __delay_ms(2000);
        
        //CCW, RD0
        LATEbits.LATE0=0x00;
        LATCbits.LATC0=0xFF;
        LATCbits.LATC1=0xFF;
        LATBbits.LATB0=0xFF;
        __delay_ms(2000);
        
        //stop
        LATEbits.LATE0=0x00;
        LATCbits.LATC0=0x00;
        LATCbits.LATC1=0x00;
        LATBbits.LATB0=0xFF;
        __delay_ms(2000);
        
        
    }
}
/**
 End of File
*/