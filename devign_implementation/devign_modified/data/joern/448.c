void ff_decode_dxt1(const uint8_t *s, uint8_t *dst,

                    const unsigned int w, const unsigned int h,

                    const unsigned int stride) {

    unsigned int bx, by, qstride = stride/4;

    uint32_t *d = (uint32_t *) dst;



    for (by=0; by < h/4; by++, d += stride-w)

        for (bx=0; bx < w/4; bx++, s+=8, d+=4)

            dxt1_decode_pixels(s, d, qstride, 0, 0LL);

}
