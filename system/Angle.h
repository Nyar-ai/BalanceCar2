#ifndef __header__
#define __header__
#include <stdint.h>
typedef double ANGLE;
ANGLE Get_angle(uint32_t us); 
ANGLE Get_convert_Angle_to_360(ANGLE angle);
ANGLE Get_Accangle(int32_t AccX, int32_t AccZ); 
#endif // !__header__