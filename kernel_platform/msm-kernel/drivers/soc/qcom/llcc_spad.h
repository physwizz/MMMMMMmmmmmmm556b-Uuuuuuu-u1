/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2022 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef _SOC_QCOM_LLCC_SPAD_PERFMON_H_
#define _SOC_QCOM_LLCC_SPAD_PERFMON_H_

#define LLCC_SPAD0_BASE_OFFSET		(0xE8000)
#define SPAD_LPI_LB_PERFMON_COUNTER_n_CONFIG(n) (0x00138 + 0x4 * n)
#define SPAD_LPI_LB_PERFMON_COUNTER_n_VALUE(n)	(0x00178 + 0x4 * n)
#define SPAD_LPI_LB_PERFMON_STATUS	(0x00130)
#define SPAD_LPI_LB_PERFMON_MODE	(0x00120)
#define SPAD_LPI_LB_PROF_FILTER_0_CFG	(0x00288)
#define SPAD_LPI_LB_PROF_FILTER_1_CFG	(0x0028C)
#define SPAD_LPI_LB_PERFMON_CONFIGURATION_INFO (0x00134)
#define WR_COLOR_REGION_MASK_SHIFT	(20)

#define SPAD_EVENT_SEL_SHIFT		(16)
#define SPAD_EVENT_SEL_MASK		GENMASK(SPAD_EVENT_SEL_SHIFT + 4,\
					SPAD_EVENT_SEL_SHIFT)
#define SPAD_PORT_SEL_SHIFT		(0)
#define SPAD_PORT_SEL_MASK		GENMASK(SPAD_PORT_SEL_SHIFT + 0,\
					SPAD_PORT_SEL_SHIFT)
#define WR_COLOR_REGION_MASK_SHIFT	(20)
#define WR_COLOR_REGION_MASK_MASK	GENMASK(WR_COLOR_REGION_MASK_SHIFT + 2,\
					WR_COLOR_REGION_MASK_SHIFT)
#define WR_COLOR_REGION_MATCH_SHIFT	(16)
#define WR_COLOR_REGION_MATCH_MASK	GENMASK(WR_COLOR_REGION_MATCH_SHIFT + 2,\
					WR_COLOR_REGION_MATCH_SHIFT)
#define RD_COLOR_REGION_MASK_SHIFT	(8)
#define RD_COLOR_REGION_MASK_MASK	GENMASK(RD_COLOR_REGION_MASK_SHIFT + 2,\
					RD_COLOR_REGION_MASK_SHIFT)
#define RD_COLOR_REGION_MATCH_SHIFT	(4)
#define RD_COLOR_REGION_MATCH_MASK	GENMASK(RD_COLOR_REGION_MATCH_SHIFT + 2,\
					RD_COLOR_REGION_MATCH_SHIFT)

#define WR_COLOR_REGION_INV_SHIFT	(12)
#define WR_COLOR_REGION_INV_MATCH	BIT(WR_COLOR_REGION_INV_SHIFT)
#define WR_COLOR_REGION_INV_MASK	GENMASK(WR_COLOR_REGION_INV_SHIFT + 0,\
					WR_COLOR_REGION_INV_SHIFT)
#define RD_COLOR_REGION_INV_SHIFT	(0)
#define RD_COLOR_REGION_INV_MATCH	BIT(RD_COLOR_REGION_INV_SHIFT)
#define RD_COLOR_REGION_INV_MASK	GENMASK(RD_COLOR_REGION_INV_SHIFT + 0,\
					RD_COLOR_REGION_INV_SHIFT)
#define SPAD_FILTER_EN_SEL_SHIFT	(4)
#define SPAD_FILTER_EN_SEL_MASK		GENMASK(SPAD_FILTER_EN_SEL_SHIFT + 1,\
					SPAD_FILTER_EN_SEL_SHIFT)
#define SPAD_MANUAL_MODE		(0)
#define SPAD_MONITOR_EN_SHIFT		(15)
#define SPAD_MONITOR_EN			BIT(SPAD_MONITOR_EN_SHIFT)
#define SPAD_MONITOR_EN_MASK		GENMASK(SPAD_MONITOR_EN_SHIFT + 0,\
					SPAD_MONITOR_EN_SHIFT)

#define SPAD_MONITOR_MODE_SHIFT		(0)
#define SPAD_MONITOR_MODE_MASK		GENMASK(SPAD_MONITOR_MODE_SHIFT + 0,\
					SPAD_MONITOR_MODE_SHIFT)
#define SPAD_NUM_PORT_EVENT_SHIFT	(16)
#define SPAD_NUM_PORT_EVENT_MASK	GENMASK(SPAD_NUM_PORT_EVENT_SHIFT + 7,\
					SPAD_NUM_PORT_EVENT_SHIFT)

#define CLEAR_ON_ENABLE			BIT(31)
#define CLEAR_ON_DUMP			BIT(30)
#define FREEZE_ON_SATURATE		BIT(29)
#define CHAINING_EN			BIT(28)
#define COUNT_CLOCK_EVENT		BIT(24)
#define ACTIVATE			(1)
#define DEACTIVATE			(0)
#define FILTER_EN_NONE			(0x2)
#define SPAD_EVENT_NUM_MAX		(128)

enum spad_event_port_select {
	SPAD_EVENT_PORT0,
	SPAD_EVENT_PORT1,
	SPAD_EVENT_PORT2,
};

enum spad_filter_type {
	FILTER0,
	FILTER1,
	UNKNOWN,
};

enum spad_events_port0 {
	SHARED_LB_ACC_FROM_SPAD_PROF_EVENT,
	RD_TX_LESS_THAN_64B_PROF_EVENT,
	WR_TX_LESS_THAN_64B_PROF_EVENT,
	RD_TX_LEN_64B_PROF_EVENT,
	WR_TX_LEN_64B_PROF_EVENT,
	RD_TX_LEN_128B_PROF_EVENT,
	WR_TX_LEN_128B_PROF_EVENT,
	RD_TX_LEN_256B_PROF_EVENT,
	WR_TX_LEN_256B_PROF_EVENT,
	RDI_ACC_PROF_EVENT,
	WRI_ACC_PROF_EVENT,
	WRO_ACC_PROF_EVENT,
	ANY_ACC_PROF_EVENT,
	RD_BACK_PRESSURE_PROF_EVENT,
	WR_BACK_PRESSURE_PROF_EVENT,
};

enum spad_events_port1 {
	RD_TX_RED_COLOR_REGION_PROF_EVENT,
	RD_TX_GREEN_COLOR_REGION_PROF_EVENT,
	RD_TX_BLUE_COLOR_REGION_PROF_EVENT,
	WR_TX_RED_COLOR_REGION_PROF_EVENT,
	WR_TX_GREEN_COLOR_REGION_PROF_EVENT,
	WR_TX_BLUE_COLOR_REGION_PROF_EVENT,
	RD_CMD_CREDIT_RELEASE_PROF_EVENT,
	RD_DATA_CREDIT_RELEASE_PROF_EVENT,
	WR_CMD_CREDIT_RELEASE_PROF_EVENT,
	WR_CMD_STALL_AT_RAMC_PROF_EVENT,
};

enum spad_events_port2 {
	CFG_ACC_FROM_SPAD_PROF_EVENT,
	LB_ACC_FROM_LLCC_PROF_EVENT = 2,
	ANY_PCB_SLP_RET_PROF_EVENT = 9,
	ANY_PCB_SLP_NRET_PROF_EVENT,
	ANY_PCB_WAKEUP_PROF_EVENT
};
#endif