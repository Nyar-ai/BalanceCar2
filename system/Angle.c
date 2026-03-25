#include "Angle.h"
#include <math.h>
#include <stdio.h>
void  Change_Gyangle(ANGLE Angular_velocity, uint32_t us, ANGLE* Gyangle) {

	*Gyangle = *Gyangle+ Angular_velocity/32768.0 * 2000.0  * us / 1000000;
}
ANGLE Get_Accangle(int32_t AccX, int32_t AccZ) {
	return Get_convert_Angle_to_360(atan2(AccX, AccZ)/ 3.1415926535 * 180);
}


ANGLE Get_angle(uint32_t us) {
		static ANGLE angle=180;
		ANGLE angleGy;
		int16_t AX, AY, AZ, GX, GY, GZ;
	    MPU6050_GetData(&AX, &AY, &AZ, &GX, &GY, &GZ);
        angleGy=angle-GY/32768.0 * 2000.0*0.02;
        angle =angleGy*0.99+Get_Accangle(AX,AZ)*0.01;
        return angle-2;
}
ANGLE Get_convert_Angle_to_360(ANGLE angle) {
    if (angle < 0) {
        return angle + 360;
    }
    return angle;
}
