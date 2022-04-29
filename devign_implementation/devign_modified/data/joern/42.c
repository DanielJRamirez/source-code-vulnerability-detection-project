static av_cold int split_init(AVFilterContext *ctx)

{

    SplitContext *s = ctx->priv;

    int i;



    for (i = 0; i < s->nb_outputs; i++) {

        char name[32];

        AVFilterPad pad = { 0 };



        snprintf(name, sizeof(name), "output%d", i);

        pad.type = ctx->filter->inputs[0].type;

        pad.name = av_strdup(name);

        if (!pad.name)

            return AVERROR(ENOMEM);



        ff_insert_outpad(ctx, i, &pad);

    }



    return 0;

}
