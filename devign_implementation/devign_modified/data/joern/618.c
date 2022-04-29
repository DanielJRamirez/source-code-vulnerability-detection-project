int av_image_alloc(uint8_t *pointers[4], int linesizes[4],
                   int w, int h, enum AVPixelFormat pix_fmt, int align)
{
    const AVPixFmtDescriptor *desc = av_pix_fmt_desc_get(pix_fmt);
    int i, ret;
    uint8_t *buf;
    if (!desc)
        return AVERROR(EINVAL);
    if ((ret = av_image_check_size(w, h, 0, NULL)) < 0)
        return ret;
    if ((ret = av_image_fill_linesizes(linesizes, pix_fmt, align>7 ? FFALIGN(w, 8) : w)) < 0)
        return ret;
    for (i = 0; i < 4; i++)
        linesizes[i] = FFALIGN(linesizes[i], align);
    if ((ret = av_image_fill_pointers(pointers, pix_fmt, h, NULL, linesizes)) < 0)
        return ret;
    buf = av_malloc(ret + align);
    if (!buf)
        return AVERROR(ENOMEM);
    if ((ret = av_image_fill_pointers(pointers, pix_fmt, h, buf, linesizes)) < 0) {
        av_free(buf);
        return ret;
    if (desc->flags & AV_PIX_FMT_FLAG_PAL || desc->flags & AV_PIX_FMT_FLAG_PSEUDOPAL)
        avpriv_set_systematic_pal2((uint32_t*)pointers[1], pix_fmt);
    return ret;