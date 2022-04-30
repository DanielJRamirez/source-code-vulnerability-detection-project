static av_cold int encode_close(AVCodecContext* avc_context)

{

    TheoraContext *h = avc_context->priv_data;



    th_encode_free(h->t_state);

    av_freep(&h->stats);

    av_freep(&avc_context->coded_frame);

    av_freep(&avc_context->stats_out);

    av_freep(&avc_context->extradata);

    avc_context->extradata_size = 0;



    return 0;

}
