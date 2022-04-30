void *av_realloc(void *ptr, unsigned int size)

{

#ifdef MEMALIGN_HACK

    int diff;

#endif



    /* let's disallow possible ambiguous cases */

    if(size > INT_MAX)

        return NULL;



#ifdef MEMALIGN_HACK

    //FIXME this isn't aligned correctly, though it probably isn't needed

    if(!ptr) return av_malloc(size);

    diff= ((char*)ptr)[-1];

    return realloc(ptr - diff, size + diff) + diff;

#else

    return realloc(ptr, size);

#endif

}
