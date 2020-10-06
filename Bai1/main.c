#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "inc/hw_ints.h"
#include "driverlib/interrupt.h"
int i;
void NgatGPIOB(void)
{ for(i =0;i<10;i++)
	{
	 GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_1,0);
	 SysCtlDelay(666666);
	 GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_1,2);
	 SysCtlDelay(666666);
	}
	GPIOPinIntClear(GPIO_PORTB_BASE,GPIO_PIN_5);
}
int main(void)
{
	SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_USE_OSC|SYSCTL_XTAL_8MHZ|SYSCTL_OSC_MAIN);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	GPIOPinTypeGPIOInput(GPIO_PORTB_BASE,GPIO_PIN_5);
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,GPIO_PIN_0);
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,GPIO_PIN_1);
	GPIOPadConfigSet(GPIO_PORTB_BASE,GPIO_PIN_5,GPIO_STRENGTH_4MA,GPIO_PIN_TYPE_STD_WPU);
	GPIOPinIntEnable(GPIO_PORTB_BASE,GPIO_PIN_5);
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