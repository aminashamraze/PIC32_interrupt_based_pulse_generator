
/* ************************************************************************** */

/* This included file provides access to the peripheral library functions and
   must be installed after the XC32 compiler. See
http://ww1.microchip.com/downloads/en/DeviceDoc/32bitPeripheralLibraryGuide.pdf
http://www.microchip.com/SWLibraryWeb/product.aspx?product=PIC32%20Peripheral%20Library
 */

// System included files
#include "hardware.h"
#include <plib.h>

// *****************************************************************************
/**
  @Function
    void hardware(void);

  @Summary
    Initializes PIC32 pins commonly used for IO on the Basys MX3 Trainer 
    processor board.

  @Description
    Initializes PIC32 digital IO pins to provide functionality for the 
    slide switches, push buttons, and LEDs

  @Parameters
    None

  @Returns
    None
***************************************************************************** */    
void Hardware_Setup(void)
{
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Statement configure cache, wait states and peripheral bus clock
 * Configure the device for maximum performance but does not change the PBDIV
 * Given the options, this function will change the flash wait states, RAM
 * wait state and enable prefetch cache but will not change the PBDIV.
 * The PBDIV value is already set via the pragma FPBDIV option above..
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    DDPCONbits.JTAGEN = 0;  // Statement is required to use Pin RA0 as IO
  
    ALL_DIGITAL_IO(); // Sets all LED, switches and push buttons for digital IO
    SET_MIC_ANALOG();       // Sets microphone input for analog
    SET_POT_ANALOG();       // Sets ANALOG INPUT CONTROL for analog input
    
    Set_All_LEDs_Output();	// Sets Basys MX3 LED0 through LED7 as output
    Set_All_LEDs_Off();		// Sets Basys MX3 LED0 through LED7 off
    SWcfg();                // Sets Basys MX3 SW0 through SW7 as input
    Set_All_PBs_Input();	// Sets Basys MX3 push buttons as input
	Set_RGB_Output();		// Sets Basys MX3 RGB LED as output
	Set_LED8_RGB(0);        // Sets Basys MX3 RGB LED off
	MCInit();
    
/* Enable multi-vector interrupts */
    INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);  /* Do only once */
    INTEnableInterrupts();   /*Do as needed for global interrupt control */
    
} /* End of Basys MX3A hardware configuration */

/* End of hardware.c */
