int ffurl_read_complete(URLContext *h, unsigned char *buf, int size)

{

    if (h->flags & AVIO_FLAG_WRITE)

        return AVERROR(EIO);

    return retry_transfer_wrapper(h, buf, size, size, h->prot->url_read);

}
