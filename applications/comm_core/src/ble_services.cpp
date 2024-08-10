/* main.c - Application main entry point */

/*
 * Copyright (c) 2015-2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/types.h>
#include <stddef.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/util.h>

#include <zephyr/bluetooth/bluetooth.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(BLE);

static uint8_t mfg_data[] = { 0xDE, 0xAD, 0xBE, 0xEF };

static uint8_t name[] = "ROVER";

static const struct bt_data ad[] = {
    BT_DATA(BT_DATA_MANUFACTURER_DATA, mfg_data, sizeof(mfg_data)),
};

/* Set Scan Response data */
static const struct bt_data sd[] = {
    BT_DATA(BT_DATA_NAME_COMPLETE, name, sizeof(name)),
};

int ble_adv_fn(void)
{
    /* Initialize the Bluetooth Subsystem */
    int err = bt_enable(NULL);
    if (err) {
        printk("Bluetooth init failed (err %d)\n", err);
        return 0;
    }
    LOG_INF("BLE initialized");

    /* Start advertising */
    err = bt_le_adv_start(BT_LE_ADV_NCONN_IDENTITY, ad, ARRAY_SIZE(ad), sd, ARRAY_SIZE(sd));
    if (err) {
        printk("Advertising failed to start (err %d)\n", err);
        return 0;
    }
    LOG_INF("BLE advertisement started");

    /* sleep this thread */
    while (1) {
        k_sleep(K_MSEC(1000));
    }
    return 0;
}

K_THREAD_DEFINE(ble_adv, 512u, ble_adv_fn, NULL, NULL, NULL, 2u, 0, 0);