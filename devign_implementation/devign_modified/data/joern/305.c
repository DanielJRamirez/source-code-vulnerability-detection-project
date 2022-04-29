static int mov_read_strf(MOVContext *c, AVIOContext *pb, MOVAtom atom)

{

    AVStream *st;



    if (c->fc->nb_streams < 1)

        return 0;

    if (atom.size <= 40)

        return 0;

    st = c->fc->streams[c->fc->nb_streams-1];



    if ((uint64_t)atom.size > (1<<30))

        return AVERROR_INVALIDDATA;



    av_free(st->codec->extradata);

    st->codec->extradata = av_mallocz(atom.size - 40 + FF_INPUT_BUFFER_PADDING_SIZE);

    if (!st->codec->extradata)

        return AVERROR(ENOMEM);

    st->codec->extradata_size = atom.size - 40;

    avio_skip(pb, 40);

    avio_read(pb, st->codec->extradata, atom.size - 40);

    return 0;

}
