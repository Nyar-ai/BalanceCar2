#include "Angle.h"
#include <math.h>
#include <stdio.h>
ANGLE Get_convert_Angle_to_360(ANGLE angle) {
    if (angle < 0) {
        return angle + 360;
    }
    return angle;
}
ANGLE Get_Accangle(int32_t AccX, int32_t AccZ) {
	return Get_convert_Angle_to_360(atan2(AccX, AccZ)/ 3.1415926535 * 180);
}


ANGLE Get_angle(uint32_t us) {
		static ANGLE angle=180;
		static ANGLE perAccangle=180;
  ANGLE offset=-2;
		int16_t AX, AY, AZ, GX, GY, GZ;
	    MPU6050_GetData(&AX, &AY, &AZ, &GX, &GY, &GZ);
		ANGLE angleGy;
		ANGLE Accangle=Get_Accangle(AX,AZ);
		
        angleGy=angle-GY/32768.0 * 2000.0*0.02;
        angle =angleGy*0.99+(Accangle*0.8+perAccangle*0.2)*0.01;
		perAccangle=Accangle;
        return angle+offset;
}

