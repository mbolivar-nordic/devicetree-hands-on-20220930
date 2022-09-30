/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <string.h>

#include <zephyr/devicetree.h>
#include <zephyr/ztest.h>

#define ZEPHYR_USER_NODE	DT_PATH(zephyr_user)

ZTEST(dt_hands_on, labels_and_phandles)
{
	zassert_equal(strcmp(DT_PROP_BY_PHANDLE(ZEPHYR_USER_NODE, device, message), "two"),
		      0);
}

ZTEST_SUITE(dt_hands_on, NULL, NULL, NULL, NULL, NULL);
