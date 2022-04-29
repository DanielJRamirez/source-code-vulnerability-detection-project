static void put_swf_matrix(ByteIOContext *pb,

                           int a, int b, int c, int d, int tx, int ty)

{

    PutBitContext p;

    uint8_t buf[256];



    init_put_bits(&p, buf, sizeof(buf));

    

    put_bits(&p, 1, 1); /* a, d present */

    put_bits(&p, 5, 20); /* nb bits */

    put_bits(&p, 20, a);

    put_bits(&p, 20, d);

    

    put_bits(&p, 1, 1); /* b, c present */

    put_bits(&p, 5, 20); /* nb bits */

    put_bits(&p, 20, c);

    put_bits(&p, 20, b);



    put_bits(&p, 5, 20); /* nb bits */

    put_bits(&p, 20, tx);

    put_bits(&p, 20, ty);



    flush_put_bits(&p);

    put_buffer(pb, buf, pbBufPtr(&p) - p.buf);

}
