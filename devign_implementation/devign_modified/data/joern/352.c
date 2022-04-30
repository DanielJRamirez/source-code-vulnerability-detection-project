void ff_rtp_send_h263(AVFormatContext *s1, const uint8_t *buf1, int size)

{

    RTPMuxContext *s = s1->priv_data;

    int len, max_packet_size;

    uint8_t *q;



    max_packet_size = s->max_payload_size;



    while (size > 0) {

        q = s->buf;

        if ((buf1[0] == 0) && (buf1[1] == 0)) {

            *q++ = 0x04;

            buf1 += 2;

            size -= 2;

        } else {

            *q++ = 0;

        }

        *q++ = 0;



        len = FFMIN(max_packet_size - 2, size);



        /* Look for a better place to split the frame into packets. */

        if (len < size) {

            const uint8_t *end = find_resync_marker_reverse(buf1, buf1 + len);

            len = end - buf1;

        }



        memcpy(q, buf1, len);

        q += len;



        /* 90 KHz time stamp */

        s->timestamp = s->cur_timestamp;

        ff_rtp_send_data(s1, s->buf, q - s->buf, (len == size));



        buf1 += len;

        size -= len;

    }

}
