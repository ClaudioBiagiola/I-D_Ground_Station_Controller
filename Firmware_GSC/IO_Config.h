/* 
 * File:   IO_Config.h
 * Author: Jere
 *
 * Created on 22 de marzo de 2021, 18:06
 */

#ifndef IO_CONFIG_H
#define	IO_CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif
    
/*==================== [Macros y Definiciones] ========================*/  
#define OUTPUT 0
#define INPUT 1
#define ANALOGIC 0
#define DIGITAL 1
/*========================================================================*/

/*===========================  Funciones   ==============================*/
void Config_CN_Pins(void);
void Config_IO(void);
void Define_IO_Pins(void);
void Remappeable_Pins(void);
void Change_Config_UART1(void);
void Set_Pin_As_A_or_D(void);
/*========================================================================*/

/************************       Info de Registros       ***********************
 - TRISx (READ/WRITE):
    Todos los pines de los puertos luego del reset son entradas.
 
    *  TRISx --> 1 Input
    *  TRISx --> 0 Output
 
 - PORTx (READ/WRITE):
    El dato en un pin (READ pin)n I/O es accedido via el registro PORTx. 
    Una lectura de el registro PORTx lee el valor en el pin I/O mientras que una escritura
    en el registro del PORTx escribe el valor en el cerrojo de datos del puerto.
 
 - LATx (READ/WRITE):
    El registro LATx associado con un pin I/O elimina el problema que puede ocurrir con
    las instricciones lectura-modoficaci�n-escritura
    Una lectura de el registro LATx devuelve el valor retenido en los cerrojos de los 
    puerto de salida en lugar de los valores en los pines I/O.
    La escritura con LATx tiene el mismo efecto que el PORTx

  Las diferencias entre los registros PORTx y LATx se pueden resumir de la siguiente manera:
    * Una escritura en el Registro PORTx escribe el valor de datos al cerrojo de puerto
    * Una escritura en el registro LATx escribe el valor de datos al cerrojo de puerto
    * Una lectura del Registro PORTx lee el valor de datos en el PIN de E / S
    * Una lectura del Registro LATx lee el valor de datos que se mantiene en el cerrojo del puerto
 
 - ODCx (WRITE ONLY):
    Cada PIN de puerto tambi�n se puede configurar individualmente para una salida digital o de drenaje abierto. 
    Esto est� controlado por el registro de control de drenaje abierto y ODCx que est� asociado con cada puerto. 
    La caracter�stica de drenaje abierto permite la generaci�n de salidas m�s alta que la VDD (por ejemplo, 5V) 
    en los pasadores de solo Dissired Digital, utilizando resistencias de pull-UP externas.

    El voltaje m�ximo de drenaje abierto permitido es el mismo que la especificaci�n VIH m�xima.
    La funci�n de salida de drenaje abierto se admite tanto para las configuraciones de puerto y perif�rico.

 - PERIPHERAL PIN SELECT (PPS)
    La funci�n de configuraci�n de PPS opera sobre un subconjunto fijo de pines de E / S digitales. Los usuarios pueden
    mapear de forma independiente la entrada y / o salida de la mayor�a de los perif�ricos digitales a cualquiera de estas E / S patas. 
    El PPS se realiza en software y generalmente no requiere que el dispositivo est� reprogramado. Se incluyen protecciones 
    de hardware para evitar cambios accidentales o falsos en el mapeo perif�rico una vez establecido.
 
    * Pines habilitados -> "RPx" x: N�mero de bit remapeable.
    * Los perif�ricos administrados por PPS son todos perif�ricos solo digitales:
        (UART y SPI), entradas de reloj con temporizador de uso general, perif�ricos relacionados con el temporizador
        (Captura de entrada y comparaci�n de salida) y entradas de interrupci�n al cambiar
 
    Existen 2 registros para controlar dichos pines:
 
       RPINRx  ->  Configura el pin remapeable como entrada
       RPORx   ->  Configura el pin remapeable como salida

 Todos los registros RPINRx se restablecen a todos los 1 y los registros RPORx se restablecen a 0, esto significa 
 que todas las entradas PPS est�n vinculadas a VSS, mientras que todas las salidas PPS est�n desconectadas
 En todos los casos, los perif�ricos seleccionables con pines no utilizados deben desactivarse por completo. 
 Los perif�ricos no utilizados deben tener sus entradas asignadas a una funci�n de pin RPn no utilizada.
 Los pines de E / S con funciones RPn no utilizadas deben configurado con la salida perif�rica nula.
 ************************************************************************/

#ifdef	__cplusplus
}
#endif

#endif	/* IO_CONFIG_H */

