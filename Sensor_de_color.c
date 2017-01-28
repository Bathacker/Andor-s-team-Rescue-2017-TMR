task main()
{

	SetSensorColorFull(S1);
	ColorSensorReadType csr;

	csr.Port = S1;
	SysColorSensorRead(csr);
	if(csr.Result == NO_ERR)
	{

		NumOut(0, LCD_LINE1, csr.ColorValue);

	}
	//negro:1 blanco:6 verde:3
}