/**
	************************************************************
	*	�ļ����� 	adxl345.c
	*	���ߣ� 		QITAS
	*	���ڣ� 		2018-10-23
	*	�汾�� 		V0.1
	*	˵���� 		ADXL345��ʼ������ȡ�������ֵ
	************************************************************
**/

//��Ƭ��ͷ�ļ�
#include "stm32f10x.h"

//Ӳ������
#include "adxl345.h"
#include "i2c.h"
#include "delay.h"
#include <stdio.h>


ADXL345_INFO adxlInfo;



/*
************************************************************
*	�������ƣ�	ADXL345_Init
*
*	�������ܣ�	ADXL345��ʼ������
*
*	��ڲ�����	��
*
*	���ز�����	��
*
*	˵����		
************************************************************
*/
void ADXL345_Init(void)
{
	
    unsigned char devid = 0, val = 0;

    uDelay(300);

    I2C_ReadByte(ADXL345_ADDRESS, 0x00, &devid);			//��ID	��ÿ�ζ�д֮ǰ����Ҫ��ID
	uDelay(300);

	val = 0x2B;
    I2C_WriteByte(ADXL345_ADDRESS, DATA_FORMAT_REG, &val);	//�͵�ƽ�ж����,13λȫ�ֱ���,��������Ҷ���,16g����
	uDelay(50);
    
	val = 0x0A;
    I2C_WriteByte(ADXL345_ADDRESS, BW_RATE, &val);			//��������ٶ�Ϊ100Hz
	uDelay(50);
    
	val = 0x28;
    I2C_WriteByte(ADXL345_ADDRESS, POWER_CTL, &val);		//����ʹ��,����ģʽ
	uDelay(50);
    
	val = 0;
    I2C_WriteByte(ADXL345_ADDRESS, INT_ENABLE, &val);		//��ʹ���ж�
	uDelay(50);
    
    I2C_WriteByte(ADXL345_ADDRESS, OFSX, &val);				//X��ƫ��0
	uDelay(50);
    
    I2C_WriteByte(ADXL345_ADDRESS, OFSY, &val);				//Y��ƫ��0
	uDelay(50);
    
    I2C_WriteByte(ADXL345_ADDRESS, OFSZ, &val);				//Z��ƫ��0
	
    uDelay(500);

}

/*
************************************************************
*	�������ƣ�	ADXL345_GetValue
*
*	�������ܣ�	��ȡADXL345���������ֵ
*
*	��ڲ�����	��
*
*	���ز�����	��
*
*	˵����		��������adxl345�ṹ����
************************************************************
*/
void ADXL345_GetValue(void)
{

	unsigned char devid = 0;
	
	unsigned char dataTemp[6];
	
	IIC_SpeedCtl(5);													//����IIC�ٶ�

    uDelay(200);
    I2C_ReadByte(ADXL345_ADDRESS, 0x00, &devid);						//��ID	��ÿ�ζ�д֮ǰ����Ҫ��ID
	uDelay(200);
	
	I2C_ReadBytes(ADXL345_ADDRESS, 0x32, dataTemp, 6);					//��ȡԭʼ����ֵ(4mg/LSB)
	
	adxlInfo.incidence_X = (short)(dataTemp[0] + ((unsigned short)dataTemp[1] << 8));
    adxlInfo.incidence_Y = (short)(dataTemp[2] + ((unsigned short)dataTemp[3] << 8));
    adxlInfo.incidence_Z = (short)(dataTemp[4] + ((unsigned short)dataTemp[5] << 8));
	
	adxlInfo.incidence_Xf = (float)adxlInfo.incidence_X * 0.0039;		//����Ϊg
	adxlInfo.incidence_Yf = (float)adxlInfo.incidence_Y * 0.0039;		//ÿһ��LSB����3.9mg
	adxlInfo.incidence_Zf = (float)adxlInfo.incidence_Z * 0.0039;		//�ж��ٸ�LSB���ͳ���0.0039g�͵õ�����gΪ��λ�ļ���ֵ
	
	
	//printf(" ADX345-X is : %f g\r\n",adxlInfo.incidence_Xf);
	//printf(" ADX345-Y is : %f g\r\n",adxlInfo.incidence_Yf);
	//printf(" ADX345-Z is : %f g\r\n",adxlInfo.incidence_Zf);	

}