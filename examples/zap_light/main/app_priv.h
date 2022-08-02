/*
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#pragma once

#include <esp_err.h>
#include <esp_matter.h>

/** Standard max values (used for remapping attributes) */
#define STANDARD_BRIGHTNESS 100
#define STANDARD_HUE 360
#define STANDARD_SATURATION 100
#define STANDARD_TEMPERATURE_FACTOR 1000000

/** Matter max values (used for remapping attributes) */
#define MATTER_BRIGHTNESS 254
#define MATTER_HUE 255
#define MATTER_SATURATION 255
#define MATTER_TEMPERATURE_FACTOR 1000000

/** Initialize the light driver
 *
 * This initializes the light driver associated with the selected board.
 *
 * @return Handle on success.
 * @return NULL in case of failure.
 */
void *app_driver_light_init();

/** Initialize the switch driver
 *
 * This initializes the switch driver associated with the selected board.
 *
 * @return Handle on success.
 * @return NULL in case of failure.
 */
void *app_driver_switch_init();

/** Driver Update
 *
 * This API should be called to update the driver for the attribute being updated.
 * This is usually called from the common `app_attribute_update_cb()`.
 *
 * @param[in] endpoint_id Endpoint ID of the attribute.
 * @param[in] cluster_id Cluster ID of the attribute.
 * @param[in] attribute_id Attribute ID of the attribute.
 * @param[in] val Pointer to `esp_matter_attr_val_t`. Use appropriate elements as per the value type.
 *
 * @return ESP_OK on success.
 * @return error in case of failure.
 */
esp_err_t app_driver_attribute_update(uint16_t endpoint_id, uint32_t cluster_id, uint32_t attribute_id,
                                      esp_matter_attr_val_t *val, void *priv_data);

/** Set driver defaults
 *
 * Set the attribute drivers to their default values.
 * This API should be called after esp_matter::start() because, for zap data model, the attribute defaults are a part
 * of zap-generated and they are initialized in esp_matter::start().
 *
 * @return ESP_OK on success.
 * @return error in case of failure.
 */
esp_err_t app_driver_attribute_set_defaults();
