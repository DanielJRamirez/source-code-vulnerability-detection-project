int ff_nvdec_start_frame(AVCodecContext *avctx, AVFrame *frame)

{

    NVDECContext *ctx = avctx->internal->hwaccel_priv_data;

    FrameDecodeData *fdd = (FrameDecodeData*)frame->private_ref->data;

    NVDECFrame *cf = NULL;

    int ret;



    ctx->bitstream_len = 0;

    ctx->nb_slices     = 0;



    if (fdd->hwaccel_priv)

        return 0;



    cf = av_mallocz(sizeof(*cf));

    if (!cf)

        return AVERROR(ENOMEM);



    cf->decoder_ref = av_buffer_ref(ctx->decoder_ref);

    if (!cf->decoder_ref)

        goto fail;



    cf->idx_ref = av_buffer_pool_get(ctx->decoder_pool);

    if (!cf->idx_ref) {

        av_log(avctx, AV_LOG_ERROR, "No decoder surfaces left\n");

        ret = AVERROR(ENOMEM);

        goto fail;

    }

    cf->idx = *(unsigned int*)cf->idx_ref->data;



    fdd->hwaccel_priv      = cf;

    fdd->hwaccel_priv_free = nvdec_fdd_priv_free;

    fdd->post_process      = nvdec_retrieve_data;



    return 0;

fail:

    nvdec_fdd_priv_free(cf);

    return ret;



}
