static int mmf_probe(AVProbeData *p)

{

    /* check file header */

    if (p->buf_size <= 32)

        return 0;

    if (p->buf[0] == 'M' && p->buf[1] == 'M' &&

        p->buf[2] == 'M' && p->buf[3] == 'D' &&

        p->buf[8] == 'C' && p->buf[9] == 'N' &&

        p->buf[10] == 'T' && p->buf[11] == 'I')

        return AVPROBE_SCORE_MAX;

    else

        return 0;

}
