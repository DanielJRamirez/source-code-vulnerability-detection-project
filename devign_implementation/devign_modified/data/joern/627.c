static void raw_decode(uint8_t *dst, const int8_t *src, int src_size)

{

    while (src_size--)

        *dst++ = *src++ + 128;

}
