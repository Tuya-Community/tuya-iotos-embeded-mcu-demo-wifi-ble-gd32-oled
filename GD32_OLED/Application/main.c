#include "gd32e23x.h"
#include "systick.h"
#include "stdio.h"
#include "led.h"
#include "delay.h"
#include "usart.h"
#include "wifi.h"
#include "delay.h"
#include "oled.h"
#include "myiic.h"

uint32_t USART0_RECEIVE_Buf[100]; 
uint32_t USART1_RECEIVE_Buf[100]; 
extern void Connect_Wifi(void);
extern unsigned int gtime[7];

void OLED_Display(void)		 
{	
		gtime[0]=gtime[0]+2000;
		OLED_ShowString(65, 0, "-",16);	
		OLED_ShowString(90, 0, "-",16);
		OLED_ShowCHinese(0, 0, 6);  //��
		OLED_ShowCHinese(16, 0, 7); //��
		OLED_ShowCHinese(0, 2, 4);  //ʱ
		OLED_ShowCHinese(16, 2, 5); //��
		OLED_ShowString(46, 2, ":",16); 
		OLED_ShowString(68, 2, ":",16); 
		//oled��ʾ����
		OLED_ShowNum(32,0,gtime[0],4,16);
		OLED_ShowNum(73,0,gtime[1],2,16); 
		OLED_ShowNum(100,0,gtime[2],2,16); 
		//oled��ʾʱ��
		OLED_ShowNum(30,2,gtime[3],2,16); //ʱ
		OLED_ShowNum(52,2,gtime[4],2,16); //��
		OLED_ShowNum(76,2,gtime[5],2,16); //��
//		switch(gtime[6])
//		{
//			case 0:

//				OLED_ShowString(32,4,"Sunday",16);
//				break;
//			case 1:

//			  OLED_ShowString(32,4,"Monday",16);
//				break;
//			case 2:

//				OLED_ShowString(32,4,"Tuesday",16);
//			
//				break;
//			case 3:

//				OLED_ShowString(32,4,"Wednesday",16);
//				break;
//			case 4:

//				OLED_ShowString(32,4,"Thursday",16);
//				break;
//			case 5:

//				OLED_ShowString(32,4,"Friday",16);
//				break;
//			case 6:

//				OLED_ShowString(32,4,"Saturday",16);
//				break;  
//		}
	  Delay_ms(1000);
}
int main(void)
{
    u8 t,i;
	  systick_config();   
		LED_Init();  
	  wifi_protocol_init();//wifiЭ���ʼ��
		USART0_Init();
		USART1_Init();
	  IIC_Init();		
    OLED_Init();	
	  t=' ';
	  OLED_Clear();
		OLED_ShowCHinese(4,1,0); //��
		OLED_ShowCHinese(22,1,1);//ӭ
		OLED_ShowCHinese(40,1,2);//��
		OLED_ShowCHinese(58,1,3);//��
		OLED_ShowCHinese(76,1,4);//ʱ
		OLED_ShowCHinese(94,1,5);//��
	  Delay_ms(1000);
	  OLED_Clear();
 while(1)
 {
	   
			Connect_Wifi(); //����
			wifi_uart_service();//wifi�������ݴ������
		  //mcu_get_green_time();
		  mcu_get_system_time();
		  OLED_Display();
 }
}
	