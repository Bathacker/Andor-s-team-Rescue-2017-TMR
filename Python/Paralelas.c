#define SENSOR_LUZ1 IN_1
#define SENSOR_LUZ2 IN_2
#define SENSOR_ULTRA IN_3
#define SENSOR_TACTO IN_4

int luz1, luz2, ultra, tacto;

task programa()
{



}

task leer()
{



}

task main()
{
	
	SetSensorLight(SENSOR_LUZ1);
	SetSensorLight(SENSOR_LUZ2);
	SetSensorLowspeed(SENSOR_ULTRA);
	SetSensorTouch(SENSOR_TACTO);

	Precedes(programa, leer);

}