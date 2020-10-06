#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "inc/hw_ints.h"
#include "driverlib/interrupt.h"
int i;
void NgatGPIOB (void)
{ 
	int xx= GPIOPinRead(GPIO_PORTB_BASE,GPIO_PIN_4|GPIO_PIN_5);
	if((xx&GPIO_PIN_4)==0)
	{
    for(i=0;i<10;i++)
	   {
		   GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_1,0);
       SysCtlDelay(666666);
       GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_1,2);
       SysCtlDelay(666666);
	   }
	  GPIOPinIntClear(GPIO_PORTB_BASE,GPIO_PIN_4);
	}
	if((xx&GPIO_PIN_5)==0)
	{
    for(i=0;i<20;i++)
	   {
		   GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_2,0);
       SysCtlDelay(666666);
       GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_2,4);
       SysCtlDelay(666666);
	   }
	  GPIOPinIntClear(GPIO_PORTB_BASE,GPIO_PIN_5);
	}
}
int main(void)
{
	// Buoc 2:
	SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_USE_OSC|SYSCTL_XTAL_8MHZ|SYSCTL_OSC_MAIN);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	// Buoc 3:
	GPIOPinTypeGPIOInput(GPIO_PORTB_BASE,GPIO_PIN_4);
	GPIOPinTypeGPIOInput(GPIO_PORTB_BASE,GPIO_PIN_5);
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,GPIO_PIN_0);
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,GPIO_PIN_1);
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,GPIO_PIN_2);
	GPIOPadConfigSet(GPIO_PORTB_BASE,GPIO_PIN_4,GPIO_STRENGTH_4MA,GPIO_PIN_TYPE_STD_WPU);
	GPIOPadConfigSet(GPIO_PORTB_BASE,GPIO_PIN_5,GPIO_STRENGTH_4MA,GPIO_PIN_TYPE_STD_WPU);
	GPIOPinIntEnable(GPIO_PORTB_BASE,GPIO_PIN_4);
	GPIOPinIntEnable(GPIO_PORTB_BASE,GPIO_PIN_5);
	// Buoc 4:
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