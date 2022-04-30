static int ipvideo_decode_block_opcode_0x2(IpvideoContext *s)

{

    unsigned char B;

    int x, y;



    /* copy block from 2 frames ago using a motion vector; need 1 more byte */

    CHECK_STREAM_PTR(s->stream_ptr, s->stream_end, 1);

    B = *s->stream_ptr++;



    if (B < 56) {

        x = 8 + (B % 7);

        y = B / 7;

    } else {

        x = -14 + ((B - 56) % 29);

        y =   8 + ((B - 56) / 29);

    }



    debug_interplay ("    motion byte = %d, (x, y) = (%d, %d)\n", B, x, y);

    return copy_from(s, &s->second_last_frame, x, y);

}
