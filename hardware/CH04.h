#ifndef __CH04_SERIAL_H
#define __CH04_SERIAL_H

#include <stdio.h>

extern char CH04_RxPacket[];
extern uint8_t CH04_RxFlag;

void CH04_Serial_Init(void);
void CH04_Serial_SendByte(uint8_t Byte);
void CH04_Serial_SendArray(uint8_t *Array, uint16_t Length);
void CH04_Serial_SendString(char *String);
void CH04_Serial_SendNumber(uint32_t Number, uint8_t Length);
void CH04_Serial_Printf(char *format, ...);

#endif