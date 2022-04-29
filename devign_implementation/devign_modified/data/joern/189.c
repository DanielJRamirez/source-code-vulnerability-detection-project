static void libopus_write_header(AVCodecContext *avctx, int stream_count,

                                 int coupled_stream_count,

                                 const uint8_t *channel_mapping)

{

    uint8_t *p   = avctx->extradata;

    int channels = avctx->channels;



    bytestream_put_buffer(&p, "OpusHead", 8);

    bytestream_put_byte(&p, 1); /* Version */

    bytestream_put_byte(&p, channels);

    bytestream_put_le16(&p, avctx->delay); /* Lookahead samples at 48kHz */

    bytestream_put_le32(&p, avctx->sample_rate); /* Original sample rate */

    bytestream_put_le16(&p, 0); /* Gain of 0dB is recommended. */



    /* Channel mapping */

    if (channels > 2) {

        bytestream_put_byte(&p, channels <= 8 ? 1 : 255);

        bytestream_put_byte(&p, stream_count);

        bytestream_put_byte(&p, coupled_stream_count);

        bytestream_put_buffer(&p, channel_mapping, channels);

    } else {

        bytestream_put_byte(&p, 0);

    }

}
