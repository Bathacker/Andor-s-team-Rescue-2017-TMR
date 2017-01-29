//Esclavo
#define ENTRADA 5
#define SALIDA 1

void no_conexion(int n)
{

	if(!BluetoothStatus(n) == NO_ERR)
	{

		TextOut(5, LCD_LINE, "DONDE ESTA MI MAESTRO");
		Wait(2000);
		Stop(true);

	}

}

task main()
{

	int recibir;

	while(true)
	{

		no_conexion(0);
		
		if(ReceiveRemoteNumber(ENTRADA, true, recibir) != STAT_MSG_EMPTY_MAILBOX)
		{

			if(recibir == 3)
			{

				OnFwd(OUT_AB, 100);

			}

			if(recibir == 2)
			{

				Off(OUT_AB);

			}

		}
	
	}

}
