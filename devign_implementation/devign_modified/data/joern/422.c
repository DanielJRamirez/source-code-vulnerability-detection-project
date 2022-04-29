static av_cold int cinepak_decode_init(AVCodecContext *avctx)

{

    CinepakContext *s = avctx->priv_data;



    s->avctx = avctx;

    s->width = (avctx->width + 3) & ~3;

    s->height = (avctx->height + 3) & ~3;

    s->sega_film_skip_bytes = -1;  /* uninitialized state */



    // check for paletted data

    if (avctx->bits_per_coded_sample != 8) {

        s->palette_video = 0;

        avctx->pix_fmt = AV_PIX_FMT_YUV420P;

    } else {

        s->palette_video = 1;

        avctx->pix_fmt = AV_PIX_FMT_PAL8;

    }



    s->frame.data[0] = NULL;



    return 0;

}
