
//	HAL_GPIO_WritePin(LED_D12_GPIO_Port,LED_D12_Pin,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(LED_D14_GPIO_Port,LED_D14_Pin,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(LED_D15_GPIO_Port,LED_D15_Pin,GPIO_PIN_SET);

//	Lcd_PortType ports[] = {LCD_D0_GPIO_Port, LCD_D1_GPIO_Port, LCD_D2_GPIO_Port, LCD_D3_GPIO_Port, LCD_D4_GPIO_Port, LCD_D5_GPIO_Port, LCD_D6_GPIO_Port, LCD_D7_GPIO_Port};
//	//Lcd_PortType ports[] = { GPIOC, GPIOB, GPIOA, GPIOA };
//	// Lcd_PinType pins[] = {D4_Pin, D5_Pin, D6_Pin, D7_Pin};
//	Lcd_PinType pins[] = {LCD_D0_Pin, LCD_D1_Pin, LCD_D2_Pin, LCD_D3_Pin, LCD_D4_Pin, LCD_D5_Pin, LCD_D6_Pin, LCD_D7_Pin};
//	Lcd_HandleTypeDef lcd;
//	// Lcd_create(ports, pins, RS_GPIO_Port, RS_Pin, EN_GPIO_Port, EN_Pin, LCD_4_BIT_MODE);
//	lcd = Lcd_create(ports, pins, LCD_RS_GPIO_Port, LCD_RS_Pin, LCD_E_GPIO_Port, LCD_E_Pin, LCD_8_BIT_MODE);
//	HAL_Delay (1000);
//	Lcd_cursor(&lcd, 0,1);
//	Lcd_string(&lcd, "Summer Lo");
//		for ( int x = 1; x <= 200 ; x++ )
//		{
//			Lcd_cursor(&lcd, 1,7);
//			Lcd_int(&lcd, x);
//			HAL_Delay (1000);
//		}

//	lcd16x2_init_8bits(LCD_RS_GPIO_Port, LCD_RS_Pin, LCD_E_GPIO_Port, LCD_E_Pin,
////D0_GPIO_Port, D0_Pin, D1_Pin, D2_Pin, D3_Pin,
//  LCD_D0_GPIO_Port, LCD_D0_Pin, LCD_D1_Pin, LCD_D2_Pin, LCD_D3_Pin,
//	LCD_D4_GPIO_Port, LCD_D4_Pin, LCD_D5_Pin, LCD_D6_Pin, LCD_D7_Pin);

//	lcd16x2_init_8bits(LCD_RS_GPIO_Port, LCD_RS_Pin, LCD_E_GPIO_Port, LCD_E_Pin,
//	//D0_GPIO_Port, D0_Pin, D1_Pin, D2_Pin, D3_Pin,
//	  GPIOE, GPIO_PIN_7, GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10,
//		GPIOE, GPIO_PIN_11, GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14);

//	lcd16x2_init_4bits(LCD_RS_GPIO_Port, LCD_RS_Pin, LCD_E_GPIO_Port, LCD_E_Pin,
//		  GPIOE, GPIO_PIN_11, GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14);
//	//		GPIOE, GPIO_PIN_7, GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10);

//  lcd16x2_printf("Hello World");
//  HAL_Delay(1000);


//		lcd16x2_1stLine();
//    lcd16x2_printf("Temperature 4bits");
//    HAL_Delay(1000);
//    lcd16x2_2ndLine();
//    lcd16x2_printf("%.2f C", 25.7824);
//    HAL_Delay(1000);
//    lcd16x2_clear();
//    HAL_Delay(500);