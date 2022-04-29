av_cold int ff_ivi_decode_close(AVCodecContext *avctx)

{

    IVI45DecContext *ctx = avctx->priv_data;



    ivi_free_buffers(&ctx->planes[0]);



    if (ctx->mb_vlc.cust_tab.table)

        ff_free_vlc(&ctx->mb_vlc.cust_tab);



#if IVI4_STREAM_ANALYSER

    if (ctx->is_indeo4) {

    if (ctx->is_scalable)

        av_log(avctx, AV_LOG_ERROR, "This video uses scalability mode!\n");

    if (ctx->uses_tiling)

        av_log(avctx, AV_LOG_ERROR, "This video uses local decoding!\n");

    if (ctx->has_b_frames)

        av_log(avctx, AV_LOG_ERROR, "This video contains B-frames!\n");

    if (ctx->has_transp)

        av_log(avctx, AV_LOG_ERROR, "Transparency mode is enabled!\n");

    if (ctx->uses_haar)

        av_log(avctx, AV_LOG_ERROR, "This video uses Haar transform!\n");

    if (ctx->uses_fullpel)

        av_log(avctx, AV_LOG_ERROR, "This video uses fullpel motion vectors!\n");

    }

#endif



    av_frame_free(&ctx->p_frame);



    return 0;

}
