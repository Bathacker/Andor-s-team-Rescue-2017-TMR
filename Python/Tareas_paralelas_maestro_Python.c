//CONSATNTES
#define SENSOR_LUZ1 IN_1
#define SENSOR_LUZ2 IN_2
#define SENSOR_ULTRA IN_3
//#define SENSOR_TACTO IN_4
#define SENSOR_COLOR IN_4
#define ENTRADA 1
#define SALIDA1 2
#define SALIDA2 3
#define SALIDA3 4
#define SALIDA4 5
//........................
//VARIABLES
int luz1, luz2, ultra, color ;
//............

//FUNCIONES...............
void no_conexion(int num){
	if(!BluetoothStatus(num)== NO_ERR){
		TextOut(5,LDEC_LINE2,"NO HAY ESCLAVO");
		Wait(2000);
		Stop(true);
	}
}
void imprimirDatos()
{
	
	TextOut(0,LCD_LINE2, "      ");
	TextOut(0,LCD_LINE3, "      ");
	TextOut(0,LCD_LINE4, "      ");
	TextOut(0,LCD_LINE5, "      ");

	TextOut(0,LCD_LINE2, "tacto1:      ");
	TextOut(0,LCD_LINE3, "tacto2:      ");
	TextOut(0,LCD_LINE4, "ultra2:      ");
	TextOut(0,LCD_LINE5, "ultra3:      ");

	NumOut(7*6,LCD_LINE2,tacto1);
	NumOut(7*6,LCD_LINE3,tacto2);
	NumOut(7*6,LCD_LINE4,ultra2);
	NumOut(7*6,LCD_LINE5,ultra3);

	no_conexion(1);
	
	SendRemoteNumber(ENTRADA, SALIDA1, luz1);
	SendRemoteNumber(ENTRADA, SALIDA2, luz2);
	SendRemoteNumber(ENTRADA, SALIDA3, ultra);
	while(true)
	{
	  	
	  	ColorSensorReadType csr;
	  	csr.Port = S1;
  		SysColorSensorRead(csr);
	  	
	  	if(csr.Result == NO_ERR)
	  	{
    	
    		SendRemoteNumber(ENTRADA, SALIDA4, color);
	  	
	  	}
	
	}

	Wait(50);

}
/*
bool sensor1(int n)
{

	if(luz1 < n)
	{
	 
		SendRemoteNumber(ENTRADA, SALIDA, true);
		return true;
	 
	}

	else 
	{

		SendRemoteNumber(ENTRADA, SALIDA, false);
		return false;
	
	}

}

bool sensor2(int n)
{

	if(luz2 < n)
	{
	
		SendRemoteNumber(ENTRADA, SALIDA, true);
		return true;
	
	}

	else
	{
	
		SendRemoteNumber(ENTRADA, SALIDA, false);
		return false;

	}

}

bool sensor3(int n)
{
	
	if(ultra < n)
	{
	
		SendRemoteNumber(ENTRADA, SALIDA, true);
		return true;
	
	}

	else
	{
	
		SendRemoteNumber(ENTRADA, SALIDA, false);
		return false;

	}
}

int sensor4()
{

    switch(color)
    {
    
        case 1:

            SendRemoteNumber(ENTRADA, SALIDA, 2);
            return 2;
        
        break;
        
        case 3:
        
            SendRemoteNumber(ENTRADA, SALIDA, 3);
            return 3;
        
        break;
        
        case 6:
        
        	SendRemoteNumber(ENTRADA, SALIDA, 1);
            return 1;
        
        break;
    
    }

}

void avanzar(int vel, int opc){
	 switch(opc){
	 	case 1:
	 	
	 		if(sensor1(45)) SendRemoteNumber(ENTRADA, SALIDA, 1);
	 		else SendRemoteNumber(ENTRADA, SALIDA, 0);
	 	
	 		break;
	 	
	 	case 2:
	 	
	 		if(sensor2(45)) SendRemoteNumber(ENTRADA, SALIDA, 1);
	 		else SendRemoteNumber(ENTRADA, SALIDA, 0);
	 	
	 		break;
	 	
	 	case 3:
	 		
	 		if(sensor3(20)) SendRemoteNumber(ENTRADA, SALIDA, 1);
	 		else SendRemoteNumber(ENTRADA, SALIDA, 0)
      		
      		break;

	 	case 4:

     		if(sensor4()) SendRemoteNumber(ENTRADA, SALIDA, 1)
     		else SendRemoteNumber(ENTRADA, SALIDA, 0);
	
	 		break;
	
	}

}

//TAREAS PRINCIPALES.......
task programa()
{

	while(true)
	{
	
		avanzar(45,4); //valores de las variables
	
	}

}*/
task leer()
{
    
    while(true)
    {
	
		luz1 = Sensor(SENSOR_LUZ1);
		luz2 = Sensor(SENSOR_LUZ2);
		ultra = SensorUS(SENSOR_ULTRA);
		color = Sensor(SENSOR_COLOR);
		imprimirDatos();
    
    }
}

task main()
{

	SetSensorLight(SENSOR_LUZ1);
	SetSensorLight(SENSOR_LUZ2);
	SetSensorLowspeed(SENSOR_ULTRA);
	//SetSensorTouch(SENSOR_TACTO);
	SetSensorColorFull(SENSOR_COLOR);
	Precedes(programa,leer);

}
