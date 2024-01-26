/**
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) Bao Project and Contributors. All rights reserved.
 */

#include <platform.h>

struct platform platform = {
    .cpu_num = 8,
    .region_num = 1,
    .regions =  (struct mem_region[]) {
        {
            .base = 0x80000000,
            .size = 0x300000000,
        },
    },

/* The console will be from the serial 0 device - serial0 = "/serial@3100000";*/
    .console = {
        .base = 0x03100000,
    },

/*  Through the Orin Series System-On-Chip Technical Reference Manual DP-10508-002_v1.0p
    Not sure about GIC details but through the incremental addresses it may be
    gicd = CCPLEX_GICD 
    gicc = CCPLEX_GICA
    gich = CCPLEX_GICT
    gicv = CCPLEX_GICP
    maintenance_id = Virtual Maintenance Interrupt (ID25)*/
    .arch = {
        .gic = {
            .gicd_addr = 0x0f400000,
            .gicc_addr = 0x0f410000,
            .gich_addr = 0x0f420000,
            .gicv_addr = 0x0f430000,
            .maintenance_id = 25,
        },

        .clusters = {
            .num = 2,
            .core_num = (size_t[]){ 2, 4 },
        },

        .smmu = {
            .base = 0x12000000,
            .interrupt_id = 187,
            .global_mask = 0x7f80,
        },
    },

};
