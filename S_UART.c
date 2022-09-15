#include "S_UART.h"

/**
 * @brief 不需要重定向的printf
 * 
 * @param uartbase 串口句柄地址
 * @param fmt 
 * @param ... 
 */
void UART_printf(UART_HandleTypeDef *uartbase, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	int length;
	char buffer[128];
	length = vsnprintf(buffer, 128, fmt, ap);
	HAL_UART_Transmit(uartbase, (uint8_t *)buffer, length, 0xffff);
}
