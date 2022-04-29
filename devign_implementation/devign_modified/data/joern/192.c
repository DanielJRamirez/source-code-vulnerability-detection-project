static int expand_rle_row16(SgiState *s, uint16_t *out_buf,

                            int len, int pixelstride)

{

    unsigned short pixel;

    unsigned char count;

    unsigned short *orig = out_buf;

    uint16_t *out_end = out_buf + len;



    while (out_buf < out_end) {

        if (bytestream2_get_bytes_left(&s->g) < 2)

            return AVERROR_INVALIDDATA;

        pixel = bytestream2_get_be16u(&s->g);

        if (!(count = (pixel & 0x7f)))

            break;



        /* Check for buffer overflow. */

        if (pixelstride * (count - 1) >= len) {

            av_log(s->avctx, AV_LOG_ERROR, "Invalid pixel count.\n");

            return AVERROR_INVALIDDATA;

        }



        if (pixel & 0x80) {

            while (count--) {

                pixel = bytestream2_get_ne16(&s->g);

                AV_WN16A(out_buf, pixel);

                out_buf += pixelstride;

            }

        } else {

            pixel = bytestream2_get_ne16(&s->g);



            while (count--) {

                AV_WN16A(out_buf, pixel);

                out_buf += pixelstride;

            }

        }

    }

    return (out_buf - orig) / pixelstride;

}
