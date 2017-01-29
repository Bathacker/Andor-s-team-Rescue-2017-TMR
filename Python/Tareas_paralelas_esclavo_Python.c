//CONSATNTES
#define ENTRADA1 2
#define ENTRADA2 3
#define ENTRADA3 2
#define ENTRADA4 5
#define SALIDA 1
#define SENSOR_TACTO1 IN_1
#define SENSOR_TACTO2 IN_2
#define SENSOR_ULTRA2 IN_3
#define SENSOR_ULTRA3 IN_4

//........................
//VARIABLES
int luz1, luz2, ultra1, ultra2, ultra3, color, tacto1, tacto2;
//............

//FUNCIONES...............
void no_conexion(int num)
{

	if(!BluetoothStatus(num)== NO_ERR)
	{
	
		TextOut(5,LDEC_LINE2,"DONDE ESTA MI MAESTRO");
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

	TextOut(0,LCD_LINE2, "luz1:      ");
	TextOut(0,LCD_LINE3, "luz2:      ");
	TextOut(0,LCD_LINE4, "ultra1:      ");
	TextOut(0,LCD_LINE5, "color:      ");

	TextOut(0,LCD_LINE2, "tacto1:      ");
	TextOut(0,LCD_LINE3, "tacto2:      ");
	TextOut(0,LCD_LINE4, "ultra2:      ");
	TextOut(0,LCD_LINE5, "ultra3:      ");

	NumOut(7*6,LCD_LINE2,luz1);
	NumOut(7*6,LCD_LINE3,luz2);
	NumOut(7*6,LCD_LINE4,ultra1);
	NumOut(7*6,LCD_LINE5,color);

	NumOut(7*6,LCD_LINE2,tacto1);
	NumOut(7*6,LCD_LINE3,tacto2);
	NumOut(7*6,LCD_LINE4,ultra2);
	NumOut(7*6,LCD_LINE5,ultra3);

}

bool sensor1(int n)
{

	if(luz1 < n) return true;
	else return false;

}

bool sensor2(int n)
{

	if(luz2 < n) return true;
	else return false;

}

bool sensor3(int n)
{

	if(ultra1 < n) return true;
	else return false;

}

int sensor4()
{

    switch(color)
    {
    
        case 1:

            return 1;
        
        break;
        
        case 3:
        
            return 3;
        
        break;
        
        case 6:
        
            return 6;
        
        break;

    }

}

bool sensor5()
{

	if(tacto1 == 1) return true;
	else return false;

}

bool sensor6()
{

	if(tacto2 == 1) return true;
	else return false;

}

bool sensor7(int n)
{

	if(ultra2 < n) return true;
	else return false;

}

bool sensor8(int n)
{

	if(ultra3 < n) return true;
	else return false;

}

void avanzar(int vel, int opc)
{

	switch(opc)
	{
	 
		case 1:
	 	
	 		if(sensor1(45)) Off(OUT_AB);
	 		else OnFwd(OUT_AB,vel);
	 	
	 	break;
	 
	 	case 2:
	 	
	 		if(sensor2(45)) Off(OUT_AB);
	 		else OnFwd(OUT_AB,vel);
	 	
	 	break;
	 	
	 	case 3:
	 		
	 		if(sensor3(20)) Off(OUT_AB);
	 		else OnFwd(OUT_AB,vel);
    	
    	break;

	 	case 4:
     
     		switch(color)
    		{
    
		        case 1:

		            OnFwd(OUT_AB, vel);
		        
		        break;
		        
		        case 3:
		        
		            OnRev(OUT_AB, vel);
		        
		        break;
		        
		        case 6:
		        
		            Off(OUT_AB);
		        
		        break;

		
		    }
	 	
	 	break;

	 	case 5:

	 		if(sensor5()) Off(OUT_AB);
	 		else OnFwd(OUT_AB, vel);

	 	break;

	 	case 6:

	 		if(sensor6()) Off(OUT_AB);
	 		else OnFwd(OUT_AB, vel);

	 	break;

	 	case 7:
	 		
	 		if(sensor7(20)) Off(OUT_AB);
	 		else OnFwd(OUT_AB,vel);
    	
    	break;

    	case 8:
	 		
	 		if(sensor8(20)) Off(OUT_AB);
	 		else OnFwd(OUT_AB,vel);
    	
    	break;
	
	}

}
//TAREASPRINCIPALES.......
task programa()
{

	while(true)
	{
	
		avanzar(45,4); //valores de las variables
	
	}

}

task leer()
{

	while(true)
	{
	
		no_conexion(0);
		if(ReceiveRemoteNumber(ENTRADA1, true, luz1) != STAT_MSG_EMPTY_MAILBOX)
			ReceiveRemoteNumber(ENTRADA1, true, luz1);

		if(ReceiveRemoteNumber(ENTRADA2, true, luz2) != STAT_MSG_EMPTY_MAILBOX)
			ReceiveRemoteNumber(ENTRADA2, true, luz2);

		if(ReceiveRemoteNumber(ENTRADA3, true, ultra1) != STAT_MSG_EMPTY_MAILBOX)
			ReceiveRemoteNumber(ENTRADA3, true, ultra1);

		if(ReceiveRemoteNumber(ENTRADA4, true, color) != STAT_MSG_EMPTY_MAILBOX)
			ReceiveRemoteNumber(ENTRADA4, true, color);

		tacto1 = Sensor(S1);
		tacto2 = Sensor(S2);
		ultra2 = SensorUS(S3);
		ultra3 = SensorUS(S4);

    	imprimirDatos();

    }

}

task main()
{

	SetSensorTouch(SENSOR_TACTO1);
	SetSensorTouch(SENSOR_TACTO2);
	SetSensorLowSpeed(SENSOR_ULTRA2);
	SetSensorLowSpeed(SENSOR_ULTRA3);
	
}
