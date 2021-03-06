//CONSATNTES
#define SENSOR_LUZ1 IN_1
#define SENSOR_LUZ2 IN_2
#define SENSOR_ULTRA IN_3
//#define SENSOR_TACTO IN_4
#define SENSOR_COLOR IN_4
//........................
//VARIABLES
int luz1, luz2, ultra, color ;
//............

//FUNCIONES...............
void imprimirDatos(){
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
void colores(){
  //negro =1 blanco = 6 verde = 3
	SetSensorColorFull(S1);
	while(true){
	  ColorSensorReadType csr;
	  csr.Port = S1;
  	SysColorSensorRead(csr);
	  if(csr.Result == NO_ERR){
    TextOut(0, LCD_LINE6, "         ");
    TextOut(0, LCD_LINE6, "color:   ");
    NumOut(7*6, LCD_LINE6, csr.ColorValue);
	  }
	}
}
bool sensor1(int n){
	 if(luz1<n) return true;
	 else return false;
}

bool sensor2(int n){
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

int sensor4(){
    switch(color){
         case 1:
              return 2;
         break;
         case 3:
              return 3;
         break;
         case 6:
              return 1;
         break;
    }
}

void avanzar(int vel, int opc){
	 switch(opc){
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
     if(sensor4()) Off(OUT_AB);
     else OnFwd(OUT_AB,vel);
	 		break;
	 }

}
//TAREASPRINCIPALES.......
task programa(){
	 while(true){
		avanzar(45,4); //valores de las variables
	}
}
task leer(){
    while(true)
    {
		luz1=Sensor(SENSOR_LUZ1);
		luz2=Sensor(SENSOR_LUZ2);
		ultra=SensorUS(SENSOR_ULTRA);
		//tacto=Sensor(SENSOR_TACTO);
		color=Sensor(SENSOR_COLOR);
		imprimirDatos();
		colores();
     }
}
task main(){
	SetSensorLight(SENSOR_LUZ1);
	SetSensorLight(SENSOR_LUZ2);
	SetSensorLowspeed(SENSOR_ULTRA);
	//SetSensorTouch(SENSOR_TACTO);
	SetSensorColorFull(SENSOR_COLOR);
	Precedes(programa,leer);
}