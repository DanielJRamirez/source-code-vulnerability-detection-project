ebml_read_ascii (MatroskaDemuxContext *matroska,

                 uint32_t             *id,

                 char                **str)

{

    ByteIOContext *pb = matroska->ctx->pb;

    int size, res;

    uint64_t rlength;



    if ((res = ebml_read_element_id(matroska, id, NULL)) < 0 ||

        (res = ebml_read_element_length(matroska, &rlength)) < 0)

        return res;

    size = rlength;



    /* ebml strings are usually not 0-terminated, so we allocate one

     * byte more, read the string and NULL-terminate it ourselves. */

    if (size < 0 || !(*str = av_malloc(size + 1))) {

        av_log(matroska->ctx, AV_LOG_ERROR, "Memory allocation failed\n");

        return AVERROR(ENOMEM);

    }

    if (get_buffer(pb, (uint8_t *) *str, size) != size) {

        offset_t pos = url_ftell(pb);

        av_log(matroska->ctx, AV_LOG_ERROR,

               "Read error at pos. %"PRIu64" (0x%"PRIx64")\n", pos, pos);


        return AVERROR(EIO);

    }

    (*str)[size] = '\0';



    return 0;

}