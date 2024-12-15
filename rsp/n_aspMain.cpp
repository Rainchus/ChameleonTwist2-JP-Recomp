#include "librecomp/rsp.hpp"
#include "librecomp/rsp_vu_impl.hpp"
RspExitReason n_aspMain(uint8_t* rdram) {
    uint32_t           r1 = 0,  r2 = 0,  r3 = 0,  r4 = 0,  r5 = 0,  r6 = 0,  r7 = 0;
    uint32_t  r8 = 0,  r9 = 0, r10 = 0, r11 = 0, r12 = 0, r13 = 0, r14 = 0, r15 = 0;
    uint32_t r16 = 0, r17 = 0, r18 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0;
    uint32_t r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    uint32_t dma_dmem_address = 0, dma_dram_address = 0, jump_target = 0;
    const char * debug_file = NULL; int debug_line = 0;
    RSP rsp{};
    r1 = 0xFC0;
    // mfc0        $5, DPC_STATUS
    r5 = 0;
    // lw          $28, 0x30($1)
    r28 = RSP_MEM_W_LOAD(0X30, r1);
    // lw          $27, 0x34($1)
    r27 = RSP_MEM_W_LOAD(0X34, r1);
    // andi        $4, $5, 0x1
    r4 = r5 & 0X1;
    // beq         $4, $zero, L_10AC
    if (r4 == 0) {
        // andi        $4, $5, 0x100
        r4 = r5 & 0X100;
        goto L_10AC;
    }
    // andi        $4, $5, 0x100
    r4 = r5 & 0X100;
    // beq         $4, $zero, L_10AC
    if (r4 == 0) {
        // mfc0        $4, DPC_STATUS
        r4 = 0;
        goto L_10AC;
    }
    // mfc0        $4, DPC_STATUS
    r4 = 0;
L_10A0:
    // andi        $4, $4, 0x100
    r4 = r4 & 0X100;
    // bgtz        $4, L_10A0
    if (RSP_SIGNED(r4) > 0) {
        // mfc0        $4, DPC_STATUS
        r4 = 0;
        goto L_10A0;
    }
    // mfc0        $4, DPC_STATUS
    r4 = 0;
L_10AC:
    // addi        $24, $zero, 0xFA0
    r24 = RSP_ADD32(0, 0XFA0);
    // jal         0x1120
    r31 = 0x10B8;
    // add         $2, $zero, $28
    r2 = RSP_ADD32(0, r28);
    goto L_1120;
    // add         $2, $zero, $28
    r2 = RSP_ADD32(0, r28);
L_10B8:
    // mfc0        $2, SP_DMA_BUSY
    r2 = 0;
L_10BC:
    // bne         $2, $zero, L_10BC
    if (r2 != 0) {
        // mfc0        $2, SP_DMA_BUSY
        r2 = 0;
        goto L_10BC;
    }
    // mfc0        $2, SP_DMA_BUSY
    r2 = 0;
    // mtc0        $zero, SP_SEMAPHORE
L_10C8:
    // lw          $26, 0x0($29)
    r26 = RSP_MEM_W_LOAD(0X0, r29);
    // lw          $25, 0x4($29)
    r25 = RSP_MEM_W_LOAD(0X4, r29);
    // addi        $28, $28, 0x8
    r28 = RSP_ADD32(r28, 0X8);
    // srl         $1, $26, 23
    r1 = S32(U32(r26) >> 23);
    // andi        $1, $1, 0xFE
    r1 = r1 & 0XFE;
    // lh          $1, 0x0($1)
    r1 = RSP_MEM_H_LOAD(0X0, r1);
    // jr          $1
    jump_target = r1;
    debug_file = __FILE__; debug_line = __LINE__;
    // addi        $27, $27, -0x8
    r27 = RSP_ADD32(r27, -0X8);
    goto do_indirect_jump;
    // addi        $27, $27, -0x8
    r27 = RSP_ADD32(r27, -0X8);
    // break       0
    return RspExitReason::Broke;
L_10EC:
    // bgtz        $30, L_10C8
    if (RSP_SIGNED(r30) > 0) {
        // addi        $29, $29, 0x8
        r29 = RSP_ADD32(r29, 0X8);
        goto L_10C8;
    }
    // addi        $29, $29, 0x8
    r29 = RSP_ADD32(r29, 0X8);
    // blez        $27, L_110C
    if (RSP_SIGNED(r27) <= 0) {
        // ori         $1, $zero, 0x4000
        r1 = 0 | 0X4000;
        goto L_110C;
    }
    // ori         $1, $zero, 0x4000
    r1 = 0 | 0X4000;
    // jal         0x1120
    r31 = 0x1104;
    // add         $2, $zero, $28
    r2 = RSP_ADD32(0, r28);
    goto L_1120;
    // add         $2, $zero, $28
    r2 = RSP_ADD32(0, r28);
L_1104:
    // j           L_10BC
    // mfc0        $2, SP_DMA_BUSY
    r2 = 0;
    goto L_10BC;
    // mfc0        $2, SP_DMA_BUSY
    r2 = 0;
L_110C:
    // mtc0        $1, SP_STATUS
    // break       0
    return RspExitReason::Broke;
    // nop

L_1118:
    // b           L_1118
    // nop

    goto L_1118;
    // nop

L_1120:
    // addi        $5, $ra, 0x0
    r5 = RSP_ADD32(r31, 0X0);
    // addi        $3, $27, 0x0
    r3 = RSP_ADD32(r27, 0X0);
    // addi        $4, $3, -0x140
    r4 = RSP_ADD32(r3, -0X140);
    // blez        $4, L_1138
    if (RSP_SIGNED(r4) <= 0) {
        // addi        $1, $zero, 0x2B0
        r1 = RSP_ADD32(0, 0X2B0);
        goto L_1138;
    }
    // addi        $1, $zero, 0x2B0
    r1 = RSP_ADD32(0, 0X2B0);
    // addi        $3, $zero, 0x140
    r3 = RSP_ADD32(0, 0X140);
L_1138:
    // addi        $30, $3, 0x0
    r30 = RSP_ADD32(r3, 0X0);
    // jal         0x114C
    r31 = 0x1144;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    goto L_114C;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
L_1144:
    // jr          $5
    jump_target = r5;
    debug_file = __FILE__; debug_line = __LINE__;
    // addi        $29, $zero, 0x2B0
    r29 = RSP_ADD32(0, 0X2B0);
    goto do_indirect_jump;
    // addi        $29, $zero, 0x2B0
    r29 = RSP_ADD32(0, 0X2B0);
L_114C:
    // mfc0        $4, SP_SEMAPHORE
    r4 = 0;
L_1150:
    // bne         $4, $zero, L_1150
    if (r4 != 0) {
        // mfc0        $4, SP_SEMAPHORE
        r4 = 0;
        goto L_1150;
    }
    // mfc0        $4, SP_SEMAPHORE
    r4 = 0;
    // mfc0        $4, SP_DMA_FULL
    r4 = 0;
L_115C:
    // bne         $4, $zero, L_115C
    if (r4 != 0) {
        // mfc0        $4, SP_DMA_FULL
        r4 = 0;
        goto L_115C;
    }
    // mfc0        $4, SP_DMA_FULL
    r4 = 0;
    // mtc0        $1, SP_MEM_ADDR
    SET_DMA_DMEM(r1);
    // mtc0        $2, SP_DRAM_ADDR
    SET_DMA_DRAM(r2);
    // jr          $ra
    jump_target = r31;
    debug_file = __FILE__; debug_line = __LINE__;
    // mtc0        $3, SP_RD_LEN
    DO_DMA_READ(r3);
    goto do_indirect_jump;
    // mtc0        $3, SP_RD_LEN
    DO_DMA_READ(r3);
L_1174:
    // mfc0        $4, SP_SEMAPHORE
    r4 = 0;
L_1178:
    // bne         $4, $zero, L_1178
    if (r4 != 0) {
        // mfc0        $4, SP_SEMAPHORE
        r4 = 0;
        goto L_1178;
    }
    // mfc0        $4, SP_SEMAPHORE
    r4 = 0;
    // mfc0        $4, SP_DMA_FULL
    r4 = 0;
L_1184:
    // bne         $4, $zero, L_1184
    if (r4 != 0) {
        // mfc0        $4, SP_DMA_FULL
        r4 = 0;
        goto L_1184;
    }
    // mfc0        $4, SP_DMA_FULL
    r4 = 0;
    // mtc0        $1, SP_MEM_ADDR
    SET_DMA_DMEM(r1);
    // mtc0        $2, SP_DRAM_ADDR
    SET_DMA_DRAM(r2);
    // jr          $ra
    jump_target = r31;
    debug_file = __FILE__; debug_line = __LINE__;
    // mtc0        $3, SP_WR_LEN
    DO_DMA_WRITE(r3);
    goto do_indirect_jump;
    // mtc0        $3, SP_WR_LEN
    DO_DMA_WRITE(r3);
L_119C:
    // andi        $2, $25, 0xFFFF
    r2 = r25 & 0XFFFF;
    // vxor        $v1, $v1, $v1
    rsp.VXOR<0>(rsp.vpu.r[1], rsp.vpu.r[1], rsp.vpu.r[1]);
    // andi        $1, $26, 0xFFFF
    r1 = r26 & 0XFFFF;
    // addi        $1, $1, 0x4F0
    r1 = RSP_ADD32(r1, 0X4F0);
L_11AC:
    // sdv         $v1[0], 0x0($1)
    rsp.SDV<0>(rsp.vpu.r[1], r1, 0X0);
    // sdv         $v1[0], 0x8($1)
    rsp.SDV<0>(rsp.vpu.r[1], r1, 0X1);
    // addi        $2, $2, -0x10
    r2 = RSP_ADD32(r2, -0X10);
    // bgtz        $2, L_11AC
    if (RSP_SIGNED(r2) > 0) {
        // addi        $1, $1, 0x10
        r1 = RSP_ADD32(r1, 0X10);
        goto L_11AC;
    }
    // addi        $1, $1, 0x10
    r1 = RSP_ADD32(r1, 0X10);
    // j           L_10EC
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    goto L_10EC;
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
L_11C8:
    // sll         $3, $26, 8
    r3 = S32(r26) << 8;
    // srl         $3, $3, 20
    r3 = S32(U32(r3) >> 20);
    // beq         $3, $zero, L_10EC
    if (r3 == 0) {
        // addi        $30, $30, -0x8
        r30 = RSP_ADD32(r30, -0X8);
        goto L_10EC;
    }
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    // andi        $1, $26, 0xFFF
    r1 = r26 & 0XFFF;
    // addi        $1, $1, 0x4F0
    r1 = RSP_ADD32(r1, 0X4F0);
    // sll         $2, $25, 8
    r2 = S32(r25) << 8;
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    // jal         0x114C
    r31 = 0x11F4;
    // addi        $2, $2, 0x0
    r2 = RSP_ADD32(r2, 0X0);
    goto L_114C;
    // addi        $2, $2, 0x0
    r2 = RSP_ADD32(r2, 0X0);
L_11F4:
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
L_11F8:
    // bne         $1, $zero, L_11F8
    if (r1 != 0) {
        // mfc0        $1, SP_DMA_BUSY
        r1 = 0;
        goto L_11F8;
    }
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
    // j           L_10EC
    // mtc0        $zero, SP_SEMAPHORE
    goto L_10EC;
    // mtc0        $zero, SP_SEMAPHORE
L_1208:
    // sll         $3, $26, 8
    r3 = S32(r26) << 8;
    // srl         $3, $3, 20
    r3 = S32(U32(r3) >> 20);
    // beq         $3, $zero, L_10EC
    if (r3 == 0) {
        // addi        $30, $30, -0x8
        r30 = RSP_ADD32(r30, -0X8);
        goto L_10EC;
    }
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    // andi        $1, $26, 0xFFF
    r1 = r26 & 0XFFF;
    // addi        $1, $1, 0x4F0
    r1 = RSP_ADD32(r1, 0X4F0);
    // sll         $2, $25, 8
    r2 = S32(r25) << 8;
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    // jal         0x1174
    r31 = 0x1234;
    // addi        $2, $2, 0x0
    r2 = RSP_ADD32(r2, 0X0);
    goto L_1174;
    // addi        $2, $2, 0x0
    r2 = RSP_ADD32(r2, 0X0);
L_1234:
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
L_1238:
    // bne         $1, $zero, L_1238
    if (r1 != 0) {
        // mfc0        $1, SP_DMA_BUSY
        r1 = 0;
        goto L_1238;
    }
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
    // j           L_10EC
    // mtc0        $zero, SP_SEMAPHORE
    goto L_10EC;
    // mtc0        $zero, SP_SEMAPHORE
L_1248:
    // sll         $2, $25, 8
    r2 = S32(r25) << 8;
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
    // addi        $2, $2, 0x0
    r2 = RSP_ADD32(r2, 0X0);
    // addi        $1, $zero, 0x3F0
    r1 = RSP_ADD32(0, 0X3F0);
    // andi        $3, $26, 0xFFFF
    r3 = r26 & 0XFFFF;
    // jal         0x114C
    r31 = 0x1264;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    goto L_114C;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
L_1264:
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
L_1268:
    // bne         $1, $zero, L_1268
    if (r1 != 0) {
        // mfc0        $1, SP_DMA_BUSY
        r1 = 0;
        goto L_1268;
    }
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
    // mtc0        $zero, SP_SEMAPHORE
    // j           L_10EC
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    goto L_10EC;
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
L_127C:
    // srl         $3, $26, 16
    r3 = S32(U32(r26) >> 16);
    // andi        $1, $3, 0x4
    r1 = r3 & 0X4;
    // beq         $1, $zero, L_12BC
    if (r1 == 0) {
        // andi        $1, $3, 0x2
        r1 = r3 & 0X2;
        goto L_12BC;
    }
    // andi        $1, $3, 0x2
    r1 = r3 & 0X2;
    // beq         $1, $zero, L_12A8
    if (r1 == 0) {
        // srl         $2, $25, 16
        r2 = S32(U32(r25) >> 16);
        goto L_12A8;
    }
    // srl         $2, $25, 16
    r2 = S32(U32(r25) >> 16);
    // sh          $26, 0x50($24)
    RSP_MEM_H_STORE(0X50, r24, r26);
    // sh          $2, 0x4C($24)
    RSP_MEM_H_STORE(0X4C, r24, r2);
    // sh          $25, 0x4E($24)
    RSP_MEM_H_STORE(0X4E, r24, r25);
    // j           L_10EC
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    goto L_10EC;
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
L_12A8:
    // sh          $26, 0x46($24)
    RSP_MEM_H_STORE(0X46, r24, r26);
    // sh          $2, 0x48($24)
    RSP_MEM_H_STORE(0X48, r24, r2);
L_12B0:
    // sh          $25, 0x4A($24)
    RSP_MEM_H_STORE(0X4A, r24, r25);
    // j           L_10EC
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    goto L_10EC;
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
L_12BC:
    // srl         $2, $25, 16
    r2 = S32(U32(r25) >> 16);
    // sh          $26, 0x40($24)
    RSP_MEM_H_STORE(0X40, r24, r26);
    // sh          $2, 0x42($24)
    RSP_MEM_H_STORE(0X42, r24, r2);
    // sh          $25, 0x44($24)
    RSP_MEM_H_STORE(0X44, r24, r25);
    // j           L_10EC
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    goto L_10EC;
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
L_12D4:
    // addi        $1, $zero, 0x170
    r1 = RSP_ADD32(0, 0X170);
    // addi        $4, $zero, 0x4F0
    r4 = RSP_ADD32(0, 0X4F0);
    // addi        $2, $zero, 0x9D0
    r2 = RSP_ADD32(0, 0X9D0);
    // addi        $3, $zero, 0xB40
    r3 = RSP_ADD32(0, 0XB40);
L_12E4:
    // lqv         $v1[0], 0x0($2)
    rsp.LQV<0>(rsp.vpu.r[1], r2, 0X0);
    // lqv         $v2[0], 0x0($3)
    rsp.LQV<0>(rsp.vpu.r[2], r3, 0X0);
    // addi        $1, $1, -0x10
    r1 = RSP_ADD32(r1, -0X10);
    // addi        $2, $2, 0x10
    r2 = RSP_ADD32(r2, 0X10);
    // addi        $3, $3, 0x10
    r3 = RSP_ADD32(r3, 0X10);
    // ssv         $v1[0], 0x0($4)
    rsp.SSV<0>(rsp.vpu.r[1], r4, 0X0);
    // ssv         $v2[0], 0x2($4)
    rsp.SSV<0>(rsp.vpu.r[2], r4, 0X1);
    // ssv         $v1[2], 0x4($4)
    rsp.SSV<2>(rsp.vpu.r[1], r4, 0X2);
    // ssv         $v2[2], 0x6($4)
    rsp.SSV<2>(rsp.vpu.r[2], r4, 0X3);
    // ssv         $v1[4], 0x8($4)
    rsp.SSV<4>(rsp.vpu.r[1], r4, 0X4);
    // ssv         $v2[4], 0xA($4)
    rsp.SSV<4>(rsp.vpu.r[2], r4, 0X5);
    // ssv         $v1[6], 0xC($4)
    rsp.SSV<6>(rsp.vpu.r[1], r4, 0X6);
    // ssv         $v2[6], 0xE($4)
    rsp.SSV<6>(rsp.vpu.r[2], r4, 0X7);
    // ssv         $v1[8], 0x10($4)
    rsp.SSV<8>(rsp.vpu.r[1], r4, 0X8);
    // ssv         $v2[8], 0x12($4)
    rsp.SSV<8>(rsp.vpu.r[2], r4, 0X9);
    // ssv         $v1[10], 0x14($4)
    rsp.SSV<10>(rsp.vpu.r[1], r4, 0XA);
    // ssv         $v2[10], 0x16($4)
    rsp.SSV<10>(rsp.vpu.r[2], r4, 0XB);
    // ssv         $v1[12], 0x18($4)
    rsp.SSV<12>(rsp.vpu.r[1], r4, 0XC);
    // ssv         $v2[12], 0x1A($4)
    rsp.SSV<12>(rsp.vpu.r[2], r4, 0XD);
    // ssv         $v1[14], 0x1C($4)
    rsp.SSV<14>(rsp.vpu.r[1], r4, 0XE);
    // ssv         $v2[14], 0x1E($4)
    rsp.SSV<14>(rsp.vpu.r[2], r4, 0XF);
    // bgtz        $1, L_12E4
    if (RSP_SIGNED(r1) > 0) {
        // addi        $4, $4, 0x20
        r4 = RSP_ADD32(r4, 0X20);
        goto L_12E4;
    }
    // addi        $4, $4, 0x20
    r4 = RSP_ADD32(r4, 0X20);
    // j           L_10EC
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    goto L_10EC;
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
L_1348:
    // andi        $1, $25, 0xFFFF
    r1 = r25 & 0XFFFF;
    // andi        $2, $26, 0xFFFF
    r2 = r26 & 0XFFFF;
    // addi        $2, $2, 0x4F0
    r2 = RSP_ADD32(r2, 0X4F0);
    // srl         $3, $25, 16
    r3 = S32(U32(r25) >> 16);
    // addi        $3, $3, 0x4F0
    r3 = RSP_ADD32(r3, 0X4F0);
L_135C:
    // ldv         $v1[0], 0x0($2)
    rsp.LDV<0>(rsp.vpu.r[1], r2, 0X0);
    // ldv         $v2[0], 0x8($2)
    rsp.LDV<0>(rsp.vpu.r[2], r2, 0X1);
    // addi        $1, $1, -0x10
    r1 = RSP_ADD32(r1, -0X10);
    // addi        $2, $2, 0x10
    r2 = RSP_ADD32(r2, 0X10);
    // sdv         $v1[0], 0x0($3)
    rsp.SDV<0>(rsp.vpu.r[1], r3, 0X0);
    // sdv         $v2[0], 0x8($3)
    rsp.SDV<0>(rsp.vpu.r[2], r3, 0X1);
    // bgtz        $1, L_135C
    if (RSP_SIGNED(r1) > 0) {
        // addi        $3, $3, 0x10
        r3 = RSP_ADD32(r3, 0X10);
        goto L_135C;
    }
    // addi        $3, $3, 0x10
    r3 = RSP_ADD32(r3, 0X10);
    // j           L_10EC
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    goto L_10EC;
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
L_1384:
    // sll         $1, $25, 8
    r1 = S32(r25) << 8;
    // srl         $1, $1, 8
    r1 = S32(U32(r1) >> 8);
    // addi        $1, $1, 0x0
    r1 = RSP_ADD32(r1, 0X0);
    // sw          $1, 0xE($zero)
    RSP_MEM_W_STORE(0XE, 0, r1);
    // j           L_10EC
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    goto L_10EC;
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
L_139C:
    // lqv         $v31[0], 0x50($zero)
    rsp.LQV<0>(rsp.vpu.r[31], 0, 0X5);
    // srl         $23, $25, 12
    r23 = S32(U32(r25) >> 12);
    // vxor        $v25, $v25, $v25
    rsp.VXOR<0>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[25]);
    // andi        $23, $23, 0xF
    r23 = r23 & 0XF;
    // vxor        $v24, $v24, $v24
    rsp.VXOR<0>(rsp.vpu.r[24], rsp.vpu.r[24], rsp.vpu.r[24]);
    // addi        $23, $23, 0x4F0
    r23 = RSP_ADD32(r23, 0X4F0);
    // vxor        $v13, $v13, $v13
    rsp.VXOR<0>(rsp.vpu.r[13], rsp.vpu.r[13], rsp.vpu.r[13]);
    // andi        $1, $25, 0xFFF
    r1 = r25 & 0XFFF;
    // vxor        $v14, $v14, $v14
    rsp.VXOR<0>(rsp.vpu.r[14], rsp.vpu.r[14], rsp.vpu.r[14]);
    // addi        $1, $1, 0x4F0
    r1 = RSP_ADD32(r1, 0X4F0);
    // vxor        $v15, $v15, $v15
    rsp.VXOR<0>(rsp.vpu.r[15], rsp.vpu.r[15], rsp.vpu.r[15]);
    // srl         $21, $25, 16
    r21 = S32(U32(r25) >> 16);
    // vxor        $v16, $v16, $v16
    rsp.VXOR<0>(rsp.vpu.r[16], rsp.vpu.r[16], rsp.vpu.r[16]);
    // andi        $21, $21, 0xFFF
    r21 = r21 & 0XFFF;
    // vxor        $v17, $v17, $v17
    rsp.VXOR<0>(rsp.vpu.r[17], rsp.vpu.r[17], rsp.vpu.r[17]);
    // sll         $20, $26, 8
    r20 = S32(r26) << 8;
    // vxor        $v18, $v18, $v18
    rsp.VXOR<0>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[18]);
    // srl         $20, $20, 8
    r20 = S32(U32(r20) >> 8);
    // vxor        $v19, $v19, $v19
    rsp.VXOR<0>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[19]);
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
    // srl         $13, $25, 28
    r13 = S32(U32(r25) >> 28);
    // andi        $2, $13, 0x1
    r2 = r13 & 0X1;
    // bgtz        $2, L_1460
    if (RSP_SIGNED(r2) > 0) {
        // addi        $22, $23, 0x1
        r22 = RSP_ADD32(r23, 0X1);
        goto L_1460;
    }
    // addi        $22, $23, 0x1
    r22 = RSP_ADD32(r23, 0X1);
    // andi        $2, $13, 0x2
    r2 = r13 & 0X2;
    // beq         $2, $zero, L_140C
    if (r2 == 0) {
        // addi        $2, $20, 0x0
        r2 = RSP_ADD32(r20, 0X0);
        goto L_140C;
    }
    // addi        $2, $20, 0x0
    r2 = RSP_ADD32(r20, 0X0);
    // lw          $2, 0xE($zero)
    r2 = RSP_MEM_W_LOAD(0XE, 0);
