int av_reallocp_array(void *ptr, size_t nmemb, size_t size)

{

    void **ptrptr = ptr;

    void *ret;

    if (size <= 0 || nmemb >= INT_MAX / size)

        return AVERROR(ENOMEM);

    if (nmemb <= 0) {

        av_freep(ptr);

        return 0;

    }

    ret = av_realloc(*ptrptr, nmemb * size);

    if (!ret) {

        av_freep(ptr);

        return AVERROR(ENOMEM);

    }

    *ptrptr = ret;

    return 0;

}
