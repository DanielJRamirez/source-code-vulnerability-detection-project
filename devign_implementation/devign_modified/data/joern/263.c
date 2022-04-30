static int bgr24ToYv12Wrapper(SwsContext *c, const uint8_t *src[],

                              int srcStride[], int srcSliceY, int srcSliceH,

                              uint8_t *dst[], int dstStride[])

{

    rgb24toyv12(

        src[0],

        dst[0] +  srcSliceY       * dstStride[0],

        dst[1] + (srcSliceY >> 1) * dstStride[1],

        dst[2] + (srcSliceY >> 1) * dstStride[2],

        c->srcW, srcSliceH,

        dstStride[0], dstStride[1], srcStride[0]);

    if (dst[3])

        fillPlane(dst[3], dstStride[3], c->srcW, srcSliceH, srcSliceY, 255);

    return srcSliceH;

}
