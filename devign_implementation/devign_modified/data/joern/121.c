static void vc1_inv_trans_8x8_dc_c(uint8_t *dest, int linesize, DCTELEM *block)

{

    int i;

    int dc = block[0];

    const uint8_t *cm;

    dc = (3 * dc +  1) >> 1;

    dc = (3 * dc + 16) >> 5;

    cm = ff_cropTbl + MAX_NEG_CROP + dc;

    for(i = 0; i < 8; i++){

        dest[0] = cm[dest[0]];

        dest[1] = cm[dest[1]];

        dest[2] = cm[dest[2]];

        dest[3] = cm[dest[3]];

        dest[4] = cm[dest[4]];

        dest[5] = cm[dest[5]];

        dest[6] = cm[dest[6]];

        dest[7] = cm[dest[7]];

        dest += linesize;

    }

}
