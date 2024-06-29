/*
 * ext_ota.h
 *
 *  Created on: 12.03.2023
 *      Author: pvvx
 */

#ifndef EXT_OTA_H_
#define EXT_OTA_H_

#include "app_config.h"

#define ID_BOOTABLE 0x544c4e4b

#if ZIGBEE_TUYA_OTA
void tuya_zigbee_ota(void);
#else
void big_to_low_ota(void);
#endif

#if defined(MI_HW_VER_FADDR) && (MI_HW_VER_FADDR)
uint32_t get_mi_hw_version(void);
void set_SerialStr(void);
#endif


#if (DEV_SERVICES & SERVICE_OTA_EXT)  // Compatible BigOTA

// Ext.OTA return code
enum {
	EXT_OTA_OK = 0,		//0
	EXT_OTA_WORKS,		//1
	EXT_OTA_BUSY,		//2
	EXT_OTA_READY,		//3
	EXT_OTA_EVENT,		//4
	EXT_OTA_ERR_PARM = 0xfe
} EXT_OTA_ENUM;

typedef struct _ext_ota_t {
	uint32_t start_addr;
	uint32_t ota_size; // in kbytes
	uint32_t check_addr;
} ext_ota_t;

extern ext_ota_t ext_ota;

uint8_t check_ext_ota(uint32_t ota_addr, uint32_t ota_size);
void clear_ota_area(void);

#endif // (DEV_SERVICES & SERVICE_OTA_EXT)

#endif /* EXT_OTA_H_ */