L_140C:
    // mfc0        $13, SP_SEMAPHORE
    r13 = 0;
L_1410:
    // bne         $13, $zero, L_1410
    if (r13 != 0) {
        // mfc0        $13, SP_SEMAPHORE
        r13 = 0;
        goto L_1410;
    }
    // mfc0        $13, SP_SEMAPHORE
    r13 = 0;
    // mfc0        $13, SP_DMA_FULL
    r13 = 0;
L_141C:
    // bne         $13, $zero, L_141C
    if (r13 != 0) {
        // mfc0        $13, SP_DMA_FULL
        r13 = 0;
        goto L_141C;
    }
    // mfc0        $13, SP_DMA_FULL
    r13 = 0;
    // mtc0        $1, SP_MEM_ADDR
    SET_DMA_DMEM(r1);
    // mtc0        $2, SP_DRAM_ADDR
    SET_DMA_DRAM(r2);
    // mtc0        $3, SP_RD_LEN
    DO_DMA_READ(r3);
    // addi        $19, $zero, 0x20
    r19 = RSP_ADD32(0, 0X20);
    // addi        $18, $zero, 0x3F0
    r18 = RSP_ADD32(0, 0X3F0);
    // ldv         $v25[0], 0x0($19)
    rsp.LDV<0>(rsp.vpu.r[25], r19, 0X0);
    // ldv         $v24[8], 0x0($19)
    rsp.LDV<8>(rsp.vpu.r[24], r19, 0X0);
    // ldv         $v23[0], 0x8($19)
    rsp.LDV<0>(rsp.vpu.r[23], r19, 0X1);
    // ldv         $v23[8], 0x8($19)
    rsp.LDV<8>(rsp.vpu.r[23], r19, 0X1);
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_144C:
    // bne         $5, $zero, L_144C
    if (r5 != 0) {
        // mfc0        $5, SP_DMA_BUSY
        r5 = 0;
        goto L_144C;
    }
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // mtc0        $zero, SP_SEMAPHORE
    // j           L_1484
    // lqv         $v27[0], 0x10($1)
    rsp.LQV<0>(rsp.vpu.r[27], r1, 0X1);
    goto L_1484;
    // lqv         $v27[0], 0x10($1)
    rsp.LQV<0>(rsp.vpu.r[27], r1, 0X1);
