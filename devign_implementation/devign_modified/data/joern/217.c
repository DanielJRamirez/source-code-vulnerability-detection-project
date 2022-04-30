static inline void writer_print_rational(WriterContext *wctx,

                                         const char *key, AVRational q, char sep)

{

    AVBPrint buf;

    av_bprint_init(&buf, 0, AV_BPRINT_SIZE_AUTOMATIC);

    av_bprintf(&buf, "%d%c%d", q.num, sep, q.den);

    wctx->writer->print_string(wctx, key, buf.str);

    wctx->nb_item++;

}
