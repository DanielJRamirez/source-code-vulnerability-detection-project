static void idr(H264Context *h){

    int i;

    ff_h264_remove_all_refs(h);

    h->prev_frame_num= 0;

    h->prev_frame_num_offset= 0;

    h->prev_poc_msb=

    h->prev_poc_lsb= 0;

    for (i = 0; i < MAX_DELAYED_PIC_COUNT; i++)

        h->last_pocs[i] = INT_MIN;

}
