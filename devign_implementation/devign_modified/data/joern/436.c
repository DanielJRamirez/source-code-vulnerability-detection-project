static int crypto_open(URLContext *h, const char *uri, int flags)

{

    const char *nested_url;

    int ret;

    CryptoContext *c = h->priv_data;



    if (!av_strstart(uri, "crypto+", &nested_url) &&

        !av_strstart(uri, "crypto:", &nested_url)) {

        av_log(h, AV_LOG_ERROR, "Unsupported url %s\n", uri);

        ret = AVERROR(EINVAL);

        goto err;

    }



    if (c->keylen < BLOCKSIZE || c->ivlen < BLOCKSIZE) {

        av_log(h, AV_LOG_ERROR, "Key or IV not set\n");

        ret = AVERROR(EINVAL);

        goto err;

    }

    if (flags & AVIO_FLAG_WRITE) {

        av_log(h, AV_LOG_ERROR, "Only decryption is supported currently\n");

        ret = AVERROR(ENOSYS);

        goto err;

    }

    if ((ret = ffurl_open(&c->hd, nested_url, AVIO_FLAG_READ)) < 0) {

        av_log(h, AV_LOG_ERROR, "Unable to open input\n");

        goto err;

    }

    c->aes = av_mallocz(av_aes_size);

    if (!c->aes) {

        ret = AVERROR(ENOMEM);

        goto err;

    }



    av_aes_init(c->aes, c->key, 128, 1);



    h->is_streamed = 1;



    return 0;

err:

    av_free(c->key);

    av_free(c->iv);

    return ret;

}
