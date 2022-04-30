int ff_alloc_entries(AVCodecContext *avctx, int count)

{

    int i;



    if (avctx->active_thread_type & FF_THREAD_SLICE)  {

        SliceThreadContext *p = avctx->internal->thread_ctx;

        p->thread_count  = avctx->thread_count;

        p->entries       = av_mallocz_array(count, sizeof(int));



        if (!p->entries) {

            return AVERROR(ENOMEM);

        }



        p->entries_count  = count;

        p->progress_mutex = av_malloc_array(p->thread_count, sizeof(pthread_mutex_t));

        p->progress_cond  = av_malloc_array(p->thread_count, sizeof(pthread_cond_t));



        for (i = 0; i < p->thread_count; i++) {

            pthread_mutex_init(&p->progress_mutex[i], NULL);

            pthread_cond_init(&p->progress_cond[i], NULL);

        }

    }



    return 0;

}
