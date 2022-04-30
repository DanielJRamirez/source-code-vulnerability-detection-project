static const AVClass *urlcontext_child_class_next(const AVClass *prev)

{

    URLProtocol *p = NULL;



    /* find the protocol that corresponds to prev */

    while (prev && (p = ffurl_protocol_next(p)))

        if (p->priv_data_class == prev)

            break;



    /* find next protocol with priv options */

    while (p = ffurl_protocol_next(p))

        if (p->priv_data_class)

            return p->priv_data_class;

    return NULL;

}
