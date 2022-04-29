static int find_stream_index(AVFormatContext *s)

{

    int i;

    AVStream *st;



    if (s->nb_streams <= 0)

        return -1;

    for(i = 0; i < s->nb_streams; i++) {

        st = s->streams[i];

        if (st->codec.codec_type == CODEC_TYPE_VIDEO) {

            return i;

        }

    }

    return 0;

}
