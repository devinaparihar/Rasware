#include <RASLib/inc/common.h>
#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/adc.h>






// Blink the LED to show we're on
// tBoolean blink_on = true;

/*
void blink(void) {
    SetPin(PIN_D6, blink_on);
    blink_on = !blink_on;
}  
*/



// The 'main' function is the entry point of the program
int main(void) {
    // Initialization code can go here
    //CallEvery(blink, 0, 0.3);
    tMotor *left = InitializeServoMotor(PIN_B2, true);
	tMotor *right = InitializeServoMotor(PIN_B3, false);
    tADC *dist = InitializeADC(PIN_E4);
    float distval;
    int dec = 0.5;
    int dec1 = 0.5;
    float previous;
    float difff;
  
    distval = ADCRead(dist);

    while (true) { 
        // Runtime code can go here
        //Printf("Hello World!\n");
        previous = distval;
        distval = ADCRead(dist);
        difff = distval - previous;
            if (difff < 0) {
                difff = difff*(-1);
            }
            change (difff)

        Printf("IR sensor value is %f\n", distval);


        SetMotor(left, 1);
        SetMotor(right, 1);
    
     
        dec1 = 0.1;
        
        while ( distval < 0.50 ) 
        {
            SetMotor(left, (1-dec1);
            SetMotor(right, 1);
            
            if (dec1 <.7) {
              dec1 += 0.1;
            }
             
            previous = distval; 
            distval = ADCRead(dist);
            difff = distval - previous;
            if (difff < 0) {
                difff = difff*(-1);
            }
            change (difff)

            Printf("loop 1, IR sensor value is %f\n", distval);
        }

        dec = 0.1; 

        while ( distval > 0.7 ) 
        {
            SetMotor(left, 1);    //(1-dec)
            SetMotor(right, (1-dec);
            
            if (dec <.7) {
              dec += 0.1;
            }
            
            previous = distval;
            distval = ADCRead(dist);
            difff = distval - previous;
            if (difff < 0) {
                difff = difff*(-1);
            }
            change (difff)

            Printf("loop 2, IR sensor value is %f\n", distval);
        }

        while ( (distval <= 0.7) & (distval >= 0.5) )
        {
            previous = distval;
            distval = ADCRead(dist);
            difff = distval - previous;
            if (difff < 0) {
                difff = difff*(-1);
            }
            change (difff)

            Printf("loop 3, IR sensor value is %f\n", distval);

            SetMotor(left, 1);
            SetMotor(right, 1);
        }
    }

    void change(int diff) {
        while (diff > 0.3) {
            Switch (diff) {
                case 0.3 > diff < 0.4 : 
                    SetMotor(left, 1);    //(1-dec)
                    SetMotor(right, (1-0.15); 
                break;

                case 0.4 > diff < 0.5 :
                    SetMotor(left, 1);    //(1-dec)
                    SetMotor(right, (1-0.3);
                break;

                case 0.5 > diff < 0.6 :
                    SetMotor(left, 1);    //(1-dec)
                    SetMotor(right, (1-0.45);
                break;

                case 0.6 > diff < 0.7 :
                    SetMotor(left, 1);    //(1-dec)
                    SetMotor(right, (1-0.6);
                break;

                case 0.7 > diff < 0.8 :
                    SetMotor(left, 1);    //(1-dec)
                    SetMotor(right, (1-0.75);
                break;

                case 0.8 > diff < 0.9 :
                    SetMotor(left, 1);    //(1-dec)
                    SetMotor(right, (1-0.9);
                break;

                default: 
                    break;
        }

        }
    }
} 



