static int decode_end(AVCodecContext *avctx)

{

    H264Context *h = avctx->priv_data;

    MpegEncContext *s = &h->s;

    


    free_tables(h); //FIXME cleanup init stuff perhaps

    MPV_common_end(s);



//    memset(h, 0, sizeof(H264Context));

        

    return 0;

}