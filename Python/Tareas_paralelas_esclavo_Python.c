//CONSATNTES
#define ENTRADA 5
#define SALIDA 1
#define SENSOR_TACTO1 IN_1
#define SENSOR_TACTO2 IN_2
#define SENSOR_ULTRA2 IN_3
#define SENSOR_ULTRA3 IN_4

//........................
//VARIABLES
int luz1, luz2, ultra, ultra2, ultra3, color, tacto1, tacto2;
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
	TextOut(0,LCD_LINE4, "ultra:      ");
	//TextOut(0,LCD_LINE5, "tacto:      ");

	NumOut(7*6,LCD_LINE2,luz1);
	NumOut(7*6,LCD_LINE3,luz2);
	NumOut(7*6,LCD_LINE4,ultra);
	//NumOut(7*6,LCD_LINE5,tacto);

}

bool sensor1()
{

	if(luz1<n) return true;
	else return false;

}

bool sensor2(){
	 if(luz2<n) return true;
	 else return false;
}
bool sensor3(int n){
	 if(ultra<n) return true;
	 else return false;
}
/*
bool sensor4(){
	 if(tacto == 1) return true;
	 else return false;
} */

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
	
	}

}
//TAREASPRINCIPALES.......
task programa()
{

	 while(true){
		avanzar(45,4); //valores de las variables
	}

}

task leer()
{

	while(true)
	{
	
		no_conexion(0);
		if(ReceiveRemoteNumber(ENTRADA, true, luz1) != STAT_MSG_EMPTY_MAILBOX)
			ReceiveRemoteNumber(ENTRADA, true, luz1);
		if(ReceiveRemoteNumber(ENTRADA, true, luz2) != STAT_MSG_EMPTY_MAILBOX)
			ReceiveRemoteNumber(ENTRADA, true, luz2);
		if(ReceiveRemoteNumber(ENTRADA, true, ultra) != STAT_MSG_EMPTY_MAILBOX)
			ReceiveRemoteNumber(ENTRADA, true, ultra);
		if(ReceiveRemoteNumber(ENTRADA, true, color) != STAT_MSG_EMPTY_MAILBOX)
			ReceiveRemoteNumber(ENTRADA, true, color);
    	imprimirDatos();

    }

}

task main()
{

	SetSensorTouch(S1);
	
}
