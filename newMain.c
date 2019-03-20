#pragma config(Sensor, dgtl1,  encoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  floorOneButton, sensorTouch)
#pragma config(Sensor, dgtl7,  floorTwoButton, sensorTouch)
#pragma config(Sensor, dgtl8,  floorThreeButton, sensorTouch)
#pragma config(Sensor, dgtl10, light1,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl11, light2,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl12, light3,         sensorLEDtoVCC)
#pragma config(Motor,  port2,           driver,        tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int floorNumber;

void LIGHTS();

void SAFETY21();
void SAFETY31();

task main()
{
	floorNumber = 1;
	while(true)
	{
		while(floorNumber == 1)
		{
			if(SensorValue(floorOneButton) == 1)
			{
				turnLEDOn(light1);
				wait(1);
				wait(0.25);
				turnLEDOff(light1);
				wait(1);
				wait(0.25);
				turnLEDOn(light1);
				wait(1);
				wait(0.25);
				turnLEDOff(light1);
				wait(1);
				wait(0.25);
				turnLEDOn(light1);
			}
			if(SensorValue(floorTwoButton) == 1)
			{
				LIGHTS();
				turnLEDOn(light2);
				startMotor(driver, -63);
				untilEncoderCounts(-730,encoder);
				stopMotor(driver);
				floorNumber = 2;
				clearTimer(T1);
			}
			if(SensorValue(floorThreeButton) == 1)
			{
				LIGHTS();
				turnLEDOn(light3);
				startMotor(driver, -63);
				untilEncoderCounts(-1370,encoder);
				stopMotor(driver);
				floorNumber = 3;
				clearTimer(T1);
			}
		}


		while(floorNumber == 2)
		{
			if(SensorValue(floorTwoButton)== 1)
			{
				clearTimer(T1);
				turnLEDOn(light2);
				wait(1);
				wait(0.25);
				turnLEDOff(light2);
				wait(1);
				wait(0.25);
				turnLEDOn(light2);
				wait(1);
				wait(0.25);
				turnLEDOff(light2);
				wait(1);
				wait(0.25);
				turnLEDOn(light2);
			}
			if(SensorValue(floorOneButton) == 1)
			{
				LIGHTS();
				turnLEDOn(light1);
				startMotor(driver, 63);
				untilEncoderCounts(700,encoder);
				stopMotor(driver);
				floorNumber = 1;
				clearTimer(T1);
			}
			if(SensorValue(floorThreeButton) == 1)
			{
				LIGHTS();
				turnLEDOn(light3);
				startMotor(driver, -63);
				untilEncoderCounts(-730,encoder);
				stopMotor(driver);
				floorNumber = 3;
				clearTimer(T1);
			}
			if (time1[T1] > 5000)
			{
				SAFETY21();
			}
		}
		while(floorNumber == 3)
		{
			if(SensorValue(floorThreeButton)== 1)
			{
				clearTimer(T1);
				turnLEDOn(light3);
				wait(1);
				wait(0.25);
				turnLEDOff(light3);
				wait(1);
				wait(0.25);
				turnLEDOn(light3);
				wait(1);
				wait(0.25);
				turnLEDOff(light3);
				wait(1);
				wait(0.25);
				turnLEDOn(light3);
			}
			if(SensorValue(floorOneButton) == 1)
			{
				LIGHTS();
				turnLEDOn(light1);
				startMotor(driver, 63);
				untilEncoderCounts(1370,encoder);
				stopMotor(driver);
				floorNumber = 1;
				clearTimer(T1);
			}
			if(SensorValue(floorTwoButton) == 1)
			{
				LIGHTS();
				turnLEDOn(light2);
				startMotor(driver, 63);
				untilEncoderCounts(730,encoder);
				stopMotor(driver);
				floorNumber = 2;
				clearTimer(T1);

				if (time1[T1] > 5000)
				{
					SAFETY31();	
				}
			}
		}
	}
}


void LIGHTS()
{
	turnLEDOff(light1);
	turnLEDOff(light2);
	turnLEDOff(light3);
}

void SAFETY21()
{
	startMotor (driver, 63);
	untilEncoderCounts(730, encoder);
	stopMotor (driver);
	turnLEDOn(light1);
	floorNumber = 1;
	clearTimer(T1);
}

void SAFETY31()
{
	startMotor (driver, 63);
	untilEncoderCounts(1370, encoder);
	stopMotor (driver);
	turnLEDOn(light1);
	floorNumber = 1;
	clearTimer(T1);
}
