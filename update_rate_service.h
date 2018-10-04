/*
Custom service that can set the update rate
of the temperature advertisement.
*/


#ifndef UPDATE_RATE_SERVICE_H__
#define UPDATE_RATE_SERVICE_H__

#include <stdint.h>
#include "ble.h"
#include "ble_srv_common.h"

#define BLE_UUID_UPDATE_RATE_BASE_UUID {0xA9, 0x2E, 0x53, 0x00, 0xDD, 0x38, 0xCA, 0xB2, 0x19, 0x41, 0xCC, 0x8D, 0x00, 0x00, 0xFD, 0xBE}
#define DBS_UUID_UPDATE_SERVICE 0x1524
#define DBS_UUID_PERIOD_VALUE 0x1525

/**
 * @brief This structure contains various status information for our service. 
 * It only holds one entry now, but will be populated with more items as we go.
 * The name is based on the naming convention used in Nordic's SDKs. 
 * 'ble’ indicates that it is a Bluetooth Low Energy relevant structure and 
 * ‘urs’ is short for update rate service). 
 */
typedef struct
{
    uint16_t    service_handle;     /**< Handle of Our Service (as provided by the BLE stack). */
}ble_urs_t;

/**@brief Function for initializing our new service.
 *
 * @param[in]   p_urs_service       Pointer to Our Service structure.
 */
void urs_service_init(ble_urs_t * p_urs_service);

#endif  /* UPDATE_RATE_SERVICE_H__ */
