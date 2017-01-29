//ESCLAVO
#define ENTRADA 5
#define SALIDA 1
void no_conexion(int num){
	if(!Bluetooth(num)== NO_ERR){
		TextOut((5,LDEC_LINE2,"DONDE ESTA EL MAESTRO"));
		Wait(2000);
		Stop(true);
	}
} 
task main(){
	int recibir ;
	while(true){
		no_conexion(0);
		if(ReciveRemoteNumber(ENTRADA, true, recibir)!= STAT_MSG_EMPTY_MAILBOX){
			if(recibir==3){
				OnFwd(OUT_AB,100);
			}
			if(recibir==2){
				Off(OUT_AB);
			}
		}
    }  
}