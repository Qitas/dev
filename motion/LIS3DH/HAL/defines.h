#ifndef __DEFINES_H__
#define __DEFINES_H__ 

#include "main.h"
#include "const_var.h"

#define GRAVIDADE 4095

//Registradores do Acelerometro
#define STATUS_REG_AUX 			0x07
#define OUT_ADC1_L    			0x08
#define OUT_ADC1_H    			0x09
#define OUT_ADC2_L    			0x0A
#define OUT_ADC2_H    			0x0B
#define OUT_ADC3_L    			0x0C
#define OUT_ADC3_H    			0x0D
#define INT_COUNTER_REG   	0x0E
#define WHO_AM_I 						0x0F
#define TEMP_CFG_REG				0x1F
#define CTRL_REG1 					0x20
#define CTRL_REG2 					0x21
#define CTRL_REG3 					0x22
#define CTRL_REG4 					0x23
#define CTRL_REG5 					0x24
#define CTRL_REG6				 		0x25
#define REFERENCE 					0x26
#define STATUS_REG					0x27
#define OUTX_L 							0x28
#define OUTX_H 							0x29
#define OUTY_L 							0x2A
#define OUTY_H 							0x2B
#define OUTZ_L 							0x2C
#define OUTZ_H 							0x2D
#define FIFO_CTRL_REG				0x2E
#define FIFO_SRC_REG				0x2F
#define INT1_CFG 						0x30
#define INT1_SRC 						0x31
#define INT1_THS 						0x32
#define INT1_DUR 						0x33
#define INT2_CFG						0x34
#define INT2_SRC 						0x35
#define INT2_THS						0x36
#define INT2_DUR						0x37
#define CLICK_CFG 					0x38 
#define CLICK_SRC 					0x39 
#define CLICK_THS 					0x3A 
#define TIME_LIMIT 					0x3B 
#define TIME_LATENCY 				0x3C 
#define TIME_WINDOW 				0x3D
#define DUMMY_BYTE 					0xA5

#define N_READS							16
#define SHIF_N_READS				4


#define SPI_MISO     							GPIOC,GPIO_PIN_7
#define SPI_MOSI     							GPIOC,GPIO_PIN_6
#define SPI_SCK      							GPIOC,GPIO_PIN_5
#define CHIPSELECT  							GPIOE,GPIO_PIN_5
#define INTERRUPT1   							GPIOC,GPIO_PIN_2
#define INTERRUPT1_SENSIBILIDADE  EXTI_PORT_GPIOC,EXTI_SENSITIVITY_RISE_ONLY
#define INTERRUPT2   							GPIOD,GPIO_PIN_3
#define INTERRUPT2_SENSIBILIDADE 	EXTI_PORT_GPIOD,EXTI_SENSITIVITY_RISE_ONLY

//usado no controle.c para configurar os pinos das teclas
#define ABRE                GPIOB,GPIO_PIN_7
#define ABRE_SENSIBILIDADE  EXTI_PORT_GPIOB,EXTI_SENSITIVITY_FALL_LOW


// controle.c
void LIS3DH_Init(void);
void LIS3DH_INT1_ISR(void);
void LIS3DH_INT2_ISR(void);
uint8_t MEMS_SendByte( uint8_t byte );
uint8_t MEMS_Read( uint8_t reg );
void MEMS_Startup (void);
void MEMS_Posicao_Inicial(void);
uint16_t Modulo (int_least16_t var);
void pega_Dados(void);
void MEMS_LowPower(void);
void Delay_ms(uint16_t tempo);
void EntraLowPower(void);
void LIS3DH_LowPower(void);
void LIS3DH_ClickSetup(void);
void LIS3DH_6DSetup (void);
void Buttons_Init(void);
void Buttons_ISR (void);
float GetAngle (int_least16_t x1, int_least16_t y1 , int_least16_t z1, int_least16_t x2, int_least16_t y2 , int_least16_t z2);
#endif
