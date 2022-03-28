// Copyright 2022 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <esp_err.h>
#include <esp_matter.h>

/** Initialize ESP Matter RainMaker
 *
 * This adds the custom RainMaker cluster which is used for RainMaker User Node Association.
 * The 'rainmaker' console command is also added.
 * This should be called before `esp_matter_start()`
 *
 * @return ESP_OK on success.
 * @return error in case of failure.
 */
esp_err_t esp_matter_rainmaker_init(void);

/** Start ESP Matter RainMaker
 *
 * This starts the post initialization process for RainMaker User Node Association.
 * This should be called after `esp_rmaker_node_init()` but before `esp_rmaker_start()`.
 *
 * @return ESP_OK on success.
 * @return error in case of failure.
 */
esp_err_t esp_matter_rainmaker_start(void);

/** Custom Command callback
 *
 * Command callback for custom commands.
 * This should be called when the application receives the custom command callback.
 *
 * @param[in] endpoint_id Endpoint ID of the command.
 * @param[in] cluster_id Cluster ID of the command.
 * @param[in] command_id Command ID.
 * @param[in] tlv_data Command data which can be parsed.
 * @param[in] priv_data Pointer to the private data paassed while setting the command callback.
 *
 * @return ESP_OK on success.
 * @return error in case of failure.
 */
esp_err_t esp_matter_rainmaker_command_callback(int endpoint_id, int cluster_id, int command_id, TLVReader &tlv_data,
                                                void *priv_data);
