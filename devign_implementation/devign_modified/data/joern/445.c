static int udp_close(URLContext *h)

{

    UDPContext *s = h->priv_data;



    if (s->is_multicast && (h->flags & AVIO_FLAG_READ))

        udp_leave_multicast_group(s->udp_fd, (struct sockaddr *)&s->dest_addr,(struct sockaddr *)&s->local_addr_storage);

    closesocket(s->udp_fd);

#if HAVE_PTHREAD_CANCEL

    if (s->thread_started) {

        int ret;

        pthread_cancel(s->circular_buffer_thread);

        ret = pthread_join(s->circular_buffer_thread, NULL);

        if (ret != 0)

            av_log(h, AV_LOG_ERROR, "pthread_join(): %s\n", strerror(ret));

        pthread_mutex_destroy(&s->mutex);

        pthread_cond_destroy(&s->cond);

    }

#endif

    av_fifo_freep(&s->fifo);

    return 0;

}
