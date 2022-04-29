static int copy_moof(AVFormatContext *s, const char* infile, const char *outfile, int64_t size)

{

    AVIOContext *in, *out;

    int ret = 0;

    if ((ret = avio_open2(&in, infile, AVIO_FLAG_READ, &s->interrupt_callback, NULL)) < 0)

        return ret;

    if ((ret = avio_open2(&out, outfile, AVIO_FLAG_WRITE, &s->interrupt_callback, NULL)) < 0) {

        avio_close(in);

        return ret;

    }

    while (size > 0) {

        uint8_t buf[8192];

        int n = FFMIN(size, sizeof(buf));

        n = avio_read(in, buf, n);

        if (n <= 0) {

            ret = AVERROR(EIO);

            break;

        }

        avio_write(out, buf, n);

        size -= n;

    }

    avio_flush(out);

    avio_close(out);

    avio_close(in);

    return ret;

}
