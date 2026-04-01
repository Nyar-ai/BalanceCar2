#include "AnglePID.h"

typedef struct PID_Parameter
{
    int8_t KP=0;
    int8_t KI=0;
    int8_t KD=0;
    FORCE Max_force=100;
    FORCE Min_force=0;
}PID_Parameter;


PID_Parameter Parameter;
void AnglePID_config(PID_Parameter PIDconfigStruct){
    Parameter.KP=PIDconfigStruct.KP;
    Parameter.KI=PIDconfigStruct.KI;
    Parameter.KD=PIDconfigStruct.KD;
    Parameter.Max_force=PIDconfigStruct.Max_force;
    Parameter.Min_force=PIDconfigStruct.Min_force;
}
ANGLE error(ANGLE act_angle,ANGLE aim_angle){
    return aim_angle -act_angle;
}



FORCE AnglePID(ANGLE act_angle ,ANGLE aim_angle){
    ANGLE error = error(act_angle,aim_angle);
    static ANGLE Pererror=0;
    static ANGLE accumulate=0;
    if(Parameter.KI){
        accumulate+=error;
    }
    else{
        accumulate=0;
    }
    FORCE force_out =Parameter.KP*error+Parameter.KI*accumulate+Parameter.KD*(error-Pererror);
    if(force_out>Parameter.Max_force){
        force_out=Parameter.Max_force;

    }
    if(force_out<Parameter.Min_force){
        force_out=Parameter.Min_force;
    }
    return force_out;
    
    
}