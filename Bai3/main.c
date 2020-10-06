#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "inc/hw_ints.h"
#include "driverlib/interrupt.h"
int i;
void NgatGPIOA (void)
{ 
	for(i=0;i<12;i++)
	{
		GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_1,0);
	  SysCtlDelay(666666);
	  GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_1,2);
	  SysCtlDelay(666666);
	}
	GPIOPinIntClear(GPIO_PORTA_BASE,GPIO_PIN_2);
}
void NgatGPIOB (void)
{ 
	for(i=0;i<10;i++)
	{
		GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_2,0);
	  SysCtlDelay(666666);
	  GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_2,4);
	  SysCtlDelay(666666);
	}
	GPIOPinIntClear(GPIO_PORTB_BASE,GPIO_PIN_5);
}
int main(void)
{
	// Buoc2:
	SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_USE_OSC|SYSCTL_XTAL_8MHZ|SYSCTL_OSC_MAIN);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	// Buoc3:
  GPIOPinTypeGPIOInput(GPIO_PORTA_BASE,GPIO_PIN_2);	
	GPIOPinTypeGPIOInput(GPIO_PORTB_BASE,GPIO_PIN_5);	
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,GPIO_PIN_0);
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,GPIO_PIN_1);
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,GPIO_PIN_2);
	GPIOPadConfigSet(GPIO_PORTA_BASE,GPIO_PIN_2,GPIO_STRENGTH_4MA,GPIO_PIN_TYPE_STD_WPU);
	GPIOPadConfigSet(GPIO_PORTB_BASE,GPIO_PIN_5,GPIO_STRENGTH_4MA,GPIO_PIN_TYPE_STD_WPU);
	GPIOPinIntEnable(GPIO_PORTA_BASE,GPIO_PIN_2);
	GPIOPinIntEnable(GPIO_PORTB_BASE,GPIO_PIN_5);
	// Buoc4
	IntEnable(INT_GPIOA);
	IntEnable(INT_GPIOB);
	IntMasterEnable();
while(1)
{
	GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_0,0);
	SysCtlDelay(1333333);
	GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_0,1);
	SysCtlDelay(1333333);
}
}