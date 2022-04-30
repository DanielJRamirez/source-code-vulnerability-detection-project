int av_packet_ref(AVPacket *dst, AVPacket *src)

{

    int ret;



    ret = av_packet_copy_props(dst, src);

    if (ret < 0)

        return ret;



    if (!src->buf) {

        ret = packet_alloc(&dst->buf, src->size);

        if (ret < 0)

            goto fail;

        memcpy(dst->buf->data, src->data, src->size);

    } else

        dst->buf = av_buffer_ref(src->buf);



    dst->size = src->size;

    dst->data = dst->buf->data;

    return 0;

fail:

    av_packet_free_side_data(dst);

    return ret;

}
