static int decode_plte_chunk(AVCodecContext *avctx, PNGDecContext *s,

                             uint32_t length)

{

    int n, i, r, g, b;



    if ((length % 3) != 0 || length > 256 * 3)

        return AVERROR_INVALIDDATA;

    /* read the palette */

    n = length / 3;

    for (i = 0; i < n; i++) {

        r = bytestream2_get_byte(&s->gb);

        g = bytestream2_get_byte(&s->gb);

        b = bytestream2_get_byte(&s->gb);

        s->palette[i] = (0xFFU << 24) | (r << 16) | (g << 8) | b;

    }

    for (; i < 256; i++)

        s->palette[i] = (0xFFU << 24);

    s->state |= PNG_PLTE;

    bytestream2_skip(&s->gb, 4);     /* crc */



    return 0;

}
