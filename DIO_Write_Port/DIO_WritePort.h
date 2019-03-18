/*Created on: Mar 16, 2019
 * Martina
 */
# include "stdint.h"
# include "tm4c123gh6pm.h"
# include "std_types.h"
# include "arm_config.h"
# include "common macros.h"
void DIO_WritePort (uint8 port_index, uint8 pins_mask,enum Dio_LevelType pins_level);