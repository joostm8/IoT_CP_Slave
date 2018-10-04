#include <stdint.h>
#include <string.h>
#include "update_rate_service.h"
#include "ble_srv_common.h"
#include "app_error.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"

/**@brief Function for initiating our new service.
 *
 * @param[in]   p_our_service        Our Service structure.
 *
 */
void urs_service_init(ble_urs_t * p_urs_service)
{
	// STEP 3: Declare 16 bit service and 128 bit base UUIDs and add them to BLE stack table     
	uint32_t err_code;
	ble_uuid_t service_uuid;
	ble_uuid128_t base_uuid = BLE_UUID_UPDATE_RATE_BASE_UUID;
	service_uuid.uuid = DBS_UUID_UPDATE_SERVICE;
	err_code = sd_ble_uuid_vs_add(&base_uuid, &service_uuid.type);
	APP_ERROR_CHECK(err_code);
    
    
  // STEP 4: Add our service
	err_code = sd_ble_gatts_service_add(BLE_GATTS_SRVC_TYPE_PRIMARY,
																			&service_uuid,
																			&p_urs_service->service_handle);
	APP_ERROR_CHECK(err_code);

  // Print messages to Segger Real Time Terminal
  // UNCOMMENT THE FOUR LINES BELOW AFTER INITIALIZING THE SERVICE OR THE EXAMPLE WILL NOT COMPILE.
	NRF_LOG_INFO("Exectuing our_service_init().\n"); // Print message to RTT to the application flow
	NRF_LOG_INFO("Service UUID: 0x%#04x\n", service_uuid.uuid); // Print service UUID should match definition BLE_UUID_OUR_SERVICE
  NRF_LOG_INFO("Service UUID type: 0x%#02x\n", service_uuid.type); // Print UUID type. Should match BLE_UUID_TYPE_VENDOR_BEGIN. Search for BLE_UUID_TYPES in ble_types.h for more info
  NRF_LOG_INFO("Service handle: 0x%#04x\n", p_urs_service->service_handle); // Print out the service handle. Should match service handle shown in MCP under Attribute values
}
