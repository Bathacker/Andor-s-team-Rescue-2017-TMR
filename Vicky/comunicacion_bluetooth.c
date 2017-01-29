//Maestro 
#define ENTRADA1
#define SALIDA5
void no_conexion(int num){
	if(!BluetoothStatus(num)== NO_ERR){
		TextOut(5,LDEC_LINE2,"NO HAY ESCLAVO");
		Wait(2000);
		Stop(true);
	}

}

task main(){
	int tacto=0;
	SetSensorTouch(S1);
	while(true){
		no_conexion(1);
		tacto=Sensor(S1);
		if(tacto == 1){
			SendRemoteNumber(ENTRADA, SALIDA, 3);	
		}
		else{
			SendRemoteNumber(ENTRADA, SALIDA, 2);
		}
	}
}
