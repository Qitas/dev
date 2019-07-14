
//Acelerometro - vari�veis de dados e registradores
extern uint8_t  WhoAmI ;         /*vari�vel respons�vel por ler o registrador WHO_AM_I*/
extern uint8_t  OutXL  ;         /*vari�vel respons�vel por ler o registrador OUT_X_L*/
extern uint8_t  OutXH  ;         /*vari�vel respons�vel por ler o registrador OUT_X_H*/
extern uint8_t  OutYL  ;         /*vari�vel respons�vel por ler o registrador OUT_Y_L*/
extern uint8_t  OutYH  ;         /*vari�vel respons�vel por ler o registrador OUT_Y_H*/
extern uint8_t  OutZL  ;         /*vari�vel respons�vel por ler o registrador OUT_Z_L*/
extern uint8_t  OutZH  ;         /*vari�vel respons�vel por ler o registrador OUT_Z_H*/
extern uint8_t  StatusReg  ;     /*vari�vel respons�vel por ler o registrador STATUS_REG2*/
extern uint8_t  Ctrl_reg1;
extern uint8_t  Ctrl_reg2;
extern uint8_t  Ctrl_reg3;
extern uint8_t  Ctrl_reg4;
extern uint8_t  Ctrl_reg5;
extern uint8_t  Ctrl_reg6;
extern uint8_t Int1_dur;
extern uint8_t Int1_ths;
extern uint8_t Int1_cfg;
extern int16_t  MEMS_OutX  ;    /*vari�vel respons�vel por montar o dado do eixo X*/
extern int16_t  MEMS_OutY  ;    /*vari�vel respons�vel por montar o dado do eixo Y*/
extern int16_t  MEMS_OutZ  ;    /*vari�vel respons�vel por montar o dado do eixo Z*/
extern int16_t  MEMS_OutX_Ref  ;/*vari�vel respons�vel por ter a referencia de posicionamento X*/
extern int16_t  MEMS_OutY_Ref  ;/*vari�vel respons�vel por ter a referencia de posicionamento Y*/
extern int16_t  MEMS_OutZ_Ref  ;/*vari�vel respons�vel por ter a referencia de posicionamento Z*/
extern uint8_t  MEMS_data_ready ;    /*vari�vel respons�vel por informar que os dados est�o prontas*/


extern uint16_t  Count_ms ;   				/*vari�vel respons�vel pelo delay*/
extern uint16_t  DataReady ;   				  /*vari�vel respons�vel pela indica��o de ODReady*/

