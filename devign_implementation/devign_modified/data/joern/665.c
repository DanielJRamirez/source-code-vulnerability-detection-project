static int64_t mpegts_get_pcr(AVFormatContext *s, int stream_index,

                              int64_t *ppos, int64_t pos_limit)

{

    MpegTSContext *ts = s->priv_data;

    int64_t pos, timestamp;

    uint8_t buf[TS_PACKET_SIZE];

    int pcr_l, pcr_pid = ((PESContext*)s->streams[stream_index]->priv_data)->pcr_pid;

    pos = ((*ppos  + ts->raw_packet_size - 1 - ts->pos47) / ts->raw_packet_size) * ts->raw_packet_size + ts->pos47;

        while(pos < pos_limit) {

            avio_seek(s->pb, pos, SEEK_SET);

            if (avio_read(s->pb, buf, TS_PACKET_SIZE) != TS_PACKET_SIZE)

                return AV_NOPTS_VALUE;

            if ((pcr_pid < 0 || (AV_RB16(buf + 1) & 0x1fff) == pcr_pid) &&

                parse_pcr(&timestamp, &pcr_l, buf) == 0) {

                *ppos = pos;

                return timestamp;

            }

            pos += ts->raw_packet_size;

        }



    return AV_NOPTS_VALUE;

}
