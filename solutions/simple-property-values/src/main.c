/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include <string.h>

#include <zephyr/devicetree.h>
#include <zephyr/ztest.h>

#define ZEPHYR_USER_NODE	DT_PATH(zephyr_user)

ZTEST(dt_hands_on, simple_property_values)
{
	const char *my_string = DT_PROP(ZEPHYR_USER_NODE, my_string);
	int my_int = DT_PROP(ZEPHYR_USER_NODE, my_int);
	int my_array[] = DT_PROP(ZEPHYR_USER_NODE, my_array);
	uint8_t my_uint8_array[] = DT_PROP(ZEPHYR_USER_NODE, my_uint8_array);
	const char *my_string_array[] = DT_PROP(ZEPHYR_USER_NODE, my_string_array);

	zassert_true(!strcmp(my_string, "foo"));
	zassert_equal(my_int, 42);
	zassert_equal(my_array[0], 1);
	zassert_equal(my_array[1], 2);
	zassert_equal(my_uint8_array[0], 0x12);
	zassert_equal(my_uint8_array[1], 0x34);
	zassert_true(!strcmp(my_string_array[0], "hello"));
	zassert_true(!strcmp(my_string_array[1], "world"));
}

ZTEST_SUITE(dt_hands_on, NULL, NULL, NULL, NULL, NULL);
