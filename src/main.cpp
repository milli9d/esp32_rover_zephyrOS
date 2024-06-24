/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>

#include <zephyr/logging/log.h>
#include <zephyr/shell/shell.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/adc.h>

LOG_MODULE_REGISTER(MAIN);

/**
 * @brief display a welcome banner
 * @param
 */
static void inline __banner(void)
{
    printf("\t   -           __                       \n"
           "\t --          ~( @\\   \\                \n"
           "\t---   _________]_[__/_>________         \n"
           "\t     /  ____ \\ <>     |  ____  \\      \n"
           "\t    =\\_/ __ \\_\\_______|_/ __ \\__D   \n"
           "\t________(__)_____________(__)____       \n\n");

    printf("     ______  ______  ______     ______  ______  ______  \n"
           "    /\\  ___\\/\\  ___\\/\\  == \\   /\\  == \\/\\  __ \\/\\__  _\\ \n"
           "    \\ \\  __\\\\ \\___  \\ \\  _-/   \\ \\  __<\\ \\ \\/\\ \\/_/\\ \\/ \n"
           "     \\ \\_____\\/\\_____\\ \\_\\      \\ \\_____\\ \\_____\\ \\ \\_\\ \n"
           "      \\/_____/\\/_____/\\/_/       \\/_____/\\/_____/  \\/_/ \n"
           "                                                        \n");
}

static void __adc_read(void)
{
    static const struct adc_dt_spec adc_chan0 = ADC_DT_SPEC_GET_BY_IDX(DT_PATH(zephyr_user), 0);

    if (adc_is_ready_dt(&adc_chan0)) {
        int err;
        uint32_t count = 0;
        uint32_t buf;

        struct adc_sequence sequence = { .buffer = &buf, .buffer_size = sizeof(buf), .resolution = 12 };

        (void)adc_sequence_init_dt(&adc_chan0, &sequence);
        err = adc_read_dt(&adc_chan0, &sequence);
        if (err == 0u) {
            int32_t val_mv = -99;
            adc_raw_to_millivolts_dt(&adc_chan0, &val_mv);

            LOG_INF("ADC Raw = %d Converted = %d", buf, val_mv);
        }
    }
}

int main(void)
{
    __banner();

    while (1) {
        k_sleep(K_SECONDS(1u));
    }

    return 0;
}

/* Creating subcommands (level 1 command) array for command "demo". */
SHELL_STATIC_SUBCMD_SET_CREATE(sub_demo, SHELL_CMD(banner, NULL, "Display banner", __banner),
                               SHELL_CMD(adc_read, NULL, "Read ADC0", __adc_read), SHELL_SUBCMD_SET_END);
/* Creating root (level 0) command "demo" */
SHELL_CMD_REGISTER(demo, &sub_demo, "Demo commands", NULL);