//Mestro
#define ENTRADA 1
#define SALIDA 5

void no_conexion(int n)
{

	if(!BluetoothStatus(n) == NO_ERR)
	{

		TextOut(5, LCD_LINE, "NO HAY ESCLAVO");
		Wait(2000);
		Stop(true);

	}

}

task main()
{

	int tacto;
	SetSensorTouch(S1);

	while(true)
	{

		no_conexion(1);
		tacto = Sensor(S1);

		if(tacto == 1)
		{

			SendRemoteNumber(ENTRADA, SALIDA, 3);

		}

		else
		{

			SendRemoteNumber(ENTRADA, SALIDA, 2);			

		}

		Wait(50);

	}

}
