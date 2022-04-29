static int write_trailer(AVFormatContext *s)

{

    WVMuxContext *wc = s->priv_data;

    AVIOContext *pb = s->pb;



    ff_ape_write(s);



    if (pb->seekable) {

        avio_seek(pb, 12, SEEK_SET);

        avio_wl32(pb, wc->duration);

        avio_flush(pb);

    }



    return 0;

}
