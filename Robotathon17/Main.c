#include <RASLib/inc/common.h>
#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/adc.h>


// The 'main' function is the entry point of the program
int main(void) {
    tMotor *left = InitializeServoMotor(PIN_B3, true);
    tMotor *right = InitializeServoMotor(PIN_B2, false);
    tADC *dist = InitializeADC(PIN_E4);
    tADC *dist_front= InitializeADC(PIN_E5);
    tLineSensor *line = InitializeGPIOLineSensor(PIN_D0, PIN_D2, PIN_D3, PIN_D1, PIN_E1, PIN_E2, PIN_E3, PIN_E4);
    //These are the eight pins you chose in the proper order
    float linevals[8];
    float weightedvals[8];
    float weights[] = [-4, -3, -2, -1, 1, 2, 3, 4]
    float weightedsum;
    float weightedavg;

    while(1){
      LineSensorReadArray(line, linevals);
      Printf(“%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t”, value[0], value[1], value[2], value[3], value[4], value[5], value[6], value[7]);
      // \t is the escape character for tabs

      for(i = 0; i < 8; i++){
        weightedsum += weights[i] * linevals[i]
      }

      weightedavg = weightedsum / 8;
    }
}
