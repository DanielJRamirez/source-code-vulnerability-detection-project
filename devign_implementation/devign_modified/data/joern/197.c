int av_buffersink_get_frame(AVFilterContext *ctx, AVFrame *frame)

{

    BufferSinkContext *s    = ctx->priv;

    AVFilterLink      *link = ctx->inputs[0];

    int ret;



    if ((ret = ff_request_frame(link)) < 0)

        return ret;



    if (!s->cur_frame)

        return AVERROR(EINVAL);



    av_frame_move_ref(frame, s->cur_frame);

    av_frame_free(&s->cur_frame);



    return 0;

}
