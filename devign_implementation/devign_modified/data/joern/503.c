static void copy_context_after_encode(MpegEncContext *d, MpegEncContext *s, int type){

    int i;



    memcpy(d->mv, s->mv, 2*4*2*sizeof(int)); 

    memcpy(d->last_mv, s->last_mv, 2*2*2*sizeof(int)); //FIXME is memcpy faster then a loop?

    

    /* mpeg1 */

    d->mb_incr= s->mb_incr;

    for(i=0; i<3; i++)

        d->last_dc[i]= s->last_dc[i];

    

    /* statistics */

    d->mv_bits= s->mv_bits;

    d->i_tex_bits= s->i_tex_bits;

    d->p_tex_bits= s->p_tex_bits;

    d->i_count= s->i_count;

    d->p_count= s->p_count;

    d->skip_count= s->skip_count;

    d->misc_bits= s->misc_bits;



    d->mb_intra= s->mb_intra;

    d->mb_skiped= s->mb_skiped;

    d->mv_type= s->mv_type;

    d->mv_dir= s->mv_dir;

    d->pb= s->pb;

    d->block= s->block;

    for(i=0; i<6; i++)

        d->block_last_index[i]= s->block_last_index[i];

}
