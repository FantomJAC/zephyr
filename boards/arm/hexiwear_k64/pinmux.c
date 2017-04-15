/*
 * Copyright (c) 2016 Freescale Semiconductor, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <init.h>
#include <pinmux.h>
#include <fsl_port.h>

static int hexiwear_k64_pinmux_init(struct device *dev)
{
	ARG_UNUSED(dev);

#ifdef CONFIG_PINMUX_MCUX_PORTA
	struct device *porta =
		device_get_binding(CONFIG_PINMUX_MCUX_PORTA_NAME);
#endif
#ifdef CONFIG_PINMUX_MCUX_PORTB
	struct device *portb =
		device_get_binding(CONFIG_PINMUX_MCUX_PORTB_NAME);
#endif
#ifdef CONFIG_PINMUX_MCUX_PORTC
	struct device *portc =
		device_get_binding(CONFIG_PINMUX_MCUX_PORTC_NAME);
#endif
#ifdef CONFIG_PINMUX_MCUX_PORTD
	struct device *portd =
		device_get_binding(CONFIG_PINMUX_MCUX_PORTD_NAME);
#endif
#ifdef CONFIG_PINMUX_MCUX_PORTE
	struct device *porte =
		device_get_binding(CONFIG_PINMUX_MCUX_PORTE_NAME);
#endif

	/* Power mgmt */
	/* BAT_SENS_EN: ZERO - Enable, Hi-Z - Disable */
	pinmux_pin_set(portc,  4, PORT_PCR_MUX(kPORT_MuxAsGpio)
					| PORT_PCR_ODE_MASK);
	/* CHG_STATE */
	pinmux_pin_set(portc, 12, PORT_PCR_MUX(kPORT_MuxAsGpio));
	/* LDO_EN: ONE - Enable, ZERO - Disable  */
	pinmux_pin_set(porta, 29, PORT_PCR_MUX(kPORT_MuxAsGpio));
	/* BOOST_EN: ONE - Enable, ZERO - Disable */
	pinmux_pin_set(portc, 13, PORT_PCR_MUX(kPORT_MuxAsGpio));
	/* 3V3B_EN: ZERO - Enable, Hi-Z - Disable  */
	pinmux_pin_set(portb, 12, PORT_PCR_MUX(kPORT_MuxAsGpio)
					| PORT_PCR_ODE_MASK);

	/* Red, green, blue LEDs */
	pinmux_pin_set(portc,  8, PORT_PCR_MUX(kPORT_MuxAsGpio));
	pinmux_pin_set(portc,  9, PORT_PCR_MUX(kPORT_MuxAsGpio));
	pinmux_pin_set(portd,  0, PORT_PCR_MUX(kPORT_MuxAsGpio));

	/* Vibration Motor */
	pinmux_pin_set(portb,  9, PORT_PCR_MUX(kPORT_MuxAsGpio));

#ifdef CONFIG_SPI_0
	/* SPI0 CS2, CS1, CS0, SCK, SOUT, SIN - ext SPI */
	pinmux_pin_set(portc,  2, PORT_PCR_MUX(kPORT_MuxAlt2));
	pinmux_pin_set(portc,  3, PORT_PCR_MUX(kPORT_MuxAlt2));
	pinmux_pin_set(portc,  4, PORT_PCR_MUX(kPORT_MuxAlt2));
	pinmux_pin_set(portc,  5, PORT_PCR_MUX(kPORT_MuxAlt2));
	pinmux_pin_set(portc,  6, PORT_PCR_MUX(kPORT_MuxAlt2));
	pinmux_pin_set(portc,  7, PORT_PCR_MUX(kPORT_MuxAlt2));
#endif

#ifdef CONFIG_SPI_1
	/* SPI1 CS0, SCK, SOUT, SIN - Flash/BLE */
	pinmux_pin_set(portd,  4, PORT_PCR_MUX(kPORT_MuxAlt7));
	pinmux_pin_set(portd,  5, PORT_PCR_MUX(kPORT_MuxAlt7));
	pinmux_pin_set(portd,  6, PORT_PCR_MUX(kPORT_MuxAlt7));
	pinmux_pin_set(portd,  7, PORT_PCR_MUX(kPORT_MuxAlt7));
#endif
	/* BLE Misc - PB18, BLE_RST, BLE_WKP */
	pinmux_pin_set(porte, 26, PORT_PCR_MUX(kPORT_MuxAsGpio));
	pinmux_pin_set(portb, 23, PORT_PCR_MUX(kPORT_MuxAsGpio));
	pinmux_pin_set(portd, 14, PORT_PCR_MUX(kPORT_MuxAsGpio));

