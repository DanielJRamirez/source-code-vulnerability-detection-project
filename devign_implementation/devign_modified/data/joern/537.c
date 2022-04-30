ASSStyle *ff_ass_style_get(ASSSplitContext *ctx, const char *style)

{

    ASS *ass = &ctx->ass;

    int i;



    if (!style || !*style)

        style = "Default";

    for (i=0; i<ass->styles_count; i++)

        if (!strcmp(ass->styles[i].name, style))

            return ass->styles + i;

    return NULL;

}
