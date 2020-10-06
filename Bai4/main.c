#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "inc/hw_ints.h"
#include "driverlib/interrupt.h"
int i;
void NgatGPIOA (void)
{ 
	i++;
	if(i>3) i=1;
	GPIOPinIntClear(GPIO_PORTA_BASE,GPIO_PIN_2);
}
void NgatGPIOB (void)
{ 
	i=0;
	GPIOPinIntClear(GPIO_PORTB_BASE,GPIO_PIN_5);
}
int main(void)
{
	// Buoc 2:
	SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_USE_OSC|SYSCTL_XTAL_8MHZ|SYSCTL_OSC_MAIN);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	// Buoc 3:
	GPIOPinTypeGPIOInput(GPIO_PORTA_BASE,GPIO_PIN_2);
	GPIOPinTypeGPIOInput(GPIO_PORTB_BASE,GPIO_PIN_5);
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,GPIO_PIN_0);
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,GPIO_PIN_1);
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,GPIO_PIN_2);
	GPIOPadConfigSet(GPIO_PORTA_BASE,GPIO_PIN_2,GPIO_STRENGTH_4MA,GPIO_PIN_TYPE_STD_WPU);
	GPIOPadConfigSet(GPIO_PORTB_BASE,GPIO_PIN_5,GPIO_STRENGTH_4MA,GPIO_PIN_TYPE_STD_WPU);
	GPIOPinIntEnable(GPIO_PORTA_BASE,GPIO_PIN_2);
	GPIOPinIntEnable(GPIO_PORTB_BASE,GPIO_PIN_5);
	// Buoc 4:
	IntEnable(INT_GPIOA);
	IntEnable(INT_GPIOB);
	IntMasterEnable();
while(1)
{
	if(i==0)
	{
		GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_0,0);
		GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_1,0);
		GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_2,0);
	}
	else if( i==1)
	{
		GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_0,1);
		GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_1,0);
		GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_2,0);
	}
	else if(i==2)
	{
		GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_0,0);
		GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_1,2);
		GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_2,0);
	}
	else if(i==3)
	{
		GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_0,0);
		GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_1,0);
		GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_2,4);
	}
}
}