#pragma config(Sensor, in1,    InfraCollector, sensorReflection)
#pragma config(Sensor, dgtl1,  RedLED,         sensorDigitalOut)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*************************************************************************
VEX Program -ENGR 120/121 Light sensor lab

Description: This program turns on an LED when the phototransistor is
exposed to a sufficiently large amount of infrared light.


Configuration: This program is written to work with the sensors constructed
as described in the ENGR 120/121 Lab 3 description.

	Breadboard connected to	- analog port 1 measures phototransistor
	                        - digital port 1 controls a red LED

*************************************************************************/

// Threshold of value read from phototransistor circuit.
const   int IR_SENSOR_THRESHOLD = 1000;

// Type of variable that will store the state values.
enum programState
{
  LookingForSignal = 0,   // Replace names with something more descriptive in in your project code.
  STATE1
};

// LED light control values.
const   int OFF = 0;
const   int ON  = 1;

void init_light_status()
{
  // Turn of the red LED
  SensorValue(RedLED)= OFF;
}


task main()
{
  // System state variable
  programState currState;

  // Initialize lighting status.
  init_light_status();

  // Initialize system state
  currState  = STATE0;

  // Endless loop
  while (1==1)
  {
    switch(currState)
    {
      // Management of system when in state 0
      case(STATE0):

        // LED should be off when we are in this state.
        SensorValue(RedLED) = OFF;

        // When an infrared beam from the IR LED hits
        // the phototransistor, the InfraCollector port should
        // go above the IR_SENSOR_THRESHOLD value.
        if (SensorValue[InfraCollector] < IR_SENSOR_THRESHOLD)
        {
          // IR Light detected: Switch system state.
          currState = STATE1;
        }
        break;

      case(STATE1):

        // Light LED when in this state
         SensorValue(RedLED) = ON;

        // When the infrared beam from the IR LED
        // to the phototransistor is blocked, the InfraCollector port should
        // go below the IR_SENSOR_THRESHOLD value.
    	if (SensorValue(InfraCollector) > IR_SENSOR_THRESHOLD)
    	{
          // Switch system state.
          currState = STATE0;
    	}
    	break;

    	default: // We should never be in this state.

    } // switch(system_state)

  } // while(true)

}
