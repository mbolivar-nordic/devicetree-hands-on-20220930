/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/devicetree.h>
#include <zephyr/ztest.h>

#define NORDIC_FOO_NODE	DT_PATH(soc, foo_0)
#define INTEL_FOO_NODE	DT_PATH(soc, bar_1000)

ZTEST(dt_hands_on, simple_bindings)
{
	zassert_equal(DT_PROP(NORDIC_FOO_NODE, fifo_depth), 16);
	zassert_equal(DT_PROP(INTEL_FOO_NODE, num_channels), 10);
}

ZTEST_SUITE(dt_hands_on, NULL, NULL, NULL, NULL, NULL);
