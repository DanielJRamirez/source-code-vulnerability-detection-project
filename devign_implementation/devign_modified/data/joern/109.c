static void RENAME(yuv2yuyv422_2)(SwsContext *c, const uint16_t *buf0,

                                  const uint16_t *buf1, const uint16_t *ubuf0,

                                  const uint16_t *ubuf1, const uint16_t *vbuf0,

                                  const uint16_t *vbuf1, const uint16_t *abuf0,

                                  const uint16_t *abuf1, uint8_t *dest,

                                  int dstW, int yalpha, int uvalpha, int y)

{

    //Note 8280 == DSTW_OFFSET but the preprocessor can't handle that there :(

    __asm__ volatile(

        "mov %%"REG_b", "ESP_OFFSET"(%5)        \n\t"

        "mov %4, %%"REG_b"                        \n\t"

        "push %%"REG_BP"                        \n\t"

        YSCALEYUV2PACKED(%%REGBP, %5)

        WRITEYUY2(%%REGb, 8280(%5), %%REGBP)

        "pop %%"REG_BP"                         \n\t"

        "mov "ESP_OFFSET"(%5), %%"REG_b"        \n\t"

        :: "c" (buf0), "d" (buf1), "S" (ubuf0), "D" (ubuf1), "m" (dest),

           "a" (&c->redDither)

    );

}