#ifdef CONFIG_SPI_2
	/* SPI2 CS0, SCK, SOUT - ssd1351 */
	pinmux_pin_set(portb, 20, PORT_PCR_MUX(kPORT_MuxAlt2));
	pinmux_pin_set(portb, 21, PORT_PCR_MUX(kPORT_MuxAlt2));
	pinmux_pin_set(portb, 22, PORT_PCR_MUX(kPORT_MuxAlt2));
#endif
	/* PTD15, PTE6 - ssd1351 control */
	pinmux_pin_set(portd, 15, PORT_PCR_MUX(kPORT_MuxAsGpio));
	pinmux_pin_set(porte,  6, PORT_PCR_MUX(kPORT_MuxAsGpio));

#ifdef CONFIG_I2C_0
	/* I2C0 SCL,SDA - AmbiLight, Humid & Temp */
	pinmux_pin_set(portb,  0, PORT_PCR_MUX(kPORT_MuxAlt2)
					| PORT_PCR_ODE_MASK);
	pinmux_pin_set(portb,  1, PORT_PCR_MUX(kPORT_MuxAlt2)
					| PORT_PCR_ODE_MASK);
#endif
	/* TSL2561 INT */
	pinmux_pin_set(portc,  0, PORT_PCR_MUX(kPORT_MuxAsGpio));
	/* MAX30101 INT */
	pinmux_pin_set(portb, 18, PORT_PCR_MUX(kPORT_MuxAsGpio));

#ifdef CONFIG_I2C_1
	/* I2C1 SCL, SDA - accel/mag, gyro, pressure */
	pinmux_pin_set(portc, 10, PORT_PCR_MUX(kPORT_MuxAlt2)
					| PORT_PCR_ODE_MASK);
	pinmux_pin_set(portc, 11, PORT_PCR_MUX(kPORT_MuxAlt2)
					| PORT_PCR_ODE_MASK);
#endif
	/* FXOS8700 RST, INT1, INT2 */
	pinmux_pin_set(portd, 11, PORT_PCR_MUX(kPORT_MuxAsGpio));
	pinmux_pin_set(portc,  1, PORT_PCR_MUX(kPORT_MuxAsGpio));
	pinmux_pin_set(portd, 13, PORT_PCR_MUX(kPORT_MuxAsGpio));
	/* FXA21002C RST, INT1, INT2 */
	pinmux_pin_set(portc, 15, PORT_PCR_MUX(kPORT_MuxAsGpio));
	pinmux_pin_set(portd,  1, PORT_PCR_MUX(kPORT_MuxAsGpio));
	pinmux_pin_set(portc, 18, PORT_PCR_MUX(kPORT_MuxAsGpio));
	/* MPL3115A2 INT1, INT2 */
	pinmux_pin_set(portd, 12, PORT_PCR_MUX(kPORT_MuxAsGpio));
	pinmux_pin_set(portd, 10, PORT_PCR_MUX(kPORT_MuxAsGpio));

#ifdef CONFIG_UART_MCUX_0
	/* UART0 RX, TX */
	pinmux_pin_set(portb, 16, PORT_PCR_MUX(kPORT_MuxAlt3));
	pinmux_pin_set(portb, 17, PORT_PCR_MUX(kPORT_MuxAlt3));
#endif

#ifdef CONFIG_UART_MCUX_2
	/* UART2 RX, TX */
	pinmux_pin_set(portd,  2, PORT_PCR_MUX(kPORT_MuxAlt3));
	pinmux_pin_set(portd,  3, PORT_PCR_MUX(kPORT_MuxAlt3));
#endif

#ifdef CONFIG_UART_MCUX_3
	/* UART3 RX, TX */
	pinmux_pin_set(portc, 16, PORT_PCR_MUX(kPORT_MuxAlt3));
	pinmux_pin_set(portc, 17, PORT_PCR_MUX(kPORT_MuxAlt3));
#endif

#ifdef CONFIG_UART_MCUX_4
	/* UART4 RX, TX - BLE */
	pinmux_pin_set(porte, 24, PORT_PCR_MUX(kPORT_MuxAlt3));
	pinmux_pin_set(porte, 25, PORT_PCR_MUX(kPORT_MuxAlt3));
#endif

	/* TODO: SDHC */
	/* TODO: I2S */

	return 0;
}

SYS_INIT(hexiwear_k64_pinmux_init, PRE_KERNEL_1, CONFIG_PINMUX_INIT_PRIORITY);