L_1460:
    // addi        $19, $zero, 0x20
    r19 = RSP_ADD32(0, 0X20);
    // vxor        $v27, $v27, $v27
    rsp.VXOR<0>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[27]);
    // addi        $18, $zero, 0x3F0
    r18 = RSP_ADD32(0, 0X3F0);
    // ldv         $v25[0], 0x0($19)
    rsp.LDV<0>(rsp.vpu.r[25], r19, 0X0);
    // ldv         $v24[8], 0x0($19)
    rsp.LDV<8>(rsp.vpu.r[24], r19, 0X0);
    // ldv         $v23[0], 0x8($19)
    rsp.LDV<0>(rsp.vpu.r[23], r19, 0X1);
    // ldv         $v23[8], 0x8($19)
    rsp.LDV<8>(rsp.vpu.r[23], r19, 0X1);
    // sqv         $v27[0], 0x0($1)
    rsp.SQV<0>(rsp.vpu.r[27], r1, 0X0);
    // sqv         $v27[0], 0x10($1)
    rsp.SQV<0>(rsp.vpu.r[27], r1, 0X1);
L_1484:
    // beq         $21, $zero, L_1634
    if (r21 == 0) {
        // addi        $1, $1, 0x20
        r1 = RSP_ADD32(r1, 0X20);
        goto L_1634;
    }
    // addi        $1, $1, 0x20
    r1 = RSP_ADD32(r1, 0X20);
    // ldv         $v12[0], 0x0($22)
    rsp.LDV<0>(rsp.vpu.r[12], r22, 0X0);
    // lbu         $10, 0x0($23)
    r10 = RSP_MEM_BU(0X0, r23);
    // addi        $13, $zero, 0xC
    r13 = RSP_ADD32(0, 0XC);
    // addi        $12, $zero, 0x1
    r12 = RSP_ADD32(0, 0X1);
    // andi        $14, $10, 0xF
    r14 = r10 & 0XF;
    // sll         $14, $14, 5
    r14 = S32(r14) << 5;
    // vand        $v10, $v25, $v12[0]
    rsp.VAND<8>(rsp.vpu.r[10], rsp.vpu.r[25], rsp.vpu.r[12]);
    // add         $16, $14, $18
    r16 = RSP_ADD32(r14, r18);
    // vand        $v9, $v24, $v12[1]
    rsp.VAND<9>(rsp.vpu.r[9], rsp.vpu.r[24], rsp.vpu.r[12]);
    // srl         $17, $10, 4
    r17 = S32(U32(r10) >> 4);
    // vand        $v8, $v25, $v12[2]
    rsp.VAND<10>(rsp.vpu.r[8], rsp.vpu.r[25], rsp.vpu.r[12]);
    // sub         $17, $13, $17
    r17 = RSP_SUB32(r13, r17);
    // vand        $v7, $v24, $v12[3]
    rsp.VAND<11>(rsp.vpu.r[7], rsp.vpu.r[24], rsp.vpu.r[12]);
    // addi        $13, $17, -0x1
    r13 = RSP_ADD32(r17, -0X1);
    // sll         $12, $12, 15
    r12 = S32(r12) << 15;
    // srlv        $11, $12, $13
    r11 = S32(U32(r12) >> (r13 & 31));
    // mtc2        $11, $v22[0]
    rsp.MTC2<0>(r11, rsp.vpu.r[22]);
    // lqv         $v21[0], 0x0($16)
    rsp.LQV<0>(rsp.vpu.r[21], r16, 0X0);
    // lqv         $v20[0], 0x10($16)
    rsp.LQV<0>(rsp.vpu.r[20], r16, 0X1);
    // addi        $16, $16, -0x2
    r16 = RSP_ADD32(r16, -0X2);
    // lrv         $v19[0], 0x20($16)
    rsp.LRV<0>(rsp.vpu.r[19], r16, 0X2);
    // addi        $16, $16, -0x2
    r16 = RSP_ADD32(r16, -0X2);
    // lrv         $v18[0], 0x20($16)
    rsp.LRV<0>(rsp.vpu.r[18], r16, 0X2);
    // addi        $16, $16, -0x2
    r16 = RSP_ADD32(r16, -0X2);
    // lrv         $v17[0], 0x20($16)
    rsp.LRV<0>(rsp.vpu.r[17], r16, 0X2);
    // addi        $16, $16, -0x2
    r16 = RSP_ADD32(r16, -0X2);
    // lrv         $v16[0], 0x20($16)
    rsp.LRV<0>(rsp.vpu.r[16], r16, 0X2);
    // addi        $16, $16, -0x2
    r16 = RSP_ADD32(r16, -0X2);
    // lrv         $v15[0], 0x20($16)
    rsp.LRV<0>(rsp.vpu.r[15], r16, 0X2);
    // addi        $16, $16, -0x2
    r16 = RSP_ADD32(r16, -0X2);
    // lrv         $v14[0], 0x20($16)
    rsp.LRV<0>(rsp.vpu.r[14], r16, 0X2);
    // addi        $16, $16, -0x2
    r16 = RSP_ADD32(r16, -0X2);
    // lrv         $v13[0], 0x20($16)
    rsp.LRV<0>(rsp.vpu.r[13], r16, 0X2);
L_1510:
    // addi        $22, $22, 0x9
    r22 = RSP_ADD32(r22, 0X9);
    // vmudn       $v30, $v10, $v23
    rsp.VMUDN<0>(rsp.vpu.r[30], rsp.vpu.r[10], rsp.vpu.r[23]);
    // addi        $23, $23, 0x9
    r23 = RSP_ADD32(r23, 0X9);
    // vmadn       $v30, $v9, $v23
    rsp.VMADN<0>(rsp.vpu.r[30], rsp.vpu.r[9], rsp.vpu.r[23]);
    // lbu         $10, 0x0($23)
    r10 = RSP_MEM_BU(0X0, r23);
    // vmudn       $v29, $v8, $v23
    rsp.VMUDN<0>(rsp.vpu.r[29], rsp.vpu.r[8], rsp.vpu.r[23]);
    // ldv         $v12[0], 0x0($22)
    rsp.LDV<0>(rsp.vpu.r[12], r22, 0X0);
    // vmadn       $v29, $v7, $v23
    rsp.VMADN<0>(rsp.vpu.r[29], rsp.vpu.r[7], rsp.vpu.r[23]);
    // addi        $13, $zero, 0xC
    r13 = RSP_ADD32(0, 0XC);
    // blez        $17, L_1544
    if (RSP_SIGNED(r17) <= 0) {
        // andi        $14, $10, 0xF
        r14 = r10 & 0XF;
        goto L_1544;
    }
    // andi        $14, $10, 0xF
    r14 = r10 & 0XF;
    // vmudm       $v30, $v30, $v22[0]
    rsp.VMUDM<8>(rsp.vpu.r[30], rsp.vpu.r[30], rsp.vpu.r[22]);
    // vmudm       $v29, $v29, $v22[0]
    rsp.VMUDM<8>(rsp.vpu.r[29], rsp.vpu.r[29], rsp.vpu.r[22]);
