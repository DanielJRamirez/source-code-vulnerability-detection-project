static int process_frame(FFFrameSync *fs)

{

    AVFilterContext *ctx = fs->parent;

    LUT2Context *s = fs->opaque;

    AVFilterLink *outlink = ctx->outputs[0];

    AVFrame *out, *srcx, *srcy;

    int ret;



    if ((ret = ff_framesync2_get_frame(&s->fs, 0, &srcx, 0)) < 0 ||

        (ret = ff_framesync2_get_frame(&s->fs, 1, &srcy, 0)) < 0)

        return ret;



    if (ctx->is_disabled) {

        out = av_frame_clone(srcx);

        if (!out)

            return AVERROR(ENOMEM);

    } else {

        out = ff_get_video_buffer(outlink, outlink->w, outlink->h);

        if (!out)

            return AVERROR(ENOMEM);

        av_frame_copy_props(out, srcx);



        s->lut2(s, out, srcx, srcy);

    }



    out->pts = av_rescale_q(s->fs.pts, s->fs.time_base, outlink->time_base);



    return ff_filter_frame(outlink, out);

}
