void ff_put_h264_qpel16_mc31_msa(uint8_t *dst, const uint8_t *src,

                                 ptrdiff_t stride)

{

    avc_luma_hv_qrt_16w_msa(src - 2,

                            src - (stride * 2) +

                            sizeof(uint8_t), stride, dst, stride, 16);

}
