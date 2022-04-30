static av_cold int hevc_init_context(AVCodecContext *avctx)
{
    HEVCContext *s = avctx->priv_data;
    int i;
    s->avctx = avctx;
    s->HEVClc = av_mallocz(sizeof(HEVCLocalContext));
    if (!s->HEVClc)
        goto fail;
    s->HEVClcList[0] = s->HEVClc;
    s->sList[0] = s;
    s->cabac_state = av_malloc(HEVC_CONTEXTS);
    if (!s->cabac_state)
        goto fail;
    s->output_frame = av_frame_alloc();
    if (!s->output_frame)
        goto fail;
    for (i = 0; i < FF_ARRAY_ELEMS(s->DPB); i++) {
        s->DPB[i].frame = av_frame_alloc();
        if (!s->DPB[i].frame)
            goto fail;
        s->DPB[i].tf.f = s->DPB[i].frame;
    }
    s->max_ra = INT_MAX;
    s->md5_ctx = av_md5_alloc();
    if (!s->md5_ctx)
        goto fail;
    ff_bswapdsp_init(&s->bdsp);
    s->context_initialized = 1;
    s->eos = 0;
    return 0;
fail:
    hevc_decode_free(avctx);
    return AVERROR(ENOMEM);
}