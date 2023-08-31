/*
 * mbedtls_entropy.c
 *
 *  Created on: 17 Jul 2018
 *      Author: Gordon.McNab
 */

#include <mbedtls/entropy_poll.h>
#include "net.h"
#include "registers/ft900_timer_wdt_registers.h"

int mbedtls_hardware_poll( void *data, unsigned char *output, size_t len, size_t *olen )
{
	static uint8_t last = 0;
	size_t i;
	uint16_t time;

	/* Initial entropy from MAC address */
	if (last == 0)
	{
		uint8_t *mac;
		mac = net_get_mac();
		for (i = 0; i < 6; i++)
		{
			last += *mac++;
		}
	}

	/* Add entropy from timer */
	timer_read(timer_select_a, &time);

	last ^= (time >> 8);
	last += (time & 0xff);

	/* Add passed in data to entropy */
    for (i = 0; i < len; i++)
    {
    	last += *(unsigned char *)data;
    	output[i] = last;
    }

    if(olen)
        *olen = len;
    return 0;
}

/*
int mbedtls_platform_std_nv_seed_read(char *buf, size_t len)
{
	char *test = "jumbled stuff 123";
#warning get/store in NVRAM
	//memcpy(buf, test, len);
	return 0;
}
*/
