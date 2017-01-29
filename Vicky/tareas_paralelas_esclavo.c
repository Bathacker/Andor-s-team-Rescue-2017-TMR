//CONSATNTES
#define ENTRADA 5
#define SALIDA 1
//........................
//VARIABLES
int luz1, luz2, ultra, color ;
//............

//FUNCIONES...............
void no_conexion(int num){
	if(!BluetoothStatus(num)== NO_ERR){
		TextOut(5,LDEC_LINE2,"DONDE ESTA MI MAESTRO");
		Wait(2000);
		Stop(true);
	}
}
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

bool sensor1(int n){
	
}

bool sensor2(int n){
	 
}
bool sensor3(int n){
	 
}
/*
bool sensor4(){
	 if(tacto == 1) return true;
	 else return false;
} */

int sensor4(){
    
}

void avanzar(int vel, int opc){
	

}
//TAREASPRINCIPALES.......
task programa(){
	 
}
task leer(){
    
}
task main(){
	
}