L_1544:
    // sll         $14, $14, 5
    r14 = S32(r14) << 5;
    // vmudh       $v11, $v21, $v27[6]
    rsp.VMUDH<14>(rsp.vpu.r[11], rsp.vpu.r[21], rsp.vpu.r[27]);
    // add         $16, $14, $18
    r16 = RSP_ADD32(r14, r18);
    // vmadh       $v11, $v20, $v27[7]
    rsp.VMADH<15>(rsp.vpu.r[11], rsp.vpu.r[20], rsp.vpu.r[27]);
    // vmadh       $v11, $v19, $v30[0]
    rsp.VMADH<8>(rsp.vpu.r[11], rsp.vpu.r[19], rsp.vpu.r[30]);
    // vmadh       $v11, $v18, $v30[1]
    rsp.VMADH<9>(rsp.vpu.r[11], rsp.vpu.r[18], rsp.vpu.r[30]);
    // srl         $17, $10, 4
    r17 = S32(U32(r10) >> 4);
    // vmadh       $v11, $v17, $v30[2]
    rsp.VMADH<10>(rsp.vpu.r[11], rsp.vpu.r[17], rsp.vpu.r[30]);
    // vmadh       $v11, $v16, $v30[3]
    rsp.VMADH<11>(rsp.vpu.r[11], rsp.vpu.r[16], rsp.vpu.r[30]);
    // sub         $17, $13, $17
    r17 = RSP_SUB32(r13, r17);
    // vmadh       $v28, $v15, $v30[4]
    rsp.VMADH<12>(rsp.vpu.r[28], rsp.vpu.r[15], rsp.vpu.r[30]);
    // addi        $13, $17, -0x1
    r13 = RSP_ADD32(r17, -0X1);
    // vmadh       $v11, $v14, $v30[5]
    rsp.VMADH<13>(rsp.vpu.r[11], rsp.vpu.r[14], rsp.vpu.r[30]);
    // vmadh       $v11, $v13, $v30[6]
    rsp.VMADH<14>(rsp.vpu.r[11], rsp.vpu.r[13], rsp.vpu.r[30]);
    // vmadh       $v11, $v30, $v31[3]
    rsp.VMADH<11>(rsp.vpu.r[11], rsp.vpu.r[30], rsp.vpu.r[31]);
    // srlv        $11, $12, $13
    r11 = S32(U32(r12) >> (r13 & 31));
    // vsar        $v26, $v6, $v28[1]
    rsp.VSAR<9>(rsp.vpu.r[26], rsp.vpu.r[6]);
    // mtc2        $11, $v22[0]
    rsp.MTC2<0>(r11, rsp.vpu.r[22]);
    // vsar        $v28, $v6, $v28[0]
    rsp.VSAR<8>(rsp.vpu.r[28], rsp.vpu.r[6]);
    // vand        $v10, $v25, $v12[0]
    rsp.VAND<8>(rsp.vpu.r[10], rsp.vpu.r[25], rsp.vpu.r[12]);
    // vand        $v9, $v24, $v12[1]
    rsp.VAND<9>(rsp.vpu.r[9], rsp.vpu.r[24], rsp.vpu.r[12]);
    // vand        $v8, $v25, $v12[2]
    rsp.VAND<10>(rsp.vpu.r[8], rsp.vpu.r[25], rsp.vpu.r[12]);
    // vand        $v7, $v24, $v12[3]
    rsp.VAND<11>(rsp.vpu.r[7], rsp.vpu.r[24], rsp.vpu.r[12]);
    // vmudn       $v11, $v26, $v31[1]
    rsp.VMUDN<9>(rsp.vpu.r[11], rsp.vpu.r[26], rsp.vpu.r[31]);
    // vmadh       $v28, $v28, $v31[1]
    rsp.VMADH<9>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[31]);
    // vmudh       $v11, $v19, $v29[0]
    rsp.VMUDH<8>(rsp.vpu.r[11], rsp.vpu.r[19], rsp.vpu.r[29]);
    // addi        $15, $16, -0x2
    r15 = RSP_ADD32(r16, -0X2);
    // vmadh       $v11, $v18, $v29[1]
    rsp.VMADH<9>(rsp.vpu.r[11], rsp.vpu.r[18], rsp.vpu.r[29]);
    // lrv         $v19[0], 0x20($15)
    rsp.LRV<0>(rsp.vpu.r[19], r15, 0X2);
    // vmadh       $v11, $v17, $v29[2]
    rsp.VMADH<10>(rsp.vpu.r[11], rsp.vpu.r[17], rsp.vpu.r[29]);
    // addi        $15, $15, -0x2
    r15 = RSP_ADD32(r15, -0X2);
    // vmadh       $v11, $v16, $v29[3]
    rsp.VMADH<11>(rsp.vpu.r[11], rsp.vpu.r[16], rsp.vpu.r[29]);
    // lrv         $v18[0], 0x20($15)
    rsp.LRV<0>(rsp.vpu.r[18], r15, 0X2);
    // vmadh       $v11, $v15, $v29[4]
    rsp.VMADH<12>(rsp.vpu.r[11], rsp.vpu.r[15], rsp.vpu.r[29]);
    // addi        $15, $15, -0x2
    r15 = RSP_ADD32(r15, -0X2);
    // vmadh       $v11, $v14, $v29[5]
    rsp.VMADH<13>(rsp.vpu.r[11], rsp.vpu.r[14], rsp.vpu.r[29]);
    // lrv         $v17[0], 0x20($15)
    rsp.LRV<0>(rsp.vpu.r[17], r15, 0X2);
    // vmadh       $v11, $v13, $v29[6]
    rsp.VMADH<14>(rsp.vpu.r[11], rsp.vpu.r[13], rsp.vpu.r[29]);
    // addi        $15, $15, -0x2
    r15 = RSP_ADD32(r15, -0X2);
    // vmadh       $v11, $v29, $v31[3]
    rsp.VMADH<11>(rsp.vpu.r[11], rsp.vpu.r[29], rsp.vpu.r[31]);
    // lrv         $v16[0], 0x20($15)
    rsp.LRV<0>(rsp.vpu.r[16], r15, 0X2);
    // vmadh       $v11, $v21, $v28[6]
    rsp.VMADH<14>(rsp.vpu.r[11], rsp.vpu.r[21], rsp.vpu.r[28]);
    // addi        $15, $15, -0x2
    r15 = RSP_ADD32(r15, -0X2);
    // vmadh       $v11, $v20, $v28[7]
    rsp.VMADH<15>(rsp.vpu.r[11], rsp.vpu.r[20], rsp.vpu.r[28]);
    // lrv         $v15[0], 0x20($15)
    rsp.LRV<0>(rsp.vpu.r[15], r15, 0X2);
    // vsar        $v26, $v6, $v27[1]
    rsp.VSAR<9>(rsp.vpu.r[26], rsp.vpu.r[6]);
    // addi        $15, $15, -0x2
    r15 = RSP_ADD32(r15, -0X2);
    // vsar        $v27, $v6, $v27[0]
    rsp.VSAR<8>(rsp.vpu.r[27], rsp.vpu.r[6]);
    // lrv         $v14[0], 0x20($15)
    rsp.LRV<0>(rsp.vpu.r[14], r15, 0X2);
    // addi        $15, $15, -0x2
    r15 = RSP_ADD32(r15, -0X2);
    // lrv         $v13[0], 0x20($15)
    rsp.LRV<0>(rsp.vpu.r[13], r15, 0X2);
    // lqv         $v21[0], 0x0($16)
    rsp.LQV<0>(rsp.vpu.r[21], r16, 0X0);
    // vmudn       $v11, $v26, $v31[1]
    rsp.VMUDN<9>(rsp.vpu.r[11], rsp.vpu.r[26], rsp.vpu.r[31]);
    // lqv         $v20[0], 0x10($16)
    rsp.LQV<0>(rsp.vpu.r[20], r16, 0X1);
    // vmadh       $v27, $v27, $v31[1]
    rsp.VMADH<9>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[31]);
    // addi        $21, $21, -0x20
    r21 = RSP_ADD32(r21, -0X20);
    // sqv         $v28[0], 0x0($1)
    rsp.SQV<0>(rsp.vpu.r[28], r1, 0X0);
    // addi        $1, $1, 0x20
    r1 = RSP_ADD32(r1, 0X20);
    // bgtz        $21, L_1510
    if (RSP_SIGNED(r21) > 0) {
        // sqv         $v27[0], 0x7F0($1)
        rsp.SQV<0>(rsp.vpu.r[27], r1, -0X1);
        goto L_1510;
    }
    // sqv         $v27[0], 0x7F0($1)
    rsp.SQV<0>(rsp.vpu.r[27], r1, -0X1);
L_1634:
    // addi        $1, $1, -0x20
    r1 = RSP_ADD32(r1, -0X20);
    // jal         0x1174
    r31 = 0x1640;
    // addi        $2, $20, 0x0
    r2 = RSP_ADD32(r20, 0X0);
    goto L_1174;
    // addi        $2, $20, 0x0
    r2 = RSP_ADD32(r20, 0X0);
L_1640:
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_1648:
    // bne         $5, $zero, L_1648
    if (r5 != 0) {
        // mfc0        $5, SP_DMA_BUSY
        r5 = 0;
        goto L_1648;
    }
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // j           L_10EC
    // mtc0        $zero, SP_SEMAPHORE
    goto L_10EC;
    // mtc0        $zero, SP_SEMAPHORE
    // srl         $19, $25, 24
    r19 = S32(U32(r25) >> 24);
    // addi        $20, $zero, 0x3F0
    r20 = RSP_ADD32(0, 0X3F0);
    // vxor        $v21, $v21, $v21
    rsp.VXOR<0>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[21]);
    // beq         $19, $zero, L_1670
    if (r19 == 0) {
        // addi        $23, $zero, 0x4F0
        r23 = RSP_ADD32(0, 0X4F0);
        goto L_1670;
    }
    // addi        $23, $zero, 0x4F0
    r23 = RSP_ADD32(0, 0X4F0);
    // addi        $23, $zero, 0x660
    r23 = RSP_ADD32(0, 0X660);
L_1670:
    // lqv         $v28[0], 0x10($20)
    rsp.LQV<0>(rsp.vpu.r[28], r20, 0X1);
    // vxor        $v22, $v22, $v22
    rsp.VXOR<0>(rsp.vpu.r[22], rsp.vpu.r[22], rsp.vpu.r[22]);
    // mtc2        $26, $v18[10]
    rsp.MTC2<10>(r26, rsp.vpu.r[18]);
    // vxor        $v23, $v23, $v23
    rsp.VXOR<0>(rsp.vpu.r[23], rsp.vpu.r[23], rsp.vpu.r[23]);
    // sll         $26, $26, 2
    r26 = S32(r26) << 2;
    // vxor        $v24, $v24, $v24
    rsp.VXOR<0>(rsp.vpu.r[24], rsp.vpu.r[24], rsp.vpu.r[24]);
    // mtc2        $26, $v20[0]
    rsp.MTC2<0>(r26, rsp.vpu.r[20]);
    // vxor        $v25, $v25, $v25
    rsp.VXOR<0>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[25]);
    // sll         $2, $25, 8
    r2 = S32(r25) << 8;
    // vxor        $v26, $v26, $v26
    rsp.VXOR<0>(rsp.vpu.r[26], rsp.vpu.r[26], rsp.vpu.r[26]);
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
    // vxor        $v27, $v27, $v27
    rsp.VXOR<0>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[27]);
    // addi        $2, $2, 0x0
    r2 = RSP_ADD32(r2, 0X0);
    // addi        $3, $zero, 0x7
    r3 = RSP_ADD32(0, 0X7);
    // addi        $19, $zero, 0x4
    r19 = RSP_ADD32(0, 0X4);
    // mtc2        $19, $v18[0]
    rsp.MTC2<0>(r19, rsp.vpu.r[18]);
    // addi        $22, $zero, 0x170
    r22 = RSP_ADD32(0, 0X170);
    // vmudm       $v20, $v28, $v20[0]
    rsp.VMUDM<8>(rsp.vpu.r[20], rsp.vpu.r[28], rsp.vpu.r[20]);
    // srl         $19, $26, 18
    r19 = S32(U32(r26) >> 18);
    // andi        $19, $19, 0x1
    r19 = r19 & 0X1;
    // bgtz        $19, L_1740
    if (RSP_SIGNED(r19) > 0) {
        // sqv         $v20[0], 0x10($20)
        rsp.SQV<0>(rsp.vpu.r[20], r20, 0X1);
        goto L_1740;
    }
    // sqv         $v20[0], 0x10($20)
    rsp.SQV<0>(rsp.vpu.r[20], r20, 0X1);
    // addi        $1, $24, 0x0
    r1 = RSP_ADD32(r24, 0X0);
    // mfc0        $19, SP_SEMAPHORE
    r19 = 0;
L_16D0:
    // bne         $19, $zero, L_16D0
    if (r19 != 0) {
        // mfc0        $19, SP_SEMAPHORE
        r19 = 0;
        goto L_16D0;
    }
    // mfc0        $19, SP_SEMAPHORE
    r19 = 0;
    // mfc0        $19, SP_DMA_FULL
    r19 = 0;
