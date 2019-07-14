#include "stm32f0xx_hal.h"
#include "lis3dh_driver.h"
//Acelerometro - vari�veis de dados e registradores
uint8_t  WhoAmI ;         /*vari�vel respons�vel por ler o registrador WHO_AM_I*/
uint8_t  OutXL  ;         /*vari�vel respons�vel por ler o registrador OUT_X_L*/
uint8_t  OutXH  ;         /*vari�vel respons�vel por ler o registrador OUT_X_H*/
uint8_t  OutYL  ;         /*vari�vel respons�vel por ler o registrador OUT_Y_L*/
uint8_t  OutYH  ;         /*vari�vel respons�vel por ler o registrador OUT_Y_H*/
uint8_t  OutZL  ;         /*vari�vel respons�vel por ler o registrador OUT_Z_L*/
uint8_t  OutZH  ;         /*vari�vel respons�vel por ler o registrador OUT_Z_H*/
uint8_t  StatusReg  ;     /*vari�vel respons�vel por ler o registrador STATUS_REG2*/
uint8_t  Ctrl_reg1;
uint8_t  Ctrl_reg2;
uint8_t  Ctrl_reg3;
uint8_t  Ctrl_reg4;
uint8_t  Ctrl_reg5;
uint8_t  Ctrl_reg6;
uint8_t Int1_dur;
uint8_t Int1_ths;
uint8_t Int1_cfg;
int16_t  MEMS_OutX  ;    /*vari�vel respons�vel por montar o dado do eixo X*/
int16_t  MEMS_OutY  ;    /*vari�vel respons�vel por montar o dado do eixo Y*/
int16_t  MEMS_OutZ  ;    /*vari�vel respons�vel por montar o dado do eixo Z*/
int16_t  MEMS_OutX_Ref  ;/*vari�vel respons�vel por ter a referencia de posicionamento X*/
int16_t  MEMS_OutY_Ref  ;/*vari�vel respons�vel por ter a referencia de posicionamento Y*/
int16_t  MEMS_OutZ_Ref  ;/*vari�vel respons�vel por ter a referencia de posicionamento Z*/
uint8_t  MEMS_data_ready ;/*vari�vel respons�vel por informar que os dados est�o prontas*/
uint8_t Int_counter,status_bit;
uint8_t StatusRegVar;
uint8_t StatusAUXVar;
AxesRaw_t leitura;
AxesRaw_t leitura_inicial;

uint16_t  Count_ms ;   				/*vari�vel respons�vel pelo delay*/
uint16_t  DataReady;   				  /*vari�vel respons�vel pela indica��o de ODReady*/
