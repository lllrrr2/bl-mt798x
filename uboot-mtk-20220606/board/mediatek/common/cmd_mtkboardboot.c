// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2021 MediaTek Inc. All Rights Reserved.
 *
 * Author: Weijie Gao <weijie.gao@mediatek.com>
 *
 * Generic image booting command
 */

#include <command.h>
#include <linux/types.h>

#include "boot_helper.h"

static int do_mtkboardboot(struct cmd_tbl *cmdtp, int flag, int argc,
			   char *const argv[])
{
	int ret = CMD_RET_SUCCESS;

	ret = board_boot_default();
	if (ret)
		ret = CMD_RET_FAILURE;

	if (IS_ENABLED(CONFIG_WEBUI_FAILSAFE_ON_AUTOBOOT_FAIL))
		run_command("httpd", 0);

	return ret;
}

U_BOOT_CMD(mtkboardboot, 1, 0, do_mtkboardboot,
	   "Boot MTK firmware", ""
);