L_16DC:
    // bne         $19, $zero, L_16DC
    if (r19 != 0) {
        // mfc0        $19, SP_DMA_FULL
        r19 = 0;
        goto L_16DC;
    }
    // mfc0        $19, SP_DMA_FULL
    r19 = 0;
    // mtc0        $1, SP_MEM_ADDR
    SET_DMA_DMEM(r1);
    // mtc0        $2, SP_DRAM_ADDR
    SET_DMA_DRAM(r2);
    // mtc0        $3, SP_RD_LEN
    DO_DMA_READ(r3);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v27[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[27], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v26[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[26], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v25[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[25], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v24[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[24], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v23[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[23], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v22[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[22], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v21[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[21], r20, 0X2);
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_172C:
    // bne         $5, $zero, L_172C
    if (r5 != 0) {
        // mfc0        $5, SP_DMA_BUSY
        r5 = 0;
        goto L_172C;
    }
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // mtc0        $zero, SP_SEMAPHORE
    // j           L_177C
    // ldv         $v30[8], 0x0($1)
    rsp.LDV<8>(rsp.vpu.r[30], r1, 0X0);
    goto L_177C;
    // ldv         $v30[8], 0x0($1)
    rsp.LDV<8>(rsp.vpu.r[30], r1, 0X0);
L_1740:
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // vxor        $v30, $v30, $v30
    rsp.VXOR<0>(rsp.vpu.r[30], rsp.vpu.r[30], rsp.vpu.r[30]);
    // lrv         $v27[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[27], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v26[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[26], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v25[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[25], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v24[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[24], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v23[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[23], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v22[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[22], r20, 0X2);
    // addi        $20, $20, -0x2
    r20 = RSP_ADD32(r20, -0X2);
    // lrv         $v21[0], 0x20($20)
    rsp.LRV<0>(rsp.vpu.r[21], r20, 0X2);
L_177C:
    // lqv         $v31[0], 0x0($23)
    rsp.LQV<0>(rsp.vpu.r[31], r23, 0X0);
L_1780:
    // vmudh       $v20, $v28, $v30[7]
    rsp.VMUDH<15>(rsp.vpu.r[20], rsp.vpu.r[28], rsp.vpu.r[30]);
    // vmadh       $v20, $v27, $v31[0]
    rsp.VMADH<8>(rsp.vpu.r[20], rsp.vpu.r[27], rsp.vpu.r[31]);
    // addi        $22, $22, -0x10
    r22 = RSP_ADD32(r22, -0X10);
    // vmadh       $v20, $v26, $v31[1]
    rsp.VMADH<9>(rsp.vpu.r[20], rsp.vpu.r[26], rsp.vpu.r[31]);
    // vmadh       $v20, $v25, $v31[2]
    rsp.VMADH<10>(rsp.vpu.r[20], rsp.vpu.r[25], rsp.vpu.r[31]);
    // sqv         $v30[0], 0x7F0($23)
    rsp.SQV<0>(rsp.vpu.r[30], r23, -0X1);
    // vmadh       $v20, $v24, $v31[3]
    rsp.VMADH<11>(rsp.vpu.r[20], rsp.vpu.r[24], rsp.vpu.r[31]);
    // vmadh       $v30, $v23, $v31[4]
    rsp.VMADH<12>(rsp.vpu.r[30], rsp.vpu.r[23], rsp.vpu.r[31]);
    // vmadh       $v20, $v22, $v31[5]
    rsp.VMADH<13>(rsp.vpu.r[20], rsp.vpu.r[22], rsp.vpu.r[31]);
    // vmadh       $v20, $v21, $v31[6]
    rsp.VMADH<14>(rsp.vpu.r[20], rsp.vpu.r[21], rsp.vpu.r[31]);
    // vmadh       $v20, $v31, $v18[5]
    rsp.VMADH<13>(rsp.vpu.r[20], rsp.vpu.r[31], rsp.vpu.r[18]);
    // lqv         $v31[0], 0x10($23)
    rsp.LQV<0>(rsp.vpu.r[31], r23, 0X1);
    // vsar        $v29, $v19, $v30[1]
    rsp.VSAR<9>(rsp.vpu.r[29], rsp.vpu.r[19]);
    // vsar        $v30, $v19, $v30[0]
    rsp.VSAR<8>(rsp.vpu.r[30], rsp.vpu.r[19]);
    // vmudn       $v20, $v29, $v18[0]
    rsp.VMUDN<8>(rsp.vpu.r[20], rsp.vpu.r[29], rsp.vpu.r[18]);
    // vmadh       $v30, $v30, $v18[0]
    rsp.VMADH<8>(rsp.vpu.r[30], rsp.vpu.r[30], rsp.vpu.r[18]);
    // bgtz        $22, L_1780
    if (RSP_SIGNED(r22) > 0) {
        // addi        $23, $23, 0x10
        r23 = RSP_ADD32(r23, 0X10);
        goto L_1780;
    }
    // addi        $23, $23, 0x10
    r23 = RSP_ADD32(r23, 0X10);
    // addi        $1, $23, -0x8
    r1 = RSP_ADD32(r23, -0X8);
    // jal         0x1174
    r31 = 0x17D4;
    // sqv         $v30[0], 0x7F0($23)
    rsp.SQV<0>(rsp.vpu.r[30], r23, -0X1);
    goto L_1174;
    // sqv         $v30[0], 0x7F0($23)
    rsp.SQV<0>(rsp.vpu.r[30], r23, -0X1);
L_17D4:
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_17DC:
    // bne         $5, $zero, L_17DC
    if (r5 != 0) {
        // mfc0        $5, SP_DMA_BUSY
        r5 = 0;
        goto L_17DC;
    }
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // j           L_10EC
    // mtc0        $zero, SP_SEMAPHORE
    goto L_10EC;
    // mtc0        $zero, SP_SEMAPHORE
L_17EC:
    // sll         $2, $26, 8
    r2 = S32(r26) << 8;
    // vxor        $v23, $v23, $v23
    rsp.VXOR<0>(rsp.vpu.r[23], rsp.vpu.r[23], rsp.vpu.r[23]);
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
    // addi        $2, $2, 0x0
    r2 = RSP_ADD32(r2, 0X0);
    // addi        $3, $zero, 0xF
    r3 = RSP_ADD32(0, 0XF);
    // srl         $21, $25, 30
    r21 = S32(U32(r25) >> 30);
    // bgtz        $21, L_1860
    if (RSP_SIGNED(r21) > 0) {
        // addi        $1, $24, 0x0
        r1 = RSP_ADD32(r24, 0X0);
        goto L_1860;
    }
    // addi        $1, $24, 0x0
    r1 = RSP_ADD32(r24, 0X0);
    // mfc0        $4, SP_SEMAPHORE
    r4 = 0;
L_1810:
    // bne         $4, $zero, L_1810
    if (r4 != 0) {
        // mfc0        $4, SP_SEMAPHORE
        r4 = 0;
        goto L_1810;
    }
    // mfc0        $4, SP_SEMAPHORE
    r4 = 0;
    // mfc0        $4, SP_DMA_FULL
    r4 = 0;
L_181C:
    // bne         $4, $zero, L_181C
    if (r4 != 0) {
        // mfc0        $4, SP_DMA_FULL
        r4 = 0;
        goto L_181C;
    }
    // mfc0        $4, SP_DMA_FULL
    r4 = 0;
    // mtc0        $1, SP_MEM_ADDR
    SET_DMA_DMEM(r1);
    // mtc0        $2, SP_DRAM_ADDR
    SET_DMA_DRAM(r2);
    // mtc0        $3, SP_RD_LEN
    DO_DMA_READ(r3);
    // srl         $20, $25, 2
    r20 = S32(U32(r25) >> 2);
    // andi        $20, $20, 0xFFF
    r20 = r20 & 0XFFF;
    // addi        $20, $20, 0x4E8
    r20 = RSP_ADD32(r20, 0X4E8);
    // lqv         $v31[0], 0x40($zero)
    rsp.LQV<0>(rsp.vpu.r[31], 0, 0X4);
    // lqv         $v25[0], 0x30($zero)
    rsp.LQV<0>(rsp.vpu.r[25], 0, 0X3);
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_1848:
    // bne         $5, $zero, L_1848
    if (r5 != 0) {
        // mfc0        $5, SP_DMA_BUSY
        r5 = 0;
        goto L_1848;
    }
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // mtc0        $zero, SP_SEMAPHORE
    // ldv         $v19[0], 0x0($24)
    rsp.LDV<0>(rsp.vpu.r[19], r24, 0X0);
    // j           L_187C
    // lsv         $v24[14], 0x8($24)
    rsp.LSV<14>(rsp.vpu.r[24], r24, 0X4);
    goto L_187C;
    // lsv         $v24[14], 0x8($24)
    rsp.LSV<14>(rsp.vpu.r[24], r24, 0X4);
L_1860:
    // srl         $20, $25, 2
    r20 = S32(U32(r25) >> 2);
    // andi        $20, $20, 0xFFF
    r20 = r20 & 0XFFF;
    // addi        $20, $20, 0x4E8
    r20 = RSP_ADD32(r20, 0X4E8);
    // lqv         $v31[0], 0x40($zero)
    rsp.LQV<0>(rsp.vpu.r[31], 0, 0X4);
    // vxor        $v19, $v19, $v19
    rsp.VXOR<0>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[19]);
    // lqv         $v25[0], 0x30($zero)
    rsp.LQV<0>(rsp.vpu.r[25], 0, 0X3);
    // vxor        $v24, $v24, $v24
    rsp.VXOR<0>(rsp.vpu.r[24], rsp.vpu.r[24], rsp.vpu.r[24]);
L_187C:
    // mtc2        $20, $v21[4]
    rsp.MTC2<4>(r20, rsp.vpu.r[21]);
    // addi        $4, $zero, 0xB0
    r4 = RSP_ADD32(0, 0XB0);
    // mtc2        $4, $v21[6]
    rsp.MTC2<6>(r4, rsp.vpu.r[21]);
    // vsub        $v25, $v25, $v31
    rsp.VSUB<0>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[31]);
    // srl         $4, $25, 14
    r4 = S32(U32(r25) >> 14);
    // mtc2        $4, $v21[8]
    rsp.MTC2<8>(r4, rsp.vpu.r[21]);
    // addi        $4, $zero, 0x40
    r4 = RSP_ADD32(0, 0X40);
    // mtc2        $4, $v21[10]
    rsp.MTC2<10>(r4, rsp.vpu.r[21]);
    // vsub        $v25, $v25, $v31
    rsp.VSUB<0>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[31]);
    // lqv         $v30[0], 0x50($zero)
    rsp.LQV<0>(rsp.vpu.r[30], 0, 0X5);
    // lqv         $v29[0], 0x60($zero)
    rsp.LQV<0>(rsp.vpu.r[29], 0, 0X6);
    // lqv         $v28[0], 0x70($zero)
    rsp.LQV<0>(rsp.vpu.r[28], 0, 0X7);
    // vmudm       $v24, $v31, $v24[7]
    rsp.VMUDM<15>(rsp.vpu.r[24], rsp.vpu.r[31], rsp.vpu.r[24]);
    // lqv         $v27[0], 0x80($zero)
    rsp.LQV<0>(rsp.vpu.r[27], 0, 0X8);
    // vmadm       $v23, $v25, $v21[4]
    rsp.VMADM<12>(rsp.vpu.r[23], rsp.vpu.r[25], rsp.vpu.r[21]);
    // lqv         $v26[0], 0x90($zero)
    rsp.LQV<0>(rsp.vpu.r[26], 0, 0X9);
    // vmadn       $v24, $v31, $v30[0]
    rsp.VMADN<8>(rsp.vpu.r[24], rsp.vpu.r[31], rsp.vpu.r[30]);
    // sdv         $v19[0], 0x0($20)
    rsp.SDV<0>(rsp.vpu.r[19], r20, 0X0);
    // lqv         $v25[0], 0x30($zero)
    rsp.LQV<0>(rsp.vpu.r[25], 0, 0X3);
    // vmudn       $v22, $v31, $v21[2]
    rsp.VMUDN<10>(rsp.vpu.r[22], rsp.vpu.r[31], rsp.vpu.r[21]);
    // addi        $22, $zero, 0x170
    r22 = RSP_ADD32(0, 0X170);
    // vmadn       $v22, $v23, $v30[2]
    rsp.VMADN<10>(rsp.vpu.r[22], rsp.vpu.r[23], rsp.vpu.r[30]);
    // andi        $4, $25, 0x3
    r4 = r25 & 0X3;
    // vmudl       $v20, $v24, $v21[5]
    rsp.VMUDL<13>(rsp.vpu.r[20], rsp.vpu.r[24], rsp.vpu.r[21]);
    // beq         $4, $zero, L_18E8
    if (r4 == 0) {
        // addi        $23, $zero, 0x4F0
        r23 = RSP_ADD32(0, 0X4F0);
        goto L_18E8;
    }
    // addi        $23, $zero, 0x4F0
    r23 = RSP_ADD32(0, 0X4F0);
    // addi        $23, $zero, 0x660
    r23 = RSP_ADD32(0, 0X660);
L_18E8:
    // ssv         $v24[7], 0x8($24)
    rsp.SSV<7>(rsp.vpu.r[24], r24, 0X4);
    // vmudn       $v20, $v20, $v30[4]
    rsp.VMUDN<12>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[30]);
    // sqv         $v22[0], 0x7B0($zero)
    rsp.SQV<0>(rsp.vpu.r[22], 0, -0X5);
    // vmadn       $v20, $v31, $v21[3]
    rsp.VMADN<11>(rsp.vpu.r[20], rsp.vpu.r[31], rsp.vpu.r[21]);
    // sqv         $v20[0], 0x7C0($zero)
    rsp.SQV<0>(rsp.vpu.r[20], 0, -0X4);
    // lh          $21, 0xFB0($zero)
    r21 = RSP_MEM_H_LOAD(0XFB0, 0);
    // lh          $13, 0xFC0($zero)
    r13 = RSP_MEM_H_LOAD(0XFC0, 0);
    // lh          $17, 0xFB8($zero)
    r17 = RSP_MEM_H_LOAD(0XFB8, 0);
    // lh          $9, 0xFC8($zero)
    r9 = RSP_MEM_H_LOAD(0XFC8, 0);
    // lh          $20, 0xFB2($zero)
    r20 = RSP_MEM_H_LOAD(0XFB2, 0);
    // lh          $12, 0xFC2($zero)
    r12 = RSP_MEM_H_LOAD(0XFC2, 0);
    // lh          $16, 0xFBA($zero)
    r16 = RSP_MEM_H_LOAD(0XFBA, 0);
    // lh          $8, 0xFCA($zero)
    r8 = RSP_MEM_H_LOAD(0XFCA, 0);
    // lh          $19, 0xFB4($zero)
    r19 = RSP_MEM_H_LOAD(0XFB4, 0);
    // lh          $11, 0xFC4($zero)
    r11 = RSP_MEM_H_LOAD(0XFC4, 0);
    // lh          $15, 0xFBC($zero)
    r15 = RSP_MEM_H_LOAD(0XFBC, 0);
    // lh          $7, 0xFCC($zero)
    r7 = RSP_MEM_H_LOAD(0XFCC, 0);
    // lh          $18, 0xFB6($zero)
    r18 = RSP_MEM_H_LOAD(0XFB6, 0);
    // lh          $10, 0xFC6($zero)
    r10 = RSP_MEM_H_LOAD(0XFC6, 0);
    // lh          $14, 0xFBE($zero)
    r14 = RSP_MEM_H_LOAD(0XFBE, 0);
    // lh          $6, 0xFCE($zero)
    r6 = RSP_MEM_H_LOAD(0XFCE, 0);
L_193C:
    // ldv         $v19[0], 0x0($21)
    rsp.LDV<0>(rsp.vpu.r[19], r21, 0X0);
    // vmudm       $v24, $v31, $v24[7]
    rsp.VMUDM<15>(rsp.vpu.r[24], rsp.vpu.r[31], rsp.vpu.r[24]);
    // ldv         $v18[0], 0x0($13)
    rsp.LDV<0>(rsp.vpu.r[18], r13, 0X0);
    // vmadh       $v24, $v31, $v23[7]
    rsp.VMADH<15>(rsp.vpu.r[24], rsp.vpu.r[31], rsp.vpu.r[23]);
    // ldv         $v19[8], 0x0($17)
    rsp.LDV<8>(rsp.vpu.r[19], r17, 0X0);
    // vmadm       $v23, $v25, $v21[4]
    rsp.VMADM<12>(rsp.vpu.r[23], rsp.vpu.r[25], rsp.vpu.r[21]);
    // ldv         $v18[8], 0x0($9)
    rsp.LDV<8>(rsp.vpu.r[18], r9, 0X0);
    // vmadn       $v24, $v31, $v30[0]
    rsp.VMADN<8>(rsp.vpu.r[24], rsp.vpu.r[31], rsp.vpu.r[30]);
    // ldv         $v17[0], 0x0($20)
    rsp.LDV<0>(rsp.vpu.r[17], r20, 0X0);
    // vmudn       $v22, $v31, $v21[2]
    rsp.VMUDN<10>(rsp.vpu.r[22], rsp.vpu.r[31], rsp.vpu.r[21]);
    // ldv         $v16[0], 0x0($12)
    rsp.LDV<0>(rsp.vpu.r[16], r12, 0X0);
    // ldv         $v17[8], 0x0($16)
    rsp.LDV<8>(rsp.vpu.r[17], r16, 0X0);
    // vmadn       $v22, $v23, $v30[2]
    rsp.VMADN<10>(rsp.vpu.r[22], rsp.vpu.r[23], rsp.vpu.r[30]);
    // ldv         $v16[8], 0x0($8)
    rsp.LDV<8>(rsp.vpu.r[16], r8, 0X0);
    // vmudl       $v20, $v24, $v21[5]
    rsp.VMUDL<13>(rsp.vpu.r[20], rsp.vpu.r[24], rsp.vpu.r[21]);
    // ldv         $v15[0], 0x0($19)
    rsp.LDV<0>(rsp.vpu.r[15], r19, 0X0);
    // ldv         $v14[0], 0x0($11)
    rsp.LDV<0>(rsp.vpu.r[14], r11, 0X0);
    // ldv         $v15[8], 0x0($15)
    rsp.LDV<8>(rsp.vpu.r[15], r15, 0X0);
    // ldv         $v14[8], 0x0($7)
    rsp.LDV<8>(rsp.vpu.r[14], r7, 0X0);
    // vmudn       $v20, $v20, $v30[4]
    rsp.VMUDN<12>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[30]);
    // ldv         $v13[0], 0x0($18)
    rsp.LDV<0>(rsp.vpu.r[13], r18, 0X0);
    // vmadn       $v20, $v31, $v21[3]
    rsp.VMADN<11>(rsp.vpu.r[20], rsp.vpu.r[31], rsp.vpu.r[21]);
    // ldv         $v12[0], 0x0($10)
    rsp.LDV<0>(rsp.vpu.r[12], r10, 0X0);
    // ldv         $v13[8], 0x0($14)
    rsp.LDV<8>(rsp.vpu.r[13], r14, 0X0);
    // vmulf       $v11, $v19, $v18
    rsp.VMULF<0>(rsp.vpu.r[11], rsp.vpu.r[19], rsp.vpu.r[18]);
    // ldv         $v12[8], 0x0($6)
    rsp.LDV<8>(rsp.vpu.r[12], r6, 0X0);
    // vmulf       $v10, $v17, $v16
    rsp.VMULF<0>(rsp.vpu.r[10], rsp.vpu.r[17], rsp.vpu.r[16]);
    // sqv         $v22[0], 0x7B0($zero)
    rsp.SQV<0>(rsp.vpu.r[22], 0, -0X5);
    // vmulf       $v9, $v15, $v14
    rsp.VMULF<0>(rsp.vpu.r[9], rsp.vpu.r[15], rsp.vpu.r[14]);
    // sqv         $v20[0], 0x7C0($zero)
    rsp.SQV<0>(rsp.vpu.r[20], 0, -0X4);
    // lh          $21, 0xFB0($zero)
    r21 = RSP_MEM_H_LOAD(0XFB0, 0);
    // lh          $13, 0xFC0($zero)
    r13 = RSP_MEM_H_LOAD(0XFC0, 0);
    // vmulf       $v8, $v13, $v12
    rsp.VMULF<0>(rsp.vpu.r[8], rsp.vpu.r[13], rsp.vpu.r[12]);
    // lh          $17, 0xFB8($zero)
    r17 = RSP_MEM_H_LOAD(0XFB8, 0);
    // vadd        $v11, $v11, $v11[1q]
    rsp.VADD<3>(rsp.vpu.r[11], rsp.vpu.r[11], rsp.vpu.r[11]);
    // lh          $9, 0xFC8($zero)
    r9 = RSP_MEM_H_LOAD(0XFC8, 0);
    // vadd        $v10, $v10, $v10[1q]
    rsp.VADD<3>(rsp.vpu.r[10], rsp.vpu.r[10], rsp.vpu.r[10]);
    // lh          $20, 0xFB2($zero)
    r20 = RSP_MEM_H_LOAD(0XFB2, 0);
    // vadd        $v9, $v9, $v9[1q]
    rsp.VADD<3>(rsp.vpu.r[9], rsp.vpu.r[9], rsp.vpu.r[9]);
    // lh          $12, 0xFC2($zero)
    r12 = RSP_MEM_H_LOAD(0XFC2, 0);
    // vadd        $v8, $v8, $v8[1q]
    rsp.VADD<3>(rsp.vpu.r[8], rsp.vpu.r[8], rsp.vpu.r[8]);
    // lh          $16, 0xFBA($zero)
    r16 = RSP_MEM_H_LOAD(0XFBA, 0);
    // vadd        $v11, $v11, $v11[2h]
    rsp.VADD<6>(rsp.vpu.r[11], rsp.vpu.r[11], rsp.vpu.r[11]);
    // lh          $8, 0xFCA($zero)
    r8 = RSP_MEM_H_LOAD(0XFCA, 0);
    // vadd        $v10, $v10, $v10[2h]
    rsp.VADD<6>(rsp.vpu.r[10], rsp.vpu.r[10], rsp.vpu.r[10]);
    // lh          $19, 0xFB4($zero)
    r19 = RSP_MEM_H_LOAD(0XFB4, 0);
    // vadd        $v9, $v9, $v9[2h]
    rsp.VADD<6>(rsp.vpu.r[9], rsp.vpu.r[9], rsp.vpu.r[9]);
    // lh          $11, 0xFC4($zero)
    r11 = RSP_MEM_H_LOAD(0XFC4, 0);
    // vadd        $v8, $v8, $v8[2h]
    rsp.VADD<6>(rsp.vpu.r[8], rsp.vpu.r[8], rsp.vpu.r[8]);
    // lh          $15, 0xFBC($zero)
    r15 = RSP_MEM_H_LOAD(0XFBC, 0);
    // vmudn       $v7, $v29, $v11[0h]
    rsp.VMUDN<4>(rsp.vpu.r[7], rsp.vpu.r[29], rsp.vpu.r[11]);
    // lh          $7, 0xFCC($zero)
    r7 = RSP_MEM_H_LOAD(0XFCC, 0);
    // vmadn       $v7, $v28, $v10[0h]
    rsp.VMADN<4>(rsp.vpu.r[7], rsp.vpu.r[28], rsp.vpu.r[10]);
    // lh          $18, 0xFB6($zero)
    r18 = RSP_MEM_H_LOAD(0XFB6, 0);
    // vmadn       $v7, $v27, $v9[0h]
    rsp.VMADN<4>(rsp.vpu.r[7], rsp.vpu.r[27], rsp.vpu.r[9]);
    // lh          $10, 0xFC6($zero)
    r10 = RSP_MEM_H_LOAD(0XFC6, 0);
    // vmadn       $v7, $v26, $v8[0h]
    rsp.VMADN<4>(rsp.vpu.r[7], rsp.vpu.r[26], rsp.vpu.r[8]);
    // lh          $14, 0xFBE($zero)
    r14 = RSP_MEM_H_LOAD(0XFBE, 0);
    // lh          $6, 0xFCE($zero)
    r6 = RSP_MEM_H_LOAD(0XFCE, 0);
    // addi        $22, $22, -0x10
    r22 = RSP_ADD32(r22, -0X10);
    // blez        $22, L_1A3C
    if (RSP_SIGNED(r22) <= 0) {
        // sqv         $v7[0], 0x0($23)
        rsp.SQV<0>(rsp.vpu.r[7], r23, 0X0);
        goto L_1A3C;
    }
    // sqv         $v7[0], 0x0($23)
    rsp.SQV<0>(rsp.vpu.r[7], r23, 0X0);
    // j           L_193C
    // addi        $23, $23, 0x10
    r23 = RSP_ADD32(r23, 0X10);
    goto L_193C;
    // addi        $23, $23, 0x10
    r23 = RSP_ADD32(r23, 0X10);
L_1A3C:
    // ldv         $v19[0], 0x0($21)
    rsp.LDV<0>(rsp.vpu.r[19], r21, 0X0);
    // ssv         $v24[0], 0x8($24)
    rsp.SSV<0>(rsp.vpu.r[24], r24, 0X4);
    // jal         0x1174
    r31 = 0x1A4C;
    // sdv         $v19[0], 0x0($24)
    rsp.SDV<0>(rsp.vpu.r[19], r24, 0X0);
    goto L_1174;
    // sdv         $v19[0], 0x0($24)
    rsp.SDV<0>(rsp.vpu.r[19], r24, 0X0);
L_1A4C:
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_1A54:
    // bne         $5, $zero, L_1A54
    if (r5 != 0) {
        // mfc0        $5, SP_DMA_BUSY
        r5 = 0;
        goto L_1A54;
    }
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // j           L_10EC
    // mtc0        $zero, SP_SEMAPHORE
    goto L_10EC;
    // mtc0        $zero, SP_SEMAPHORE
L_1A64:
    // sll         $2, $25, 8
    r2 = S32(r25) << 8;
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
    // addi        $2, $2, 0x0
    r2 = RSP_ADD32(r2, 0X0);
    // lqv         $v31[0], 0x40($zero)
    rsp.LQV<0>(rsp.vpu.r[31], 0, 0X4);
    // lqv         $v10[0], 0x50($zero)
    rsp.LQV<0>(rsp.vpu.r[10], 0, 0X5);
    // lqv         $v30[0], 0xA0($zero)
    rsp.LQV<0>(rsp.vpu.r[30], 0, 0XA);
    // vxor        $v0, $v0, $v0
    rsp.VXOR<0>(rsp.vpu.r[0], rsp.vpu.r[0], rsp.vpu.r[0]);
    // srl         $14, $26, 16
    r14 = S32(U32(r26) >> 16);
    // andi        $15, $14, 0x1
    r15 = r14 & 0X1;
    // bgtz        $15, L_1AB8
    if (RSP_SIGNED(r15) > 0) {
        // addi        $1, $24, 0x0
        r1 = RSP_ADD32(r24, 0X0);
        goto L_1AB8;
    }
    // addi        $1, $24, 0x0
    r1 = RSP_ADD32(r24, 0X0);
    // jal         0x114C
    r31 = 0x1A98;
    // addi        $3, $zero, 0x4F
    r3 = RSP_ADD32(0, 0X4F);
    goto L_114C;
    // addi        $3, $zero, 0x4F
    r3 = RSP_ADD32(0, 0X4F);
L_1A98:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_1A9C:
    // bne         $5, $zero, L_1A9C
    if (r5 != 0) {
        // mfc0        $5, SP_DMA_BUSY
        r5 = 0;
        goto L_1A9C;
    }
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // mtc0        $zero, SP_SEMAPHORE
    // lqv         $v20[0], 0x0($24)
    rsp.LQV<0>(rsp.vpu.r[20], r24, 0X0);
    // lqv         $v21[0], 0x10($24)
    rsp.LQV<0>(rsp.vpu.r[21], r24, 0X1);
    // lqv         $v18[0], 0x20($24)
    rsp.LQV<0>(rsp.vpu.r[18], r24, 0X2);
    // lqv         $v19[0], 0x30($24)
    rsp.LQV<0>(rsp.vpu.r[19], r24, 0X3);
L_1AB8:
    // lqv         $v24[0], 0x40($24)
    rsp.LQV<0>(rsp.vpu.r[24], r24, 0X4);
    // addi        $16, $zero, 0x4F0
    r16 = RSP_ADD32(0, 0X4F0);
    // addi        $21, $zero, 0x9D0
    r21 = RSP_ADD32(0, 0X9D0);
    // addi        $20, $zero, 0xB40
    r20 = RSP_ADD32(0, 0XB40);
    // addi        $19, $zero, 0xCB0
    r19 = RSP_ADD32(0, 0XCB0);
    // addi        $18, $zero, 0xE20
    r18 = RSP_ADD32(0, 0XE20);
    // addi        $17, $zero, 0x170
    r17 = RSP_ADD32(0, 0X170);
    // mfc2        $22, $v24[8]
    rsp.MFC2<8>(r22, rsp.vpu.r[24]);
    // beq         $15, $zero, L_1BA8
    if (r15 == 0) {
        // mfc2        $23, $v24[2]
        rsp.MFC2<2>(r23, rsp.vpu.r[24]);
        goto L_1BA8;
    }
    // mfc2        $23, $v24[2]
    rsp.MFC2<2>(r23, rsp.vpu.r[24]);
    // addi        $3, $zero, 0x4F
    r3 = RSP_ADD32(0, 0X4F);
    // vxor        $v20, $v20, $v20
    rsp.VXOR<0>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[20]);
    // lsv         $v20[14], 0x50($24)
    rsp.LSV<14>(rsp.vpu.r[20], r24, 0X28);
    // vxor        $v21, $v21, $v21
    rsp.VXOR<0>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[21]);
    // lqv         $v17[0], 0x0($16)
    rsp.LQV<0>(rsp.vpu.r[17], r16, 0X0);
    // vxor        $v18, $v18, $v18
    rsp.VXOR<0>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[18]);
    // mtc2        $26, $v18[14]
    rsp.MTC2<14>(r26, rsp.vpu.r[18]);
    // vmudl       $v23, $v30, $v24[2]
    rsp.VMUDL<10>(rsp.vpu.r[23], rsp.vpu.r[30], rsp.vpu.r[24]);
    // lqv         $v29[0], 0x0($21)
    rsp.LQV<0>(rsp.vpu.r[29], r21, 0X0);
    // vmadn       $v23, $v30, $v24[1]
    rsp.VMADN<9>(rsp.vpu.r[23], rsp.vpu.r[30], rsp.vpu.r[24]);
    // lqv         $v27[0], 0x0($19)
    rsp.LQV<0>(rsp.vpu.r[27], r19, 0X0);
    // vmadh       $v20, $v31, $v20[7]
    rsp.VMADH<15>(rsp.vpu.r[20], rsp.vpu.r[31], rsp.vpu.r[20]);
    // lqv         $v28[0], 0x0($20)
    rsp.LQV<0>(rsp.vpu.r[28], r20, 0X0);
    // vmadn       $v21, $v31, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[21], rsp.vpu.r[31], rsp.vpu.r[0]);
    // bgez        $23, L_1B28
    if (RSP_SIGNED(r23) >= 0) {
        // vxor        $v19, $v19, $v19
        rsp.VXOR<0>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[19]);
        goto L_1B28;
    }
    // vxor        $v19, $v19, $v19
    rsp.VXOR<0>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[19]);
    // j           L_1B2C
    // vge         $v20, $v20, $v24[0]
    rsp.VGE<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
    goto L_1B2C;
    // vge         $v20, $v20, $v24[0]
    rsp.VGE<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
