static int nut_write_trailer(AVFormatContext *s)

{

    NUTContext *nut = s->priv_data;

    AVIOContext *bc = s->pb, *dyn_bc;

    int i, ret;



    while (nut->header_count < 3)

        write_headers(s, bc);



    ret = avio_open_dyn_buf(&dyn_bc);

    if (ret >= 0 && nut->sp_count) {

        av_assert1(nut->write_index);

        write_index(nut, dyn_bc);

        put_packet(nut, bc, dyn_bc, 1, INDEX_STARTCODE);

    }



    ff_nut_free_sp(nut);

    for (i=0; i<s->nb_streams; i++)

        av_freep(&nut->stream[i].keyframe_pts);



    av_freep(&nut->stream);

    av_freep(&nut->chapter);

    av_freep(&nut->time_base);



    return 0;

}
