static int r3d_read_rdvo(AVFormatContext *s, Atom *atom)

{

    R3DContext *r3d = s->priv_data;

    AVStream *st = s->streams[0];

    int i;



    r3d->video_offsets_count = (atom->size - 8) / 4;

    r3d->video_offsets = av_malloc(atom->size);

    if (!r3d->video_offsets)

        return AVERROR(ENOMEM);



    for (i = 0; i < r3d->video_offsets_count; i++) {

        r3d->video_offsets[i] = avio_rb32(s->pb);

        if (!r3d->video_offsets[i]) {

            r3d->video_offsets_count = i;

            break;

        }

        av_dlog(s, "video offset %d: %#x\n", i, r3d->video_offsets[i]);

    }



    if (st->r_frame_rate.num)

        st->duration = av_rescale_q(r3d->video_offsets_count,

                                    (AVRational){st->r_frame_rate.den,

                                                 st->r_frame_rate.num},

                                    st->time_base);

    av_dlog(s, "duration %"PRId64"\n", st->duration);



    return 0;

}