L_1B28:
    // vlt         $v20, $v20, $v24[0]
    rsp.VLT<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
L_1B2C:
    // vmudl       $v23, $v30, $v24[5]
    rsp.VMUDL<13>(rsp.vpu.r[23], rsp.vpu.r[30], rsp.vpu.r[24]);
    // lqv         $v26[0], 0x0($18)
    rsp.LQV<0>(rsp.vpu.r[26], r18, 0X0);
    // vmadn       $v23, $v30, $v24[4]
    rsp.VMADN<12>(rsp.vpu.r[23], rsp.vpu.r[30], rsp.vpu.r[24]);
    // addi        $17, $17, -0x10
    r17 = RSP_ADD32(r17, -0X10);
    // vmadh       $v18, $v31, $v18[7]
    rsp.VMADH<15>(rsp.vpu.r[18], rsp.vpu.r[31], rsp.vpu.r[18]);
    // addi        $16, $16, 0x10
    r16 = RSP_ADD32(r16, 0X10);
    // vmadn       $v19, $v31, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[19], rsp.vpu.r[31], rsp.vpu.r[0]);
    // vmulf       $v16, $v20, $v24[6]
    rsp.VMULF<14>(rsp.vpu.r[16], rsp.vpu.r[20], rsp.vpu.r[24]);
    // bgez        $22, L_1B5C
    if (RSP_SIGNED(r22) >= 0) {
        // vmulf       $v15, $v20, $v24[7]
        rsp.VMULF<15>(rsp.vpu.r[15], rsp.vpu.r[20], rsp.vpu.r[24]);
        goto L_1B5C;
    }
    // vmulf       $v15, $v20, $v24[7]
    rsp.VMULF<15>(rsp.vpu.r[15], rsp.vpu.r[20], rsp.vpu.r[24]);
    // j           L_1B60
    // vge         $v18, $v18, $v24[3]
    rsp.VGE<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
    goto L_1B60;
    // vge         $v18, $v18, $v24[3]
    rsp.VGE<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
