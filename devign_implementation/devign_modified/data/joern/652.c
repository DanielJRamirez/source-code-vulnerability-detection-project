static NvencSurface *get_free_frame(NvencContext *ctx)

{

    int i;



    for (i = 0; i < ctx->nb_surfaces; i++) {

        if (!ctx->surfaces[i].lockCount) {

            ctx->surfaces[i].lockCount = 1;

            return &ctx->surfaces[i];

        }

    }



    return NULL;

}
