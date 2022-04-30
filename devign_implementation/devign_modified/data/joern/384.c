static AVFilterBufferRef *copy_buffer_ref(AVFilterContext *ctx,

                                          AVFilterBufferRef *ref)

{

    AVFilterLink *outlink = ctx->outputs[0];

    AVFilterBufferRef *buf;

    int channels, data_size, i;



    switch (outlink->type) {



    case AVMEDIA_TYPE_VIDEO:

        buf = avfilter_get_video_buffer(outlink, AV_PERM_WRITE,

                                        ref->video->w, ref->video->h);



        av_image_copy(buf->data, buf->linesize,

                      (void*)ref->data, ref->linesize,

                      ref->format, ref->video->w, ref->video->h);

        break;



    case AVMEDIA_TYPE_AUDIO:

        buf = ff_get_audio_buffer(outlink, AV_PERM_WRITE,

                                        ref->audio->nb_samples);



        channels = av_get_channel_layout_nb_channels(ref->audio->channel_layout);

        av_samples_copy(buf->extended_data, ref->buf->extended_data,

                        0, 0, ref->audio->nb_samples,

                        channels,

                        ref->format);

        break;



    default:


    }

    avfilter_copy_buffer_ref_props(buf, ref);

    return buf;

}