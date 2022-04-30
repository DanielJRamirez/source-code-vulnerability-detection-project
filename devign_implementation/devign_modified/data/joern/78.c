SwsContext *sws_alloc_context(void)

{

    SwsContext *c = av_mallocz(sizeof(SwsContext));



    c->av_class = &sws_context_class;

    av_opt_set_defaults(c);



    return c;

}
