static void avc_luma_mid_and_aver_dst_16x16_msa(const uint8_t *src,

                                                int32_t src_stride,

                                                uint8_t *dst,

                                                int32_t dst_stride)

{

    avc_luma_mid_and_aver_dst_8w_msa(src, src_stride, dst, dst_stride, 16);

    avc_luma_mid_and_aver_dst_8w_msa(src + 8, src_stride, dst + 8, dst_stride,

                                     16);

}
