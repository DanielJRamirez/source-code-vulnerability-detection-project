void MPV_common_init_armv4l(MpegEncContext *s)

{

    int i;

    const int idct_algo= s->avctx->idct_algo;



    ff_put_pixels_clamped = s->avctx->dsp.put_pixels_clamped;

    ff_add_pixels_clamped = s->avctx->dsp.put_pixels_clamped;



    if(idct_algo==FF_IDCT_AUTO || idct_algo==FF_IDCT_ARM){

        s->idct_put= arm_idct_put;

        s->idct_add= arm_idct_add;

        s->idct_permutation_type= FF_NO_IDCT_PERM;

    }

}
