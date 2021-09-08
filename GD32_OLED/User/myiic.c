/*IIC连线：SCL -- PB0   SDA -- PB1*/
#include "myiic.h"
#include "systick.h"
#include "delay.h"

//初始化IIC
void IIC_Init(void)
{					     	
	rcu_periph_clock_enable(RCU_GPIOB);   
	gpio_mode_set(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_0|GPIO_PIN_1); 
	gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_0|GPIO_PIN_1); 			
}
//产生IIC起始信号
void IIC_Start(void)
{
	SET_IIC_SDA();	  	  
	SET_IIC_SCL();
 	CLR_IIC_SDA();//START:when CLK is high,DATA change form high to low 
	CLR_IIC_SCL();//钳住I2C总线，准备发送或接收数据 
}	  
//产生IIC停止信号
void IIC_Stop(void)
{
	SET_IIC_SCL(); 
	CLR_IIC_SDA();
	SET_IIC_SDA();//发送I2C总线结束信号						   	
}
//等待应答信号到来
//返回值：1，接收应答失败
//        0，接收应答成功
u8 IIC_Wait_Ack(void)
{
	SET_IIC_SCL();	
	CLR_IIC_SCL();//时钟输出0 	   
	return 0;  
} 
//产生ACK应答
void IIC_Ack(void)
{
	CLR_IIC_SCL();
	SDA_OUT();
	CLR_IIC_SDA();
	SET_IIC_SCL();
	CLR_IIC_SCL();
}
//不产生ACK应答		    
void IIC_NAck(void)
{
	CLR_IIC_SCL();
	SDA_OUT();
	SET_IIC_SDA();
	SET_IIC_SCL();
	CLR_IIC_SCL();
}					 				     
//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答			  
void IIC_Send_Byte(u8 txd)
{                        
    u8 t;    
    CLR_IIC_SCL();//拉低时钟开始数据传输
    for(t=1;t<=8;t++)
    {              
		if((txd&0x80)>>7)
			SET_IIC_SDA();
		else
			CLR_IIC_SDA();
        txd<<=1; 	  
		SET_IIC_SCL();
		CLR_IIC_SCL();	
    }	 
}
//读1个字节，ack=1时，发送ACK，ack=0，发送nACK   
u8 IIC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0x00;
	SDA_IN();//SDA设置为输入
    for(i=1;i<=8;i++ )
	 {
		CLR_IIC_SCL();
		SET_IIC_SCL();
    receive<<=1;
    if(READ_SDA)
		receive++;  
   }					 
    if (!ack)
        IIC_NAck();//发送nACK
    else
        IIC_Ack(); //发送ACK   
    return receive;
}


















