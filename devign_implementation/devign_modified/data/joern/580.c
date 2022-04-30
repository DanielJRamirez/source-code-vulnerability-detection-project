static int flashsv2_prime(FlashSVContext *s, uint8_t *src, int size)
{
    z_stream zs;
    int zret; // Zlib return code
    zs.zalloc = NULL;
    zs.zfree  = NULL;
    zs.opaque = NULL;
    s->zstream.next_in   = src;
    s->zstream.avail_in  = size;
    s->zstream.next_out  = s->tmpblock;
    s->zstream.avail_out = s->block_size * 3;
    inflate(&s->zstream, Z_SYNC_FLUSH);
    if (deflateInit(&zs, 0) != Z_OK)
        return -1;
    zs.next_in   = s->tmpblock;
    zs.avail_in  = s->block_size * 3 - s->zstream.avail_out;
    zs.next_out  = s->deflate_block;
    zs.avail_out = s->deflate_block_size;
    deflate(&zs, Z_SYNC_FLUSH);
    deflateEnd(&zs);
    if ((zret = inflateReset(&s->zstream)) != Z_OK) {
        av_log(s->avctx, AV_LOG_ERROR, "Inflate reset error: %d\n", zret);
        return AVERROR_UNKNOWN;
    }
    s->zstream.next_in   = s->deflate_block;
    s->zstream.avail_in  = s->deflate_block_size - zs.avail_out;
    s->zstream.next_out  = s->tmpblock;
    s->zstream.avail_out = s->block_size * 3;
    inflate(&s->zstream, Z_SYNC_FLUSH);
    return 0;
}