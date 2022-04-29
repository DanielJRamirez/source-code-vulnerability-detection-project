static int vid_probe(AVProbeData *p)

{

    // little endian VID tag, file starts with "VID\0"

    if (p->buf_size < 4 || AV_RL32(p->buf) != MKTAG('V', 'I', 'D', 0))

        return 0;



    return AVPROBE_SCORE_MAX;

}
