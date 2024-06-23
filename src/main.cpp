/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>

#include <zephyr/logging/log.h>
#include <zephyr/shell/shell.h>
#include <zephyr/kernel.h>

LOG_MODULE_DECLARE(MAIN);

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

int main(void)
{
    __banner();
    return 0;
}

/* Creating subcommands (level 1 command) array for command "demo". */
SHELL_STATIC_SUBCMD_SET_CREATE(sub_demo, SHELL_CMD(banner, NULL, "Display banner", __banner), SHELL_SUBCMD_SET_END);
/* Creating root (level 0) command "demo" */
SHELL_CMD_REGISTER(demo, &sub_demo, "Demo commands", NULL);