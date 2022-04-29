void ff_xvmc_init_block(MpegEncContext *s)

{

    struct xvmc_render_state *render = (struct xvmc_render_state*)s->current_picture.data[2];

    assert(render);

    if (!render || render->magic != AV_XVMC_RENDER_MAGIC) {

        assert(0);

        return; // make sure that this is a render packet

    }

    s->block = (DCTELEM *)(render->data_blocks + render->next_free_data_block_num * 64);

}