L_1B5C:
    // vlt         $v18, $v18, $v24[3]
    rsp.VLT<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
L_1B60:
    // vmulf       $v29, $v29, $v10[5]
    rsp.VMULF<13>(rsp.vpu.r[29], rsp.vpu.r[29], rsp.vpu.r[10]);
    // vmacf       $v29, $v17, $v16
    rsp.VMACF<0>(rsp.vpu.r[29], rsp.vpu.r[17], rsp.vpu.r[16]);
    // vmulf       $v27, $v27, $v10[5]
    rsp.VMULF<13>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[10]);
    // vmacf       $v27, $v17, $v15
    rsp.VMACF<0>(rsp.vpu.r[27], rsp.vpu.r[17], rsp.vpu.r[15]);
    // vmulf       $v16, $v18, $v24[6]
    rsp.VMULF<14>(rsp.vpu.r[16], rsp.vpu.r[18], rsp.vpu.r[24]);
    // vmulf       $v15, $v18, $v24[7]
    rsp.VMULF<15>(rsp.vpu.r[15], rsp.vpu.r[18], rsp.vpu.r[24]);
    // sqv         $v29[0], 0x0($21)
    rsp.SQV<0>(rsp.vpu.r[29], r21, 0X0);
    // vmulf       $v28, $v28, $v10[5]
    rsp.VMULF<13>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[10]);
    // addi        $21, $21, 0x10
    r21 = RSP_ADD32(r21, 0X10);
    // vmacf       $v28, $v17, $v16
    rsp.VMACF<0>(rsp.vpu.r[28], rsp.vpu.r[17], rsp.vpu.r[16]);
    // sqv         $v27[0], 0x0($19)
    rsp.SQV<0>(rsp.vpu.r[27], r19, 0X0);
    // vmulf       $v26, $v26, $v10[5]
    rsp.VMULF<13>(rsp.vpu.r[26], rsp.vpu.r[26], rsp.vpu.r[10]);
    // addi        $19, $19, 0x10
    r19 = RSP_ADD32(r19, 0X10);
    // vmacf       $v26, $v17, $v15
    rsp.VMACF<0>(rsp.vpu.r[26], rsp.vpu.r[17], rsp.vpu.r[15]);
    // sqv         $v28[0], 0x0($20)
    rsp.SQV<0>(rsp.vpu.r[28], r20, 0X0);
    // addi        $20, $20, 0x10
    r20 = RSP_ADD32(r20, 0X10);
    // sqv         $v26[0], 0x0($18)
    rsp.SQV<0>(rsp.vpu.r[26], r18, 0X0);
    // addi        $18, $18, 0x10
    r18 = RSP_ADD32(r18, 0X10);
L_1BA8:
    // vaddc       $v21, $v21, $v24[2]
    rsp.VADDC<10>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[24]);
    // vadd        $v20, $v20, $v24[1]
    rsp.VADD<9>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
L_1BB0:
    // lqv         $v29[0], 0x0($21)
    rsp.LQV<0>(rsp.vpu.r[29], r21, 0X0);
    // vaddc       $v19, $v19, $v24[5]
    rsp.VADDC<13>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[24]);
    // lqv         $v17[0], 0x0($16)
    rsp.LQV<0>(rsp.vpu.r[17], r16, 0X0);
    // bgez        $23, L_1BCC
    if (RSP_SIGNED(r23) >= 0) {
        // vadd        $v18, $v18, $v24[4]
        rsp.VADD<12>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
        goto L_1BCC;
    }
    // vadd        $v18, $v18, $v24[4]
    rsp.VADD<12>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
    // j           L_1BD0
    // vge         $v20, $v20, $v24[0]
    rsp.VGE<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
    goto L_1BD0;
    // vge         $v20, $v20, $v24[0]
    rsp.VGE<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
L_1BCC:
    // vlt         $v20, $v20, $v24[0]
    rsp.VLT<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
L_1BD0:
    // bgez        $22, L_1BE0
    if (RSP_SIGNED(r22) >= 0) {
        // lqv         $v27[0], 0x0($19)
        rsp.LQV<0>(rsp.vpu.r[27], r19, 0X0);
        goto L_1BE0;
    }
    // lqv         $v27[0], 0x0($19)
    rsp.LQV<0>(rsp.vpu.r[27], r19, 0X0);
    // j           L_1BE4
    // vge         $v18, $v18, $v24[3]
    rsp.VGE<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
    goto L_1BE4;
    // vge         $v18, $v18, $v24[3]
    rsp.VGE<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
L_1BE0:
    // vlt         $v18, $v18, $v24[3]
    rsp.VLT<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
L_1BE4:
    // vmulf       $v16, $v20, $v24[6]
    rsp.VMULF<14>(rsp.vpu.r[16], rsp.vpu.r[20], rsp.vpu.r[24]);
    // sqv         $v20[0], 0x0($24)
    rsp.SQV<0>(rsp.vpu.r[20], r24, 0X0);
    // vmulf       $v15, $v20, $v24[7]
    rsp.VMULF<15>(rsp.vpu.r[15], rsp.vpu.r[20], rsp.vpu.r[24]);
    // sqv         $v21[0], 0x10($24)
    rsp.SQV<0>(rsp.vpu.r[21], r24, 0X1);
    // vmulf       $v29, $v29, $v10[5]
    rsp.VMULF<13>(rsp.vpu.r[29], rsp.vpu.r[29], rsp.vpu.r[10]);
    // vmacf       $v29, $v17, $v16
    rsp.VMACF<0>(rsp.vpu.r[29], rsp.vpu.r[17], rsp.vpu.r[16]);
    // lqv         $v28[0], 0x0($20)
    rsp.LQV<0>(rsp.vpu.r[28], r20, 0X0);
    // vmulf       $v27, $v27, $v10[5]
    rsp.VMULF<13>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[10]);
    // lqv         $v26[0], 0x0($18)
    rsp.LQV<0>(rsp.vpu.r[26], r18, 0X0);
    // vmacf       $v27, $v17, $v15
    rsp.VMACF<0>(rsp.vpu.r[27], rsp.vpu.r[17], rsp.vpu.r[15]);
    // addi        $17, $17, -0x10
    r17 = RSP_ADD32(r17, -0X10);
    // vaddc       $v21, $v21, $v24[2]
    rsp.VADDC<10>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[24]);
    // addi        $16, $16, 0x10
    r16 = RSP_ADD32(r16, 0X10);
    // vadd        $v20, $v20, $v24[1]
    rsp.VADD<9>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
    // sqv         $v29[0], 0x0($21)
    rsp.SQV<0>(rsp.vpu.r[29], r21, 0X0);
    // vmulf       $v16, $v18, $v24[6]
    rsp.VMULF<14>(rsp.vpu.r[16], rsp.vpu.r[18], rsp.vpu.r[24]);
    // addi        $21, $21, 0x10
    r21 = RSP_ADD32(r21, 0X10);
    // vmulf       $v15, $v18, $v24[7]
    rsp.VMULF<15>(rsp.vpu.r[15], rsp.vpu.r[18], rsp.vpu.r[24]);
    // sqv         $v27[0], 0x0($19)
    rsp.SQV<0>(rsp.vpu.r[27], r19, 0X0);
    // vmulf       $v28, $v28, $v10[5]
    rsp.VMULF<13>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[10]);
    // addi        $19, $19, 0x10
    r19 = RSP_ADD32(r19, 0X10);
    // vmacf       $v28, $v17, $v16
    rsp.VMACF<0>(rsp.vpu.r[28], rsp.vpu.r[17], rsp.vpu.r[16]);
    // vmulf       $v26, $v26, $v10[5]
    rsp.VMULF<13>(rsp.vpu.r[26], rsp.vpu.r[26], rsp.vpu.r[10]);
    // vmacf       $v26, $v17, $v15
    rsp.VMACF<0>(rsp.vpu.r[26], rsp.vpu.r[17], rsp.vpu.r[15]);
    // sqv         $v28[0], 0x0($20)
    rsp.SQV<0>(rsp.vpu.r[28], r20, 0X0);
    // addi        $20, $20, 0x10
    r20 = RSP_ADD32(r20, 0X10);
    // blez        $17, L_1C5C
    if (RSP_SIGNED(r17) <= 0) {
        // sqv         $v26[0], 0x0($18)
        rsp.SQV<0>(rsp.vpu.r[26], r18, 0X0);
        goto L_1C5C;
    }
    // sqv         $v26[0], 0x0($18)
    rsp.SQV<0>(rsp.vpu.r[26], r18, 0X0);
    // j           L_1BB0
    // addi        $18, $18, 0x10
    r18 = RSP_ADD32(r18, 0X10);
    goto L_1BB0;
    // addi        $18, $18, 0x10
    r18 = RSP_ADD32(r18, 0X10);
L_1C5C:
    // sqv         $v18[0], 0x20($24)
    rsp.SQV<0>(rsp.vpu.r[18], r24, 0X2);
    // sqv         $v19[0], 0x30($24)
    rsp.SQV<0>(rsp.vpu.r[19], r24, 0X3);
    // jal         0x1174
    r31 = 0x1C6C;
    // sqv         $v24[0], 0x40($24)
    rsp.SQV<0>(rsp.vpu.r[24], r24, 0X4);
    goto L_1174;
    // sqv         $v24[0], 0x40($24)
    rsp.SQV<0>(rsp.vpu.r[24], r24, 0X4);
L_1C6C:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_1C70:
    // bne         $5, $zero, L_1C70
    if (r5 != 0) {
        // mfc0        $5, SP_DMA_BUSY
        r5 = 0;
        goto L_1C70;
    }
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // mtc0        $zero, SP_SEMAPHORE
    // j           L_10EC
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    goto L_10EC;
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
L_1C84:
    // lqv         $v31[0], 0x50($zero)
    rsp.LQV<0>(rsp.vpu.r[31], 0, 0X5);
    // andi        $22, $25, 0xFFFF
    r22 = r25 & 0XFFFF;
    // addi        $22, $22, 0x4F0
    r22 = RSP_ADD32(r22, 0X4F0);
    // lqv         $v28[0], 0x0($22)
    rsp.LQV<0>(rsp.vpu.r[28], r22, 0X0);
    // srl         $23, $25, 16
    r23 = S32(U32(r25) >> 16);
    // addi        $23, $23, 0x4F0
    r23 = RSP_ADD32(r23, 0X4F0);
    // lqv         $v29[0], 0x0($23)
    rsp.LQV<0>(rsp.vpu.r[29], r23, 0X0);
    // mtc2        $26, $v30[0]
    rsp.MTC2<0>(r26, rsp.vpu.r[30]);
    // addi        $21, $zero, 0x170
    r21 = RSP_ADD32(0, 0X170);
L_1CA8:
    // vmulf       $v27, $v28, $v31[5]
    rsp.VMULF<13>(rsp.vpu.r[27], rsp.vpu.r[28], rsp.vpu.r[31]);
    // addi        $21, $21, -0x10
    r21 = RSP_ADD32(r21, -0X10);
    // addi        $23, $23, 0x10
    r23 = RSP_ADD32(r23, 0X10);
    // addi        $22, $22, 0x10
    r22 = RSP_ADD32(r22, 0X10);
    // vmacf       $v27, $v29, $v30[0]
    rsp.VMACF<8>(rsp.vpu.r[27], rsp.vpu.r[29], rsp.vpu.r[30]);
    // lqv         $v28[0], 0x0($22)
    rsp.LQV<0>(rsp.vpu.r[28], r22, 0X0);
    // lqv         $v29[0], 0x0($23)
    rsp.LQV<0>(rsp.vpu.r[29], r23, 0X0);
    // bgtz        $21, L_1CA8
    if (RSP_SIGNED(r21) > 0) {
        // sqv         $v27[0], 0x7F0($22)
        rsp.SQV<0>(rsp.vpu.r[27], r22, -0X1);
        goto L_1CA8;
    }
    // sqv         $v27[0], 0x7F0($22)
    rsp.SQV<0>(rsp.vpu.r[27], r22, -0X1);
    // j           L_10EC
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    goto L_10EC;
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    // nop

    // nop

    // nop

    return RspExitReason::ImemOverrun;
do_indirect_jump:
    switch ((jump_target | 0x1000) & 0X1FFF) { 
        case 0x1C6C: goto L_1C6C;
        case 0x10B8: goto L_10B8;
        case 0x11F4: goto L_11F4;
        case 0x1104: goto L_1104;
        case 0x1144: goto L_1144;
        case 0x1640: goto L_1640;
        case 0x1264: goto L_1264;
        case 0x1A4C: goto L_1A4C;
        case 0x1234: goto L_1234;
        case 0x17D4: goto L_17D4;
        case 0x12B0: goto L_12B0;
        case 0x1A98: goto L_1A98;
        case 0x10EC: goto L_10EC;
        case 0x139C: goto L_139C;
        case 0x119C: goto L_119C;
        case 0x127C: goto L_127C;
        case 0x1A64: goto L_1A64;
        case 0x11C8: goto L_11C8;
        case 0x17EC: goto L_17EC;
        case 0x1248: goto L_1248;
        case 0x1208: goto L_1208;
        case 0x1348: goto L_1348;
        case 0x1C84: goto L_1C84;
        case 0x12D4: goto L_12D4;
        case 0x1384: goto L_1384;
    }
    printf("Unhandled jump target 0x%04X in microcode n_aspMain, coming from [%s:%d]\n", jump_target, debug_file, debug_line);
    printf("Register dump: r0  = %08X r1  = %08X r2  = %08X r3  = %08X r4  = %08X r5  = %08X r6  = %08X r7  = %08X\n"
           "               r8  = %08X r9  = %08X r10 = %08X r11 = %08X r12 = %08X r13 = %08X r14 = %08X r15 = %08X\n"
           "               r16 = %08X r17 = %08X r18 = %08X r19 = %08X r20 = %08X r21 = %08X r22 = %08X r23 = %08X\n"
           "               r24 = %08X r25 = %08X r26 = %08X r27 = %08X r28 = %08X r29 = %08X r30 = %08X r31 = %08X\n",
           0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15, r16,
           r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r29, r30, r31);
    return RspExitReason::UnhandledJumpTarget;
}
